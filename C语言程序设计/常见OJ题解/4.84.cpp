#include <stdio.h>
int main()
{
	float height;
	char name[30];
	printf("Please enter your height(m) and your name.\n");
	scanf("%f %s",&height,name);
	printf("%s, you are %.2f metres tall\n",name,height);
	
	return 0;
}