#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define maxpop 160 //定义种群的最大数目
#define maxstring 81 //数字串最大长度
#define n 10  //定义寻优参数最多个数


struct individual  //个体的数据结构
{
	int chrom[maxstring];//二进制串
	double x[n]; //二进制串的十进制数值
	double fitness;  //适应度值
};

double min[n],max[n];//变量的最小和最大值
double r[n];
double port2;
struct individual population[maxpop];
struct individual oldpopu[maxpop];
struct individual midst;
struct individual middle;
struct individual port;
int popsize=50;//种群大小
int lchrom=10;//二进制串长
int maxgen=8;//循环次数
double pcross=0.6;//交叉概率
double pmutation=0.03;//变异概率
double sumfitness;//某一代种群中的所有个体适应度的总和
double avg;//某一代种群中的平均适应度值
int p;//变量个数

//定义适应度函数;
	double f(struct individual popu)
	{
		double func;
//		func=popu.x[0]*popu.x[0]+popu.x[1]*popu.x[1]+fabs(popu.x[0]);
//		return(func);
//检验函数1,求全局极小值
//		func=100*(popu.x[0]*popu.x[0]-popu.x[1])*(popu.x[0]*popu.x[0]-popu.x[1])+(1-popu.x[0])*(1-popu.x[0]);
//		return(-func);
//检验函数2,求全局极小值
//		func=(1+(popu.x[0]+popu.x[1]+1)*(popu.x[0]+popu.x[1]+1)*(19-14*popu.x[0]+3*popu.x[0]*popu.x[0]-14*popu.x[1]+6*popu.x[0]*popu.x[1]+3*popu.x[1]*popu.x[1]))*(30+(2*popu.x[0]-3*popu.x[1])*(2*popu.x[0]-3*popu.x[1])*(18-32*popu.x[0]+12*popu.x[0]*popu.x[0]+48*popu.x[1]-36*popu.x[0]*popu.x[1]+27*popu.x[1]*popu.x[1]));
//		return(-func);
//检验函数3,求全局极大值
		func=0.5-(sin(sqrt(popu.x[0]*popu.x[0]+popu.x[1]*popu.x[1]))*sin(sqrt(popu.x[0]*popu.x[0]+popu.x[1]*popu.x[1]))-0.5)/((1+0.001*(popu.x[0]*popu.x[0]+popu.x[1]*popu.x[1])*(1+0.001*(popu.x[0]*popu.x[0]+popu.x[1]*popu.x[1]))));
		return(func);
	}

//随机生成一系列介于最小与最大值间的值
	double ran(double minimum,double maximum)
	{
		double t;
		t=(maximum-minimum)*rand()/32767+minimum;
		return(t);
	}
//查找比最大的适应度值更大的适应度所对应的变量值
	void power(struct individual popu)
	{
		int pq;
		double gg,ff;
		gg=f(popu);
		for(pq=0;pq<=p-1;pq++)
		{
			popu.x[pq]=popu.x[pq]+0.1;
			if(popu.x[pq]>max[pq])
			{
				popu.x[pq]-=0.1;
				goto down;
			}
			ff=f(popu);
			if(gg<ff)
			{
				while(gg<ff)
				{
					gg=ff;
					popu.x[pq]+=0.1;
					if(popu.x[pq]>max[pq])
					{
						popu.x[pq]-=0.1;
						goto down;
					}
					ff=f(popu);
				}
			}
			else
			{
				while(gg>ff)
				{
					ff=gg;
					popu.x[pq]-=0.1;
					gg=f(popu);
					if(popu.x[pq]<min[pq])
					{
						popu.x[pq]+=0.1;
						goto down;
					}
				}
			}
down:
			continue;
		}
	}
/*
//将适应度值变换后的平均值
	void change()
	{
		int i;
		double ff;
		sumfitness=0.0;
		ff=population[0].fitness;
		for(i=1;i<=popsize-1;i++)
		{
			if(ff>population[i].fitness)
			{
				ff=population[i].fitness;
			}
		}
		for(i=0;i<=popsize-1;i++)
		{
			population[i].fitness=population[i].fitness-ff;
			sumfitness=sumfitness+population[i].fitness;
		}
		avg=sumfitness/(popsize-1);
	}
*/
//编码
	void decode()
	{
		int i,j,m,num1;
		int v;
		for(i=0;i<=popsize-1;i++)
		{
			for(j=0;j<=lchrom*p-1;j++)
			{
    			population[i].chrom[j]=0;
			}
			for(j=0;j<=p-1;j++)
			{
				v=(int)((population[i].x[j]-min[j])*(exp(lchrom*log(2))-1)/(max[j]-min[j]));
				//cout<<"v= "<<" "<<v<<endl;
				for(m=0;m<=lchrom-1;m++)
				{
					num1=lchrom*j+m;
					if((v%2)==1)
					{
						population[i].chrom[num1]=1;
					}
					else
					{
						population[i].chrom[num1]=0;
					}
					if(v==1)
					{
						break;
					}
					v=v/2;
//					cout<<population[i].chrom[num1];
				}
			}
//			cout<<endl;
		}
	}

