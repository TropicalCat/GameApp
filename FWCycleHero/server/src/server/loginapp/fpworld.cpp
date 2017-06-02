/*
----------------------------------------------------------------------------
		file name : fpworld.hpp
		desc	  : ����������ʵ��
		author    : LJP

		log		  : [ 2015-08-24 ]
----------------------------------------------------------------------------
*/
#include "fpworld.hpp"
#include "fpworld_mgr.hpp"





namespace KBEngine
{
	//------------------------------------------------------------------------------
	// CONSTANTS
	//------------------------------------------------------------------------------
	const INT32	ALLOW_PLAYER_LOGIN = 2;		// �������һ���˽�������
	const INT32	UPDATE_QUEUE_TIME = 2000;	// �����Ŷ��б�ʱ����
	const FLOAT	LOGIN_LIMIT = 0.9f;	// ���ﵽfpworld�������޵�90%,�Ϳ�ʼ�Ŷ�
	fpWorld::fpWorld() : m_Data(), m_dwTime(0)
	{

	}

	fpWorld::~fpWorld()
	{
		Destroy();
	}


	////-------------------------------------------------------------------------------
	//// ��ʼ������
	////-------------------------------------------------------------------------------
	//bool fpWorld::Init(INT32 nIndex)
	//{
	//	// ����fpworld Data�е�����
	//	m_Data.bValid			= false;
	//	m_Data.eStatus			= EWS_InitNotDone;
	//	m_Data.nCurOnlineNum	= 0;
	//	m_Data.nMaxOnlineNum	= 0;
	//	m_Data.dwIP				= 0;
	//	m_Data.nPort			= 0;
	//	//temp add by songg
	//	m_Data.dwWorldID		= 1;
	//	return true;
	//}


	//-------------------------------------------------------------------------------
	// ���º���
	//-------------------------------------------------------------------------------
	void fpWorld::Update()
	{
	//	if ( IsValid() )
	//	{
	//		// ��������������Ϣ
	//		UpdateSession();

	//		// �������м��뵽��Ϸ��������
	//		UpdateInsertPlayer();

	//		// ���������Ŷӵ����
	//		UpdateQueuedPlayer();

	//		// �������еȴ��б��е����
	//		UpdateWaitingPlayer();

	//		// �����ߵ��б��е����
	//		UpdateKickedPlayer();
	//	}
	//	else
	//	{
	//		// �����ߵ��б��е����
	//		UpdateKickedPlayer();
	//	}
	}

	////-------------------------------------------------------------------------------
	//// ��������
	////-------------------------------------------------------------------------------
	//void fpWorld::UpdateSession()
	//{
	//	uchar* pRecv	= NULL;
	//	UINT32 dwSize   = 0;
	//	INT32  nUnRecv  = 0;
	//	UINT32 dwTime   = 0;
	//	pRecv = sFpWorldMgr.RecvMsg(m_Data.dwNameCrc, dwSize, nUnRecv);
	//	while (P_VALID(pRecv) )
	//	{
	//		// ������Ϣ
	//		sFpWorldMgr.HandleCmd((tagNetCmd*)pRecv, dwSize, (DWORD)this);

	//		// �黹��Ϣ
	//		sFpWorldMgr.ReturnMsg(m_Data.dwNameCrc, pRecv);

	//		// ��ȡ��һ����Ϣ
	//		pRecv = sFpWorldMgr.RecvMsg(m_Data.dwNameCrc, dwSize, nUnRecv);
	//	}
	//}

	////-------------------------------------------------------------------------------
	//// ���²��������б�
	////-------------------------------------------------------------------------------
	//void fpWorld::UpdateInsertPlayer()
	//{
	//	if (!m_Data.bValid) return;
	//	if ( EWS_Well == m_Data.eStatus ) return ;

	//	INT32 nBeginWaitNum  = m_Data.nMaxOnlineNum * LOGIN_LIMIT;
	//	INT32 nTemp			 = m_Data.nCurOnlineNum + m_mapWaitting.Size();

	//	Player* pPlayer		 = m_listInsertPlayer.PopFront();
	//	while (P_VALID(pPlayer) )
	//	{
	//		// �鿴�Ŷ��б����Ƿ�Ϊ��
	//		if (m_listQueue.Empty())
	//		{
	//			// �����ǰ���������������ŶӵĻ��ߣ���ʼ�Ŷ�
	//			if (nTemp >= nBeginWaitNum)
	//			{
	//				AddIntoQueue(pPlayer);
	//			}
	//			// ����Ҫ�Ŷ�
	//			else
	//			{
	//				AddIntoWaitingMap(pPlayer);
	//				++nTemp;		// �ۼ�һ������
	//			}
	//		}
	//		// �Ŷ��б�Ϊ�գ�ֱ����ӵ��Ŷ��б�
	//		else
	//		{
	//			AddIntoQueue(pPlayer);
	//		}

	//		// �ٻ�ȡһ�����
	//		pPlayer = m_listInsertPlayer.PopFront();
	//	}
	//}

