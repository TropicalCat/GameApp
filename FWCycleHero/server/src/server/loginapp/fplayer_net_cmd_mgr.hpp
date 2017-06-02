/*
----------------------------------------------------------------------------
	//��Name				:   player_net_cmd_mgr.h
	//��Compiler			:	Microsoft Visual C++ 9.0
	//��Version				:	1.00
	//��Create Date			:	05/31/2009
	//��LastModified		:	05/31/2009
	//��Copyright (C)		:	
	//��Writen  by			:   
	//��Mode  by			:   
	//��Brief				:	�ͻ����������������Ҫ���NetCmdMgr�޷���Զ������Ϣ�����ȱ��
//////////////////////////////////////////////////////////////////////////
----------------------------------------------------------------------------
*/
#ifndef __FPLAYER_NET_CMD_MGR_H__
#define __FPLAYER_NET_CMD_MGR_H__
#include "common/common.hpp"
#include "common/memorystream.hpp"
#include "network/net_define.h"
#include "network/simple_map.h"







namespace KBEngine
{
	class CPlayerSession;
	typedef UINT32(CPlayerSession::*NETMSGHANDLER)(MemoryStream* pMsg);
	class PlayerNetCmdMgr
	{

	public:

		//-------------------------------------------------------------------------------------
		// ���캯��
		 PlayerNetCmdMgr();
		~PlayerNetCmdMgr();

		void					Destroy(void);

		bool					Register(UINT32 szCmd, NETMSGHANDLER fp, char* szDesc);
		void					UnRegisterAll();


		NETMSGHANDLER			GetMsgHandler(UINT32 dwMsgID, UINT32 nSize);
		
	protected:

		typedef struct tagPlayerCmd
		{
			UINT32				strCmd;			// ������
			std::string			strDesc;		// ����
			NETMSGHANDLER		handler;		// ����ָ��
			UINT32				nTimes;			// �յ�������Ĵ���
		} tagPlayerCmd;

		TMap<UINT32, tagPlayerCmd*>		m_mapProc;
	};
}

#endif
