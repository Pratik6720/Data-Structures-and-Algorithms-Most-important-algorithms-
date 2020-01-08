#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 20
int small(int arr[],int k,int n);
void selection(int arr[],int n);


int small(int arr[],int k,int n)
{
	int pos=k,small=arr[k],i;
	for(i=k+1;i<n;i++)
	{
		if(arr[i]<small)
		{
			small=arr[i];
			pos=i;
		}
	}
	return pos;
}


void selection(int arr[],int n)
{
	int k,pos,temp;
	for(k=0;k<n;k++)
	{
		pos=small(arr,k,n);
		temp=arr[k];
		arr[k]=arr[pos];
		arr[pos]=temp;
	}
}


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
	selection(arr,n);
	printf("\n the array sorted is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",arr[i]);
	}
	return 0;
}
