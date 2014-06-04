#pragma once


// denglu 对话框

class denglu : public CDialogEx
{
	DECLARE_DYNAMIC(denglu)

public:
	denglu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~denglu();

// 对话框数据
	enum { IDD = IDD_denglu_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickeddebgluButton3();
	CString m_edit_yonghuming;
	CString m_edit_mima;
};
