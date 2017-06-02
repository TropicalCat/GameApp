//-----------------------------------------------------------------------------
//!\file x_list.h
//!\Auth:
//!
//!\date 2004-07-07
//! last 2009-06-11
//!
//!\brief	��std::list��װ���̰߳�ȫ
//!
//-----------------------------------------------------------------------------
#pragma once






namespace KBEngine 
{

	//-----------------------------------------------------------------------------
	// ��std::list��װ���̰߳�ȫ
	//-----------------------------------------------------------------------------
	template<typename Type> class XList
	{
	public:
		inline void PushBack(Type val)	// ���Ԫ�ص�����β
		{
			Lock();
			m_list.push_back(val);
			++m_nItemNum;
			Unlock();
		}

		inline Type PopFront()	// �Ӷ���ͷȡԪ��
		{
			if( m_nItemNum <= 0 )
				return Type(GT_INVALID);

			Lock();
			if( m_nItemNum <= 0 )
			{
				Unlock();
				return Type(GT_INVALID);
			}
			Type val = m_list.front();
			m_list.pop_front();
			m_nItemNum--;
			Unlock();
			return val;
		}
	
		inline bool Erase(Type& val)	// ɾ��ָ��Ԫ��
		{
			std::list<Type>::iterator it;
			Lock();
			for(it=m_list.begin(); it!=m_list.end(); ++it)
			{
				if( val == *it )
				{
					m_list.erase(it);
					--m_nItemNum;
					Unlock();
					return true;
				}
			}
			Unlock();
			return false;
		}

		inline bool IsExist(Type& val)	// ���ָ��Ԫ���Ƿ����
		{
			Lock();
			std::list<Type>::iterator it;
			for(it=m_list.begin(); it!=m_list.end(); ++it)
			{
				if( val == *it )
				{
					Unlock();
					return true
				}
			}
			Unlock();
			return false;
		}

		inline void Clear()	// �������Ԫ��
		{
			Lock();
			m_list.clear();
			m_nItemNum=0;
			Unlock();
		}

		// �õ�Ԫ����Ŀ,std::list.size()�����ܱ�֤�̰߳�ȫ,���������Լ�����һ�ݸ�������
		inline INT32	Size() { return m_nItemNum; }

		//! ȡ���ڲ��ĵ�����ָ���Ԫ�أ������Ƶ�����,ע��Ҫlock�����ʹ��
		inline bool _Peek(Type& value)
		{
			if( m_it == m_list.end() )
				return FALSE;
			value = *m_it;
			return true;
		}

		//! ���ڲ��ĵ�������ʼ����map�Ŀ�ʼ,ע��Ҫlock�����ʹ��
		inline void _ResetIterator(){ m_it = m_list.begin(); }
		inline void _AddIterator(){ ++m_it; }
		inline void _EraseCurrent(){ m_list.erase(m_it); }

		inline XList() :m_nItemNum(0), m_lLock(0) {}
		inline ~XList(){ }//ASSERT( 0 == m_nItemNum); }
		inline void	Lock() { while (InterlockedCompareExchange((LPLONG)&m_lLock, 1, 0) != 0) Sleep(0); }
		inline void	Unlock() { InterlockedExchange((LPLONG)(&m_lLock), 0); }

	private:
		std::list<Type>						m_list;
		typename std::list<Type>::iterator	m_it;
	
		INT32	volatile	m_nItemNum;
		LONG	volatile	m_lLock;
	};

}