/*
---------------------------------------------------------------------------------------------------
			file name : cellapp.h
			desc      : ����������
			author	  : ljp

			log		  : by ljp create 2017-06-11
---------------------------------------------------------------------------------------------------
*/
#pragma once
#include "spaces.h"
#include "cells.h"
#include "LoginSession.h"
#include "DBSession.h"
#include "network/event_dispatcher.hpp"
#include "ClientSessionMgr.h"

	



namespace KBEngine
{

	class CellServerApp : public Singleton<CellServerApp>
	{
	public:
	
		 CellServerApp();
		~CellServerApp();
	
		bool						Initialize(COMPONENT_TYPE componentType);
		void						MainLoop(void);

		/* ��ʼ����ؽӿ� */
		/* ��ʼ����ؽӿ� */
		bool						initDB();
		bool						InitializeEnd();
		void						Destroy(void);
	protected:

		// ���е�cell
		COMPONENT_TYPE				mComponentType;

		CCellAppSessionMgr*			m_CellSessionMgr;
		EventDispatcher*			m_pDispatcher;
		CLoginSession				m_Login;				// ���ӵ���¼������
		CDBSession					m_DB;					// ���ӵ����ݿ�

		Cells						cells_;
		uint32						flags_;
	};

}


