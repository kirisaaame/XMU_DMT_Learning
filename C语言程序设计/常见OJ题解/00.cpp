#include <stdio.h>
union 
{
	int i;
	short s;
	char c;
}t;
void hex_out(char a)
{
	const char HEX[] = "0123456789ABCDEF";
	printf("%c%c ",HEX[((a&0xf0)>>4)&0x0f],HEX[a&0x0f]);
}
void out_1byte(char *addr)
{
	hex_out(*(addr+0));
}
void out_2byte(char *addr)
{
	//小段方式先输出高字节
	hex_out(*(addr+1));
	hex_out(*(addr+0));
}
void out_4byte(char *addr)
{
	hex_out(*(addr+3));
	hex_out(*(addr+2));
	hex_out(*(addr+1));
	hex_out(*(addr+0));
}
int f1(unsigned n)
{
	int sum=1, power = 1;
	for (unsigned i =0;,i<=n-1;i++)
	{
		power*=2;
		sum+=power;
	}
	return sum;
}
int main()
{
	t.i = 0xc77fffff;
	out_4byte((char*)&t.i);
	printf("  = %d \n",t.i);
	out_4byte((char*)&t.s);
	printf("  = %d \n",t.s);
	out_4byte((char*)&t.c);
	printf("  = %d \n",t.c);
}

void main1()
{
	short s1 = 32767,s2 = -32768,s;
	unsigned char uc1 = 128,uc2=255,uc;
	s = s1+1;
	printf(" %d + 1 = %d\n",s1,s);
	s = s2-3;
	printf(" %d - 3 = %d\n",s2,s);
	uc = uc1+uc2;
	printf(" %d + %d = %d\n",uc1,uc2,uc);
	uc = uc1-uc2;
	printf(" %d - %d = %d\n",uc1,uc2,uc);
}

void main2()
{
	unsigned char uc1 = 255,uc;
	char c1 = -127,c;
	c = (char) uc1;
	out_1byte(&uc1);
	printf(" = uc1 = %u  \n",uc1);
	out_1byte(&c);
	printf(" = c = %d  \n",c);

	uc = c1;
	out_1byte(&c1);
	printf(" = c1 = %d  \n",c1);
	out_1byte(&uc);
	printf(" = uc = %u  \n",uc);
}