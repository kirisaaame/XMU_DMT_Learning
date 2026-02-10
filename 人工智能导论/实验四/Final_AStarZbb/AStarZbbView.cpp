// AStarZbbView.cpp : implementation of the CAStarZbbView class
//

#include "stdafx.h"
#include "AStarZbb.h"
#include <crtdbg.h> 
#include "AStarZbbDoc.h"
#include "AStarZbbView.h"
#include "MainFrm.h"

#include ".\astarzbbview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbView

IMPLEMENT_DYNCREATE(CAStarZbbView, CScrollView)

BEGIN_MESSAGE_MAP(CAStarZbbView, CScrollView)
	//{{AFX_MSG_MAP(CAStarZbbView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_START_POINT, OnStartPoint)
	ON_UPDATE_COMMAND_UI(ID_START_POINT,OnUpdateStartPoint)

	ON_COMMAND(ID_GO,OnGo)
	ON_COMMAND(ID_GOSTEP,OnGoByStepStart)

	ON_COMMAND(ID_BLOCK,OnBlock)
	ON_UPDATE_COMMAND_UI(ID_BLOCK,OnUpdateBlock)
	ON_COMMAND(ID_END_POINT,OnEndPoint)
	ON_UPDATE_COMMAND_UI(ID_END_POINT,OnUpdateEndPoint)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_REFRESH,OnRefresh)
	ON_WM_SIZE()
	ON_COMMAND(ID_NEW_MAP,OnNewMap)
	ON_COMMAND(ID_OPEN_MAP,OnOpenMap)
	ON_COMMAND(ID_SAVE_MAP,OnSaveMap)
	ON_COMMAND(ID_SAVE_MAP_AS,OnSaveMapAs)
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbView construction/destruction

// 定义初始值
CAStarZbbView::CAStarZbbView()
{
	 for ( int i=0; i<MAPHEIGHT; i++)
		 for ( int j=0; j<MAPWIDTH; j++)
			m_Map[i][j]   =  0;

		    m_ptStart.x   =  -1;
		    m_ptStart.y   =  0;
		    m_ptEnd.x     =  -1;
		    m_ptEnd.y     =  0;
		    m_nFlag       =  ENone;
		    m_pStatusBar  =  NULL;
		    m_bIsModified =  FALSE;
		    m_strFileName = "Newmap.map";
			m_nPathNum=0;


}


CAStarZbbView::~CAStarZbbView()
{
	
}


BOOL CAStarZbbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREARUCT cs


	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbView drawing

// 画地图
void CAStarZbbView::OnDraw(CDC* pDC)
{

	CAStarZbbDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i,j;

	for ( i=0; i<=MAPWIDTH; i++)
	{
		for ( j=0; j<=MAPHEIGHT; j++)
		{
			//画背景
			pDC->BitBlt( TILEWIDTH * i, TILEWIDTH *j ,32,32,&m_BackDC,0,0,SRCCOPY);
		}
		
	}
	

	for ( i=0; i<MAPHEIGHT; i++) 
		for ( j=0; j<MAPWIDTH; j++)	
			if ( m_Map[i][j] == 1)
			{
				// 画出障碍物
				pDC->BitBlt(j*TILEWIDTH, i*TILEHEIGHT,32,32,&m_StoneDC,0,32,SRCAND);
				pDC->BitBlt(j*TILEWIDTH, i*TILEHEIGHT,32,32,&m_StoneDC,0,0,SRCPAINT);			

			}
   
	for ( i=1; i<m_nPathNum-1; i++)
	{	
		// 画出路径
		pDC->BitBlt(m_PathList[i]->x*TILEWIDTH, m_PathList[i]->y*TILEHEIGHT,32,32,&m_DirDC[8],0,0,SRCAND);
		pDC->BitBlt(m_PathList[i]->x*TILEWIDTH, m_PathList[i]->y*TILEHEIGHT,32,32,&m_DirDC[m_PathList[i]->Dir-1],0,0,SRCPAINT);
	
	}
	
 
	if ( m_ptStart.x>=0 )
	{
		//画出起始点
		pDC->BitBlt(m_ptStart.x*TILEWIDTH, m_ptStart.y*TILEHEIGHT,32,32,&m_StartDC,0,32,SRCAND);
		pDC->BitBlt(m_ptStart.x*TILEWIDTH, m_ptStart.y*TILEHEIGHT,32,32,&m_StartDC,0,0,SRCPAINT);	

	}
		
	if ( m_ptEnd.x>=0 ) 
	{
		//画出目标点
		pDC->BitBlt(m_ptEnd.x*TILEWIDTH, m_ptEnd.y*TILEHEIGHT,32,32,&m_GoalDC,0,32,SRCAND);
		pDC->BitBlt(m_ptEnd.x*TILEWIDTH, m_ptEnd.y*TILEHEIGHT,32,32,&m_GoalDC,0,0,SRCPAINT);	
		
	}

	//如果是一步步地寻路，则画出当前寻路状况
	if( m_nFlag == EGoByStep || m_nFlag == EFindPath || m_nFlag == EShowPath)
	{
 		DrawCurrentFinding();
	}

}

