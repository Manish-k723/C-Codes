#include<stdio.h>
#include<stdlib.h>
struct Node
{
   struct Node *lchild;
   int data;
   struct Node *rchild;
   int height;
}*root=NULL;

int Nodeheight(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct Node *p)
{
     int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;

}
struct Node *LLRotation(struct Node *p)
{
struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=p;
p->lchild=plr;

p->height=Nodeheight(p);
pl->height=Nodeheight(pl);
if(root==p)
root=pl;
return pl;
}
struct Node *LRRotation(struct Node *p)
{
   struct Node *pl=p->lchild;
   struct Node *plr=pl->rchild;

   pl->rchild=plr->lchild;
   p->lchild=plr->rchild;

   plr->rchild=p;
   plr->lchild=pl;
   pl->height=Nodeheight(pl);
   p->height=Nodeheight(p);
   plr->height=Nodeheight(plr);
  if(root==p)
   root=plr;
  return plr;
}
struct Node *RRRotation(struct Node *p)
{
    return NULL;
}
struct Node *RLRotation(struct Node *p)
{
    return NULL;
}
struct Node *Rinsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
      t=(struct Node *)malloc(sizeof(struct Node));
t->data=key;
t->height=1;
t->lchild=t->rchild=NULL;
return t;
    }
  if(key < p->data)
p->lchild=Rinsert(p->lchild,key);
else if(key > p->data)
p->rchild=Rinsert(p->rchild,key);
p->height=Nodeheight(p);
if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
return LLRotation(p);
else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
return LRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
return RRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
return RLRotation(p);
return p;
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
int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
int main()
{
root=Rinsert(root,30);
Rinsert(root,10);
Rinsert(root,5);
Rinsert(root,3);
Rinsert(root,1);


printf("%d",root->data);
return 0;
}
