// AStarZbbDoc.h : interface of the CAStarZbbDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASTARZBBDOC_H__D35E6D31_E2C7_4805_BEF7_0C81EFDE4729__INCLUDED_)
#define AFX_ASTARZBBDOC_H__D35E6D31_E2C7_4805_BEF7_0C81EFDE4729__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAStarZbbDoc : public CDocument
{
protected: // create from serialization only
	CAStarZbbDoc();
	DECLARE_DYNCREATE(CAStarZbbDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAStarZbbDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAStarZbbDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAStarZbbDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASTARZBBDOC_H__D35E6D31_E2C7_4805_BEF7_0C81EFDE4729__INCLUDED_)
