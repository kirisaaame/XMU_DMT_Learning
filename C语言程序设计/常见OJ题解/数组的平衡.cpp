#include <stdio.h>
#include <math.h>

int center(int a[], int n)
{
	int ctr=1,i,j,lsum,rsum,result,min;
	for (i=1;i<=n;i++)
		min+=a[i];
	for (i=1;i<n;i++)
	{
		lsum=0;rsum=0;
		for(j=1;j<=i;j++)
			lsum+=a[j];
		for(j=i+1;j<=n;j++)
			rsum+=a[j];
		result=fabs(lsum-rsum);
		if (result<min)
			{
				min=result;
				ctr=i;
			}
	}
	return ctr;
}

int main()
{
  int i, n, a[10001];
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("%d", center(a, n));
  return 0;
}