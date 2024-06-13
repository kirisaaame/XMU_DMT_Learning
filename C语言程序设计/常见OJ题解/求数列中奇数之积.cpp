#include <stdio.h>
int main()
{
  int n,i,t,sum;
  sum=1;
  while(scanf("%d",&n)==1)
  {
  
  for (i=0;i<n;i++)
  {
    scanf("%d",&t);
    if (t%2!=0)
      sum=sum*t;
  }
  printf("%d\n",sum);
  sum=1;
}

  return 0;
}
      