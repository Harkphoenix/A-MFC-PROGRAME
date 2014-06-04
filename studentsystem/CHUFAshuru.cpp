// CHUFAshuru.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "CHUFAshuru.h"
#include "afxdialogex.h"


// CCHUFAshuru 对话框

IMPLEMENT_DYNAMIC(CCHUFAshuru, CDialogEx)

CCHUFAshuru::CCHUFAshuru(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCHUFAshuru::IDD, pParent)
	, m_chufadengji(_T(""))
	, m_chufaid(_T(""))
	, m_chufashijian(_T(""))
	, m_chufastuid(_T(""))
	, m_chufazhuangtai(_T(""))
	, m_chufamiaoshu(_T(""))
{

}

CCHUFAshuru::~CCHUFAshuru()
{
}

void CCHUFAshuru::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_chufa_ADODC1, m_chufaadodc);
	//  DDX_Control(pDX, IDC_chufadengji_EDIT4, m_chufadengji);
	//  DDX_Control(pDX, IDC_chufaid_EDIT1, m_chufaid);
	//  DDX_Control(pDX, IDC_chufashijian_EDIT5, m_chufashijian);
	DDX_Text(pDX, IDC_chufadengji_EDIT4, m_chufadengji);
	DDX_Text(pDX, IDC_chufaid_EDIT1, m_chufaid);
	DDX_Text(pDX, IDC_chufashijian_EDIT5, m_chufashijian);
	DDX_Text(pDX, IDC_chufastuid_EDIT3, m_chufastuid);
	DDX_Text(pDX, IDC_chulizhuangtai_EDIT6, m_chufazhuangtai);
	DDX_Text(pDX, IDC_miaoshu_EDIT7, m_chufamiaoshu);
}


BEGIN_MESSAGE_MAP(CCHUFAshuru, CDialogEx)
	ON_BN_CLICKED(IDC_chufacharu_BUTTON1, &CCHUFAshuru::OnBnClickedchufacharuButton1)
END_MESSAGE_MAP()


// CCHUFAshuru 消息处理程序


void CCHUFAshuru::OnBnClickedchufacharuButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	_bstr_t strAdd = "INSERT INTO PUBLISHMENT VALUES('";
	strAdd = strAdd + m_chufaid + "','"; 
	strAdd = strAdd + m_chufastuid + "','";
	strAdd = strAdd + m_chufadengji + "','";
	strAdd = strAdd + m_chufashijian + "','";
	strAdd = strAdd + m_chufazhuangtai + "','";
	strAdd = strAdd + m_chufamiaoshu + "')";

	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();

	m_chufaadodc.Refresh();
	m_chufaadodc.put_RecordSource("SELECT * FROM PUBLISHMENT"); 
	m_chufaadodc.Refresh();
	UpdateData(FALSE);
}
