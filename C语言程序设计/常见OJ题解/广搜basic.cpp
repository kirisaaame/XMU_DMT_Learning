#include <bits/stdc++.h>
using namespace std;
char area[25][25];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int bfs(int x,int y)
{
    int res=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    area[x][y] = '#';
    while(q.size())
    {
        auto t =q.front();
        q.pop();
        res++;
        for(int i=0;i<4;i++)
        {
            int x1 = t.first+dx[i];
            int y1 = t.second+dy[i];
            if(x1<0||x1>=m||y1<0||y1>=n||area[x1][y1]!='.') continue;
            area[x1][y1]='#';
            q.push({x1,y1});
        }
    }
    return res;
}
int main()
{
    while(cin >> n >> m && !(n==0 &&m==0))
    {
        int x,y;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                    { 
                        cin >> area[i][j];
                        if (area[i][j]=='@')
                        {x = i;y=j;}    
                    }
       cout << bfs(x,y) << endl;
    }
}