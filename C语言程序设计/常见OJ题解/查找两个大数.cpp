#include <stdio.h>
void find_two_largest(int a[],int n,int *largest,int *second_largest)
{
	*largest=0;*second_largest=0;
	int i;
	*largest=a[0];
	if(a[1]>a[0])
		{
		*second_largest=*largest;
		*largest=a[1];
	}
	else *second_largest=a[1];
	for (i=2;i<n;i++)
	{
		if(a[i]>=*largest)
			{
			*second_largest=*largest;
			*largest=a[i];
			}
		else if(a[i]<*largest && a[i] >*second_largest)
			*second_largest=a[i];
	}
}

int main()
{
   int i,n,arr[100],largest,second_largest;
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
   find_two_largest(arr,n,&largest,&second_largest);
   printf("%d %d",largest,second_largest);
   return 0;
}