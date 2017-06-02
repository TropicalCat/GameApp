/*
-------------------------------------------------------------------------------------------------
file name : endpoint.hpp
desc	  : ������ socket �ķ�װ
author	  : LJP

log		  : [ 2015-04-26 ]
-------------------------------------------------------------------------------------------------
*/
#include "CliSocket.hpp"
#include "network/event_iocp.hpp"
#include "helper/debug_helper.hpp"






namespace KBEngine
{

	#define POOL_PKG_SIZE 1024
	#define MAX_PKG_LEN		(1024*10)
	/*****************************************************************************************
		client socket
	*****************************************************************************************/
	ClientSocket::ClientSocket() : m_socket(-1), m_bConnected(false), m_pSendBuf(0)
	{
		m_stRecvIoData.nOp			= IOCP_RECV;
		m_stSendIoData.nOp			= IOCP_SEND;
		m_stPerHandleData.bListen	= false;
		m_stPerHandleData.ptr		= this;
		m_nDataReceived				= 0;
		m_IsShutDown				= false;
		m_bConnected				= false;
		m_pSendBuf					= new char[MAX_PKG_LEN];
		m_pRecvBuf					= new char[MAX_PKG_LEN];
		m_PoolSend					= new SafeMemPool(POOL_PKG_SIZE);
		m_PoolRecv					= new SafeMemPool(POOL_PKG_SIZE);
	}

	ClientSocket::~ClientSocket()
	{

	}


	/*******************************************************************************************
	* function :
	* desc     : ���ٶ������
	*******************************************************************************************/
	void ClientSocket::Destory()
	{
		SAFE_DEL_ARRAY(m_pSendBuf);

		while (m_SendQueue.GetNum() > 0)
		{
			tagUnit* pUnit = m_SendQueue.Get();
			if (pUnit == NULL)
				return;
			SAFE_DEL(pUnit);
		}
		SAFE_DEL(m_PoolSend);

		while (m_RecvQueue.GetNum() > 0)
		{
			tagUnit* pUnit = m_RecvQueue.Get();
			if (pUnit == NULL)
				return;
			SAFE_DEL(pUnit);
		}
		SAFE_DEL(m_PoolRecv);

		closesock();
	}

	/*****************************************************************************************
		
	*****************************************************************************************/
	void ClientSocket::connect(UINT32 nIP, UINT16 nPort)
	{
		sockaddr_in	sin;
		sin.sin_family		= AF_INET;
		sin.sin_port		= nPort;
		sin.sin_addr.s_addr = nIP;

		int ret = ::connect(m_socket, (sockaddr*)&sin, sizeof(sin));
		
		// ���� socket noblock
		u_long val = 1;
		::ioctlsocket(m_socket, FIONBIO, &val);	

		// ���� socket nodelay
		int arg = 1;
		setsockopt(m_socket, IPPROTO_TCP, TCP_NODELAY, (char*)&arg, sizeof(int));
	}


	//-------------------------------------------------------------------------------------------
	//  function : 
	//  desc     : �ر�����
	//-------------------------------------------------------------------------------------------
	void ClientSocket::closesock()
	{
		if (m_socket == -1)
			return;

		m_bConnected = false;
		m_IsShutDown = true;
		::closesocket(m_socket);
	}


	void ClientSocket::sendmsg( void )
	{
		/////////////////////////////////////////////////////////////////////////////////////
		// �ϲ�������
		UINT32 dwTotal = 0;
		while ( m_SendQueue.GetNum() > 0 )
		{
			tagUnit* pUnit = m_SendQueue.Get();
			if (pUnit == NULL)
				return;

			if ((pUnit->dwSize + dwTotal) >= POOL_PKG_SIZE)
			{
				m_SendQueue.AddFront(pUnit);
				break;
			}
			
			memcpy(m_pSendBuf + dwTotal, pUnit->Buf, pUnit->dwSize);
			dwTotal += pUnit->dwSize;

			// �黹�����ڴ�
			m_PoolSend->Free(pUnit);
		}

		if (dwTotal = 0)
			return;

		memset(&m_stSendIoData.stOverlapped, 0, sizeof(m_stSendIoData.stOverlapped));

		// �ڰ�ͷ��д��С��ѹ����С
		m_stSendIoData.stWsaBuf.buf = m_pSendBuf;
		m_stSendIoData.stWsaBuf.len = dwTotal;

		DWORD dwNumberOfBytesSend	= 0;
		if (0 != WSASend(m_socket, &m_stSendIoData.stWsaBuf, 1, &dwNumberOfBytesSend, 0, &m_stSendIoData.stOverlapped, NULL))
		{
			if (WSAGetLastError() != WSA_IO_PENDING)
			{
				return;
			}
		}
	}

	INT32 ClientSocket::SyncSend(const char* pBuf, UINT32 dwLen)
	{
		WSABUF  sndBuf;
		sndBuf.buf = (char*)pBuf;
		sndBuf.len = dwLen;

		DWORD dwNumberOfBytesSend = 0;
		if (0 != WSASend(m_socket, &sndBuf, 1, &dwNumberOfBytesSend, 0, NULL, NULL))
		{
			INT32 errNO = WSAGetLastError();
			if (errNO == WSA_IO_PENDING)
			{
				closesock();
				return -1;
			}

			KBE_ASSERT(dwLen == dwNumberOfBytesSend);
		}
		return dwNumberOfBytesSend;
	}


