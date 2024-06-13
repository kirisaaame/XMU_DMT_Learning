#include <stdio.h>

int main()
{
	char ch,al[100];
	int i,num,anum,count[100]={0};
	ch=getchar();
	al[anum]=ch;
	count[anum]++;
	while ((ch=getchar())!=-1 && ch!='\n') 
	{
		if(ch==al[anum])
			{
			count[anum]++;
			}
		else
			{
			anum++;num++;
			al[anum]=ch;
			count[anum]++;
			}
			
	}
	for (i=0;i<num;i++)
	printf("%c%d ",al[i],count[i]);
}
	
 
