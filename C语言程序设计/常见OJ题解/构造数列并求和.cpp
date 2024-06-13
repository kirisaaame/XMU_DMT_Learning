#include <stdio.h>
#include <math.h>
int main()
{
  int n,i;
  double m,t,sum;
  while (scanf("%lf%d",&m,&n)!=-1)
  {
    sum=0.0;
    t=m;
    for (i=0;i<n;i++)
    {
      sum=sum+t;
      t=sqrt(t);
    }
    sum=int(sum*100)/100.0;
    printf("%.2lf\n",sum);
  }
  
  return 0;
  
}
    