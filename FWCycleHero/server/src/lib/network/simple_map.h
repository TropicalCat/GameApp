//-----------------------------------------------------------------------------
//!\file simple_map.h
//!\Auth:
//!
//!\date 2004-10-27
//! last 2004-10-27
//!
//!\brief	�ṩ�򵥵�map����
//!
//!
//-----------------------------------------------------------------------------
#pragma once







namespace KBEngine {

//-----------------------------------------------------------------------------
// �ṩ�򵥵�map����
//-----------------------------------------------------------------------------
template<class KeyType, class ValueType> class TMap
{
public:
	typedef std::map<KeyType, ValueType>					map_type;
	typedef typename map_type::iterator						TMapIterator;
	typedef typename map_type::const_iterator				TMapCIterator;

public:
	//! ���Ԫ��
	void Add(KeyType key, ValueType value)
	{ m_map.insert(std::make_pair(key, value)); }
	
	//! ��ȡԪ��
	ValueType Peek(KeyType key)
	{
		std::map<KeyType, ValueType>::iterator it = m_map.find(key);
		if( it == m_map.end() )
			return ValueType(GT_INVALID);
		else
			return it->second;
	}

	ValueType Peek( KeyType key ) const
	{
		std::map<KeyType, ValueType>::const_iterator it = m_map.find(key);
		if( it == m_map.end() )
			return ValueType(GT_INVALID);
		else
			return it->second;
	}
	
	//! �ı�ָ��key��Ӧ��ֵ
	bool ChangeValue(KeyType key, ValueType new_value)
	{
		std::map<KeyType, ValueType>::iterator it = m_map.find(key);
		if( it == m_map.end() )
			return false;

		it->second = new_value;
		return true;
	}

	//! �ۼ�ָ��key��Ӧ��ֵ�����key�����ڣ���ֱ����ӣ�Ҫ��ValueType������operator+��operator=���أ�
	void ModifyValue(KeyType key, ValueType mod_value)
	{
		std::map<KeyType, ValueType>::iterator it = m_map.find(key);
		if( it == m_map.end() )
		{
			m_map.insert(std::make_pair(key, mod_value));
		}
		else
		{
			it->second = it->second + mod_value;
		}
	}

	//! ���ָ��Ԫ���Ƿ����
	bool IsExist(KeyType key) const
	{
		std::map<KeyType, ValueType>::const_iterator it = m_map.find(key);
		if( it == m_map.end() )
			return false;
		else
			return true;
	}

	//! ɾ��һ��ָ��Ԫ��
	bool Erase(KeyType key)
	{ 
		std::map<KeyType, ValueType>::iterator it = m_map.find(key);
		if( it == m_map.end() )
			return false;

        m_map.erase(it);
		return true;
	}

	//! �������Ԫ��
	void Clear() { m_map.clear(); }

	//! �õ�Ԫ�ظ���
	INT32	Size() const { return (INT32)m_map.size(); }

	bool Empty() { return m_map.empty(); }

	//! ���ڲ��ĵ�������ʼ����map�Ŀ�ʼ
	void ResetIterator()
	{ m_it = m_map.begin(); }

	void ResetIterator() const
	{
		m_const_it = m_map.begin();
	}

	// ! �õ�map��ͷ
	TMapIterator	Begin()			{ return m_map.begin(); }
	TMapCIterator	Begin() const	{ return m_map.begin(); }
	// ! �õ�map��β
	TMapIterator	End()			{ return m_map.end(); }
	TMapCIterator	End() const		{ return m_map.end(); }


	//! ȡ���ڲ��ĵ�����ָ���Ԫ�أ������Ƶ�����
	bool PeekNext(ValueType& value)
	{
		if( m_it == m_map.end() )
			return false;
		value = m_it->second;
		++m_it;
		return true;
	}

	//! ȡ��ָ��������ָ���Ԫ�أ������Ƹõ�����
	bool PeekNext(TMapIterator& it, ValueType& value)
	{
		if( it == m_map.end() )
			return false;
		value = it->second;
		++it;
		return true;
	}

	bool PeekNext(TMapCIterator& it, ValueType& value) const
	{
		if( it == m_map.end() )
			return false;
		value = it->second;
		++it;
		return true;
	}


	//! ȡ���ڲ��ĵ�����ָ���Ԫ�أ������Ƶ�����
	bool PeekNext(KeyType& key, ValueType& value)
	{
		if( m_it == m_map.end() )
			return false;
		key = m_it->first;
		value = m_it->second;
		++m_it;
		return true;
	}

	bool PeekNext(KeyType& key, const ValueType& value) const
	{
		if( m_const_it == m_map.end() )
			return false;
		key = m_const_it->first;
		value = m_const_it->second;
		++m_const_it;
		return true;
	}

	//! ȡ��ָ���ĵ�����ָ���Ԫ�أ������Ƶ�����
	bool PeekNext(TMapIterator& it, KeyType& key, ValueType& value)
	{
		if( it == m_map.end() )
			return false;
		key = it->first;
		value = it->second;
		++it;
		return true;
	}

	//! ��list���������ȡһ��Ԫ��
	bool RandPeek(KeyType& key, ValueType& value)
	{
		INT nSize = m_map.size();
		if( nSize <= 0 )
			return false;

		INT nRand = rand() % nSize;

		std::map<KeyType, ValueType>::iterator it = m_map.begin();
		for(INT n=0; n<nRand; n++)
			++it;

		key = it->first;
		value = it->second;
		return true;
	}


	//! ������key������һ������std::list
	void ExportAllKey(std::list<KeyType>& listDest)
	{
		std::map<KeyType, ValueType>::iterator it;
		for(it = m_map.begin(); it != m_map.end(); ++it)
			listDest.push_back(it->first);
	}
	
	//! ������value������һ������std::list
	void ExportAllValue(std::list<ValueType>& listDest)
	{
		std::map<KeyType, ValueType>::iterator it;
		for(it = m_map.begin(); it != m_map.end(); ++it)
			listDest.push_back(it->second);
	}


private:
	std::map<KeyType, ValueType>					m_map;
	typename std::map<KeyType, ValueType>::iterator m_it;
	typename std::map<KeyType, ValueType>::const_iterator m_const_it;
};


}