/////////////////////////////////////////////////////////////////////////////
// CAStarZbbView printing

void CAStarZbbView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	
	CSize sizeTotal;
	sizeTotal.cx = MAPWIDTH * TILEWIDTH+1;
	sizeTotal.cy = MAPHEIGHT * TILEHEIGHT+1;
	SetScrollSizes(MM_TEXT, sizeTotal, sizeDefault, CSize(TILEWIDTH,TILEHEIGHT));

	m_pStatusBar = &((CMainFrame*)AfxGetMainWnd())->m_wndStatusBar;

	CDC *pDC=AfxGetMainWnd()->GetDC();
	if(pDC==NULL)
		return;

	ImporrtPic( pDC );

	
}


//载入图片
void CAStarZbbView::ImporrtPic( CDC *pDC )
{

	m_BackDC.CreateCompatibleDC(pDC);
	CBitmap backBmp;
	backBmp.LoadBitmap(BACK_IMP);
	m_BackDC.SelectObject(&backBmp);

	m_StoneDC.CreateCompatibleDC(pDC);
	CBitmap stoneBmp;
	stoneBmp.LoadBitmap(STONE_IMP);
	m_StoneDC.SelectObject(&stoneBmp);

	m_StartDC.CreateCompatibleDC(pDC);
	CBitmap startBmp;
	startBmp.LoadBitmap(START_IMP);
	m_StartDC.SelectObject(&startBmp);

	m_GoalDC.CreateCompatibleDC(pDC);
	CBitmap goalBmp;
	goalBmp.LoadBitmap(GOAL_IMP);
	m_GoalDC.SelectObject(&goalBmp);

	for( int i = 0 ;i<= 8 ;i++)
	{
		m_DirDC[i].CreateCompatibleDC(pDC);
		CBitmap temp;
		temp.LoadBitmap( 153+i );
		m_DirDC[i].SelectObject(&temp);

	}

	for( int j = 0 ;j<= 7 ;j++)
	{
		m_CloseDir[j].CreateCompatibleDC(pDC);
		CBitmap temp;
		temp.LoadBitmap( 162+j );
		m_CloseDir[j].SelectObject(&temp);

		m_PathBmp[j].CreateCompatibleDC(pDC);
		CBitmap temp1;
		temp1.LoadBitmap( 174+j );
		m_PathBmp[j].SelectObject(&temp1);

	}


}


BOOL CAStarZbbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CAStarZbbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}


void CAStarZbbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


/////////////////////////////////////////////////////////////////////////////
// CAStarZbbView diagnostics

#ifdef _DEBUG

void CAStarZbbView::AssertValid() const
{
	CScrollView::AssertValid();
}


void CAStarZbbView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}


CAStarZbbDoc* CAStarZbbView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAStarZbbDoc)));
	return (CAStarZbbDoc*)m_pDocument;
}

#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CAStarZbbView message handlers

// 标志、更新 （障碍物、起始点和目标点）
void CAStarZbbView::OnBlock()
{
	m_nFlag = EBlock;

}

void CAStarZbbView::OnUpdateBlock(CCmdUI*pCmdUI)
{
	pCmdUI->SetCheck(m_nFlag == EBlock);
	
}

void CAStarZbbView::OnStartPoint()
{
	m_nFlag = EStart;
	
}

void CAStarZbbView::OnUpdateStartPoint(CCmdUI*pCmdUI)
{
	pCmdUI->SetCheck(m_nFlag == EStart);
	
}

void CAStarZbbView::OnEndPoint()
{
	m_nFlag = EGoal;

}

