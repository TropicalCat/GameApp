/*
----------------------------------------------------------------------------------------------
			file name : sync_app_handler.h
			desc	  : �ͻ��˷���DB Server ��Э�鴦��ӿ�
			author	  : ljp

			log		  : by ljp create 2017-06-10
----------------------------------------------------------------------------------------------
*/
#include "sync_cellapp_handler.h"



namespace KBEngine{	

	//-------------------------------------------------------------------------------------
	CCellAppNetCmdMgr::CCellAppNetCmdMgr()
	{
		m_mapProc.Clear();
	}

	CCellAppNetCmdMgr::~CCellAppNetCmdMgr()
	{
		Destroy();
	}

	//-----------------------------------------------------------------------------
	// destroy
	//-----------------------------------------------------------------------------
	void CCellAppNetCmdMgr::Destroy()
	{

	}

	//-----------------------------------------------------------------------------
	// ע����Ϣ
	//-----------------------------------------------------------------------------
	bool CCellAppNetCmdMgr::Register(UINT32 dwID, CELLNETMSGHANDLER fp, char* szDesc)
	{
		tagPlayerCmd* pCmd = m_mapProc.Peek(dwID);
		if (P_VALID(pCmd))
		{
			if (pCmd->strCmd == dwID)
			{
				KBE_ASSERT(0);
				return false;
			}
		}
		else
		{
			pCmd = new tagPlayerCmd;
			pCmd->nTimes = 0;
			pCmd->handler = fp;
			pCmd->strCmd = dwID;
			pCmd->strDesc = szDesc;
			m_mapProc.Add(dwID, pCmd);
		}
		return true;
	}

	//------------------------------------------------------------------------------
	// ȡ��ע��
	//------------------------------------------------------------------------------
	void CCellAppNetCmdMgr::UnRegisterAll()
	{
		m_mapProc.ResetIterator();
		tagPlayerCmd* pCmd = NULL;
		while (m_mapProc.PeekNext(pCmd))
		{
			SAFE_DEL(pCmd);
		}
		m_mapProc.Clear();
	}

	//------------------------------------------------------------------------------
	// �õ�ĳ����ϢID��Ӧ�Ĵ�����
	//------------------------------------------------------------------------------
	CELLNETMSGHANDLER CCellAppNetCmdMgr::GetMsgHandler(UINT32 dwMsgID, UINT32 nSize)
	{
		tagPlayerCmd* pCmd = m_mapProc.Peek(dwMsgID);
		if (!P_VALID(pCmd))
		{
			//ERROR_MSG("Unknow player command recved[<cmdid>%d <size>%d]\r\n", pMsg->dwID, nMsgSize);
			return NULL;
		}

		/*
		if (pMsg->dwSize != nSize || nSize > GT_MAX_PACKAGE_LEN)
		{
		//ERROR_MSG("Invalid net command size[<cmd>%u <size>%d]\r\n", pMsg->dwID, pMsg->dwSize);
		return NULL;
		}
		*/
		++pCmd->nTimes;
		return pCmd->handler;
	}
}
