/*
----------------------------------------------------------------------------
		file name : fpworld.hpp
		desc	  : ����������ʵ��
		author    : LJP

		log		  : [ 2015-08-24 ]
----------------------------------------------------------------------------
*/
#pragma once
#include "flogin_define.hpp"
#include "common/common.hpp"
#include "network/simple_list.h"
#include "network/simple_map.h"





namespace KBEngine
{
	//-----------------------------------------------------------------------------
	// ��Ϸ����
	//-----------------------------------------------------------------------------
	class Player;
	class fpWorld 
	{

	public:
		//--------------------------------------------------------------------------
		// CONSTRUCT
		//--------------------------------------------------------------------------
		 fpWorld();
		~fpWorld();

		//--------------------------------------------------------------------------
		// ��ʼ�������¼�����
		//--------------------------------------------------------------------------
		bool				Init(INT32 nIndex);
		void				Update();
		void				Destroy();


		//--------------------------------------------------------------------------
		// �����͹ر�
		//--------------------------------------------------------------------------
		bool				WorldLogin(UINT32 dwIP, INT32 nPort, UINT32* pOLAccountIDs, INT32 nOLAccountIDNum);
		bool				WorldLogout();

		//--------------------------------------------------------------------------
		// ����Get
		//--------------------------------------------------------------------------
		UINT32				GetID()				{ return m_Data.dwNameCrc; }
		UINT32				GetWorldID()		{ return m_Data.dwWorldID; }
		EWorldStatus		GetStatus()			{ return m_Data.eStatus; }
		INT32				GetMaxOnlineNum()	{ return m_Data.nMaxOnlineNum; }
		INT32				GetCurrOnlineNum()	{ return m_Data.nCurOnlineNum; }
		char*				GetName()			{ return m_Data.szName; }
		INT32				GetListQueue()		{ return m_listQueue.Size(); }
		UINT32				GetDBUpdateTime()	{ return m_dwDBUpdateTime; }
		UINT32				GetDBInsertTime()	{ return m_dwDBInsertTime; }

		//--------------------------------------------------------------------------
		// ����Set
		//--------------------------------------------------------------------------
		void				SetDBUpdateTime(UINT32 dwTime)	{ m_dwDBUpdateTime = dwTime; }
		void				SetDBInsertTime(UINT32 dwTime)	{ m_dwDBInsertTime = dwTime; }

		bool				IsValid()			{ return m_Data.bValid; }
		bool				IsAutoSeal()		{ return m_Data.bAutoSeal; }

		//--------------------------------------------------------------------------
		// ����״̬
		//--------------------------------------------------------------------------
		void				UpdateStatus(EWorldStatus eStatus, INT32 nCurOnline, INT32 nMaxOnline);


		//--------------------------------------------------------------------------
		// ��������
		//--------------------------------------------------------------------------
		void				KickPlayer(Player* pPlayer);
		void				AddPlayer(Player* pPlayer)	{}

		//----------------------------------------------------------------------------
		// ������������
		//----------------------------------------------------------------------------
		void				PlayerWillLoginRet(UINT32 dwAccountID, UINT32 dwErrorCode);

		
	private:
		//----------------------------------------------------------------------------
		// �����������ӣ��Ŷ��б�͵ȴ��б�
		//----------------------------------------------------------------------------
		void				UpdateSession();
		void				UpdateInsertPlayer();
		void				UpdateQueuedPlayer();
		void				UpdateWaitingPlayer();
		void				UpdateKickedPlayer();

		//----------------------------------------------------------------------------
		// ��������б�
		//----------------------------------------------------------------------------
		void				AddIntoQueue(Player* pPlayer);
		void				AddIntoWaitingMap(Player* pPlayer);
	private:

		UINT32					m_id; 
		EWorldStatus			m_eStatus;
		tagWorldInfo			m_Data;
		UINT32					m_dwTime;					// ���ڶ�ʱ�����Ŷ��б�

		UINT32					m_dwDBUpdateTime;
		UINT32					m_dwDBInsertTime;
		//----------------------------------------------------------------------------------
		// ����б�
		//----------------------------------------------------------------------------------
		TList<Player*>			m_listInsertPlayer;			// �����б�
		TList<Player*>			m_listQueue;				// �Ŷ��б�
		TMap<DWORD, Player*>	m_mapWaitting;				// �ȴ�������Ϸ���������б�
		TList<Player*>			m_listKickPlayer;			// ��������ԭ���ߵ����
	};
}

