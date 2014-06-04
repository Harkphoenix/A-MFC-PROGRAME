//Download by http://www.NewXing.com
// DataGrid.h : main header file for the DATAGRID application
//

#if !defined(AFX_DATAGRID_H__6E71FD5F_ECA3_4B10_AA5D_5BBE46820706__INCLUDED_)
#define AFX_DATAGRID_H__6E71FD5F_ECA3_4B10_AA5D_5BBE46820706__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataGridApp:
// See DataGrid.cpp for the implementation of this class
//

class CDataGridApp : public CWinApp
{
public:
	CDataGridApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataGridApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDataGridApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAGRID_H__6E71FD5F_ECA3_4B10_AA5D_5BBE46820706__INCLUDED_)
