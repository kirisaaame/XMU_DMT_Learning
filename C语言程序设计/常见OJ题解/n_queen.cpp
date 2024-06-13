#include <bits/stdc++.h>
using namespace std;
void dfs(int k,int n,vector<int>&res);
int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    dfs(0,n,res);
}
void dfs(int k,int n,vector<int>&res)
{
    if (k==n)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                if (j==res[i]) cout << 'Q';
                else cout << '.';
            cout << '\n';
        }
        cout << '\n';
    }
    for (int i=0;i<n;i++)
    {
        int t;
        for( t=0;t<k;t++)
            if (res[t]==i or abs(i-res[t])==abs(t-k))
                break;
        if (t==k)
        {
            res[k]=i;
            dfs(k+1,n,res);
        }
    }

}