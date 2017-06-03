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

#ifndef KBE_DBTASKS_HPP
#define KBE_DBTASKS_HPP

// common include	
// #define NDEBUG
#include "common/common.hpp"
#include "common/memorystream.hpp"
#include "common/timestamp.hpp"
#include "thread/threadtask.hpp"
#include "helper/debug_helper.hpp"
#include "server/glw_errorcode.hpp"

namespace KBEngine{ 

class DBInterface;
class Buffered_DBTasks;
struct ACCOUNT_INFOS;

/*
	���ݿ��߳����������
*/

	//class DBTask : public Task
	//{
	//public:
	//	DBTask(MemoryStream& datas);

	//	DBTask(const Address& addr):
	//		Task(),
	//	pDatas_(0)
	//	{
	//	}

	//	virtual ~DBTask();

	//	bool send();
	//protected:
	//	MemoryStream* pDatas_;
	//};

	///*
	//	EntityDBTask
	//*/
	//class EntityDBTask : public DBTask
	//{
	//public:
	//	EntityDBTask(const Address& addr, MemoryStream& datas, ENTITY_ID entityID, DBID entityDBID):
	//	DBTask(addr, datas),
	//	_entityID(entityID),
	//	_entityDBID(entityDBID),
	//	_pBuffered_DBTasks(NULL)
	//	{
	//	}
	//
	//	EntityDBTask(const Address& addr, ENTITY_ID entityID, DBID entityDBID):
	//	DBTask(addr),
	//	_entityID(entityID),
	//	_entityDBID(entityDBID),
	//	_pBuffered_DBTasks(NULL)
	//	{
	//	}
	//
	//	virtual ~EntityDBTask(){}
	//
	//	ENTITY_ID EntityDBTask_entityID()const { return _entityID; }
	//	DBID EntityDBTask_entityDBID()const { return _entityDBID; }
	//
	//	void pBuffered_DBTasks(Buffered_DBTasks* v){ _pBuffered_DBTasks = v; }
	//	virtual thread::TPTask::TPTaskState presentMainThread();

	//	DBTask* tryGetNextTask();
	//private:
	//	ENTITY_ID _entityID;
	//	DBID _entityDBID;
	//	Buffered_DBTasks* _pBuffered_DBTasks;
	//};

	///**
	//	ִ��һ��sql���
	//*/
	//class DBTaskExecuteRawDatabaseCommand : public DBTask
	//{
	//public:
	//	DBTaskExecuteRawDatabaseCommand(const Address& addr, MemoryStream& datas);
	//	virtual ~DBTaskExecuteRawDatabaseCommand();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	COMPONENT_ID componentID_;
	//	COMPONENT_TYPE componentType_;
	//	std::string sdatas_;
	//	CALLBACK_ID callbackID_;
	//	std::string error_;
	//	MemoryStream execret_;
	//};


	///**
	//	ִ��һ��sql���
	//*/
	//class DBTaskExecuteRawDatabaseCommandByEntity : public EntityDBTask
	//{
	//public:
	//	DBTaskExecuteRawDatabaseCommandByEntity(const Address& addr, MemoryStream& datas, ENTITY_ID entityID);
	//	virtual ~DBTaskExecuteRawDatabaseCommandByEntity();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	COMPONENT_ID componentID_;
	//	COMPONENT_TYPE componentType_;
	//	std::string sdatas_;
	//	CALLBACK_ID callbackID_;
	//	std::string error_;
	//	MemoryStream execret_;
	//};

	///**
	//	�����ݿ�дentity�� ����entityʱҲ���������
	//*/
	//class DBTaskWriteEntity : public EntityDBTask
	//{
	//public:
	//	DBTaskWriteEntity(const Address& addr, COMPONENT_ID componentID, 
	//		ENTITY_ID eid, DBID entityDBID, MemoryStream& datas);

	//	virtual ~DBTaskWriteEntity();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	COMPONENT_ID componentID_;
	//	ENTITY_ID eid_;
	//	DBID entityDBID_;
	//	CALLBACK_ID callbackID_;
	//	bool success_;
	//};

	///**
	//	�����ݿ���ɾ��entity
	//*/
	//class DBTaskRemoveEntity : public EntityDBTask
	//{
	//public:
	//	DBTaskRemoveEntity(const Address& addr, COMPONENT_ID componentID, 
	//		ENTITY_ID eid, DBID entityDBID, MemoryStream& datas);

