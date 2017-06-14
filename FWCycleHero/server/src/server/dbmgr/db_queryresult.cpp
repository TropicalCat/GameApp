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
#include "db_queryresult.h"
#include "db_field.h"
#include "db_interface_mysql.h"






namespace KBEngine {

	//---------------------------------------------------------------------------------------------------
	// ���캯��
	//---------------------------------------------------------------------------------------------------
	QueryResult::QueryResult(MYSQL_RES* result, INT nRows, INT nCols, Connection* con)
							: m_Result(result), m_nRows(nRows), m_nCols(nCols), m_con(con)
	{
		KBE_ASSERT(m_Result != NULL && m_nRows >= 0 && m_nCols > 0);

		m_CurrentRow = new Field[m_nCols];
		KBE_ASSERT(m_CurrentRow != NULL);

		MYSQL_FIELD* field = mysql_fetch_fields(m_Result);
		for(INT n = 0; n < m_nCols; n++)
		{
			m_CurrentRow[n].SetALL(field[n].name, ConvertType(field[n].type), field[n].max_length);
		}
	}

	//-----------------------------------------------------------------------------------------------------
	// ��������
	//-----------------------------------------------------------------------------------------------------
	QueryResult::~QueryResult()
	{
		delete[] m_CurrentRow;
		if( m_Result )
			mysql_free_result(m_Result);
		//do {
		//	MYSQL_RES* pRes = mysql_store_result(m_con->m_Mysql);
		//	mysql_free_result( pRes );
		//}while( mysql_next_result(m_con->m_Mysql) );
	}

	//-----------------------------------------------------------------------------------------------------
	// �õ���һ��
	// ע�⣺������QueryResultʱ���ϲ���Ҫ���̵���һ��NextRow���Ա㶨λ��������ĵ�һ��
	//-----------------------------------------------------------------------------------------------------
	bool QueryResult::NextRow()
	{
		MYSQL_ROW row = mysql_fetch_row(m_Result);
		if( NULL == row )
			return false;

		// ͬʱ������ֵ���еĳ���
		ulong* uLen = mysql_fetch_lengths(m_Result);
		for(INT n = 0; n < m_nCols; n++)
		{
			m_CurrentRow[n].SetValue(row[n]);
			m_CurrentRow[n].SetLen(uLen[n]);
		}

		return true;
	}

	//-----------------------------------------------------------------------------------------------------
	// ת��mysql����������ΪFieldԤ�����ö������
	//-----------------------------------------------------------------------------------------------------
	Field::DataTypes QueryResult::ConvertType(enum_field_types mysqlType) const
	{
		switch (mysqlType)
		{
		case FIELD_TYPE_TIMESTAMP:
		case FIELD_TYPE_DATE:
		case FIELD_TYPE_TIME:
		case FIELD_TYPE_DATETIME:
		case FIELD_TYPE_YEAR:
		case FIELD_TYPE_STRING:
		case FIELD_TYPE_VAR_STRING:
		case FIELD_TYPE_SET:
		case FIELD_TYPE_NULL:
			return Field::EDBT_STRING;

		case FIELD_TYPE_TINY:
		case FIELD_TYPE_SHORT:
		case FIELD_TYPE_LONG:
		case FIELD_TYPE_INT24:
		case FIELD_TYPE_LONGLONG:
		case FIELD_TYPE_ENUM:
			return Field::EDBT_INTEGER;

		case FIELD_TYPE_DECIMAL:
		case FIELD_TYPE_FLOAT:
		case FIELD_TYPE_DOUBLE:
			return Field::EDBT_FLOAT;
		
		case FIELD_TYPE_BLOB:
			return Field::EDBT_BLOB;

		default:
			return Field::EDBT_UNKNOWN;
		}
	}

}