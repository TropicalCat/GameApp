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
#ifndef KBE_COMMON_HPP
#define KBE_COMMON_HPP
#include "common/platform.hpp"
#include "common/singleton.hpp"
#include "common/kbeversion.hpp"
#include "common/kbemalloc.hpp"
#include "common/stringconv.hpp"
#include "common/format.hpp"

namespace KBEngine{
/** ��ȫ���ͷ�һ��ָ���ڴ� */
#define SAFE_RELEASE(i)										\
	if (i)													\
		{													\
			delete i;										\
			i = NULL;										\
		}

/** ��ȫ���ͷ�һ��ָ�������ڴ� */
#define SAFE_RELEASE_ARRAY(i)								\
	if (i)													\
		{													\
			delete[] i;										\
			i = NULL;										\
		}

#ifdef CODE_INLINE
    #define INLINE    inline
#else
    #define INLINE
#endif


#ifndef SAFE_DEL
#define SAFE_DEL(p)				{ if(p) { delete(p);		(p) = NULL; } }
#endif
#ifndef SAFE_DEL_ARRAY
#define SAFE_DEL_ARRAY(p)		{ if(p) { delete[](p);		(p) = NULL; } }
#endif




/** �˺ŵ���� */
enum ACCOUNT_TYPE
{
	ACCOUNT_TYPE_NORMAL = 1,	// ��ͨ�˺�
	ACCOUNT_TYPE_MAIL = 2,		// email�˺�(�輤��)
	ACCOUNT_TYPE_SMART = 3		// ����ʶ��
};

enum ACCOUNT_FLAGS
{
	ACCOUNT_FLAG_NORMAL = 0x00000000,
	ACCOUNT_FLAG_LOCK = 0x000000001,
	ACCOUNT_FLAG_NOT_ACTIVATED = 0x000000002
};

/** entity��mailbox��� */
enum ENTITY_MAILBOX_TYPE
{
	MAILBOX_TYPE_CELL												= 0,
	MAILBOX_TYPE_BASE												= 1,
	MAILBOX_TYPE_CLIENT												= 2,
	MAILBOX_TYPE_CELL_VIA_BASE										= 3,
	MAILBOX_TYPE_BASE_VIA_CELL										= 4,
	MAILBOX_TYPE_CLIENT_VIA_CELL									= 5,
	MAILBOX_TYPE_CLIENT_VIA_BASE									= 6,
};

/** mailbox�����Ի�Ϊ�ַ������� �ϸ��ENTITY_MAILBOX_TYPE����ƥ�� */
const char ENTITY_MAILBOX_TYPE_TO_NAME_TABLE[][8] = 
{
	"cell",
	"base",
	"client",
	"cell",
	"base",
	"client",
	"client",
};

/** ����������������� */
enum COMPONENT_TYPE
{
	UNKNOWN_COMPONENT_TYPE	= 0,
	DBMGR_TYPE				= 1,
	LOGINAPP_TYPE			= 2,
	BASEAPPMGR_TYPE			= 3,
	CELLAPPMGR_TYPE			= 4,
	CELLAPP_TYPE			= 5,
	BASEAPP_TYPE			= 6,
	CLIENT_TYPE				= 7,
	MACHINE_TYPE			= 8,
	CONSOLE_TYPE			= 9,
	MESSAGELOG_TYPE			= 10,
	BOTS_TYPE				= 11,
	WATCHER_TYPE			= 12,
	BILLING_TYPE			= 13,
	COMPONENT_END_TYPE		= 14,
};



/** ������������������ */
const char COMPONENT_NAME[][255] = {
	"unknown",
	"dbmgr",
	"loginapp",
	"baseappmgr",
	"cellappmgr",
	"cellapp",
	"baseapp",
	"client",
	"kbmachine",
	"console",
	"messagelog",
	"bots",
	"billing",
};

const char COMPONENT_NAME_1[][255] = {
	"unknown    ",
	"dbmgr      ",
	"loginapp   ",
	"baseappmgr ",
	"cellappmgr ",
	"cellapp    ",
	"baseapp    ",
	"client     ",
	"kbmachine  ",
	"console    ",
	"messagelog ",
	"bots",
	"billing",
};

inline const char* COMPONENT_NAME_EX(COMPONENT_TYPE CTYPE)
{									
	if(CTYPE < 0 || CTYPE >= COMPONENT_END_TYPE)
	{
		return COMPONENT_NAME[UNKNOWN_COMPONENT_TYPE];
	}

	return COMPONENT_NAME[CTYPE];
}

inline const char* COMPONENT_NAME_EX_1(COMPONENT_TYPE CTYPE)
{									
	if(CTYPE < 0 || CTYPE >= COMPONENT_END_TYPE)
	{
		return COMPONENT_NAME_1[UNKNOWN_COMPONENT_TYPE];
	}

	return COMPONENT_NAME_1[CTYPE];
}

inline COMPONENT_TYPE ComponentName2ComponentType(const char* name)
{
	for(int i=0; i<(int)COMPONENT_END_TYPE; i++)
	{
		if(kbe_stricmp(COMPONENT_NAME[i], name) == 0)
			return (COMPONENT_TYPE)i;
	}

	return UNKNOWN_COMPONENT_TYPE;
}

// ���е�����б�
const COMPONENT_TYPE ALL_COMPONENT_TYPES[] = {BASEAPPMGR_TYPE, CELLAPPMGR_TYPE, DBMGR_TYPE, CELLAPP_TYPE, 
						BASEAPP_TYPE, LOGINAPP_TYPE, MACHINE_TYPE, CONSOLE_TYPE, MESSAGELOG_TYPE, 
						 BILLING_TYPE, BOTS_TYPE, UNKNOWN_COMPONENT_TYPE};

// ���еĺ������б�
const COMPONENT_TYPE ALL_SERVER_COMPONENT_TYPES[] = {BASEAPPMGR_TYPE, CELLAPPMGR_TYPE, DBMGR_TYPE, CELLAPP_TYPE, 
						BASEAPP_TYPE, LOGINAPP_TYPE, MACHINE_TYPE, MESSAGELOG_TYPE, 
						BILLING_TYPE, BOTS_TYPE, UNKNOWN_COMPONENT_TYPE};

// ���еĺ������б�
const COMPONENT_TYPE ALL_GAME_SERVER_COMPONENT_TYPES[] = {BASEAPPMGR_TYPE, CELLAPPMGR_TYPE, DBMGR_TYPE, CELLAPP_TYPE, 
						BASEAPP_TYPE, LOGINAPP_TYPE, BILLING_TYPE, UNKNOWN_COMPONENT_TYPE};

// ���еĸ��������
const COMPONENT_TYPE ALL_HELPER_COMPONENT_TYPE[] = {MESSAGELOG_TYPE, UNKNOWN_COMPONENT_TYPE};

// �����Ƿ���һ����Ч�����
#define VALID_COMPONENT(C_TYPE) ((C_TYPE) > 0 && (C_TYPE) < COMPONENT_END_TYPE)

/** ����Ƿ�Ϊһ����Ϸ����������� */
inline bool isGameServerComponentType(COMPONENT_TYPE componentType)
{
	int i = 0;
	while(true)
	{
		COMPONENT_TYPE t = ALL_GAME_SERVER_COMPONENT_TYPES[i++];
		if(t == UNKNOWN_COMPONENT_TYPE)
			break;

		if(t == componentType)
			return true;
	}

	return false;
}

// ǰ��Ӧ�õ����, All client type
enum COMPONENT_CLIENT_TYPE
{
	UNKNOWN_CLIENT_COMPONENT_TYPE	= 0,