	//	virtual ~DBTaskRemoveEntity();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	COMPONENT_ID componentID_;
	//	ENTITY_ID eid_;
	//	DBID entityDBID_;
	//};

	///**
	//	�����ݿ���ɾ��entity
	//*/
	//class DBTaskDeleteBaseByDBID : public DBTask
	//{
	//public:
	//	DBTaskDeleteBaseByDBID(const Address& addr, COMPONENT_ID componentID, 
	//		DBID entityDBID, CALLBACK_ID callbackID);

	//	virtual ~DBTaskDeleteBaseByDBID();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	COMPONENT_ID componentID_;
	//	CALLBACK_ID callbackID_;
	//	DBID entityDBID_;
	//	bool success_;
	//	ENTITY_ID entityID_;
	//	COMPONENT_ID entityInAppID_;
	//};

	///**
	//	ͨ��dbid��ѯһ��ʵ���Ƿ�����ݿ���
	//*/
	//class DBTaskLookUpBaseByDBID : public DBTask
	//{
	//public:
	//	DBTaskLookUpBaseByDBID(const Address& addr, COMPONENT_ID componentID, 
	//		DBID entityDBID, CALLBACK_ID callbackID);

	//	virtual ~DBTaskLookUpBaseByDBID();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	COMPONENT_ID componentID_;
	//	CALLBACK_ID callbackID_;
	//	DBID entityDBID_;
	//	bool success_;
	//	ENTITY_ID entityID_;
	//	COMPONENT_ID entityInAppID_;
	//};

	///**
	//	����һ���˺ŵ����ݿ�
	//*/
	//class DBTaskCreateAccount : public DBTask
	//{
	//public:
	//	DBTaskCreateAccount(const Address& addr, std::string& registerName, std::string& accountName, 
	//		std::string& password, std::string& postdatas, std::string& getdatas);
	//	virtual ~DBTaskCreateAccount();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();

	//	static bool writeAccount(DBInterface* pdbi, const std::string& accountName, 
	//		const std::string& passwd, const std::string& datas, ACCOUNT_INFOS& info);
	//protected:
	//	std::string registerName_; 
	//	std::string accountName_;
	//	std::string password_;
	//	std::string postdatas_, getdatas_;
	//	bool success_;
	//
	//};

	///**
	//	����һ��email�˺�
	//*/
	//class DBTaskCreateMailAccount : public DBTask
	//{
	//public:
	//	DBTaskCreateMailAccount(const Address& addr, std::string& registerName, std::string& accountName, 
	//		std::string& password, std::string& postdatas, std::string& getdatas);
	//	virtual ~DBTaskCreateMailAccount();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string registerName_; 
	//	std::string accountName_;
	//	std::string password_;
	//	std::string postdatas_, getdatas_;
	//	bool success_;
	//
	//};

	///**
	//	����һ��email�˺�
	//*/
	//class DBTaskActivateAccount : public DBTask
	//{
	//public:
	//	DBTaskActivateAccount(const Address& addr, std::string& code);
	//	virtual ~DBTaskActivateAccount();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string code_; 
	//	bool success_;
	//
	//};

	///**
	//	���������˺�
	//*/
	//class DBTaskReqAccountResetPassword : public DBTask
	//{
	//public:
	//	DBTaskReqAccountResetPassword(const Address& addr, std::string& accountName);
	//	virtual ~DBTaskReqAccountResetPassword();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string code_; 
	//	std::string email_;
	//	std::string accountName_;
	//	bool success_;
	//
	//};

	///**
	//	��������˺�
	//*/
	//class DBTaskAccountResetPassword : public DBTask
	//{
	//public:
	//	DBTaskAccountResetPassword(const Address& addr, std::string& accountName, 
	//		std::string& newpassword, std::string& code);
	//	virtual ~DBTaskAccountResetPassword();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string code_; 
	//	std::string accountName_;
	//	std::string newpassword_;
	//	bool success_;
	//
	//};

	///**
	//	�����email
	//*/
	//class DBTaskReqAccountBindEmail : public DBTask
	//{
	//public:
	//	DBTaskReqAccountBindEmail(const Address& addr, ENTITY_ID entityID, std::string& accountName, 
	//		std::string password,std::string& email);
	//	virtual ~DBTaskReqAccountBindEmail();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string code_; 
	//	std::string password_; 
	//	std::string accountName_;
	//	std::string email_; 
	//	bool success_;
	//	ENTITY_ID entityID_;
	//
	//};

