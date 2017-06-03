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
#include "server/serverconfig.hpp"
#include "server/serverconfig.hpp"
#include "common/timer.hpp"
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

	class AppDBServer : public Singleton<AppDBServer>
	{

	public:
	
		 AppDBServer();
		~AppDBServer();
	
		
		bool						Initialize(COMPONENT_TYPE componentType);
		void						MainLoop(void);

		/* ��ʼ����ؽӿ� */
		/* ��ʼ����ؽӿ� */
		bool						initDB();
		bool						InitializeEnd();
		void						Destroy(void);

	protected:
		
		COMPONENT_TYPE				mComponentType;		
		
	};

}

#endif // KBE_DBMGR_HPP
