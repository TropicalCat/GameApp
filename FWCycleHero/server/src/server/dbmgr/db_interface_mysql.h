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
#include "common/singleton.hpp"
#include "common/memorystream.hpp"
#include "helper/debug_helper.hpp"
#include "mysql/mysql.h"






//------------------------------------------------------------------------------------------------------------------------
/**	Database�� - �ṩ���ݿ�����࣬�������ӵĽ�����ά�������ֲ�ѯ�����²������Ƶȵ�
1. Database���������ݿ�һһ��Ӧ������ϲ�Ӧ�ó�����Ҫ����⣬Ҫ�������Database����
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
		virtual ~InterfaceMysql();

	private:
		InterfaceMysql(const InterfaceMysql&);
		InterfaceMysql& operator = (const InterfaceMysql&);



	protected:

	};


}
