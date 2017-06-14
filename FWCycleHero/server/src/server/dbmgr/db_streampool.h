/*
---------------------------------------------------------------------------------------------------------------------------
			file name : db_streampool.h
			desc	  : 
			author    : ljp

			log		  : by ljp create 2017-06-13
---------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "db_stream.h"
#include "db_streamqueue.h"
#include "thread/threadmutex.hpp"







namespace KBEngine {

	class MyStream;
	class SafeStreamQueue;
	//----------------------------------------------------------------------------------------------------
	/**	StreamPool�� - Ϊ�ϲ��ṩMysqlStream�أ����ϲ���ȡʹ��
	1. Ԥ�ȷ���һ����С����Դ���粻��ɶ�̬���䣬�������࣬���ڲ���Ҫʱ�ͷŶ����ڴ�
	2. �̰߳�ȫ
	*/
	//-----------------------------------------------------------------------------------------------------
	class StreamPool
	{
	public:
		StreamPool(int32 nDefaultSize=1000);
		virtual ~StreamPool();

	private:
		StreamPool(const StreamPool&);
		StreamPool& operator = (const StreamPool&);

	public:
		inline MyStream*	AllocStream();
		inline void			FreeStream(MyStream* pStream);

		inline long			GetAvailableStreamNum() { return m_FreeQueue.Size(); }
		inline int32		GetAllStreamNum() { return m_nTotalNum; }

	private:
		inline VOID			RealAlloc(INT nNum);
		inline VOID			RealFree(INT nNum);
		inline VOID			RealFreeAll();

	private:
		thread::ThreadMutex	m_Mutex;
		SafeStreamQueue		m_FreeQueue;
		volatile int32		m_nDefaultSize;		// ������ʱ��Ĭ�ϴ�С
		volatile int32		m_nTotalNum;		// �ó�һ�������˶��ٸ�stream
	};

} 
