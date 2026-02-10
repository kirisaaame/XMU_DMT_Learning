//AStarPathFind.h:header file

#ifndef _ASTARPATHFIND_H
#define _ASTARPATHFIND_H

#include"assert.h"



class CAStarPathFind

{
	
public:
	CAStarPathFind(){};
	CAStarPathFind(int xStart,int yStart,int xEnd,int yEnd,int xSpeed,int ySpeed);
	CAStarPathFind(POINT ptStart,POINT ptEnd,int xSpeed,int ySpeed);
	~CAStarPathFind();
	int PathFind( PATHLIST& ptPathList );
	void SetMapData(int *Map,int nMapWidth,int nMapHeight,int nTileWidth,int nTileHeight);

	void BeginPathFind();
	int  PathFindByStep( PATHLIST& ptPathList );

	void FreeLink (NODE *pHead); // 释放链表

	void SetDrawDC( CDC *pDC) { m_pDC = pDC; }
	void SetPathDC( CDC *pDC) { m_pGoalDC = pDC; }

	void SetData(int xStart,int yStart,int xEnd,int yEnd,int xSpeed,int ySpeed);

	NODE* GetOpenList() { return m_pOpenHead; }
	NODE* GetCloseList() { return m_pClosedHead; }

	
	
	
private:
	
		int  m_xStart,m_yStart; // 起始点坐标
	    int  m_xEnd,m_yEnd; // 目标点坐标
	    int  m_xSpeed,m_ySpeed;  // XY方向上的移动速度

	    PathNode *m_ptPath;

    	int  H(int x,int y); // 评估函数
    	void ExpandPoint(POINT *pt,int x,int y); // 计算八个方向上的坐标点
		int GetDir( int x,int y, int PreX,int PreY);// 指针方向函数
    	void MakePath(NODE *pHead,int &num, PATHLIST& ptPathList); // 计算最佳路径，放到Pt数组中
    	


		// 地图长宽，单位网格（节点）长宽
    	int  m_nMapWidth,m_nMapHeight,m_nTileWidth,m_nTileHeight;
		int *m_Map;
    	int TileX(int x);
    	int TileY(int y);	


		//寻路用
		NODE *m_pNode,*m_pPre,*m_pNext,*m_pOpenHead,*m_pClosedHead;

		CDC  *m_pDC;
		CDC  *m_pGoalDC;
		
	
};

#endif