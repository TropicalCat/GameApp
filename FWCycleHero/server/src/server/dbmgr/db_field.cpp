/*
----------------------------------------------------------------------------------------------------------------------------
		file name : db_exception.h
		desc      : ���ݿ��ֶεķ�װ
		author    : ljp

		log		  : by ljp create 2017-06-13
----------------------------------------------------------------------------------------------------------------------------
*/
#include "db_field.h"
#include <string>






namespace KBEngine {

	//----------------------------------------------------------------------------------------------------
	// �õ�TCHAR�ַ���
	// ��������ݴ�����nLen��ֵ��������Ӧ���������nLenΪ0����ת���ɹ����򷵻�ֵΪ��Ҫ�ⲿ�ṩ�Ĵ洢�ռ�
	// ���ַ��������nLen��Ϊ0�����������ַ�ת�������ת���ɹ����򷵻�ת���ɹ����ַ��������򷵻�0
	//----------------------------------------------------------------------------------------------------
	int32 Field::GetTCHAR(TCHAR* szValue, int32 nLen) const
	{
		if( NULL == szValue || NULL == m_szValue || EDBT_BLOB == m_eType )
			return 0;

	#if defined _UNICODE

		return MultiByteToWideChar(CP_UTF8, 0, m_szValue, -1, szValue, nLen);

	#else

		if( nLen < m_uLen + 1 ) return 0;
		memcpy(szValue, m_szValue, m_uLen+1);
		return m_uLen+1;

	#endif
	}

	//------------------------------------------------------------------------------------------------------
	// �õ�sstring�ַ���
	// �����ǰ����UNICODE�������ڲ�����ת������ת�����ַ���д��sstring�У�����ֱ�ӿ���
	//------------------------------------------------------------------------------------------------------
	std::string Field::GetUnicodeString() const
	{
		if( NULL == m_szValue || EDBT_BLOB == m_eType || EDBT_UNKNOWN == m_eType )
			return std::string("");

	#if defined _UNICODE

		INT nDesiredLen = MultiByteToWideChar(CP_UTF8, 0, m_szValue, -1, NULL, 0);
		if (nDesiredLen == 0) return std::string("");

		TCHAR* szResultValue = new TCHAR[nDesiredLen];
		if( 0 == MultiByteToWideChar(CP_UTF8, 0, m_szValue, -1, szResultValue, nDesiredLen) )
		{
			delete []szResultValue;
			return  std::string("");
		}

		//std::string str(szResultValue);
		std::string str("");
		delete[] szResultValue;
		return str;

	#else

		return sstring(m_szValue);

	#endif

	}

	//--------------------------------------------------------------------------------------------------------
	// �õ�blog�ֶε�ֵ�����ؿ������ֽ�����������Ȳ������򷵻�0
	//--------------------------------------------------------------------------------------------------------
	bool Field::GetBlob(void* buffer, ulong uLen) const
	{
		if( uLen < m_uLen ) return false;

		memcpy(buffer, m_szValue, m_uLen);
		return true;
	}

} 