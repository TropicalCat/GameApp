/*
----------------------------------------------------------------------------
	file name : NetCmdMgr.hpp
	desc	  : �����������
	author    : LJP

	log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#pragma once
#include "common/singleton.hpp"
#include "common/memorystream.hpp"
#include "network/SessionMgr.hpp"
#include "fplayer_net_cmd_mgr.hpp"
#include "fpworld.hpp"






namespace KBEngine
{
	class CPlayerSession;
	class CLoginSessionMgr : public INetSessionMgr
	{

	public:
		CLoginSessionMgr();
		virtual ~CLoginSessionMgr();

	public:

		//////////////////////////////////////////////////////////////////////////
		// ��������Session
		//////////////////////////////////////////////////////////////////////////
		void						UpdateSession( void );

		virtual INetSession*		CreateSession(SESSION_TYPE type);
		virtual bool				RemoveSession(INetSession* pSession);

	private:

	protected:

		TMap<UINT32, CPlayerSession*>	mapSession;
		UINT32						m_GenID;
	};
}


