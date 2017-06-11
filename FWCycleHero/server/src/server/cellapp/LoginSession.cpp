/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : ���ӵ������������ϵĿͻ��˹������
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/

#include "cellapp.h"
#include "LoginSession.h"
#include "common/memorystream.hpp"







namespace KBEngine{	

	CLoginSession::CLoginSession()
	{

	}

	CLoginSession::~CLoginSession()
	{

	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ע������Э��
	//--------------------------------------------------------------------------------------------------------
	void  CLoginSession::InitProtol()
	{
		//m_LoginSessionNetMgr.Register(CL_ProofAccount, &CLoginSession::HandleProofAccount, "CL_ProofAccount");

	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ע������Э��
	//--------------------------------------------------------------------------------------------------------
	void CLoginSession::Destory()
	{
		m_LoginSessionNetMgr.UnRegisterAll();
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ��·Э��Ĵ���ӿ�
	//--------------------------------------------------------------------------------------------------------
	UINT32 CLoginSession::HandleMessage()
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
		LOGINNETMSGHANDLER handle = m_LoginSessionNetMgr.GetMsgHandler(nMsgID, dwSize);
		if (NULL != handle)
			(this->*handle)(&m_RecvStream);

		ReturnMsg(pMsg);
		return 0;
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc     : ͬ������������Ϣ
	//--------------------------------------------------------------------------------------------------------
	void CLoginSession::SyncSendMessage(tagNetCmd* pMsg)
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
	void CLoginSession::SendMessage(tagNetCmd* pMsg)
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
	void CLoginSession::ReturnMsg(tagUnit* pMsg)
	{

	}
}
