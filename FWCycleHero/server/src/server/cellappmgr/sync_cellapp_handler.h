/*
----------------------------------------------------------------------------------------------
			file name : sync_app_handler.h
			desc	  : �ͻ��˷���Cell Server ��Э�鴦��ӿ�
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

	class CCellSession;
	typedef UINT32(CCellSession::*CELLNETMSGHANDLER)(MemoryStream* pMsg);
	class CCellAppNetCmdMgr
	{

	public:

		//-------------------------------------------------------------------------------------
		// ���캯��
		CCellAppNetCmdMgr();
		~CCellAppNetCmdMgr();

		void					Destroy(void);

		bool					Register(UINT32 szCmd, CELLNETMSGHANDLER fp, char* szDesc);
		void					UnRegisterAll();


		CELLNETMSGHANDLER		GetMsgHandler(UINT32 dwMsgID, UINT32 nSize);

	protected:

		typedef struct tagPlayerCmd
		{
			UINT32				strCmd;			// ������
			std::string			strDesc;		// ����
			CELLNETMSGHANDLER	handler;		// ����ָ��
			UINT32				nTimes;			// �յ�������Ĵ���
		} tagPlayerCmd;

		TMap<UINT32, tagPlayerCmd*>		m_mapProc;
	};
}


