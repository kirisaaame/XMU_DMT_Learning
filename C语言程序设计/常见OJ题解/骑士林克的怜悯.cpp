#include <bits/stdc++.h>
using namespace std;
/*思路：按棋盘上各点枚举，对于每个点进行深度优先搜索
如果找到一个符合条件的则返回，输出结果，否则输出None
*/
int p,q;
 int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {-1,1,-2,2,-2,2,-1,1};
    vector<pair<char,int>> path;
    bool st[27][27];
bool dfs(int x,int y,int cnt);
int main()
{
  int t;
  cin >>t;
  for (int i=0;i<t;i++)
  {
    cout<< '#'<<i+1<<':'<<endl;
    cin >>p>>q;
    path.clear();
    memset(st,0,sizeof(st));
    bool flag = false;
    for (int j=0;j<q;j++)
        for (int k=0;k<p;k++)
        {
            if(dfs(j,k,1))
            {
                flag = true;
                break;
            }
        }
    if(!flag) cout << "none";
    cout <<endl;
  }
}
bool dfs(int x,int y,int cnt)
{
    path.push_back({char(x+'A'),y+1});
    if (cnt == p*q)
    {
        for (auto a:path) cout << a.first <<a.second;
        return true;
    }
    else
    {
        st[x][y]=true;
        for(int i=0;i<8;i++)
        {
            int a=x+dx[i];
            int b=y+dy[i];
            if (a<0 || a>=q ||b<0 || b>=p) continue;
            if (st[a][b]) continue;
            if(dfs(a,b,cnt+1))return true;
        }
        st[x][y]=false;
        path.pop_back();
        return false;
    }
}
