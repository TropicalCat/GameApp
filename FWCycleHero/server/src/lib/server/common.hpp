/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KBE_SERVER_COMMON_HPP
#define KBE_SERVER_COMMON_HPP

// common include
#include "common/timer.hpp"
#include "common/common.hpp"
#include "server/glw_errorcode.hpp"
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif

namespace KBEngine 
{ 

	
	/**
	����ת��Ϊtick
	@lowerBound: ���ٲ�����Ntick
	*/
	int32 secondsToTicks(float seconds, int lowerBound);

	/**
		����Ϊ��λ��ʱ��ת��Ϊÿ�����ĵ�stamps
	*/
	inline uint64 secondsToStamps(float seconds)
	{
		return (uint64)(seconds * stampsPerSecondD());
	}

	/*
	 �˺ź�������󳤶�
	*/
	#define ACCOUNT_NAME_MAX_LENGTH 64
	#define ACCOUNT_PASSWD_MAX_LENGTH 64

	// ��¼ע��ʱ��������Ϣ��󳤶�
	#define ACCOUNT_DATA_MAX_LENGTH 1024

	// �����������κ�ֻ��һ�κ��Զ�����Ϊ������ѡ��
	#define KBE_NEXT_ONLY 2

	/** c/c++�������ת����KBEDataTypeID */
	uint16 datatype2id(std::string datatype);

}

#endif // KBE_SERVER_COMMON_HPP
