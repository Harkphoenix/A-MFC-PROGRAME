//Download by http://www.NewXing.com
// DataGridDlg.h : header file
//

#if !defined(AFX_DATAGRIDDLG_H__A768AB82_E720_4E23_BAAD_3BE6662777B0__INCLUDED_)
#define AFX_DATAGRIDDLG_H__A768AB82_E720_4E23_BAAD_3BE6662777B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDataGridDlg dialog

class CDataGridDlg : public CDialog
{
// Construction
public:
	CDataGridDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDataGridDlg)
	enum { IDD = IDD_DATAGRID_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataGridDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDataGridDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAGRIDDLG_H__A768AB82_E720_4E23_BAAD_3BE6662777B0__INCLUDED_)
