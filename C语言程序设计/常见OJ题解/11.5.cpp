#include <stdio.h>
#include <string.h>
int main()
{
	const char *mesg="don't be a fool!";
	const char *copy;
	
	copy=mesg;
	printf("%s\n",copy);
	printf("mesg=%s;&mesg =%p;value=%p\n",mesg,&mesg,mesg);
	printf("copy=%s;&copy =%p;value=%p\n",copy,&copy,copy);
	
	return 0;