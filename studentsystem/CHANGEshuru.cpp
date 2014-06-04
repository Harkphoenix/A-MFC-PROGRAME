// CHANGEshuru.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "CHANGEshuru.h"
#include "afxdialogex.h"


// CCHANGEshuru 对话框

IMPLEMENT_DYNAMIC(CCHANGEshuru, CDialogEx)

CCHANGEshuru::CCHANGEshuru(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCHANGEshuru::IDD, pParent)
	, m_change(_T(""))
	, m_changeid(_T(""))
	, m_changemiaoshu(_T(""))
	, m_changeshijian(_T(""))
	, m_changestuid(_T(""))
{

}

CCHANGEshuru::~CCHANGEshuru()
{
}

void CCHANGEshuru::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_change_EDIT4, m_change);
	DDX_Text(pDX, IDC_id_EDIT1, m_changeid);
	DDX_Text(pDX, IDC_miaoshu_EDIT6, m_changemiaoshu);
	DDX_Text(pDX, IDC_shijian_EDIT5, m_changeshijian);
	DDX_Text(pDX, IDC_stuid_EDIT3, m_changestuid);
	DDX_Control(pDX, IDC_ADODC1, m_changeadodc);
}


BEGIN_MESSAGE_MAP(CCHANGEshuru, CDialogEx)
	ON_BN_CLICKED(IDC_changechashu_BUTTON1, &CCHANGEshuru::OnBnClickedchangechashuButton1)
END_MESSAGE_MAP()


// CCHANGEshuru 消息处理程序


void CCHANGEshuru::OnBnClickedchangechashuButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);             //初始化OLE/COM库环境
	
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConn = "Provider = SQLOLEDB.1;Integrated Security = SSPI; Persist Security Info = False; Initial Catalog = 学生信息管理系统; Data Source = XURAN";
		m_pConnection->Open(strConn, "","",adModeUnknown);
		//if(m_pConnection->State == adStateOpen) MessageBox("已经成功连接该数据库");
	}
	catch(_com_error e)
	{
		::CoUninitialize();
		AfxMessageBox(e.ErrorMessage());
		return ;
	}

	_variant_t ra;
	_bstr_t strAdd = "INSERT INTO CHANGE VALUES('";
	strAdd = strAdd + m_changeid + "','"; 
	strAdd = strAdd + m_changestuid + "','";
	strAdd = strAdd + m_change + "','";
	strAdd = strAdd + m_changeshijian + "','";
	strAdd = strAdd + m_changemiaoshu + "')";

	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();

	m_changeadodc.put_RecordSource("SELECT * FROM CHANGE"); 
	m_changeadodc.Refresh();
	UpdateData(FALSE);
}
