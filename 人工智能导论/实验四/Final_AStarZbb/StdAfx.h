// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__8563B451_B231_4873_9551_0D6DBC553942__INCLUDED_)
#define AFX_STDAFX_H__8563B451_B231_4873_9551_0D6DBC553942__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#include <vector>
#endif // _AFX_NO_AFXCMN_SUPPORT



#define MAPWIDTH 80
#define MAPHEIGHT 80
#define TILEWIDTH 32
#define TILEHEIGHT 32



enum
{
	EUp = 1,
	EUpRight = 2,
	ERight = 3,
	EDownRight = 4,
	EDown = 5,
	EDownLeft = 6,
	ELeft = 7,
	EUpLeft = 8,
};

enum 
{
	ENone = 0,  //默认值
	EBlock = 1, //障碍
	EStart = 2,//起始
	EGoal = 3, //目标 
	EFindPath = 4,
	EShowPath = 5,
	EGoByStep = 6,
};

struct NODE
{  
	int x,y;   // 节点坐标(x,y)
	int g,h;   //  f(n)=g(n)+h(n)
	NODE *pParent; // 父节点
	NODE *pNext; // 下一个节点
};

struct PathNode
{
	int x;
	int y;
	int Dir;
	PathNode()
	{
		Dir = ENone;
	}

};

typedef std::vector<PathNode*> PATHLIST;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__8563B451_B231_4873_9551_0D6DBC553942__INCLUDED_)
