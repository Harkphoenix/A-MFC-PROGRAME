// Cshanchu.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "Cshanchu.h"
#include "afxdialogex.h"
#include "column.h"
#include "columns.h"

// Cshanchu 对话框

IMPLEMENT_DYNAMIC(Cshanchu, CDialogEx)

Cshanchu::Cshanchu(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cshanchu::IDD, pParent)
{

}

Cshanchu::~Cshanchu()
{
}

void Cshanchu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_shanchu_ADODC1, m_shanchuadodc1);
	DDX_Control(pDX, IDC_shanchu_DATAGRID1, m_shanchudatagrid);
}


BEGIN_MESSAGE_MAP(Cshanchu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cshanchu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Cshanchu::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cshanchu 消息处理程序
BEGIN_EVENTSINK_MAP(Cshanchu, CDialogEx)
	ON_EVENT(Cshanchu, IDC_shanchu_DATAGRID1, DISPID_DBLCLICK, Cshanchu::OnDblclickShanchuDatagrid1, VTS_NONE)
END_EVENTSINK_MAP()


void Cshanchu::OnDblclickShanchuDatagrid1()
{
	// TODO: 在此处添加消息处理程序代码
	int ColNum = 2;
	CString coVal;
	CColumns cols;
	CColumn  col;
	VARIANT v_ColNum, v_Value;
	cols = m_shanchudatagrid.get_Columns();
	v_ColNum.vt = VT_I2;

	//读取学号
	v_ColNum.iVal = 0;
	col = cols.GetItem(v_ColNum);
	v_Value = col.GetValue();
	CString temp = (CString)v_Value.bstrVal;
	CString temp2 = "确认要删除编号为 " + temp + "的记录么？";
	if(MessageBox(temp2,_T("删除数据提示"),MB_YESNO|MB_ICONSTOP)!=IDYES)
		return ;

	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);     //初始化OLE控件
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
	_bstr_t strAdd = "DELETE FROM STUDENT WHERE STUID = " + temp;
	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();
	m_shanchuadodc1.put_RecordSource("select * from STUDENT");
	m_shanchuadodc1.Refresh();
	UpdateData(FALSE);
}


void Cshanchu::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnDblclickShanchuDatagrid1();
}


void Cshanchu::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(MessageBox(_T("确认要删除所有的数据么"),_T("删除数据提示"),MB_YESNO|MB_ICONSTOP)!=IDYES)
		return ;

	UpdateData(TRUE);
	_ConnectionPtr m_pConnection;
	::CoInitialize(NULL);     //初始化OLE控件
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
	_bstr_t strAdd = "DELETE FROM STUDENT";
	m_pConnection->Execute(strAdd, &ra, adCmdText);
	m_pConnection->Close();
	m_shanchuadodc1.put_RecordSource("select * from STUDENT");
	m_shanchuadodc1.Refresh();
	UpdateData(FALSE);

}
