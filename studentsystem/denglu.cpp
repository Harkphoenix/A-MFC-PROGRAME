// denglu.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "denglu.h"
#include "afxdialogex.h"
#include "MainDlg.h"

// denglu 对话框

IMPLEMENT_DYNAMIC(denglu, CDialogEx)

	denglu::denglu(CWnd* pParent /*=NULL*/)
	: CDialogEx(denglu::IDD, pParent)
	, m_edit_yonghuming(_T(""))
	, m_edit_mima(_T(""))
{

}

denglu::~denglu()
{
}

void denglu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_yonghuming_EDIT1, m_edit_yonghuming);
	DDX_Text(pDX, IDC_mima_EDIT2, m_edit_mima);
}


BEGIN_MESSAGE_MAP(denglu, CDialogEx)
	ON_BN_CLICKED(IDC_debglu_BUTTON3, &denglu::OnBnClickeddebgluButton3)
END_MESSAGE_MAP()


// denglu 消息处理程序


void denglu::OnBnClickeddebgluButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString admin = "xuran";
	CString passwd = "123456";
	int counts = 1;

	CString yonghuming = m_edit_yonghuming;
	CString mima = m_edit_mima;
	if(admin == yonghuming && passwd == mima)
	{
		MainDlg dlg;
		dlg.DoModal();
	}
	else
	{
		MessageBox("密码或账户名不对，别装了，你肯定不知道");
		counts++;
	}
	if(counts == 3)
	{
		MessageBox("登陆失败超过三次，你没有权限登陆系统");
		return ;
	}
	UpdateData(FALSE);

}
