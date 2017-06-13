/*
--------------------------------------------------------------------------------------------------------------
		file name : 
		desc      : �������ݷ�װ���������
		author	  : ljp

		log		  : by ljp create 2017-06-13
--------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "common/timer.hpp"
#include "thread/threadtask.hpp"






namespace KBEngine
{ 
	/*-----------------------------------------------------------------------------------------------
	enum TPTaskState
	{
		/// һ�������Ѿ����
		TPTASK_STATE_COMPLETED				= 0,

		/// ���������߳�ִ��
		TPTASK_STATE_CONTINUE_MAINTHREAD	= 1,

		// ���������߳�ִ��
		TPTASK_STATE_CONTINUE_CHILDTHREAD	= 2,
	};
	------------------------------------------------------------------------------------------------*/
	class MemoryStream;
	class DBInterface;
	class EntityTable;

	/*
		���ݿ��߳����������
	*/
	class DBTaskBase : public thread::TPTask
	{
	public:

		DBTaskBase():
		initTime_(timestamp())
		{
		}

		virtual ~DBTaskBase(){}
		virtual bool			process();
		virtual bool			db_thread_process() = 0;
		virtual DBTaskBase*		tryGetNextTask(){ return NULL; }
		
		virtual void			pdbi(DBInterface* ptr){ pdbi_ = ptr; }
		virtual thread::TPTask::TPTaskState presentMainThread();

		uint64					initTime() const{ return initTime_; }
	protected:

		DBInterface*			pdbi_;
		uint64					initTime_;
	};

	/**
		ִ��һ��sql���
	*/
	class DBTaskSyncTable : public DBTaskBase
	{
	public:
		DBTaskSyncTable(SHARED_PTR<EntityTable> pEntityTable);
		virtual ~DBTaskSyncTable();
		virtual bool			db_thread_process();
		virtual thread::TPTask::TPTaskState presentMainThread();
	protected:
		SHARED_PTR<EntityTable> pEntityTable_;
		bool success_;
	};
}

