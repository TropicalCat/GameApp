/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : 连接到场景服务器上的客户端管理对象
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "network/Session.hpp"
#include "network/net_define.h"
#include "common/memorystream.hpp"
#include "sync_loginapp_handler.h"





namespace KBEngine{

	class CLoginSession : public INetSession
	{

	public:
		CLoginSession();
		virtual ~CLoginSession();

		void				InitProtol();
		void				Destory();

		////////////////////////////////////////////////////////////////////////////////////////////
		// 发送消息
		void				SendMessage(tagNetCmd* pMsg);
		void				SyncSendMessage(tagNetCmd* pMsg);


		UINT32				HandleMessage();
		void				ReturnMsg(tagUnit* pMsg);


	protected:

		MemoryStream		m_SendStream;
		MemoryStream		m_RecvStream;
		CLoginAppNetCmdMgr	m_LoginSessionNetMgr;
	};
}
