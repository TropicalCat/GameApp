/*
----------------------------------------------------------------------------
	file name : fpworld_mgr.hpp
	desc	  : �������е���Ϸ������
	author    : LJP

	log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#pragma once
#include "common/singleton.hpp"
#include "fpworld.hpp"
#include "player.hpp"
#include "network/net_define.h"
#include "network/simple_map.h"






namespace KBEngine
{
	class FpWorldMgr : public Singleton<FpWorldMgr>
	{

	public:

		//-------------------------------------------------------------------------
		// CONSTRUCT
		//-------------------------------------------------------------------------
		FpWorldMgr();
		~FpWorldMgr();

		static FpWorldMgr*	 Instance(void);
		//-------------------------------------------------------------------------
		// ��ʼ�������º�����
		//-------------------------------------------------------------------------
		bool			Init();
		void			Update();
		void			Destroy();
		void			UpdateWorldState(fpWorld* pWorld);


		//-------------------------------------------------------------------------
		// ������Ϣ���
		//-------------------------------------------------------------------------
		
		/*uchar*			RecvMsg(UINT32 dwID, UINT32& dwMsgSize, INT32& nUnRecved)	{ return m_pSession->Recv(dwID, dwMsgSize, nUnRecved); }
		void			ReturnMsg(UINT32 dwID, uchar* pMsg)							{ m_pSession->FreeRecved(dwID, pMsg); }
		void			SendMsg(UINT32 dwID, void* pMsg, UINT32 dwSize)				{ m_pSession->Send(dwID, pMsg, dwSize); }
		void			HandleCmd(void* pMsg, UINT32 dwSize, UINT32 dwParam)		{ m_pMsgCmdMgr->HandleCmd((tagNetCmd*)pMsg, dwSize, dwParam); }
		*/


		//-------------------------------------------------------------------------
		// �õ���Ϸ����
		//-------------------------------------------------------------------------
		fpWorld*		GetFpWorld(UINT32 dwNameCrc)	{ return m_mapFpWorld.Peek(dwNameCrc); }
		DWORD			GetFpWorldNum()					{ return m_mapFpWorld.Size(); }


		//-----------------------------------------------------------------------
		// ������
		//-----------------------------------------------------------------------
		void			AddToWorld(Player* pPlayer, UINT32 dwWorldNameCrc);

	private:

		//-----------------------------------------------------------------------
		// ������Ϣ���
		//-----------------------------------------------------------------------
		void			RegisterFpWorldMsg();
		void			UnRegisterFpWorldMsg();

		//-----------------------------------------------------------------------
		// ����ǳ��ص�
		//-----------------------------------------------------------------------
		UINT32			LoginCallBack(uchar* pByte, UINT32 dwSize);
		UINT32			LogoutCallBack(UINT32 dwParam);

		//-----------------------------------------------------------------------
		// ��Ϣ����
		//-----------------------------------------------------------------------
		UINT32			HandleCertification(tagNetCmd* pMsg, fpWorld* pWorld);
		UINT32			HandleZoneServerStatus(tagNetCmd* pMsg, fpWorld* pWorld);
		UINT32			HandlePlayerLogin(tagNetCmd* pMsg, fpWorld* pWorld);
		UINT32			HandlePlayerLogout(tagNetCmd* pMsg, fpWorld* pWorld);
		UINT32			HandlePlayerWillLogin(tagNetCmd* pMsg, fpWorld* pWorld);
		UINT32			HandleKickLog(tagNetCmd* pMsg, fpWorld* pWorld);
		UINT32			HandleWorldClosed(tagNetCmd* pMsg, fpWorld* pWorld);

	private:

		TMap<UINT32, fpWorld*>		m_mapFpWorld;			// ��Ϸ�����б�
		//NetCmdMgr*					m_pMsgCmdMgr;

	};

	#define sFpWorldMgr FpWorldMgr::getSingleton()
}


