#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27
#define			scaleValue  32767;
#define			InputNo 3
#define			OutputnNo 3
#define			PatternNo 358
#define			ErrorLevelValue  0.005;	//满意的误差水平
#define			wmaxValue  0.1
//  可调参数
#define			HiddenNo 10
#define			IterationsNo 1000000
#define			etaValue    0.1 //默认的学习速率
#define			alphaValue  0.1 //默认的势态因子

void main()
{
	int			nReportErrors=100;	//误差报告频率
	char		MonitorError=0;	//表示为真
	double	    error1=0.0;	    //最新的误差平方之和
	double      temp;		//临时变量
	double		out1[PatternNo][HiddenNo];	//隐含层,[模式数][隐含]
	double		delta1[PatternNo][HiddenNo];	//隐含层中的误差修正量,[模式数][隐含]
	double		delw1[HiddenNo+1][InputNo+1];	//输入与隐含层之间权值的变化,[隐含+1][输入+1]
	double		w1[HiddenNo+1][InputNo+1];	    //输入与隐含层之间的权值,[隐含+1][输入+1]
	double		out2[PatternNo][OutputnNo];	//输出层
	double		delta2[PatternNo][OutputnNo];	//输出层中的误差修正量
	double		delw2[OutputnNo][HiddenNo+1];	//隐含与输出层之间权值的变化,[输出][隐含+1]
	double		w2[OutputnNo][HiddenNo+1];	    //隐含与输出层间的权值,[输出][隐含+1]

	double      x[PatternNo][InputNo];  //历史数据输入值
	double      y[PatternNo][OutputnNo];	 //历史数据输出值
	double      out0[PatternNo+2][InputNo];
	double      target[PatternNo+2][OutputnNo];
	double      ss[InputNo];
	double		average[InputNo];
	double		sss[InputNo];
	double		fangcha[InputNo];
	double		ssy[InputNo];
	double		averagey[InputNo];
	double		sssy[InputNo];
	double		fangchay[InputNo];
	double		min;
	double		max;

	//double		out00[InputNo];
	//double		out10[HiddenNo];
	//double		out20[OutputnNo];

	int			h;	//代表隐含层的值
	int			i;	//代表输入层的值
	int			j;	//代表输出层的值
	int			p;	//模式数
	int			qq;	//循环值
	int			nPatterns=PatternNo;	//模式个数
	int			nInputNodes=InputNo;	//输入节点个数
	int			nHiddenNodes=HiddenNo;	//隐含层节点个数
	int			nOutputNodes=OutputnNo;	//输出层节点个数

	//将节点数写到数据文件中去
	ofstream my_file3;
	my_file3.open("E:/GuideSystem/小模块/S1期鼓风预测/节点数.dat",ios::out);
	my_file3<<"";
    my_file3<<nInputNodes<<"\n";
    my_file3<<nHiddenNodes<<"\n";
    my_file3<<nOutputNodes<<"\n";
	my_file3.close();	

	int			nIterations=IterationsNo;	//迭代次数
	double		frand;
	double		scale=scaleValue;
	double		errorLimit=ErrorLevelValue;	//满意的误差水平
	double		wmax=wmaxValue;
	double		eta=etaValue;	//默认的学习速率
	double		alpha=alphaValue;//默认的势态因子

//一.神经网络的训练阶段

	//将历史数据从数据文件中读入数组中
	ifstream my_file1("E:/GuideSystem/小模块/S1期鼓风预测/S1期鼓风操作数据.dat");
	my_file1.seekg(0,ios::beg);
	for(i=0;i<=nPatterns-1;i++)
	{
		for(j=0;j<=nInputNodes+2;j++)
		{
			if(j>=nInputNodes)
			{
				my_file1>>y[i][j-nInputNodes];
			}
			else
			{
				my_file1>>x[i][j];
			}
		}
	}
	my_file1.close();	



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
//		cout<<average[i]<<" ";
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
	//求自标准化后的输入值
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

	//将标准化后的输入值输到数据文件中去
	ofstream my_file5;
	my_file5.open("E:/GuideSystem/小模块/S1期鼓风预测/输入自标准化.dat",ios::out);
	my_file5<<"";

	//将输入自标准化的权值写入数据文件
	for(i=0;i<=nInputNodes-1;i++)
	{
    	 my_file5<<average[i]<<"\n";
    	 my_file5<<fangcha[i]<<"\n";
    	 my_file5<<out0[nPatterns][i]<<"\n";
    	 my_file5<<out0[nPatterns+1][i]<<"\n";
	}
	my_file5.close();


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
		cout<<"输出值平均值为:"<<averagey[i]<<" ";
	}
	cout<<endl;
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
	//求自标准化后的输出值
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
	{
		for(j=0;j<=nPatterns-1;j++)
		{
			target[j][i]=(target[j][i]-target[nPatterns][i])/(target[nPatterns+1][i]-target[nPatterns][i])*0.8+0.1;
		}
	}

	//将自标准化后的输出值输到数据文件中去
	ofstream my_file6;
	my_file6.open("E:/GuideSystem/小模块/S1期鼓风预测/输出自标准化.dat",ios::out);
	my_file6<<"";

	for(i=0;i<=nOutputNodes-1;i++)
	{
    	 my_file6<<averagey[i]<<"\n";
    	 my_file6<<fangchay[i]<<"\n";
    	 my_file6<<target[nPatterns][i]<<"\n";
    	 my_file6<<target[nPatterns+1][i]<<"\n";
	}
	my_file6.close();


	//输入-隐含层权值初始化
	for(i=0;i<=nHiddenNodes;i++)
	{
		for(j=0;j<=nInputNodes;j++)
		{
			frand=rand();
			w1[i][j]=wmax*(1.0-2*frand/scale);
			delw1[i][j]=0.0;
		}
	}

	//隐含-输出层的权值初始化
	for(i=0;i<=nOutputNodes-1;i++)
	{
		for(j=0;j<=nHiddenNodes;j++)
		{
			frand=rand();
			w2[i][j]=wmax*(1.0-2*frand/scale);
			delw2[i][j]=0.0;
		}
	}

	//开始迭代循环;
	cout<<"正在计算......"<<endl;
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
			 if(error1<errorLimit)
			 {
				  break;
			 }
		 }
	}
	cout<<"标准化后的平均误差限为:"<<error1<<endl;
