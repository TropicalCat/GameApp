/*
---------------------------------------------------------------------------------------------------------------------------
			file name : db_streamqueue.h
			desc	  : 
			author    : ljp

			log		  : by ljp create 2017-06-13
---------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include "common/common.hpp"
#include "db_stream.h"
#include "thread/threadmutex.hpp"






namespace KBEngine {

	class MyStream;
	class Mutex;
	//----------------------------------------------------------------------------------------------------
	/**	SafeStream�� - ����MyStream����ָ�룬Ϊ��ʵʱ�����ṩ֧��
	1. �ⲿ���ݿ����в���Ҫ����������sql��䣬���ɷ���ö����У��ɱ���̲߳���
	2. Ԥ�ȷ����Mystream���������ʱ��������У�������ȡ��ʹ��
	*/
	//-----------------------------------------------------------------------------------------------------
	class SafeStreamQueue
	{
	public:
		SafeStreamQueue() : m_lNum(0) { m_hEvent = ::CreateEvent(NULL, FALSE, TRUE, NULL); }
		virtual ~SafeStreamQueue();

	private:
		SafeStreamQueue(const SafeStreamQueue&);
		SafeStreamQueue& operator = (const SafeStreamQueue&);

	public:
		inline MyStream*		Get();
		inline void				Add(MyStream* pStream);
		inline long				Size() const { return m_lNum; }

		inline HANDLE			GetEvent() { return m_hEvent; }

	private:
		thread::ThreadMutex		m_Mutex;
		HANDLE					m_hEvent;
		std::list<MyStream*>	m_listQueue;
		volatile LONG			m_lNum;
	};

	//---------------------------------------------------------------------------------------------------------
	// �ⲿ��ȡһ��stream
	//---------------------------------------------------------------------------------------------------------
	MyStream* SafeStreamQueue::Get()
	{
		if( m_lNum == 0 ) return NULL;

		m_Mutex.lockMutex();

		if( m_lNum == 0 )
		{
			m_Mutex.unlockMutex();
			return NULL;
		}
		MyStream* pStream = m_listQueue.front();
		m_listQueue.pop_front();
		InterlockedExchangeAdd((LPLONG)&m_lNum, -1);

		m_Mutex.unlockMutex();

		return pStream;
	}

	//-----------------------------------------------------------------------------------------------------------
	// �õ�һ��stream
	//-----------------------------------------------------------------------------------------------------------
	void SafeStreamQueue::Add(MyStream* pStream)
	{
		if( NULL == pStream ) return;

		m_Mutex.lockMutex();

		m_listQueue.push_back(pStream);
		InterlockedExchangeAdd((LPLONG)&m_lNum, 1);

		if( m_lNum == 1 )
			::SetEvent(m_hEvent);	// �����¼�

		m_Mutex.unlockMutex();
	}

}