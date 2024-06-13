#include <bits/stdc++.h>
using namespace std;
char area[101][101];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int x,y;//x为行数，y为列数
int bfs(int mx,int my)
{
    queue<vector<int>>q;
    q.push({mx,my,0});
    area[mx][my]='M';
    //设置初始状态
    int day =0;
    while(q.size())
    {
            auto t = q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int x1 =(t)[0]+dx[i],y1 =t[1]+dy[i],flr1 = t[2];
                if(x1<0||x1>=x || y1<0||y1>=y||area[x1][y1]!='.') continue;
                q.push({x1,y1,flr1+1});
                area[x1][y1] = 'M';
                day = flr1+1;
                //cout << 1 <<endl;
            }
           // cout <<get<0>(t)<<'-'<< get<1>(t) <<'-'<<get<2>(t) << endl;
    }
    return day;
}
int main()
{
    int mx,my;
    cin >>y>>x>>my>>mx;
    int sum =0 ;
    for (int i=0;i<x;i++)
        for (int j=0;j<y;j++)
        {
            cin >> area[i][j];
            if(area[i][j]!='*')
            sum++;
        }
    cout << bfs(x-mx,my-1) << endl;
    
}