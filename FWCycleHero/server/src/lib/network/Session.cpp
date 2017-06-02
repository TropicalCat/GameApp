/*
--------------------------------------------------------------------------------------------
file name : Session.hpp
desc	  : ���������ͽ���Ķ���
author    : LJP

log		  : [2015-04-26]
--------------------------------------------------------------------------------------------
*/
#include "Session.hpp"
#include "SessionMgr.hpp"
#include "network/CliSocket.hpp"
#include "network/message_handler.hpp"




namespace KBEngine 
{ 

	INetSession::INetSession() : mRemoteIP(0), mRemotePort(0) 
							   , mClientSocket(NULL), mIsUseBuffer(false)
	{
		mConnectStats = NET_SESSION_NONE;
	}

	INetSession::~INetSession()
	{

	}


	/*********************************************************************************************
	* @brief Callback when the connection is established
	*********************************************************************************************/
	void INetSession::Close()
	{
		if (IsConnected() )
		{
		
		}
	}

	/*********************************************************************************************
	* ����Ϣ���͵�������
	**********************************************************************************************/
	bool INetSession::Send(const char* szBuf, UINT32 dwLen)
	{
		if (!IsConnected())
		{
			return false;
		}

		if (mIsUseBuffer)
		{

		}

		if (mClientSocket != NULL)
		{
			mClientSocket->Send(szBuf, dwLen);
		}
		return true;
	}


	/*********************************************************************************************
	* �������Ͻ�����Ϣ
	**********************************************************************************************/
	bool INetSession::Recv(const char* szBuf, UINT dwLen)
	{
		if (!IsConnected())
		{
			return false;
		}

		return true;
	}

	/*********************************************************************************************
	* ��ʱ�ر�����
	**********************************************************************************************/
	void INetSession::delayclose(UINT32 error_code, UINT32 delayCount)
	{

	}

}
