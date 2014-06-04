#pragma once
#include "adodc1.h"


// Cduobiao 对话框

class Cduobiao : public CDialogEx
{
	DECLARE_DYNAMIC(Cduobiao)

public:
	Cduobiao(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cduobiao();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_duobiaobanji;
	CString m_duobiaoxingming;
	CAdodc1 m_duobiaoadodc1;
	afx_msg void OnBnClickedxingmingRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedchaxunButton1();
};
