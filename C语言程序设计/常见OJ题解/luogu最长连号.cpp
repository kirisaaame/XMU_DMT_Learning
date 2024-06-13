#include <stdio.h>

int main()
{
	int n,i,s1,s2,cnt,cntmax;
	
	scanf("%d",&n);
	scanf("%d",&s1);
	cnt=1;
	cntmax=1;
	
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&s2);
		if (s2==s1+1)
		{
			cnt++;
			if(cnt>cntmax) cntmax=cnt;
		}
		else
			cnt=1;
		s1=s2;
	}
	printf("%d",cntmax);
	
	return 0;
}