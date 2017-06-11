/*
------------------------------------------------------------------------------------------------------------------
file Name	:
desc		: db ����������ģ��
author		:
log			:
------------------------------------------------------------------------------------------------------------------
*/
#ifndef KBE_DBMGR_HPP
#define KBE_DBMGR_HPP
#include "server/serverconfig.hpp"
#include "server/glw_resmgr.hpp"
#include "network/event_dispatcher.hpp"
#include "DBSessionMgr.h"





namespace KBEngine
{

	
	class AppDBServer : public Singleton<AppDBServer>
	{

	public:
	
		 AppDBServer();
		~AppDBServer();
	
		
		bool						Initialize(COMPONENT_TYPE componentType);
		void						InitNetWork( void );
		void						MainLoop(void);

		/* ��ʼ����ؽӿ� */
		/* ��ʼ����ؽӿ� */
		bool						initDB();
		bool						InitializeEnd();
		void						Destroy(void);

	protected:
		
		COMPONENT_TYPE				mComponentType;		
		CDBAppSessionMgr*			m_pDBAppSessionMgr;
		EventDispatcher*			m_pDispatcher;
	};

}

#endif // KBE_DBMGR_HPP
