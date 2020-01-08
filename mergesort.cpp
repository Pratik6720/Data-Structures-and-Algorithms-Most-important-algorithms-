#include<stdio.h>
#include<conio.h>
#define size 100

void merge(int arr[],int,int,int);
void merge_sort(int arr[],int,int);

void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,temp[size],k;
	while((i<mid)&&(j<=end))
	{
		if(arr[i]<arr[j])
		{
			temp[index]=arr[i];     // here in class book we have taken index=k don't confuse dude
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	arr[k]=temp[k];
}
void merge_sort(int arr[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}

int main()
{
	int i,n,arr[size];
	printf("enter the number of elements in an array:");
	scanf("%d",&n);
	printf("\n Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf("\n the array sorted  is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",arr[i]);
	}
	return 0;
}
