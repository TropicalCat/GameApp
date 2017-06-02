/*
-------------------------------------------------------------------------------------------------
		file name : glw_errorcode.hpp
		desc	  : �������˴�����Ϣ����
		author    : LJP

		log		  : [2015-04-25]
-------------------------------------------------------------------------------------------------
*/

#ifndef KBE_SERVER_ERRORS_HPP
#define KBE_SERVER_ERRORS_HPP

// common include
#include "common/common.hpp"	
#if KBE_PLATFORM == PLATFORM_WIN32
// windows include
#else
// linux include
#endif

namespace KBEngine 
{ 

	/**
		���������� ��Ҫ�Ƿ��������ظ��ͻ����õġ�
	*/
	
	typedef uint16 SERVER_ERROR_CODE;								// ���������


	#define SERVER_SUCCESS								0			// �ɹ���
	#define SERVER_ERR_SRV_NO_READY						1			// ������û��׼���á�
	#define SERVER_ERR_SRV_OVERLOAD						2			// ���������ع��ء�
	#define SERVER_ERR_ILLEGAL_LOGIN					3			// �Ƿ���¼��
	#define SERVER_ERR_NAME_PASSWORD					4			// �û����������벻��ȷ��
	#define SERVER_ERR_NAME								5			// �û�������ȷ��
	#define SERVER_ERR_PASSWORD							6			// ���벻��ȷ��
	#define SERVER_ERR_ACCOUNT_CREATE_FAILED			7			// �����˺�ʧ�ܣ��Ѿ�����һ����ͬ���˺ţ���
	#define SERVER_ERR_BUSY								8			// �������ڷ�æ(���磺�ڷ�����ǰһ������δִ����ϵ����������N�δ����˺�)��
	#define SERVER_ERR_ACCOUNT_LOGIN_ANOTHER			9			// ��ǰ�˺�����һ����¼�ˡ�
	#define SERVER_ERR_ACCOUNT_IS_ONLINE				10			// ���Ѿ���¼�ˣ��������ܾ��ٴε�¼��
	#define SERVER_ERR_PROXY_DESTROYED					11			// ��ͻ��˹�����proxy�ڷ��������Ѿ����١�
	#define SERVER_ERR_ENTITYDEFS_NOT_MATCH				12			// entityDefs��ƥ�䡣
	#define SERVER_ERR_IN_SHUTTINGDOWN					13			// ���������ڹر���
	#define SERVER_ERR_NAME_MAIL						14			// email��ַ����
	#define SERVER_ERR_ACCOUNT_LOCK						15			// �˺ű����ᡣ
	#define SERVER_ERR_ACCOUNT_DEADLINE					16			// �˺��ѹ��ڡ�
	#define SERVER_ERR_ACCOUNT_NOT_ACTIVATED			17			// �˺�δ���
	#define SERVER_ERR_VERSION_NOT_MATCH				18			// �����˵İ汾��ƥ�䡣
	#define SERVER_ERR_OP_FAILED						19			// ����ʧ�ܡ�
	#define SERVER_ERR_SRV_STARTING						20			// ���������������С�
	#define SERVER_ERR_ACCOUNT_REGISTER_NOT_AVAILABLE	21			// δ�����˺�ע�Ṧ�ܡ�
	#define SERVER_ERR_CANNOT_USE_MAIL					22			// ����ʹ��email��ַ��
	#define SERVER_ERR_NOT_FOUND_ACCOUNT				23			// �Ҳ������˺š�
	#define SERVER_ERR_DB								24			// ���ݿ����(����dbmgr��־��DB)��

	const char SERVER_ERR_STR[][256] = 
	{
		"SERVER_SUCCESS",
		"SERVER_ERR_SRV_NO_READY",
		"SERVER_ERR_SRV_OVERLOAD",
		"SERVER_ERR_ILLEGAL_LOGIN",
		"SERVER_ERR_NAME_PASSWORD",
		"SERVER_ERR_NAME",
		"SERVER_ERR_PASSWORD",
		"SERVER_ERR_ACCOUNT_CREATE_FAILED",
		"SERVER_ERR_BUSY",
		"SERVER_ERR_ACCOUNT_LOGIN_ANOTHER",
		"SERVER_ERR_ACCOUNT_IS_ONLINE",
		"SERVER_ERR_PROXY_DESTROYED",
		"SERVER_ERR_ENTITYDEFS_NOT_MATCH",
		"SERVER_ERR_IN_SHUTTINGDOWN",
		"SERVER_ERR_NAME_MAIL",
		"SERVER_ERR_ACCOUNT_LOCK",
		"SERVER_ERR_ACCOUNT_DEADLINE",
		"SERVER_ERR_ACCOUNT_NOT_ACTIVATED",
		"SERVER_ERR_VERSION_NOT_MATCH",
		"SERVER_ERR_OP_FAILED",
		"SERVER_ERR_SRV_STARTING",
		"SERVER_ERR_ACCOUNT_REGISTER_NOT_AVAILABLE",
		"SERVER_ERR_CANNOT_USE_MAIL",
		"SERVER_ERR_NOT_FOUND_ACCOUNT",
		"SERVER_ERR_DB"
	};

}

#endif // KBE_SERVER_ERRORS_HPP
