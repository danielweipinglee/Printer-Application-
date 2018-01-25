#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
	int priority;
	char info[30];
	struct Node *link;
} node;


typedef struct Priority_Queue
{
	node* front;
} PriorityQ;

void insert(char* item, int priority, PriorityQ* queue)
{
	node *tmp, *q;
	tmp = (node*)malloc(sizeof(node));

	strcpy(tmp->info, item);
	tmp->priority = priority;
	if ( queue->front == NULL || priority < queue->front->priority)
	{
		tmp->link = queue->front;
		queue->front = tmp;
	}
	else
	{
		q = queue->front;
		while (q->link != NULL && q->link->priority <= priority)
			q=q->link;
		tmp->link = q->link;
		q->link = tmp;
	}
}
//Delete the file which already in the current printing list and has lowest priority 
void del(PriorityQ* queue)
{
	node *tmp;
	if(queue->front == NULL)
		printf("printing list is empty\n");
	else
	{
		tmp = queue->front;
		printf("Deleted File is:%s\n",tmp->info);
		queue->front = queue->front->link;
		free(tmp);
	}
}

//Display the current printing file list
void display(PriorityQ* queue)
{
	node *ptr;
	ptr = queue->front;
	if (ptr == NULL)
		printf("printing list is empty\n");
	else
	{	
		printf("Printing List :\n");
		printf("\tPriority\t\tFile Name\n");
		while(ptr != NULL)
		{
			printf("\t%d\t\t\t%s\n", ptr->priority, ptr->info);
			ptr = ptr->link;
		}
	} 
}

void print(PriorityQ* queue)
{
	node *ptr;
	ptr = queue ->front;
	if (ptr == NULL)
		printf("Printing list is empty!\n");
	else 
	{ 
		printf("Perpare printing...\n");
		while(ptr != NULL)
		{
			printf("Printing %s....\n",ptr->info);
			ptr = ptr->link;
		}
		printf("Done!\n");
	}
}


int main()
{
	int choice,priority;
	char item[30];
	PriorityQ pq;
	pq.front = NULL;
	printf("Welcome to Wei-Ping, Lee's Printer System!\n");
	printf("What can I help you today?\n"); 
	do
	{
		printf("1.Insert the file to the printing list\n");
		printf("2.Automatically delete the file which has lowest priority\n");
		printf("3.Display the current printing list\n");
		printf("4.Print\n");
		printf("5.Quit\n");
		printf("Enter your choice: "); 
		scanf("%d",&choice); 
		switch(choice)
		{
		case 1:
			printf("Input the file name to be added in the queue : ");
			scanf("%s",&item);
			printf("Enter its priority : ");
			scanf("%d",&priority); 
			insert(item, priority, &pq);
                        printf("File has been inserted\n");
			break;
		case 2:
			del(&pq);
			break;
		case 3: 
			display(&pq);
			break;
		case 4:
                        print(&pq);
			break;
		case 5:
	                break;	
		default :
			printf("Wrong choice\n");
		}
                printf("\n");
	}
	while ( choice !=5 && choice !=4);
	return 0;
}


