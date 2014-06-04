// Cduobiao.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "Cduobiao.h"
#include "afxdialogex.h"


// Cduobiao 对话框

IMPLEMENT_DYNAMIC(Cduobiao, CDialogEx)

Cduobiao::Cduobiao(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cduobiao::IDD, pParent)
	, m_duobiaobanji(_T(""))
	, m_duobiaoxingming(_T(""))
{

}

Cduobiao::~Cduobiao()
{
}

void Cduobiao::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_banji_EDIT2, m_duobiaobanji);
	DDX_Text(pDX, IDC_xingming_EDIT1, m_duobiaoxingming);
	DDX_Control(pDX, IDC_ADODC1, m_duobiaoadodc1);
}


BEGIN_MESSAGE_MAP(Cduobiao, CDialogEx)
	ON_BN_CLICKED(IDC_xingming_RADIO1, &Cduobiao::OnBnClickedxingmingRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cduobiao::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_chaxun_BUTTON1, &Cduobiao::OnBnClickedchaxunButton1)
END_MESSAGE_MAP()


// Cduobiao 消息处理程序

int selectyes = 0;
void Cduobiao::OnBnClickedxingmingRadio1()
{
	selectyes = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void Cduobiao::OnBnClickedRadio2()
{
	selectyes = 2;
	// TODO: 在此添加控件通知处理程序代码
}


void Cduobiao::OnBnClickedchaxunButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(selectyes == 1)
	{
		CString str = "select * from Stu_view where s_name = '" + m_duobiaoxingming + "'";
		m_duobiaoadodc1.put_RecordSource(str);
		m_duobiaoadodc1.Refresh();
		UpdateData(FALSE);
	}
}
