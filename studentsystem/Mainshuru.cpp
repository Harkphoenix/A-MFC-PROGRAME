// Mainshuru.cpp : 实现文件
//

#include "stdafx.h"
#include "studentsystem.h"
#include "Mainshuru.h"
#include "afxdialogex.h"
#include "insertdata.h"
#include "CHANGEshuru.h"
#include "REWARDshuru.h"
#include "CHUFAshuru.h"
#include "CLASSshuru.h"
// Mainshuru 对话框

IMPLEMENT_DYNAMIC(Mainshuru, CDialogEx)

Mainshuru::Mainshuru(CWnd* pParent /*=NULL*/)
	: CDialogEx(Mainshuru::IDD, pParent)
{

}

Mainshuru::~Mainshuru()
{
}

void Mainshuru::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Mainshuru, CDialogEx)
	ON_BN_CLICKED(IDC_geren_BUTTON1, &Mainshuru::OnBnClickedgerenButton1)
	ON_BN_CLICKED(IDC_xueji_BUTTON2, &Mainshuru::OnBnClickedxuejiButton2)
	ON_BN_CLICKED(IDC_jiangli_BUTTON3, &Mainshuru::OnBnClickedjiangliButton3)
	ON_BN_CLICKED(IDC_chufa_BUTTON4, &Mainshuru::OnBnClickedchufaButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Mainshuru::OnBnClickedButton5)
END_MESSAGE_MAP()


// Mainshuru 消息处理程序


void Mainshuru::OnBnClickedgerenButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	insertdata dlag;
	dlag.DoModal();

}


void Mainshuru::OnBnClickedxuejiButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CCHANGEshuru dlag;
	dlag.DoModal();
}


void Mainshuru::OnBnClickedjiangliButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CREWARDshuru dlag;
	dlag.DoModal();
}


void Mainshuru::OnBnClickedchufaButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CCHUFAshuru dlag;
	dlag.DoModal();
}


void Mainshuru::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CCLASSshuru dlag;
	dlag.DoModal();
}
