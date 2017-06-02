/*
-------------------------------------------------------------------------------
		file name : message_handler.hpp
		desc      : ������Ϣ��������װ
		author    : LJP

		log		  : [ 2015-04-28 ]
-------------------------------------------------------------------------------
*/
#ifndef KBE_MESSAGE_HANDLER_HPP
#define KBE_MESSAGE_HANDLER_HPP
#include "Session.hpp"
#include "common/memorystream.hpp"
#include "common/smartpointer.hpp"
#include "helper/debug_helper.hpp"
#include "network/common.hpp"





namespace KBEngine
{

		typedef int(*NETMSG_HANDLE)(int nID, const MemoryStream* pMsg);

		/* ** 
			brif ���пͻ��˷�����Ϣ�Ĵ���ļ���
		*/
		
		class CHandlerNode
		{

		public:
			 CHandlerNode();
			~CHandlerNode();

		public:
			int32						msgID;
			int32						msgLen;
			std::string					desc;
			// stats
			uint32						send_count;
			uint32						recv_count;
			NETMSG_HANDLE				handler;

		};

		class MessageHandlers
		{

		public:
			MessageHandlers();
			virtual ~MessageHandlers();
	

			CHandlerNode*			Find(int32 nID);
			void					CreateMsgHandlePool(int nMax, int nStartID);
			virtual void			AddMessageHandler( int32 nID, NETMSG_HANDLE _handler);
			

			virtual void			HandleMessage(int nID, const MemoryStream* pNet);
			CHandlerNode*			mapMsgCode;

		protected:

			int						_max;
			int						_iStartID;

		};

		static MessageHandlers		messageHandlers;
		

		//------------------------------------------------------------------------------------------------------------
		// ������Ϣ�ṹ��
		typedef bool(*msg_handle)(const char* pMsg, int n32MsgLength, INetSession* vthis, int n32MsgID);

		// ������Ϣ�ڵ㣬������������==>������Ϣ�����ַ�֮
		struct MsgNode
		{
			msg_handle mHandle;
			bool mIsInitMsg;
			MsgNode() { mIsInitMsg = false; mHandle = NULL; }
		};


		class IMessageHandle
		{

		public:
			IMessageHandle(int base, int max);
			virtual ~IMessageHandle();

			void					RegisterMsgFunc(int type, msg_handle fuc_handle, bool isInitMsg = false);
			void					SetUnKnownMsgHandle(msg_handle fuc_handle);
			MsgNode*				mNodes;
			msg_handle				mUnknownHandle;
			int						mMax;
			int						mBase;
		};
}
#endif 
