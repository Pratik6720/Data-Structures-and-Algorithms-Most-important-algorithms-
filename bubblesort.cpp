#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,temp,arr[10];
	printf("enter the number of elements in an array:");
	scanf("%d",&n);
	printf("\n Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\n the array sorted  is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",arr[i]);
	}
	return 0;
}
