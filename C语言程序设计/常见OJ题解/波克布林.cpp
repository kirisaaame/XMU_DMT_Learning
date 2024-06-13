#include <bits/stdc++.h>
using namespace std;
bool area[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool check(int x,int y,int k)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    while(y)
    {
        sum+=y%10;
        y/=10;
    }
    return sum>k;
}
int main()
{
    int k,m,n;
    cin >> k >> m >> n;
    if(m==0||n==0)
    {
        cout << '0' << endl;
        return 0;
    }
    int x=0,y=0;
    queue<pair<int,int>>q;
    q.push({0,0});
    area[0][0]=true;
    int res = 0;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        res++;
        for (int i=0;i<4;i++)
            {
                auto x1= t.first+dx[i],y1 = t.second+dy[i];
                if(x1<0||y1<0||x1>=m||y1>=n||check(x1,y1,k)||area[x1][y1]) continue;
                q.push({x1,y1});
                area[x1][y1] = true; 
            }
    }
    cout << res << endl;
    return 0;
}