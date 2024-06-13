#include <iostream>
#include <vector>
#include <string>
using namespace std;
string dfs(int num)
{
	if (num==0) return "0";
	if (num==2) return "2";
	else if (num==1) return "2(0)";
	else if (num==3) return "2+2(0)";
	//终止状态
	else
	{
		int zhishu = 0,result=1;
		int yushu;
		while(num>=result*2)
		{
			result*=2;
			zhishu++;
		}
		yushu = num-result;
		string ans = "2(" + dfs(zhishu) +")" ;
		if (yushu>0)
			ans+="+" +dfs(yushu);
		return ans;//递归
	}
}
int main()
{
	int n;
	cin >>n;
	cout << dfs(n) << endl;
}