#include <bits/stdc++.h>
using namespace std;
int const Maxsize=100;//顶点上限数量为100
typedef struct 
{
    float vex[Maxsize];//包含数据
    int size;
}V;//点集定义（仅包含数据）

typedef vector<pair<int,int>> VR;//边集定义
typedef struct Vertex
{
    float data;
    Vertex()
    {
        data = -1;//默认-1为未初始化
    }
}Vertex;//顶点定义，其中未初始化为-1
typedef struct 
{
    bool NonDirec = false;//是否为无向图
    int edges[Maxsize][Maxsize];
    int vernum=0;
    Vertex vex[Maxsize];
    
}Graph;
void CreateGraph(Graph& G,const V& v,const VR& vr)
    {
        G.vernum = v.size;
        for (int i=0;i<v.size;i++)
            G.vex[i].data=v.vex[i] ;//赋值顶点集
        for (int i=0;i<vr.size();i++)
            G.edges[vr[i].first][vr[i].second] =1;//赋值边集
    }
    int DestroyGraph(Graph &G)
    {
        G.vernum = 0;
        free(G.vex);
        free(G.edges);//大小置0，释放数组空间
    }
    int LocateVex(const Graph &G,int u)
    {
        for (int i=0;i<G.vernum;i++)
            if (G.vex[i].data == u) return i;
        cout << "Failed to find the vertex."<<endl;
        return -1;//未找到，返回-1
    }
    int GetVex(const Graph& G,int index)
    {
        if (index > G.vernum)
        {
            cout << "index overflow!" << endl;
            return -1;
        }//查找节点非法
        return G.vex[index-1].data;//返回节点数据
    }
    int PutVex(Graph& G,int index, float value)
    {
        if (index>G.vernum)
        {
            cout << "index overflow!" << endl;
            return -1;
        }//查找节点非法
        G.vex[index].data = value;//设置节点数据
        return 0;
    }
    int FirstAdjVex(const Graph& G,int index)
    {
        if (index>G.vernum)
        {
            cout << "index overflow!" << endl;
            return -1;
        }//查找节点非法
        for (int i=0;i<G.vernum;i++)
        {
            if (G.edges[index][i]==1)
                return i;//找到邻接矩阵中为1，返回对应顶点指针
        }
        return -1;//未找到，返回空指针
    }
    int NextAdjVex(const Graph& G,int index,int w)
    {
        if (index>G.vernum || w>G.vernum)
        {
            cout << "index overflow!" << endl;
            return -1;
        }//查找节点非法
        for (int i=w;i<G.vernum;i++)
        {
            if (G.edges[index][i]==1)
                return i;//找到邻接矩阵中为1，返回对应顶点指针
        }
        return -1;//未找到，返回空指针
    }
    void InsertVex(Graph& G,int v)
    {
        G.vernum++;//顶点数量+1
        G.vex[G.vernum-1].data = v;
    }
    void DeleteVex(Graph& G,int index)
    {
        if (index>G.vernum)
        {
            cout << "index overflow!" << endl;
            return;
        }//查找节点非法
        for (int i=index;i<G.vernum;i++)
            G.vex[i].data = G.vex[i+1].data;//替换数据
        for (int i=index;i<G.vernum;i++)
            for (int j=0;j<G.vernum-1;j++)
            {
                G.edges[i][j] = G.edges[i+1][j];
                G.edges[j][i] = G.edges[j][i+1];
            }//后面的数据需要前移（行，列）
        G.vernum--;
    }
    void InsertArc(Graph&G , int v,int w)
    {
        G.edges[v-1][w-1] = 1;
        if (G.NonDirec)
            G.edges[w-1][v-1]=1;
    }
    void DeleteArc(Graph &G,int v,int w)
    {
        G.edges[v-1][w-1] = 0;
        if (G.NonDirec)
            G.edges[w-1][v-1]=0;
    }
    //深度优先搜索值
    int visited[Maxsize];
    void dfs(const Graph& G,int v, int value)
    {
        if (G.vex[v].data == value)
        {
            cout << value << " is in No." << v << " Vertex."<<endl;
            return ;
        }//先访问该节点
        visited[v] = 1;//标记已访问
        int w = FirstAdjVex(G,v);
        if (w==-1) return;//没有邻接节点
        while (visited[w]&& w!=-1)
            w = NextAdjVex(G,v,w);//找下一个
        if (w==-1) return;//没有未访问邻接节点
        dfs(G,w,value);
        return ;
    }
    //广度优先搜索值
    void bfs(const Graph& G,int value)
    {
        int visize=0;
        queue<int> q;
        int v = 0;
        q.push(v);//塞入第一个节点
        if (G.vex[v].data == value)
        {
            cout << value << " is in No." << v << " Vertex."<<endl;
            return ;
        }
        visited[v]=1;
        int w = FirstAdjVex(G,v);
        while(w!=-1)
        {
            q.push(w);
            w = NextAdjVex(G,v,w);
        }//邻接节点入队 
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            if (G.vex[v].data == value)
        {
            cout << value << " is in No." << v << " Vertex."<<endl;
            return ;
        }
        w = FirstAdjVex(G,v);
        while(w!=-1&&!visited[w])
        {
            q.push(w);
            w = NextAdjVex(G,v,w);
        }
        cout << "Failed to find." << value << " in G."<< endl;
    }
    }
//邻接矩阵图的Dijkstra算法
/*
    假定初始数据：
    顶点集V={0,1,2,3,4,5},存储数据分别为0.6,1.2,1.8,2.4,3.0,3.6
    边集VR = {<0,1>,<0,4>,<2,3>,<2,5>,<3,0>,<3,1>,<3,4>,<4,5>}
*/
int main()
{
    //数据初始化部分
    V v;
    v.size=6;
    for (int i=0;i<v.size;i++)
        v.vex[i] = 0.6f*(i+1);
    
}