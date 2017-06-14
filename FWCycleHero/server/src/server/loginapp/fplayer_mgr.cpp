/*
----------------------------------------------------------------------------
	file name : fplayer_mgr.cpp
	desc	  : ��¼�����˺ŷ�������client �Ĺ���
	author    : LJP

	log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#include "fplayer_mgr.hpp"
#include "player.hpp"
#include "server/serverconfig.hpp"







namespace KBEngine
{

	KBE_SINGLETON_INIT(CPlayerMgr);
	//-------------------------------------------------------------------------------
	// ���캯��
	//-------------------------------------------------------------------------------
	CPlayerMgr::CPlayerMgr() : m_nPlayerNum(0), m_nPlayerLoging(0), m_nProofResultNum(0),
							   m_dwClientIDGen(0), m_dwCurrVer(0), m_nPort(0), 
							   m_ePolicy(EPP_Null)
	{

	}

	//-------------------------------------------------------------------------------
	// ��������
	//-------------------------------------------------------------------------------
	CPlayerMgr::~CPlayerMgr()
	{
		Destroy();
	}


	//-------------------------------------------------------------------------------
	// ���ٺ���
	//-------------------------------------------------------------------------------
	void CPlayerMgr::AddPlayerToAll(Player* pPlayer)				
	{ 
		m_mapAllPlayer.Add(pPlayer->GetClientID(), pPlayer); 
	}

	//-------------------------------------------------------------------------------
	// ���ٺ���
	//-------------------------------------------------------------------------------
	void CPlayerMgr::AddPlayerToLogining(Player* pPlayer)		
	{
		m_mapLoginingPlayer.Add(pPlayer->GetClientID(), pPlayer);
	}

	//-------------------------------------------------------------------------------
	// ���ٺ���
	//-------------------------------------------------------------------------------
	void CPlayerMgr::RemoveAccount(UINT32 dwAccountID)
	{
		if (!P_VALID(dwAccountID))
			return;
		m_mapAccountIDClientID.Erase(dwAccountID);
	}

	
	//-------------------------------------------------------------------------------
	// ���ٺ���
	//-------------------------------------------------------------------------------
	void CPlayerMgr::Destroy()
	{
		/////////////////////////////////////////////////////
		m_mapAllPlayer.Clear();
		m_mapAccountData.Clear();
		m_listProofResult.Clear();
		m_mapLoginingPlayer.Clear();
		m_mapAccountIDClientID.Clear();
		m_mapAccountNameCrc2AccountID.Clear();
		/////////////////////////////////////////////////////

		Player::UnRegisterPlayerMsg();
		// ����
		// ������ڵ�¼�����
		Player* pPlayer = NULL;
		m_mapLoginingPlayer.ResetIterator();
		while (m_mapLoginingPlayer.PeekNext(pPlayer))
		{
			SAFE_DEL(pPlayer);
		}
		// ��֤��������
		//m_pPolicy->Destroy();
	}


	//-------------------------------------------------------------------------------
	// ���º���
	//-------------------------------------------------------------------------------
	void CPlayerMgr::Update()
	{
		// ������֤���
		UpdateProofResult();
	}


	//---------------------------------------------------------------------------------
	// ��ҵǳ�
	//---------------------------------------------------------------------------------
	void CPlayerMgr::PlayerLogout(Player* pPlayer)
	{
		bool bLogoutFromDB = true;		// �Ƿ��������ݿ��и����Ϊ����
		if (!pPlayer->IsProofEnd() || GT_INVALID == pPlayer->GetAccountID())	// ��û����֤�ɹ������ݿ������û�в�����
		{
			bLogoutFromDB = false;
		}
		else if (pPlayer->IsSelectWorldOk())	// world�Ѿ����˻�Ӧ��˵�����Ͼͻ���뵽world��
		{
			bLogoutFromDB = false;
		}

		// �����Ҫ�������ݿ�
		/*if (bLogoutFromDB)
		{
			sBeton.PlayerLogout(pPlayer->GetAccountID());
		}*/

		// ����ʺźϷ������Ƴ��ʺ�
		if (GT_INVALID != pPlayer->GetAccountID())
		{
			RemoveAccount(pPlayer->GetAccountID());
		}

		// ���б���ɾ�������
		RemovePlayerFromAll(pPlayer->GetClientID());

		// ɾ�����
		SAFE_DEL(pPlayer);
	}

	//------------------------------------------------------------------------------------
	// ������֤
	//------------------------------------------------------------------------------------
	void CPlayerMgr::Proof(UINT32 dwClientID, char* szAccoutName, char* szPsd, char* szGUID)
	{
		if (!P_VALID(szAccoutName) || !P_VALID(szPsd) || !P_VALID(szGUID))
			return;

		// ���͸���Ӧ����֤���Խ�����֤
		// m_pPolicy->Proof(dwClientID, szAccoutName, szPsd, szGUID);
	}
}
