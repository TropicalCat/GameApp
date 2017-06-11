/*
---------------------------------------------------------------------------------------------
		file name :
		desc	  : ����������������
		author    : ljp

		log       : by ljp create 2017-06-11
---------------------------------------------------------------------------------------------
*/


#ifndef KBE_CELLAPPMGR_H
#define KBE_CELLAPPMGR_H
#include "cellapp.h"
#include "server/serverconfig.hpp"
#include "CellSessionMgr.h"
#include "network/event_dispatcher.hpp"






namespace KBEngine{


	class Cellappmgr : public Singleton<Cellappmgr>
	{
	public:
	
		 Cellappmgr();
		~Cellappmgr();
	
		bool						Initialize(COMPONENT_TYPE componentType);
		void						MainLoop(void);

		/* ��ʼ����ؽӿ� */
		/* ��ʼ����ؽӿ� */
		bool						initDB();
		bool						InitializeEnd();
		void						Destroy(void);
	protected:

		COMPONENT_TYPE				mComponentType;
		CCellAppSessionMgr*			m_pCellSessionMgr;
		EventDispatcher*			m_pDispatcher;


		std::map< COMPONENT_ID, Cellapp >	cellapps_;
	};

}

#endif // KBE_CELLAPPMGR_H
