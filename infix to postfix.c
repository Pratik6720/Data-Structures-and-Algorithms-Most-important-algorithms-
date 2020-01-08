#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct stack
{
	int top;
	char item[SIZE];
}s;

void init(struct stack*);
void push(struct stack*,int);
char pop(struct stack*);
int precedence(char left,char right);
void convert(char infix[],char postfix[]);

void init(struct stack*p)
{
	p->top=-1;
}
void push(struct stack*p,int n)
{
	if(p->top==SIZE-1)
		printf("\n stack is overflow");
	else
	    p->top=p->top+1;
	    p->item[p->top]=n;
}
char pop(struct stack*p)
{
	char popped;
	if(p->top==-1)
	    printf("stack is underflow");
	else
	      p->top=p->top-1;
	      popped=p->item[p->top+1];
	return popped;
}
int precedence(char left,char right)
{
	if(left=='('||right=='(')
	  return 0;
	if(right==')')
	  return 1;
	  if(left=='*' || left=='/')
	  {
	  	if(right=='*'||right=='/'||right=='+'||right=='-')
	  	  return 1;
	  }
	  if(left=='-'||right=='+')
	  {
	  	if(left=='+'||right=='-')
	  	  return 1;
	  }
	  else
	  return 0;
}

void convert(char infix[],char postfix[])
{
	int i=0,j=0;
	char token;
	char popped;
	
	while(infix[i]!='\0')
	{
		token=infix[i];
		
		if( (token>='0' && token<='9') || (token>='a' && token<='z') ||(token>='A' && token<='Z'))
		{postfix[j++]=token;} 
		
		else if( token=='+' || token=='-' || token=='*' || token=='/' || token=='(' || token==')' || token=='$')
	    {
	    	while(s.top!=-1 && precedence(s.item[s.top],token))
	    	{
	    		popped=pop(&s);
	    		postfix[j++]=popped;
			}
			if(token==')')
			{
				pop(&s);
			}
			else
				push(&s,token);
				
		}
		i++;
    }
    while(s.top!=0)
    {
    	popped=pop(&s);
    	postfix[j++]=popped;
	}
	postfix[j]='\0';
}


int main()
{
	char infix[SIZE],postfix[SIZE];
	printf("enter the string:");
	scanf("%s",infix);
	
	convert(infix,postfix);
	printf("\n the converted string is %s",postfix);
	return 0;
}