	////-------------------------------------------------------------------------------
	//// �����Ŷ��б�
	////-------------------------------------------------------------------------------
	//void fpWorld::UpdateQueuedPlayer( )
	//{
	//	if (!m_Data.bValid) return;
	//	if (EWS_Well == m_Data.eStatus) return;
	//	if (m_listQueue.Empty()) return;

	//	// ��ѯÿ�����
	//	//Player* pPlayer = NULL;
	//	//m_listQueue.ResetIterator();
	//	//INT32 nIndexInQueue = 0;
	//	//while (m_listQueue.PeekNext(pPlayer) )
	//	//{
	//	//	if (pPlayer->IsConnLost())		// ��ҵ�����
	//	//	{
	//	//		m_listQueue.Erase(pPlayer);
	//	//		sPlayerMgr.PlayerLogout(pPlayer);
	//	//		continue;
	//	//	}
	//	//}
	//}


	////-------------------------------------------------------------------------------
	//// ���µȴ������
	////-------------------------------------------------------------------------------
	//void fpWorld::UpdateWaitingPlayer()
	//{
	//	if (m_mapWaitting.Empty()) return;

	//	Player* pPlayer = NULL;
	//	m_mapWaitting.ResetIterator();

	//	while (m_mapWaitting.PeekNext(pPlayer))
	//	{
	//		if (pPlayer->IsConnLost())				// ������
	//		{
	//			m_mapWaitting.Erase(pPlayer->GetAccountID());
	//			sPlayerMgr.PlayerLogout(pPlayer);
	//		}
	//		//else if (pPlayer->IsSelectWorldOk())		// �Ѿ���֤�ɹ���
	//		//{
	//		//	if (CalcTimeDiff(GetCurrentDWORDTime(), pPlayer->GetKickTime()) > 5)	// ��֤�ɹ���������5���Ӳ��Ͽ����ӣ����ߵ�
	//		//	{
	//		//		m_mapWaitting.Erase(pPlayer->GetAccountID());
	//		//		KickPlayer(pPlayer);
	//		//	}
	//		//}
	//	}
	//}

	////-------------------------------------------------------------------------------
	//// �����ߵ�������б�
	////-------------------------------------------------------------------------------
	//void fpWorld::UpdateKickedPlayer()
	//{
	//	if (m_listKickPlayer.Empty()) return;

	//	Player* pPlayer = NULL;
	//	m_listKickPlayer.ResetIterator();

	//	while (m_listKickPlayer.PeekNext(pPlayer))
	//	{
	//		if (pPlayer->IsConnLost())		// ���ߵ���
	//		{
	//			m_listKickPlayer.Erase(pPlayer);
	//			sPlayerMgr.PlayerLogout(pPlayer);
	//		}
	//	}
	//}

	//-------------------------------------------------------------------------------
	// �ͷ���Դ
	//-------------------------------------------------------------------------------
	void fpWorld::Destroy()
	{
		// ȥ��logtime
	}

	////-------------------------------------------------------------------------------
	//// ���뵽�Ŷ��б���
	////-------------------------------------------------------------------------------
	//void fpWorld::AddIntoQueue(Player* pPlayer)
	//{
	//	//if (!P_VALID(pPlayer)) return;

	//	//m_listQueue.PushBack(pPlayer);

	//	//// ���ͻ��˷�����Ϣ
	//	//tagNLS_ProofResult send;
	//	//send.bGuard			= pPlayer->IsGuard();
	//	//send.dwErrorCode	= E_ProofResult_Queue;
	//	//pPlayer->SendMessage(&send, send.dwSize);
	//}

	////-------------------------------------------------------------------------------
	//// ���뵽�ȴ��б���
	////-------------------------------------------------------------------------------
	//void fpWorld::AddIntoWaitingMap(Player* pPlayer)
	//{
	//	if (!P_VALID(pPlayer)) return;

	//	m_mapWaitting.Add(pPlayer->GetAccountID(), pPlayer);

	//	// ��world������Ϣ
	//	//tagNLW_PlayerWillLogin send;
	//	//send.dwVerifyCode	= pPlayer->GetVerifyCode();
	//	//send.dwAccountID	= pPlayer->GetAccountID();
	//	//send.byPrivilege	= pPlayer->GetPrivilege();
	//	//send.bGuard			= pPlayer->GetPlayerData().bGuard;
	//	//send.dwAccOLSec		= pPlayer->GetPlayerData().nAccOLSec;
	//	////add for prevent thief
	//	//send.dwPreLoginIP	= pPlayer->GetPreLoginIP();
	//	//send.dwPreLoginTime = pPlayer->GetPreLoginTime();

	//	//strncpy_s(send.szAccount, pPlayer->GetAccoutName(), X_SHORT_NAME);
	//	//sFpWorldMgr.SendMsg(m_Data.dwNameCrc, &send, send.dwSize);
	//}

