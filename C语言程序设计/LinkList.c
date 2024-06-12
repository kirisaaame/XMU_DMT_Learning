#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node, * linklist;

#define OK 0
#define ERROR -1

void clear_stdin()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}
//清空输入行
#define INPUT_VALID 1
#define INPUT_FINISH 0

int scanf_with_message(const char* message, const char * format, void* data)
{
	int result = 0;
	do
	{
		printf("%s", message);
		result = scanf(format, data);
		if (result == 0 && getchar() == 'q')
			return INPUT_FINISH;
		else if (result == 0)
		{
			fputs("Try again due to wrong format.", stderr);
			clear_stdin();
		}
		else if (result == EOF) {
			fputs("Standard input stream is closed.", stderr);
			return INPUT_FINISH;
		}
	} while (result != 1);
	return INPUT_VALID;
}
//读取输入信息
int get_data_from_input(int* data)
{
	return scanf_with_message("Please enter the data of the new node (press 'q' for quit): ","%d", data);
}

node* create_node()
{
	node* current = (node*)malloc(sizeof(node));
	if (current == NULL)
	{
		fprintf(stderr, "%s\n", "Failed to allocate the new node due to not enough memory space.");
		return NULL;
	}
	current->data = 0;
	current->next = NULL;
	return current;
}

linklist creat_from_head()
{
	linklist list = NULL;
	node* current = NULL;
	int data;
	while (get_data_from_input(&data) == INPUT_VALID)
	{
		current = create_node();
		if (current == NULL)
			break;
		current->data = data;
		current->next = list;
		list = current;
	}
	return list;
}

linklist creat_from_tail()
{
	linklist list = NULL;
	node* current = NULL, * previous = NULL;
	int data;
	while (get_data_from_input(&data) == INPUT_VALID)
	{
		current = create_node();
		if (current == NULL)
			break;
		current->data = data;
		if (previous == NULL)
			list = current;
		else
			previous->next = current;
		previous = current;
	}

	return list;
}

node* get_item(const linklist list, const size_t offset)
{
	size_t i;
	if (list == NULL)
	{
		fputs("Empty list.\n", stderr);
		return NULL;
	}
	node* current = list;
	for (i = 0; i < offset && current != NULL; i++)
		current = current->next;
	if (i != offset)
		current = NULL;
	return current;
}

node* locate(const linklist list, const int data, size_t* offset)
{
	size_t i;
	if (list == NULL)
	{
		fputs("Empty list.\n", stderr);
		return NULL;
	}
	node* current = list;
	for (i = 0; current != NULL && current->data != data; ++i)
		current = current->next;
	*offset = i;
	return current;
}

int insert_item(linklist* list, const size_t offset, const int data)
{
	node* previous, * current;
	size_t i;
	previous = *list;

	if (offset == 0 || *list == NULL)
	{
		current = create_node();
		if (current == NULL)
			return ERROR;
		current->data = data;
		current->next = *list;
		*list = current;
		return OK;
	}

	for (i = 0; i < offset - 1 && previous->next; ++i)
		previous = previous->next;
	if (i != offset - 1)
	{
		fputs("Failed to find the offset.", stderr);
		return ERROR;
	}
	current = create_node();
	if (current == NULL)
		return ERROR;
	current->data = data;
	current->next = previous->next;
	previous->next = current;
	return OK;
}

int remove_item(linklist* list, const size_t offset, int* data)
{
	node* previous, * current;
	size_t i;
	previous = *list;
	if (previous == NULL)
	{
		fputs("Empty list.", stderr);
		return ERROR;
	}
	if (offset == 0)
	{
		current = *list;
		*data = current->data;
		*list = current->next;
		free(current);
		return OK;
	}
	for (i = 0; i < offset - 1 && previous->next; ++i)
		previous = previous->next;
	current = previous->next;
	if (current == NULL)
	{
		fputs("Failed to find the offset.", stderr);
		return ERROR;
	}
	*data = current->data;
	previous->next = current->next;
	free(current);
	return OK;
}

size_t count(const linklist list)
{
	size_t i;
	node* current = list;
	for (i = 0; current; ++i)
		current = current->next;
	return i;
}

