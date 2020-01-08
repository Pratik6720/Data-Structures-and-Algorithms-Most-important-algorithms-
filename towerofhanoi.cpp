#include<stdio.h>
#include<conio.h>

void toh(int n,char s,char a,char d)
{
	if(n==1)
	{
		printf("move disk from %c to %c \n",s,d);
		return;
	}
	else
	toh(n-1,s,d,a);
	toh(1,s,a,d);
	toh(n-1,a,s,d);
}

int main()
{
	int n;
	char s,a,d;
	printf("enter the value of n:");
	scanf("%d",&n);
	toh(n,'a','b','c');
	return 0;
}

