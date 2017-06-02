
// guiconsole.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "common/common.hpp"
#include "network/endpoint.hpp"
#include "network/common.hpp"
#include "network/channel.hpp"
#include "network/tcp_packet.hpp"
#include "network/interfaces.hpp"
#include "network/event_dispatcher.hpp"
#include "network/glw_netsession.hpp"
#include "helper/debug_helper.hpp"
#include "xmlplus/xmlplus.hpp"
#include "common/smartpointer.hpp"

// CguiconsoleApp:
// See guiconsole.cpp for the implementation of this class
//

class CguiconsoleApp : public CWinAppEx
{
public:
	CguiconsoleApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CguiconsoleApp theApp;

inline CString GetAppPath()
{
	::TCHAR modulePath[MAX_PATH];
    GetModuleFileName(NULL, modulePath, MAX_PATH);
    CString strModulePath(modulePath);
    strModulePath = strModulePath.Left(strModulePath.ReverseFind(_T('\\')));
    return strModulePath;
}

struct ListSortData{
     CListCtrl *listctrl;               //CListCtrl�ؼ�ָ��
     int isub;							//l�к�
     int seq;							//1Ϊ����0Ϊ����
};

int CALLBACK CompareFunc(LPARAM lParam1,LPARAM lParam2,LPARAM lParamSort);
int CALLBACK CompareFloatFunc(LPARAM lParam1,LPARAM lParam2,LPARAM lParamSort);

extern int g_diffHeight;
extern bool g_isDestroyed;