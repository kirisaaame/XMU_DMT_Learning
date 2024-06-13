#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct date{
	char date[11];
	struct date * next;
} date ;

int main()
{
	int n,k,i;
	date * head=NULL,* current,* prev=NULL;
	date*now;
	char temp[11];
	
	scanf("%d",&n);
	//use linklist to save data
	for(i=0;i<n;i++)
	{
		current=(date*)malloc(sizeof(date));
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		scanf("%s",current->date);
		
		prev=current;
		prev->next=NULL;
	}
	scanf("%d",&k);
	
	//selection sort
	current=head;
	while(current)
	{	
		now=current;
		while(1)
		{
		now=now->next;
		if (now==NULL) break;
		else if(strcmp(now->date,current->date)<0)
		{
			strcpy(temp,now->date);
			strcpy(now->date,current->date);
			strcpy(current->date,temp);
		}
		}
		current=current->next;
	}
	
	//search
	current=head;
	for(i=1;i<k;i++)
		current=current->next;
	printf("%s",current->date);
	
	//free memory
	current=head;
	while(current)
	{
		free(current);
		current=current->next;
	}
	
	return 0;
}