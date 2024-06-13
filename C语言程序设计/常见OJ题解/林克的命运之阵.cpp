#include <bits/stdc++.h>
using namespace std;
int cnt =0;
void dfs(int i,int n,char pre,int row)
{
    if (i==n)
    {
        cnt++;
        return ;
    }
        if(pre !='r')
        dfs(i+1,n,'l',row);
        dfs(i+1,n,'d',row+1);
        if(pre != 'l')
        dfs(i+1,n,'r',row);
}
int main()
{
    int n;
    cin >> n;
    dfs(0,n,'s',0);
    cout << cnt << endl;
}