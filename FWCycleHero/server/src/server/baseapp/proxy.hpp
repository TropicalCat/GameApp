/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef KBE_PROXY_HPP
#define KBE_PROXY_HPP
	
// common include
#include "base.hpp"
#include "data_downloads.hpp"
#include "common/common.hpp"
#include "helper/debug_helper.hpp"
#include "network/message_handler.hpp"

//#define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif
	
namespace KBEngine{



class Channel;
class ProxyForwarder;

#define LOG_ON_REJECT  0
#define LOG_ON_ACCEPT  1
#define LOG_ON_WAIT_FOR_DESTROY 2

class Proxy : public Base
{
	/** ���໯ ��һЩpy�������������� */
	
public:
	Proxy(ENTITY_ID id);
	~Proxy();
	
	INLINE void addr(const Address& address);
	INLINE const Address& addr()const;

	typedef std::vector<Bundle*> Bundles;
	Bundles* pBundles();

	
	bool sendToClient(Bundle* pBundle);
	bool sendToClient(bool expectData = true);

	/** 
		�ű������ȡ���ӵ�rttֵ
	*/
	double getRoundTripTime()const;
	
	/** 
		This is the number of seconds since a packet from the client was last received. 
	*/
	double getTimeSinceHeardFromClient()const;
	
	/** 
		�ű������ȡ�Ƿ���client�󶨵�proxy��
	*/
	bool hasClient()const;
	
	/** 
		�ű������ȡ���ӵ�rttֵ
	*/
	INLINE bool entitiesEnabled()const;
	
	/**
		���entity��������, �ڿͻ��˳�ʼ���ö�Ӧ��entity�� �������������
	*/
	void onEntitiesEnabled(void);
	
	/**
		һ�����������������
	*/
	void onStreamComplete(int16 id, bool success);

	/**
		��½���ԣ� �������ĵ�½ʧ��֮�� ��������ӿ��ٽ��г��� 
	*/
	int32 onLogOnAttempt(const char* addr, uint32 port, const char* password);
	
	/**
		��ʼ���ͻ���proxy������
	*/
	void initClientBasePropertys();
	void initClientCellPropertys();

	/** 
		��������entity��Ӧ�Ŀͻ���socket�Ͽ�ʱ������ 
	*/
	void onClientDeath(void);
	
	/** ����ӿ�
		���ͻ��������������entity��cell������ʱ�������� 
	*/
	void onClientGetCell(Channel* pChannel, COMPONENT_ID componentID);

	/**
		��ȡǰ�����
	*/
	INLINE COMPONENT_CLIENT_TYPE getClientType()const;
	INLINE void setClientType(COMPONENT_CLIENT_TYPE ctype);
	
	/**
		ÿ��proxy����֮�󶼻���ϵͳ����һ��uuid�� �ṩǰ���ص�½ʱ�������ʶ��
	*/
	INLINE uint64 rndUUID()const;
	INLINE void rndUUID(uint64 uid);

	/** 
		���������������Ŀͻ���ת����һ��proxyȥ���� 
	*/
	void giveClientTo(Proxy* proxy);
	void onGiveClientTo(Channel* lpChannel);
	void onGiveClientToFailure();
	

	
	/**
		����witness
	*/
	void onGetWitness();

protected:
	uint64 rndUUID_;
	Address addr_;
	DataDownloads dataDownloads_;

	bool entitiesEnabled_;

	// ���ƿͻ���ÿ������ʹ�õĴ���
	int32 bandwidthPerSecond_;

	// ͨ�ż���key Ĭ��blowfish
	std::string encryptionKey;

	ProxyForwarder* pProxyForwarder_;

	COMPONENT_CLIENT_TYPE clientComponentType_;
};

}


#ifdef CODE_INLINE
#include "proxy.ipp"
#endif

#endif // KBE_PROXY_HPP
