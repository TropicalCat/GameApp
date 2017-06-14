/*
---------------------------------------------------------------------------------------------------------------------------
			file name : db_streampool.h
			desc	  : 
			author    : ljp

			log		  : by ljp create 2017-06-13
---------------------------------------------------------------------------------------------------------------------------
*/
#include "db_stream.h"
#include "db_streampool.h"
#include "db_streamqueue.h"





namespace KBEngine
{
	//-----------------------------------------------------------------------------------------------------------
	// ���캯����������
	//-----------------------------------------------------------------------------------------------------------
	StreamPool::StreamPool(int32 nDefaultSize)
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
	void StreamPool::RealAlloc(int32 nNum)
	{
		if( nNum <= 0 ) return;

		m_Mutex.lockMutex();
		for (int32 n = 0; n < nNum; n++)
		{
			MyStream* pStream = new MyStream();
			if( NULL == pStream ) break;

			m_FreeQueue.Add(pStream);
			InterlockedExchangeAdd((LPLONG)&m_nTotalNum, 1);
		}
		m_Mutex.unlockMutex();
	}

	//-------------------------------------------------------------------------------------------------------------
	// ��ʵ�ͷ��ڴ�
	//-------------------------------------------------------------------------------------------------------------
	void StreamPool::RealFree(int32 nNum)
	{
		if( nNum <= 0 ) return;

		m_Mutex.lockMutex();
		for (int32 n = 0; n < nNum; n++)
		{
			MyStream* pStream = m_FreeQueue.Get();
			if( pStream )
			{
				SAFE_DEL(pStream);
				InterlockedExchangeAdd((LPLONG)&m_nTotalNum, -1);
			}
		}
		m_Mutex.unlockMutex();
	}

	//-------------------------------------------------------------------------------------------------------------
	// �ͷ�����������ڴ�
	//-------------------------------------------------------------------------------------------------------------
	void StreamPool::RealFreeAll()
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
	void StreamPool::FreeStream(MyStream* pStream)
	{
		if( NULL == pStream ) return;

		m_FreeQueue.Add(pStream);

		// �����˹����ڴ棬���ͷ�һ����
		int32 nSize = m_FreeQueue.Size();
		if( nSize >= 8 * m_nDefaultSize )
		{
			RealFree(nSize/4);
		}
	}

} // namespace Beton
