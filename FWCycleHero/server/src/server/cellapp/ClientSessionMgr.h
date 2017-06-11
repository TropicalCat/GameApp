/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : ���ӵ������������ϵĿͻ��˹������
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "network/SessionMgr.hpp"






namespace KBEngine{

	class CCleintSession;
	class CCellAppSessionMgr : public INetSessionMgr
	{

	public:
		CCellAppSessionMgr();
		virtual ~CCellAppSessionMgr();

	public:

		//////////////////////////////////////////////////////////////////////////
		// ��������Session
		//////////////////////////////////////////////////////////////////////////
		void						UpdateSession(void);

		virtual INetSession*		CreateSession(SESSION_TYPE type);
		virtual bool				RemoveSession(INetSession* pSession);

	protected:

		TMap<UINT32, CCleintSession*>	mapSession;
		UINT32						m_GenID;
	};
}


