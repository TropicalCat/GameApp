
#ifndef KBE_DEBUG_HPP
#define KBE_DEBUG_HPP

#include <assert.h>
#include <time.h>	
#include <stdarg.h> 
#include <queue> 
#if defined( __WIN32__ ) || defined( WIN32 ) || defined( _WIN32 )
#pragma warning(disable:4819)
#endif
#include "common/singleton.hpp"
#include "thread/threadmutex.hpp"
#include "network/common.hpp"


namespace KBEngine{


	class EventDispatcher;


/** 
	֧��uft-8�����ַ������ 
*/
void vutf8printf(FILE *out, const char *str, va_list* ap);
void utf8printf(FILE *out, const char *str, ...);


#define	KBELOG_UNKNOWN		0x00000000
#define	KBELOG_PRINT		0x00000001
#define	KBELOG_ERROR		0x00000002
#define	KBELOG_WARNING		0x00000004
#define	KBELOG_DEBUG		0x00000008
#define	KBELOG_INFO			0x00000010
#define	KBELOG_CRITICAL		0x00000020
#define KBELOG_SCRIPT		0x00000040

#define KBELOG_TYPES KBELOG_UNKNOWN | KBELOG_PRINT | KBELOG_ERROR | KBELOG_WARNING | KBELOG_DEBUG | KBELOG_INFO | KBELOG_CRITICAL | KBELOG_SCRIPT

const char KBELOG_TYPE_NAME[][255] = {
	" UNKNOWN",
	"        ",
	"   ERROR",
	" WARNING",
	"   DEBUG",
	"    INFO",
	"CRITICAL",
	"  SCRIPT",
};

inline const char* KBELOG_TYPE_NAME_EX(uint32 CTYPE)
{									
	if(CTYPE < 0 || ((CTYPE) & (KBELOG_TYPES)) <= 0)
	{
		return " UNKNOWN";
	}
	
	switch(CTYPE)
	{
	case KBELOG_PRINT:
		return "        ";
	case KBELOG_ERROR:
		return "   ERROR";
	case KBELOG_WARNING:
		return " WARNING";
	case KBELOG_DEBUG:
		return "   DEBUG";
	case KBELOG_INFO:
		return "    INFO";
	case KBELOG_CRITICAL:
		return "CRITICAL";
	case KBELOG_SCRIPT:
		return "  SCRIPT";
	};

	return " UNKNOWN";
}

class DebugHelper  : public Singleton<DebugHelper>
{

public:
	 DebugHelper();
	~DebugHelper();
	
	static void initialize(COMPONENT_TYPE componentType);
	static void finalise();


	void			print_msg(const std::string& s);
	void			debug_msg(const std::string& s);
	void			error_msg(const std::string& s);
	void			info_msg(const std::string& s);
	void			warning_msg(const std::string& s);
	void			critical_msg(const std::string& s);
	
	void			printmsg(INT32 eType, const char* format, ...);

	
	void			changeLogger(std::string name);
	void			clearBufferedLog(bool destroy = false);
	void			shouldWriteToSyslog(bool v = true);

	/** 
		ͬ����־��messagelog
	*/
	void			sync();
private:
	FILE*			_logfile;
	std::string		_currFile, _currFuncName;
	uint32			_currLine;

	bool			noSyncLog_;
	bool			canLogFile_;
};

/*---------------------------------------------------------------------------------
	������Ϣ����ӿ�
---------------------------------------------------------------------------------*/	
#define PRINT_MSG(m)					DebugHelper::getSingleton().print_msg((m))									// ����κ���Ϣ
#define ERROR_MSG(m)					DebugHelper::getSingleton().error_msg((m))									// ���һ������
#define DEBUG_MSG(m)					DebugHelper::getSingleton().debug_msg((m))									// ���һ��debug��Ϣ
#define INFO_MSG(m)						DebugHelper::getSingleton().info_msg((m))									// ���һ��info��Ϣ
#define WARNING_MSG(m)					DebugHelper::getSingleton().warning_msg((m))								// ���һ��������Ϣ
#define CRITICAL_MSG(m)					DebugHelper::getSingleton().setFile(__FUNCTION__, \
										__FILE__, __LINE__); \
										DebugHelper::getSingleton().critical_msg((m))

/*---------------------------------------------------------------------------------
	���Ժ�
---------------------------------------------------------------------------------*/
#ifdef KBE_USE_ASSERTS
void myassert(const char* exp, const char * func, const char * file, unsigned int line);
#define KBE_ASSERT(exp) if(!(exp))myassert(#exp, __FUNCTION__, __FILE__, __LINE__);
#define KBE_REAL_ASSERT assert(0);
#else
#define KBE_ASSERT(exp) NULL;
#define KBE_REAL_ASSERT
#endif

#ifdef _DEBUG
#define KBE_VERIFY KBE_ASSERT
#else
#define KBE_VERIFY(exp) (exp)
#endif

#define KBE_EXIT(msg) {														\
			CRITICAL_MSG(msg);												\
			KBE_REAL_ASSERT	}												\


}

#endif // KBE_DEBUG_HPP
