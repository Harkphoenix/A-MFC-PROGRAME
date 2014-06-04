
// studentsystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "studentsystemDlg.h"
#include "afxdialogex.h"
#include "datagrid1.h"
#include "CColumn.h"
#include "CColumns0.h"
#include "string"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

_ConnectionPtr m_pConnection;
_RecordsetPtr  m_pRecordsetPtr;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CstudentsystemDlg 对话框



CstudentsystemDlg::CstudentsystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CstudentsystemDlg::IDD, pParent)
	, m_edit_shuru(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CstudentsystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_biao_COMBO1, m_combo_biao);
	//  DDX_Control(pDX, IDC_ziduan_COMBO2, m_combo_ziduan);
	DDX_Text(pDX, IDC_shuru_EDIT1, m_edit_shuru);
	DDX_Control(pDX, IDC_ADODC1, m_adodc1);
	DDX_Control(pDX, IDC_ziduan_COMBO3, m_ziduan_combo);
	DDX_Control(pDX, IDC_DATAGRID1, m_grid);
}

BEGIN_MESSAGE_MAP(CstudentsystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_chaxun_BUTTON1, &CstudentsystemDlg::OnClickedChaxunButton1)
	ON_CBN_KILLFOCUS(IDC_biao_COMBO1, &CstudentsystemDlg::OnKillfocusBiaoCombo1)
	//	ON_CBN_SELCHANGE(IDC_biao_COMBO1, &CstudentsystemDlg::OnCbnSelchangebiaoCombo1)
END_MESSAGE_MAP()


// CstudentsystemDlg 消息处理程序

BOOL CstudentsystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_combo_biao.SetWindowText((CString)"STUDENT");                      //初始化
	m_ziduan_combo.SetWindowText((CString)"NAME");
	m_ziduan_combo.SetWindowText((CString)"SEX");
	m_ziduan_combo.SetWindowText((CString)"STUID");

	m_combo_biao.AddString("STUDENT");
	m_combo_biao.AddString("CHANGE");
	m_combo_biao.AddString("REWARD");
	m_combo_biao.AddString("PUBLISHMENT");
	m_combo_biao.AddString("DEPARTMENT");
	m_combo_biao.AddString("CLASS");


	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CstudentsystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CstudentsystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CstudentsystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CstudentsystemDlg::OnClickedChaxunButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString tempstr;
	CString strSQL = (CString)"SELECT * FROM ";
	m_combo_biao.GetWindowText(tempstr);            //获取combo菜单中的输入
	strSQL += tempstr + (CString)" WHERE ";
	m_ziduan_combo.GetWindowText(tempstr);
	strSQL += tempstr + (CString)" = ";
	strSQL += (CString)"'" + m_edit_shuru + (CString)"'";
    m_adodc1.put_RecordSource(strSQL);
    m_adodc1.Refresh();
	m_grid.Refresh();
	UpdateData(FALSE);    //
}

void CstudentsystemDlg::takeupdate()
{
	UpdateData(TRUE);
	CString tempstr;
	CString strSQL = (CString)"SELECT * FROM ";
	m_combo_biao.GetWindowText(tempstr);
	strSQL += tempstr;
	m_adodc1.put_RecordSource(strSQL);
    m_adodc1.Refresh();
	m_grid.Refresh();
	UpdateData(FALSE);
}
void CstudentsystemDlg::OnKillfocusBiaoCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tableName;
	m_combo_biao.GetWindowText(tableName);
	m_ziduan_combo.ResetContent();
	::CoInitialize(NULL);             //初始化OLE/COM库环境
	if(tableName == "STUDENT")
	{

		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("NAME");
		m_ziduan_combo.AddString("SEX");
		m_ziduan_combo.AddString("CLASS");
		takeupdate();
	}
	else if(tableName == "CHANGE")
	{
		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("CHANGE");
		takeupdate();
	//try
	//{
		//m_pConnection.CreateInstance("ADODB.Connection");
		//m_pRecordsetPtr.CreateInstance("ADODB.Recordset");
		//_bstr_t strConn = "Provider = SQLOLEDB.1;Integrated Security = SSPI; Persist Security Info = False; Initial Catalog = 课程设计实例; Data Source = XURAN";
		//m_pConnection->Open(strConn, "","",adModeUnknown);
		//if(m_pConnection->State == adStateOpen) MessageBox("已经成功连接该数据库");
		//m_pRecordsetPtr->Open("SELECT * FROM students",_variant_t((IDispatch*)m_pConnection,true),adOpenStatic,adLockOptimistic,adCmdText);
		//m_grid.putref_DataSource(NULL);
		//m_grid.putref_DataSource((LPUNKNOWN)m_pRecordsetPtr);
		//m_grid.Refresh();
		//if(m_pConnection->State == adStateOpen) MessageBox("已经成功连接该数据库");
	//}
	//catch(_com_error e)
	//{
	//	::CoUninitialize();
	//	AfxMessageBox(e.ErrorMessage());
	//	return ;
	//}
		

	} else if(tableName == "REWARD")
	{
		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("LEVELS");
		takeupdate();

	} else if(tableName == "PUBLISHMENT")
	{
		m_ziduan_combo.AddString("STUID");
		m_ziduan_combo.AddString("LEVELS");
		takeupdate();

	} else if(tableName == "DEPARTMENT")
	{
		m_ziduan_combo.AddString("ID");
		m_ziduan_combo.AddString("NAME");
		takeupdate();

	} else if(tableName == "CLASS")
	{
		m_ziduan_combo.AddString("ID");
		m_ziduan_combo.AddString("NAME");
		m_ziduan_combo.AddString("MONITOR");
		takeupdate();
	}

}
