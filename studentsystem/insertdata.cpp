// insertdata.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "insertdata.h"
#include "afxdialogex.h"
#include "denglu.h"

// insertdata 对话框

IMPLEMENT_DYNAMIC(insertdata, CDialogEx)

insertdata::insertdata(CWnd* pParent /*=NULL*/)
	: CDialogEx(insertdata::IDD, pParent)
	, m_edit_banji(_T(""))
	, m_edit_jiguan(_T(""))
	, m_edit_name(_T(""))
	, m_edit_shengri(_T(""))
	, m_edit_xingbie(_T(""))
	, m_edit_xuehao(_T(""))
	, m_edit_zhuanye(_T(""))
	, m_edit_waihao(_T(""))
{

}

insertdata::~insertdata()
{
}

void insertdata::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_banji_EDIT6, m_edit_banji);
	DDX_Text(pDX, IDC_jiguan_EDIT10, m_edit_jiguan);
	DDX_Text(pDX, IDC_name_EDIT3, m_edit_name);
	DDX_Text(pDX, IDC_shengri_EDIT9, m_edit_shengri);
	DDX_Text(pDX, IDC_xingbie_EDIT5, m_edit_xingbie);
	DDX_Text(pDX, IDC_xuehao_EDIT2, m_edit_xuehao);
	DDX_Text(pDX, IDC_zhuanye_EDIT8, m_edit_zhuanye);
	DDX_Control(pDX, IDC_ADODC1, m_charuadodc);
	DDX_Text(pDX, IDC_waihao_EDIT1, m_edit_waihao);
}


BEGIN_MESSAGE_MAP(insertdata, CDialogEx)
	ON_BN_CLICKED(IDC_charu_BUTTON1, &insertdata::OnClickedCharuButton1)
END_MESSAGE_MAP()


// insertdata 消息处理程序


void insertdata::OnClickedCharuButton1()
{
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
	_bstr_t strAdd = "INSERT INTO STUDENT VALUES('";
	strAdd = strAdd + m_edit_xuehao + "','"; 
	strAdd = strAdd + m_edit_name + "','";
	strAdd = strAdd + m_edit_xingbie + "','";
	strAdd = strAdd + m_edit_banji + "','";
	strAdd = strAdd + m_edit_zhuanye + "','";
	strAdd = strAdd + m_edit_shengri + "','";
	strAdd = strAdd + m_edit_jiguan + "','";
	strAdd = strAdd + m_edit_waihao + "')";

	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();

	m_charuadodc.put_RecordSource("SELECT * FROM STUDENT"); 
	m_charuadodc.Refresh();
	UpdateData(FALSE);
}	
