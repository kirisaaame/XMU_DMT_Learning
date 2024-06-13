#include<iostream>
using namespace std;
int main()
{
	int a[10] = {90,85,81,78,75,72,68,64,60,0};
	double b[]={4,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.0,0.0};
	int n;
	while (cin>>n)
	{
		int score;
		double grade;
		double sum = 0;
		
		if (n < 60)
			printf("0.0\n");
	
		else if (n >= 360)
			printf("16.0\n");
		else
		{
			for (int i = 0; i < 10;i++)
			for (int j = 0; i < 10;j++)
			for (int k = 0; i < 10;k++)
			for (int l = 0; i < 10;l++)
			{
				score=a[i]+a[j]+a[k]+a[l];
				grade=b[i]+b[j]+b[k]+b[l];
				if(score<n && grade>sum)
					sum=grade;
				

			}
				printf("%.1lf\n", sum);
		}
	}
	return 0;
}