	//------------------------------------------------------------------------------------------
	// function :
	// desc     : �ŵ��l�������
	//--------------------------------------------------------------------------------------------
	void ClientSocket::Send(const char* pMsg, UINT32 dwLen)
	{
		if ( IsConnected() )
		{
			tagUnit* pMsgUnit = (tagUnit*)(m_PoolSend->TryAlloc(dwLen));
			pMsgUnit->dwSize  = dwLen;
			pMsgUnit->pNext	  = NULL;
			memcpy( pMsgUnit->Buf, pMsg, dwLen );
			m_SendQueue.Add( pMsgUnit );
		}
	}


	//--------------------------------------------------------------------------------------------
	// function : 
	// desc     : �������Ͻ��̶ܹ����ݳ��ȵ�
	//--------------------------------------------------------------------------------------------
	void ClientSocket::PostRecv()
	{
		memset(&m_stRecvIoData.stOverlapped, 0, sizeof(m_stRecvIoData.stOverlapped));
		m_stRecvIoData.stWsaBuf.buf = m_pRecvBuf;
		m_stRecvIoData.stWsaBuf.len = MAX_PKG_LEN;

		if (m_stRecvIoData.stWsaBuf.len > MAX_PKG_LEN)
		{
			m_stRecvIoData.stWsaBuf.len = MAX_PKG_LEN;
		}

		DWORD  dwBytes;
		DWORD  dwFlag = 0;		// �@�Yһ��Ҫ�O�ó�0 ��t����10045 �e�`
		if (WSARecv(m_socket, &m_stRecvIoData.stWsaBuf, 1, &dwBytes, &dwFlag, &m_stRecvIoData.stOverlapped, NULL) != 0)
		{
			int err = WSAGetLastError();
			if (err != WSA_IO_PENDING)
			{
				return;
			}
		}
	}

	void ClientSocket::recvmsg(UINT32 dwBytes)
	{
		m_nDataReceived += dwBytes;
		
		char* p			 = m_pRecvBuf;
		while (m_nDataReceived > 0)
		{
			INT32 nUsedLen = m_nDataReceived;
			if (0 == nUsedLen)
			{
				// ���һ�ν��ܻ����������� ����û��װ��һ����ɰ��� ֻ�öϿ�������
				if (m_nDataReceived >= MAX_PKG_LEN)
				{
					this->closesock();
					return;
				}
			}
			else if (nUsedLen > 0)
			{
				// ��������������涨��С����Ϊ�쳣
				if (nUsedLen > MAX_PAGE_SIZE)
				{
					this->closesock();
					return;
				}

				/// �����������
				tagUnit* pUnit = (tagUnit*)m_PoolRecv->Alloc(sizeof(tagUnit));
				pUnit->dwSize  = nUsedLen;
				memset(pUnit->Buf, 0, MAX_PAGE_SIZE);
				
				
				{
					memcpy(pUnit->Buf, p, nUsedLen);
				}
				m_RecvQueue.Add(pUnit);

				p += nUsedLen;
				m_nDataReceived -= nUsedLen;
			}
		}

		PostRecv();
	}

	//-------------------------------------------------------------------------------------------
	// function :
	// desc     : �õ����ͻ���Ĵ�С
	//-------------------------------------------------------------------------------------------
	int ClientSocket::GetBufferSize(int optname) const
	{
		KBE_ASSERT(optname == SO_SNDBUF || optname == SO_RCVBUF);
		int recvbuf = -1;
		socklen_t rbargsize = sizeof(int);
		int rberr = getsockopt(m_socket, SOL_SOCKET, optname, (char*)&recvbuf, &rbargsize);
		if (rberr == 0 && rbargsize == sizeof(int))
			return recvbuf;

		return -1;
	}

	bool ClientSocket::SetBufferSize(int optname, int size)
	{
		setsockopt(m_socket, SOL_SOCKET, optname, (const char*)&size, sizeof(size));
		return this->GetBufferSize(optname) >= size;
	}


	//-------------------------------------------------------------------------------------------
	//  function : 
	//  desc     : ����ɶ˿�ģʽ
	//-------------------------------------------------------------------------------------------
	bool ClientSocket::AssociateWithIOCP()
	{
		return CIocpPoller::Instance()->AssociateWithIocp(m_socket, &m_stPerHandleData);
	}


	//-------------------------------------------------------------------------------------------
	//  function : 
	//  desc     : �õ��ÿͻ����Ѿ����ܵ�һ��������Ϣ
	//-------------------------------------------------------------------------------------------
	tagUnit* ClientSocket::GetRecvMessages(UINT32& dwSize, INT32& nRecvNum)
	{

		nRecvNum		= m_RecvQueue.GetNum();
		tagUnit* pUnit	= m_RecvQueue.Get();
		if (pUnit == NULL)
			return NULL;

		dwSize = pUnit->dwSize;
		return pUnit;
	}
}