void difference(linklist* list1, const linklist list2)
{
	node* previous = *list1, * current, * temp;
	int has_found = 1;
	if (previous == NULL)
		return;

	while (previous && has_found == 1)
	{
		has_found = 0;
		for (temp = list2; temp && has_found == 0; temp = temp->next)
		{
			if (previous->data == temp->data)
			{
				current = *list1;
				*list1 = current->next;
				free(current);
				has_found = 1;
			}
		}
		previous = *list1;
	}

	if (*list1 == NULL)
		return;

	while (current = previous->next)
	{
		has_found = 0;
		for (temp = list2; temp && has_found == 0; temp = temp->next)
		{
			if (current->data == temp->data)
			{
				previous->next = current->next;
				free(current);
				has_found = 1;
			}
		}
		if (has_found == 0)
			previous = previous->next;
	}
}

int show(const linklist list)
{
	node* current = list;
	size_t i = 0;
	if (current == NULL)
	{
		fprintf(stderr, "%s\n", "The list is empty.");
		return ERROR;
	}
	printf("%-6s\t%-8s\t%-16s\t%-16s\n", "ID", "Data", "Next", "Address");
	printf("======\t========\t==================\t==================\n");
	while (current != NULL)
	{
		printf("%4zu  \t%6d  \t%016p\t%016p\n", ++i, current->data, current->next, current);
		current = current->next;
	}
	return OK;
}

int select_from_menu()
{
	int choice = 0;

	//clear_stdin();

#define PRINT_DIVISION() puts("*********************************************************")
	PRINT_DIVISION();
	puts("*        DEMONSTRATION OF OPERATIONS OF LINKLIST        *");
	PRINT_DIVISION();
#define PRINT_CHOICE(MSG) printf("     [%2d] %s\n", ++choice, MSG)
	PRINT_CHOICE("Creating a linklist using insertion by head");
	PRINT_CHOICE("Creating a linklist using insertion by tail");
	PRINT_CHOICE("Search data from a linklist by location");
	PRINT_CHOICE("Search data from a linklist by content");
	PRINT_CHOICE("Insert data into given location of a linklist");
	PRINT_CHOICE("Remove data from a linklist");
	PRINT_CHOICE("Calculate the node count of a linklist");
	PRINT_CHOICE("Find the difference set of two linklists");
	PRINT_CHOICE("List all nodes of a linklist");
	PRINT_DIVISION();
	if (scanf_with_message("Please choose an item ('q' for quit): ", "%d", &choice) == INPUT_FINISH)
		exit(1);
	return choice;
}

char* order_string(const size_t order, char* string)
{
	switch (order % 10)
	{
	case 1: sprintf(string, "%zust", order); break;
	case 2: sprintf(string, "%zund", order); break;
	case 3: sprintf(string, "%zurd", order); break;
	default: sprintf(string, "%zuth", order);
	}
	return string;
}

int main()
{
	int ch = 0;
	size_t location;
	int data;
	node* p;
	char string[30];
	linklist list1 = NULL, list2 = NULL;
	while (ch = select_from_menu())
	{
		switch (ch)
		{
		case 1:
			list1 = creat_from_head();
			break;
		case 2:
			list1 = creat_from_tail();
			break;
		case 3:
			scanf_with_message("Please input the location: ", "%zu", &location);
			p = get_item(list1, location - 1);
			if (p != NULL)
				printf("The %s element is %d.\n", order_string(location, string), p->data);
			else
				printf("The %s element is not found.\n", order_string(location, string));
			break;
		case 4:
			scanf_with_message("Please input the data to find: ", "%d", &data);
			p = locate(list1, data, &location);
			if (p != NULL)
				printf("The data %d is first found at %s element.\n", p->data, order_string(location + 1, string));
			else
				printf("The data %d is not found.\n", data);
			break;
		case 5:
			scanf_with_message("Please input the data to insert: ", "%d", &data);
			scanf_with_message("Please input the location to insert: ","%zu", &location);
			if (insert_item(&list1, location - 1, data) == OK)
				puts("Insertion succeed.");
			else
				puts("Insertion failed.");
			break;
		case 6:
			scanf_with_message("Please input the location to remove: ", "%zu", & location);
			if (remove_item(&list1, location - 1, &data) == OK)
				printf("Removal succeed, and the removed item is %d.\n", data);
			else
				puts("Removal failed.");
			break;
		case 7:
			printf("The length of the linklist is %zu.\n", count(list1));
			break;
		case 8:
			printf("The main linklist is as follows.\n");
			show(list1);
			list2 = creat_from_tail();
			difference(&list1, list2);
			printf("The side linklist is as follows.\n");
			show(list2);
			printf("Their difference is:\n");
			show(list1);
			break;
		case 9:
			printf("The main linklist is as follows.\n");
			show(list1);
			break;
		default:
			fputs("Type error.\n", stderr);
		}
	}
	return 0;
}
