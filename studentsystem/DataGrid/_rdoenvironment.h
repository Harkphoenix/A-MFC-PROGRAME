//Download by http://www.NewXing.com
#if !defined(AFX__RDOENVIRONMENT_H__50532EAF_80D2_49BE_BC8B_C166E045506E__INCLUDED_)
#define AFX__RDOENVIRONMENT_H__50532EAF_80D2_49BE_BC8B_C166E045506E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CrdoConnections;
class C_rdoConnection;
class C_rdoEngine;

/////////////////////////////////////////////////////////////////////////////
// C_rdoEnvironment wrapper class

class C_rdoEnvironment : public COleDispatchDriver
{
public:
	C_rdoEnvironment() {}		// Calls COleDispatchDriver default constructor
	C_rdoEnvironment(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	C_rdoEnvironment(const C_rdoEnvironment& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CrdoConnections GetRdoConnections();
	CString GetName();
	CString GetUserName_();
	void SetUserName(LPCTSTR lpszNewValue);
	void SetPassword(LPCTSTR lpszNewValue);
	long GetLoginTimeout();
	void SetLoginTimeout(long nNewValue);
	long GetCursorDriver();
	void SetCursorDriver(long nNewValue);
	long GetHEnv();
	void BeginTrans();
	void Close();
	void CommitTrans();
	void RollbackTrans();
	C_rdoConnection OpenConnection(LPCTSTR dsName, const VARIANT& Prompt, const VARIANT& Readonly, const VARIANT& Connect, const VARIANT& Options);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__RDOENVIRONMENT_H__50532EAF_80D2_49BE_BC8B_C166E045506E__INCLUDED_)