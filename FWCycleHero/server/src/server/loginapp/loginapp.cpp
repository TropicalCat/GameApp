/*
----------------------------------------------------------------------------
		file name : loginapp.hpp
		desc	  : ��¼������
		author    : LJP

		log		  : [ 2015-04-25 ]
----------------------------------------------------------------------------
*/
#include "loginapp.hpp"
#include "network/common.hpp"
#include "common/kbeversion.hpp"
#include "server/components.hpp"
#include "server/glw_resmgr.hpp"
#include "fpworld_mgr.hpp"
#include "fplayer_mgr.hpp"





namespace KBEngine
{
	
	//ServerConfig g_serverConfig;
	KBE_SINGLETON_INIT(Loginapp);

	//-------------------------------------------------------------------------------------
	Loginapp::Loginapp()
	{

	}

	//-------------------------------------------------------------------------------------
	Loginapp::~Loginapp()
	{
		
	}


	bool Loginapp::Initialize(COMPONENT_TYPE componentType)
	{
		mComponentType = componentType;

		// ��ʼ�������
		WSADATA ws;
		WSAStartup(MAKEWORD(2,2), &ws);

		INFO_MSG("-----------------------------------------------------------------------------------------\n");
		INFO_MSG("Statr CPlayerMgr new EventDispatcher \n");
		m_pDispatcher = new EventDispatcher();
		DebugHelper::initialize(componentType);

		// ��Դ��ʼ��
		new Resmgr();
		Resmgr::getSingleton().initialize();

		INFO_MSG("Load config files \n");
		g_kbeSrvConfig.loadConfig("config/kbengine_defs.xml");
		g_kbeSrvConfig.loadConfig("config/kbengine.xml");

		new FpWorldMgr();
		new CPlayerMgr();
		new ServerConfig();

		// init
		sPlayerMgr.Init();
		return true;
	}


	//-------------------------------------------------------------------------------------
	void Loginapp::MainLoop( void )
	{
		while (true)
		{
			// ���� DB Session
			if (m_pDB != NULL)
				m_pDB->UpdateSession();

			// �������е� player session
			m_pNetSessionMgr->UpdateSession();

			sleep(10);
		}
	}


	//-------------------------------------------------------------------------------------
	void Loginapp::handleTimeout(TimerHandle handle, void * arg)
	{
		/*switch (reinterpret_cast<uintptr>(arg))
		{
		default:

		}*/
	}


	//-------------------------------------------------------------------------------------
	bool Loginapp::InitializeEnd()
	{
		if (m_pNetSessionMgr == NULL)
		{
			m_pNetSessionMgr = new CLoginSessionMgr();
		}

		// �������ڶ�λ����socket
		ENGINE_COMPONENT_INFO& info = g_kbeSrvConfig.getLoginApp();
		if (m_pDispatcher->pPoller() != NULL)
		{
			m_pDispatcher->pPoller()->InitNetEngine(info.port);
			m_pDispatcher->pPoller()->SetSessionFactory(m_pNetSessionMgr);
		}
		return true;
	}

	//-------------------------------------------------------------------------------------
	// �������� 
	//-------------------------------------------------------------------------------------
	void Loginapp::Destroy( void )
	{
		
	}

	
}
