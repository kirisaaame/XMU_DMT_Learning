#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//随机生成一系列介于0与1间的值
	double ran(double minimum,double maximum)
	{
		double w;
			w=(double)rand()/32767;
		return(w);
	}
		
//主控程序
void main()
{

	//梯度下降法用到的变量
	double x01,x02;
	double x1,x2,y0,y1;
	double pian1,pian2,lemda;
	int t;
	int u; //总的迭代次数
	//混沌优化法用到的变量
	int j,p;
	double min[2],max[2];
	double v[2];
	int times;//循环次数;
	double q0;

	//变量
	x01=-0.2;
	x02=2.5;
	lemda=0.1;
	t=0;
	u=0;

	cout<<" 开始计算... "<<endl;

	while(t<=10)
	{
		u=u+1;
		//梯度下降法寻优
		//y0=x01*x01+25*x02*x02;
		y0=4+4.5*x01-4*x02+x01*x01+2*x02*x02-2*x01*x02+x01*x01*x01*x01-2*x01*x01*x02;
		//y0=100*(x01-x02)+(1-x01)*(1-x01);

		//对第一个变量的偏导数
		//pian1=2*x01;
		pian1=4.5+2*x01-2*x02+4*x01*x01*x01-4*x01*x02;
		//pian1=100-2*(1-x01);

		//对第二个变量的偏导数
		//pian2=50*x02;
		pian2=-4+4*x02-2*x01-2*x01*x01;
		//pian2=-100;

		//x1=x01-lemda*(2*x01)/sqrt(4*x01*x01+2500*x02*x02);
		x1=x01-lemda*pian1/sqrt(pian1*pian1+pian2*pian2);

		//x2=x02-lemda*(25*x02)/sqrt(4*x01*x01+2500*x02*x02);
		x2=x02-lemda*pian2/sqrt(pian1*pian1+pian2*pian2);

		//y1=x1*x1+25*x2*x2;
		y1=4+4.5*x1-4*x2+x1*x1+2*x2*x2-2*x1*x2+x1*x1*x1*x1-2*x1*x1*x2;
		//y1=100*(x1-x2)+(1-x1)*(1-x1);

		if(y1<y0)
		{
			x01=x1;
			x02=x2;
		}

		cout<<" 总迭代次数为 "<<u<<"  "<<"自变量为"<<x01<<"    "<<x02<<" 当前极小值为 "<<y0<<" t值为 "<<t<<endl;
	}
	cout<<"极小值为: "<<y0<<endl;
	cout<<"计算已结束."<<endl;
}