//定义布尔函数
	int flip(double pp)
	{
		double f;

		f=rand()/32767;
		if(f<pp)
			return(1);
		else
			return(0);
	}
	int bol(int xp)
	{
		if(xp!=0)
		{
			return(1);
		}
		else
			return(0);
	}

//选择杂交与变异的个体
	int select()
	{
		double r,partsum=0.0;
		int j=0;
		int i=0;
		r=rand()/32767*sumfitness;
		do
		{
			partsum=partsum+population[i].fitness;
			i++;
		}
		while((partsum>=r)&&(++j<=popsize-1));
		return(j);
	}
	
//复制,杂交与变异
	void crossmutation()
	{
		int i,j,m,z;
		int bit,nv;
		int k;
		int ii,jj=0;
		int t;
		int beg;
		int uu,s;
		double per=0.08;//per为要保留的个体的百分比
		beg=int(popsize*per);
		nv=lchrom*p;
		//拷贝另外的(1-per)*100%
		s=beg;
		for(i=beg;i<=popsize-1;i++)
		{
			uu=int(f(population[i])/sumfitness*popsize*(1-per));
			for(j=0;j<=uu;j++)
			{
				//拷贝
				for(jj=0;jj<=p-1;jj++)
				{
					oldpopu[s+j].x[jj]=population[i].x[jj];
				}
				oldpopu[s+j].fitness=population[i].fitness;
				for(ii=0;ii<=lchrom*p-1;ii++)
				{
					oldpopu[s+j].chrom[ii]=population[i].chrom[ii];
				}
				s=s+1;
			}
		}
		cout<<" s=:"<<s<<endl;
		for(i=beg;i<=s;i++)
		{
			//拷贝
			for(jj=0;jj<=p-1;jj++)
			{
				population[i].x[jj]=oldpopu[i].x[jj];
			}
			population[i].fitness=oldpopu[i].fitness;
			for(ii=0;ii<=lchrom*p-1;ii++)
			{
				population[i].chrom[ii]=oldpopu[i].chrom[ii];
			}
		}

		for(i=beg;i<=popsize-1;i++)
			//拷贝
			for(jj=0;jj<=p-1;jj++)
			{
				population[i].x[jj]=oldpopu[i].x[jj];
			}
			population[i].fitness=oldpopu[i].fitness;
			for(ii=0;ii<=lchrom*p-1;ii++)
			{
				population[i].chrom[ii]=oldpopu[i].chrom[ii];
			}

		//交叉与变异
		for(i=beg;i<=(popsize-1-beg)/2;i++)

		{
			m=int((popsize-1-beg)*rand()/32767+beg);
			z=int((popsize-1-beg)*rand()/32767+beg);
			for(k=0;k<=nv-1;k++)
			{
				if(population[m].chrom[k]==population[z].chrom[k])
					jj++;
				if(jj==nv)
					z=int((popsize-1-beg)*rand()/32767+beg);
				if(flip(pcross))
				{
					bit=int((nv-1)*rand()/32767+1);
					bol(bit);
					for(j=bit;j<=nv-1;j++)
					{
						t=population[m].chrom[j];
						population[m].chrom[j]=population[z].chrom[j];
						population[z].chrom[j]=t;
					}
				}
				if(flip(pmutation))
				{
					bit=int((nv-1)*rand()/32767+1);
					bol(bit);
					population[m].chrom[j]=!(population[m].chrom[bit]);
					population[z].chrom[j]=!(population[z].chrom[bit]);
				}
			}
		}
	}

	//解码
	void undecode()
	{
		int i,j,num2,m;
		sumfitness=0.0;
		for(i=0;i<=popsize-1;i++)
		{
			for(j=0;j<=p-1;j++)
			{
				double accum,powerof2;
				accum=0.0;
				powerof2=1;
				for(m=0;m<=lchrom-1;m++)
				{
					num2=j*lchrom+m;
					if(population[i].chrom[num2]==1)
						accum=accum+powerof2;
					powerof2=powerof2*2;
				}
				accum=accum*(max[j]-min[j])/(exp(lchrom*log(2))-1)+min[j];
				population[i].x[j]=accum;
//				cout<<population[i].x[j]<<" ";
			}
//			cout<<endl;
			population[i].fitness=f(population[i]);
		}
	}
		
