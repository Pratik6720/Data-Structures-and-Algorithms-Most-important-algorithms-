#include<stdio.h>
#include<conio.h>
struct student
{
	int marks;
	char name[20];
};
void printdata(struct student y)
{
	printf("the marks are %d \n",y.marks);
	printf("the name is %s",y.name);
}
int main()
{
	struct student s1;
	printf("enter the marks");
	scanf("%d",&s1.marks);
	printf("enter the name");
	scanf("%s",&s1.name);
	printdata(s1);
	return 0;
	
}
