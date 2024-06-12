#include <bits/stdc++.h>
using namespace std;
#define INF 1000
int const maxSize = 100;
//邻接矩阵图的数据结构定义
typedef struct 
{
    int a[maxSize][maxSize];
    int size;
    int arcnum;
}MGraph;
//邻接表图的数据结构定义
//边节点定义
typedef struct ArcNode
{
    int adjvex;
    int length;
    ArcNode* nextarc;
}ArcNode;
//顶点节点定义
typedef struct 
{
    int no;
    ArcNode* firstarc;
}Vex;
//图定义
typedef struct
{
    Vex a[maxSize];
    int size;
    int arcnum;
}AdjGraph;
//生成一个邻接矩阵图
void CreateMGraph(MGraph&G,int pnum,int arcnum)
{
    G.size = pnum;
    G.arcnum = arcnum;
    int src,dst,dis;
    for (int i=0;i<arcnum;i++)
    {
        cin >> src >> dst >> dis;
        G.a[src][dst] = dis;
        G.a[dst][src] = dis;//对称边
    }
    for (int i=0;i<pnum;i++)
        G.a[i][i] = 0;
}
//生成一个邻接表图
void CreateAdjGraph(AdjGraph&G,int pnum,int arcnum)
{
    G.size = pnum;
    G.arcnum = arcnum;//初始化数值
    int src,dst,dis;
    for (int i=0;i<arcnum;i++)
    {
        cin >> src >> dst >> dis;  //输入起点终点和权值
        //生成新边
        ArcNode* p = new ArcNode;
        p->adjvex = dst;
        p->length = dis;
        p->nextarc = NULL; 
        
        //生成对称边
        ArcNode* q = new ArcNode;
        q->adjvex = src;
        q->length = dis;
        q->nextarc =NULL;
        //边加入图中
        if(G.a[src].firstarc==NULL) //该顶点目前没有边连接
        {   
            G.a[src].firstarc=p;
            //cout << src << " -> " << dst << " added." << endl;
        }
        else    //该顶点有边连接，头插法（DFS遍历与顺序无关）
        {
            p->nextarc = G.a[src].firstarc;
            G.a[src].firstarc = p;
            //cout << src << " -> " << dst << " added." << endl;
        }
        //对称边加入图中
        if(G.a[dst].firstarc==NULL) //该顶点目前没有边连接
        {   
            G.a[dst].firstarc=q;
            //cout << dst << " -> " << src << " added." << endl;
        }
        else    //该顶点有边连接，头插法（DFS遍历与顺序无关）
        {
            q->nextarc = G.a[dst].firstarc;
            G.a[dst].firstarc = q;
            //cout << dst << " -> " << src << " added." << endl;
        }
    }
    
}
//邻接表图的Dijkstra算法
void Dijkstra(const AdjGraph&G,int start,int goal)
{

}
//邻接矩阵图最小生成树的Kruskal算法
void Kruskal(const MGraph&G,int n,int u)
{
    
}
//邻接矩阵图最小生成树的Prim算法
void Prim(const MGraph&G,int n,int u)
{
    bool isvisited[n];  //记录顶点是否已经被访问
    pair<int,int> dis[n]; //权值表
    int totaldis = 0;   //总距离
    int cur=u;//当前选中顶点
    int src;    //输出的出发顶点
    int dst;    //输出的终点顶点
    isvisited[u]=true;
    for (int i=0;i<n;i++)
    {
        dis[i].first=INF;   //更新距离为最大距离
        dis[i].second=-1;   //-1表示未选择点
    }
    //选点求最短路径
    for (int i=0;i<n-1;i++)
    {
        int min=INF;
        //更新dis表
        for(int i=0;i<n;i++)
        {
            if(G.a[cur][i]!=0&&dis[i].first>G.a[cur][i])
            {
                dis[i].first = G.a[cur][i]; //更新最短距离
                dis[i].second = cur;    //更新源顶点
            }
        }
        //寻找有效最短距离
        for(int i=0;i<n;i++)
            if(min>dis[i].first&&!isvisited[i])
            {
                min = dis[i].first; //更新最短距离
                src = dis[i].second;//更新源顶点
                dst = i;//更新目标顶点
            }
        if(min==INF)//没有找到合法路径
        {
            cout << "Not Connected!" << endl;
            return;
        }
        totaldis+=min;
        //输出
        cout << src << " -> " << dst << " :" << min << endl;
        cur = dst;
        isvisited[dst]=true;
    }
    cout << "Distance: " << totaldis << endl;
}
//邻接表图判断是否存在长度为k的简单路径的深度优先搜索
bool DFS(const AdjGraph&G,int src,int dst,int len)
{
    int isvisited[G.size]={false};//是否已访问数组
    if (src == dst && len==0)//若找到简单路径
        return true;
    else if (src==dst && len>0)
        return false;
    else if (len>0)
    {
        isvisited[src]=true;//访问当前节点
        for (ArcNode* p =G.a[src].firstarc;p;p=p->nextarc)//遍历边
        {
            int v = p->adjvex;
            if (!isvisited[v])//没被深度优先访问过
            {
                //cout << src << " -> " << v << endl;
                if(DFS(G,v,dst,len-p->length))//递归调用，若有返回true，否则继续遍历。
                    return true;
            }
        }
        isvisited[src]=false;
    }
    return false;//没找到，返回false
}
int main()
{
    //邻接矩阵部分
    MGraph G;
    int pnum,arcnum,u;
    cout << "Prim Algorithm:Enter number of points and arcs." << endl;
    cin >> pnum >> arcnum;//输入顶点数、边数
    CreateMGraph(G,pnum,arcnum);
    cout << "Enter start point: " << endl;
    cin >> u;
    Prim(G,G.size,u);
    //邻接表部分
    AdjGraph G1;
    int src,dst,dis;
    cout << "DFS:Enter number of points and arcs." << endl;
    cin >> pnum >> arcnum;//输入顶点数、边数
    CreateAdjGraph(G1,pnum,arcnum);
    cout << "Enter start point and destination, as well as k:"<<endl;
    cin >> src >> dst >> dis;//输入起点、终点、k
    bool find=DFS(G1,src,dst,dis);
    find ? cout << "Exist" << endl:cout << "Not exist" << endl;
}