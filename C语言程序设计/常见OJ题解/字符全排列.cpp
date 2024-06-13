#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void dfs(string &s,int n,string& ans,bool*visit)
{
	if (n == s.length())
	{
		cout << ans <<endl;
		return;
	}
	//终止状态
	for (int i=0;i<s.length();i++)
	{
		if (!visit[i])
		{
		ans+=s[i];
		visit[i]=true;
		dfs(s,n+1,ans,visit);//状态转移
		ans.pop_back();
		visit[i]=false;//回溯
		}
	}
}

int main()
{
	string str;
	cin >> str;
	bool visited[str.length()]={false};
	string ans = "";
	sort(str.begin(),str.end(),less<char>());
	dfs(str,0,ans,visited);
	
}