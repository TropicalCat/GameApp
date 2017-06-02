//-----------------------------------------------------------------------------
//!\file safe_list.h
//!\Auth:
//!
//!\date 2004-07-07
//! last 2004-07-12
//!
//!\brief	��std::list��װ���̰߳�ȫ
//!
//-----------------------------------------------------------------------------
#pragma once








namespace KBEngine {

//-----------------------------------------------------------------------------
// ��std::list��װ���̰߳�ȫ
//-----------------------------------------------------------------------------
template<typename Type> class TSafeList
{
public:
	// ���Ԫ�ص�����β
	void PushBack(Type val)
	{
		EnterCriticalSection(&m_Lock);
		m_list.push_back(val);
		++m_nItemNum;
		LeaveCriticalSection(&m_Lock);
	}

	// ���Ԫ�ص������ײ�
	void PushFront(Type val)
	{
		EnterCriticalSection(&m_Lock);
		m_list.push_front(val);
		++m_nItemNum;
		LeaveCriticalSection(&m_Lock);
	}

	// �Ӷ���ͷȡԪ��
	Type PopFront()
	{
		Type val;
		if( m_nItemNum <= 0 )
			return Type(GT_INVALID);

		EnterCriticalSection(&m_Lock);
		if( m_nItemNum <= 0 )
		{
			LeaveCriticalSection(&m_Lock);
			return Type(GT_INVALID);
		}

		val = m_list.front();
		m_list.pop_front();
		m_nItemNum--;
		
		LeaveCriticalSection(&m_Lock);
		return val;
	}

	// ɾ��ָ��Ԫ��
	bool Erase(Type& val)
	{
		std::list<Type>::iterator it;
		EnterCriticalSection(&m_Lock);
		for(it=m_list.begin(); it!=m_list.end(); ++it)
		{
			if( val == *it )
			{
				m_list.erase(it);
				--m_nItemNum;
				LeaveCriticalSection(&m_Lock);
				return true;
			}
		}
		LeaveCriticalSection(&m_Lock);
		return false;
	}


	// ���ָ��Ԫ���Ƿ����
	bool IsExist(Type& val)
	{
		bool bFound = false;
		EnterCriticalSection(&m_Lock);
		std::list<Type>::iterator it;
		for(it=m_list.begin(); it!=m_list.end(); ++it)
		{
			if( val == *it )
			{
				bFound = true;
				break;
			}
		}
		LeaveCriticalSection(&m_Lock);
		return bFound;
	}



	// �������Ԫ��
	void Clear()
	{
		EnterCriticalSection(&m_Lock);
		m_list.clear();
		m_nItemNum=0;
		LeaveCriticalSection(&m_Lock);
	}

	// �õ�Ԫ����Ŀ,std::list.size()�����ܱ�֤�̰߳�ȫ,
	// ���������Լ�����һ�ݸ�������
	INT32	Size() { return m_nItemNum;	}

	// ��ȫ�Ľ����ݵ���һ����ͨstd::list,�������ݸ���
	INT32 Export(std::list<Type>& listDest)
	{
		INT32 n=0;
		EnterCriticalSection(&m_Lock);
		std::list<Type>::iterator it;
		for(it=m_list.begin(); it!=m_list.end(); ++it, ++n)
			listDest.push_back(*it);
            
		LeaveCriticalSection(&m_Lock);
		return n;
	}


	TSafeList():m_nItemNum(0) { InitializeCriticalSection(&m_Lock); }
	~TSafeList(){ DeleteCriticalSection(&m_Lock); }

private:
	std::list<Type>		m_list;
	INT32				m_nItemNum;
	CRITICAL_SECTION	m_Lock;
};



}