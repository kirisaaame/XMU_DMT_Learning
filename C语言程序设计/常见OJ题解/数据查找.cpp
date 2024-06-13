#include <stdio.h>

int main()
{
	int n,i,k,s,count=0;
	int goods[1000][5];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&goods[i][0],&goods[i][1],&goods[i][2],&goods[i][3]);
	scanf("%d%d",&k,&s);
	
	for(i=0;i<n;i++)
		if(goods[i][k]>=s)
		{
			count++;
			printf("%d %d %d %d\n",goods[i][0],goods[i][1],goods[i][2],goods[i][3]);
		}
	if (count==0)
		printf("nothing");
	return 0;
}