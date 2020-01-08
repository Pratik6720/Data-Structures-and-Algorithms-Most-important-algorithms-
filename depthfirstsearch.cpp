#include<stdio.h>
# define max 8
void depth_first_search(int adj[][max],int visited[],char start)
{
	int stack[max];
	int top=-1,i;
	printf("%c->",start+65);
	visited[start]=1;
	stack[++top]=start;
	while(top!=-1)
	{
		start=stack[top];
		for(i=0;i<max;i++)
		{
			if(adj[start][i]&&visited[i]==0)
			{
				stack[++top]==i;
				printf("%c->",i+65);
				visited[i]=1;
				break;
			}
		}
		if(i==max)
		top--;
	}
}
int main()
{
	int adj[max][max];
	int visited[max]={0},i,j;
 	printf("\n enter the adjency matrix: \n");
 	for(i=0;i<max;i++)
 	     for(j=0;j<max;j++)
 	     {
 	        scanf("%d",&adj[i][j]);
 	    }
 	     printf("DFS traversal: ");
 	     depth_first_search(adj,visited,1);
 	     printf("\n");
 	     return 0;	
}
