/*
-------------------------------------------------------------------------------------
		file name	: interfaces.hpp
		desc		: һЩ��Ϣ֪ͨ�������Ľӿ�
		author		: ljp

		log			: [ 2015-04-28 ]
-------------------------------------------------------------------------------------
*/

#ifndef KBE_NETWORK_INTERFACES_HPP
#define KBE_NETWORK_INTERFACES_HPP





namespace KBEngine 
{ 
		class MessageHandler;

		/** ����ӿ����ڽ�����ͨ��Network������Ϣ֪ͨ������
		*/
		class InputNotificationHandler
		{
		public:
			virtual ~InputNotificationHandler() {};
			virtual int handleInputNotification(int fd) { return 0; };
		};

		/** ����ӿ����ڽ�����ͨ��Network�����Ϣ֪ͨ������
		*/
		class OutputNotificationHandler
		{
		public:
			virtual ~OutputNotificationHandler() {};
			virtual int handleOutputNotification(int fd) = 0;
		};

		/** ����ӿ����ڼ���NetworkStats�¼�
		*/
		class NetworkStatsHandler
		{
		public:
			virtual void onSendMessage(const MessageHandler& msgHandler, int size) = 0;
			virtual void onRecvMessage(const MessageHandler& msgHandler, int size) = 0;
		};
}

#endif // KBE_NETWORK_INTERFACES_HPP
