#include<stdio.h>
#include<stdlib.h>
#define size 10
struct queue 
{
	int item[size];
	int front,rear;
}qu;
void init(struct queue *);
void enqueue(struct queue *, int);
int dequeue(struct queue *);
void search(struct queue *);
void change(struct queue *, int,int);

void init(struct queue *q)
{
	q->front=0;
	q->rear=0;
}

void enqueue(struct queue *q, int x)
{
	if(q->rear==size)
		printf("\n queue overflow");
	else if(q->rear==0 && q->front==0)
	{
		q->front=q->rear=1;	
		q->item[q->front]=x;
	}
	else
		q->rear=q->rear+1;
		q->item[q->rear]=x;
}

int dequeue(struct queue *q)
{
	int v;
	if(q->rear==0)
		printf("queue underflow");
	else
	{
		v=q->item[q->front];
		if(q->front==q->rear)
		{
			q->front=0;
			q->rear=0;
		}
		else
			q->front=q->front+1;
	}
	return v;
}

void search(struct queue *q)
{
	int i=0,t;		
	printf("\n enter value u wanna search");
	scanf("%d",&t);
	for(i=q->front;i<=q->rear;i++)
	{
		while(q->item[i]==t)
		{
			printf("\n match found ennjoyyyy");
			return;
		}
	}
	if(i==q->rear+1)
		printf("match not found, go die :)");
}

void change(struct queue *q,int v,int i)
{
	int newvalue,oldvalue;
	printf("\n enter the value you wanna change");
	scanf("%d",&oldvalue);
	printf("enter the new value");
	scanf("%d",&newvalue);
	for(i=q->front;i<=q->rear;i++)
	{
		if(q->item[i]==oldvalue)
		{
			(q->item[i]=newvalue);
			break;
		}
	}
		if(i==q->rear+1)
		printf("match not found go die :)");

}

void display(struct queue *q)
{
	if(q->rear==0)
		printf("\n queue underflow");
	int i;
	for(i=q->front;i<=q->rear;i++)
	{
		printf(" %d \t",q->item[i]);
	}
}
void menu()
{
	int choice,value,index,i;
	while(1)
	{
		printf("\n --------queue implementation--------");
		printf("\n 1.enqueue \n 2.dequeue \n 3.search \n 4.Change \n 5.display \n 6.Exit \n Select any one:");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					printf("\n enter value to insert:");
					scanf("%d",&value);
					enqueue(&qu, value);
					break;
				case 2:
					printf("\n deleted value is %d",dequeue(&qu));
					break;
				case 3:
					search(&qu);
					break;
				case 4:
					change(&qu,value,value);
					break;
				case 5:
					display(&qu);
					break;
				case 6:
					exit(1);
				default:
					printf("\n wrong choice! try again \n");
			}
	}	
}
int main()
{
	init(&qu);
	menu();
	return 0;
}
