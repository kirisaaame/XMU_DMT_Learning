#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define maxpop 201
#define maxstring 81
#define n 10
#define pi 3.1415926
struct individual
{
	double chrom[maxstring];
	double x[n];
	double fitness;
};
double min[n],max[n];
struct individual population[maxpop],midst,mid;
int popsize=151;
int maxgen=15;
double pcross=0.6;
double pmutation=0.02;
double sumfitness;
double avg;
int p;

//定义适应度函数;
double f(struct individual popu)
{
	int k;
	double func;
	int j;
	double y[n];
	for(j=1;j<=p;j++)
	{
		k=(j-1)*2+1;
		popu.x[j]=popu.chrom[k]+popu.chrom[k+1];
		y[j]=popu.x[j];
	}
	func=(4-2.1*y[1]*y[1]+y[1]*y[1]*y[1]*y[1]/3)*y[1]*y[1];
	func=func+y[1]*y[2]+(4*y[2]*y[2]-4)*y[2]*y[2];
	func=-func+10000;
	return(func);
}

	void power(struct individual popu)
	{
		int j,i,z;
		double g,t1;
		g=f(popu);
ff:
		for(j=1;j<=p;j++)
		{
			popu.x[j]-=0.01;
			t1=f(popu);
			if(popu.x[j]<min[j])
			{
				popu.x[j]+=0.1;
				goto down;
			}
			if(t1<g)
			{
				while(t1<g)
				{
					g=t1;
					popu.x[j]-=0.01;
					if(popu.x[j]<min[j])
					{
						popu.x[j]+=0.1;
						goto down;
					}
					t1=f(popu);
				}
			}
			else
			{
				while(t1>g)
				{
					t1=g;
					popu.x[j]+=0.01;
					if(popu.x[j]>max[j])
					{
						popu.x[j]-=0.01;
						goto down;
					}
					g=f(popu);
				}
			}
down:
			continue;
		}
	}

	double ran(double minimum,double maximum)
	{
		double t;
		do
		{
			t=Rnd(10001)/10000.0*10;
		}
		while((t<minimum)||(t>maximum));
		return(t);
	}

		//种群的初始化
	void initialize()
	{
		int i,j,k;
		sumfitness=0.0;
		printf("Pleaser input the number of the variable:\n");
		scanf("%d",&p);
		printf("Pleaser input minimum and maxmum of each variable:\n");
		for(j=1;j<=p;j++)
			scanf("%f%f",&min[j],&max[j]);
		for(i=1;i<=popsize-1;i++)
		{
			for(j=1;j<=p;j++)
				printf("%3.4f",population[i].x[j]);
			printf("\n");
			population[i].fitness=f(population[i]);
			sumfitness=sumfitness+population[i].fitness;
		}
		avg=sumfitness/(popsize-1);
		printf("\naverage of the sumfitness is %3.4f",avg);
	}

	//拷贝两个个体
	void cop(struct individual newpop,struct individual oldpop)
	{
		int j,i;
		for(j=1;j<=p;j++)
			newpop.x[j]=oldpop.fitness;
			newpop.fitness=oldpop.fitness;
		for(i=1;i<=2*p;i++)
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
		int  Rnd(int);
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
		r=Rnd(10001)/10000.0*sumfitness;
		do
		{
			partsum=partsum+population[i].fitness;
			i++;
			j++;
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
		double t;
		int  Rnd(int);
		nv=2*p;
		for(i=1;i<popsize-1;i++)
		{
			int a=select();
			bol(a);
			cop(population[i],population[a]);
		}
		for(i=1;i<popsize/2;i++)
		{
			m=Rnd(popsize);
			bol(m);
			z=Rnd(popsize);
			bol(z);
			for(k=1;k<=nv;k++)
			{
				if(population[m].chrom[k]==population[z].chrom[k])
					jj++;
				if(jj==nv)
					z=select();
					bit=Rnd(nv);
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
					bit=Rnd(nv);
					if((bit%2)==0)
						bit=bit;
					else 
						bit-=1;
					bol(bit);
					population[m].chrom[bit]=random(2)-1;
					population[z].chrom[bit]=random(2)-1;
				}
			}
		}
	}

			//主控程序
		void main()
		{
			int q;
			double g;
			void Randomize();
			initialize();
			sort();
			power(population[1]);
			cop(mid,population[1]);
			do
			{
				crossmutation();
				sort();
				cop(population[popsize-1],mid);
				power(population[1]);
				cop(mid,population[1]);
			}while(population[1].fitness-avg>0.1);
			sort();
			power(population[1]);
			for(q=1;q<=p;q++)
			{
				printf("%4.4f\t",population[1].x[q]);
				g=-f(population[1])+10000;
				printf("\n%4.4f",g);
				power(population[1]);
				g=-f(population[1])+10000;
				printf("\n%4.4f",g);
			}
		}
