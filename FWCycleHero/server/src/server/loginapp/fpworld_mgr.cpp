/*
----------------------------------------------------------------------------
		file name : fpworld_mgr.hpp
		desc	  : �������е���Ϸ������
		author    : LJP

		log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#include "common/common.hpp"
#include "fpworld_mgr.hpp"






namespace KBEngine
{
	KBE_SINGLETON_INIT(FpWorldMgr);
	//------------------------------------------------------------------------------
	// ���캯��
	//------------------------------------------------------------------------------
	FpWorldMgr::FpWorldMgr()
	{
		//g_pWorldServerMgr = this;
	}

	//------------------------------------------------------------------------------
	// ��������
	//------------------------------------------------------------------------------
	FpWorldMgr::~FpWorldMgr()
	{
		Destroy();
	}

	//-------------------------------------------------------------------------------
	// ��ʼ������
	//-------------------------------------------------------------------------------
	bool FpWorldMgr::Init()
	{
		return true;
	}

	//-------------------------------------------------------------------------------
	// ���ٺ���
	//-------------------------------------------------------------------------------
	void FpWorldMgr::Destroy()
	{
		// ���fpworld����
		fpWorld* pFWorld = NULL;
		m_mapFpWorld.ResetIterator();
		while (m_mapFpWorld.PeekNext(pFWorld))
		{
			SAFE_DEL(pFWorld);
		}
		m_mapFpWorld.Clear();
		UnRegisterFpWorldMsg();
	}

	//-------------------------------------------------------------------------------
	// ���º���
	//-------------------------------------------------------------------------------
	void FpWorldMgr::Update()
	{
		// ����ÿһ��world
		fpWorld* pfWorld = NULL;
		m_mapFpWorld.ResetIterator();
		while (m_mapFpWorld.PeekNext(pfWorld))
		{
			pfWorld->Update();
			UpdateWorldState(pfWorld);
		}
	}

	//-------------------------------------------------------------------------------
	// ��������״̬
	//-------------------------------------------------------------------------------
	void FpWorldMgr::UpdateWorldState(fpWorld* pWorld)
	{
		
	}

	//-------------------------------------------------------------------------------
	// ע��������Ϣ
	//-------------------------------------------------------------------------------
	void FpWorldMgr::RegisterFpWorldMsg()
	{
		/*m_pMsgCmdMgr->Register(NWL_Certification, m_Trunk.sfp2(&FpWorldMgr::HandleCertification), _T("NWL_Certification"));
		m_pMsgCmdMgr->Register(NWL_WorldStatus, m_Trunk.sfp2(&FpWorldMgr::HandleZoneServerStatus), _T("NWL_WorldStatus"));
		m_pMsgCmdMgr->Register(NWL_PlayerWillLogin, m_Trunk.sfp2(&FpWorldMgr::HandlePlayerWillLogin), _T("NWL_PlayerWillLogin"));
		m_pMsgCmdMgr->Register(NWL_PlayerLogin, m_Trunk.sfp2(&FpWorldMgr::HandlePlayerLogin), _T("NWL_PlayerLogin"));
		m_pMsgCmdMgr->Register(NWL_PlayerLogout, m_Trunk.sfp2(&FpWorldMgr::HandlePlayerLogout), _T("NWL_PlayerLogout"));
		m_pMsgCmdMgr->Register(NWL_KickLog, m_Trunk.sfp2(&FpWorldMgr::HandleKickLog), _T("NWL_KickLog"));
		m_pMsgCmdMgr->Register(NWL_WorldColsed, m_Trunk.sfp2(&FpWorldMgr::HandleWorldClosed), _T("NWL_WorldColsed"));*/
	}

	//------------------------------------------------------------------------
	// ��ע��������Ϣ
	//------------------------------------------------------------------------
	void FpWorldMgr::UnRegisterFpWorldMsg()
	{
		//m_pMsgCmdMgr->Destroy();
	}

	//------------------------------------------------------------------------
	// ��½�ص�
	//------------------------------------------------------------------------
	UINT32 FpWorldMgr::LoginCallBack(uchar* pByte, UINT32 dwSize)
	{
		return 0;
	}

	//----------------------------------------------------------------------------
	// �ǳ��ص�
	//----------------------------------------------------------------------------
	UINT32 FpWorldMgr::LogoutCallBack(UINT32 dwParam)
	{
		return 0;
	}

	//------------------------------------------------------------------------------
	// ��ӵ���Ϸ����
	//------------------------------------------------------------------------------
	void FpWorldMgr::AddToWorld(Player* pPlayer, UINT32 dwWorldNameCrc)
	{
		if (!P_VALID(pPlayer)) return;

		fpWorld* pWorld = GetFpWorld(dwWorldNameCrc);
		if (!P_VALID(pWorld)) return;

		pWorld->AddPlayer(pPlayer);

		// д�����ݿ�
		//sBeton.PlayerLogin(pPlayer->GetAccountID(), dwWorldNameCrc);
	}
}