void CAStarZbbView::OnUpdateEndPoint(CCmdUI*pCmdUI)
{
	pCmdUI->SetCheck(m_nFlag == EGoal);

}

void CAStarZbbView::OnGoByStepStart()
{
	if ( m_ptStart.x<0 || m_ptEnd.x<0)
	{
		AfxMessageBox("请先选择起始点和终点！\n");
		return;

	}

	ClearPath();

	CDC *pDC = GetDC();
	pDC->SetWindowOrg(GetScrollPosition());		

	m_nFlag = EGoByStep;
	DWORD time = GetTickCount();

	m_cPathfind.SetData(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y,1,1);
	m_cPathfind.SetMapData((int*)m_Map, MAPWIDTH, MAPHEIGHT,1,1);

	m_cPathfind.BeginPathFind();

	m_cPathfind.SetDrawDC(pDC);

	m_cPathfind.SetPathDC(&m_GoalDC);

	m_pOpenList = m_cPathfind.GetOpenList();
	m_pCloseList = m_cPathfind.GetCloseList();

}

void CAStarZbbView::OnGoBySteping()
{
	if( m_nFlag == EGoByStep )
	{
		Invalidate(false);
		CDC *pDC = GetDC();
		m_cPathfind.SetDrawDC( pDC);

		DrawCurrentFinding();
		m_nPathNum = m_cPathfind.PathFindByStep(m_PathList);
	

		if ( m_nPathNum> 0)//int m_nPathNum;  POINT *ptPath; 在头文件里已定义
		{

 			m_nFlag = EFindPath;

		}
	}

	else if ( m_nFlag == EFindPath)
	{
		CDC *pDC = GetDC();
		pDC->SetWindowOrg(GetScrollPosition());		

		m_nFlag = EShowPath;

		for( int i = 0; i < m_PathList.size() ; i++ )
		{
			m_Map[m_PathList[i]->y][m_PathList[i]->x] = 2; // 表路径

		}

		DrawCurrentFinding();

		
	}

	else if ( m_nFlag == EShowPath )
	{
		
   		CDC *pDC = GetDC();
		pDC->SetWindowOrg(GetScrollPosition());	

		m_nFlag = ENone;

		//反转路径

		for( int j = 0; j < m_PathList.size(); j++ )
		{
			m_PathList[j]->Dir = (m_PathList[j]->Dir + 4) % 8 ;
		}

		m_cPathfind.FreeLink( m_pOpenList);
		m_cPathfind.FreeLink( m_pCloseList);

		Invalidate(false);
		
	}

}

//画出当前寻路状况

void CAStarZbbView::DrawCurrentFinding()
{
	CDC *pDC = GetDC();
	pDC->SetWindowOrg(GetScrollPosition());	

	NODE* temp ;

	temp = m_pOpenList->pNext;

	while( temp )
	{
		CBrush brush0( RGB(255,0,0) );
		pDC->SelectObject(&brush0);	

		int Dir = GetDirToParent( temp );

		if( Dir != -1)
		{
			pDC->BitBlt(temp->x*TILEWIDTH, temp->y*TILEHEIGHT,32,32,&m_DirDC[8],0,0,SRCAND);
			pDC->BitBlt(temp->x*TILEWIDTH, temp->y*TILEHEIGHT,32,32,&m_DirDC[Dir-1],0,0,SRCPAINT);


			CString msg;
			msg.Format("%d",(temp->g + temp->h) );

			pDC->SetBkMode(TRANSPARENT);

			pDC->SetTextColor( RGB(255,255,255) );
			pDC->TextOut(temp->x*TILEWIDTH,temp->y*TILEHEIGHT,msg);

		}

		temp = temp->pNext;
	}

	temp = m_pCloseList->pNext;

	if( temp)
	{
		CBrush brush0( RGB(0,0,255) );
		pDC->SelectObject(&brush0);		
		pDC->Rectangle ( temp->x*TILEWIDTH, temp->y*TILEHEIGHT, (temp->x+1)*TILEWIDTH+1, (temp->y+1) *TILEHEIGHT+1);

		temp = temp->pNext;
		
	}

	while( temp)
	{
		CBrush brush0( RGB(255,0,0) );
		pDC->SelectObject(&brush0);	

		int Dir = GetDirToParent( temp );

		if( Dir != -1)
		{
			pDC->BitBlt(temp->x*TILEWIDTH, temp->y*TILEHEIGHT,32,32,&m_DirDC[8],0,0,SRCAND);
			pDC->BitBlt(temp->x*TILEWIDTH, temp->y*TILEHEIGHT,32,32,&m_CloseDir[Dir-1],0,0,SRCPAINT);
			

			CString msg;
			msg.Format("%d",(temp->g + temp->h) );

			pDC->SetBkMode(TRANSPARENT);

			pDC->SetTextColor( RGB(255,255,255) );
			pDC->TextOut(temp->x*TILEWIDTH,temp->y*TILEHEIGHT,msg);

		}

		temp = temp->pNext;

	}

	if( m_nFlag == EShowPath )
	{
		
		for( int i = 1; i < m_PathList.size() - 1; i++ )
		{
			pDC->BitBlt(m_PathList[i]->x*TILEWIDTH, m_PathList[i]->y*TILEHEIGHT,32,32,&m_DirDC[8],0,0,SRCAND);
			pDC->BitBlt(m_PathList[i]->x*TILEWIDTH, m_PathList[i]->y*TILEHEIGHT,32,32,&m_PathBmp[m_PathList[i]->Dir-1],0,0,SRCPAINT);	
		}
	}


}


