#include <bits/stdc++.h>
using namespace std;
int house[51][51];
bool st[51][51]={{false}};//房间是否已被搜索
int cnt=0,_max=1;
//思路：遍历所有房间进行深搜，其中深搜计算房间大小，遍历计算房间数量
int dfs(int row,int col)
{
    if (st[row][col]) return 0;
    st[row][col] = true;
    int size = 1;
    if (!(house[row][col]&1)&& !st[row][col-1])//保留1这一位，看是否有墙
        size+=dfs(row,col-1);
    if (!(house[row][col]&2)&&!st[row-1][col])
        size+=dfs(row-1,col);
    if ((!(house[row][col]&4)&&!st[row][col+1]))
        size+=dfs(row,col+1);
    if ((!(house[row][col]&8)&&!st[row+1][col]))
        size+=dfs(row+1,col);
    return size;
}       
int main()
{
    int row,col;
    cin >> row >> col;
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            cin >> house[i][j];
    for (int i=0;i<row;i++)
        for (int j =0;j<col;j++)
        {
            if (!st[i][j]) cnt++;
            int x = dfs(i,j);//查找房间大小，如果已被搜索过，返回0
            if (_max<x) _max = x;
        }
    cout << cnt <<endl;
    cout << _max << endl;
    return 0;
}