	////-------------------------------------------------------------------------------
	//// fpworld��½
	////-------------------------------------------------------------------------------
	//bool fpWorld::WorldLogin(UINT32 dwIP, INT32 nPort, UINT32* pOLAccountIDs, INT32 nOLAccountIDNum)
	//{
	//	if (IsValid()) return false;	// ����Ƿ��Ѿ�������

	//	// ���õ�½��Ϣ
	//	m_Data.bValid			= TRUE;
	//	m_Data.dwIP				= dwIP;
	//	m_Data.nPort			= nPort;
	//	m_Data.eStatus			= EWS_InitNotDone;
	//	m_Data.nCurOnlineNum	= 0;
	//	m_Data.nMaxOnlineNum	= 0;

	//	//// tdb:worldnamecrcΪ��world��״̬ΪEPLS_Online�����״̬ΪEPLS_Unknown
	//	//sBeton.FixOneWorldPlayerLoginStatus(m_Data.dwNameCrc, EPLS_Online, EPLS_Unknown);

	//	//// tbd:�������״̬��ָ����Ҹ���ΪΪEPLS_Online
	//	//sBeton.ResetPlayersLoginStatus(pOLAccountIDs, nOLAccountIDNum, EPLS_Online);

	//	//// tdb:worldnamecrcΪ��world��״̬ΪEPLS_Unknown�����״̬ΪEPLS_Offline
	//	//sBeton.FixOneWorldPlayerLoginStatus(m_Data.dwNameCrc, EPLS_Unknown, EPLS_OffLine);

	//	//sFatigueMgr.ResetWorldAccounts(m_Data.dwNameCrc, pOLAccountIDs, nOLAccountIDNum);

	//	return true;
	//}

	////-------------------------------------------------------------------------------
	//// fpworld�ǳ�
	////-------------------------------------------------------------------------------
	//bool fpWorld::WorldLogout()
	//{
	//	if (!IsValid()) return false;	// ����Ƿ�һ��ʼ��û������

	//	// ���õǳ���Ϣ
	//	m_Data.bValid		= FALSE;
	//	m_Data.dwIP			= 0;
	//	m_Data.nPort		= 0;
	//	m_Data.eStatus		= EWS_InitNotDone;
	//	m_Data.nCurOnlineNum = 0;
	//	m_Data.nMaxOnlineNum = 0;

	//	// �ߵ����и���Ϸ�����ڵ����
	//	Player* pPlayer = NULL;

	//	//// �����ߵ�insertlist�е����
	//	//pPlayer = m_listInsertPlayer.PopFront();
	//	//while (P_VALID(pPlayer))
	//	//{
	//	//	KickPlayer(pPlayer);

	//	//	pPlayer = m_listInsertPlayer.PopFront();
	//	//}

	//	//// ���ߵ��Ŷ��б��е����
	//	//pPlayer = m_listQueue.PopFront();
	//	//while (P_VALID(pPlayer))
	//	//{
	//	//	KickPlayer(pPlayer);

	//	//	pPlayer = m_listQueue.PopFront();
	//	//}

	//	//// ���ߵ��ȴ��б��е����
	//	//m_mapWaitting.ResetIterator();
	//	//while (m_mapWaitting.PeekNext(pPlayer))
	//	//{
	//	//	KickPlayer(pPlayer);
	//	//}
	//	//m_mapWaitting.Clear();

	//	//sFatigueMgr.ResetWorldAccounts(m_Data.dwNameCrc, NULL, 0);

	//	return true;
	//}

	////-----------------------------------------------------------------------
	//// ��ҵ�¼���
	////-----------------------------------------------------------------------
	//void fpWorld::PlayerWillLoginRet(UINT32 dwAccountID, UINT32 dwErrorCode)
	//{
	//	// �ڵȴ��б��в������
	//	//Player* pPlayer = m_mapWaitting.Peek(dwAccountID);
	//	//if (P_VALID(pPlayer))
	//	//{
	//	//	// �������֤�ɹ���������ѡ����Ϸ�������
	//	//	if (E_Success == dwErrorCode)
	//	//	{
	//	//		pPlayer->SetSelectWorldOK();
	//	//	}

	//	//	// ����ҷ��ͷ��ؽ��
	//	//	tagNLS_ProofResult send;
	//	//	send.bGuard = pPlayer->IsGuard();
	//	//	send.dwIndex = 0;
	//	//	send.dwIP = m_Data.dwIP;
	//	//	send.dwPort = m_Data.nPort;
	//	//	send.dwAccountID = dwAccountID;
	//	//	send.dwVerifyCode = pPlayer->GetVerifyCode();

	//	//	if (E_Success == dwErrorCode)
	//	//		send.dwErrorCode = E_Success;
	//	//	else
	//	//		send.dwErrorCode = E_ProofResult_Account_No_Match;

	//	//	pPlayer->SendMessage(&send, send.dwSize);

	//	//	// �������Ҫ���ߵ���ʱ��
	//	//	pPlayer->SetKickTime(GetCurrentDWORDTime());
	//	//}
	//}
}