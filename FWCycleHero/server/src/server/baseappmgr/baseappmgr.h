/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2016 KBEngine.

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


#ifndef KBE_BASEAPPMGR_H
#define KBE_BASEAPPMGR_H

#include "baseapp.h"
#include "server/glw_main.hpp"
#include "server/serverapp.hpp"
#include "server/serverconfig.hpp"
#include "common/timer.hpp"
#include "network/endpoint.hpp"
	
namespace KBEngine{

class Baseappmgr :	public ServerApp, 
					public Singleton<Baseappmgr>
{
public:
	enum TimeOutType
	{
		TIMEOUT_GAME_TICK = TIMEOUT_SERVERAPP_MAX + 1
	};
	
	Baseappmgr(EventDispatcher& dispatcher, 
		NetSession& ninterface, 
		COMPONENT_TYPE componentType,
		COMPONENT_ID componentID);

	~Baseappmgr();
	
	bool run();
	
	virtual void onChannelDeregister(Channel * pChannel);
	virtual void onAddComponent(const Components::ComponentInfos* pInfos);

	void handleTimeout(TimerHandle handle, void * arg);
	void handleGameTick();

	/* ��ʼ����ؽӿ� */
	bool initializeBegin();
	bool inInitialize();
	bool initializeEnd();
	void finalise();

	COMPONENT_ID findFreeBaseapp();
	void updateBestBaseapp();

	/** ����ӿ�
		�յ�baseapp::createBaseAnywhere������ĳ�����е�baseapp�ϴ���һ��baseEntity
		@param sp: ������ݰ��д洢���� entityType	: entity����� entities.xml�еĶ���ġ�
										strInitData	: ���entity��������Ӧ�ø�����ʼ����һЩ���ݣ� 
													  ��Ҫʹ��pickle.loads���.
										componentID	: ���󴴽�entity��baseapp�����ID
	*/
	void reqCreateBaseAnywhere(Channel* pChannel, MemoryStream& s);

	/** ����ӿ�
		�յ�baseapp::createBaseAnywhereFromDBID������ĳ�����е�baseapp�ϴ���һ��baseEntity
	*/
	void reqCreateBaseAnywhereFromDBID(Channel* pChannel, MemoryStream& s);

	/** ����ӿ�
		��Ϣת���� ��ĳ��app��ͨ����app����Ϣת����ĳ��app��
	*/
	void forwardMessage(Channel* pChannel, MemoryStream& s);

	/** ����ӿ�
		һ���µ�¼���˺Ż�úϷ�����baseapp��Ȩ���� ������Ҫ���˺�ע���baseapp
		ʹ�������ڴ�baseapp�ϵ�¼��
	*/
	void registerPendingAccountToBaseapp(Channel* pChannel, MemoryStream& s);

	/** ����ӿ�
		һ���µ�¼���˺Ż�úϷ�����baseapp��Ȩ���� ������Ҫ���˺�ע���ָ����baseapp
		ʹ�������ڴ�baseapp�ϵ�¼��
	*/
	void registerPendingAccountToBaseappAddr(Channel* pChannel, MemoryStream& s);

	/** ����ӿ�
		baseapp���Լ��ĵ�ַ���͸�loginapp��ת�����ͻ��ˡ�
	*/
	void onPendingAccountGetBaseappAddr(Channel* pChannel, 
								  std::string& loginName, std::string& accountName, 
								  std::string& addr, uint16 port);

	/** ����ӿ�
		����baseapp�����
	*/
	void updateBaseapp(Channel* pChannel, COMPONENT_ID componentID,
								ENTITY_ID numBases, ENTITY_ID numProxices, float load, uint32 flags);

	/** ����ӿ�
		baseappͬ���Լ��ĳ�ʼ����Ϣ
		startGlobalOrder: ȫ������˳�� �������ֲ�ͬ���
		startGroupOrder: ��������˳�� ����������baseapp�еڼ���������
	*/
	void onBaseappInitProgress(Channel* pChannel, COMPONENT_ID cid, float progress);

	/** 
		�������baseapp��ַ���͸�loginapp��ת�����ͻ��ˡ�
	*/
	void sendAllocatedBaseappAddr(Channel* pChannel, 
								  std::string& loginName, std::string& accountName, 
								  const std::string& addr, uint16 port);

	bool componentsReady();
	bool componentReady(COMPONENT_ID cid);

protected:
	TimerHandle													gameTimer_;

	COMPONENT_ID												bestBaseappID_;

	std::map< COMPONENT_ID, Baseapp >							baseapps_;

	UNORDERED_MAP< std::string, COMPONENT_ID >					pending_logins_;

	float														baseappsInitProgress_;
};

}

#endif // KBE_BASEAPPMGR_H
