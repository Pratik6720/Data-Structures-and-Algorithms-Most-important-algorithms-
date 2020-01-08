#include<stdio.h>
#define SIZE 10
struct stack
{
	int item[SIZE];
	int top;
}s;
void init(struct stack*s);
void push(struct stack*s,int n);
int pop(struct stack*s);
int peep(struct stack*s,int i);
void change(struct stack *s,int i,int n);

void init(struct stack*p)
{
	p->top=-1;
}
void push(struct stack*p,int n)
{
	if(p->top==SIZE-1)
	{
		printf("stack is overflow");
	}
	else
	{
		p->top=p->top+1;
		p->item[p->top]=n;
	}
}
int pop(struct stack*p)
{
	int value;
	if(p->top==-1)
	{
		printf("stack is underflow");
	}
	else
	{
		p->top=p->top-1;
		value=p->item[p->top+1];
	}
	return value;
}
int peep(struct stack*p,int i)
{
	int value;
	if(p->top-i+1<0)
	{
		printf("invalid");
	}
	else
	{
		value=p->item[p->top-i+1];
	}
	return value;
}
void change(struct stack*p,int i,int n)
{
	if(p->top-i+1<0)
	{
		printf("invalid");
	}
	else
	{
		p->item[p->top-i+1]=n;
	}
}
int main()
{
	int i,c;
	init(&s);
	label:printf("\nmenu\n1.push\n2.pop\n3.peep\n4.change\n5.display\n6.exit");
	printf("\nenter your choice:");
	scanf("%d",&c);
	if(c==1)
	{
		int v;
		char j;
		printf("\nenter the index of the variable you want to push:");
		scanf("%d",&v);
		push(&s,v);
		printf("\npress y to continue and any other key to exit\n");
		scanf("%s",&j);
		if(j=='y'||j=='Y')
		{
			goto label;
		}
	}
	else if(c==2)
	{
		int p;
		char j;
		p=pop(&s);
		printf("\npoped variable is %d",p);
		printf("\npress y for continue and any other key to exit\n");
		scanf("%s",&j);
		if(j=='y'||j=='Y')
		{
			goto label;
		}
    }
    else if(c==3)
    {
    	int i,p;
    	char j;
    	printf("\nenter the index of the variable you want to peep");
    	scanf("%d",&i);
    	p=peep(&s,i);
    	printf("\n the peeped variable is %d",p);
    	printf("\npress y to continue and any other key to exit\n");
    	scanf("%s",&j);
    	if(j=='y'||j=='Y')
    	{
    		goto label;
		}
	}
	else if(c==4)
	{
		int i,v;
		char j;
		printf("enter the index and the value of variable you want to change:");
		scanf("%d %d",&i,&v);
		change(&s,i,v);
		printf("\npress y to continue and any other key to exit\n");
		scanf("%s",&j);
		if(j=='y'||j=='Y')
		{
			goto label;
		}
	}
	else if(c==5)
	{
		char j;
		for(i=s.top;i>-1;i--)
		{
			printf("%d \n",s.item[i]);
		}
		printf("\npress y to continue and any other key to exit\n");
		scanf("%s",&j);
		if(j=='y'||j=='Y')
		{
			goto label;
		}
	}
	else if(c==6)
	{
		printf("\ngoodbye\n");
	}
	else
	{
		printf("\ninvalid");
	}
	return 0;
}

