#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct snglist
{
	struct node *head;
	struct node *tail;
}snglist;

void init(snglist *l)
{
	l->head=l->tail='\0';
}

void addfirst(snglist *l,int data)
{
	node *p=(node*)malloc(sizeof(node));
	p->data=data;
	p->next='\0';
	
	if(l->head=='\0')
	{
		l->head=p;
		l->tail=p;
	}
	else
	{
	    p->next=l->head;
	    l->head=p;
	}
}
void addlast(snglist *l,int data)
{
	node *p=(node*)malloc(sizeof(node));
	p->data=data;
	p->next='\0';
	
	if(l->head=='\0')
	{
		l->head=p;
		l->tail=p;
	}
	else
	    l->tail->next=p;
	    l->tail=p;
}

void insat(snglist *l,int data)
{
	node *p=(node*)malloc(sizeof(node));
	node *current;
	p->data=data;
	current=l->head;
	
	if(l->head==NULL)
	{
		l->head=p;
		l->tail=p;
	}
	
	while(p->data < current->data)
	{
	    current=current->next;
    }
	    p->next=current->next;
	    current->next=p;
}

void display(snglist *l)
{
	node *current;
	current=l->head;
	int i=1;
	while(current!=NULL)
	{
		printf("%d. %p [%d | %p] \n",i,current,current->data,current->next);
		current=current->next;
		i++;
	}
}

int deletefirst(snglist *l)
{
	int x;
	node *current;
	current=l->head;               //you declared current w malloc here ,were not actually allocating any momry
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
	x=current->data;		// <--- yeh wali line to likhi hi nai thi
	l->head=current->next;
	free (current);
	return x;					//else if ka hi locha tha
	}
	
}

int deletelast(snglist *l)
{
	node *current=l->head;
	node *pred=current;
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
		while(current->next != NULL)
		{
			pred=current;		//previous element
			current=current->next;		//increments current (traversing)
		}
		x=current->data;		//YAHA PE BHI SAME YE LINE NAHI LIKHI THI
		l->tail=pred;
		pred->next=NULL;
	    free(current);			//apne pred ko free karva rahe the lekin CURRENT FREE HOGA
		return x;
	}
}

void search(snglist *l,int target)
{
	node *current=l->head;
	
	while(current!=NULL)
	{
		if(current->data==target)
		{
			printf("match found \n");
			return;
		}
		current=current->next;
	}
	printf("match not found \n");
}

void reverse(snglist *l,snglist *lr)
{
	int x;
	node *current = l->head;
	while(current != NULL)
	{
		x=current->data;
		addfirst(lr,x);
		current=current->next;
	}
	return ;
}

int count(snglist *l)
{
	int count=0;
	node *current=l->head;
	while(current != NULL)
	{
		count++;
		current=current->next;			// bhai ye line to main hai tu likhna bhul gaya bc
    } 
    return count;
}

void menu()
{
 while(1)
 {
	  int choice,num1,num2,num3,searchvalue;
	  snglist list,list2;
	  printf("-------- SINGLY LINKED LIST MENU-------\n");
	  printf("\n 1.INSERT-insert at first \n 2.INSEND-insert at last \n 3.INSAT-insert in middle \n 4.DELETE FIRST \n 5.DELETE LAST \n 6.REVERSE \n 7.SEARCH \n 8.COUNT \n 9.DISPLAY \n 10.EXIT \n");
	  printf("enter your choice: ");
	  scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("Insert a value at first: ");
			scanf("%d",&num1);
			addfirst(&list,num1);
			break;
			
		case 2:
			printf("Insert a value at last: ");
			scanf("%d",&num2);
			addlast(&list,num2);
			break;
			
		case 3:
			printf("Insert a value at middle: ");
			scanf("%d",&num3);
			insat(&list,num3);
			break;
			
		case 4:
			printf("\n deleted value is %d",deletefirst(&list));
			break;			// this function returns an int type value, you just called the funcin, never printed the deleted value
			
		case 5:
			printf("\n deleted value is %d",deletelast(&list));
			break;
			
		case 6:
			reverse(&list,&list2);
			printf("\n the reversed list is: \n ");
			display(&list2);
			break;
		
		case 7:
			printf("Enter the value you wanna search: ");
			scanf("%d",&searchvalue);
			search(&list,searchvalue);
			break;
			
		case 8:
			printf("the count is %d \n",count(&list));
			break;
			
		case 9:
			printf("displaying value........\n");
			display(&list);
			break;
			
		case 10:
			printf("GOODBYE SHITHEAD.....");
			exit(0);
			break;
			
		default:
			printf("Invalid input \n");
	}
  }
}
int main()
{
	snglist list,list2;
	init(&list);		// you forgot to initialze lol
	init(&list2);
	menu();
	return 0;
}
