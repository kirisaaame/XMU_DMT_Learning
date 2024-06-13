#include <stdio.h>
#include <math.h>
int main ()
{
  int n,i;
  double x1,x2,y1,y2,distance;
  scanf("%d",&n);
  for (i=0;i<n;i++)
  {
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    printf("%.2lf\n",distance);
  }
  
  return 0;
}
 