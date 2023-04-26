#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include<stdlib.h>
#include"queueheader.h"

struct Node
{
    int data;
    struct Node *next;
}
*first=NULL,*s=NULL,*third=NULL;


void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index<0 || index>count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;

    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;

            t->next=p->next;
            p->next=t;
        }
    }
int Delete(struct Node *p,int index)
{
    struct Node *q;
    int x = -1,i;
     if(index<0 || index>count(p))
        return -1;
    else if(index==1)
    {
        x=first->data;
        q=first;
        first=first->next;
        free(p);
        return x;
    }
    else
    {
        p=first;
        q=NULL;
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
         x=p->data;
        free(p);
         return x;
    }

}


#endif // SORTING_H_INCLUDED
