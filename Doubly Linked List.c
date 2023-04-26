#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
     first=(struct Node*)malloc(sizeof(struct Node));
     first->data=A[0];
     first->prev=NULL;
     first->next=NULL;
     last=first;
     for(i=1;i<n;i++)
     {
          t=(struct Node*)malloc(sizeof(struct Node));
          t->data=A[i];
          t->prev=last;
          t->next=NULL;
          last->next=t;
          last=t;
     }
}
void display(struct Node *p)
{
    while(p)
    {
        printf(" %d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int Length(struct Node *p)
{
    int len=0;
    while (p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct Node *p,int index, int x)
{
    if(index<0 || index>Length(first))
    {
     printf("Input Error :-)\n");
     return;
    }
    struct Node *t;
    int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->prev=NULL;
        t->next=first;
        first->prev=t->next;
        first=t;
    }
    else
    {
        for(i=1;i<index-1;i++)p=p->next;
        t->next=p->next;
        t->prev=p;
        p->next=t;
        if(p->next)
            p->next->prev=t;

    }
}
int delete(struct Node *p,int index)
{
    if(index<0 || index>Length(first))
    {
     printf("Input Error :-)\n");
     return -1;
    }
    struct Node *q;
    int x=-1,i;
    if(index==1)
    {
        x=p->data;
        if(p->next)
          {
            p->next->prev=NULL;
            first=p->next;
            free(p);
          }
          else
            free(p);
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        x=p->data;
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        free(p);
    }
    return x;
}
void reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        first=p;

    }
}
int main()
{
    int A[]={10,20,30,40,65,66};
    create(A,6);
      //printf("%d \n",delete(first,1));
    //insert(first,1,15);
    display(first);
    reverse(first);
    display(first);
    printf("Number of elements in given LL is %d ",Length(first));
    return 0;
}