	// �ƶ��࣬�ֻ���ƽ�����
	// Mobile, Phone, Pad(Allowing does not contain Python-scripts and entitydefs analysis, can be imported protocol from network)
	CLIENT_TYPE_MOBILE				= 1,

	// ������Windows/Linux/MacӦ�ó���(����python�ű���entitydefs��������entitydefs��MD5��ԭ����)
	// Windows/Linux/Mac Application program (Contains the Python-scripts, entitydefs parsing and check entitydefs-MD5, Native)
	CLIENT_TYPE_PC					= 2,	

	// ������Python�ű���entitydefsЭ���ʹ�����絼��
	// Web, HTML5, Flash
	CLIENT_TYPE_BROWSER				= 3,	

	// ����Python�ű���entitydefs��������entitydefs��MD5��ԭ����
	// bots	 (Contains the Python-scripts, entitydefs parsing and check entitydefs-MD5, Native)
	CLIENT_TYPE_BOTS				= 4,	

	// �����, �ɲ�����python�ű���entitydefsЭ���ʹ�����絼��
	// Mini-Client(Allowing does not contain Python-scripts and entitydefs analysis, can be imported protocol from network)
	CLIENT_TYPE_MINI				= 5,	

	// End
	CLIENT_TYPE_END					= 6		
};

/** ����ǰ��Ӧ�õ�������� */
const char COMPONENT_CLIENT_NAME[][255] = {
	"UNKNOWN_CLIENT_COMPONENT_TYPE",
	"CLIENT_TYPE_MOBILE",
	"CLIENT_TYPE_PC",
	"CLIENT_TYPE_BROWSER",
	"CLIENT_TYPE_BOTS",
	"CLIENT_TYPE_MINI",
};

// ����ǰ��Ӧ�õ����
const COMPONENT_CLIENT_TYPE ALL_CLIENT_TYPES[] = {CLIENT_TYPE_MOBILE, CLIENT_TYPE_PC, CLIENT_TYPE_BROWSER, 
												CLIENT_TYPE_BOTS, CLIENT_TYPE_MINI, UNKNOWN_CLIENT_COMPONENT_TYPE};

typedef int8 CLIENT_CTYPE;

// ǰ���Ƿ�֧�ָ�����
// #define CLIENT_NO_FLOAT

// һ��cell��Ĭ�ϵı߽������С��С
#define CELL_DEF_MIN_AREA_SIZE				500.0f

/** һ���ռ��һ��chunk��С */
#define SPACE_CHUNK_SIZE					100

#define INVALID_VALUE						-1



}
#endif // KBE_COMMON_HPP