//主控程序
void main()
{

	int i,j,ii,jj;
	double eps;  //eps----代表平均适应度与最大适应度间的误差
	int times;//循环次数;
	//1.种群的初始化
		times=0;
//		eps=70;
		eps=0.01;
		sumfitness=0.0;
		cout<<"Pleaser input the number of the variable:"<<endl;
		cin>>p;
		cout<<"Please input minimum and maxmum of each variable:"<<endl;
		for(j=0;j<=p-1;j++)
		{
			cin>>min[j]>>max[j];
		}
		for(i=0;i<=popsize-1;i++)
		{
			for(j=0;j<=p-1;j++)
			{
				population[i].x[j]=ran(min[j],max[j]);
				//cout<<population[i].x[j]<<" ";
			}
			cout<<endl;
//			port2=f(population[i]);
			population[i].fitness=f(population[i]);
			sumfitness=sumfitness+population[i].fitness;
			//cout<<population[i].fitness<<endl;
		}
		avg=sumfitness/popsize;
		//cout<<"average of the sumfitness is "<<avg;

//2.按适应度值对种群进行由大到小排列
	for(j=0;j<=popsize-2;j++)
	{
		for(i=0;i<=popsize-2-j;i++)
		{
			if((population[i].fitness)<(population[i+1].fitness))
			{

				//拷贝
				for(jj=0;jj<=p-1;jj++)
				{
					midst.x[jj]=population[i].x[jj];
				}
				midst.fitness=population[i].fitness;
				for(ii=0;ii<=lchrom*p-1;ii++)
				{
					midst.chrom[ii]=population[i].chrom[ii];
				}
				//拷贝
				for(jj=0;jj<=p-1;jj++)
				{
					population[i].x[jj]=population[i+1].x[jj];
				}
				population[i].fitness=population[i+1].fitness;
				for(ii=0;ii<=lchrom*p-1;ii++)
				{
					population[i].chrom[ii]=population[i+1].chrom[ii];
				}
				//拷贝
				for(jj=0;jj<=p-1;jj++)
				{
					population[i+1].x[jj]=midst.x[jj];
				}
				population[i+1].fitness=midst.fitness;
				for(ii=0;ii<=lchrom*p-1;ii++)
				{
					population[i+1].chrom[ii]=midst.chrom[ii];
				}
			}
		}
		//cout<<population[j].x[0]<<" "<<population[j].x[1]<<" "<<population[j].fitness<<endl;
	}
	//cout<<endl;
	cout<<" 正在计算... ";
//开始进入循环
	while(fabs(avg-f(population[0]))>eps)
	{
	//3.在第一个值附近查找比它更大的值
		power(population[0]);
	//4.编码
		decode();
	//5.将适应度值最大的前per*100%的个体直接带入下一代
	//6.对复制的(1-per)n个个体进行交叉操作
		crossmutation();
	//7.对个体进行变异操作
	//8.解码
		undecode();
	//9.计算适合度
		for(i=0;i<=popsize-1;i++)
		{
			population[i].fitness=f(population[i]);
			sumfitness=sumfitness+population[i].fitness;
//			cout<<population[i].fitness<<endl;
		}
	//10.求适合度的平均值
		avg=sumfitness/popsize;
		//cout<<"average of the sumfitness is "<<avg<<" ";
	//11.重新排序
		for(j=0;j<=popsize-2;j++)
		{
			for(i=0;i<=popsize-2-j;i++)
			{
				if((population[i].fitness)<(population[i+1].fitness))
				{

					//拷贝
					for(jj=0;jj<=p-1;jj++)
					{
						midst.x[jj]=population[i].x[jj];
					}
					midst.fitness=population[i].fitness;
					for(ii=0;ii<=lchrom*p-1;ii++)
					{
						midst.chrom[ii]=population[i].chrom[ii];
					}

					//拷贝
					for(jj=0;jj<=p-1;jj++)
					{
						population[i].x[jj]=population[i+1].x[jj];
					}
					population[i].fitness=population[i+1].fitness;
					for(ii=0;ii<=lchrom*p-1;ii++)
					{
						population[i].chrom[ii]=population[i+1].chrom[ii];
					}

					//拷贝
					for(jj=0;jj<=p-1;jj++)
					{
						population[i+1].x[jj]=midst.x[jj];
					}
					population[i+1].fitness=midst.fitness;
					for(ii=0;ii<=lchrom*p-1;ii++)
					{
						population[i+1].chrom[ii]=midst.chrom[ii];
					}
				}
			}
//			cout<<population[j].x[0]<<" "<<population[j].x[1]<<" "<<population[j].fitness<<endl;
		}
//		cout<<endl;
		times=times+1;
		cout<<"第"<<times<<"次时"<<" 该函数的最大值为:"<<" "<<f(population[0])<<"对应的坐标为:"<<population[0].x[0]<<" "<<population[0].x[1]<<" "<<endl;
		//12.结束循环
	}
	cout<<"计算已结束.";
	cout<<" 该函数的最大值为:"<<f(population[0])<<endl;
	cout<<" 平均值为:"<<avg<<endl;
	cout<<" 循环次数为: "<<times<<endl;
}
