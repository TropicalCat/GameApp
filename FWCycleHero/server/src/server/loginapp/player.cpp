/*
----------------------------------------------------------------------------
	file name : player.hpp
	desc	  : ��¼����������ĵ�¼���˺�
	author    : LJP

	log		  : [ 2016-02-27 ]
----------------------------------------------------------------------------
*/
#include "player.hpp"
#include "msg_cl.h"
#include "msg_login.h"






namespace KBEngine
{

	
	//-------------------------------------------------------------------------------
	// ���캯��
	//-------------------------------------------------------------------------------
	Player::Player(uint32 dwClientID, uint32 dwCDIndex, uint32 dwIP, uint32 dwWorldID) :
					m_Data(), m_bConnLost(false), m_nVerifyCode(0), m_bProofEnd(false),
					m_bProofing(false), m_bNeedMibao(false), m_bSelectWorldOk(false)
	{
		m_Data.dwClientID	= dwClientID;
		m_Data.dwCDIndex	= dwCDIndex;
		m_Data.dwAccountID	= GT_INVALID;
		m_Data.dwFrobidMask = 0;
		m_Data.bGuard		= FALSE;
		m_Data.nAccOLSec	= 0;
		m_Data.dwIP			= dwIP;
		m_Data.dwWorldNameCrc = dwWorldID;
		m_Data.byPrivilege	= 0;
	}

	//-------------------------------------------------------------------------------
	// ��������
	//-------------------------------------------------------------------------------
	Player::~Player()
	{

	}

	//-------------------------------------------------------------------------------
	// ��֤����
	//-------------------------------------------------------------------------------
	void Player::ProofReturn(tagProofResult* pResult)
	{
		m_Data.dwAccountID		= pResult->dwAccountID;
		m_Data.bGuard			= pResult->bGuard;
		m_Data.nAccOLSec		= pResult->nGuardAccuTime;
		m_Data.byPrivilege		= pResult->byPrivilege;
		m_Data.dwFrobidMask		= pResult->dwFrobidMask;
		SetProofEnd();
	}

	//-------------------------------------------------------------------------------
	// ע����Ϣ������
	//-------------------------------------------------------------------------------
	void Player::RegisterPlayerMsg()
	{
		//m_playerNetMgr.Register(NLC_Proof, &HandleProof, "NLC_Proof");
	}

	//-------------------------------------------------------------------------------
	// ע����Ϣ������
	//-------------------------------------------------------------------------------
	void Player::UnRegisterPlayerMsg()
	{
		//m_playerNetMgr.UnRegisterAll();
	}

	
	//-----------------------------------------------------------------------------
	// �����֤��Ϣ
	//-----------------------------------------------------------------------------
	UINT32 Player::HandleProof(tagNetCmd* pCmd)
	{
		//tagNLC_Proof* pRecv = (tagNLC_Proof*)pCmd;
		//
		//// ��ֹ�ַ������
		//pRecv->szUserName[X_SHORT_NAME - 1]	= '\0';
		//pRecv->szPsd[MAX_MD5_ARRAY - 1]		= '\0';
		//pRecv->szGUID[X_LONG_NAME - 1]		= '\0';

		return 0;
	}
}
