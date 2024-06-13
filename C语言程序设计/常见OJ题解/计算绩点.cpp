#include <stdio.h>

int main(void)
{
	int n,i,grade,point,tpoint=0;
	float gpa,tgarde=0.0;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&grade,&point);
		tpoint+=point;
		
			if (90<=grade)
				tgarde+=4.0*point;
			else if (85<=grade &&grade<90)
				tgarde+=3.7*point;
			else if (81<=grade &&grade<85)
				tgarde+=3.3*point;
			else if (78<=grade&&grade<81)
				tgarde+=3.0*point;
			else if (75<=grade&&grade<78)
				tgarde+=2.7*point;
			else if (72<=grade&&grade<75)
				tgarde+=2.3*point;
			else if (68<=grade&&grade<72)
				tgarde+=2.0*point;
			else if (64<=grade&&grade<68)
				tgarde+=1.7*point;
			else if (60<=grade&&grade<64)
				tgarde+=1.0*point;
			else
				;
		
	}
	gpa=tgarde/tpoint;
	printf("%.4f",gpa);
	
	return 0;
}