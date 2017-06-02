/*
----------------------------------------------------------------------------
	file name : NetCmdMgr.hpp
	desc	  : �����������
	author    : LJP

	log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#pragma once
#include "common/singleton.hpp"
#include "common/memorystream.hpp"
#include "network/SessionMgr.hpp"
#include "fplayer_net_cmd_mgr.hpp"
#include "fpworld.hpp"






namespace KBEngine
{
	
	//////////////////////////////////////////////////////////////////////////
	class MemoryStream;
	class CPlayerSession : public INetSession
	{

	public:

		CPlayerSession();
		virtual ~CPlayerSession();

		void						InitProtol();
		void						Destory();


		////////////////////////////////////////////////////////////////////////////////////////////
		// ������Ϣ
		void						SendMessage(tagNetCmd* pMsg);
		void						SyncSendMessage(tagNetCmd* pMsg);
		

		UINT32						HandleMessage();
		void						ReturnMsg(tagUnit* pMsg);


		///-----------------------------------------------------------------------------------------
		// ������Ϣ����ӿ�
		UINT32						HandleProofAccount(MemoryStream* pMsg);
		UINT32						HandleLoginAppMessage(MemoryStream* pMsg);
		UINT32						HandleHeartBeatMessage(MemoryStream* pMsg);

	public:

		MemoryStream				m_SendStream;
		MemoryStream				m_RecvStream;
		PlayerNetCmdMgr				m_playerNetMgr;		// ��Ϣ������
	};


	class CLoginSessionMgr : public INetSessionMgr
	{

	public:
		CLoginSessionMgr();
		virtual ~CLoginSessionMgr();

	public:

		//////////////////////////////////////////////////////////////////////////
		// ��������Session
		//////////////////////////////////////////////////////////////////////////
		void						UpdateSession( void );

		virtual INetSession*		CreateSession(SESSION_TYPE type);
		virtual bool				RemoveSession(INetSession* pSession);

	private:

	protected:

		TMap<UINT32, CPlayerSession*>	mapSession;
		UINT32						m_GenID;
	};
}


