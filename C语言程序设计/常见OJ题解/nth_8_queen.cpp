#include <bits/stdc++.h>
using namespace std;
void dfs(int k,int n,vector<int>&res,vector<vector<int>>&ans);
int main()
{
    vector<vector<int>> ansset;
    vector<int>res(8);
    dfs(0,8,res,ansset);
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin >>t;
        for (auto c:ansset[t-1]) cout << c+1;
        cout <<'\n';
    }
    
}
void dfs(int k,int n,vector<int>&res,vector<vector<int>>&ans)
{
    if (k==n)
    {
        vector<int> t(8);
        t.assign(res.begin(),res.end());
        ans.push_back(t);
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
            dfs(k+1,n,res,ans);
        }
    }

}