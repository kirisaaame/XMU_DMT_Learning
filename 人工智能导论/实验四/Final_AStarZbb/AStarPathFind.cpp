
//AStarPathFind.cpp

#include "StdAfx.h"
#include "AStarPathFind.h"
#include <math.h>
// 定义地图上的点的坐标
CAStarPathFind::CAStarPathFind(int xStart,int yStart,int xEnd,int yEnd,int xSpeed,int ySpeed)
:m_xStart(xStart),m_yStart(yStart),m_xEnd(xEnd),m_yEnd(yEnd),m_xSpeed(xSpeed),m_ySpeed(ySpeed)

{
    m_Map =  NULL;
	m_ptPath = NULL;

}

// 定义路径指针
CAStarPathFind::CAStarPathFind(POINT ptStart,POINT ptEnd,int xSpeed,int ySpeed)
:m_xStart(ptStart.x),m_yStart(ptStart.y),m_xEnd(ptEnd.x),m_yEnd(ptEnd.y),m_xSpeed(xSpeed),m_ySpeed(ySpeed)

{
	m_Map  = NULL;
	
}

void CAStarPathFind::SetData(int xStart,int yStart,int xEnd,int yEnd,int xSpeed,int ySpeed)
{
	m_xStart = xStart; 
	m_yStart = yStart; 
	m_xEnd = xEnd; 
	m_yEnd = yEnd;
	m_xSpeed = xSpeed;
	m_ySpeed = ySpeed;

	m_Map =  NULL;
	m_ptPath = NULL;
}

CAStarPathFind::~CAStarPathFind()

{

}

// 评估函数
inline int CAStarPathFind::H(int x,int y)
{
	int dx = abs(m_xEnd - x);
	int  dy = abs(m_yEnd - y);
	int dis = abs( dx - dy);

	if( dx > dy )
	{
		return ( 14 * dy + 10 * dis); 
	}
	else
	{
		return ( 14 * dx + 10 * dis); 
	}

}

// 定义八个方向的拓展节点的坐标
inline void CAStarPathFind::ExpandPoint(POINT *pt,int x,int y)

{
	assert(pt!=NULL);
	pt[0].x=x-m_xSpeed;   pt[0].y=y-m_ySpeed;
	pt[1].x=x;            pt[1].y=y-m_ySpeed;
    pt[2].x=x+m_xSpeed;   pt[2].y=y-m_ySpeed;
    pt[3].x=x-m_xSpeed;   pt[3].y=y;
    pt[4].x=x+m_xSpeed;   pt[4].y=y;
	pt[5].x=x-m_xSpeed;   pt[5].y=y+m_ySpeed;
	pt[6].x=x;            pt[6].y=y+m_ySpeed;
	pt[7].x=x+m_xSpeed;   pt[7].y=y+m_ySpeed;

}

// 形成最佳路径指针链表
void CAStarPathFind::MakePath(NODE *pHead,int &num, PATHLIST& ptPathList)
{
	bool b_First = true;

	ptPathList.clear();

	num= 0;

	int PreX,PreY;

	assert(pHead!=NULL);

	NODE *pTemp = pHead;

	while ( pTemp )
	{
		PathNode *pt=new PathNode();
		(*pt).x = pTemp->x;
		(*pt).y = pTemp->y;        

		 if( b_First )
		 {
			 PreX = pTemp->x;
			 PreY = pTemp->y;
			 b_First = false;
		 }
		 else 
		 {
			pt->Dir = GetDir( PreX,PreY,pt->x,pt->y);
			PreX = pt->x;
			PreY = pt->y;
		 }

		  ptPathList.push_back(pt);
		  num++;
		  pTemp = pTemp->pParent; 

	}
	
}




