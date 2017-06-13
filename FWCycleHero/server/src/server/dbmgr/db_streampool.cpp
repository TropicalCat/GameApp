//��Name				:   StreamPool.cpp
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	05/31/2009
//��LastModified		:	05/31/2009
//��Copyright (C)		:	
//��Writen  by			:   
//��Mode  by			:   
//////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Config.h"
#include "MysqlStream.h"
#include "SafeStreamQueue.h"

namespace Beton
{
//-----------------------------------------------------------------------------------------------------------
// ���캯����������
//-----------------------------------------------------------------------------------------------------------
StreamPool::StreamPool(INT nDefaultSize)
	: m_nDefaultSize(nDefaultSize), m_nTotalNum(0)
{
	//ASSERT( m_nDefaultSize > 0 );

	RealAlloc(m_nDefaultSize);
}

StreamPool::~StreamPool()
{
	RealFreeAll();
}

//------------------------------------------------------------------------------------------------------------
// ��ʵ�����ڴ�
//------------------------------------------------------------------------------------------------------------
VOID StreamPool::RealAlloc(INT nNum)
{
	if( nNum <= 0 ) return;

	m_Mutex.Acquire();
	for(INT n = 0; n < nNum; n++)
	{
		MyStream* pStream = new MyStream();
		if( NULL == pStream ) break;

		m_FreeQueue.Add(pStream);
		InterlockedExchangeAdd((LPLONG)&m_nTotalNum, 1);
	}
	m_Mutex.Release();
}

//-------------------------------------------------------------------------------------------------------------
// ��ʵ�ͷ��ڴ�
//-------------------------------------------------------------------------------------------------------------
VOID StreamPool::RealFree(INT nNum)
{
	if( nNum <= 0 ) return;

	m_Mutex.Acquire();
	for(INT n = 0; n < nNum; n++)
	{
		MyStream* pStream = m_FreeQueue.Get();
		if( pStream )
		{
			SAFE_DEL(pStream);
			InterlockedExchangeAdd((LPLONG)&m_nTotalNum, -1);
		}
	}
	m_Mutex.Release();
}

//-------------------------------------------------------------------------------------------------------------
// �ͷ�����������ڴ�
//-------------------------------------------------------------------------------------------------------------
VOID StreamPool::RealFreeAll()
{
	while( m_nTotalNum != 0 )
	{
		MyStream* pStream = m_FreeQueue.Get();
		if( NULL == pStream ) continue;

		SAFE_DEL(pStream);
		InterlockedExchangeAdd((LPLONG)&m_nTotalNum, -1);
	}
}

//-------------------------------------------------------------------------------------------------------------
// �ӳ���ȡ������ȡ������������ص�����
//--------------------------------------------------------------------------------------------------------------
MyStream* StreamPool::AllocStream()
{
	MyStream* pStream = m_FreeQueue.Get();

	while( NULL == pStream )
	{
		RealAlloc(m_nDefaultSize);
		pStream = m_FreeQueue.Get();
	}

	return pStream;
}

//---------------------------------------------------------------------------------------------------------------
// �黹������
//----------------------------------------------------------------------------------------------------------------
VOID StreamPool::FreeStream(MyStream* pStream)
{
	if( NULL == pStream ) return;

	m_FreeQueue.Add(pStream);

	// �����˹����ڴ棬���ͷ�һ����
	INT nSize = m_FreeQueue.Size();
	if( nSize >= 8 * m_nDefaultSize )
	{
		RealFree(nSize/4);
	}
}

} // namespace Beton
