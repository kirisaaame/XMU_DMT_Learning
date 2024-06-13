//常见的数据结构
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Linklist()
{
	struct linkedList{
		struct linkedList * head;
		char content[100];
		struct linkedList * next;
	};	
	struct linkedList * head,*current,*prev;
	char input[100];
	
	while(scanf("%s",input)!=NULL)
	{
		current=(struct *)malloc(sizeof(struct linkedList));
		if (head==NULL)
			head=current;
		else
			prev->next=current;
		current->next=NULL;
		strcpy(current->content,input);
		prev=current;
	}
	if(head==NULL);
	else 
	
		while(current!=NULL)
		{
		
		current=head;
		printf("%s\n",current->content);
		current=current->next;
	}
	current=head;
	while(current!=NULL)
	{
		free(current);
		current=current->next;
	}
	//linkedlist in structure
	//cooperate with structure pointer
}

void Array()
{
	int num[100]=,i=0,j;
	
	while(scanf("%d",&num[i])==1)
		i++;
	for(j=0;j<i;j++)
		printf("%d ",num[j]);
	printf("\n");
}