// 标出每个节点上的路径指针方向
int CAStarPathFind::GetDir( int x,int y, int PreX,int PreY)
{

	int dx = x - PreX;
	int dy = y - PreY;

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

void CAStarPathFind::FreeLink(NODE *pHead)
{

	NODE *pNode;

	while ( pHead )
	{
		pNode = pHead;
		pHead = pHead->pNext;
		free(pNode);
	}

}

void CAStarPathFind::BeginPathFind()
{
	assert(m_Map !=NULL);
	
	m_pOpenHead =(NODE*)malloc(sizeof(NODE));
	m_pNext = (NODE*)malloc(sizeof(NODE));
	m_pNext->x=m_xStart;
	m_pNext->y=m_yStart;
	m_pNext->g=1;
	m_pNext->h=H(m_xStart,m_yStart);
	m_pNext->pParent = NULL;
	m_pNext->pNext = NULL;
	m_pOpenHead->pNext = m_pNext;
	m_pOpenHead->pParent = NULL;
	m_pClosedHead = (NODE*)malloc(sizeof(NODE));
	m_pClosedHead->pParent = NULL;
	m_pClosedHead->pNext = NULL;


}

int CAStarPathFind::PathFindByStep( PATHLIST& ptPathList )
{
	if(m_pOpenHead->pNext!=NULL)
	{
		m_pNode = m_pOpenHead->pNext;

		if (m_pNode->x==m_xEnd && m_pNode->y==m_yEnd)

		{
			int nNum;

			m_pOpenHead->pNext = m_pNode->pNext;
			m_pNode->pNext = m_pClosedHead->pNext;
			m_pClosedHead->pNext = m_pNode;	
			
			MakePath(m_pNode,nNum,ptPathList);

			m_pOpenHead = NULL;
			m_pClosedHead = NULL;


			return nNum;

		}

		bool bFlag;

		POINT pt[8];

		ExpandPoint(pt,m_pNode->x,m_pNode->y); // 计算八个方向的坐标点

		// 利用评估函数选取最小值点作为下一步的拓展点
		for(int i=0; i<8; i++)

		{
			int x = TileX(pt[i].x);
			int y = TileY(pt[i].y);
			if (x<0||y<0||x>=m_nMapWidth||y>=m_nMapHeight||m_Map[y*m_nMapWidth+x]==1)
				continue;

			int  g ;
			if( i== 0 || i== 2 || i== 5 || i== 7 )
			{
				g = m_pNode->g + 14;
			}
			else
			{
				g = m_pNode->g + 10;
			}
			int  h = H(x,y);
			bFlag = FALSE;
			m_pPre = m_pNode;
			m_pNext = m_pNode->pNext;


			while (m_pNext!=NULL)

			{
				if (m_pNext->x == x && m_pNext->y == y) 

				{
					if (m_pNext->g<=g)

					{
						bFlag = TRUE;
						break;
					}

					else 

					{
						m_pPre->pNext = m_pNext->pNext;
						free(m_pNext);
						break;
					}

				}

				m_pPre = m_pNext;
				m_pNext = m_pNext->pNext;

			}

			if (!bFlag)

			{
				m_pPre = m_pClosedHead;
				m_pNext = m_pPre->pNext;

				while (m_pNext!=NULL)

				{
					if (m_pNext->x == x && m_pNext->y == y)

					{
						if (m_pNext->g<=g)

						{
							bFlag = TRUE;
							break;
						}

						else

						{
							m_pPre->pNext = m_pNext->pNext;
							free(m_pNext);
							break;
						}

					}

					m_pPre = m_pNext;
					m_pNext = m_pNext->pNext;

				}

			}

			if (!bFlag)

			{
				NODE *pPoint = (NODE*)malloc(sizeof(NODE));
				pPoint->x = x;
				pPoint->y = y;
				pPoint->g = g;
				pPoint->h = h;
				pPoint->pParent = m_pNode;
				m_pPre = m_pNode;
				m_pNext = m_pNode->pNext;

				while (m_pNext!=NULL)

				{
					if ((m_pNext->g+m_pNext->h)>(g+h))

					{
						m_pPre->pNext = pPoint;
						pPoint->pNext = m_pNext;
						break;
					}

					m_pPre = m_pNext;
					m_pNext = m_pNext->pNext;

				}

				if (m_pNext == NULL)

				{
					m_pPre->pNext = pPoint;
					pPoint->pNext = NULL;

				}

			}

		}

	
		m_pOpenHead->pNext = m_pNode->pNext;
		m_pNode->pNext = m_pClosedHead->pNext;
		m_pClosedHead->pNext = m_pNode;	
	}

	return  0;

}


// 搜索形成最佳路径的节点列表
int CAStarPathFind::PathFind( PATHLIST& ptPathList )

{ 
	assert(m_Map !=NULL);
	NODE *pNode,*pPre,*pNext,*pOpenHead,*pClosedHead;
	pOpenHead =(NODE*)malloc(sizeof(NODE));
	pNext = (NODE*)malloc(sizeof(NODE));
	pNext->x=m_xStart;
	pNext->y=m_yStart;
	pNext->g=0;
	pNext->h=H(m_xStart,m_yStart);
	pNext->pParent = NULL;
	pNext->pNext = NULL;
	pOpenHead->pNext = pNext;
	pOpenHead->pParent = NULL;
	pClosedHead = (NODE*)malloc(sizeof(NODE));
	pClosedHead->pParent = NULL;
	pClosedHead->pNext = NULL;

	while (pOpenHead->pNext!=NULL)

	{
		pNode = pOpenHead->pNext;

		if (pNode->x==m_xEnd && pNode->y==m_yEnd)

		{
			int nNum;
		
			MakePath(pNode,nNum,ptPathList);

			FreeLink(pOpenHead);
			pOpenHead = NULL;
			FreeLink(pClosedHead);
			pClosedHead = NULL;
			return nNum;

		}

		bool bFlag;

		POINT pt[8];
        
		ExpandPoint(pt,pNode->x,pNode->y); // 计算八个方向的坐标点

        // 利用评估函数选取最小值点作为下一步的拓展点
		for(int i=0; i<8; i++)

		{
			int x = TileX(pt[i].x);
			int y = TileY(pt[i].y);
			if (x<0||y<0||x>=m_nMapWidth||y>=m_nMapHeight||m_Map[y*m_nMapWidth+x]==1)
			continue;

			int  g ;
			if( i== 0 || i== 2 || i== 5 || i== 7 )
			{
				g = pNode->g + 14;
			}
			else
			{
				g = pNode->g + 10;
			}


			int  h = H(x,y);
			bFlag = FALSE;
			pPre = pNode;
			pNext = pNode->pNext;

			while (pNext!=NULL)
			
			{
				if (pNext->x == x && pNext->y == y) 

				{
					if (pNext->g <= g)
					{
						bFlag = TRUE;
						break;
					}
					
					else 
					{
						pPre->pNext = pNext->pNext;
						free(pNext);
						break;
					}
					
				}
				
				pPre = pNext;
				pNext = pNext->pNext;

			}

			if (!bFlag)

			{
				pPre = pClosedHead;
				pNext = pPre->pNext;

				while (pNext!=NULL)
					
				{
					if (pNext->x == x && pNext->y == y)
					
					{
						if (pNext->g<=g)
						
						{
							bFlag = TRUE;
							break;
						}

						else
						
						{
							pPre->pNext = pNext->pNext;
							free(pNext);
							break;
						}
					
					}
					
					pPre = pNext;
					pNext = pNext->pNext;

				}

			}

			if (!bFlag)
			
			{
				NODE *pPoint = (NODE*)malloc(sizeof(NODE));
				pPoint->x = x;
				pPoint->y = y;
				pPoint->g = g;
				pPoint->h = h;
				pPoint->pParent = pNode;
				pPre = pNode;
				pNext = pNode->pNext;

				while (pNext!=NULL)
				
				{
					if ((pNext->g+pNext->h)>(g+h))
					
					{
						pPre->pNext = pPoint;
						pPoint->pNext = pNext;
						break;
					}

					pPre = pNext;
					pNext = pNext->pNext;
					
				}

				if (pNext == NULL)
				
				{
					pPre->pNext = pPoint;
					pPoint->pNext = NULL;

				}

			}

		}

		pOpenHead->pNext = pNode->pNext;
		pNode->pNext = pClosedHead->pNext;
		pClosedHead->pNext = pNode;	
	
	}

	return  0;

}


//	设置地图有关数据
void CAStarPathFind::SetMapData(int *Map,int nMapWidth,int nMapHeight,int nTileWidth,int nTileHeight)

{
	assert(Map != NULL);

	if (m_Map != NULL)
		free(m_Map);

	m_Map         =   Map;
	m_nMapWidth   =   nMapWidth;
	m_nMapHeight  =   nMapHeight;
	m_nTileWidth  =   nTileWidth;
	m_nTileHeight =   nTileHeight;

}	

// 单位网格的大小
inline int CAStarPathFind::TileX(int x)	

{

	return  x/m_nTileWidth;

}			

inline int CAStarPathFind::TileY(int y)

{
	return  y/m_nTileHeight;
	

}
