#include <stdio.h>
 int main()
 {
 	int n,i,left,right,c;
 	char a;
 	
 	while(scanf("%d",&n)!=-1)
 		{	
 			
		 	left=0;right=0;c=0;
 			scanf("%c",&a);
 			{
			 for (i=0;i<n;i++)
 			{
 				scanf("%c",&a);
 				if (a=='(')
 				left++;
 				else if (a==')')
 				right++;
 				if (right>left)
 				c++;
			}
			//printf("%d%d\n",left,right);
			if (c>0) printf("No\n");
			else
			{
			if (left==right)
			printf("Yes\n");
			else 
			printf("No\n");

		}
			}
		}

 	return 0;
 	
 }