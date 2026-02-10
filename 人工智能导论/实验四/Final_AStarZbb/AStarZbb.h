// AStarZbb.h : main header file for the ASTARZBB application
//

#if !defined(AFX_ASTARZBB_H__C179CE77_E9A3_45D2_B30C_90A71B843B8D__INCLUDED_)
#define AFX_ASTARZBB_H__C179CE77_E9A3_45D2_B30C_90A71B843B8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbApp:
// See AStarZbb.cpp for the implementation of this class
//

class CAStarZbbApp : public CWinApp
{
public:
	CAStarZbbApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAStarZbbApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAStarZbbApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASTARZBB_H__C179CE77_E9A3_45D2_B30C_90A71B843B8D__INCLUDED_)
