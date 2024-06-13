#include <stdio.h>
int main()
{
	float speed;
	float size;
	printf("Enter your download speed(Mb/s) and the size of your file(Mb):\n");
	scanf("%f %f",&speed,&size);
	printf("At %.2f megabytes per second, a file of %.2f megabytes\n",speed,size);
	printf("downloads in %.2f seconds.",size/speed);
	return 0;
}