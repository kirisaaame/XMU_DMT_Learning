#include <bits/stdc++.h>
using namespace std;
const int N=507;
struct Stone
{
     int x,y,status;
     Stone(int a,int b,int c){x=a,y=b,status = c;}
     Stone() :x(0),y(0),status(0){};
};
void DisplaytStone(Stone& s)
{
    cout << "(" <<s.x << ' ' << s.y << ' ' << s.status << ')';
}
int direction[4][3][3] = {
{{-2,0,2},{-1,0,1},{-1,0,0}},
{{1,0,2},{1,0,1},{2,0,0}},
{{0,-2,1},{0,-1,0},{0,-1,2}},
{{0,1,1},{0,2,0},{0,1,2}}};
Stone moveStone(Stone& p,int udlf)
{
    int dx = direction[udlf][p.status][0];
    int dy = direction[udlf][p.status][1];
    int newstatus = direction[udlf][p.status][2];
    return Stone(p.x+dx,p.y+dy,newstatus);
}
int n,m;
char area[N][N];
int dist[N][N][3];
queue<Stone>q;
Stone start,target,qhead;
bool isVisited(Stone node)
{
    return dist[node.x][node.y][node.status]!=-1;
}

bool isInside(int x,int y)
{
    return x>=0 &&x<n &&y>=0 &&y<m;
}
bool isValid(Stone node)
{
    if(!isInside(node.x,node.y)|| area[node.x][node.y]=='#')
        return false;
    if (node.status == 2&&(!isInside(node.x+1,node.y))||area[node.x+1][node.y]=='#')
        return false;
    if (node.status == 1&&(!isInside(node.x,node.y+1))||area[node.x][node.y+1]=='#')
        return false;
    if (node.status == 0&&area[node.x][node.y]=='E')
        return false;
    return true;
}
char Readchar()
{
    char  c = getchar();
    while(c!='#'&& c!='.'&&c!='X'&&c!='O'&&c!='E')
        c = getchar();
    return c;
}
void Buildmap(int n,int m)
{
    memset(area,'#',sizeof(area));//初始化为禁区
    memset(dist,-1,sizeof(dist));

    for(int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            area[i][j] = Readchar();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
    {
        char c = area[i][j];
        if (c=='X')
        {
            start.x =i,start.y = j,start.status=0,area[i][j]='.';
            if (isInside(i,j+1)&&area[i][j+1]=='X')
                start.status=1,area[i][j+1]='.';
            if (isInside(i+1,j)&&area[i+1][j]=='X')
                start.status=2,area[i+1][j]='.';
        }
        if (c=='O') target.x =i,target.y =j,target.status = 0;
    }
}
int bfs(Stone &s)
{
    while(q.size())
        q.pop();
    q.push(s);
    dist[s.x][s.y][s.status]=0;
    while(q.size())
    {
        qhead = q.front();
        q.pop();
        for (int i=0;i<4;i++)
        {
            Stone next = moveStone(qhead,i);
            if (!isValid(next)) continue;
            if (!isVisited(next))
            {
                dist[next.x][next.y][next.status] = dist[qhead.x][qhead.y][qhead.status]+1;
                q.push(next);
                if (next.x ==target.x&& next.y==target.y&&next.status==target.status)
                    return dist[next.x][next.y][next.status];
            }
        } 
    }
    return -1;
}
int main()
{
    while(cin >> n>>m &&n)
    {
        Buildmap(n,m);
        int res = bfs(start);
        if (res==-1)
            cout << "Impossible" << endl;
        else cout << res << endl;
    }
}