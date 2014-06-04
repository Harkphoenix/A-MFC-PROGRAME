// chaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "chaDlg.h"
#include "afxdialogex.h"
#include "studentsystemDlg.h"
#include "Cduobiao.h"
// chaDlg 对话框

IMPLEMENT_DYNAMIC(chaDlg, CDialogEx)

chaDlg::chaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(chaDlg::IDD, pParent)
{

}

chaDlg::~chaDlg()
{
}

void chaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(chaDlg, CDialogEx)
	ON_BN_CLICKED(IDC_danbiao_BUTTON2, &chaDlg::OnClickedDanbiaoButton2)
//	ON_BN_CLICKED(IDC_duobiao_BUTTON1, &chaDlg::OnClickedDuobiaoButton1)
ON_BN_CLICKED(IDC_duobiao_BUTTON1, &chaDlg::OnBnClickedduobiaoButton1)
END_MESSAGE_MAP()


// chaDlg 消息处理程序


void chaDlg::OnClickedDanbiaoButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CstudentsystemDlg dlg;
	dlg.DoModal();
}



void chaDlg::OnBnClickedduobiaoButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cduobiao dlg;
	dlg.DoModal();
}
