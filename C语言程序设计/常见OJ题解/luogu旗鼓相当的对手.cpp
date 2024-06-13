#include <stdio.h>
#include <math.h>
bool if_ok(int a [3],int b [3]);

int main()
{
	int n,i,j,cnt=0,a[1000][3]={0};
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	//录入数据
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(fabs(a[i][0]-a[j][0])<=5 &&
			   fabs(a[i][1]-a[j][1])<=5 &&
			   fabs(a[i][2]-a[j][2])<=5 &&
			   fabs(a[i][1]+a[i][2]+a[i][0]-a[j][0]-a[j][1]-a[j][2])<=10)
			   
				cnt++;
		}
	//通过新函数比较数据
	printf("%d",cnt);
	
	return 0;
}
