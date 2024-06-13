#include <stdio.h>
int zuidagongyueshu(int a,int b);
int zuixiaogongbeishu(int a,int b);

  int main(void)
{
  	int a,b;
	scanf("%d%d",&a,&b);
  	printf("%d %d",zuidagongyueshu(a,b),zuixiaogongbeishu(a,b));
  
  return 0;
}

int zuidagongyueshu(int a,int b)
{
	while(a^=b%=a);
      return a;
}

int zuixiaogongbeishu(int a,int b)
{
  int c=a*b/zuidagongyueshu(a,b);
  return c;
}