#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 100
void insertion(int arr[],int n);

void insertion(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while((temp<arr[j]&&(j>=0)))
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
int main()
{
	int i,n,arr[10];
	printf("enter the number of elements in an array:");
	scanf("%d",&n);
	printf("\n Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion(arr,n);
	printf("\n the array sorted in descending order is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",arr[i]);
	}
	return 0;
}
