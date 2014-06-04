#pragma once
#include "adodc1.h"


// CREWARDshuru 对话框

class CREWARDshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CREWARDshuru)

public:
	CREWARDshuru(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CREWARDshuru();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CAdodc1 m_rewardadodc;
	CString m_rewarddengji;
	CString m_rewardid;
	CString m_rewardmiaoshu;
	CString m_rewardshijian;
	CString m_rewardstuid;
	afx_msg void OnBnClickedcharuButton1();
};
