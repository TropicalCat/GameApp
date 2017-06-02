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
	
// common include	
#include "buffered_dbtasks.hpp"
#include "server/glw_main.hpp"
#include "server/serverapp.hpp"
#include "server/serverconfig.hpp"
#include "common/timer.hpp"
#include "network/endpoint.hpp"
#include "server/glw_resmgr.hpp"
#include "thread/threadpool.hpp"

//#define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif
	
namespace KBEngine
{

	class DBInterface;
	class BillingHandler;
	class SyncAppDatasHandler;

	class AppDBServer : public ServerApp, public Singleton<AppDBServer>
	{

	public:
		enum TimeOutType
		{
			TIMEOUT_TICK = TIMEOUT_SERVERAPP_MAX + 1,
			TIMEOUT_CHECK_STATUS
		};
	
		AppDBServer(EventDispatcher& dispatcher,
					 NetSession& ninterface, 
					 COMPONENT_TYPE componentType,
					 COMPONENT_ID componentID);

		~AppDBServer();
	
		
		void					handleTimeout(TimerHandle handle, void * arg);
		void					handleMainTick();
		void					handleCheckStatusTick();

		/* ��ʼ����ؽӿ� */
		virtual bool			inInitialize();
		virtual bool			initializeEnd();
		virtual void			finalise();
		virtual bool			run();
		virtual bool			canShutdown();


		bool					initDB();

		/** ����ӿ�
			�������һ��ENTITY_ID��
		*/
		static int			onReqAllocEntityID(int msgid, const MemoryStream* pNetCmd);

		/* ����ӿ�
			ע��һ���¼����baseapp����cellapp����dbmgr
			ͨ����һ���µ�app�������ˣ� ����Ҫ��ĳЩ���ע���Լ���
		*/
		virtual void		onRegisterNewApp(
												int32 uid, 
												std::string& username, 
												COMPONENT_TYPE componentType, COMPONENT_ID componentID, COMPONENT_ORDER globalorderID, COMPONENT_ORDER grouporderID,
												uint32 intaddr, uint16 intport, uint32 extaddr, uint16 extport, std::string& extaddrEx);


		/** ����ӿ�
			dbmgr�㲥global���ݵĸı�
		*/
		void				onGlobalDataClientLogon(Channel* pChannel, COMPONENT_TYPE componentType);
		void				onBroadcastGlobalDataChanged(Channel* pChannel, KBEngine::MemoryStream& s);
	
	
		/** ����ӿ�
			��������ͻ�����������
		*/
		void				eraseClientReq(Channel* pChannel, std::string& logkey);

		/** ����ӿ�
			һ�����û���¼�� ��Ҫ���Ϸ���
		*/
		void				onAccountLogin(Channel* pChannel, KBEngine::MemoryStream& s);
		void				onLoginAccountCBBFromBilling(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			baseapp�����ѯaccount��Ϣ
		*/
		void				queryAccount(Channel* pChannel, std::string& accountName, std::string& password, 
											COMPONENT_ID componentID, ENTITY_ID entityID, DBID entityDBID, uint32 ip, uint16 port);

		/** ����ӿ�
			�˺Ŵ�baseapp������
		*/
		void				onAccountOnline(Channel* pChannel, std::string& accountName, 
											COMPONENT_ID componentID, ENTITY_ID entityID);


		/** ����ӿ�
			ִ�����ݿ��ѯ
		*/
		void				executeRawDatabaseCommand(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			ĳ��entity�浵
		*/
		void				writeEntity(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			ɾ��ĳ��entity�Ĵ浵����
		*/
		void				removeEntity(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			ͨ��dbid�����ݿ���ɾ��һ��ʵ��Ļص�
		*/
		void				deleteBaseByDBID(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			ͨ��dbid��ѯһ��ʵ���Ƿ�����ݿ���
		*/
		void				lookUpBaseByDBID(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			�����db��ȡentity����������
		*/
		void				queryEntity(Channel* pChannel, COMPONENT_ID componentID, int8	queryMode, DBID dbid, 
										std::string& entityType, CALLBACK_ID callbackID, ENTITY_ID entityID);

		/** ����ӿ�
			ͬ��entity��ģ��
		*/
		void				syncEntityStreamTemplate(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			�����ֵ
		*/
		void				charge(Channel* pChannel, KBEngine::MemoryStream& s);

		/** ����ӿ�
			��ֵ�ص�
		*/
		void				onChargeCB(Channel* pChannel, KBEngine::MemoryStream& s);


		/** ����ӿ�
			����ص�
		*/
		void				accountActivate(Channel* pChannel, std::string& scode);

		/** ����ӿ�
			�˺���������
		*/
		void				accountReqResetPassword(Channel* pChannel, std::string& accountName);
		void				accountResetPassword(Channel* pChannel, std::string& accountName, std::string& newpassword, std::string& code);

		/** ����ӿ�
			�˺Ű�����
		*/
		void				accountReqBindMail(Channel* pChannel, ENTITY_ID entityID, std::string& accountName, std::string& password, std::string& email);
		void				accountBindMail(Channel* pChannel, std::string& username, std::string& scode);

		/** ����ӿ�
			�˺��޸�����
		*/
		void				accountNewPassword(Channel* pChannel, ENTITY_ID entityID, std::string& accountName, std::string& password, std::string& newpassword);
	
		SyncAppDatasHandler* GetSyncAppDatasHandler()const					{ return pSyncAppDatasHandler_; }
		void				 SetSyncAppDatasHandler(SyncAppDatasHandler* p)	{ pSyncAppDatasHandler_ = p; }
	protected:
		TimerHandle							loopCheckTimerHandle_;
		TimerHandle							mainProcessTimer_;

														
		// ���񻺳�����
		Buffered_DBTasks					bufferedDBTasks_;			

		// Statistics
		uint32								numWrittenEntity_;
		uint32								numRemovedEntity_;
		uint32								numQueryEntity_;
		uint32								numExecuteRawDatabaseCommand_;
		uint32								numCreatedAccount_;

		BillingHandler*						pBillingAccountHandler_;
		BillingHandler*						pBillingChargeHandler_;

		SyncAppDatasHandler*				pSyncAppDatasHandler_;
	};

}

#endif // KBE_DBMGR_HPP
