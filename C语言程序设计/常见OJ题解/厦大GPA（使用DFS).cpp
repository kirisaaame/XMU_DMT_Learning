#include <iostream>
#include <time.h>
using namespace std;

int score[]={90,85,81,78,75,72,68,64,60,0};
double point[]={4.0, 3.7 ,3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.0, 0.0};

double ans=0;
int summ;
void dfs(int sum,int depth,double res)
{
    if(depth==4)
    {
        ans=max(ans,res);
        return;
    }
    for (int i=0;i<10;i++)
    {
        sum-=score[i];
        if(sum>=0)
        dfs(sum,depth+1,res+point[i]);
        sum+=score[i];
    }
}

int main()
{
    int n;
    
    while(~scanf("%d",&summ))
    {
        ans=0;
        dfs(summ,0,0);
        printf("%.1f\n",ans);
    }
    return 0;
}
