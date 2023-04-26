#include<stdio.h>
#ifndef TREECPP_H_INCLUDED
#define TREECPP_H_INCLUDED
#include"Treecpp.h"
using namespace std;
class Node
{
  public:
    Node *lchild;
    int data;
    Node *rchild;

};
class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){front=rear=-1;size=10;Q=new Node*[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
    void enqueue(Node *);
    int isEmpty(){return rear==front;}
    Node * dequeue();
    void display();
};

void Queue::enqueue(Node *x)
{
    if(rear==size-1)
    {
        cout<<"Queue is Full";
        return;
    }
    rear++;
    Q[rear]=x;
}
Node * Queue ::dequeue()
{
    Node * x=NULL;
    if(front==rear)
    {
        cout<<"Queue is Empty";
        return x;
    }
    front ++;
    x=Q[front];
    return x;
}
void Queue :: display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}



#endif // TREECPP_H_INCLUDED
