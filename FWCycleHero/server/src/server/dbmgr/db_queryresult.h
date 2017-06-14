/*
----------------------------------------------------------------------------------------------------------------------------
		file name : db_queryresult.h
		desc      : ��ѯ�����װ
		author    : ljp

		log		  : by ljp create 2017-06-13
----------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "helper/debug_helper.hpp"
#include "db_field.h"
#include "mysql/mysql.h"







namespace KBEngine {

	//----------------------------------------------------------------------------------------------------
	/**	QueryResult�� - �ṩ���ݿ���������ع��ܣ��Խ��������������ݺ����Խ��й���
		1. �ṩ����������ȡ����Ĺ��ܣ�ÿ���µ���ֵ����µ�����Field��
		2. �ṩ���������ַ��������еĹ���
		3. �ṩ��ѯ���ԵĹ��ܣ������������������ȵ�
		4. �ṩ�α�Ĺ��ܣ����Զ�λ����Ӧ�кͶ�Ӧ�У�������ɣ�
	
		ע������
		1. �ý����ֻ������ʹ��mysql_store_result()���صĽ����������mysql_use_reslut()�Ľ�������ڻ����ṩ֧��
		2. ����mysql_use_resultʹ�õĽ������һ�㲻�Ƽ�ʹ�ã��������ṩ�ù��ܵļ���
	*/
	//----------------------------------------------------------------------------------------------------
	class Field;
	struct MysqlConnection;
	class QueryResult
	{
	public:
		QueryResult(MYSQL_RES* result, int32 nRows, int32 nCols, MysqlConnection* con);
		~QueryResult();

		inline int32			GetRowCount() const			{ return m_nRows; }
		inline int32			GetFieldCount() const		{ return m_nCols; }
		inline const Field*		Fetch() const				{ return m_CurrentRow; }

		bool					NextRow();
		inline Field&			operator [] (int32 nIndex) const { KBE_ASSERT(nIndex >= 0 && nIndex < m_nCols && m_CurrentRow != NULL); return m_CurrentRow[nIndex]; }
		inline Field&			operator [] (char* szFieldName) const;

	private:
		Field::DataTypes ConvertType(enum_field_types mysqlType) const;
	
	private:
		MYSQL_RES*		m_Result;			// mysql�����
		int32			m_nRows;			// ���������
		int32			m_nCols;			// ���������
		Field*			m_CurrentRow;		// ��ǰ���м�
		MysqlConnection*	m_con;

	};

}