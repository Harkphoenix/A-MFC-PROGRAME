#pragma once
#include "adodc1.h"


// CCLASSshuru 对话框

class CCLASSshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CCLASSshuru)

public:
	CCLASSshuru(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCLASSshuru();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_banjiadodc;
	CString m_banjibanzhang;
	CString m_banjiid;
	CString m_banjiname;
	afx_msg void OnBnClickedcharuButton1();
};
