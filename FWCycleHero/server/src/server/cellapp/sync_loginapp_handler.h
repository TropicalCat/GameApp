/*
----------------------------------------------------------------------------------------------
			file name : sync_loginapp_handler.h
			desc	  : �������������¼����������Э�鴦��
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

	class CLoginSession;
	typedef UINT32(CLoginSession::*LOGINNETMSGHANDLER)(MemoryStream* pMsg);
	class CLoginAppNetCmdMgr
	{

	public:

		//-------------------------------------------------------------------------------------
		// ���캯��
		 CLoginAppNetCmdMgr();
		~CLoginAppNetCmdMgr();

		void					Destroy(void);

		bool					Register(UINT32 szCmd, LOGINNETMSGHANDLER fp, char* szDesc);
		void					UnRegisterAll();


		LOGINNETMSGHANDLER		GetMsgHandler(UINT32 dwMsgID, UINT32 nSize);

	protected:

		typedef struct tagPlayerCmd
		{
			UINT32				strCmd;			// ������
			std::string			strDesc;		// ����
			LOGINNETMSGHANDLER	handler;		// ����ָ��
			UINT32				nTimes;			// �յ�������Ĵ���
		} tagPlayerCmd;

		TMap<UINT32, tagPlayerCmd*>		m_mapProc;
	};
}


