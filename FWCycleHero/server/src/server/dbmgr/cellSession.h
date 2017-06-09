/*
---------------------------------------------------------------------------------------------------------
		file name : cellSession.hpp
		desc      : ������������ DBapp ������
		author    : ljp

		log		  : 2017-06-09 : 15:55
---------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "helper/debug_helper.hpp"
#include "network/Session.hpp"
#include "network/net_define.h"
#include "common/memorystream.hpp"
#include "common/common.hpp"








namespace KBEngine
{

	class CCellSession : public INetSession
	{

	public:
		CCellSession();
		virtual ~CCellSession();

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
	};
}