	///**
	//	��ɰ�email
	//*/
	//class DBTaskAccountBindEmail : public DBTask
	//{
	//public:
	//	DBTaskAccountBindEmail(const Address& addr, std::string& accountName, 
	//		std::string& code);
	//	virtual ~DBTaskAccountBindEmail();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string code_; 
	//	std::string accountName_;
	//	bool success_;
	//};

	///**
	//	����������
	//*/
	//class DBTaskAccountNewPassword : public DBTask
	//{
	//public:
	//	DBTaskAccountNewPassword(const Address& addr, ENTITY_ID entityID, std::string& accountName, 
	//		std::string& oldpassword_, std::string& newpassword);
	//	virtual ~DBTaskAccountNewPassword();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string accountName_;
	//	std::string oldpassword_, newpassword_;
	//	bool success_;
	//	ENTITY_ID entityID_;
	//};

	///**
	//	baseapp�����ѯaccount��Ϣ
	//*/
	//class DBTaskQueryAccount : public EntityDBTask
	//{
	//public:
	//	DBTaskQueryAccount(const Address& addr, std::string& accountName, std::string& password, 
	//		COMPONENT_ID componentID, ENTITY_ID entityID, DBID entityDBID, uint32 ip, uint16 port);
	//	virtual ~DBTaskQueryAccount();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string accountName_;
	//	std::string password_;
	//	bool success_;
	//	MemoryStream s_;
	//	DBID dbid_;
	//	COMPONENT_ID componentID_;
	//	ENTITY_ID entityID_;
	//	std::string error_;
	//	uint32 ip_;
	//	uint16 port_;

	//	uint32 flags_;
	//	uint64 deadline_;
	//};

	///**
	//	�˺�����
	//*/
	//class DBTaskAccountOnline : public EntityDBTask
	//{
	//public:
	//	DBTaskAccountOnline(const Address& addr, std::string& accountName,
	//		COMPONENT_ID componentID, ENTITY_ID entityID);
	//	virtual ~DBTaskAccountOnline();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string accountName_;
	//	COMPONENT_ID componentID_;
	//};


	///**
	//	entity����
	//*/
	//class DBTaskEntityOffline : public EntityDBTask
	//{
	//public:
	//	DBTaskEntityOffline(const Address& addr, DBID dbid);
	//	virtual ~DBTaskEntityOffline();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:

	//};


	///**
	//	һ�����û���¼�� ��Ҫ���Ϸ���
	//*/
	//class DBTaskAccountLogin : public DBTask
	//{
	//public:
	//	DBTaskAccountLogin(const Address& addr, std::string& loginName, 
	//		std::string& accountName, std::string& password, SERVER_ERROR_CODE retcode, std::string& postdatas, std::string& getdatas);

	//	virtual ~DBTaskAccountLogin();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	std::string loginName_;
	//	std::string accountName_;
	//	std::string password_;
	//	std::string postdatas_, getdatas_;
	//	SERVER_ERROR_CODE retcode_;
	//	COMPONENT_ID componentID_;
	//	ENTITY_ID entityID_;
	//	DBID dbid_;
	//	uint32 flags_;
	//	uint64 deadline_;
	//};

	///**
	//	baseapp�����ѯentity��Ϣ
	//*/
	//class DBTaskQueryEntity : public EntityDBTask
	//{
	//public:
	//	DBTaskQueryEntity(const Address& addr, int8 queryMode, std::string& entityType, DBID dbid, 
	//		COMPONENT_ID componentID, CALLBACK_ID callbackID, ENTITY_ID entityID);

	//	virtual ~DBTaskQueryEntity();
	//	virtual bool db_thread_process();
	//	virtual thread::TPTask::TPTaskState presentMainThread();
	//protected:
	//	int8 queryMode_;
	//	std::string entityType_;
	//	DBID dbid_;
	//	COMPONENT_ID componentID_;
	//	CALLBACK_ID callbackID_;
	//	bool success_;
	//	MemoryStream s_;
	//	ENTITY_ID entityID_;

	//	// ���ʵ���Ѿ�������������ָ��ʵ������app
	//	bool wasActive_;
	//	COMPONENT_ID wasActiveCID_;
	//	ENTITY_ID wasActiveEntityID_;
	//};

}

#endif // KBE_DBTASKS_HPP
