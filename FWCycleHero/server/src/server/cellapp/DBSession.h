/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : ���ӵ������������ϵĿͻ��˹������
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "network/Session.hpp"
#include "network/net_define.h"
#include "common/memorystream.hpp"
#include "sync_dbapp_handler.h"





namespace KBEngine{

	class CDBSession : public INetSession
	{

	public:
		CDBSession();
		virtual ~CDBSession();

		void				InitProtol();
		void				Destory();

		////////////////////////////////////////////////////////////////////////////////////////////
		// ������Ϣ
		void				SendMessage(tagNetCmd* pMsg);
		void				SyncSendMessage(tagNetCmd* pMsg);


		UINT32				HandleMessage();
		void				ReturnMsg(tagUnit* pMsg);


	protected:

		MemoryStream		m_SendStream;
		MemoryStream		m_RecvStream;
		CDBAppNetCmdMgr		m_DbSessionNetMgr;
	};
}


