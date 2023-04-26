#include<iostream>
#include<stdio.h>
#include"Treecpp.h"
using namespace std;

class trees
{
private:
    Node * root;
public:
    trees(){root=NULL;}
    void createtree();
    void preorder(){preorder(root);}
    void preorder(Node *p);
    void Inorder(){Inorder(root);}
    void Inorder(Node *p);
     void postorder(){postorder(root);}
    void postorder(Node *p);
     void Levelorder(){Levelorder(root);}
    void Levelorder(Node *p);
     int height(){return height(root);}
    int height(Node *root);
};
void trees ::createtree()
{
     Node *p,*t;
    int x;
    Queue q(100);

    cout<<"Enter root value = ";
   cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("Enter left child of %d =",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter right child of %d =",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void trees:: Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d",p->data);
        printf("  ");
        Inorder(p->rchild);
    }
}
void trees::postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d",p->data);
        printf("  ");
    }
}
void trees::preorder(struct Node *p)
{
    if(p)
    {
        printf("%d",p->data);
        printf("  ");
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void trees:: Levelorder(struct Node *root)
{
    Queue q(100);
    printf("%d",root->data);
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            printf("%d",root->lchild->data);
            q.enqueue(root->lchild);
        }
         if(root->rchild)
        {
            printf("%d",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}
int trees:: height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
        else return y+1;
}
int main()
{
    trees t;
    t.createtree();
    t.preorder();
    printf("\n");
    t.Inorder();
      printf("\n");
    t.postorder();
    printf("\n");
    t.Levelorder();
     printf("\n");
    printf("%d",t.height());

    return 0;
}

