#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *previous,*next;
}node;

typedef struct doublylinkedlist
{
	struct node *head;
	struct node *tail;
}doublylist;

void init(doublylist *l)
{
	l->head = l->tail = NULL;
}

void addfirst(doublylist *l,int data)
{
	node *p=(node*)malloc(sizeof(node));
	p->data=data;
	p->previous='\0';
	p->next='\0';
	
	if(l->head == '\0')		//if no elemnt exists
	{
		l->head=p;
		l->tail=p;
	}	
	else			//1 or more than that exists
	{
	    p->next=l->head;
	    l->head->previous=p;
	    l->head=p;
	}
}

void addlast(doublylist *l,int data)
{
	node *p=(node*)malloc(sizeof(node));
	p->data=data;
	p->next='\0';
	
	if(l->head== NULL)
	{
		l->head=p;
		l->tail=p;
	}
	else
		p->previous=l->tail;
	    l->tail->next=p;
	    l->tail=p;
}

void insat(doublylist *l,int data)
{
	node *p=(node*)malloc(sizeof(node));
	node *current=l->head;
	p->data=data;
	doublylist list;
	if(l->head==NULL)
	{
		l->head=p;
		l->tail=p;
	}
	if(p->data < l->head->data)
		{	addfirst(&list,data);	}
	else if(p->data > l->tail->data)
		{	addlast(&list,data);	}
	else
	{
		while( current->next->data < p->data )
		{
		    current=current->next;
	    }
	    	p->previous=current;
		    p->next=current->next;
		    current->next=p;
		    p->next->previous=p;
	}
}

void display(doublylist *l)
{
	node *current;
	current=l->head;
	int i=1;
	while(current!=NULL)
	{
		printf("%d. %p [ %p | %d | %p ] \n",i,current,current->previous,current->data,current->next);
		current=current->next;
		i++;
	}
}

int deletefirst(doublylist *l)
{
	int x;
	node *current;
	current=l->head;          
	if(l->head==NULL)
	{
		printf("LINKED LIST IS EMPTY \n");
		return 0;
	}
 	else if(l->head == l->tail)		//only 1 elemnt exists
	{
		x=current->data;
		l->head=l->tail=NULL;
		free(current);
		return x;
	}
	else{					// mre than 1 element exists
	x=l->head->data;	
	l->head=l->head->next;
	l->head->previous=NULL;
	free (current);
	return x;				
	}
	
}

/*int deletefirst(doublylist *l)
{
	int x;
	node *current;
	current=l->head;          
	if(l->head==NULL)
	{
		printf("LINKED LIST IS EMPTY \n");
		return 0;
	}
	else
	{
		x=l->head->data;
		l->head=l->head->next;
		l->head->previous=NULL;
		free(current);
		return x;
	}
}
*/

int deletelast(doublylist *l)
{
	node *current=l->head;
	int x;
	if(l->head==NULL)
	{
		printf("LINKED LIST IS EMPTY \n");
		return 0;
	}
	else if(l->head==l->tail)			// 1 element
	{
		x=current->data;
		l->head=l->tail=NULL;
		free(current);
		return x;
	}
	else
	{
		x=current->data;		//YAHA PE BHI SAME YE LINE NAHI LIKHI THI
		l->tail=l->tail->previous;
	    free(current);	
		return x;
	}
}

int main()
{
	doublylist list;
	init(&list);
	label:
	  int choice,num1,num2,num3;
	  printf("-------- Doubly LINKED LIST MENU-------\n");
	  printf("\n 1.INSERT-insert at first \n 2.INSEND-insert at last \n 3.INSAT-insert in middle \n 4.DELETE FIRST \n 5.DELETE LAST \n 6.DISPLAY \n 7.EXIT \n");
	  printf("enter your choice: ");
	  scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("Insert a value at first: ");
			scanf("%d",&num1);
			addfirst(&list,num1);
			goto label;
			
		case 2:
			printf("Insert a value at last: ");
			scanf("%d",&num2);
			addlast(&list,num2);
			goto label;
			
		case 3:
			printf("Insert a value at middle: ");
			scanf("%d",&num3);
			insat(&list,num3);
			goto label;
			
		case 4:
			printf("\n deleted value is %d",deletefirst(&list));
			goto label;		
			
		case 5:
			printf("\n deleted value is %d",deletelast(&list));
			goto label;
			
		case 6:
			printf("displaying value........\n");
			display(&list);
			goto label;
			
		case 7:
			printf("GOODBYE SHITHEAD.....");
			exit(0);
			goto label;
			
		default:
			printf("Invalid input \n");
			goto label;
	}
	return 0;
  }

