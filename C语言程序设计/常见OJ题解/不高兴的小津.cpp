#include <stdio.h>

int main()
{
	int h1,h2,day,max=8,i;
	//不要在程序部分打中文字符！灰色的是注释
	//h1,h2读取输入，day记载最不高兴的那天,max
	//比较上课时长
	//懂了，一天上八个小时的课就会不高兴，你也知
	//道啊
	for (i=1;i<=7;i++)//循环7次
	{
		scanf("%d%d",&h1,&h2);
		if (h1+h2>max)
			{
				max=h1+h2;
				day=i;	
			}		
	}
	printf("%d\n",day);
	
	return 0;
}
