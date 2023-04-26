#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class stack
{
private:
    Node *top;
public:
    stack(){top=NULL;}
    void push(int x);
    int pop();
    void display();
    int peek(int index);

};
void stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stack is full"<<endl;
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int stack::pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        x=top->data;
        Node *t=top;
        top=top->next;
        delete(t);

    }
    return x;
}
void stack::display()
{
    Node *t=top;
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
int stack:: peek(int index)
{
    struct Node *t=top;
    int i;
    for(i=0;t!=NULL && i<index-1;i++)
    {
        t=t->next;
    }
    if(t)
        return t->data;
    else
        return -1;
}
int main()
{
    stack st;
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    cout<<endl<<"The searched element is "<<st.peek(3);
    st.display();
    return 0;
}
