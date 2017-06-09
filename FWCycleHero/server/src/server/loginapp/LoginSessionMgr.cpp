/*
----------------------------------------------------------------------------
		file name : LoginSessionMgr.hpp
		desc	  : �����������
		author    : LJP

		log		  : [ 2016-02-28 ]
----------------------------------------------------------------------------
*/
#include "LoginSessionMgr.h"
#include "PlayerSession.h"
#include "msg_cl.h"
#include "msg_login.h"





namespace KBEngine
{
	CLoginSessionMgr::CLoginSessionMgr() : m_GenID(0)
	{
		mapSession.Clear();
	}

	CLoginSessionMgr::~CLoginSessionMgr()
	{
		mapSession.ResetIterator();
		CPlayerSession* pSeesion = NULL;
		while (mapSession.PeekNext(pSeesion))
		{
			SAFE_DEL(pSeesion);
		}
	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: �������ӵ���¼�������� PlayerSession ����
	//-------------------------------------------------------------------------------------------
	INetSession* CLoginSessionMgr::CreateSession(SESSION_TYPE type)
	{
		CPlayerSession* pSession = new CPlayerSession();
		if (pSession != nullptr)
		{
			pSession->SetType(ST_CLIENT_Login);
			mapSession.Add(m_GenID, pSession);
			pSession->SetID(m_GenID);
			m_GenID++;
		}
		return pSession;
	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: ����session��������Ϣ
	//-------------------------------------------------------------------------------------------
	void CLoginSessionMgr::UpdateSession( void )
	{
		if (mapSession.Size() <= 0)
			return;


		mapSession.ResetIterator();
		CPlayerSession* pSeesion = NULL;
		while (mapSession.PeekNext(pSeesion))
		{
			pSeesion->HandleMessage();
		}
	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: ���б���ɾ�� session ����
	//-------------------------------------------------------------------------------------------
	bool CLoginSessionMgr::RemoveSession(INetSession* pSession)
	{
		return mapSession.Erase(pSession->GetID());
	}

}