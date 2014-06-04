
// studentsystemDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "adodc1.h"
#include "datagrid1.h"


// CstudentsystemDlg 对话框
class CstudentsystemDlg : public CDialogEx
{
// 构造
public:
	CstudentsystemDlg(CWnd* pParent = NULL);	// 标准构造函数
	void CstudentsystemDlg::takeupdate();
// 对话框数据
	enum { IDD = IDD_STUDENTSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_biao;
	CComboBox m_ziduan_combo;
//	CComboBox m_combo_ziduan;
	CString m_edit_shuru;
	CAdodc1 m_adodc1;
	afx_msg void OnClickedChaxunButton1();
	afx_msg void OnKillfocusBiaoCombo1();
	//CComboBox m_combo_ziduan;
//	afx_msg void OnCbnSelchangebiaoCombo1();
	CDatagrid1 m_grid;
};
