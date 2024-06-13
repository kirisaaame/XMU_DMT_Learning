#include <stdio.h>
int main()
{
  int m,n,i,square,cube;
  while(scanf("%d%d",&m,&n)!=-1)
  {
    square=0;
    cube=0;
  for (i=m;i<=n;i++)
  {
    if (i%2==0)
      square=square+i*i;
    else 
      cube=cube+i*i*i;
  }
    printf("%d %d\n",square,cube);
  }
  
  return 0;
}
    
      