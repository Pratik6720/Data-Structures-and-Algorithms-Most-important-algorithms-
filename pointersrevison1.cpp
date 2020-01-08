#include<stdio.h>
#include<conio.h>
struct student
{
	int marks;
	char name[20];
}s;
void printdata(struct student *s1)
{
	printf("enter the marks");
	scanf("%d",&s1->marks);
	printf("enter the name");
	scanf("%s",&s1->name);
}
int main()
{
	printdata(&s);
	printf("the marks are %d \n",s.marks);
	printf("the name is %s",s.name);
	return 0;
}
