//��Name				:   MySqlStream.h
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	05/31/2009
//��LastModified		:	05/31/2009
//��Copyright (C)		:	
//��Writen  by			:   
//��Mode  by			:   
//��Brief				:	
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "StdAfx.h"
#include "Config.h"
#include "Database.h"

namespace Beton {

struct Connection;
class CBlobStreamAdapter;
//----------------------------------------------------------------------------------------------------
/**	MysqlStream�� - ���̰߳�ȫ��MysqlStream�࣬���ڴ洢ת����ת����sql���
*/
//----------------------------------------------------------------------------------------------------
class BETON_API MyStream
{
public:
	MyStream(INT nDefaultSize=1024);
	virtual ~MyStream();

private:
	MyStream(const MyStream&);
	MyStream& operator = (MyStream&);

public:
	//--------------------------------------------------------------------------------------------------
	// �ַ������������ֶε�������
	//--------------------------------------------------------------------------------------------------
	MyStream& FillString(const char* p, Connection* con=NULL);
	MyStream& FillString(const WCHAR* p, Connection* con=NULL);
	MyStream& FillBlob(const VOID* p, INT nSize, Connection* con);
	MyStream& FillBlob(VOID* p, INT nSize);	// ���ø÷����Ķ��������ݲ���Ҫת��

	//--------------------------------------------------------------------------------------------------
	// ������������
	//--------------------------------------------------------------------------------------------------
	BETON_INLINE MyStream& operator << (const UINT p);

	BETON_INLINE MyStream& operator << (const INT p);
	BETON_INLINE MyStream& operator << (const DWORD p);
	BETON_INLINE MyStream& operator << (const INT64 p);
	BETON_INLINE MyStream& operator << (const DOUBLE p);
	BETON_INLINE MyStream& operator << (const FLOAT p)		{ return operator << (static_cast<DOUBLE>(p)); }
	BETON_INLINE MyStream& operator << (const WORD p)		{ return operator << (static_cast<DWORD>(p));}
	BETON_INLINE MyStream& operator << (const BYTE p)		{ return operator << (static_cast<DWORD>(p));}
	BETON_INLINE MyStream& operator << (const char* p);
	BETON_INLINE MyStream& operator << (const WCHAR* p);
	BETON_INLINE MyStream& operator << (const CBlobStreamAdapter& blob );



public:
	//--------------------------------------------------------------------------------------------------
	// ����SQL������
	//--------------------------------------------------------------------------------------------------
	BETON_INLINE MyStream& SetCopyItem(const char* szTab1, const char* szSeclect, const char* szTab2)
	{

		Clear();
		return (*this).FillString("insert into ").FillString(szTab1).FillString(" select ").FillString(szSeclect).FillString(" from ").FillString(szTab2);
	}

	BETON_INLINE MyStream& SetSelect(const char* szTab, const char* szSeclect)
	{

		Clear();
		return (*this).FillString("select ").FillString(szSeclect).FillString(" from ").FillString(szTab);
	}

	BETON_INLINE MyStream& SetUpdate(const char* szTab)
	{
		Clear();
		return (*this).FillString("update ").FillString(szTab).FillString(" set ");
	}

	BETON_INLINE MyStream& SetInsert(const char* szTab)
	{
		Clear();
		return (*this).FillString("insert into ").FillString(szTab).FillString(" set ");
	}

	BETON_INLINE MyStream& SetInsert(const char* szTab, const char* szPostfix)
	{
		Clear();
		return (*this).FillString("insert into ").FillString(szTab).FillString(szPostfix).FillString(" set ");
	}

	BETON_INLINE MyStream& SetReplace(const char* szTab)
	{
		Clear();
		return (*this).FillString("replace into ").FillString(szTab).FillString(" set ");
	}

	BETON_INLINE MyStream& SetDelete(const char* szTab)
	{
		Clear();
		return (*this).FillString("delete from ").FillString(szTab);
	}

	BETON_INLINE MyStream& SetWhere()
	{
		return (*this).FillString(" where ");
	}

	BETON_INLINE MyStream& SetLimit(INT nNum, INT nBegin = 0)
	{
		(*this).FillString(" limit ");
		if( nBegin > 0 )
		{
			(*this) << nBegin;
			(*this).FillString(",");
		}
		return (*this) << nNum;
	}

public:
	BETON_INLINE VOID			Grow(INT nSize);
	BETON_INLINE BOOL			Seek(INT nPos);
	BETON_INLINE VOID			End()					{ m_pBuf[m_nPos] = '\0'; }
	BETON_INLINE const char*	GetBuf() const			{ return m_pBuf; }
	BETON_INLINE DWORD			GetBufLen() const		{ return m_nPos; }
	BETON_INLINE BOOL			IsEmpty() const			{ return m_nPos == 0; }
	BETON_INLINE VOID			Clear()					{ m_nPos = 0; End(); }

private:
	char*		m_pBuf;				// ��仺��
	INT			m_nBufLen;			// ����Ĵ�С
	INT			m_nPos;				// ��ǰ�������ڵ�λ��
	INT			m_nDefaultSize;		// ����Ĵ�С
};

class CBlobStreamAdapter
{
	const VOID*	m_pData;
	size_t		m_nSize;
	Connection* m_pCon;
public:
	CBlobStreamAdapter( const VOID* pBlobData, size_t nLength, Connection* pCon )
		: m_pData( pBlobData )
		, m_nSize( nLength )
		, m_pCon( pCon )
	{
	}

	const VOID* BlobData() const {
		return m_pData;
	}

	size_t Length() const {
		return m_nSize;
	}

	Connection* Con() const {
		return m_pCon;
	}

};

} // namespace Beton
