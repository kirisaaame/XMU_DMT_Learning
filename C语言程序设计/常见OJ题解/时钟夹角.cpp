#include <stdio.h>
#include <assert.h>
int main(void)
{
	int n,i,hh,mm,ss,j4;
	float j1,j2,j3;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&hh,&mm,&ss);
		assert (hh<=24);
      if(hh>=12)
        hh-=12;
		j2=(mm+ss/60.0);
      j1=30.0*(hh+j2/60.0);
      j2*=6.0;
      if(j1>=j2)
		{
			if(j1-j2>180.0)
				{
				j3=360.0-j1+j2;
          j4=(int)j3;}
			else if(j1-j2<=180.0)
				{
			j3=(j1-j2);
          j4=(int)j3;}
		}
		else 
		{
			if(j2-j1>=180.0)
				{j3=(360.0-j2+j1);
          j4=(int)j3;}
			else if(j2-j1<=180.0)
				{j3=j2-j1;
          j4=(int)j3;}
		}
		printf("%d\n",j4);	
	}
	
	return 0;
}