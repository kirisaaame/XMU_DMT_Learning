#include <stdio.h>
 int main()
 {
 	int n,i,p_ct,o_ct,n_ct;
 	double a;
 	while(scanf("%d",&n)!=-1)
 		{	p_ct=0;o_ct=0;n_ct=0;
 			if (n==0) break;
 			else
 			{
			 for (i=0;i<n;i++)
 			{
 				scanf("%lf",&a);
				if (a>0)	p_ct++;
				else if (a<0) n_ct++;
				else o_ct++;
			}
			printf("%d %d %d\n",n_ct,o_ct,p_ct);
			}
		}

 	return 0;
 	
 }