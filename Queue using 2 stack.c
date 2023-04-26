#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;
void push(struct queue *q,int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack overflow");
    else
        {
            t->data=x;
            t->next=top;
            top=t;
        }
}
int pop(struct queue *q)
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("stack underflow");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}
void enqueue(struct queue *q,int x)
{
    push(&q->s1,x);
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->s1==NULL && q->s2=NULL)
    {
        printf("\nQueue is Empty");
        return x;
    }
    if(q->s2==NULL)
    {
      while(q->s1!=NULL)
      {
          x=pop(&q->s1);
          push(&q->s2,x);
      }
    }
    x=pop(q->s2)
    printf("\n")
    return x;
}
void display(struct Node *top1,struct Node *top2)
{
    while(top1!=NULL)
    {
        printf("%d",top1->data);
        top1=top1->next;
    }
    while(top2!=NULL)
    {
        printf("%d",top2->data);
        top2=top2->next;
    }
}
int main()
{
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    char ch='y';
    int f=0,a;
    q->s1=NULL;
    q->s2=NULL;
    while((ch=='y' || ch=='Y'))
    {
    printf("Enter your choice\n 1.Add element to queue\n2.Remove element from queue \n3.Diplay\nExit\n" );
    scanf("%d",&f);
    switch(f)

                case 1:printf("\nEnter the element for insertion")
                    scanf("&d",&a);
                enqueue(q,a);
                case 2: dequeue(q);
                case 3:display(q->s1,q->s2);
                       break;
                case 4:exit(1);
                default: printf("\nInvalid");
                        break;
                        }


}
\
