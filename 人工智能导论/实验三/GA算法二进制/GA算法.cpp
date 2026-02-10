#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define maxpop 201 //定义种群的最大数目
#define maxstring 81 //数字串最大长度
#define n 10  //定义寻优参数最多个数
#define pi 3.1415926 
struct individual  //个体的数据结构
{
	int chrom[maxstring];
	double x[n]; //二进制串的数值
	double fitness;  //适应度值
};
double min[n],max[n];
double r[n];
double port2;
struct individual population[maxpop],oldpopu[maxpop],midst,middle,port;
int popsize=151;//种群大小
int lchrom=10;//二进制串长
int maxgen=8;//循环次数
double pcross=0.6;//交叉概率
double pmutation=0.02;//变异概率
double sumfitness;//某一代种群中的所有个体适应度的总和
double avg;//某一代种群中的平均适应度值
int p;//变量个数

//定义适应度函数;
double f(struct individual popu)
{
	double func1,func2,func;
	int j;
	double y[n];
	double u,dcu,cz,b,wm;
	double cx,tt;
	for(j=1;j<=p;j++)
		y[j]=popu.x[j];
	u=pi*y[1]*1000/60;
	cz=200/(y[1]*y[1]*(1-y[2]*y[2])*pi);
	dcu=980/(1.26*u*0.8);
	wm=exp(0.5*log(cz*cz+(u-dcu/2)*(u-dcu/2)));
	b=117600/(y[4]*y[3]*1.26*800*wm);
	cx=0.022-0.006*pi*y[1]/y[3]/b+0.018*y[4]*y[4]+0.02*2*pi/(y[3]*(1-y[2]));
	tt=pi*y[1]/y[3];
	r[1]=b/tt-0.5;
	r[2]=1.5-b/tt;
	func1=1-cx/y[4]*wm*wm/(u*cz)-0.1*y[2]*y[2]*(2-y[2]*y[2])*cz*cz/(u*dcu);
	func2=56*log(u)+10*log(980*y[1]*(1-y[2])*y[3]*exp(0.6*log(b))/2)-26.22;
	func=100*func1-func2+200;
	return(func);
}

