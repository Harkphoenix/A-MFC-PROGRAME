// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "studentsystemDlg.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "insertdata.h"
#include "denglu.h"
#include "chaDlg.h"
#include "update.h"
#include "Mainshuru.h"
#include "Cshanchu.h"
// MainDlg 对话框

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainDlg::IDD, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &MainDlg::OnBnClickedButtonInsert)
//	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &MainDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &MainDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_shuru_BUTTON1, &MainDlg::OnBnClickedshuruButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &MainDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// MainDlg 消息处理程序


void MainDlg::OnBnClickedButtonInsert()
{
	// TODO: 在此添加控件通知处理程序代码
	//CstudentsystemDlg dlg;
	//chaxunzhu dlg;
	chaDlg dlg;
	dlg.DoModal();
	
}


void MainDlg::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
	update dlg;
	dlg.DoModal();
}


void MainDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}





void MainDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	update dlg;
	dlg.DoModal();
}


void MainDlg::OnBnClickedshuruButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Mainshuru dlag;
	dlag.DoModal();
}


void MainDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	Cshanchu dlag;
	dlag.DoModal();
}
