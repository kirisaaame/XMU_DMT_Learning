#include <stdio.h>

int main()
{
	int n,i,num,up90=0,up80=0,up70=0,up60=0,down=0;
	float sum=0.0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			sum+=num;
			if (90<=num)
				up90++;
			else if(80<=num && num<90)
				up80++;
			else if (70<=num && num <80)
				up70++;
			else if (60<=num && num<70)
				up60++;
			else 
				down++;
		}
	printf("%0.1f %d %d %d %d %d\n",sum/n,up90,up80,up70,up60,down);
	
	return 0;
		
}