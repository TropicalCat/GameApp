//��Name				:   SafeStreamQueue.cpp
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	05/31/2009
//��LastModified		:	05/31/2009
//��Copyright (C)		:	
//��Writen  by			:   
//��Mode  by			:   
//��Brief				:	
//////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "Config.h"
#include "MysqlStream.h"
#include "SafeStreamQueue.h"

namespace Beton
{
//--------------------------------------------------------------------------------------------------------
// ��������
//--------------------------------------------------------------------------------------------------------
SafeStreamQueue::~SafeStreamQueue()
{
	// ASSERT( 0 == m_lNum );
	if( m_hEvent )
		::CloseHandle(m_hEvent);
}

} // namespace Beton