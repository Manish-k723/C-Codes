#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head;

    void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *h)
{
    do
    {
        printf("%d",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}
void rdisplay(struct Node *h)
{int flag=0;
if(h!=head || flag==0)
{
    flag=1;
    printf(" %d ",h->data);
   rdisplay(h->next);
}flag=0;}
void insert(struct Node *p,int index, int x)
{
    struct Node *t;
    int i;
    if(index<0)
        return;
    if (index==0)
    {
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=x;
         if(head==NULL)
         {
             head=t;
             head->next=head;
         }
         else
        {
            while (p->next!=head) p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
       {
         for(i=0;i<index-1;i++) p=p->next;
           t=(struct Node*)malloc(sizeof(struct Node));
     t->data=x;
    t->next=p->next;
    p->next=t;

       }
}
int Delete(struct Node *p,int index)
{
    struct Node *q;
    int i,x;
    if(index<0)
        return -1;
    if(index==1)
    {
        while(p->next!=head);p=p->next;
        x=head->data;
        if(head==p)
        {
            free(head);
            head=NULL;
        }
        else
        {
        p->next=head->next;
        free(head);
        head=p->next;
        }
    }
    else
    {
        for(i=0;i<index;i++)p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
int main()
{
    int A[]={10,20,30,40,65,66};
    create(A,6);
    insert(head,2,25);
    rdisplay(head);
    Delete(head,2);
    rdisplay(head);
}


