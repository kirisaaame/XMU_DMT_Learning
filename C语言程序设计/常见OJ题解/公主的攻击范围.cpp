#include <bits/stdc++.h>
using namespace std;
char board[151][151];
queue<pair<int,int>> q;
int Col,Row;
int bfs(int x0,int y0,int x1,int y1)
{
    q.push({x0,y0});
}
int main()
{
    int x0,y0;
    int x1,y1;
    cin >>Col>>Row;
    for (int i=0;i<Row;i++)
        for (int j=0;j<Col;j++)
        {
            cin >> board[i][j];
            if(board[i][j]=='K')
                x0=i,y0=j;
            else if(board[i][j]=='H')
                x1=i,y1=j;
        }
    cout <<bfs(x0,y0,x1,y1) <<endl;
}