#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> name_table;

class MatchName
{
    string name;

public:
    MatchName(string s)
    {
        name = s;
    }
    bool operator()(pair<string, int> v)
    {
        return v.first == name;
    }
};

int main()
{
    name_table["北京"] = 10;
    name_table["上海"] = 21;
    name_table["南京"] = 25;
    name_table["广州"] = 20;
    name_table["武汉"] = 27;
    name_table["哈尔滨"] = 451;
    name_table["西藏"] = 891;

    map<string, int>::const_iterator it;                        //创建一个不能修改所指向的元素的迭代器
    for (it = name_table.begin(); it != name_table.end(); it++) //遍历容器
        cout << it->first << ": " << it->second << endl;        //输出元素的关键字和值

    cout << "\n查找：南京...\n";
    it = find_if(name_table.begin(), name_table.end(), MatchName("南京"));
    if (it != name_table.end())
        cout << it->first << ": " << it->second << endl;
    else
        cout << "未找到！\n";
    return 0;
}
