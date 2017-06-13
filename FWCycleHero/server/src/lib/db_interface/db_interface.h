/*
----------------------------------------------------------------------------------------------------------------------------
		file name : db_interface.h
		desc      : Ӧ�ò㵽DB�����ķ�װ
		author    : ljp

		log		  : by ljp create 2017-06-13
----------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "common/singleton.hpp"
#include "helper/debug_helper.hpp"
#include "db_interface/entity_table.h"







namespace KBEngine 
{ 

	namespace thread
	{
		class ThreadPool;
	}
	class DBUtil;

	/*
		���ݿ�ӿ�
	*/
	class DBInterface
	{
	public:
		enum DB_OP_STATE
		{
			DB_OP_READ,
			DB_OP_WRITE,
		};

		friend class DBUtil;
		DBInterface(): db_port_(3306), db_numConnections_(1),lastquery_()
		{

		};

		virtual ~DBInterface()
		{

		};

		/**
			��黷��
		*/
		virtual bool				checkEnvironment() = 0;
	
		/**
			������ �Դ�������ݽ��о���
			����������ɹ�����ʧ��
		*/
		virtual bool				checkErrors() = 0;

		/**
			��ĳ�����ݿ����
		*/
		virtual bool				attach(const char* databaseName) = 0;
		virtual bool				detach() = 0;

		/**
			��ȡ���ݿ����еı���
		*/
		virtual bool				getTableNames( std::vector<std::string>& tableNames, const char * pattern) = 0;

		/**
			��ȡ���ݿ�ĳ�������е��ֶ�����
		*/
		virtual bool				getTableItemNames(const char* tablename, std::vector<std::string>& itemNames) = 0;

		/**
			��ѯ��
		*/
		virtual bool				query(const char* strCommand, uint32 size, bool showexecinfo = true) = 0;
		virtual bool				query(const std::string& cmd, bool showexecinfo = true)
		{
			return					query(cmd.c_str(), cmd.size(), showexecinfo);
		}

		/**
			��������ӿڵ�����
		*/
		virtual const char*			c_str() = 0;

		/** 
			��ȡ����
		*/
		virtual const char*			getstrerror() = 0;

		/** 
			��ȡ������
		*/
		virtual int					getlasterror() = 0;

		/**
			����һ��entity�洢��
		*/
		virtual EntityTable*		createEntityTable() = 0;

		/** 
			�����ݿ�ɾ��entity��
		*/
		virtual bool				dropEntityTableFromDB(const char* tablename) = 0;

		/** 
			�����ݿ�ɾ��entity���ֶ�
		*/
		virtual bool				dropEntityTableItemFromDB(const char* tablename, const char* tableItemName) = 0;

		/**
			��ס�ӿڲ���
		*/
		virtual bool				lock() = 0;
		virtual bool				unlock() = 0;

		/**
			�����쳣
		*/
		virtual bool				processException(std::exception & e) = 0;

		/**
			��ȡ���һ�β�ѯ��sql���
		*/
		virtual const std::string& lastquery() const{ return lastquery_; }
	protected:

		char						db_type_[MAX_BUF];									// ���ݿ�����
		uint32						db_port_;											// ���ݿ�Ķ˿�
		char						db_ip_[MAX_IP];										// ���ݿ��ip��ַ
		char						db_username_[MAX_BUF];								// ���ݿ���û���
		char						db_password_[MAX_BUF];								// ���ݿ������
		char						db_name_[MAX_BUF];									// ���ݿ���
		uint16						db_numConnections_;									// ���ݿ��������
		std::string					lastquery_;											// ���һ�β�ѯ����
	};

	/*
		���ݿ������Ԫ
	*/
	class DBUtil : public Singleton<DBUtil>
	{
	public:
		DBUtil();
		~DBUtil();
	
		static bool					initialize();
		static void					finalise();

		static bool					initThread();
		static bool					finiThread();

		static DBInterface*			createInterface(bool showinfo = true);
		static const char*			dbname();
		static const char*			dbtype();
		static const char*			accountScriptName();
		static bool					initInterface(DBInterface* dbi);

		static thread::ThreadPool*  pThreadPool(){ return pThreadPool_; }
	private:
		static thread::ThreadPool*  pThreadPool_;
	};

}
