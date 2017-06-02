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
#include "network/event_poller.hpp"
#include "network/event_dispatcher.hpp"
#include "server/serverconfig.hpp"







namespace KBEngine
{

	KBE_SINGLETON_INIT(CPlayerMgr);
	//-------------------------------------------------------------------------------
	// ���캯��
	//-------------------------------------------------------------------------------
	CPlayerMgr::CPlayerMgr() : m_nPlayerNum(0), m_nPlayerLoging(0), m_nProofResultNum(0),
							   m_dwClientIDGen(0), m_dwCurrVer(0), m_nPort(0), 
							   m_ePolicy(EPP_Null), m_pNetSessionMgr(0)
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
	// ��ʼ������
	//-------------------------------------------------------------------------------
	bool CPlayerMgr::Init(void)
	{
		INFO_MSG("-----------------------------------------------------------------------------------------\n");
		INFO_MSG("Statr CPlayerMgr new EventDispatcher \n");
		m_pDispatcher = new EventDispatcher();

		INFO_MSG("Load config files \n");
		g_kbeSrvConfig.loadConfig("config/kbengine_defs.xml");
		g_kbeSrvConfig.loadConfig("config/kbengine.xml");

		// init net work
		InitNetWork();
		return true;
	}

	//-------------------------------------------------------------------------------
	// function : 
	// desc		: ��ʼ������������
	//-------------------------------------------------------------------------------
	void CPlayerMgr::InitNetWork(void)
	{
		if (m_pNetSessionMgr == NULL)
		{
			m_pNetSessionMgr = new CLoginSessionMgr();
		}

		// �������ڶ�λ����socket
		ENGINE_COMPONENT_INFO& info = g_kbeSrvConfig.getLoginApp();
		if (m_pDispatcher->pPoller() != NULL)
		{
			m_pDispatcher->pPoller()->InitNetEngine(info.internalPorts);
			m_pDispatcher->pPoller()->SetSessionFactory(m_pNetSessionMgr);
		}
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
		// ���������Ϣ
		UpdateSession();

		// ������֤���
		UpdateProofResult();
	}

	//-------------------------------------------------------------------------------
	// ���������Ϣ
	//-------------------------------------------------------------------------------
	void CPlayerMgr::UpdateSession()
	{
		if (m_pNetSessionMgr != nullptr)
		{
			m_pNetSessionMgr->UpdateSession();
		}
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
