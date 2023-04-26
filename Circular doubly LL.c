#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head=NULL;
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->prev=head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->prev=last;
        t->next=head->prev;
        head->prev=t->next;
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
int main()
{
    int A[]={10,20,30,40,65,66};
    create(A,6);
    return 0;
}