//迭代循环结束

//将调节参数写入数据文件中去
	ofstream my_file7;
	my_file7.open("E:/GuideSystem/小模块/S1期鼓风预测/调节参数.dat",ios::app);
   	my_file7<<"模式个数:"<<nPatterns<<"\n";
   	my_file7<<"输入节点个数:"<<nInputNodes<<"\n";
   	my_file7<<"输出层节点个数:"<<nOutputNodes<<"\n";
   	my_file7<<"隐含层节点个数:"<<nHiddenNodes<<"\n";
   	my_file7<<"最大权值:"<<wmax<<"\n";
   	my_file7<<"学习速率:"<<eta<<"\n";
   	my_file7<<"势态因子:"<<alpha<<"\n";
   	my_file7<<"误差平方限为:"<<errorLimit<<"\n";
   	my_file7<<"最终误差平方之和为:"<<error1<<"\n";
   	my_file7<<"迭代次数为:"<<qq<<"\n\n";
	my_file7.close();



//将所有模式的目标值和输出值还原
	for(i=0;i<=nOutputNodes-1;i++)
	{
		for(j=0;j<=nPatterns-1;j++)
		{
			target[j][i]=((target[j][i]-0.1)/0.8*(target[nPatterns+1][i]-target[nPatterns][i])+target[nPatterns][i])*fangchay[i]+averagey[i];
			out2[j][i]=((out2[j][i]-0.1)/0.8*(target[nPatterns+1][i]-target[nPatterns][i])+target[nPatterns][i])*fangchay[i]+averagey[i];
		}
	}

