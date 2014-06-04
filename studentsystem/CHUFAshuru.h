#pragma once
#include "adodc1.h"
#include "afxwin.h"


// CCHUFAshuru 对话框

class CCHUFAshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CCHUFAshuru)

public:
	CCHUFAshuru(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCHUFAshuru();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_chufaadodc;
//	CEdit m_chufadengji;
//	CEdit m_chufaid;
//	CEdit m_chufashijian;
	CString m_chufadengji;
	CString m_chufaid;
	CString m_chufashijian;
	CString m_chufastuid;
	CString m_chufazhuangtai;
	CString m_chufamiaoshu;
	afx_msg void OnBnClickedchufacharuButton1();
};
