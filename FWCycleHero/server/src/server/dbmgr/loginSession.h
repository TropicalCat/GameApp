/*
---------------------------------------------------------------------------------------------------------
file name : loginSession.hpp
desc      : ��¼�������� DBapp ������
author    : ljp

log		  : 2017-06-09 : 15:55
---------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "helper/debug_helper.hpp"
#include "network/Session.hpp"
#include "network/net_define.h"
#include "common/common.hpp"
#include "common/memorystream.hpp"
#include "sync_app_handler.h"








namespace KBEngine
{

	
	class CLoginSession : public INetSession
	{

	public:
		CLoginSession();
		virtual ~CLoginSession();

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
		CDBAppNetCmdMgr		m_loginNetMgr;
	};
}

