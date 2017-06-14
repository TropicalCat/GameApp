/*
----------------------------------------------------------------------------------------------------------------------------
		file name : db_stream.h
		desc      : ���ݿ��������װ
		author    : ljp

		log		  : by ljp create 2017-06-13
----------------------------------------------------------------------------------------------------------------------------
*/
#include "db_stream.h"
#include "db_interface_mysql.h"
#include "mysql/mysql.h"






namespace {
	const int BUFSIZE = 64;
};


namespace KBEngine
{
	//---------------------------------------------------------------------------------
	// ���캯������ʼ�����ڴ�
	//---------------------------------------------------------------------------------
		MyStream::MyStream(int32 nDefaultSize)
		: m_nBufLen(nDefaultSize), m_nDefaultSize(nDefaultSize), m_nPos(0)
	{
		m_pBuf = new char[m_nDefaultSize];
		if( NULL == m_pBuf ) { abort(); }
		m_pBuf[0] = 0;
	}

	//----------------------------------------------------------------------------------
	// ��������
	//----------------------------------------------------------------------------------
	MyStream::~MyStream()
	{
		SAFE_DEL_ARRAY(m_pBuf);
	}

	//----------------------------------------------------------------------------
	// �ַ����α��ƶ���ָ��λ��
	//----------------------------------------------------------------------------
	bool MyStream::Seek(int32 nPos)
	{
		if( nPos <= m_nBufLen - 1 )
		{
			m_nPos = nPos;
			End();
			return TRUE;
		}
		return FALSE;
	}

	//-----------------------------------------------------------------------------
	// ���ַ�����������
	//-----------------------------------------------------------------------------
	void MyStream::Grow(int32 nSize)
	{
		if( nSize <= 0 ) nSize = m_nDefaultSize;

		if( m_nPos + nSize <= m_nBufLen - 1 )
			return;

		INT nTmpLen = m_nBufLen  + nSize;
		char* pTmp = new char[nTmpLen];

		// ����ԭ��������
		if(m_pBuf)
		{
			memcpy(pTmp, m_pBuf, m_nBufLen);
			SAFE_DEL_ARRAY(m_pBuf);
		}

		m_pBuf = pTmp;
		m_nBufLen = nTmpLen;
	}

	//-------------------------------------------------------------------------------
	// ����������غ���
	//-------------------------------------------------------------------------------
	MyStream& MyStream::operator << (const uint32 v)
	{
		char szBuf[BUFSIZE] = {0,};
		int n = sprintf_s( szBuf, BUFSIZE, "%u", v);
		if( n != -1 )
		{
			Grow(n);
			memcpy( m_pBuf + m_nPos, szBuf, n );
			m_nPos += n;
			End();
		}

		return *this;
	}


	MyStream& MyStream::operator << (const int32 p)
	{
		char szBuf[64] = { 0 };
		_itoa_s(p, szBuf, 10);

		INT nLen = strlen(szBuf);
		Grow(nLen);
		memcpy(m_pBuf + m_nPos, szBuf, nLen);
		m_nPos += nLen;
		End();
		return *this;
	}

	MyStream& MyStream::operator << (const int64 p)
	{
		char szBuf[96] = { 0 };
		_i64toa_s(p, szBuf, 96, 10);

		size_t nLen = strlen(szBuf);
		Grow(nLen);
		memcpy(m_pBuf + m_nPos, szBuf, nLen);
		m_nPos += nLen;
		End();
		return *this;

	}

	MyStream& MyStream::operator << (const double p)
	{
		char szBuf[_CVTBUFSIZE] = { 0 };
		_gcvt_s(szBuf, p, 5);

		size_t nLen = strlen(szBuf);
		Grow(nLen);
		memcpy(m_pBuf + m_nPos, szBuf, nLen);
		m_nPos += nLen;
		End();
		return *this;
	}

	MyStream& MyStream::operator << (const char* p)
	{
		FillString( p );
		return *this;
	}

	MyStream& MyStream::operator << (const WCHAR* p)
	{
		FillString( "'" );
		FillString( p );
		FillString( "'" );
		return *this;
	}

	MyStream& MyStream::operator << (const CBlobStreamAdapter& adapter)
	{
		FillBlob(adapter.BlobData(), adapter.Length(), adapter.Con());
		return *this;
	}


	//----------------------------------------------------------------------------
	// ����Unicode�ַ���
	//----------------------------------------------------------------------------
	MyStream& MyStream::FillString(const char* p, MysqlConnection* con/* = NULL */)
	{
		if( NULL == p || '\0' == p[0] ) return (*this);

		// ת���ַ���
		if( NULL != con )
		{
			size_t nStrlen = strlen(p);
			size_t nGrowSize = nStrlen * 2 + 1;
			Grow(nGrowSize);
			char* pRet = m_pBuf + m_nPos;
			memset(pRet, 0, nGrowSize);
			size_t nLen = mysql_real_escape_string(con->m_Mysql, pRet, p, nStrlen);
			m_nPos += nLen;
			End();
		}
		// ��ת���ַ���
		else
		{
			size_t nLen = strlen(p);
			Grow(nLen);
			char* pRet = m_pBuf + m_nPos;
			strcat(pRet, p);
			m_nPos += nLen;
			End();
		}

		return *this;
	}

	//------------------------------------------------------------------------------
	// ���Unicode�ַ���
	//------------------------------------------------------------------------------
	MyStream& MyStream::FillString(const WCHAR* p, MysqlConnection* con/* =NULL */)
	{
		if( NULL == p || 0 == p[0] ) return (*this);

		// �ַ���ת��
		int32 nDesiredLen = WideCharToMultiByte(CP_UTF8, 0, p, -1, NULL, 0, NULL, NULL);
		if( 0 == nDesiredLen ) return (*this);

		char* szTemp = new char[nDesiredLen];
		if( 0 == WideCharToMultiByte(CP_UTF8, 0, p, -1, szTemp, nDesiredLen, NULL, NULL) )
		{
			SAFE_DEL_ARRAY(szTemp);
			return (*this);
		}

		// ���г����ַ�������
		FillString(szTemp, con);

		// ɾ����ʱ�ַ���
		SAFE_DEL_ARRAY(szTemp);

		return (*this);
	}


	//------------------------------------------------------------------------------
	// ���BLOB�ֶ�
	//------------------------------------------------------------------------------
	MyStream& MyStream::FillBlob(const VOID* p, int32 nSize, MysqlConnection* con/* =NULL */)
	{
		if( NULL == p || nSize <= 0 )	return (*this);

		if( NULL == con ) return (*this);

		// ת��
		int32 nGrowSize = nSize * 2 + 1;
		Grow(nGrowSize);
		char* pRet = m_pBuf + m_nPos;
		memset(pRet, 0, nGrowSize);
		int32 nLen = mysql_real_escape_string(con->m_Mysql, pRet, (char*)p, nSize);
		m_nPos += nLen;
		End();

		return *this;
	}

	//------------------------------------------------------------------------------
	// ���BLOB�ֶ�
	//------------------------------------------------------------------------------
	MyStream& MyStream::FillBlob(void* p, int32 nSize)
	{
		Grow(nSize);
		memcpy(m_pBuf + m_nPos, p, nSize);
		m_nPos += nSize;
		End();

		return *this;
	}

} 


