#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;
void push(int x)
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
int pop()
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
int peek(int index)
{
    int i;
    struct Node *t=top;
    for(i=0;t!=NULL && i<index-1;i++)
    {
        t=t->next;
    }
    if(t)
     return t->data;
     else
     {
         printf("Not found");
         return -1;
     }

}
void display()
{
    struct Node *t=top;
    while(t)
    {
        printf(" %d ",t->data);
        t=t->next;
    }
    printf("\n\n");
}
int main()
{
    push(5);
     push(6);
    push(8);
    push(10);
    push(16);
    push(18);
    display();
     printf("\nThe searched value is %d",peek(3));
     pop();
     display();
     printf("\nThe searched value is %d",peek(3));
    return 0;
}
