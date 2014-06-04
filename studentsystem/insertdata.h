#pragma once
#include "adodc1.h"


// insertdata 对话框

class insertdata : public CDialogEx
{
	DECLARE_DYNAMIC(insertdata)

public:
	insertdata(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~insertdata();

// 对话框数据
	enum { IDD = IDD_stufilecharu_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_edit_banji;
	CString m_edit_jiguan;
	CString m_edit_name;
	CString m_edit_shengri;
	CString m_edit_xingbie;
	CString m_edit_xuehao;
	CString m_edit_zhuanye;
	afx_msg void OnClickedCharuButton1();
	CAdodc1 m_charuadodc;
	CString m_edit_waihao;
};
