/*
-------------------------------------------------------------------------------------------
		file name : address.hpp
		desc	  : �����ն˵�ַ������
		author    : LJP

		log		  : [2015-04-26]
-------------------------------------------------------------------------------------------
*/

#ifndef __NET_ISOCKET_H__
#define __NET_ISOCKET_H__
#include "common/common.hpp"





namespace KBEngine 
{ 
	// �����¼�ö�ٵĶ��� 
	enum EIocpOperation
	{
		IOCP_NULL = 0,
		IOCP_ACCEPT,
		IOCP_RECV,
		IOCP_SEND,
		IOCP_CLOSE
	};


	/**
	* @brief ÿ��IO������,��ÿ��IO����������һ�������
	*/
	struct SPerIoData
	{
		OVERLAPPED			stOverlapped;
		SOCKET				hSock;
		EIocpOperation		nOp;
		WSABUF				stWsaBuf;
		char				Buf[128];
	};



	//-----------------------------------------------------------------------------
	//!	unit����
	//-----------------------------------------------------------------------------
	#define MAX_PAGE_SIZE 256
	struct tagUnit
	{
		UINT32				dwSize;					// ��Ч���ݴ�С,����ʵ���ڴ�ռ��С
		tagUnit*			pNext;					// ָ����һ��unit,����safe_unit_queue
		char				Buf[MAX_PAGE_SIZE];
	};


	//-----------------------------------------------------------------------------
	//!	����ڵ����ͻ��˵Ķ���
	//-----------------------------------------------------------------------------
	class ClientSocket;
	struct tagXClient
	{
		BOOL volatile			bShutDown;		// �Ƿ��Ѿ���shutdown
		LONG volatile			lSendCast;		// �Ѿ�������send,��δ�յ�֪ͨ��
		LONG volatile			lRecvCast;		// �Ѿ�������recv,��δ�յ�֪ͨ��

		UINT32					dwClientID;		// �ͻ���ID,�ϲ�ȷ�ϵ�һ�����Ժ����Ч
		UINT32					dwConnectTime;	// ����ȷ���߳���ʱ��δ��֤�ͻ���
		UINT32					dwSendSize;		// �ȴ����ʹ�С

		ClientSocket*			pClient;
	};

	/**
	* @brief ÿ�������,�;��������һ�������
	*/
	struct SPerHandleData
	{
		bool		bListen;
		void*		ptr;
	};

	
	/**
	* @brief Break packet from TCP data stream. The interface need to be implemented by user
	*/
	class IPacketParser
	{
	public:
		/**
		* @brief Return the length in bytes of the packet in TCP data stream
		* @param pBuf : the data buffer need to parse
		* @param dwLen : the data buffer length
		*/
		virtual INT32			ParsePacket(const char* pBuf, UINT32 dwLen) = 0;
	};

	/**
	* @brief CONNECTION_OPT_SOCKOPT is a data structure, its members correspond the parameters of setsockopt
	*/
	struct SConnectionOptSockopt
	{
		INT32       nLevel;
		INT32       nOptName;
		const char* pOptVal;
		INT32       nOptLen;
	};


	/*
	 * @brief the interface for TCP socket 
	*/
	class ISocket
	{

	public:
		/**
		* @ ����� client socket ��Ҫʵ�ָýӿڣ����ӵ�������
		*        
		* @param ip, nPort
		*/
		virtual void			connect(UINT32 ip, UINT16 nPort) = 0;

		/**
		* @ �Ͽ���Զ�˵�����
		*      
		* @param 
		*/
		virtual void			closesock() = 0;

		/**
		* @ �������� socket
		*
		* @param
		*/
		virtual void			setsocket(int sock) = 0;

	};
}


#endif // __NET_ISOCKET_H__
