/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : ���ӵ������������ϵĿͻ��˹������
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/

#include "cellapp.h"
#include "ClientSession.h"
#include "common/memorystream.hpp"







namespace KBEngine{	

	CCleintSession::CCleintSession()
	{

	}

	CCleintSession::~CCleintSession()
	{

	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ע������Э��
	//--------------------------------------------------------------------------------------------------------
	void  CCleintSession::InitProtol()
	{
		//m_CellSessionNetMgr.Register(CL_ProofAccount, &CLoginSession::HandleProofAccount, "CL_ProofAccount");

	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ע������Э��
	//--------------------------------------------------------------------------------------------------------
	void CCleintSession::Destory()
	{
		m_CellSessionNetMgr.UnRegisterAll();
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc		: ��·Э��Ĵ���ӿ�
	//--------------------------------------------------------------------------------------------------------
	UINT32 CCleintSession::HandleMessage()
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
		CELLNETMSGHANDLER handle = m_CellSessionNetMgr.GetMsgHandler(nMsgID, dwSize);
		if (NULL != handle)
			(this->*handle)(&m_RecvStream);

		ReturnMsg(pMsg);
		return 0;
	}

	//--------------------------------------------------------------------------------------------------------
	// function :
	// desc     : ͬ������������Ϣ
	//--------------------------------------------------------------------------------------------------------
	void CCleintSession::SyncSendMessage(tagNetCmd* pMsg)
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
	void CCleintSession::SendMessage(tagNetCmd* pMsg)
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
	void CCleintSession::ReturnMsg(tagUnit* pMsg)
	{

	}
}
