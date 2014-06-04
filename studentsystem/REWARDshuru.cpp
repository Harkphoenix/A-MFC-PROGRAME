// REWARDshuru.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "REWARDshuru.h"
#include "afxdialogex.h"


// CREWARDshuru 对话框

IMPLEMENT_DYNAMIC(CREWARDshuru, CDialogEx)

CREWARDshuru::CREWARDshuru(CWnd* pParent /*=NULL*/)
	: CDialogEx(CREWARDshuru::IDD, pParent)
	, m_rewarddengji(_T(""))
	, m_rewardid(_T(""))
	, m_rewardmiaoshu(_T(""))
	, m_rewardshijian(_T(""))
	, m_rewardstuid(_T(""))
{

}

CREWARDshuru::~CREWARDshuru()
{
}

void CREWARDshuru::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_JIANGLI_ADODC1, m_rewardadodc);
	DDX_Text(pDX, IDC_rewdengji_EDIT3, m_rewarddengji);
	DDX_Text(pDX, IDC_rewid_EDIT1, m_rewardid);
	DDX_Text(pDX, IDC_rewmiaoshu_EDIT6, m_rewardmiaoshu);
	DDX_Text(pDX, IDC_rewshijian_EDIT5, m_rewardshijian);
	DDX_Text(pDX, IDC_rewstuid_EDIT2, m_rewardstuid);
}


BEGIN_MESSAGE_MAP(CREWARDshuru, CDialogEx)
	ON_BN_CLICKED(IDC_charu_BUTTON1, &CREWARDshuru::OnBnClickedcharuButton1)
END_MESSAGE_MAP()


// CREWARDshuru 消息处理程序


void CREWARDshuru::OnBnClickedcharuButton1()
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
	_bstr_t strAdd = "INSERT INTO REWARD VALUES('";
	strAdd = strAdd + m_rewardid + "','"; 
	strAdd = strAdd + m_rewardstuid + "','";
	strAdd = strAdd + m_rewarddengji + "','";
	strAdd = strAdd + m_rewardshijian + "','";
	strAdd = strAdd + m_rewardmiaoshu + "')";

	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();

	m_rewardadodc.put_RecordSource("SELECT * FROM REWARD"); 
	m_rewardadodc.Refresh();
	UpdateData(FALSE);

}
