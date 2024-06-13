#include <stdio.h>
#include <math.h>

int primes(int a[], int n)
{
 int j,k,count=0;
for (j=0;j<n;j++)
{
	int flag=1;
	if (a[j]==1);
	else
	{
	
		for(k=2;k*k<=a[j];k++)
			if (a[j]%k==0)
			{
				flag=0;
				break;
			}
	if (flag)
		count++;
}
}
return count;
}

int main()
{
  int i,n; 
  int a[10000];
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("%d", primes(a, n));
  return 0;
}
