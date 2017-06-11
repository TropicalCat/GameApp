/*
---------------------------------------------------------------------------------------------------
		file name : cellapp.h
		desc      : ��������������
		author	  : ljp

		log		  : by ljp create 2017-06-11
---------------------------------------------------------------------------------------------------
*/
#include "cellapp.h"
#include "space.h"
#include "server/glw_resmgr.hpp"
#include "server/serverconfig.hpp"
#include "server/components.hpp"
#include "network/event_poller.hpp"
#include "navigation/navigation.hpp"






namespace KBEngine{
	

	KBE_SINGLETON_INIT(CellServerApp);
	//Navigation g_navigation;
	//-------------------------------------------------------------------------------------
	CellServerApp::CellServerApp() : m_CellSessionMgr(0), m_pDispatcher(0)
	{
	
	}

	//-------------------------------------------------------------------------------------
	CellServerApp::~CellServerApp()
	{
		//EntityMailbox::resetCallHooks();
	}


	//--------------------------------------------------------------------------------------
	bool CellServerApp::Initialize(COMPONENT_TYPE componentType)
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

		m_pDispatcher = new EventDispatcher();
		InitializeEnd();
		return true;
	}

	bool CellServerApp::InitializeEnd()
	{
		if (m_CellSessionMgr == NULL)
		{
			m_CellSessionMgr = new CCellAppSessionMgr();
		}

		// �������ڶ�λ����socket
		ENGINE_COMPONENT_INFO& info = g_kbeSrvConfig.getLoginApp();
		if (m_pDispatcher->pPoller() != NULL)
		{
			m_pDispatcher->pPoller()->InitNetEngine(info.db_port);
			m_pDispatcher->pPoller()->SetSessionFactory(m_CellSessionMgr);
		}
		return true;
	}

	//-------------------------------------------------------------------------------------
	void CellServerApp::MainLoop(void)
	{
		while (true)
		{
			m_CellSessionMgr->UpdateSession();
			sleep(10);
		}
	}

	//-------------------------------------------------------------------------------------
	void CellServerApp::Destroy()
	{


	}
}
