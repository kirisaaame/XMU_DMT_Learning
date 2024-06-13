#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
int nb [101]={0};

int main()
{
  int index=0;
  string num;
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
      if(s[i]!=','&& i<s.size()-1)
      {
        num+=s[i];
        continue;
      }
      else
      {
        if(i==s.size()-1)
          num+=s[i];
        if (num[0]=='0')
          if(num[1]=='b')
      {
            int sum=0;
    int m=num.size()-1;
    for (int j=m;j>1;j--)
      {
        int l=num[j]-'0';
        for (int k=0;k<m-j;k++)
          l*=2;
        sum+=l;
      }
      nb[index]=sum;
      index++;
          }
          else if(num[1]=='x')
          {
            int sum=0;
            int m=num.size()-1;
            for (int j=m;j>1;j--)
            {
               int l=0;
                if(isdigit(num[j])) l+=num[j]-'0';
              else l+=10+num[j]-'a';
              for (int k=0;k<m-j;k++)
                l*=16;
             sum+=l;
            }
            nb[index]=sum;
            index++;
          }
          else
          {
            int sum=0;
            int m=num.size()-1;
            for (int j=m;j>0;j--)
          {
            int l=num[j]-'0';
            for (int k=0;k<m-j;k++)
            l*=8;
            sum+=l;
          }
          nb[index]=sum;
          index++;
          }
        else
        {
          int sum=0;
          int m=num.size()-1;
          for (int j=m;j>=0;j--)
        {
          int l=num[j]-'0';
          for (int k=0;k<m-j;k++)
          l*=10;
          sum+=l;
        }
        nb[index]=sum;
        index++;
        }
        num="";
      }
    }
    sort(nb,nb+index);
    for (int i=0;i<index;i++)
      if (i==index-1) cout << nb[i];
      else cout << nb[i]<<',';
    
  return 0;
}