#pragma once
#include "adodc1.h"
#include "datagrid1.h"


// Cshanchu 对话框

class Cshanchu : public CDialogEx
{
	DECLARE_DYNAMIC(Cshanchu)

public:
	Cshanchu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cshanchu();

// 对话框数据
	enum { IDD = IDD_SHANCHU_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	void OnDblclickShanchuDatagrid1();
	CAdodc1 m_shanchuadodc1;
	CDatagrid1 m_shanchudatagrid;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
};
