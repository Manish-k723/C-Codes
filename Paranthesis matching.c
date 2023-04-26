#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;
int isEmpty()
{
   if(top==NULL)return 1;
   return 0;
}
void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack overflow");
    else
        {
            t->data=x;
            t->next=top;
            top=t;
        }
}
int pop()
{
    struct Node *t;
   int x=-1;
    if(top==NULL)
        printf("stack underflow");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}
int stackTop()
{

}
int peek(int index)
{
    int i;
    struct Node *t=top;
    for(i=0;t!=NULL && i<index-1;i++)
    {
        t=t->next;
    }
    if(t)
     return t->data;
     else
     {
         printf("Not found");
         return -1;
     }

}
void display()
{
    struct Node *t=top;
    while(t)
    {
        printf(" %d ",t->data);
        t=t->next;
    }
    printf("\n\n");
}
int isBalanced(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')push(exp[i]);
        else if (exp[i]==')')
        {
            if(isEmpty())return 0;
            pop();
        }
    }
    if(isEmpty())return 0;
    return 1;
}
int match(char a,char b)
{
        if(a=='(' && b==')')
       {
         return 1;
       }
        if(a=='[' && b==']')
       {
         return 1;
       }
        if(a=='{' && b=='}')
       {
         return 1;
       }
       return 0;
}
int isBalanced2(char *exp)
{
    char popped_ch;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')push(exp[i]);
        else if (exp[i]==')')
        {
            if(isEmpty())return 0;
            popped_ch=pop();
            if(!match(popped_ch,exp[i]))
            {
                return 0;
            }
        }
    }
    if(isEmpty())return 1;
    return 0;
}
int pre(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    return 0;
}
int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else return 1;
}
char *intoPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
            push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
    }
int Eval(char *postfix)
{
int i=0;
int x1,x2,r=0 ;
for(i=0;postfix[i]!='\0';i++)
{
if(isOperand(postfix[i]))
{
push(postfix[i]-'0');
}
else
{
x2=pop();x1=pop();
switch(postfix[i])
{
case '+':r=x1+x2; break;
case '-':r=x1-x2; break;
case '*':r=x1*x2; break;
case '/':r=x1/x2; break;
}
push(r);
}
}
return top->data;
}

int main()
{
char *postfix="234*+82/-";
printf("Result is %d\n",Eval(postfix));
return 0;

}

/*int outpre(char x)
 {
    if(x=='+' || x=='-')
       {
           return 1;
       }
    else if(x=='*' || x=='/')
        {
            return 3;
        }
    else if(x=='^')
        {
            return 6;
        }
    else if(x=='(')
        {
            return 7;
        }
    else
    return 0;
}
int inpre(char x)
{
       if(x=='(')
       {
           return 0;
       }
        else if(x=='+' || x=='-')
        {
            return 2;
        }
        else if(x=='*' || x=='/')
        {
            return 4;
        }
        else if(x=='^')
        {
            return 5;
        }
        else
        {
            return -1;
        }
}
int isOperand1(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    else return 1;
}
char *intoPost1(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+5)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand1(infix[i]))
        {
            postfix[j++]=infix[i++];

        }

        else
        {
            if(outpre(infix[i])>(inpre(top->data)))
            {
                push(infix[i++]);

            }
            else
            {
                postfix[j++]=pop();


            }
        }

    }
         printf("\nHiii");
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("Hiiii");
    return postfix;
}*/


/*int isBalanced1(char *exp)
{
    int y;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || '[' || '{')
            {
                push(exp[i]);
            }
        else if (exp[i]==')' || ']' || '}')
        {
            if(top==NULL)return 1;
            y=pop1(exp[i]);
            if(y==0)
                return 1;
        }
    }
    if(isEmpty()) return 0;
    return 1;
}*/
