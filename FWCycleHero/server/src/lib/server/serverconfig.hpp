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

	class Address;
	// ���������Ϣ�ṹ��
	typedef struct EngineComponentInfo
	{
		EngineComponentInfo()
		{
			tcp_SOMAXCONN = 5;
			notFoundAccountAutoCreate = false;
			account_registration_enable = false;
			account_type = 3;
			debugDBMgr = false;

			externalAddress[0] = '\0';
		}

		~EngineComponentInfo()
		{
		}

		uint32 port;											// ��������к�����Ķ˿�
		char ip[MAX_BUF];										// �����������ip��ַ

		float defaultAoIRadius;									// ������cellapp�ڵ��е�player��aoi�뾶��С
		float defaultAoIHysteresisArea;							// ������cellapp�ڵ��е�player��aoi���ͺ�Χ
		uint16 witness_timeout;									// �۲���Ĭ�ϳ�ʱʱ��(��)
		COMPONENT_ID componentID;

		float ghostDistance;									// ghost�������
		uint16 ghostingMaxPerCheck;								// ÿ����ghost����
		uint16 ghostUpdateHertz;								// ghost����hz
	
		bool aliasEntityID;										// �Ż�EntityID��aoi��Χ��С��255��EntityID, ���䵽clientʱʹ��1�ֽ�αID 
		bool entitydefAliasID;									// �Ż�entity���Ժͷ����㲥ʱռ�õĴ���entity�ͻ������Ի��߿ͻ��˲�����255��ʱ�� ����uid������uid���䵽clientʱʹ��1�ֽڱ���ID


		char externalAddress[MAX_NAME];							// �ⲿIP��ַ
		int32 externalPorts;									// ����socket�˿�
		int32 internalPorts;									// ����socket�˿�

		char db_type[MAX_BUF];									// ���ݿ�����
		uint32 db_port;											// ���ݿ�Ķ˿�
		char db_ip[MAX_BUF];									// ���ݿ��ip��ַ
		char db_username[MAX_NAME];								// ���ݿ���û���
		char db_password[MAX_BUF * 10];							// ���ݿ������
		char db_name[MAX_NAME];									// ���ݿ���
		uint16 db_numConnections;								// ���ݿ��������
		std::string db_unicodeString_characterSet;				// �������ݿ��ַ���
		std::string db_unicodeString_collation;
		bool notFoundAccountAutoCreate;							// ��¼�Ϸ�ʱ��Ϸ���ݿ��Ҳ�����Ϸ�˺����Զ�����
		bool db_passwordEncrypt;								// db�����Ƿ��Ǽ��ܵ�
		bool allowEmptyDigest;									// �Ƿ���defs-MD5
		bool account_registration_enable;						// �Ƿ񿪷�ע��

		float archivePeriod;									// entity�洢���ݿ�����
		float backupPeriod;										// entity��������
		bool backUpUndefinedProperties;							// entity�Ƿ񱸷�δ��������
		uint16 entityRestoreSize;								// entity restoreÿtick���� 

		float loadSmoothingBias;								// baseapp������ƽ�����ֵ�� 
		uint32 login_port;										// ��������¼�˿� Ŀǰbots����
		char login_ip[MAX_BUF];									// ��������¼ip��ַ

		ENTITY_ID criticallyLowSize;							// idʣ����ô���ʱ��dbmgr�����µ�id��Դ

		uint32 downloadBitsPerSecondTotal;						// ���пͻ���ÿ�����ش���������
		uint32 downloadBitsPerSecondPerClient;					// ÿ���ͻ���ÿ������ش���

		uint32 defaultAddBots_totalCount;						// Ĭ���������̺��Զ������ô���bots ���������
		float defaultAddBots_tickTime;							// Ĭ���������̺��Զ������ô���bots ÿ���������ʱ��(s)
		uint32 defaultAddBots_tickCount;						// Ĭ���������̺��Զ������ô���bots ÿ���������

		std::string bots_account_name_prefix;					// �������˺����Ƶ�ǰ׺
		uint32 bots_account_name_suffix_inc;					// �������˺����Ƶĺ�׺����, 0ʹ������������� ������baseNum��д��������

		uint32 tcp_SOMAXCONN;									// listen�����������ֵ

		int8 encrypt_login;										// ���ܵ�¼��Ϣ

		uint32 telnet_port;
		std::string telnet_passwd;
		std::string telnet_deflayer;

		uint32 perSecsDestroyEntitySize;						// ÿ������base|entity����

		uint64 respool_timeout;
		uint32 respool_buffersize;

		uint8 account_type;										// 1: ��ͨ�˺�, 2: email�˺�(��Ҫ����), 3: �����˺�(�Զ�ʶ��email�� ��ͨ�����) 
		uint32 accountDefaultFlags;								// ���˺�Ĭ�ϱ��(ACCOUNT_FLAGS�ɵ��ӣ� ��дʱ��ʮ���Ƹ�ʽ) 
		uint64 accountDefaultDeadline;							// ���˺�Ĭ�Ϲ���ʱ��(��, �������ϵ�ǰʱ��)
	
		std::string http_cbhost;
		uint16 http_cbport;										// �û�http�ص��ӿڣ�������֤���������õ�

		bool debugDBMgr;										// debugģʽ�¿������д������Ϣ
	}ENGINE_COMPONENT_INFO;

	class ServerConfig : public Singleton<ServerConfig>
	{
	public:
		ServerConfig();
		~ServerConfig();
	
		bool loadConfig(std::string fileName);
	
		INLINE ENGINE_COMPONENT_INFO& getCellApp(void);
		INLINE ENGINE_COMPONENT_INFO& getBaseApp(void);
		INLINE ENGINE_COMPONENT_INFO& getDBMgr(void);
		INLINE ENGINE_COMPONENT_INFO& getLoginApp(void);
		INLINE ENGINE_COMPONENT_INFO& getCellAppMgr(void);
		INLINE ENGINE_COMPONENT_INFO& getBaseAppMgr(void);
		INLINE ENGINE_COMPONENT_INFO& getKBMachine(void);
		INLINE ENGINE_COMPONENT_INFO& getBots(void);
		INLINE ENGINE_COMPONENT_INFO& getMessagelog(void);
		INLINE ENGINE_COMPONENT_INFO& getBilling(void);

		INLINE ENGINE_COMPONENT_INFO& getComponent(COMPONENT_TYPE componentType);
 	
		INLINE ENGINE_COMPONENT_INFO& getConfig();

 		void updateInfos(bool isPrint, COMPONENT_TYPE componentType, COMPONENT_ID componentID, 
 					const Address& internalAddr, const Address& externalAddr);
 	
		void updateExternalAddress(char* buf);

		INLINE int16 gameUpdateHertz(void)const;
	
		INLINE const char* billingSystemAccountType()const;
		INLINE const char* billingSystemChargeType()const;

		INLINE const char* billingSystemThirdpartyAccountServiceAddr()const;
		INLINE uint16 billingSystemThirdpartyAccountServicePort()const;

		INLINE const char* billingSystemThirdpartyChargeServiceAddr()const;
		INLINE uint16 billingSystemThirdpartyChargeServicePort()const;

		INLINE uint16 billingSystemThirdpartyServiceCBPort()const;

		uint32 tcp_SOMAXCONN(COMPONENT_TYPE componentType);

		float shutdowntime(){ return shutdown_time_; }
		float shutdownWaitTickTime(){ return shutdown_waitTickTime_; }

		uint32 tickMaxSyncLogs()const { return tick_max_sync_logs_; }
	private:
		void _updateEmailInfos();

	private:
		ENGINE_COMPONENT_INFO _cellAppInfo;
		ENGINE_COMPONENT_INFO _baseAppInfo;
		ENGINE_COMPONENT_INFO _dbmgrInfo;
		ENGINE_COMPONENT_INFO _loginAppInfo;
		ENGINE_COMPONENT_INFO _cellAppMgrInfo;
		ENGINE_COMPONENT_INFO _baseAppMgrInfo;
		ENGINE_COMPONENT_INFO _kbMachineInfo;
		ENGINE_COMPONENT_INFO _botsInfo;
		ENGINE_COMPONENT_INFO _messagelogInfo;
		ENGINE_COMPONENT_INFO _billingInfo;
	public:
		int16 gameUpdateHertz_;
		uint32 tick_max_sync_logs_;

		// ÿ���ͻ���ÿ��ռ�õ�������
		uint32 bitsPerSecondToClient_;		
		float shutdown_time_;
		float shutdown_waitTickTime_;

		float callback_timeout_;										// callbackĬ�ϳ�ʱʱ��(��)
		float thread_timeout_;											// Ĭ�ϳ�ʱʱ��(��)

		uint32 thread_init_create_, thread_pre_create_, thread_max_create_;

	};

	#define g_kbeSrvConfig ServerConfig::getSingleton()
}


#ifdef CODE_INLINE
#include "serverconfig.ipp"
#endif
#endif // KBE_SERVER_CONFIG_HPP