int CAStarZbbView::GetDirToParent( NODE* pNode)
{
	if( !pNode || !pNode->pParent )
	 return -1;

	int dx = pNode->x - pNode->pParent->x;
	int dy = pNode->y - pNode->pParent->y;

	if( dx == 0 )
	{
		if( dy > 0 )
		{
			return EUp;
		}
		else
		{
			return EDown;
		}

	}

	if( dy == 0 )
	{
		if( dx > 0)
		{
			return ELeft;
		}
		else
		{
			return ERight;
		}

	}

	if( dx > 0 )
	{
		if( dy > 0 )
		{
			return EUpLeft;
		}
		else
		{
			return EDownLeft;
		}

	}

	if( dx < 0 )
	{
		if( dy > 0 )
		{
			return EUpRight;
		}
		else
		{
			return EDownRight;
		}

	}
	
	
}


//实现最优路径搜索，并将所得路径表为红色。
void CAStarZbbView::OnGo()
{
	if ( m_ptStart.x<0 || m_ptEnd.x<0)
	{
		AfxMessageBox("请先选择起始点和终点！\n");
		return;
		
	}

	ClearPath();

	CDC *pDC = GetDC();
	pDC->SetWindowOrg(GetScrollPosition());		

	m_nFlag = ENone;
	DWORD time = GetTickCount();
		
	CAStarPathFind pathfind(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y,1,1);
	pathfind.SetMapData((int*)m_Map, MAPWIDTH, MAPHEIGHT,1,1);

	pathfind.BeginPathFind();


	if ((m_nPathNum = pathfind.PathFind(m_PathList)) > 0)//int m_nPathNum;  POINT *ptPath; 在头文件里已定义
	{
		m_nPathNum = m_PathList.size();
		CString str;
		str.Format("共耗时%d毫秒，需走%d步",GetTickCount()-time, m_nPathNum);
		m_pStatusBar->SetPaneText(1,str);

		for( int j = 0; j < m_PathList.size(); j++ )
		{
			m_PathList[j]->Dir = (m_PathList[j]->Dir + 4) % 8 ;
		}
		
		for (int i=1; i<m_nPathNum-1; i++)
		{
			m_Map[m_PathList[i]->y][m_PathList[i]->x] = 2; // 表路径

			CDC *pDC = GetDC();
			pDC->SetWindowOrg(GetScrollPosition());			

			// 标出路径，带有方向箭头
			pDC->BitBlt(m_PathList[i]->x*TILEWIDTH, m_PathList[i]->y*TILEHEIGHT,32,32,&m_DirDC[8],0,0,SRCAND);
			pDC->BitBlt(m_PathList[i]->x*TILEWIDTH, m_PathList[i]->y*TILEHEIGHT,32,32,&m_DirDC[m_PathList[i]->Dir-1],0,0,SRCPAINT);	
			
		}

	}
	
	else 
		AfxMessageBox("没有找到最佳路径");


}


