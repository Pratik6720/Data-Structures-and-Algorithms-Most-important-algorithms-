#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 20
int main()
{
	int arr[size],num,i,n,found=0,pos=-1;
	printf("enter the number of elements in an array:");
	scanf("%d",&n);
	printf("\n Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to be searched:");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(arr[i]==num)
		{
			found=1;
			pos=i;
			printf(" \n %d is found in the array at position=%d",num,i+1);
			break;
		}
	}
	if(found==0)
		printf("%d is not in the array cry in a corner",num);
		return 0;
 } 
