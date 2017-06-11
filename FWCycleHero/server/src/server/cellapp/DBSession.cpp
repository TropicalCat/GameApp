/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : ���ӵ������������ϵĿͻ��˹������
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/

#include "cellapp.h"
#include "DBSession.h"
#include "common/memorystream.hpp"







namespace KBEngine{	

	CDBSession::CDBSession()
	{

	}

	CDBSession::~CDBSession()
	{

	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ע������Э��
	//--------------------------------------------------------------------------------------------------------
	void  CDBSession::InitProtol()
	{
		//m_DbSessionNetMgr.Register(CL_ProofAccount, &CLoginSession::HandleProofAccount, "CL_ProofAccount");

	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ע������Э��
	//--------------------------------------------------------------------------------------------------------
	void CDBSession::Destory()
	{
		m_DbSessionNetMgr.UnRegisterAll();
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ��·Э��Ĵ���ӿ�
	//--------------------------------------------------------------------------------------------------------
	UINT32 CDBSession::HandleMessage()
	{

		UINT32 dwSize = 0;
		INT32  nUnRecved = 0;
		tagUnit* pMsg = mClientSocket->GetRecvMessages(dwSize, nUnRecved);
		if (!P_VALID(pMsg))
			return 0;


		uint32 nMsgID = -1;
		m_RecvStream.clear(true);
		m_RecvStream.append((const uint8*)pMsg->Buf, pMsg->dwSize);
		m_RecvStream >> nMsgID;
		m_RecvStream.flushread();
		DBNETMSGHANDLER handle = m_DbSessionNetMgr.GetMsgHandler(nMsgID, dwSize);
		if (NULL != handle)
			(this->*handle)(&m_RecvStream);

		ReturnMsg(pMsg);
		return 0;
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc     : ͬ������������Ϣ
	//--------------------------------------------------------------------------------------------------------
	void CDBSession::SyncSendMessage(tagNetCmd* pMsg)
	{
		if (mClientSocket != NULL)
		{
			m_SendStream.clear(true);
			pMsg->Serialize(&m_SendStream);
			mClientSocket->SyncSend((const char*)m_SendStream.data(), m_SendStream.wpos());
		}
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc     : �첽������Ϣ
	//--------------------------------------------------------------------------------------------------------
	void CDBSession::SendMessage(tagNetCmd* pMsg)
	{
		if (mClientSocket != NULL)
		{
			m_SendStream.clear(true);
			pMsg->Serialize(&m_SendStream);
			mClientSocket->Send((const char*)m_SendStream.data(), m_SendStream.wpos());
		}
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc     : ���������ڴ�黹���ڴ����
	//--------------------------------------------------------------------------------------------------------
	void CDBSession::ReturnMsg(tagUnit* pMsg)
	{

	}
}
