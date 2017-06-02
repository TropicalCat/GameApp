/*
----------------------------------------------------------------------------
	file name : fplayer_mgr.hpp
	desc	  : ��¼�����˺ŷ�������client �Ĺ���
	author    : LJP

	log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#pragma once
#include "common/singleton.hpp"







namespace KBEngine
{
	//-----------------------------------------------------------------------------
	// ��Ϸ����״̬
	//-----------------------------------------------------------------------------
	enum EWorldStatus
	{
		EWS_Well = 0,		// ����
		EWS_InitNotDone = 1,		// δ��ʼ�����
		EWS_SystemError = 2,		// ϵͳ���ֹ���
		EWS_ProofError = 3,		// ��֤����������
	};

	//------------------------------------------------------------------------------
	// ��֤����
	//------------------------------------------------------------------------------
	enum EProofPolicy
	{
		EPP_Null = -1,
		EPP_Test = 0,		// ����ר��
		EPP_Own = 1,		// �Լ���˾��֤����
		EPP_XunLei = 2,		// xunlei

		EPP_End = 3
	};

	//------------------------------------------------------------------------------
	// ��ҵ�¼ʱ��״̬
	//------------------------------------------------------------------------------
	enum  EPlayerLoginStatus
	{
		EPLS_Null = -1,		// ��Ч
		EPLS_OffLine = 0,		// ����
		EPLS_Online = 1,		// ����
		EPLS_Loging = 2,		// ��¼��
		EPLS_Unknown = 3,		// δ֪
	};

	//-----------------------------------------------------------------------------
	// ��֤����ṹ
	//-----------------------------------------------------------------------------
	struct tagProofResult
	{
		UINT32					dwClientID;			// �ͻ���ID
		UINT32					dwAccountID;		// �ʺ�ID
		bool					bGuard;				// ������
		UINT32					nGuardAccuTime;		// �������ۻ�ʱ��
		EPlayerLoginStatus		eLoginStatus;		// ��½״̬
		UINT32					dwWorldNameCrc;		// ��ǰ��½����Ϸ����
		UINT32					dwFrobidMask;		// ��ͣ���� ÿ1λ��Ӧһ�ַ�ͣ����
		uchar					byPrivilege;		// Ȩ��
		bool					bNeedMibao;			// �Ƿ�ʹ���ܱ�
		UINT32					dwPreLoginIP;		// �ϴε�¼ip
		uchar					byReserved[2];		// ����������

		tagProofResult()
		{
			dwClientID = GT_INVALID;
			dwAccountID = GT_INVALID;
			bGuard = FALSE;
			nGuardAccuTime = 0;
			eLoginStatus = EPLS_OffLine;
			byPrivilege = 0;
			bNeedMibao = false;
			dwFrobidMask = 0;
			dwPreLoginIP = 0;
		}
	};


	struct tagProofResultFull : public tagProofResult
	{
		INT32 nRet;		// ���ؽ��
	};


	//----------------------------------------------------------------
	// ��¼��һ�����Ϣ sizeof = 396
	//----------------------------------------------------------------
	struct tagAccountData
	{
		char*				szAccountName[32];
		uint32				dwIp;
		bool				bGuard;
	};

	//------------------------------------------------------------------------------
	// fpworld��ǰ��Ϣ
	//------------------------------------------------------------------------------
	struct tagWorldInfo
	{

		UINT32			dwNameCrc;					// ����CRCֵ
		UINT32			dwWorldID;					// worldid
		UINT32			dwIP;						// IP
		UINT32			nPort;						// �˿�
		UINT32			nMaxOnlineNum;				// �����������
		UINT32			nCurOnlineNum;				// ��ǰ��������
		bool			bAutoSeal;					// �Ƿ��Զ�
		bool			bValid;						// ��ǰ�Ƿ�����
		char			szName[32];					// World����
		EWorldStatus	eStatus;					// ��ǰ״̬


		tagWorldInfo()
		{
			memset(this, 0, sizeof(*this));
		}
	};
}

