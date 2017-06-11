/*
---------------------------------------------------------------------------------------------------------
		file name : dbappserver.h
		desc      : db ���������,�������е�DB server ������
		author    : ljp

		log		  : 2017-06-09 : 15:55
---------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/memorystream.hpp"
#include "network/SessionMgr.hpp"







namespace KBEngine
{

	class CLoginSession;
	class CDBAppSessionMgr : public INetSessionMgr
	{

	public:
		CDBAppSessionMgr();
		virtual ~CDBAppSessionMgr();

	public:

		//////////////////////////////////////////////////////////////////////////
		// ��������Session
		//////////////////////////////////////////////////////////////////////////
		void						UpdateSession(void);

		virtual INetSession*		CreateSession(SESSION_TYPE type);
		virtual bool				RemoveSession(INetSession* pSession);

	protected:

		TMap<UINT32, CLoginSession*>	mapSession;
		UINT32						m_GenID;
	};
	
}

