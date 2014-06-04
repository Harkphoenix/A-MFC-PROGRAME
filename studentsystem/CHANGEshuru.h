#pragma once
#include "adodc1.h"


// CCHANGEshuru 对话框

class CCHANGEshuru : public CDialogEx
{
	DECLARE_DYNAMIC(CCHANGEshuru)

public:
	CCHANGEshuru(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCHANGEshuru();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_change;
	CString m_changeid;
	CString m_changemiaoshu;
	CString m_changeshijian;
	CString m_changestuid;
	afx_msg void OnBnClickedchangechashuButton1();
	CAdodc1 m_changeadodc;
};
