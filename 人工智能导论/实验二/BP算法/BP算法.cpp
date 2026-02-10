#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27
#define ERRORLEVEL 0.02
#define ITEMS 8

//指针的动态存储
typedef double *PFLOAT;
typedef PFLOAT VECTOR;
typedef PFLOAT *MATRIX;

void VectorAllocate(VECTOR *vector,int nCols);
void AllocateCols(PFLOAT matrix[],int nRows,int nCols);
void MatrixAllocate(MATRIX *pmatrix,int nRows,int nCols);
void MatrixFree(MATRIX matrix,int nRows);

//定义网络层的存储
	//输入层,输出层及权值等的指针;
	MATRIX out0;   //输入层
	MATRIX out1;	//隐含层
	MATRIX delta1;	//隐含层中的误差修正量
	MATRIX delw1;	//输入与隐含层之间权值的变化
	MATRIX w1;	//输入与隐含层之间的权值
	MATRIX out2;	//输出层;
	MATRIX delta2;	//输出层中的误差修正量
	MATRIX delw2;	//隐含与输出层之间权值的变化
	MATRIX w2;	//隐含与输出层间的权值
	MATRIX target;	//目标输出值
	MATRIX PatternID;	//每一个被储存模式的识别标志

void main(int argc,char *argv[])
	{
	double eta=0.15;	//默认的学习速率
	double alpha=0.075;	//默认的势态因子
	int nReportErrors=100;	//误差报告频率
	double ErrorLevel=ERRORLEVEL;	//满意的误差水平
	char MonitorError=0;	//表示为真
	double error;	//最新的平方根误差之和
	register int h;	//代表隐含层的值
	register int i;	//代表输入层的值
	register int j;	//代表输出层的值
	int p,	//模式数
		q,	//
		r,	//运行数
		nPatterns,	//模式个数
		nInputNodes,	//输入节点个数
		nHiddenNodes,	//隐含层节点个数
		nOutputNodes,	//输出层节点个数
		nIterations,	//
		nRuns;	//运行个数
	FILE  *fpRun,	//运行文件
		  *fpPattern,	//模式输入文件
		  *fpWeights,	//初始权值文件
		  *fpWeightsOut,	//最合权输出文件
		  *fpResults,	//结果输出文件
		  *fpError;		//误差输出文件
	char szResults[66];	//变量文件
	char szError[66];
	char szPattern[66];
	char szWeights[66];
	char szWeightsOut[66];
	char *progname=*argv;

	//读优化参数
	for(;argc>1;argc--)
	{
		char *arg=*++argv;
		if(*arg!='-')
			break;
		switch(*++arg)
		{
			case 'e':sscanf(++arg,"%d",&nReportErrors);break;
			case 'd':sscanf(++arg,"%d",&ErrorLevel);break;
			default:break;
		}
	}
	if(argc<2)
	{
		fprintf(stderr,"Usage:%s{-en,-df} runfilename\n",progname);
		fprintf(stderr,"-en=>report error every n iterations\n");
		fprintf(stderr,"-df=>done if mean squared error<f\n");
		exit(1);
	}
	//打开文件读数据
	if((fpRun=fopen(*argv,"r"))==NULL)
	{
		fprintf(stderr,"%s:can't open file %s\n",*argv);
		exit(1);
	}
	//读第一行
	fscanf(fpRun,"%d",&nRuns);
	//循环开始
	for(r=0;r<nRuns;r++)
	{
		fscanf(fpRun,"%s %s %s %s %s %d %d %d %d %f %f",
			szResults,	//结果输出文件
			szError,	//误差输出文件
			szPattern,	//模式输入文件
			szWeights,	//初始权值文件
			szWeightsOut,	//最后权输出文件
			&nPatterns,	//待学习的模式的个数
			&nIterations,	//迭代次数
			&nInputNodes,	//输入节点个数
			&nHiddenNodes,	//隐含节点个数
			&nOutputNodes,	//输出节点个数
			&eta,	//学习速率
			&alpha);	//动量因子
	//所有数据的动态存储
	MatrixAllocate(&out0,nPatterns,nInputNodes);
	MatrixAllocate(&out1,nPatterns,nHiddenNodes);
	MatrixAllocate(&out2,nPatterns,nOutputNodes);
	MatrixAllocate(&delta2,nPatterns,nOutputNodes);
	MatrixAllocate(&delw2,nOutputNodes,nHiddenNodes);
	MatrixAllocate(&w2,nOutputNodes,nHiddenNodes+1);
	MatrixAllocate(&delta1,nPatterns,nHiddenNodes);
	MatrixAllocate(&delw1,nHiddenNodes,nInputNodes+1);
	MatrixAllocate(&w1,nHiddenNodes,nInputNodes+1);
	MatrixAllocate(&target,nPatterns,nOutputNodes);
	VectorAllocate(PatternID,nPatterns);
	//读初始权矩阵
	if((fpWeights=fopen(szWeights,"r"))==NULL)
	{
		fprintf(stderr,"%s:can't open file %s\n",progname,szWeights);
		exit(1);
	}
	//读输入-隐含层权值
	for(h=0;h<nHiddenNodes;h++)
		for(i=0;i<=nInputNodes;i++)
		{
			fscanf(fpWeights,"%f",&w1[h][i]);
			delw1[h][i]=0.0;
		}
	//读隐含-输出层的权值
	for(j=0;j<nOutputNodes;j++)
		for(h=0;h<=nHiddenNodes;h++)
		{
			fscanf(fpWeights,"%f",&w2[j][h]);
			delw1[j][h]=0.0;
		}
	//读所有要学习的模式
	if((fpPattern=fopen(szPattern,"r"))==NULL)
	{
		fprintf(stderr,"%s:can't open file %s\n",progname,szPattern);
		exit(1);
	}
	for(p=0;p<nPatterns;p++)
	{
		for(i=0;i<nInputNodes;i++)
			if(fscanf(fpPattern,"&f",&out0[p][i])!=1)
				goto ALLPATTERNSREAD;
			//读目标输出
			for(j=0;j<=nOutputNodes;j++)
				fscanf(fpPattern,"%f",&target[p][j]);
				//读每一个模式的分别号
				fscanf(fpPattern,"%f",&PatternID[p]);
	}

ALLPATTERNSREAD:
	fclose(fpPattern);
	 if(p<nPatterns)
	 {
		 fprintf(stderr,"%s:%d out of %d patterns read\n",progname,p,nPatterns);
		 nPatterns=p;
	 }
	 //打开误差输出文件
	 if((fpError=fopen(szError,"w"))==NULL)
	 {
		 fprintf(stderr,"%s:can't open file %s\n",progname,szError);
		 exit(1);
	 }
	 fprintf(stderr,nIterations>1 ? "Training...\n":"Teating\n");

	 //开始迭代循环
	 for(q=0;q<nIterations;q++)
	 {
		 for(p=0;p<nPatterns;p++)
		 {
			//隐含层
			for(h=0;h<nHiddenNodes;h++)
			{
				double sum=w1[h][nInputNodes];
				for(i=0;i<nInputNodes;i++)
					sum+=w1[h][i]*out0[p][i];
				//计算输出层
				out1[p][h]=1.0/(1.0+exp(-sum));
			}
			//输出层
			for(j=0;j<nOutputNodes;j++)
			{
				double sum=w2[j][nHiddenNodes];
				for(h=0;h<nHiddenNodes;h++)
					sum+=w2[j][h]*out1[p][h];
				out2[p][j]=1.0/(1.0+exp(-sum));
			}
			//输出层误差修正量
			for(j=0;j<nOutputNodes;j++)
				delta2[p][j]=(target[p][j]-out2[p][j])*out2[p][j]*(1.0-out2[p][j]);
			//隐含层误差修正量
			for(h=0;h<nOutputNodes;h++)
			{
				double sum=0.0;
				for(j=0;j<nOutputNodes;j++)
					sum+=delta2[p][j]*w2[j][h];
				delta1[p][h]=sum*out1[p][h]*(1.0-out1[p][h]);
			}
		 }
		//调整隐含-输出层部的权值
		 for(j=0;j<nOutputNodes;j++)
		 {
			 double dw;
			 double sum=0.0;
			 for(p=0;p<nPatterns;p++)
				 sum+=delta2[p][j];
			 dw=eta*sum+alpha*delw2[j][nHiddenNodes];
			 w2[j][nHiddenNodes]+=dw;
			 delw2[j][nHiddenNodes]=dw;
			 for(h=0;h<nHiddenNodes;h++)
			 {
				double sum=0.0;
				for(p=0;p<nPatterns;p++)
					sum+=delta2[p][j]*out1[p][h];
				dw=eta*sum+alpha*delw2[j][h];
				w2[j][h]+=dw;
				delw2[j][h]=dw;
			 }
		 }
		//调整输入-隐含层的权值
		 for(h=0;h<nHiddenNodes;h++)
		 {
			 double dw;
			 double sum=0.0;
			 for(p=0;p<nPatterns;p++)
				 sum+=delta1[p][h];
			 dw=eta*sum+alpha*delw1[j][nInputNodes];
			 w1[h][nInputNodes]+=dw;
			 delw1[j][nInputNodes]=dw;
			 for(i=0;i<nInputNodes;i++)
			 {
				double sum=0.0;
				for(p=0;p<nPatterns;p++)
					sum+=delta1[p][h]*out0[p][i];
				dw=eta*sum+alpha*delw1[h][i];
				w1[h][i]+=dw;
				delw1[h][i]=dw;
			 }
		 }
		//监督键盘响应
		 if(_kbhit())
		 {
			 int c=getch();
			 if(c=toupper(c)=='E')
				 MonitorError++;
			 else if(c==ESC)
				 break;
		 }

		 //计算均方根误差
		 if(MonitorError||(q%nReportErrors==0))
		 {
			 for(p=0,error=0.0;p<nPatterns;p++)
			 {
				 for(j=0;j<nOutputNodes;j++)
				 {
					 double temp=target[p][j]-out2[p][j];
					 error+=temp*temp;
				 }
			 }
			 error/=(nPatterns*nOutputNodes);
			 fprintf(stderr,"iteration %5d%-5d  Error %f\r",q,nIterations,error);
			 MonitorError=0;
			 if(q%nReportErrors==0)
				 fprintf(fpError,"%d %f\n",q,error);
			 if(error<ErrorLevel)
				 break;
		 }
	}
	//迭代循环结束

	for(p=0,error=0.0;p<nPatterns;p++)
	{
		for(j=0;j<nOutputNodes;j++)
		{
			double temp=target[p][j]-out2[p][j];
			error+=temp*temp;
		}
	}

	//计算所有模式的平均误差
	error/=(nPatterns*nOutputNodes);
	fprintf(stderr,"Iteration %5d%-5d Error %f\n",q,nIterations,error);
	fprintf(fpError,"\n%d  %f\n",q,error);
	fclose(fpError);
	if((fpWeightsOut=fopen(szWeightsOut,"w"))==NULL)
	{
		fprintf(stderr,"%s:can't write file %s\n",progname,szWeightsOut);
		exit(1);
	}
	for(h=0;h<nHiddenNodes;h++)
		for(i=0;i<=nInputNodes;i++)
			fprintf(fpWeightsOut,"%g%c",w1[h][i],i%ITEMS==ITEMS-1 ?'\n':' ');
		for(j=0;j<nOutputNodes;j++)
			for(h=0;h<nHiddenNodes;h++)
				fprintf(fpWeightsOut,"%g%c",w2[j][h],j%ITEMS==ITEMS-1 ?'\n':' ');
		fclose(fpWeightsOut);

		if((fpResults=fopen(szResults,"w"))==NULL)
		{
			fprintf(stderr,"%s:can't write file %s\n",progname,szResults);
			fpResults=stderr;
		}

		for(p=0;p<nPatterns;p++)
		{
			fprintf(fpResults,"%d   ",p);
			for(j=0;j<nOutputNodes;j++)
				fprintf(fpResults,"%f",out2[p][j]);
			fprintf(fpResults,"  %-6.0f\n",PatternID[p]);
		}
		fclose(fpResults);

		//释放数据的动态存储
		MatrixFree(out0,nPatterns);
		MatrixFree(out1,nPatterns);
		MatrixFree(delta1,nPatterns);
		MatrixFree(delw1,nHiddenNodes);
		MatrixFree(w1,nHiddenNodes);
		MatrixFree(out2,nPatterns);
		MatrixFree(delta2,nPatterns);
		MatrixFree(delw2,nOutputNodes);
		MatrixFree(w2,nOutputNodes);
		MatrixFree(target,nPatterns);
		free(PatternID);
		}
		fclose(fpRun);
		}


		void VectorAllocate(VECTOR *vector,int nCols)
		{
			if((*vector=(VECTOR) calloc(nCols,sizeof(double)))==NULL)
			{
				fprintf(stderr,"Sorry! Not enough memory for nodes\n");
				exit(1);
			}
		}

		void AllocateCols(PFLOAT matrix[],int nRows,int nCols)
		{
			int i;
			for(i=0;i<nRows;i++)
				VectorAllocate(&matrix[i],nCols);
		}

		void MatrixAllocate(MATRIX *pmatrix,int nRows,int nCols)
		{
			if((*pmatrix=(MATRIX)calloc(nRows,sizeof(PFLOAT)))==NULL)
			{
				fprintf(stderr,"Sorry! Not enough memory for nodes\n");
				exit(1);
			}
			AllocateCols(*pmatrix,nRows,nCols);
		}

		void MatrixFree(MATRIX matrix,int nRows)
		{
			int i;
			for(i=0;i<nRows;i++)
				free(matrix[i]);
		}




