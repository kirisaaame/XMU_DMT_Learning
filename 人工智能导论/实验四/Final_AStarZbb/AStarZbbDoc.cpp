// AStarZbbDoc.cpp : implementation of the CAStarZbbDoc class
//

#include "stdafx.h"
#include "AStarZbb.h"

#include "AStarZbbDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbDoc

IMPLEMENT_DYNCREATE(CAStarZbbDoc, CDocument)

BEGIN_MESSAGE_MAP(CAStarZbbDoc, CDocument)
	//{{AFX_MSG_MAP(CAStarZbbDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbDoc construction/destruction

CAStarZbbDoc::CAStarZbbDoc()
{
	// TODO: add one-time construction code here

}

CAStarZbbDoc::~CAStarZbbDoc()
{
}

BOOL CAStarZbbDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAStarZbbDoc serialization

void CAStarZbbDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbDoc diagnostics

#ifdef _DEBUG
void CAStarZbbDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAStarZbbDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbDoc commands