double f2(struct individual popu)
{
	double func1,func2,func;
	int j;
	double y[n];
	double u,dcu,cz,b,wm;
	double cx;
	//double gg,tt;
	for(j=1;j<=p;j++)
		y[j]=popu.x[j];
	u=pi*y[1]*1000/60;
	cz=200/(y[1]*y[1]*(1-y[2]*y[2])*pi);
	dcu=980/(1.26*u*0.8);
	wm=exp(0.5*log(cz*cz+(u-dcu/2)*(u-dcu/2)));
	b=117600/(y[4]*y[3]*1.26*800*wm);
	cx=0.022-0.006*pi*y[1]/y[3]/b+0.018*y[4]*y[4]+0.02*2*pi/(y[3]*(1-y[2]));
	func1=1-cx/y[4]*wm*wm/(u*cz)-0.1*y[2]*y[2]*(2-y[2]*y[2])*cz*cz/(u*dcu);
	func2=56*log(u)+10*log(980*y[1]*(1-y[2])*y[3]*exp(0.6*log(b))/2);
	func=100*func1-func2+500;
	return(func);
}

	double ran(double minimum,double maximum)
	{
		double t;
		do
		{
			t=random(10001)/10000.0*20;
		}
		while((t<minimum)||(t>maximum));
		return(t);
	}

	void power(struct individual popu)
	{
		int pq;
		double gg,ff;
		gg=f(popu);
		for(pq=1;pq<=p;pq++)
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

	//种群的初始化
	void initialize()
	{
		int i,j;
		sumfitness=0.0;
		printf("Pleaser input the number of the variable:\n");
		scanf("%d",&p);
		printf("Pleaser input minimum and maxmum of each variable:\n");
		for(j=1;j<=p;j++)
			scanf("%f%f",&min[j],&max[j]);
		for(i=1;i<=popsize-1;i++)
		{
			for(j=1;j<=p;j++)
				population[i].x[j]=ran(min[j],max[j]);
			port2=f(population[i]);
			population[i].fitness=f(population[i]);
			sumfitness=sumfitness+population[i].fitness;
		}
		avg=sumfitness/(popsize-1);
		printf("\naverage of the sumfitness is %3.4f",avg);
	}

	//求适应度值的平均值
	void change()
	{
		int i;
		double ff;
		sumfitness=0.0;
		ff=population[1].fitness;
		for(i=2;i<popsize;i++)
		{
			if(ff>population[i].fitness)
				ff=population[i].fitness;
		}
		for(i=1;i<popsize;i++)
		{
			population[i].fitness=population[i].fitness-ff;
			sumfitness=sumfitness+population[i].fitness;
		}
		avg=sumfitness/(popsize-1);
	}

	//编码
	void decode()
	{
		int i,j,m,num1;
		int v;
		printf("\n");
		for(i=1;i<=popsize-1;i++)
		{
			for(j=1;j<=lchrom*p;j++)
			population[i].chrom[j]=0;
			for(j=1;j<=p;j++)
			{
				v=(int)((population[i].x[j]-min[j])*1023/(max[j]-min[j]));
				for(m=1;m<=lchrom;m++)
				{
					num1=lchrom*(j-1)+m;
					if((v%2)==1)
						population[i].chrom[num1]=1;
					if(v==1) break;
					v=v/2;
					printf("%d",population[i].chrom[num1]);
				}
			}
		}
	}

	//拷贝两个个体
	void cop(struct individual newpop,struct individual oldpop)
	{
		int j,i;
		for(j=1;j<=p;j++)
		{
			newpop.x[j]=oldpop.fitness;
			newpop.fitness=oldpop.fitness;
		}
		for(i=1;i<=lchrom;i++)
			newpop.chrom[i]=oldpop.chrom[i];
	}

	//按适应度值对种群进行排列
	void sort()
	{
		int i,j;
		for(j=1;j<=popsize-2;j++)
			for(i=1;i<popsize-j;i++)
				if((population[i].fitness)<(population[i+1].fitness))
				{
					cop(midst,population[i]);
					cop(population[i],population[i+1]);
					cop(population[i],midst);
				}
	}

	//定义布尔函数
	int flip(double pp)
	{
		double f;
		int  rand(int);

		f=Rnd(1001)/1000.0;
		printf("\n The Rnd number is %f",f);
		if(f<pp)
			return(1);
		else
			return(0);
	}
	int bol(int xp)
	{
		if(xp==0)
			return(1);
		else
			return(0);
	}

	//选择杂交与变异的个体
	int select()
	{
		double r,partsum=0.0;
		int j=0;
		int i=1;
		int  Rnd(int);
		r=rand(10001)/10000.0*sumfitness;
		do
		{
			partsum=partsum+population[i].fitness;
			i++;
		}
		while((partsum>=r)&&(++j<=popsize-1));
		return(j);
	}
	
	//杂交与变异
	void crossmutation()
	{
		int i,j,m,z;
		int bit,nv;
		int k;
		int jj=0;
		int a,t;
		nv=lchrom*p;
		for(i=1;i<popsize;i++)
		{
			a=select();
			cop(oldpopu[i],population[a]);
		}
		for(i=1;i<popsize;i++)
			cop(population[a],oldpopu[i]);
		for(i=1;i<popsize/2;i++)
		{
			m=rand(popsize-1);
			z=rand(popsize-1);
			for(k=1;k<=nv;k++)
			{
				if(population[m].chrom[k]==population[z].chrom[k])
					jj++;
				if(jj==nv)
					z=rand(popsize-1);
				if(flip(pcross))
				{
					bit=rand(nv);
					bol(bit);
					for(j=bit;j<=nv;j++)
					{
						t=population[m].chrom[j];
						population[m].chrom[j]=population[z].chrom[j];
						population[z].chrom[j]=t;
					}
				}
				if(flip(pmutation))
				{
					bit=rand(nv);
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
		for(i=1;i<=popsize;i++)
		{
			for(j=1;j<=p;j++)
			{
				double accum,powerof2;
				accum=0.0;
				powerof2=1;
				for(m=1;m<=lchrom;m++)
				{
					num2=(j-1)*lchrom+m;
					if(population[i].chrom[num2]==1)
						accum=accum+powerof2;
					powerof2=powerof2*2;
				}
				accum=accum*(max[j]-min[j])/1023.0+min[j];
				population[i].x[j]=accum;
				printf("%3.4f  ",population[i].x[j]);
			}
			printf("\n");
			population[i].fitness=f(population[i]);
		}
	}
		
		//主控程序
		void main()
		{
			int gen;
			int q;
			double g;
			void Randomize();
			initialize();
			change();
			sort();
			power(population[1]);
			decode();
			cop(port,population[1]);
			for(gen=1;gen<=25;gen++)
			{
				crossmutation();
				undecode();
				sort();
				cop(population[popsize-1],port);
				change();
			}
			sort();
			power(population[1]);
			q=(int)population[1].x[3];
			population[1].x[3]=q;
			for(q=1;q<=p;q++)
			{
				printf("%4.4f\t",population[1].x[q]);
				g=f2(population[1]);
				printf("\n%4.4f",g);
				population[1].x[1]=1.4891;
				population[1].x[2]=0.2942;
				population[1].x[3]=13;
				population[1].x[4]=1.1591;
				g=f2(population[1]);
				printf("\n%4.4f",g);
			}
		}