// 鼠标左键实现判断选择 
void CAStarZbbView::OnLButtonUp(UINT nFlags, CPoint point)
{
	int i, j;
	point += GetScrollPosition();

	CDC *pDC = GetDC();
	pDC->SetWindowOrg(GetScrollPosition());
	
	switch (m_nFlag) // 判断后画出（障碍物、起始点、目标点）
	{
		//障碍物处理
		case EBlock:
			m_bIsModified = TRUE;
			i = point.x/TILEWIDTH;
			j = point.y/TILEHEIGHT;

			// 消除障碍物
			if (m_Map[j][i]>0)   
			{
				m_Map[j][i] = 0;
				
				//画背景图
				pDC->BitBlt( TILEWIDTH * i, TILEHEIGHT *j ,32,32,&m_BackDC,0,0,SRCCOPY);
				
			}
			
			//生成障碍物
			else		
			{
				m_Map[j][i] = 1;				

				//画出障碍物
				pDC->BitBlt(i*TILEWIDTH, j*TILEHEIGHT,32,32,&m_StoneDC,0,32,SRCAND);
				pDC->BitBlt(i*TILEWIDTH, j*TILEHEIGHT,32,32,&m_StoneDC,0,0,SRCPAINT);
				
               // 更新障碍物时清除路径
				if(m_nPathNum!=0)
				{
					for (int i=1; i<m_nPathNum-1; i++)
						m_Map[m_PathList[i]->y][m_PathList[i]->x] = 0; 

					 ClearPath();

					Invalidate();

				}
			
			}

			break;

		//起始点处理
        case EStart:   
			m_bIsModified = TRUE;
			
			//生成起始点
			if (m_ptStart.x>=0)    
			{
				//画背景图
				pDC->BitBlt( m_ptStart.x*TILEWIDTH, m_ptStart.y*TILEHEIGHT ,32,32,&m_BackDC,0,0,SRCCOPY);  
			
			}

			m_ptStart.x  =  point.x/TILEWIDTH;
			m_ptStart.y  =  point.y/TILEHEIGHT;

			//画出起始点
			pDC->BitBlt(m_ptStart.x*TILEWIDTH, m_ptStart.y*TILEHEIGHT,32,32,&m_StartDC,0,32,SRCAND);
			pDC->BitBlt(m_ptStart.x*TILEWIDTH, m_ptStart.y*TILEHEIGHT,32,32,&m_StartDC,0,0,SRCPAINT);	

		
			// 更新起始点时清除路径
			if(m_nPathNum!=0)
			{
				for (int i=1; i<m_nPathNum-1; i++)
					m_Map[m_PathList[i]->y][m_PathList[i]->x] = 0; 

				 ClearPath();

				Invalidate();
				
			}

			break;

		//目标点处理
		case EGoal:       
			m_bIsModified = TRUE;

			// 生成目标点
			if (m_ptEnd.x>=0)
			{
				//画背景图
				pDC->BitBlt( m_ptEnd.x*TILEWIDTH, m_ptEnd.y*TILEHEIGHT ,32,32,&m_BackDC,0,0,SRCCOPY);  
			
			}
			
			m_ptEnd.x  =  point.x/TILEWIDTH;			
			m_ptEnd.y  =  point.y/TILEHEIGHT;			

			//画出目标点
			pDC->BitBlt( m_ptEnd.x*TILEWIDTH, m_ptEnd.y*TILEHEIGHT,32,32,&m_GoalDC,0,32,SRCAND );
			pDC->BitBlt( m_ptEnd.x*TILEWIDTH, m_ptEnd.y*TILEHEIGHT,32,32,&m_GoalDC,0,0,SRCPAINT );	
			
			// 更新目标点时清除路径
			if(m_nPathNum!=0)
			{
				for (int i=1; i<m_nPathNum-1; i++)
					m_Map[m_PathList[i]->y][m_PathList[i]->x] = 0; 

				ClearPath();

				Invalidate();

			}

			break;	

	}
	
	ReleaseDC(pDC);
	
	CScrollView::OnLButtonUp( nFlags, point);

}


// 限定搜索范围
void CAStarZbbView::OnSize(UINT nType, int cx, int cy)
{
	
	CScrollView::OnSize(nType,cx,cy);
	
    GetClientRect(&m_rectClient);
	
}


// 刷新地图，只保留障碍物
void CAStarZbbView::OnRefresh()
{
	   // 清除路径
		for (int i=1; i<m_nPathNum-1; i++)
			m_Map[m_PathList[i]->y][m_PathList[i]->x] = 0; 

		ClearPath();
	    	
		   //清除点
		    m_ptStart.x   = -1;
		    m_ptStart.y   =  0;
	        m_ptEnd.x     = -1;
		    m_ptEnd.y     =  0;
		    m_nFlag       =  ENone;
	        m_bIsModified =  FALSE;
		
       	    Invalidate();		

}


