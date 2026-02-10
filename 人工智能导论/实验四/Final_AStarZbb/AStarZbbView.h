// AStarZbbView.h : interface of the CAStarZbbView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASTARZBBVIEW_H__DA52C85A_FA2A_4DAE_A230_5AF3BF89EEE7__INCLUDED_)
#define AFX_ASTARZBBVIEW_H__DA52C85A_FA2A_4DAE_A230_5AF3BF89EEE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "AStarPathFind.h"


class CAStarZbbView : public CScrollView
{

private:
//	PathNode *ptPath;
	int m_nPathNum;

protected: // create from serialization only
	CAStarZbbView();
	DECLARE_DYNCREATE(CAStarZbbView)

// Attributes
public:
	CAStarZbbDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest6View)
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	virtual void OnStartPoint();
	virtual void OnEndPoint();
	virtual void OnBlock();
	virtual void OnUpdateStartPoint(CCmdUI*pCmdUI);
	virtual void OnUpdateEndPoint(CCmdUI*pCmdUI);    
	virtual void OnUpdateBlock(CCmdUI*pCmdUI);
    virtual void OnInitialUpdate();
	
	virtual void OnLButtonUp(UINT nFlags, CPoint point);
    virtual void OnGo();
	virtual void OnRefresh();	
	virtual void OnSize(UINT nType, int cx, int cy);

	virtual void OnNewMap();
	virtual void OnOpenMap();
	virtual void OnSaveMap();
	virtual void OnSaveMapAs();

	void OnGoByStepStart();
	void OnGoBySteping();
	void OnGoByStepEnd();

	virtual BOOL IsModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAStarZbbView();

#ifdef _DEBUG

	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

#endif


private:
	void ImporrtPic( CDC *pDC );   //载入图片


private:
	
	int m_Map[MAPWIDTH][MAPHEIGHT];  //保存地图
	int m_PathDirMap[MAPWIDTH][MAPHEIGHT];  //保存路径方向
	POINT m_ptStart;
	POINT m_ptEnd;
	int m_nFlag;
	CStatusBar* m_pStatusBar;
	CString m_strFileName;
	CRect m_rectClient;
	BOOL m_bIsModified;

	CAStarPathFind m_cPathfind;

	PATHLIST m_PathList;
	
//////////////////////////////////////////////////////////////////////////
// 绘图相关
//////////////////////////////////////////////////////////////////////////


	CDC m_BackDC;
	CDC m_StoneDC;
	CDC m_StartDC;
	CDC m_GoalDC;
	CDC m_DirDC[9];

	CDC m_CloseDir[8];
	CDC m_PathBmp[8];

	NODE* m_pOpenList;
	NODE* m_pCloseList;


	//画出开放表，关闭表,及当前遍历点
	void DrawCurrentFinding();

	int GetDirToParent( NODE* pNode);


	void ClearPath()
	{
		if( m_nPathNum > 0 )
		{
			int totalNum = m_PathList.size();
			for( int index = 0 ;index < totalNum; index++ ) 
			{
				delete m_PathList[index];
			}
			m_PathList.clear();
			m_nPathNum = 0;
		}
	}


// Generated message map functions
protected:
	//{{AFX_MSG(CAStarZbbView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in AStarZbbView.cpp

    inline CAStarZbbDoc* CAStarZbbView::GetDocument()
	{ 
		return (CAStarZbbDoc*)m_pDocument; 
	}
	
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASTARZBBVIEW_H__DA52C85A_FA2A_4DAE_A230_5AF3BF89EEE7__INCLUDED_)
