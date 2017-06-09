/*
----------------------------------------------------------------------------
	file name : fplayer_mgr.hpp
	desc	  : ��¼�����˺ŷ�������client �Ĺ���
	author    : LJP

	log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#ifndef FPLAYER_MGR_HPP
#define FPLAYER_MGR_HPP
#include "common/singleton.hpp"
#include "network/safe_map.h"
#include "network/simple_map.h"
#include "network/safe_list.h"
#include "network/event_dispatcher.hpp"
#include "proof_Policy.hpp"
#include "LoginSessionMgr.h"
#include "flogin_define.hpp"






namespace KBEngine
{
	
	class Player;
	class CLoginPolicy;
	class CPlayerMgr : public Singleton<CPlayerMgr>
	{

	public:
		 CPlayerMgr();
		~CPlayerMgr();


		//--------------------------------------------------------------------------
		// ��ʼ�������º�����
		//--------------------------------------------------------------------------
		bool				Init( void );
		void				Update( void );
		void				Destroy( void );
		void				InitNetWork(void);

		//--------------------------------------------------------------------------
		// ����Get
		//--------------------------------------------------------------------------
		uint32				GetCurrVer()		{ return m_dwCurrVer; }
		int32				GetPlayerNum()		{ return m_nPlayerNum; }
		int32				GetPlayerLoging()	{ return m_nPlayerLoging; }
		int32				GetProofResultNum()	{ return m_nProofResultNum; }
		EProofPolicy		GetProofPolicy()	{ return m_ePolicy; }
		CLoginPolicy*		GetProofPolicyPtr()	{ return m_pPolicy; }

		//--------------------------------------------------------------------------
		// ��������
		//--------------------------------------------------------------------------
		void				SendMsg(UINT32 dwCDIndex, void* pMsg, UINT32 dwSize);
		
		//--------------------------------------------------------------------------
		// ����
		//--------------------------------------------------------------------------
		void				Kick(UINT32 dwCDIndex)		{ m_pDispatcher->KickPlayer(dwCDIndex); }

		//--------------------------------------------------------------------------
		// ID����
		//--------------------------------------------------------------------------
		uint32				GenerateClientID()				{ ++m_dwClientIDGen; return m_dwClientIDGen; }

		//--------------------------------------------------------------------------
		// ������
		//--------------------------------------------------------------------------
		void				AddPlayerToAll(Player* pPlayer);
		void				AddPlayerToLogining(Player* pPlayer);
		void				RemovePlayerFromAll(UINT32 dwClientID)		{ m_mapAllPlayer.Erase(dwClientID); }
		void				RemovePlayerFromLogining(UINT32 dwClientID)	{ m_mapLoginingPlayer.Erase(dwClientID); }
		void				PlayerLogout(Player* pPlayer);

		void				AddAccount(UINT32 dwAccountID, UINT32 dwClientID);
		void				RemoveAccount(UINT32 dwAccountID);
		bool				IsAccountExist(UINT32 dwAccountID)			{ return m_mapAccountIDClientID.IsExist(dwAccountID); }


		//--------------------------------------------------------------------------
		// ��֤���
		//--------------------------------------------------------------------------
		void				Proof(UINT32 dwClientID, char* szAccoutName, char* szPsd, char* szGUID);
		
	
	private:
		//--------------------------------------------------------------------------
		// ��ʼ�������ļ�
		//--------------------------------------------------------------------------
		bool				InitConfig();

		//--------------------------------------------------------------------------
		// ����
		//--------------------------------------------------------------------------
		void				UpdateSession();
		void				UpdateProofResult(){}

		//--------------------------------------------------------------------------
		// ��½�ǳ��ص�
		//--------------------------------------------------------------------------
		uint32				LoginCallBack(void*, void*);
		uint32				LogoutCallBack(void*);

	private:
		
		//--------------------------------------------------------------------------
		// �������
		//--------------------------------------------------------------------------
		int32								m_nPort;

		//--------------------------------------------------------------------------
		// ID������
		//--------------------------------------------------------------------------
		uint32								m_dwClientIDGen;

		//--------------------------------------------------------------------------
		// �汾�ź�����
		//--------------------------------------------------------------------------
		uint32								m_dwCurrVer;

		//--------------------------------------------------------------------------
		// ͳ����Ϣ
		//--------------------------------------------------------------------------
		volatile int32						m_nPlayerNum;
		volatile int32						m_nPlayerLoging;
		volatile int32						m_nProofResultNum;

		//--------------------------------------------------------------------------
		// ������
		//--------------------------------------------------------------------------
		TSafeMap<UINT32, Player*>			m_mapAllPlayer;			// ���е�Player,��ClientID Ϊ key
		TMap<UINT32, Player*>				m_mapLoginingPlayer;	// ���ڵ�¼�����
		TMap<UINT32, UINT32>				m_mapAccountIDClientID;	// ���ߵ�AccountID��ClientID��Ӧ��
		TSafeList<tagProofResultFull*>		m_listProofResult;		// ���سɹ������

		TMap<UINT32, tagAccountData*>		m_mapAccountData;		// ���е�AccountID�Ļ������ݣ�����AccountName��guard��ip ��ʼ�����أ���̬����
		TMap<UINT32, UINT32>				m_mapAccountNameCrc2AccountID;	// accountid -> namecrc	��ʼ��ʱ���أ����Ҷ�̬���

		//--------------------------------------------------------------------------
		// ��֤����
		//--------------------------------------------------------------------------
		EProofPolicy						m_ePolicy;				// ��֤��ʽ
		CLoginPolicy*						m_pPolicy;				// ��֤����

		CLoginSessionMgr*					m_pNetSessionMgr;
		EventDispatcher*					m_pDispatcher;			// ������Ϣ������
	};

	#define sPlayerMgr CPlayerMgr::getSingleton()
}

#endif
