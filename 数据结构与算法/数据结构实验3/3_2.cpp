//图的邻接表表示
#include <bits/stdc++.h>
const int maxSize = 100;
using namespace std;
//定义边集
typedef struct 
{
    vector<pair<int,int>> a;
    int size;
}VR;
//定义点集
typedef struct 
{
    int no[maxSize];
    int vex[maxSize];//定义顶点编号
    int size;
}V;
//边的节点定义
typedef struct ArcNode
{
    int adjvex;//指向的顶点编号
    struct ArcNode* nextarc;//下一个顶点的编号
}ArcNode;
//顶点节点定义
typedef struct 
{
    int no;
    int data;
    ArcNode *firstarc;
}VNode;
//
enum GraphType//图的类型定义
{
    undirected,
    directed
};
//图的定义
typedef struct
{
    GraphType type;
    VNode adjlist[maxSize];
    int vexnum,arcnum;
}AGraph;
void CreateGraph(AGraph& G,const V& v,const VR& vr)//根据已有点集和边集建立图(使用头插法)
    {
        //大小赋值
        G.vexnum = v.size;
        G.arcnum = vr.size;
        //顶点赋值
        for (int i=0;i<G.vexnum;i++)
        {
            G.adjlist[i].no =v.no[i];
            G.adjlist[i].data = v.vex[i]; 
            G.adjlist[i].firstarc = NULL;//将尾部设置为NULL
        }
        //链表赋值
        for (int i=0;i<G.arcnum;i++)
        {
          ArcNode* arc = new ArcNode;
          arc->adjvex = vr.a[i].second;
          ArcNode* p = G.adjlist[vr.a[i].first].firstarc;
          arc->nextarc = G.adjlist[vr.a[i].first].firstarc;//头插法
          G.adjlist[vr.a[i].first].firstarc = arc; 
          if (G.type == undirected)//无向图添加对称边
          {
            ArcNode* arc = new ArcNode;
            arc->adjvex = vr.a[i].first;
            arc->nextarc = G.adjlist[vr.a[i].second].firstarc;//头插法
            G.adjlist[vr.a[i].second].firstarc = arc; 
          } 
        }    
    }
    int DestroyGraph(AGraph &G)    //清空图
    {
        //大小置零
       G.vexnum = 0;
       G.arcnum = 0;
       //释放空间
       free(G.adjlist);
    }
    int LocateVex(const AGraph &G,int u)//确定对应编号在图中对应的顶点
    {
        for (int i=0;i<G.vexnum;i++)
            if (G.adjlist[i].data==u) return i;//找到对应顶点，返回找到的第一个顶点编号
        cout << "Failed to find the vertex."<<endl;
        return -1;//未找到，返回空
    }
    int GetVex(const AGraph& G,int index)//查找编号index的节点数据
    {
       for (int i=0;i<G.vexnum;i++)
        if(G.adjlist[i].no == index)
            return G.adjlist[i].data;//返回节点数据
        cout << "Failed to find Vertex."<<endl;
        return -1;//非法
    }
    int PutVex(AGraph& G,int index, float value)//将编号index的节点数据修改为value
    {
        for (int i=0;i<G.vexnum;i++)
            if(G.adjlist[i].no == index)
               { 
                    G.adjlist[index].data = value;
                    return 0;
                }//设置节点数据
        cout << "Failed to find Vertex."<<endl;
        return -1;//非法
    }
    ArcNode* FirstAdjVex(const AGraph& G,int index)//查找编号为Index的节点的第一条连接边(边节点)
    {
        for (int i=0;i<G.vexnum;i++)
            if(G.adjlist[i].no == index)
                return G.adjlist[index].firstarc;
        cout << "Failed to find Vertex."<<endl;
        return NULL;//非法
    }
    ArcNode* NextAdjVex(const AGraph& G,int index,int w)//查找编号为Index的节点关于连接点为W的下一条连接边
    {
        for (int i=0;i<G.vexnum;i++)
            if(G.adjlist[i].no == index)
        { 
            ArcNode* p = G.adjlist[i].firstarc;
            while (p->adjvex != w && p) p= p->nextarc;//找到对应的边
                if (p==NULL)  return NULL;//未找到，返回空指针
            return p->nextarc;
        }
         cout << "Failed to find arc."<<endl;
        return NULL;
    }
    void InsertVex(AGraph& G,int v,int data)//加入一个顶点
    {
        G.vexnum++;//顶点数量+1
        G.adjlist[G.vexnum-1].no = v;//no赋值
        G.adjlist[G.vexnum-1].data = data;
    }
    void DeleteVex(AGraph& G,int index)//删除一个顶点（待修改）
    {
        if (index>G.vexnum)
        {
            cout << "index overflow!" << endl;
            return;
        }//查找节点非法
        
        G.vexnum--;
    }
    void InsertArc(AGraph&G , int start,int goal)//加入一条边
    {
       for (int i=0;i<G.vexnum;i++)
       {
        if (G.adjlist[i].no==start)//找到对应顶点
        {
            ArcNode *p = new ArcNode;
            p->adjvex = goal;
            p->nextarc=G.adjlist[i].firstarc;
            G.adjlist[i].firstarc=p;
        if (G.type == undirected)//无向图添加对称边
        {
            ArcNode *p = new ArcNode;
            p->adjvex = start;
            for (int j=0;j<G.vexnum;j++)
                if (G.adjlist[j].no==goal)
                {
                    p->nextarc=G.adjlist[j].firstarc;
                    G.adjlist[j].firstarc=p;
                }
        }
        }
       }
        
    }
    void DeleteArc(AGraph &G,int start,int goal)//删除一条边
    {
        if(start>G.vexnum) 
        {
            cout << "index overflow!" << endl;
            return;
        }//查找节点非法
        ArcNode *p = G.adjlist[start].firstarc;
        if (p->adjvex == goal)//第一条边就是要删除的边
        {
            G.adjlist[start].firstarc = p->nextarc;
            free(p);
        }
        while(p->nextarc->adjvex!=goal && p->nextarc!=NULL) p = p->nextarc;//寻找对应边
        if (p->nextarc==NULL)//找不到对应边
        {
            cout << "Failed to find correspond arc.";
            return ;
        }
        //找到对应边
        ArcNode* q = p->nextarc;
        p->nextarc = q->nextarc;
        if (G.type == undirected)//无向图删除对称边
        {
            ArcNode *p = G.adjlist[goal].firstarc;
            if (p->adjvex == start)//第一条边就是要删除的边
            {
            G.adjlist[goal].firstarc = p->nextarc;
            free(p);
            }
            while(p->nextarc->adjvex!=goal && p->nextarc!=NULL) p = p->nextarc;//寻找对应边
         //找到对应边
            ArcNode* q = p->nextarc;
            p->nextarc = q->nextarc;
        }
    }
    //深度优先搜索值
    int visited[maxSize];
    bool dfs(const AGraph& G,int v, int value)
    {
        if (G.adjlist[v].data == value)
        {
            cout << value << " is in No." << v << " Vertex."<<endl;
            return true;
        }//先访问该节点
        visited[v] = 1;//标记已访问
        for (ArcNode * w = FirstAdjVex(G,v);w;w=NextAdjVex(G,v,w->adjvex))//遍历邻接点
        {
            if(!visited[w->adjvex]&&dfs(G,w->adjvex,value)) return true;
        }
        visited[v]=0;
        return false;   //未搜索到值
    }
    //广度优先搜索值
    bool bfs(const AGraph& G,int value)
    {
        queue<int> q;
        int v = 0;
        q.push(v);//塞入第一个节点
        while(!q.empty())//当栈非空循环操作
        {
            v=q.front();//赋值
            q.pop();//弹出
            //找到目标节点
            if (G.adjlist[v].data == value)
            {
                cout << value << " is in No." << v << " Vertex."<<endl;
                return true;
            }
            visited[v]=1;
            ArcNode* w = FirstAdjVex(G,v);
            while(w!=NULL&&!visited[w->adjvex])
            {
                q.push(w->adjvex);
                w = NextAdjVex(G,v,w->adjvex);
            }//邻接未访问节点入队 
        }
        return false;   //栈空未找到，返回false
    }


int main()
{

}
