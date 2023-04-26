#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class linkedlist
{
private:
    Node *first;
public:
    linkedlist(){first=NULL;}
    linkedlist(int A[],int n);
    ~linkedlist();
    void display();
    void Insert(int index,int x);
    int Delete(int index);
    int Length();
    };
linkedlist::linkedlist(int A[],int n)
{
    Node *last ,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
linkedlist::~linkedlist()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
void linkedlist::display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<endl;
}
int linkedlist:: Length()
{
    int x=0;
    Node *p=first;
    while (p)
    {
       x++;
       p=p->next;
    }
    return x;
}
void linkedlist:: Insert(int index,int x)
{
    Node *p=first,*t;
    int i;
    if(index<0 || index>Length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
    {
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
            t->next=p->next;
        p->next=t;

    }
}
int linkedlist::Delete(int index)
{
    Node *p,*q=NULL;
    int i,x;
        if(index<0 || index>Length())
        return -1;
        if(index==1)
        {
            p=first;
            first=first->next;
            x=p->data;
            delete p;
        }
        else
        {
            p=first;
            for(i=0;i<index-1;i++)
            {
                q=p;
                p=p->next;
            }
            q->next=p->next;
            x=p->data;
            delete p;
        }
        return x;

}
int main()
{
    int A[]={1,2,3,4,5};
    linkedlist x(A,5);
    x.Insert(3,10);
    cout<<x.Length()<<endl<<x.Delete(1)<<endl<<x.Length()<<endl;
    x.display();
    return 0;
}
