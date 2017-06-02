//-----------------------------------------------------------------------------
//!\file simple_list.h
//!\Auth:
//!
//!\date 2005-3-2
//! last 2005-3-2
//!
//!\brief	�ṩ�򵥵�list����
//!			
//!
//-----------------------------------------------------------------------------
#pragma once








namespace KBEngine {

	//-----------------------------------------------------------------------------
	// ����� std::list,�������ڲ�Ԫ�ؼ���
	//-----------------------------------------------------------------------------
	template<typename Type> class TList
	{
	public:
		typedef typename std::list<Type>::iterator TListIterator;

	public:
		// ���Ԫ�ص�����β
		void PushBack(Type val)
		{
			m_list.push_back(val);
			++m_nItemNum;
		}

		// �Ӷ���ͷȡԪ��
		Type PopFront()
		{
			Type val;
			if( m_nItemNum <= 0 )
				return Type(GT_INVALID);

			val = m_list.front();
			m_list.pop_front();
			m_nItemNum--;
			return val;
		}

		// ���Ԫ�ص�����ͷ
		void PushFront(Type val)
		{
			m_list.push_front(val);
			++m_nItemNum;
		}

		// �õ���һ��Ԫ�ص�ֵ��������ȡ����
		Type Front()
		{
			if( m_nItemNum <= 0 )
				return Type(GT_INVALID);

			return m_list.front();
		}

		// ɾ��ָ��Ԫ��
		bool Erase(Type& val)
		{
			std::list<Type>::iterator it;
			for(it=m_list.begin(); it!=m_list.end(); ++it)
			{
				if( val == *it )
				{
					m_list.erase(it);
					--m_nItemNum;	// ��Ҫ����nItemNum,���Բ���ֱ����list::remove
					return true;
				}
			}
			return false;
		}

		// ���ָ��Ԫ���Ƿ����
		bool IsExist( const Type& val) const
		{
			std::list<Type>::const_iterator it;
			for(it=m_list.begin(); it!=m_list.end(); ++it)
			{
				if( val == *it )
					return true;
			}
			return false;
		}

		// �������Ԫ��
		void Clear()
		{
			m_list.clear();
			m_nItemNum=0;
		}

		// �õ�Ԫ����Ŀ,std::list.size()�����ܱ�֤�̰߳�ȫ,
		// ���������Լ�����һ�ݸ�������
		INT32	Size()	{ return m_nItemNum;	}
		bool	Empty() { return (0 == m_nItemNum); }


		//! ��list���������һ��Ԫ��
		bool RandPeek(Type& value, BOOL bPop=FALSE)
		{
			if( m_list.empty() )
				return false;

			INT nRand = rand() % m_nItemNum;
			std::list<Type>::iterator it = m_list.begin();
			for(INT n=0; n<nRand; n++)
				++it;
       
			value = *it;
			if( bPop )
			{
				m_list.erase(it);
				m_nItemNum--;
			}
			
			return true;
		}


		//! ȡ���ڲ��ĵ�����ָ���Ԫ�أ������Ƶ�����
		bool PeekNext(Type& value)
		{
			if( m_it == m_list.end() )
				return false;
			value = *m_it;
			++m_it;
			return true;
		}

		//! ȡ���ⲿ�ĵ�����ָ���Ԫ�أ������Ƶ�����
		bool PeekNext(TListIterator& it, Type& value)
		{
			if( it == m_list.end() )
				return false;
			value = *it;
			++it;
			return true;
		}

		//! ���ڲ��ĵ�������ʼ����map�Ŀ�ʼ
		void ResetIterator()
		{ m_it = m_list.begin();	}

		//! �õ�ָ��list��ʼλ�õĵ�����
		TListIterator Begin()
		{
			return m_list.begin();
		}

		std::list<Type>& GetList() { return m_list; }


		void operator=(std::list<Type>& list) { m_list = list;	}
		void operator=(TList<Type>& list) { m_list = list.GetList(); m_nItemNum = m_list.size(); m_it = m_list.end(); }


		TList():m_nItemNum(0) {}
		TList(std::list<Type>& list){ m_list = list; }
		~TList(){}

	private:
		std::list<Type>						m_list;
		INT32								m_nItemNum;
		typename std::list<Type>::iterator	m_it;
	};
}