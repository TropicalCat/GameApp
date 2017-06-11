/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc	  : ���ӵ������������ϵĿͻ��˹������
		author	  : ljp

		log		  : by ljp create 2017-06-11
--------------------------------------------------------------------------------------------------------------
*/

#include "cellapp.h"
#include "ClientSession.h"
#include "common/memorystream.hpp"







namespace KBEngine{	

	CCellAppSessionMgr::CCellAppSessionMgr() : m_GenID(0)
	{
		mapSession.Clear();
	}

	CCellAppSessionMgr::~CCellAppSessionMgr()
	{

	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: �������ӵ���¼�������� PlayerSession ����
	//-------------------------------------------------------------------------------------------
	INetSession* CCellAppSessionMgr::CreateSession(SESSION_TYPE type)
	{
		CCleintSession* pSession = new CCleintSession();
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
	void CCellAppSessionMgr::UpdateSession(void)
	{
		if (mapSession.Size() <= 0)
			return;


		mapSession.ResetIterator();
		CCleintSession* pSeesion = NULL;
		while (mapSession.PeekNext(pSeesion))
		{
			pSeesion->HandleMessage();
		}
	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: ���б���ɾ�� session ����
	//-------------------------------------------------------------------------------------------
	bool CCellAppSessionMgr::RemoveSession(INetSession* pSession)
	{
		return mapSession.Erase(pSession->GetID());
	}

}
