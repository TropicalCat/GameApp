//-----------------------------------------------------------------------------
//!\file safe_map.h
//!\Auth:
//!
//!\date 2004-07-09
//! last 2004-08-16
//!
//!\brief	�ṩ���������̰߳�ȫ��map����
//!			
//!
//-----------------------------------------------------------------------------
#pragma once







namespace KBEngine {

//-----------------------------------------------------------------------------
// �ṩ���������̰߳�ȫ��map����
//-----------------------------------------------------------------------------
template<typename KeyType, typename ValueType> class TSafeMap
{
public:
	//! ���Ԫ��
	void Add(KeyType key, ValueType value)
	{
		EnterCriticalSection(&m_Lock);
		m_map.insert(std::pair<KeyType, ValueType>(key, value));
		LeaveCriticalSection(&m_Lock);
	}

	//! ��ȡԪ��
	ValueType Peek(KeyType key)
	{
		ValueType temp;
		std::map<KeyType, ValueType>::iterator it;
		EnterCriticalSection(&m_Lock);
		it = m_map.find(key);
		if( it == m_map.end() )
			temp = ValueType(GT_INVALID);
		else
			temp = it->second;
		LeaveCriticalSection(&m_Lock);
		return temp;
	}

	//! �ı�ָ��key��Ӧ��ֵ
	bool ChangeValue(KeyType key, ValueType new_value)
	{
		std::map<KeyType, ValueType>::iterator it;
		EnterCriticalSection(&m_Lock);
		it = m_map.find(key);
		
		if( it == m_map.end() )
		{
			LeaveCriticalSection(&m_Lock);
			return FALSE;
		}
		else
		{
			it->second = new_value;
			LeaveCriticalSection(&m_Lock);
			return TRUE;
		}
	}

	//! ���ָ��Ԫ���Ƿ����
	bool IsExist(KeyType key)
	{
		BOOL bResult = FALSE;
		std::map<KeyType, ValueType>::iterator it;
		EnterCriticalSection(&m_Lock);
		it = m_map.find(key);
		
		if( it == m_map.end() )
			bResult = FALSE;
		else
			bResult = TRUE;
		LeaveCriticalSection(&m_Lock);

		return bResult;
	}


	//! ɾ��ָ��Ԫ��
	bool Erase(KeyType key)
	{
		bool bResult = false;
		std::map<KeyType, ValueType>::iterator it;
		
		EnterCriticalSection(&m_Lock);
		it = m_map.find(key);
		if( it == m_map.end() )
		{
			bResult = false;
		}
		else
		{
			m_map.erase(it);
			bResult = true;
		}
		LeaveCriticalSection(&m_Lock);
		return bResult;
	}


	//! �������Ԫ��
	void Clear()
	{
		EnterCriticalSection(&m_Lock);
		m_map.clear();
		LeaveCriticalSection(&m_Lock);
	}

	//! �õ�Ԫ�ظ���
	INT32	Size() { return (INT32)m_map.size(); }


	//! ������key������һ������std::list,�����ص����ĸ���
	INT32 ExportAllKey(std::list<KeyType>& listDest)
	{
		INT32 n=0;
		EnterCriticalSection(&m_Lock);
		std::map<KeyType, ValueType>::iterator it;
		for(it = m_map.begin(); it != m_map.end(); ++it, ++n)
			listDest.push_back(it->first);
		LeaveCriticalSection(&m_Lock);
		return n;
	}

	//! ������value������һ������std::list,�����ص����ĸ���
	INT32 ExportAllValue(std::list<ValueType>& listDest)
	{
		INT32 n=0;
		EnterCriticalSection(&m_Lock);
		std::map<KeyType, ValueType>::iterator it;
		for(it = m_map.begin(); it != m_map.end(); ++it, ++n)
			listDest.push_back(it->second);
		LeaveCriticalSection(&m_Lock);
		return n;
	}

	void Lock() { EnterCriticalSection(&m_Lock); }
	void Unlock() { LeaveCriticalSection(&m_Lock); }


	TSafeMap() { InitializeCriticalSection(&m_Lock); }
	~TSafeMap()	{ DeleteCriticalSection(&m_Lock); }


private:
	std::map<KeyType, ValueType>			m_map;
	CRITICAL_SECTION						m_Lock;
};



}