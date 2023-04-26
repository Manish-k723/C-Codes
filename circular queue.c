#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q,int size)
{
    q->size=size;
     q->rear=q->front=0;
    q->Q=(int *)malloc((q->size)*sizeof(int));

}
void enqueue(struct queue *q,int x )
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("/nQueue is Full");
        return;
    }
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
        printf("Queue is empty");
        return x;
    }
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];

    return x;
}
void display(struct queue q)
{
    int i=q.front+1;
    do
    {
        printf(" %d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main()
{
    struct queue q;
    int n;
    printf("Enter the size of queue ");
    scanf("%d",&n);
   create(&q,n);
   enqueue(&q,10);
   enqueue(&q,20);
   enqueue(&q,30);
   enqueue(&q,40);
   display(q);
   printf("%d",dequeue(&q));
    return 0;
}

