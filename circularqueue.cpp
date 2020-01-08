#include<stdio.h>
#include<stdlib.h>
#define size 100

struct cir_queue
{
    int item[size];
    int front,rear;
}cq;

void init(struct cir_queue *);
void enqueue(struct cir_queue * , int);
int dequeue(struct cir_queue *);
void search(struct cir_queue * , int);
void change(struct cir_queue * , int);
void display(struct cir_queue *);
void menu();

void init(struct cir_queue *q)
{
    q->front=q->rear=size-1;
}

void enqueue(struct cir_queue *q , int v)
{
    if((q->rear+1)%size==q->front)
        printf("circular queue is overflow");
    else
        q->rear = (q->rear+1)%size;
        q->item[q->rear] = v;
}

int dequeue(struct cir_queue *q)
{
    int v;
    if(q->front==q->rear)
        printf("circular queue is underflow");
    else
         {
             q->front = (q->front+1)%size;
             v = q->item[q->front];
         }
         return v;
}

void display(struct cir_queue *q)
{
    int i;
    for(i=(q->front+1)%size ; i!=(q->rear+1)%size ; i=(i+1)%size)
    {
        printf(" %d\t " , q->item[i]);
    }
}

void search(struct cir_queue *q , int target)
{
    int i;
    for(i=(q->front+1)%size ; i!=(q->rear+1)%size ; i=(i+1)%size)
    {
        if(q->item[i]==target)
        {
            printf("Match Found \n");
            break;
        }
    }
    if(i==q->rear+1)
    {
        printf("Match not found \n");
    }
}

void change(struct cir_queue *q , int target)
{
    int i , n  , replace  ;
    for(i=(q->front+1)%size ; i!=(q->rear+1)%size ; i=(i+1)%size)
    {
        if(q->item[i]==target)
        {
            target = n;
            n = q->item[i];
            printf("You choosed the value %d \n" ,q->item[i]);
            printf("Enter the value you want to replace it:");
            scanf("%d",&replace);
            if(q->item[i]!=replace)
            {
                q->item[i] = replace ;
                printf("Changed value is %d \n" , q->item[i]);
                display(&cq);
            }
            else
                printf("New value %d is same as the old value " ,q->item[i]);
            break;
        }
    }
    if(i==q->rear+1)
    {
        printf("Match Not found");
    }

}

void menu()
{
    while(1)
    {
        int choice,value,number,chng;
        printf("\n -----Queue Implementation----- \n");
        printf("\n 1.Insert \n 2.Delete \n 3.Search \n 4.Change \n 5.Display \n 6.Exit \n");
        printf("\n Select any one : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\n Insert a value in the queue:");
            scanf("%d",&number);
            enqueue(&cq,number);
            break;

        case 2:
            printf("\n the deleted value is %d",dequeue(&cq));
            break;

        case 3:
            printf("\n Enter the value you want to search:");
            scanf("%d",&number);
            search(&cq,number);
            break;

        case 4:
            printf("Enter the value you want to change:");
            scanf("%d",&chng);
            change(&cq,chng);
            break;

        case 5:
        	printf("the value is:");
            display(&cq);
            break;

        case 6:
            printf("bye bye have a great day :)");
            exit (0);
            break;

        default:
            printf("Invalid input \n");
        }
    }
}
int main()
{
    menu();
    return 0;
}
