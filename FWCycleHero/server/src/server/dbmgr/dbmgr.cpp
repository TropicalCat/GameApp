/*
------------------------------------------------------------------------------------------------------------------
file Name	:
desc		: db ����������ģ��
author		:
log			:
------------------------------------------------------------------------------------------------------------------
*/
#include "dbmgr.hpp"
#include "network/common.hpp"
#include "network/event_poller.hpp"
#include "network/event_dispatcher.hpp"
#include "server/components.hpp"
#include "db_interface/db_interface.h"



namespace KBEngine{
	

	KBE_SINGLETON_INIT(AppDBServer);

	//-------------------------------------------------------------------------------------
	AppDBServer::AppDBServer() : m_pDBAppSessionMgr(0), m_pDispatcher(0)
	{

	}

	//-------------------------------------------------------------------------------------
	AppDBServer::~AppDBServer()
	{

	}

	//--------------------------------------------------------------------------------------
	bool AppDBServer::Initialize(COMPONENT_TYPE componentType )
	{
		// ע��������Ҫ�������Ϣ�ӿ�
		mComponentType = componentType;
		DebugHelper::initialize(componentType);

		// ��Դ��ʼ��
		new Resmgr();
		Resmgr::getSingleton().initialize();
		new ServerConfig();

		INFO_MSG("-----------------------------------------------------------------------------------------\n");
		g_kbeSrvConfig.loadConfig("config/kbengine_defs.xml");
		g_kbeSrvConfig.loadConfig("config/kbengine.xml");
		INFO_MSG("Load config files \n");

		if (!initDB())
			return false;
		INFO_MSG("Connection DB Success!! \n");



		m_pDispatcher = new EventDispatcher();
		InitNetWork();
		return true;
	}

	//-------------------------------------------------------------------------------
	// function : 
	// desc		: ��ʼ������������
	//-------------------------------------------------------------------------------
	void AppDBServer::InitNetWork(void)
	{
		if (m_pDBAppSessionMgr == NULL)
		{
			m_pDBAppSessionMgr = new CDBAppSessionMgr();
		}

		// �������ڶ�λ����socket
		ENGINE_COMPONENT_INFO& info = g_kbeSrvConfig.getLoginApp();
		if (m_pDispatcher->pPoller() != NULL)
		{
			m_pDispatcher->pPoller()->InitNetEngine(info.db_port);
			m_pDispatcher->pPoller()->SetSessionFactory(m_pDBAppSessionMgr);
		}
	}


	bool AppDBServer::InitializeEnd()
	{
		return true;
	}

	//-------------------------------------------------------------------------------------
	void AppDBServer::MainLoop( void )
	{
		while (true)
		{
			m_pDBAppSessionMgr->UpdateSession();
			sleep(10);
		}
	}


	
	//-------------------------------------------------------------------------------------		
	bool AppDBServer::initDB()
	{
		
		if(!DBUtil::initialize())
		{
			ERROR_MSG("Dbmgr::initDB(): can't initialize dbinterface!\n");
			return false;
		}

		DBInterface* pDBInterface = DBUtil::createInterface();
		if(pDBInterface == NULL)
		{
			ERROR_MSG("Dbmgr::initDB(): can't create dbinterface!\n");
			return false;
		}

		bool ret = DBUtil::initInterface(pDBInterface);
		pDBInterface->detach();
		SAFE_RELEASE(pDBInterface);

		if(!ret)
			return false;

		return true;
	}

	//-------------------------------------------------------------------------------------
	void AppDBServer::Destroy()
	{
	
	}
}
