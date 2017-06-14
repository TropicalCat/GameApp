/*
---------------------------------------------------------------------------------------------------------------------------
			file name : db_interface_mysql.h
			desc	  : ���ӺͲ���mysql���ݵķ�װ
			author    : ljp

			log		  : by ljp create 2017-06-13
---------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "db_stream.h"
#include "db_queryresult.h"
#include "db_streampool.h"
#include "db_streamqueue.h"
#include "mysql/mysql.h"






//------------------------------------------------------------------------------------------------------------------------
/**	Database�� - �ṩ���ݿ�����࣬�������ӵĽ�����ά�������ֲ�ѯ�����²������Ƶȵ�
1. Database���������ݿ�һһ��Ӧ������ϲ�Ӧ�ó�����Ҫ����⣬Ҫ�������InterfaceMysql����
1. ���ӳػ��ƣ�������̵߳Ĳ�������
2. �ṩ�����ݿ����Ӳ����Լ���ǰ���ݿ�״̬��Ϣ����ȡ
3. �ṩ���ֲ�ѯ��������ʽ��������ʽ�������ص�ʽ�������޷��ز���
4. �ṩ�򵥵���������ƣ��պ��������������֧��
*/
//------------------------------------------------------------------------------------------------------------------------
namespace KBEngine 
{ 

	struct MysqlConnection
	{
		MYSQL*		m_Mysql;
		MysqlConnection();
	};


	/*
		���ݿ�ӿ�
	*/
	class InterfaceMysql
	{

	public:
		 InterfaceMysql();
		~InterfaceMysql();

		//---------------------------------------------------------------------------
		// ��ʼ��������
		//---------------------------------------------------------------------------
		bool				Init(const char* strHost, const char* strUser, const char* strPassword, const char* strDatabase, int32 nPort, int32 nConNum = 2);
		void				ShutDown();

		//---------------------------------------------------------------------------
		// �������
		//---------------------------------------------------------------------------
		INLINE MysqlConnection* GetFreeConnection();
		INLINE void			ReturnConnection(MysqlConnection* con);

		//---------------------------------------------------------------------------
		// �鿴���Ӷ�ʧ������
		//---------------------------------------------------------------------------
		bool				Reconnect();
		INLINE bool			IsConnLost()		{ return m_bConLost; }

		//---------------------------------------------------------------------------
		// Stream���
		//---------------------------------------------------------------------------
		INLINE MyStream*	GetStream() { return m_StreamPool.AllocStream(); }
		INLINE void			ReturnStream(MyStream* pStream) { m_StreamPool.FreeStream(pStream); }

		//----------------------------------------------------------------------------
		// ��ѯ���
		//----------------------------------------------------------------------------
		INLINE QueryResult* Query(const char* szStr);
		INLINE QueryResult* Query(const MyStream* pStream);
		INLINE QueryResult* WaitQuery(const char* szStr, MysqlConnection* con);
		INLINE QueryResult* WaitQuery(const MyStream* pStream, MysqlConnection* con);

		//-----------------------------------------------------------------------------
		// �������
		//-----------------------------------------------------------------------------
		INLINE bool			Execute(const char* szStr);
		INLINE bool			Execute(const MyStream* pStream);
		INLINE bool			WaitExecute(const char* szStr, MysqlConnection* con);
		INLINE bool			WaitExecute(const MyStream* pStream, MysqlConnection* con);

		//-----------------------------------------------------------------------------
		// ���������
		//-----------------------------------------------------------------------------
		INLINE int32		CheckExecute(const char* szStr);
		INLINE int32		CheckExecute(const MyStream* pStream);
		INLINE int32		CheckWaitExecute(const char* szStr, MysqlConnection* con);
		INLINE int32		CheckWaitExecute(const MyStream* pStream, MysqlConnection* con);

		//------------------------------------------------------------------------------
		// ��¼�����
		//------------------------------------------------------------------------------
		INLINE void			FreeQueryResult(QueryResult* pRet) { SAFE_DEL(pRet); }

		//------------------------------------------------------------------------------
		// �첽�������
		//------------------------------------------------------------------------------
		INLINE void			AddQuery(MyStream* pStream) { m_AsynStreamQueue.Add(pStream); }

		//------------------------------------------------------------------------------
		// �������
		//------------------------------------------------------------------------------
		INLINE bool			BeginTransaction(MysqlConnection* con);
		INLINE bool			EndTransaction(MysqlConnection* con);
		INLINE bool			RollBack(MysqlConnection* con);

		INLINE QueryResult* NextResult(MysqlConnection* con);
		INLINE QueryResult* StoreQueryResult(MysqlConnection* con);
	private:
		InterfaceMysql(const InterfaceMysql&);
		InterfaceMysql& operator = (const InterfaceMysql&);

	private:
		bool				Start();

		INLINE bool			Reconnect(MysqlConnection* con);
		INLINE bool			SendQuery(MysqlConnection* con, const char* szSql, INT nLen, bool bSelf = FALSE);
	protected:

		/**
		������ݿⲻ�����򴴽�һ�����ݿ�
		*/
		virtual bool		createDatabaseIfNotExist();

		/**
		���ݱ����
		*/
		bool				createTable();
		bool				dropTableFromDB(const char* tablename);

		/**
		��ס�ӿڲ���
		*/
		bool				lock();
		bool				unlock();

		/**
		�����쳣
		*/
		bool				processException(std::exception & e);

	protected:
		
		MysqlConnection*	m_SqlConn;
		bool				m_bConLost;
		StreamPool			m_StreamPool;
		SafeStreamQueue		m_AsynStreamQueue;

		std::string			m_Hostname;				// mysql����������
		std::string			m_Username;				// �û���
		std::string			m_Password;				// ����
		std::string			m_DatabaseName;			// ���ݿ���
		int32				m_nPort;				// mysql�������˿ں�
		int32				m_nConNum;
	};


}
