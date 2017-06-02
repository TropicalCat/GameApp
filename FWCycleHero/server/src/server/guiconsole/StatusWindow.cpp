// StatusWindow.cpp : implementation file
//

#include "stdafx.h"
#include "guiconsole.h"
#include "StatusWindow.h"


// StatusWindow dialog

IMPLEMENT_DYNAMIC(StatusWindow, CDialog)

StatusWindow::StatusWindow(CWnd* pParent /*=NULL*/)
	: CDialog(StatusWindow::IDD, pParent)
{

}

StatusWindow::~StatusWindow()
{
}

void StatusWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATUS_LIST1, m_statusList);
}


BEGIN_MESSAGE_MAP(StatusWindow, CDialog)
END_MESSAGE_MAP()

BOOL StatusWindow::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	DWORD dwStyle = m_statusList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;					//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	dwStyle |= LVS_EX_GRIDLINES;						//�����ߣ�ֻ������report����listctrl��
	//dwStyle |= LVS_EX_ONECLICKACTIVATE;
	m_statusList.SetExtendedStyle(dwStyle);				//������չ���

	int idx = 0;
	m_statusList.InsertColumn(idx++, _T("uid"),					LVCFMT_CENTER,	40);
	m_statusList.InsertColumn(idx++, _T("componentType"),		LVCFMT_CENTER,	100);
	m_statusList.InsertColumn(idx++, _T("componentID"),			LVCFMT_CENTER,	120);
	m_statusList.InsertColumn(idx++, _T("cpu"),					LVCFMT_CENTER,	60);
	m_statusList.InsertColumn(idx++, _T("memory"),				LVCFMT_CENTER,	100);
	m_statusList.InsertColumn(idx++, _T("entities"),			LVCFMT_CENTER,	100);
	m_statusList.InsertColumn(idx++, _T("proxies"),				LVCFMT_CENTER,	100);
	m_statusList.InsertColumn(idx++, _T("clients"),				LVCFMT_CENTER,	100);
	m_statusList.InsertColumn(idx++, _T("cells"),				LVCFMT_CENTER,	100);
	m_statusList.InsertColumn(idx++, _T("address"),				LVCFMT_CENTER,	140);
	m_statusList.InsertColumn(idx++, _T("username"),			LVCFMT_CENTER,	100);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void StatusWindow::autoWndSize()
{
	CRect rect;
	GetClientRect(&rect);

	m_statusList.MoveWindow(2, 3, rect.right - 2, rect.bottom - 3, TRUE);
	
}

void StatusWindow::addApp(Components::ComponentInfos& cinfos)
{
	std::stringstream stream;
	stream << cinfos.cid;
	CString str;
	std::string tstr;
	stream >> tstr;
	wchar_t* ws = KBEngine::strutil::char2wchar(tstr.c_str());
	str = ws;
	free(ws);

	bool found = false;
	for(int icount = 0; icount < m_statusList.GetItemCount(); icount++)
	{
		CString s = m_statusList.GetItemText(icount, 2);
		if(str == s)
		{
			found = true;
			break;
		}
	}

	if(!found)
	{
		CString suid;
		suid.Format(L"%u", cinfos.uid);
		m_statusList.InsertItem(0, suid);
		static int ndata = 0;
		m_statusList.SetItemData(0, ndata++);

		CString cname;
		ws = KBEngine::strutil::char2wchar(COMPONENT_NAME_EX(cinfos.componentType));
		cname = ws;
		free(ws);
		m_statusList.SetItemText(0, 1, cname);

		m_statusList.SetItemText(0, 2, str);

		suid.Format(L"%f", cinfos.cpu);
		m_statusList.SetItemText(0, 3, suid);

		suid.Format(L"%.2fm", float(cinfos.usedmem) / 1024.f / 1024.f);
		m_statusList.SetItemText(0, 4, suid);

		if(cinfos.componentType == CELLAPP_TYPE)
		{
			suid.Format(L"%d", cinfos.extradata);
			m_statusList.SetItemText(0, 5, suid);
			suid.Format(L"%d", cinfos.extradata1);
			m_statusList.SetItemText(0, 8, suid);
		}

		if(cinfos.componentType == BASEAPP_TYPE)
		{
			suid.Format(L"%d", cinfos.extradata);
			m_statusList.SetItemText(0, 5, suid);
			suid.Format(L"%d", cinfos.extradata2);
			m_statusList.SetItemText(0, 6, suid);
			suid.Format(L"%d", cinfos.extradata1);
			m_statusList.SetItemText(0, 7, suid);
		}

		ws = KBEngine::strutil::char2wchar(cinfos.pIntAddr->c_str());
		str = ws;
		free(ws);
		m_statusList.SetItemText(0, 9, str);

		ws = KBEngine::strutil::char2wchar(cinfos.username);
		str = ws;
		free(ws);
		m_statusList.SetItemText(0, 10, str);
	}
}

// StatusWindow message handlers
