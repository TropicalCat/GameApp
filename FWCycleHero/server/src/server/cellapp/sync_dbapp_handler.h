/*
----------------------------------------------------------------------------------------------
			file name : sync_dbapp_handler.h
			desc	  : DB Server �� Cell Server ��Э�鴦��ӿ�
			author	  : ljp

			log		  : by ljp create 2017-06-10
----------------------------------------------------------------------------------------------
*/
#pragma once
#include "network/net_define.h"
#include "network/simple_map.h"
#include "helper/debug_helper.hpp"
#include "common/common.hpp"







namespace KBEngine
{

	class CDBSession;
	typedef UINT32(CDBSession::*DBNETMSGHANDLER)(MemoryStream* pMsg);
	class CDBAppNetCmdMgr
	{

	public:

		//-------------------------------------------------------------------------------------
		// ���캯��
		 CDBAppNetCmdMgr();
		~CDBAppNetCmdMgr();

		void					Destroy(void);

		bool					Register(UINT32 szCmd, DBNETMSGHANDLER fp, char* szDesc);
		void					UnRegisterAll();


		DBNETMSGHANDLER			GetMsgHandler(UINT32 dwMsgID, UINT32 nSize);

	protected:

		typedef struct tagPlayerCmd
		{
			UINT32				strCmd;			// ������
			std::string			strDesc;		// ����
			DBNETMSGHANDLER		handler;		// ����ָ��
			UINT32				nTimes;			// �յ�������Ĵ���
		} tagPlayerCmd;

		TMap<UINT32, tagPlayerCmd*>		m_mapProc;
	};
}


