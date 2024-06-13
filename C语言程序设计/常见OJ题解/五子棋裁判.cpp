//Caution!VScode Debugger does not accept files with Chinese Characters.
#include <iostream>
#include <vector>
using namespace std;
int judge(string s)
{
  if (s=="WWWWW")
    {
      cout << "White";
      return 1;
    }
  else if (s=="BBBBB")
  {
    cout << "Black";

    return 1;
  }
    return 0;
}
int solve(int n)
{
  string s;
  int a;
  cin>> a;
  vector<string> qipan(a);
  for (int i=0;i<a;i++)
    cin>> qipan[i];
  for (int i=0;i<a;i++)
    for (int j=0;j<a-4;j++)
     {
      for (int k=0;k<5;k++)
        s+=qipan[i][j+k];
      if(judge(s)) 
      {
       if(n) cout << "\n";
        return 1;
      }
      s="";
     } 
  s="";
  for (int i=0;i<a-4;i++)
    for (int j=0;j<a;j++)
      {
        for (int k=0;k<5;k++)
        s+=qipan[i+k][j];
        if(judge(s) )
        {
          if(n) cout << '\n';
          return 1;
        }
         s="";
      }
  s="";
  for (int i=0;i<a-4;i++)
    for (int j=0;j<a-4;j++)
      {
        for (int k=0;k<5;k++)
        s+=qipan[i+k][j+k];
        if(judge(s))
        {
         if(n) cout << '\n';
          return 1;
        } 
        s="";
      }
      s="";
      for (int i=0;i<a-4;i++)
    for (int j=4;j<a;j++)
      {
        for (int k=0;k<5;k++)
          s+=qipan[i+k][j-k];
        if(judge(s))
        {
         if(n) cout << '\n';
          return 1;
        } 
        s="";
      }
  cout << "Not so fast" << endl;
  return 0;
}
int main()
{
  int n;
  cin>> n;
  while (n--)
  {
    solve(n);
  }

  return 0;
}