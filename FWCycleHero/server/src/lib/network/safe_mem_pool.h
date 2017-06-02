//-----------------------------------------------------------------------------
// File: safe_mem_pool
// Desc: game tool mem pool 2.0
// Auth:
// Date: 2009-1-8	
// Last: 2009-3-18
//-----------------------------------------------------------------------------
#pragma once
#include "common/common.hpp"





namespace KBEngine {
//-----------------------------------------------------------------------------
// �ڴ��(ע�⣺�ڴ�صĴ�С��ʾ:�ڴ�ص�ǰ�����ڴ�Ĵ�С)
// ��ʼ��ʱ��
// 1 �ⲿ�趨�ڴ�ص���������С
// 2 �ڴ�ز����κ��ڴ�Ԥ����
//
// �ⲿ�����ڴ�ʱ,�����жϣ�
// 1 ����ڴ���ж�Ӧ�ߴ�Ŀ��п�,ʹ�ÿ��п鷵��
// 2 û�п��п�ʱ,ֱ�������ڴ沢���ڴ�ǰ����tagMemItem,Ȼ�󷵻�
//
// �ⲿ�ͷ��ڴ�ʱ,�����ж�:
// 1 ����ͷ��ڴ���С>�ڴ������С,ֱ���ͷŵ�ϵͳ�ڴ�
// 2 �����ǰ�ڴ�ش�С+�ͷ��ڴ���С<�ڴ������С,ֱ�ӷ����ڴ��
// 3 ���������ռ��������ռ������¼������ĵ�2���������ͨ��������е�4��
// 4 ����ֱ���ͷ���ϵͳ�ڴ�
//-----------------------------------------------------------------------------
class SafeMemPool
{
public:
	 void*					Alloc(UINT32 dwBytes);
	 void					Free(void* pMem);
	 void*					TryAlloc(UINT32 dwBytes);	// ���Խ�����������
	 bool					TryFree(void* pMem);		// ���Խ�����������
	 void					SetMaxSize(UINT32 dwSize) { m_dwMaxSize = dwSize; }
	 UINT32					GetSize() { return m_dwCurrentSize; }
	 UINT32					GetMalloc() { return m_dwMalloc; }
	 UINT32					GetGC() { return m_dwGCTimes; }

	 SafeMemPool(UINT32 dwMaxPoolSize = 16 * 1024 * 1024);
	~SafeMemPool();

private:
	struct tagNode	// �ڴ��ͷ����
	{
		tagNode*	pNext;
		tagNode*	pPrev;
		INT			nIndex;
		UINT32		dwSize;
		UINT32		dwUseTime;
		UINT32		pMem[1];	// ʵ���ڴ�ռ�
	};

	struct
	{
		tagNode*	pFirst;
		tagNode*	pLast;
	} m_Pool[16];

	UINT32			m_dwMaxSize;		// �ⲿ�趨�������������ڴ�
	UINT32			m_dwMalloc;			// ͳ���ã�ʵ��Malloc����
	UINT32			m_dwGCTimes;		// ͳ���ã�ʵ�������ռ�����

	UINT32 volatile m_dwCurrentSize;	// �ڴ���п����ڴ�����
	LONG volatile 	m_lLock;

	void Lock()		{ while (InterlockedCompareExchange((LPLONG)&m_lLock, 1, 0) != 0) Sleep(0); }
	void Unlock()	{ InterlockedExchange((LPLONG)(&m_lLock), 0); }
	bool TryLock()	{ return InterlockedCompareExchange((LPLONG)(&m_lLock), 1, 0) == 0;	}

	// �����ռ�
	void			GarbageCollect(UINT32 dwExpectSize, UINT32 dwUseTime);
	// ������ƥ��Ĵ�С
	INT32				SizeToIndex(UINT32 dwSize, UINT32& dwRealSize);
};
} 
