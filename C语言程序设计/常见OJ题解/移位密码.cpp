#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
  string code;
  cin>>code;
  string s;
  string ans="";
  getchar();
  while (cin>>s && s !="")
  {
	for (int i=0;i<s.size();i++)
	{
		if (isalpha(s.at(i)))
    {
      int k=code.find(s.at(i));
      ans+='A'+k;
    }
	}
	ans+=' ';
  }
  cout << ans << endl;

  return 0;
}