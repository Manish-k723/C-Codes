#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
void create(struct queue *q,int size)
{
    q->size=size;
     q->rear=q->front=-1;
    q->Q=(int *)malloc((q->size)*sizeof(int));

}
void renqueue(struct queue *q,int x )
{
    if(q->rear==q->size-1)
    {
        printf("\nQueue is Full");
        return;
    }
    q->rear++;
    q->Q[q->rear]=x;
}
void fenqueue(struct queue *q, int x)
{
    if(q->front==-1)
    {
         printf("\nQueue is Full");
         return;
    }
    q->Q[q->front]=x;
    q->front--;
}
int rdequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
         printf("\nQueue is empty");
        return x;
    }
   x=q->Q[q->rear];
   q->rear--;
   return x;
}
int fdequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
        printf("\nQueue is empty");
        return x;
    }
    q->front++;
    x=q->Q[q->front];

    return x;
}
void display(struct queue q)
{
    int i;
    for (i=q.front+1;i<=q.rear;i++)
    {
        printf(" %d ",q.Q[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int ch;
    struct queue q;
    //printf("Enter the size of queue ");
    //scanf("%d",6);
   create(&q,7);
  do
  {
      printf("\nEnter from where you want insert of delete element and also enter the element if you want to insert");
  printf("\n 1. Insert from front ");
  printf("\n 2. Insert from rear ");
  printf("\n 3. Delete from front ");
  printf("\n 4. Delete from rear ");
  printf("\n 5.Display");
  printf("\n 6. Exit");
  printf("\nEnter you choice = ");
  scanf("%d",&ch);
  switch(ch)
  {
      case 1:{ printf("Enter value to insert");
               scanf("%d",&n);
               fenqueue(&q,n);
               break;
             }
      case 2:{  printf("Enter value to insert");
                scanf("%d",&n);
                renqueue(&q,n);
                break;
             }
      case 3:fdequeue(&q);
             break;
      case 4:rdequeue(&q);
             break;
      case 5:display(q);
              break;
  }}while(ch<6);
  display(q);
    return 0;
}
