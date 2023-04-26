#ifndef QUEUEHEADER_H_INCLUDED
#define QUEUEHEADER_H_INCLUDED


struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};
void create(struct queue *q,int size)
{
    q->size=size;
     q->rear=q->front=0;
    q->Q=( Node **)malloc((q->size)*sizeof(Node*));

}
void enqueue(struct queue *q, Node* x )
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("/nQueue is Full");
        return;
    }
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
}
 Node* dequeue(struct queue *q)
{
    Node* x=NULL;
    if(q->rear==q->front)
    {
        printf("Queue is empty");
        return x;
    }
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];

    return x;
}
int isEmpty(struct queue q)
{
    return q.front==q.rear;
}
#endif // QUEUEHEADER_H_INCLUDED
