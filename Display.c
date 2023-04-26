 #include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}
*first=NULL,*s=NULL,*third=NULL;
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create1(int B[],int n)
{
    int i;
    struct Node *t,*last;
    s=(struct Node*)malloc(sizeof(struct Node));
    s->data=B[0];
    s->next=NULL;
    last=s;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}



void rdisplay(struct Node *p)
{
   if(p!=NULL)
   {
       printf("%d ",p->data);
       rdisplay(p->next);
   }
}
int count(struct Node *p)
{
    int x=0;
    while(p!=NULL)
    { x++;
      p=p->next;
    }
    return x;

}
int count1(struct Node *p)
{
      if(p==NULL)
      return 0;
      return count(p->next)+1;
}
void rdisplay1(struct Node *p)
{
   if(p!=NULL)
   {
       rdisplay1(p->next);
       printf("%d ",p->data);
   }
}
int max(struct Node *p)
{
    int max= INT_MIN;
    while(p!=NULL)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;

    }
return max;
}
int rmax(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT_MIN;
    x=rmax(p->next);
    if(x>p->data)
    return x;
    else return p->data;

}
struct Node* rsearch(struct Node *p,int key)
{
 if(p==NULL)
        return NULL;
 if(key==p->data)
    return p;
 return rsearch(p->next,key);
};
struct Node* search(struct Node *p, int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
          q->next=p->next;
          p->next= first;
          first=p;
          return p;
        }
        q=p;
        p=p->next;
    }
}
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
void sortedinsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
       first =t;
       else
       {
          while(p && p->data<x)
              {
                q=p;
                p=p->next;
              }

        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
}}
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
void reverse(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void concat(struct Node *p,struct Node *q)
{
    third=p;
    while(p->next!=NULL){p=p->next;}
    p->next=q;
}
void merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
       {
        third=last=p;
        p=p->next;
        third->next=NULL;
       }
    else {
            third=last=q;
             q=q->next;
            third->next=NULL;
    }
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
        if(q)last->next=q;
}
void isLoop(struct Node *p)
{
   struct Node *q,*r;
   q=r=p;
   do
   {
       p=p->next;
       q=q->next;
       q=q?q->next:q;
   }while (p && q && p!=q);
   if(p==q)
    printf("A Loop");
   else printf("Not a loop");

}
int middle(struct Node *p)
{
    struct Node *q=first;
    int count=1;
    while(p!=NULL)
    {
        p=p->next;
        if(p)p=p->next;
        if(p)
        {
            q=q->next;
            count++;
        }
    }
    printf("The middle element is at index = %d and element is ",count);
    return q->data;
}
int main()
{
    int n,temp=0;
    struct Node *t1,*t2;
    int A[]={10,20,30,40,65,66,76,87,98};
    //int B[]={12,23,64,68,70,73};
    create(A,9);
    //t1=first->next->next->next;
    printf("%d ",middle(first));
    //t2=first->next->next->next->next->next;
    //t2->next=t1;
    //create1(B,6);
    printf("\n");
    //isLoop(first);
   display(first);
    //reverse(first);
    //printf("Deleted Element is %d",Delete(first,3));
     printf("\n\n");
    //sortedinsert(first,356);
   //display(s);
  // merge(first,s);
   printf("\n\n");
    //display(third);
    //rdisplay1(first);
    //rdisplay1(first);
    /*printf("\nEnter Number for search ");
    scanf("%d",&n);
    temp =search(first,n);
    if(temp)
        printf("Key found=%d",n);
    else printf("key not found");
    printf("\n");
    //rdisplay(first);
    //search(first,n);
     //printf("\nMAX is%d ",rmax(first));*/
    return 0;
}
