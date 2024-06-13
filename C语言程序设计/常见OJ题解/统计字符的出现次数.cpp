#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    while (cin>>s)
    {
        vector <char> ch;//已经出现过的字符集合
        vector<int> count;//字符计数
        for (auto a:s)//遍历字符串
        {
            int i;
            for (i=0;i<ch.size();i++)
            {
                if(ch[i]==a)
                {
                    count[i]++;
                    break;
                }//如果前面已经出现过了，该字符计数+1
            }
            if (i==ch.size())
            {
                ch.push_back(a);
                count.push_back(0);
            }//如果没找到，字符集合加入该字符，数组多加一个0
        }
        for (int i=0;i<ch.size();i++)
            for (int j=i;j<ch.size();j++)
                if(count[j]>count[i] || count[j]==count[i] && ch[j]>ch[i])
                {
                    int temp;char t;
                    temp=count[i];t=ch[i];
                    count[i]=count[j];ch[i]=ch[j];
                    count[j]=temp;ch[j]=t;
                }//选择排序
        for (int i=0;i<ch.size();i++)
                cout << ch[i] << ":" << count[i]+1<< ' ';
        cout << endl;
    }

    return 0;
}