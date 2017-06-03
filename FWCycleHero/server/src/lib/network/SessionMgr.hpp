/*
--------------------------------------------------------------------------------------------
		file name : INetSessionMgr.hpp
		desc	  : 
		author    : LJP

		log		  : [2015-04-26]
--------------------------------------------------------------------------------------------
*/

#ifndef __INETSESSIONMGR_H__
#define __INETSESSIONMGR_H__
#include "network/ISocket.hpp"
#include "network/ISocket.hpp"
#include "network/IListener.hpp"
#include "network/ISession.hpp"
#include "network/Session.hpp"
#include "network/simple_map.h"
#include "network/ISessionFactory.hpp"





#define MAX_COUNT_LISTENER	3
namespace KBEngine 
{ 
	class INetSession;
	class INetSessionMgr : public ISessionFactory
	{

	public:
		INetSessionMgr();
		virtual ~INetSessionMgr();
		static INetSessionMgr*		GetInstance() { return mInstance; }

		//--------------------------------------------------------------------------------------------------
		// ���� Session ��صĲ��� 
		INetSession*				GetSession(int sessionId);
		bool						RemoveSession(INetSession* pSession);
		void						SendMsgToSession(SESSION_TYPE stype, int sessionId, const std::string& sMsg, int n32MsgID);
		void						SendMsgToSession(SESSION_TYPE stype, int sessionId, const char* pMsgBuffer, int n32MsgLen, int n32MsgID);
		void						TranMsgToSession(SESSION_TYPE stype, int sessionId, const char* pMsgBuffer, int n32MsgLen, int n32MsgID, int n32TransId, int n32GcNet);//�Ż�GSר��(������pb)
		void						Send(SESSION_TYPE stype, int sessionId, char* pBuffer);
		void						StopListener(int pos) { if (pos<MAX_COUNT_LISTENER){ mListener[pos]->Stop(); } }
		void						DisconnectOne(int sessionId);
		virtual INetSession*		CreateSession(SESSION_TYPE type) = 0;

	private:

		UINT32						mNextConnectorID;
		IListener*					mListener[MAX_COUNT_LISTENER];//��������
		static INetSessionMgr*		mInstance;//����

	};
}

#endif 
// __INETSESSIONMGR_H__
