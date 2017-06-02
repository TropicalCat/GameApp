/*
------------------------------------------------------------------------------------------------
file name : event_iocp.hpp
desc	  : ���� windows �� ��ɶ˿�����ģ��
author    : LJP

log		  : [ 2015-04-28 ]
------------------------------------------------------------------------------------------------
*/

#ifndef __EVENT_NET_IOCP_H__
#define __EVENT_NET_IOCP_H__
#include "common/common.hpp"
#include "network/event_poller.hpp"
#include "common/timestamp.hpp"
#include "network/interfaces.hpp"
#include "thread/concurrency.hpp"
#include "network/common.hpp"
#include "network/ISocket.hpp"
#include "network/x_list.h"
#include <map>
#include <list>




#if KBE_PLATFORM == PLATFORM_WIN32
namespace KBEngine 
{ 

#ifndef SAFE_CLOSE_HANDLE
#define SAFE_CLOSE_HANDLE(h)	do { if(h) { CloseHandle(h);	(h) = NULL; } } while(0)
#endif


#define	X_SLEEP_TIME 500


	//-------------------------------------------------------------------------------------
	class ISessionFactory;
	class IPacketParser;
	class IListener;
	class CIocpPoller : public EventPoller
	{

	public:
		CIocpPoller();
		virtual ~CIocpPoller();

		static CIocpPoller*			Instance();

	protected:

		/** brif ���ܿͻ��������߳�
		*/
		static UINT32 WINAPI		ListenAcceptThread(void* arg);
		static UINT32 WINAPI		ThreadSendProc(void* arg);
		
	public:

		/***
		* @brief ��ʼ�� NetWork
		*/
		virtual bool				InitNetEngine(UINT32 nPort);

		/**
		* @brief ��ʼ��IOCP������
		* @return �Ƿ��ʼ���ɹ���trueΪ�ɹ���falseΪʧ��
		*/
		bool						CreateIoCompletion( UINT16 nPort );

		/**
		* @brief ����IOCP������
		*
		*/
		void						Destroy();

		/**
		* @brief ����IOCP������
		*
		*/
		void						OnAccept(SPerIoData* pIoInfo);


		/**
		* @brief ��IOCPִ��ʱ�����ô˺���
		*
		*/
		void						ThreadSetupAcceptEx( );
		void						ThreadSendProceEX();
		
		/**
		* @brief ��ĳ���׽��ֽӿڰ��ڴ�IOCP��
		* @param hSock : �󶨵��׽���
		* @param pstData : �͸��׽�����ص�����
		* @return �Ƿ�󶨳ɹ�
		*/
		bool						AssociateWithIocp(KBESOCKET hSock, SPerHandleData* pstData);

	protected:
		static CIocpPoller*			g_IocpInstance;
		//IO��ɶ˿ڵľ��
		HANDLE						m_hCompletionPort;
		
		KBESOCKET					m_sockListen;
		INT32						m_nNumberOfWorkers;
		HANDLE*						m_WorkerArray;

		//-----------------------------------------------------------------------------
		ClientSocket*				m_pClient;
		XList<ClientSocket*>		m_listFreeClient;
		XList<ClientSocket*>		m_listDestroyClient;

		SPerHandleData              m_stPerHandleData;
		SPerIoData*					m_pPerIoDataArray;
		LPFN_ACCEPTEX				m_lpfnAcceptEx;
		LPFN_GETACCEPTEXSOCKADDRS	m_lpfnGetAcceptExSockAddr;
	};
}
#endif

#endif // __EVENT_NET_IOCP_H__
