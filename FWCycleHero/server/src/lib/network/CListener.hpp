/*
--------------------------------------------------------------------------------------
		file name : handle_listener.hpp
		��ɶ˿ڼ�����,�ڱ���Ϊ��������ʱ,������ʹ��IOCP��ʵ���ܽ������ӵ���
		������CConnectCtrl��Ӧ
		author    : LJP

		log		  : [ 2015-04-28 ]
--------------------------------------------------------------------------------------
*/

#ifndef KBE_NETWORKLISTENER_RECEIVER_HPP
#define KBE_NETWORKLISTENER_RECEIVER_HPP
#include "common/common.hpp"
#include "network/IListener.hpp"








namespace KBEngine 
{ 
		/**
		* @brief ��ɶ˿ڼ�����,�ڱ���Ϊ��������ʱ,������ʹ��IOCP��ʵ���ܽ������ӵ���
		* ������CConnectCtrl��Ӧ
		*/
		class CListenerReceiver : public IListener
		{
		public:
			CListenerReceiver();
			virtual ~CListenerReceiver();

			void						CreateAcceptThread(void);
			
			// �������������߳�
			#if KBE_PLATFORM == PLATFORM_WIN32
			static unsigned __stdcall	ListenAcceptThread(void* arg);
			#else
			static void*				ListenAcceptThread( void* arg );
			#endif
	
			/**
			* @brief ������ɶ˿ڼ�����ID
			* @param dwID : ���õ�ID
			* @return void
			*/
			inline void					SetID(UINT32 dwID)			{ m_dwID = dwID; }

			/**
			* @brief �������ݰ�������
			* @param poPacketParser : ���õ����ݰ�������
			* @return void
			*/
			inline void					SetPacketParser(IPacketParser* poPacketParser)			{ m_poPacketParser = poPacketParser; }

			/**
			* @brief ���ûỰ������
			* @param poSessionFactory : ���õĻỰ������
			* @return void
			*/
			inline void					SetSessionFactory(ISessionFactory* poSessionFactory)	{ m_poSessionFactory = poSessionFactory; }


			/**
			* @brief ���û����С
			* @param dwRecvBufSize : ���ý��ջ����С
			* @param dwSendBufSize : ���÷��ͻ����С
			* @return void
			*/
			inline void					SetBufferSize(UINT32 dwRecvBufSize, UINT32 dwSendBufSize) { m_dwRecvBufSize = dwRecvBufSize; m_dwSendBufSize = dwSendBufSize; }


			/**
			* @brief ��ʼ����
			* @param pszIP : ����IP��ַ
			* @param wPort : ���ض˿ں�
			* @param bReUseAddr : �Ƿ�˿ڸ���
			* @return �����ɹ�����true,����ʧ�ܷ���false
			*/
			virtual bool				Start(const char* pszIP, UINT16 wPort, bool bReUseAddr);

			/**
			* @brief ֹͣ����
			* @return void
			*/
			virtual bool				Stop(void);

			/**
			* @brief �ͷŴ˼�����
			* @return void
			*/
			virtual void				Release(void) { delete this; }

			/**
			* @brief ���ͻ��˷���һ��������������ʱ��ִ�д˺���
			* @param bSucc : �����������Ƿ�ɹ���trueΪ�ɹ�
			* @param pstPerIoData : �˽������������ÿIO����
			* @return void
			*/
			void						OnAccept(BOOL bSucc, SPerIoData* pClient, tagXClient* pTagClient );

		private:
			#if KBE_PLATFORM == PLATFORM_WIN32
			bool						_InitAccepteEx();
			/**
			* @brief ����һ���������ӵ�ÿIO����
			* @param pstPerIoData : �˽������������ÿIO����
			* @return �Ƿ������ӳɹ���trueΪ�ɹ�
			*/
			bool						PostAcceptEx(SPerIoData* pstPerIoData);
			#else

			#endif

			inline	void				ShutDownSocket(KBESOCKET sock);
		protected:

			UINT32						m_dwID;
			KBESOCKET					m_ListenerSocket;
			IPacketParser*				m_poPacketParser;
			ISessionFactory*			m_poSessionFactory;
			UINT32						m_dwRecvBufSize;
			UINT32						m_dwSendBufSize;
			bool						m_bStart;
			SPerHandleData              m_stPerHandleData;
			#if KBE_PLATFORM == PLATFORM_WIN32
			HANDLE						m_Handle;
			LPFN_ACCEPTEX				m_lpfnAcceptEx;
			LPFN_GETACCEPTEXSOCKADDRS	m_lpfnGetAcceptExSockAddr;
			#endif
		};

		inline	void CListenerReceiver::ShutDownSocket(KBESOCKET sock)
		{						
			#if KBE_PLATFORM == PLATFORM_WIN32					
			::closesocket(sock);
			#else												
			::close(sock);
			#endif
		}
		
}


#endif // KBE_NETWORKLISTENER_RECEIVER_HPP
