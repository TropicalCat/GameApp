//-----------------------------------------------------------------------------
//!\file net_define.h
//!\Auth:
//!
//!\date 2004-07-14
//! last 2004-07-14
//!
//!\brief ����ͻ���ͨѶ�ײ��������
//-----------------------------------------------------------------------------
#pragma once
#include "common/common.hpp"







namespace KBEngine 
{
	CONST INT32 GT_NET_BLOCK_TIME = 1000*150;	// 150 ms
	#pragma pack(push, 1)

	//-----------------------------------------------------------------------------
	// ������Ϣ�����ṹ
	//-----------------------------------------------------------------------------
	class MemoryStream;
	class tagNetCmd
	{
	public:
		  tagNetCmd(int32 ID){ dwID = ID; dwSize = dwSize = sizeof(*this); }
		 ~tagNetCmd(){}


		 virtual void	Serialize(MemoryStream* pNetStream )		{}
		 virtual void	UnSerialize(MemoryStream* pNetStream )		{}

	public:
		int32			dwID;
		int32			dwSize;
	};

	struct tagNetCmdE
	{
		int32			dwSize;
		int32			dwID;
	};

	//-----------------------------------------------------------------------------
	// ����������Ϣ�Ķ���
	//-----------------------------------------------------------------------------
	#ifndef CMD_START

	#define CMDT( name ) tag##name

	
	// ��Ϊ����������캯�����ԾͲ�����POD���͡���
	#define CMD_START(name)											\
	struct  CMDT(name) : public tagNetCmdE{							\
			CMDT(name)(){ memset(this, 0, sizeof(*this));			\
						  dwID = name; dwSize = sizeof(*this);}
	#define CMD_END		};


	#endif

	#pragma pack(pop)


	#define X_LONG_NAME				256
	#define X_SHORT_NAME			32
} 
