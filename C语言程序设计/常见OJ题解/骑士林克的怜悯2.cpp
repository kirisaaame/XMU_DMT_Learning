#include <bits/stdc++.h>
using namespace std;
//思路：使用宽搜得出给定步数可以到达的最远距离
//当检测到终点时，返回答案
char area[151][151];
queue<vector<int>> q;
int dx[8]={-1,1,-2,2,-2,2,-1,1};
int dy[8]={-2,-2,-1,-1,1,1,2,2};
int col,row;
int bfs(int x0,int y0,int x1,int y1)
{
    q.push({x0,y0,0});
    area[x0][y0]='*';
    while(q.size())
    {
        auto t = q.front();
        //cout << t[0]<<t[1] <<t[2] << endl;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int x2 = t[0]+dx[i],y2 = t[1]+dy[i],step = t[2]+1;
            if(x2<0||y2<0||x2>=row||y2>=col||(area[x2][y2]=='*')) continue;//检测目标点是否合法的部分
            if (x2==x1 &&y2==y1) return step;//返回答案的部分
            q.push({x2,y2,step});//加入队列的部分
            //cout << x2 <<'-'<< y2 << '-'<<step<<endl;
            area[x2][y2]='*';
        }
    }
    return 0;
}
int main()
{
    int x0,y0,x1,y1;
    cin >> col >> row;
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
        {
            cin >> area[i][j];
            if (area[i][j]=='K')
                x0 = i, y0=j;
            else if (area[i][j]=='H')
                x1=i,y1=j;
        }
    cout <<  bfs(x0,y0,x1,y1) <<endl;
}