//将原始渣成分,神经网络计算出来的渣成分,相对误差输入数据文件
	ofstream my_file;
	my_file.open("E:/GuideSystem/小模块/S1期鼓风预测/鼓风优化参数.dat",ios::out);
	my_file<<"";

	error1=0.0;
	for(p=0;p<=nPatterns-1;p++)
	{
		my_file.open("E:/GuideSystem/小模块/S1期鼓风预测/鼓风优化参数.dat",ios::app);
		 for(j=0;j<=nOutputNodes-1;j++)
		 {
    		 my_file<<p<<" "<<out2[p][j]<<" "<<target[p][j]<<" "<<(target[p][j]-out2[p][j])/target[p][j]*100<<"\n";
			 temp=target[p][j]-out2[p][j];
			 error1=error1+temp*temp;
		 }
		 my_file.close();			
	}

	error1=error1/(nPatterns*nOutputNodes);

//将权值写入数据文件
	ofstream my_file2;
	my_file2.open("E:/GuideSystem/小模块/S1期鼓风预测/权值.dat",ios::out);
	my_file2<<"";
	my_file2.open("E:/GuideSystem/小模块/S1期鼓风预测/权值.dat",ios::app);
	for(j=0;j<=nInputNodes;j++)
	{
	     my_file2<<0<<"\n";
	}
	my_file2.close();
	//将输入-隐含层的权值写入数据文件
	for(i=0;i<=nHiddenNodes;i++)
	{
		my_file2.open("E:/GuideSystem/小模块/S1期鼓风预测/权值.dat",ios::app);
		for(j=0;j<=nInputNodes;j++)
		{
    		 //my_file2<<i<<" "<<j<<" "<<w1[i][j]<<"\n";
	   		 my_file2<<w1[i][j]<<"\n";
		}
		my_file2.close();
	}
	//将隐含-输出层的权值写入数据文件
	for(i=0;i<=nOutputNodes-1;i++)
	{
		my_file2.open("E:/GuideSystem/小模块/S1期鼓风预测/权值.dat",ios::app);
		for(j=0;j<=nHiddenNodes;j++)
		{
    		//my_file2<<i<<" "<<j<<" "<<w2[i][j]<<"\n";
	    	my_file2<<w2[i][j]<<"\n";
		}
	    my_file2.close();
	}
	cout<<"训练已经结束"<<endl;
    cout<<"循环次数为:"<<qq<<endl;
	cout<<"最终原始平均误差为:"<<error1<<endl;

/*
//二.神经网络的回响阶段

	//参数样本126.5 66.51 0 46 23719 1279
	out00[0]=126.5;
	out00[1]=66.51;
	out00[2]=0;

	cout<<"回响阶段开始..."<<endl;
	cout<<"回响阶段样本输入值为:"<<" ";
	for(i=0;i<=nInputNodes-1;i++)
	{
		cout<<out00[i]<<" ";
	}
	cout<<endl;
	
	for(i=0;i<=nInputNodes-1;i++)
	{
		out00[i]=((out00[i]-average[i])/fangcha[i]-out0[nPatterns][i])/(out0[nPatterns+1][i]-out0[nPatterns][i])*0.8+0.1;
	}

	//隐含层的输出值;
	for(h=0;h<=nHiddenNodes-1;h++)
	{
		double sum=w1[h][nInputNodes];
		for(i=0;i<=nInputNodes-1;i++)
		{
			sum=sum+w1[h][i]*out00[i];
		}
		out10[h]=1.0/(1.0+exp(-sum));
	}
	//输出层的输出值
	for(j=0;j<=nOutputNodes-1;j++)
	{
		double sum=w2[j][nHiddenNodes];
		for(h=0;h<=nHiddenNodes-1;h++)
		{
			sum=sum+w2[j][h]*out10[h];
		}
		out20[j]=1.0/(1.0+exp(-sum));
	}

	cout<<"回响阶段样本输出值为"<<out20[0]<<endl;
	for(i=0;i<=nOutputNodes-1;i++)
	{
		out20[i]=((out20[i]-0.1)/0.8*(target[nPatterns+1][i]-target[nPatterns][i])+target[nPatterns][i])*fangchay[i]+averagey[i];
		cout<<out20[i]<<endl;
	}

//	cout<<"训练已经结束"<<endl;
//  cout<<"循环次数为:"<<qq<<endl;
//	cout<<"最终原始平均误差为:"<<error1<<endl;

*/

}
