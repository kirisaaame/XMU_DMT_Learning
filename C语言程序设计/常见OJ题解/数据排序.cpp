#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
	char num[14];
	int score[6];
	int rank;
} student;


int main()
{
	student *p;
	int n,i,j,sort;

	
	scanf("%d",&n);
	p=(student*)malloc(n*sizeof(student));
	for (i=0;i<n;i++)
	{
		scanf("%s",p[i].num);
		for (j=0;j<6;j++)
			scanf("%d",&p[i].score[j]);
		p[i].rank=1;
	}
	scanf("%d",&sort);
	sort-=1;
	//获取输入
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(p[i].score[sort]<p[j].score[sort])
				p[i].rank++;
			else if (p[i].score[sort]==p[j].score[sort] && 
			strcmp(p[i].num,p[j].num)>0)
				p[i].rank++;//计算排位
		}
	//输出排位
	for(i=1;i<=n;i++)
		for(j=0;j<n;j++)
			if(p[j].rank==i)
			{
				if(i==n)
				printf("%d",j+1);
				else 
				printf("%d\n",j+1);
				break;
			}
	
	return 0;
}