#include <stdio.h>
int main()
{
 float score;
 while(scanf("%f",&score)!=-1)
 	{
	 if (90<=score&&score<=100)
    {
	printf("A:[90,100]\n");}
    else if (80<=score&&score<90)
      {
	  printf("B:[80,90)\n");}
    else if (70<=score&&score<80)
      {
	  printf("C:[70,80)\n");}
    else if (60<=score&&score<70)
      {
	  printf("D:[60,70)\n");}
    else if (0<=score&&score<60)
      {
	  printf("E:[0,60)\n");}
    else
      {
	  printf("Wrong score!\n");}
}
 return 0;
}
        