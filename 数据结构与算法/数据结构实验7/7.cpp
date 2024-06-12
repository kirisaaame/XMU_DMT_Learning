#include <bits/stdc++.h> 
using namespace std;
#define N 20
int a[N][N],times[N][N];//a是临接矩阵，times用于记录每条边被走过的次数  
int len=10000,rec[N*N],res[N*N];//len用于记录总路长,rec用于记录走过点的顺序 ,res用于记录可行的结果 
int n_v=0,n_e=0;//分别是点数和边数 
map<int,string>mp;//一个字典对应编号和景点名称
void Display()//展示矩阵 
{
	for(int i=0;i<n_v;i++)
	{
		for(int j=0;j<n_v;j++)
		{
			if(a[i][j]>0)
			    cout<<a[i][j]<<' ';
			else if(a[i][j]==-1)
			    cout<<"* ";
		}
		cout<<endl;
	}
}
bool Judge(int des[],int n)//判断是否走完了全部目标 
{
	bool *flags=new bool[n_v];
	memset(flags, false,n_v);//初始化
	for(int i=0;rec[i]!=-1;i++)
		flags[rec[i]]=true;
    for(int i=0;i<n;i++)
    	if(flags[des[i]]==false)
    	    return false;
	return true;
}

void FindWay(int des[],int n,int x,int pointVisited=0)//n是目标个数，x是起点，cou是已经走过点的数量 
{
	if(Judge(des,n))//如果达成一种结果 
	{
		int sum=0;//用于记录该结果的总长度 
		for(int i=1;rec[i]!=-1;i++)
		    sum+=a[rec[i-1]][rec[i]];
		if(sum<len)
		{
			cout<<"推荐的路径为：";
			len=sum;
			for(int i=0;rec[i]!=-1;i++)
			{
			    res[i]=rec[i];//储存当前最优解 
			    cout<<mp[res[i]+1]<<"->";
		    }
		    cout<<"这条路的长度是:"<<len<<endl;
	    }
	    return;
	}
	
	
	for(int y=0;y<n_v;y++)
	{
		if(a[x][y]>0 && times[x][y]<2)//如果可以走 
		    {
		    	//cout<<"One step forward"<<y+1<<endl;
		    	times[x][y]++;
		    	times[y][x]++;
		    	rec[pointVisited]=x;
		    	pointVisited++;//留痕 
		    	
		    	FindWay(des,n,y,pointVisited);
		    	
		    	times[x][y]--;
		    	times[y][x]--;
                rec[pointVisited]=-1;
                pointVisited--;//恢复现场
                //cout<<"One step back"<<x+1<<endl;
			}
	}
}

int main()
{
	cout<<"请输入景点个数(20以内)：";
	cin>>n_v;
	cout<<"请输入路径个数：";
	cin>>n_e;
    cout << "请输入景点名称和对应编号" << endl;
    for (int i=0;i<n_v;i++)
    {
        int no;
        string name;
        cin >> no;
        cin >> name;
        mp[no] = name;
    }
	for(int i=0;i<N*N;i++)
	rec[i]=res[i]=-1;
	
	for(int i=0;i<n_v;i++)//初始化 
	{
	    for(int j=0;j<n_v;j++)
	    {
	        a[i][j]=-1;
	        times[i][j]=0;
	    }
	}
	
	cout<<"请依次输入邻近景点序号以及路径距离："<<endl; 
	for(int i=0;i<n_e;i++)
	{
		int t1,t2,weight;
		cin>>t1>>t2>>weight;	
		a[t1-1][t2-1]=a[t2-1][t1-1]=weight;
	}
	Display(); 
	cout<<"请输入起点"<<endl;
	int ori;
	cin>>ori;
	ori--; 
	cout<<"请输入要游览的景点个数"<<endl;
	int n;
	cin>>n; 
	cout<<"请输入要游览的景点的序号"<<endl;
	int *des=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>des[i];
		des[i]--;
	}
	
	cout<<"查询中"<<endl;
	FindWay(des,n,ori);
	cout<<"最短的路程是:"<<endl;
	for(int i=0;res[i]!=-1;i++)
	cout<<mp[res[i]+1]<<"->";
	cout<<"最短的路程为:"<<len<<endl;
	return 0;
}

/*
9
9
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 2 1
6 7 2
6 8 3
8 9 4
2
4
1 4 7 9
*/
