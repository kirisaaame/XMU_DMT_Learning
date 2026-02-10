#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27

void main()
{
	int			nReportErrors=100;	//误差报告频率
	char		MonitorError=0;	//表示为真
	double	    error1=0.0;	    //最新的误差平方之和
	double      temp;		//临时变量
//	double		out0[66][9];   //输入层
	double		out1[66][5];	//隐含层,[模式数][隐含]
	double		delta1[66][5];	//隐含层中的误差修正量,[模式数][隐含]
	double		delw1[6][10];	//输入与隐含层之间权值的变化,[隐含+1][输入]
	double		w1[6][10];	    //输入与隐含层之间的权值,[隐含+1][输入]
	double		out2[66][1];	//输出层
	double		delta2[66][1];	//输出层中的误差修正量
	double		delw2[1][6];	//隐含与输出层之间权值的变化,[输出][隐含+1]
	double		w2[1][6];	    //隐含与输出层间的权值,[输出][隐含+1]
//	double		target[66][1];	//目标输出值
	double    x[66][9]={{0.05,2.32,0.21,0.073,26,340,690,8,18},{0.05,2.25,0.19,0.072,30,340,695,8,18},{0.05,2.30,0.25,0.080,29,300,700,9,17},{0.04,2.18,0.20,0.080,27,350,700,8,16},{0.07,2.27,0.25,0.084,30,320,700,9,17},{0.05,2.42,0.22,0.084,28,310,700,7,17},{0.06,2.23,0.22,0.084,30,320,700,9,17},{0.06,2.43,0.26,0.085,27,330,695,8,17},{0.05,2.00,0.21,0.073,27,330,695,8,17},{0.04,2.55,0.20,0.087,28,360,700,7,15},{0.05,2.10,0.17,0.078,28,350,700,9,14},{0.04,2.27,0.25,0.071,30,305,700,9,17},{0.07,2.38,0.22,0.079,27,350,695,8,16},{0.05,2.31,0.32,0.062,28,360,700,7,15},{0.05,2.29,0.21,0.082,30,340,695,8,18},{0.05,2.26,0.23,0.084,27,320,695,9,16},{0.05,2.41,0.23,0.081,26,345,700,9,16},{0.06,2.41,0.22,0.083,27,340,690,8,16},{0.05,2.27,0.20,0.069,26,370,700,6,18},{0.05,2.18,0.20,0.084,27,350,700,8,16},
				{0.06,2.34,0.24,0.079,29,320,700,8,18},{0.05,2.33,0.22,0.078,28,350,700,9,14},{0.05,2.32,0.22,0.071,27,310,700,9,18},{0.07,2.04,0.24,0.068,28,330,690,8,18},{0.04,2.60,0.20,0.088,28,330,700,5,17},{0.05,2.51,0.24,0.087,27,360,700,9,16},{0.04,2.18,0.23,0.083,27,380,695,9,16},{0.06,2.21,0.21,0.081,27,350,695,8,16},{0.06,2.20,0.22,0.060,27,320,690,8,18},{0.07,2.39,0.30,0.085,26,365,695,9,17},{0.06,2.03,0.21,0.077,30,300,690,8,16},{0.04,2.47,0.28,0.074,30,305,700,9,17},{0.05,2.31,0.22,0.074,29,290,695,8,18},{0.07,2.41,0.22,0.081,26,320,695,8,15},{0.04,2.37,0.37,0.086,28,320,700,9,16},{0.06,2.60,0.22,0.087,33,290,695,8,17},{0.06,2.13,0.23,0.077,28,330,700,6,18},{0.06,2.25,0.22,0.085,29,335,700,9,17},{0.06,2.36,0.23,0.080,28,330,700,6,18},{0.08,2.33,0.26,0.082,28,325,690,8,20},
				{0.07,2.18,0.26,0.079,29,320,695,7,16},{0.07,2.59,0.24,0.089,29,330,690,8,18},{0.08,2.50,0.21,0.085,30,220,690,9,17},{0.08,2.65,0.25,0.087,26,350,695,8,19},{0.05,2.35,0.26,0.082,29,310,695,9,18},{0.07,2.02,0.30,0.070,28,360,700,8,16},{0.05,2.64,0.24,0.078,28,390,700,9,15},{0.07,2.22,0.32,0.080,28,280,700,6,15},{0.08,2.44,0.25,0.081,28,300,700,9,17},{0.08,2.40,0.29,0.075,29,360,695,8,17},{0.04,2.03,0.18,0.080,33,265,695,8,16},{0.06,2.44,0.22,0.073,29,320,700,9,17},{0.09,2.09,0.20,0.072,28,330,700,6,18},{0.07,2.53,0.25,0.085,29,300,700,9,15},{0.07,2.54,0.23,0.088,27,380,690,8,17},{0.07,2.45,0.24,0.071,28,340,700,7,15},{0.08,2.39,0.24,0.086,29,290,695,8,18},{0.06,2.58,0.23,0.087,28,355,695,6,16},{0.06,2.48,0.23,0.074,29,310,695,8,18},{0.07,2.50,0.24,0.081,30,310,695,9,18},
				{0.06,2.13,0.19,0.073,30,280,695,7,16},{0.07,2.39,0.25,0.082,31,280,695,6,17},{0.07,2.35,0.20,0.090,30,695,8,17},{0.10,2.68,0.30,0.087,27,300,700,9,17},{0.07,2.40,0.26,0.082,27,310,700,9,18},{0.05,2.23,0.21,0.081,29,360,695,8,17}};
	double    y[66][1]={{435},{442},{450},{453},{455},{456},{460},{461},{463},{467},{467},{468},{470},{471},{472},{475},{476},{478},{478},{484},{485},{486},{487},{488},{489},{491},{492},{493},{496},{496},{497},{498},{498},{499},{499},{520},{521},{524},{525},{526},{527},{528},{528},{529},{533},{534},{535},{536},{536},{538},{539},{539},{540},{543},{543},{546},{548},{548},{550},{551},{551},{553},{553},{554},{558},{567}};
	double    out0[68][9];
	double    target[68][1];
	double ss[9];
	double average[9];
	double sss[9];
	double fangcha[9];
	double ssy[9];
	double averagey[9];
	double sssy[9];
	double fangchay[9];
	double min;
	double max;

	int h;	//代表隐含层的值
	int	i;	//代表输入层的值
	int	j;	//代表输出层的值
	int	p;	//模式数
	int	qq;	//循环值
	int	nPatterns=66;	//模式个数
	int	nInputNodes=9;	//输入节点个数
	int	nHiddenNodes=5;	//隐含层节点个数
	int	nOutputNodes=1;	//输出层节点个数
	int nIterations=500000;	//迭代次数
	double frand;
	double ErrorLevel=0.002;	//满意的误差水平
	double wmax=0.3;
	double scale=32767;
	double eta=0.35;	//默认的学习速率
	double alpha=0.1;//默认的势态因子

//将输入与输出值标准化;
//1.对输入值标准化	
	//求均值;
	for(i=0;i<=nInputNodes-1;i++)
	{
		ss[i]=0;
		for(j=0;j<=nPatterns-1;j++)
		{
			ss[i]=ss[i]+x[j][i];
		}
		average[i]=ss[i]/nPatterns;
		cout<<average[i]<<" ";
	}
	//求方差;
	for(i=0;i<=nInputNodes-1;i++)
	{
		sss[i]=0;
		for(j=0;j<=nPatterns-1;j++)
		{
			sss[i]=sss[i]+(x[j][i]-average[i])*(x[j][i]-average[i]);
		}
		fangcha[i]=sqrt(sss[i]/(nPatterns-1));
	}
	//求自标准化后的输入值与输出值
	for(i=0;i<=nInputNodes-1;i++)
	{
		min=1000.0;
		max=-1000.0;
		for(j=0;j<=nPatterns-1;j++)
		{
			out0[j][i]=(x[j][i]-average[i])/fangcha[i];
			//cout<<out0[j][i]<<" ";
			if(out0[j][i]<=min)
			{
				min=out0[j][i];
			}
			if(out0[j][i]>=max)
			{
				max=out0[j][i];
			}
		}
		//cout<<endl;
		out0[nPatterns][i]=min;
		out0[nPatterns+1][i]=max;
	}
	//标准化
	for(i=0;i<=nInputNodes-1;i++)
		for(j=0;j<=nPatterns-1;j++)
		{
			out0[j][i]=(out0[j][i]-out0[nPatterns][i])/(out0[nPatterns+1][i]-out0[nPatterns][i])*0.8+0.1;
//			cout<<out0[j][i]<<" ";
		}
//		cout<<endl;
//2.对输出值标准化
	//求均值;
	for(i=0;i<=nOutputNodes-1;i++)
	{
		ssy[i]=0;
		for(j=0;j<=nPatterns-1;j++)
		{
			ssy[i]=ssy[i]+y[j][i];
		}
		averagey[i]=ssy[i]/nPatterns;
		cout<<averagey[i]<<" ";
	}
	//求方差;
	for(i=0;i<=nOutputNodes-1;i++)
	{
		sssy[i]=0;
		for(j=0;j<=nPatterns-1;j++)
		{
			sssy[i]=sssy[i]+(y[j][i]-averagey[i])*(y[j][i]-averagey[i]);
		}
		fangchay[i]=sqrt(sssy[i]/(nPatterns-1));
	}
	//求自标准化后的输入值与输出值
	for(i=0;i<=nOutputNodes-1;i++)
	{
		min=1000.0;
		max=-1000.0;
		for(j=0;j<=nPatterns-1;j++)
		{
			target[j][i]=(y[j][i]-averagey[i])/fangchay[i];
			if(target[j][i]<=min)
			{
				min=target[j][i];
			}
			if(target[j][i]>=max)
			{
				max=target[j][i];
			}
		}
		target[nPatterns][i]=min;
		target[nPatterns+1][i]=max;
	}
	//标准化
	for(i=0;i<=nOutputNodes-1;i++)
		for(j=0;j<=nPatterns-1;j++)
		{
			target[j][i]=(target[j][i]-target[nPatterns][i])/(target[nPatterns+1][i]-target[nPatterns][i])*0.8+0.1;
//			cout<<target[j][i]<<" ";
		}
		cout<<endl;


	//读输入-隐含层权值
	for(i=0;i<=nHiddenNodes;i++)
	{
		for(j=0;j<=nInputNodes;j++)
		{
			frand=rand();
			w1[i][j]=wmax*(1.0-2*frand/scale);
			delw1[i][j]=0.0;
		}
	}
	cout<<endl;
	//读隐含-输出层的权值
	for(i=0;i<=nOutputNodes-1;i++)
	{
		for(j=0;j<=nHiddenNodes;j++)
		{
			frand=rand();
			w2[i][j]=wmax*(1.0-2*frand/scale);
			delw2[i][j]=0.0;
		}
	}
	cout<<endl;
	//开始迭代循环;
	cout<<"正在计算......";
	 for(qq=0;qq<=nIterations;qq++)
	 {
		 for(p=0;p<=nPatterns-1;p++)
		 {
			//隐含层的输出值;
			for(h=0;h<=nHiddenNodes-1;h++)
			{
				double sum=w1[h][nInputNodes];
				for(i=0;i<=nInputNodes-1;i++)
				{
					sum=sum+w1[h][i]*out0[p][i];
				}
				out1[p][h]=1.0/(1.0+exp(-sum));
			}
			//输出层的输出值
			for(j=0;j<=nOutputNodes-1;j++)
			{
				double sum=w2[j][nHiddenNodes];
				for(h=0;h<=nHiddenNodes-1;h++)
				{
					sum=sum+w2[j][h]*out1[p][h];
				}
				out2[p][j]=1.0/(1.0+exp(-sum));
			}
			//输出层的误差
			for(j=0;j<=nOutputNodes-1;j++)
			{
				delta2[p][j]=(target[p][j]-out2[p][j])*out2[p][j]*(1.0-out2[p][j]);
			}
			//隐含层的误差
			for(h=0;h<=nHiddenNodes-1;h++)
			{
				double sum=0.0;
				for(j=0;j<=nOutputNodes-1;j++)
				{
					sum=sum+delta2[p][j]*w2[j][h];
				}
				delta1[p][h]=sum*out1[p][h]*(1.0-out1[p][h]);
			}
		 }

		//调整隐含-输出层间的权值
		 for(j=0;j<=nOutputNodes-1;j++)
		 {
			 double dw;
			 double sum=0.0;
			 for(p=0;p<=nPatterns-1;p++)
			 {
				 sum=sum+delta2[p][j];
			 }
			 dw=eta*sum+alpha*delw2[j][nHiddenNodes];
			 w2[j][nHiddenNodes]+=dw;
			 delw2[j][nHiddenNodes]=dw;
			 for(h=0;h<=nHiddenNodes-1;h++)
			 {
				double sum=0.0;
				for(p=0;p<=nPatterns-1;p++)
				{
					sum=sum+delta2[p][j]*out1[p][h];
				}
				dw=eta*sum+alpha*delw2[j][h];
				w2[j][h]=w2[j][h]+dw;
				delw2[j][h]=dw;
			 }
		 }
		//调整输入-隐含层的权值
		 for(h=0;h<=nHiddenNodes-1;h++)
		 {
			 double dw;
			 double sum=0.0;
			 for(p=0;p<=nPatterns-1;p++)
			 {
				 sum=sum+delta1[p][h];
			 }
			 dw=eta*sum+alpha*delw1[h][nInputNodes];
			 w1[h][nInputNodes]+=dw;
			 delw1[h][nInputNodes]=dw;
			 for(i=0;i<=nInputNodes-1;i++)
			 {
				double sum=0.0;
				for(p=0;p<=nPatterns-1;p++)
				{
					sum=sum+delta1[p][h]*out0[p][i];
				}
				dw=eta*sum+alpha*delw1[h][i];
				w1[h][i]=w1[h][i]+dw;
				delw1[h][i]=dw;
			 }
		 }

		 //计算均方根误差
		 if(MonitorError||(qq%nReportErrors==0))
		 {
			 error1=0.0;
			 for(p=0;p<=nPatterns-1;p++)
			 {
				 for(j=0;j<=nOutputNodes-1;j++)
				 {
					 temp=target[p][j]-out2[p][j];
					 error1=error1+temp*temp;
				 }
			 }
			 //所有模式每个节点的平均误差
			 error1=error1/(nPatterns*nOutputNodes);
			 MonitorError=0;
			 if(error1<ErrorLevel)
			 {
				cout<<"最终平均误差为:"<<error1<<endl;
				  break;
			 }
		 }
	}
	//迭代循环结束
	//计算所有模式的平均误差

	ofstream my_file;
	my_file.open("BP算法.dat",ios::out);
	my_file<<"";

	error1=0.0;
	for(p=0;p<=nPatterns-1;p++)
	{
		my_file.open("BP算法.dat",ios::app);
		 for(j=0;j<=nOutputNodes-1;j++)
		 {
    		 my_file<<p<<" "<<out2[p][j]<<" "<<target[p][j]<<" "<<(target[p][j]-out2[p][j])/target[p][j]*100<<"\n";
			 cout<<"out2["<<p<<"]["<<j<<"]="<<out2[p][j]<<"  target["<<p<<"]["<<j<<"]="<<target[p][j]<<endl;
			 temp=target[p][j]-out2[p][j];
			 error1=error1+temp*temp;
		 }
		 my_file.close();			
	}
	error1=error1/(nPatterns*nOutputNodes);


	for(i=0;i<=nHiddenNodes;i++)
	{
		for(j=0;j<=nInputNodes;j++)
		{
			cout<<"w1["<<i<<"]["<<j<<"] "<<w1[i][j]<<"  ";
		}
		cout<<endl;
	}

	//读隐含-输出层的权值
	for(i=0;i<=nOutputNodes-1;i++)
	{
		for(j=0;j<=nHiddenNodes;j++)
		{
			cout<<"w2["<<i<<"]["<<j<<"] "<<w2[i][j]<<"  ";
		}
		cout<<endl;
	}

    cout<<"循环次数为:"<<qq<<endl;
	cout<<"循环已经结束";
	cout<<"最终平均误差为:"<<error1<<endl;
}