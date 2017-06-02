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
#include "network/message_handler.hpp"
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

		DebugHelper::initialize(componentType);

		// ��Դ��ʼ��
		new Resmgr();
		Resmgr::getSingleton().initialize();

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
			sPlayerMgr.Update();
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
		
		return true;
	}

	//-------------------------------------------------------------------------------------
	// �������� 
	//-------------------------------------------------------------------------------------
	void Loginapp::Destroy( void )
	{
		
	}

	
}
