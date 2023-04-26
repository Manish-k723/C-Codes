#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insert(int key)
{
    struct Node *t=root;
    struct Node *p,*r=NULL;

    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        //printf("Hello");
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
p=(struct Node*)malloc(sizeof(struct Node));
p->data=key;
p->lchild=p->rchild=NULL;

if(key<r->data)r->lchild=p;
else r->rchild=p;
//printf("Hii");
}
void Inorder(struct Node *p)
{
    if(p)
    {
        //printf("Hell");
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
struct Node *search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
 {
 if(t->data>key)
        t=t->lchild;
 else if(t->data<key)
       t=t->rchild;
 else return t;
}
return NULL;
}
struct Node *Rinsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=key;
       t->lchild=t->rchild=NULL;
       return t;
    }
    if(key>p->data)
        p->rchild=Rinsert(p->rchild,key);
    else if(key<p->data)
        p->lchild=Rinsert(p->lchild,key);
        return p;
}
int height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}
struct Node *Inpre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
struct Node *Insucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}
struct Node *Delete(struct Node *p, int key)
{

struct Node *q;
if(p==NULL)
    return NULL;
if(p->lchild==NULL && p->rchild==NULL)
{
if(p==root)
root=NULL;
free(p);
return NULL;
}
if(key<p->data)
p->lchild=Delete(p->lchild,key);
else if(key>p->data)
p->rchild=Delete(p->rchild,key);
else
{
if(height(p->lchild)>height(p->rchild))
{
q=Inpre(p->lchild);
p->data=q->data;
p->lchild=Delete(p->lchild,q->data);
}
else
{
q=Insucc(p->rchild);
p->data=q->data;
p->rchild=Delete(p->rchild,q->data);
}
}
return p;
};
int main()
{
struct Node *temp;
root=Rinsert(root,30);
Rinsert(root,10);
Rinsert(root,20);
Rinsert(root,40);
Rinsert(root,50);
Rinsert(root,80);

Inorder(root);
printf("\n");
temp=search(10);
if(temp)
printf("\nKey %d is found",temp->data);
else
printf("\nKey is not found");
Delete(root,10);
Inorder(root);
printf("\n");

temp=search(10);
if(temp)
printf("\nKey %d is found",temp->data);
else
printf("\nKey is not found");
return 0;
}