// 新建地图
void CAStarZbbView::OnNewMap()
{

	// 判断地图是否被更改，若更改则保存	
	if (IsModified())
	{
		CString str;
		str = "文件" + m_strFileName + "的正文已经更改。\n是否保存更改？";
		
    	int rval = MessageBox(str,"A*算法路径搜索", MB_YESNOCANCEL|MB_ICONWARNING);
		
		if (rval == IDCANCEL)
		   return;
		
		else if (rval == IDYES)
			OnSaveMap();
	
	} 
	
	
	// 将地图初始化
	for ( int i=0; i<MAPHEIGHT; i++)		
		for ( int j=0; j<MAPWIDTH; j++)
			m_Map[i][j]   =  0;		
	
	     m_ptStart.x   =  -1;
      	 m_ptStart.y   =  0;
    	 m_ptEnd.x     =  -1;
    	 m_ptEnd.y     =  0;
    	 m_nFlag       =  ENone;    	
    	 m_bIsModified =  FALSE;
		 m_strFileName = "Newmap.map";
		
		ClearPath();
				
    Invalidate();		
		
	AfxGetMainWnd()->SetWindowText("A*算法路径搜索 -- Newmap.map");

}


// 打开地图
void CAStarZbbView::OnOpenMap()
{
	
	// 判断是否更改，若更改则保存
	if (IsModified())
	{
		CString str;
		str = "文件" + m_strFileName + "的正文已经更改。\n" + "是否保存更改？";
    	int rval = MessageBox(str,"A*算法路径搜索", MB_YESNOCANCEL|MB_ICONWARNING);

		if (rval == IDCANCEL)
			return;
		
		else if (rval == IDYES)
			OnSaveMap();

	}

	OnRefresh(); //清空数据

	// 选择并读出所选地图
	CFileDialog  dlg(TRUE,_T("map"),NULL,OFN_PATHMUSTEXIST,_T("Map Files(*.map)|*.map||"),this);

	if (dlg.DoModal() == IDOK)
	{
		m_nFlag = ENone;
		m_strFileName = dlg.GetPathName();

		CFile file(m_strFileName,CFile::modeRead);
         file.Read(&m_ptStart, sizeof(POINT));
         file.Read(&m_ptEnd, sizeof(POINT));

		for ( int i=0; i<MAPHEIGHT; i++)			
			for ( int j=0; j<MAPWIDTH; j++)					
				file.Read(&m_Map[i][j], sizeof(int));

        Invalidate();
		
		CString strTitle;
		strTitle = "A*算法路径搜索--" + dlg.GetFileName();
		AfxGetMainWnd()->SetWindowText(strTitle);
		m_bIsModified = FALSE;
		
	}

}


// 保存地图（将所选地图写入）
void CAStarZbbView::OnSaveMap()
{
    CFile file(m_strFileName,CFile::modeCreate|CFile::modeWrite);
	 file.Write(&m_ptStart, sizeof(POINT));
	 file.Write(&m_ptEnd, sizeof(POINT));

	for ( int i=0; i<MAPHEIGHT; i++)			
		for ( int j=0; j<MAPWIDTH; j++)					
			file.Write(&m_Map[i][j], sizeof(int));

	m_bIsModified = FALSE;
		
}

// 地图另存为
void CAStarZbbView::OnSaveMapAs()
{
	CFileDialog  dlg(FALSE,_T("map"),NULL,OFN_PATHMUSTEXIST,_T("Map Files(*.map)|*.map||"),this);
    
	if (dlg.DoModal() == IDOK)
	{
		m_bIsModified = FALSE;
		m_strFileName = dlg.GetPathName();
		OnSaveMap();

		CString strTitle;
		strTitle = "A*算法路径搜索--" + dlg.GetFileName();
		AfxGetMainWnd()->SetWindowText(strTitle);
	
	}

}

BOOL CAStarZbbView::IsModified()
{

	return   m_bIsModified;
	
}

void CAStarZbbView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if( nChar == VK_SPACE && ( m_nFlag == EGoByStep || m_nFlag == EShowPath || m_nFlag == EFindPath) )
	{
		OnGoBySteping();
	}

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}


