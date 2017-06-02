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


#ifndef KBE_BASEAPP_HPP
#define KBE_BASEAPP_HPP
	
// common include	
#include "server/serverapp.hpp"
#include "proxy.hpp"
#include "profile.hpp"
#include "network/endpoint.hpp"

//#define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif
	
namespace KBEngine{


class Channel;
class Proxy;
class Backuper;
class Archiver;
class TelnetServer;


class Baseapp : public ServerApp,
				public Singleton<Baseapp>
{
public:
	enum TimeOutType
	{
		TIMEOUT_CHECK_STATUS =1,
		TIMEOUT_MAX
	};
	
	Baseapp(EventDispatcher& dispatcher, NetSession& ninterface, COMPONENT_TYPE componentType,COMPONENT_ID componentID);
	~Baseapp();
	
	
	bool					run();
	
	/** 
		��ش���ӿ� 
	*/
	virtual void			handleTimeout(TimerHandle handle, void * arg);
	virtual void			handleGameTick();
	void					handleCheckStatusTick();
	void					handleBackup();
	void					handleArchive();

	/** 
		��ʼ����ؽӿ� 
	*/
	bool					initialize();
	bool					initializeBegin();
	bool					initializeEnd();
	void					finalise();
	
	virtual bool			canShutdown();
	virtual void			onShutdownBegin();
	virtual void			onShutdown(bool first);
	virtual void			onShutdownEnd();

	
	float					getLoad()const { return load_; }
	void					updateLoad();
	static uint64			checkTickPeriod();
	static int				quantumPassedPercent(uint64 curr = timestamp());
	virtual void			onChannelDeregister(Channel * pChannel);

	/**
		һ��cellapp����
	*/
	void onCellAppDeath(Channel * pChannel);

	/** ����ӿ�
		dbmgr��֪�Ѿ�����������baseapp����cellapp�ĵ�ַ
		��ǰapp��Ҫ������ȥ�����ǽ�������
	*/
	virtual void onGetEntityAppFromDbmgr(Channel* pChannel, 
							int32 uid, 
							std::string& username, 
							COMPONENT_TYPE componentType, COMPONENT_ID componentID, COMPONENT_ORDER globalorderID, COMPONENT_ORDER grouporderID,
							uint32 intaddr, uint16 intport, uint32 extaddr, uint16 extport, std::string& extaddrEx);
	
	/** ����ӿ�
		ĳ��client��app��֪���ڻ״̬��
	*/
	void onClientActiveTick(Channel* pChannel);

	

	/**
		�ָ�һ��space 
	*/
	void restoreSpaceInCell(Base* base);

	
	/** �յ�baseappmgr������ĳ��baseappҪ��createBaseAnywhere�������ڱ�baseapp��ִ�� 
		@param entityType	: entity����� entities.xml�еĶ���ġ�
		@param strInitData	: ���entity��������Ӧ�ø�����ʼ����һЩ���ݣ� ��Ҫʹ��pickle.loads���.
		@param componentID	: ���󴴽�entity��baseapp�����ID
	*/
	void onCreateBaseAnywhere(Channel* pChannel, MemoryStream& s);


	/** ����ӿ�
		createBaseFromDBID�Ļص���
	*/
	void onCreateBaseFromDBIDCallback(Channel* pChannel, KBEngine::MemoryStream& s);

	
	/** ����ӿ�
		createBaseFromDBID�Ļص���
	*/
	// �����ݿ����Ļص�
	void onCreateBaseAnywhereFromDBIDCallback(Channel* pChannel, KBEngine::MemoryStream& s);
	// ��������������ϴ������entity
	void createBaseAnywhereFromDBIDOtherBaseapp(Channel* pChannel, KBEngine::MemoryStream& s);
	// ������Ϻ�Ļص�
	void onCreateBaseAnywhereFromDBIDOtherBaseappCallback(Channel* pChannel, COMPONENT_ID createByBaseappID, 
							std::string entityType, ENTITY_ID createdEntityID, CALLBACK_ID callbackID, DBID dbid);
	

	/** 
		baseapp ��createBaseAnywhere�Ļص� 
	*/
	void onCreateBaseAnywhereCallback(Channel* pChannel, KBEngine::MemoryStream& s);
	void _onCreateBaseAnywhereCallback(Channel* pChannel, CALLBACK_ID callbackID, 
		std::string& entityType, ENTITY_ID eid, COMPONENT_ID componentID);

	/** ����ӿ�
		createCellEntityʧ�ܵĻص���
	*/
	void onCreateCellFailure(Channel* pChannel, ENTITY_ID entityID);

	/** ����ӿ�
		createCellEntity��cellʵ�崴���ɹ��ص���
	*/
	void onEntityGetCell(Channel* pChannel, ENTITY_ID id, COMPONENT_ID componentID, SPACE_ID spaceID);

	/** 
		֪ͨ�ͻ��˴���һ��proxy��Ӧ��ʵ�� 
	*/
	bool createClientProxies(Proxy* base, bool reload = false);

	void onExecuteRawDatabaseCommandCB(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		dbmgr���ͳ�ʼ��Ϣ
		startID: ��ʼ����ENTITY_ID ����ʼλ��
		endID: ��ʼ����ENTITY_ID �ν���λ��
		startGlobalOrder: ȫ������˳�� �������ֲ�ͬ���
		startGroupOrder: ��������˳�� ����������baseapp�еڼ���������
	*/
	void onDbmgrInitCompleted(Channel* pChannel, 
		GAME_TIME gametime, ENTITY_ID startID, ENTITY_ID endID, COMPONENT_ORDER startGlobalOrder, COMPONENT_ORDER startGroupOrder, const std::string& digest);

	/** ����ӿ�
		dbmgr�㲥global���ݵĸı�
	*/
	void onBroadcastBaseAppDataChanged(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		ע�ὫҪ��¼���˺�, ע����������¼��������
	*/
	void registerPendingLogin(Channel* pChannel, std::string& loginName, std::string& accountName, 
		std::string& password, ENTITY_ID entityID, DBID entityDBID, uint32 flags, uint64 deadline, COMPONENT_TYPE componentType);

	/** ����ӿ�
		���û������¼��������
	*/
	void loginGateway(Channel* pChannel, std::string& accountName, std::string& password);

	
	/** ����ӿ�
		���µ�¼ ���������ؽ���������ϵ(ǰ����֮ǰ�Ѿ���¼�ˣ� 
		֮��Ͽ��ڷ������ж���ǰ�˵�Entityδ��ʱ���ٵ�ǰ���¿��Կ�����������������Ӳ��ﵽ�ٿظ�entity��Ŀ��)
	*/
	void reLoginGateway(Channel* pChannel, std::string& accountName, 
		std::string& password, uint64 key, ENTITY_ID entityID);

	/** ����ӿ�
		��dbmgr��ȡ���˺�Entity��Ϣ
	*/
	void onQueryAccountCBFromDbmgr(Channel* pChannel, KBEngine::MemoryStream& s);
	
	/**
		�ͻ����������������
	*/
	void onClientEntityEnterWorld(Proxy* base, COMPONENT_ID componentID);

	/** ����ӿ�
		entity�յ�һ��mail, ��ĳ��app�ϵ�mailbox����(ֻ����������ڲ�ʹ�ã� �ͻ��˵�mailbox���÷�����
		onRemoteCellMethodCallFromClient)
	*/
	void onEntityMail(Channel* pChannel, KBEngine::MemoryStream& s);
	
	/** ����ӿ�
		client����entity��cell����
	*/
	void onRemoteCallCellMethodFromClient(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		client��������
	*/
	void onUpdateDataFromClient(Channel* pChannel, KBEngine::MemoryStream& s);


	/** ����ӿ�
		cellapp����entity��cell����
	*/
	void onBackupEntityCellData(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		cellapp writeToDB���
	*/
	void onCellWriteToDBCompleted(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		cellappת��entity��Ϣ��client
	*/
	void forwardMessageToClientFromCellapp(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		cellappת��entity��Ϣ��ĳ��baseEntity��cellEntity
	*/
	void forwardMessageToCellappFromCellapp(Channel* pChannel, KBEngine::MemoryStream& s);
	

	/** ����ӿ�
		дentity��db�ص�
	*/
	void onWriteToDBCallback(Channel* pChannel, ENTITY_ID eid, DBID entityDBID, CALLBACK_ID callbackID, bool success);

	/**
		����proxices����
	*/
	void incProxicesCount(){ ++numProxices_; }

	/**
		����proxices����
	*/
	void decProxicesCount(){ --numProxices_; }

	/**
		���proxices����
	*/
	int32 numProxices()const{ return numProxices_; }

	
	void onChargeCB(Channel* pChannel, KBEngine::MemoryStream& s);

	
	virtual void onHello(Channel* pChannel, 
		const std::string& verInfo, 
		const std::string& scriptVerInfo, 
		const std::string& encryptedKey);

	
	/** ����ӿ�
		����������APP���ѻָ����ؽ��
	*/
	void onRequestRestoreCB(Channel* pChannel, KBEngine::MemoryStream& s);

	
	/** ����ӿ�
		ĳ��baseapp�ϵ�space�ָ���cell�� �жϵ�ǰbaseapp�Ƿ������entity��Ҫ�ָ�cell
	*/
	void onRestoreSpaceCellFromOtherBaseapp(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		ĳ��app����鿴��app
	*/
	virtual void lookApp(Channel* pChannel);

	/** ����ӿ�
		�ͻ���Э�鵼��
	*/
	void importClientMessages(Channel* pChannel);

	/** ����ӿ�
		�ͻ���entitydef����
	*/
	void importClientEntityDef(Channel* pChannel);

	
	/** ����ӿ�
		ͨ��dbid�����ݿ���ɾ��һ��ʵ��Ļص�
	*/
	void deleteBaseByDBIDCB(Channel* pChannel, KBEngine::MemoryStream& s);

	
	/** ����ӿ�
		���ʵ�����߻ص�����basemailbox�����ʵ�岻������ص�����true�������κ�ԭ�򶼷���false.
	*/
	void lookUpBaseByDBIDCB(Channel* pChannel, KBEngine::MemoryStream& s);

	/** ����ӿ�
		�����email
	*/
	void reqAccountBindEmail(Channel* pChannel, ENTITY_ID entityID, std::string& password, std::string& email);


	/** ����ӿ�
		�����email
	*/
	void reqAccountNewPassword(Channel* pChannel, ENTITY_ID entityID, std::string& oldpassworld, std::string& newpassword);

	
protected:
	TimerHandle												loopCheckTimerHandle_;

	
	// ���ݴ浵���
	SHARED_PTR< Backuper >								pBackuper_;	
	SHARED_PTR< Archiver >								pArchiver_;	

	float													load_;

	static uint64											_g_lastTimestamp;

	int32													numProxices_;

	TelnetServer*											pTelnetServer_;

	
	TimerHandle												pResmgrTimerHandle_;
};

}

#endif // KBE_BASEAPP_HPP
