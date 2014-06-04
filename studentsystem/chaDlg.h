#pragma once


// chaDlg 对话框

class chaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(chaDlg)

public:
	chaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~chaDlg();

// 对话框数据
	enum { IDD = IDD_chaxunzhu_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedDanbiaoButton2();
//	afx_msg void OnClickedDuobiaoButton1();
	afx_msg void OnBnClickedduobiaoButton1();
};
