/*
--------------------------------------------------------------------------------
		file name : serverconfig.hpp
		desc	  : ������������Ϣ
		author	  : LJP

		log		  : [2015-04-25]
--------------------------------------------------------------------------------
*/
#ifndef KBE_SERVER_CONFIG_HPP
#define KBE_SERVER_CONFIG_HPP

#define __LIB_DLLAPI__	
// common include
#include "common/common.hpp"
#if KBE_PLATFORM == PLATFORM_WIN32
#pragma warning (disable : 4996)
#endif
//#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>	
#include <stdarg.h> 
#include "common/singleton.hpp"
#include "thread/threadmutex.hpp"
#include "thread/threadguard.hpp"
#include "xmlplus/xmlplus.hpp"	
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#include <errno.h>
#endif
	
namespace KBEngine
{

	// ���������Ϣ�ṹ��
	typedef struct EngineComponentInfo
	{
		EngineComponentInfo()
		{

		}

		~EngineComponentInfo()
		{

		}

		char			ip[MAX_BUF];									// �����������ip��ַ
		uint32			port;											// ��������к�����Ķ˿�
		COMPONENT_ID	componentID;
		
	}ENGINE_COMPONENT_INFO;


	typedef struct EngineDBConfig
	{
		char			db_ip[MAX_BUF];									// �����������ip��ַ
		char			db_username[MAX_NAME];							// ���ݿ���û���
		char			db_password[MAX_BUF * 10];						// ���ݿ������
		char			db_name[MAX_NAME];								// ���ݿ���
		uint32			db_port;
		uint16			db_maxconn;										// ���ݿ��������
	} ENGINE_DB_CONFIG;

	class ServerConfig : public Singleton<ServerConfig>
	{
	public:
		ServerConfig();
		~ServerConfig();
	
		bool loadConfig(std::string fileName);
		bool loadDBConfig(std::string fileName);
	
		INLINE ENGINE_COMPONENT_INFO& getCellApp(void);
		INLINE ENGINE_COMPONENT_INFO& getBaseApp(void);
		INLINE ENGINE_COMPONENT_INFO& getDBMgr(void);
		INLINE ENGINE_COMPONENT_INFO& getLoginApp(void);
		INLINE ENGINE_COMPONENT_INFO& getCellAppMgr(void);
		INLINE ENGINE_COMPONENT_INFO& getBaseAppMgr(void);
		INLINE ENGINE_COMPONENT_INFO& getComponent(COMPONENT_TYPE componentType);
 	
		INLINE ENGINE_COMPONENT_INFO& getConfig();
		INLINE ENGINE_DB_CONFIG&	  getDBconfig();
 		
	private:
		ENGINE_COMPONENT_INFO _cellAppInfo;
		ENGINE_COMPONENT_INFO _baseAppInfo;
		ENGINE_COMPONENT_INFO _dbmgrInfo;
		ENGINE_COMPONENT_INFO _loginAppInfo;
		ENGINE_COMPONENT_INFO _cellAppMgrInfo;
		ENGINE_COMPONENT_INFO _baseAppMgrInfo;


		ENGINE_DB_CONFIG	  _dbconfig;
	
	};

	#define g_kbeSrvConfig ServerConfig::getSingleton()
}


#ifdef CODE_INLINE
#include "serverconfig.ipp"
#endif
#endif // KBE_SERVER_CONFIG_HPP
