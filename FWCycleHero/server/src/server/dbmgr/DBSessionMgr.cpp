/*
---------------------------------------------------------------------------------------------------------
file name : DBSessionMgr.h
desc      : ���ӵ�DB Server ������ Session ������
author    : ljp

log		  : 2017-06-09 : 15:55
---------------------------------------------------------------------------------------------------------
*/
#include "DBSessionMgr.h"
#include "loginSession.h"






namespace KBEngine{	


	CDBAppSessionMgr::CDBAppSessionMgr() : m_GenID(0)
	{
		mapSession.Clear();
	}

	CDBAppSessionMgr::~CDBAppSessionMgr()
	{

	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: �������ӵ���¼�������� PlayerSession ����
	//-------------------------------------------------------------------------------------------
	INetSession* CDBAppSessionMgr::CreateSession(SESSION_TYPE type)
	{
		CLoginSession* pSession = new CLoginSession();
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
	void CDBAppSessionMgr::UpdateSession(void)
	{
		if (mapSession.Size() <= 0)
			return;


		mapSession.ResetIterator();
		CLoginSession* pSeesion = NULL;
		while (mapSession.PeekNext(pSeesion))
		{
			pSeesion->HandleMessage();
		}
	}

	//--------------------------------------------------------------------------------------------
	// function :
	// desc		: ���б���ɾ�� session ����
	//-------------------------------------------------------------------------------------------
	bool CDBAppSessionMgr::RemoveSession(INetSession* pSession)
	{
		return mapSession.Erase(pSession->GetID());
	}

}
