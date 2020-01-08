#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 100
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
	int arr[size],num,i,n,found=0,beg,end,mid;
	printf("enter the number of elements in an array:");
	scanf("%d",&n);
	printf("\n Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection(arr,n);
	printf("\n the sorted array is: \n");
	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
	printf("\n Enter the number to be searched:");
	scanf("%d",&num);
	beg =0,end = n-1;
	while(beg<end)
	{
		mid=(beg+end)/2;
		if(arr[mid] == num)
		{
			printf("\n %d is present at array at position %d",num,mid+1);
			found==1;
			break;
		}
		else if(arr[mid]>num)
		end=num-1;
		else
		beg=num+1;
	}
	if(beg>end && found==0)
	printf("\n %d does not exist in array",num);
	return 0;
}
