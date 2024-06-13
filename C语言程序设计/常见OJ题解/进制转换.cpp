#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int n,d,i,j,digit;
	char num[32];
	
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
		{
			digit=0;
			scanf("%s",num);
			d=strlen(num);
			for(j=0;j<d;j++)
					if (num[j]=='1')
						digit+=	pow(2,d-j-1);
			printf("%d\n",digit);
		}
		
	return 0;
}