#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};
void create (struct Stack *st)
{
    printf("Enter size of the stack = ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));

}
void display(struct Stack st)
{
   int i;
   for(i=st.top;i>=0;i--)
       printf("%d\n",st.s[i]);
}
void push(struct Stack *st,int x)
{
   if(st->top==st->size-1)
        printf("stack overflow\n");
    else
   {
       st->top++;
       st->s[st->top]=x;
   }
}
int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("stack underflow\n");
    else
       {
          x=st->s[st->top];
          st->top--;
       }
    return x;
}
int peek(struct Stack *st,int index)
{
    int x=-1;
    if(st->top-index+1<0)
        printf("invalid index");
    else
    {
        x=st->s[st->top-index+1];
    }
   return x;
}
int isEmpty(struct Stack st)
{
if(st.top==-1)
return 1;
return 0;
}
int isFull(struct Stack st)
{
return st.top==st.size-1;
}
int stackTop(struct Stack st)
{
if(!isEmpty(st))
    return st.s[st.top];
return -1;
}
int main()
{
    struct Stack st;
    create(&st);
    push(&st,3);
    push(&st,6);
    push(&st,8);
    push(&st,5);
    push(&st,10);
    push(&st,12);
    display(st);
    return 0;
}
