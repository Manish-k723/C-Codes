#include<stdio.h>
#include<stdlib.h>
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m,int i,int j,int x)
{
    if(j>=i)
        m->A[(j*(j-1))/2+(i-1)]=x;
}
int get(struct matrix m,int i,int j)
{
   if(j>=i)
    return m.A[(j*(j-1))/2+(i-1)];
   else
    return 0;
}
void display(struct matrix m)
{ for(int i=1;i<=m.n;i++)
{
    for(int j=1;j<=m.n;j++)
    {
        if(j>=i)
            printf("%d ",m.A[(j*(j-1))/2+(i-1)]);
        else
            printf("0 ");
    }
    printf("\n");
}
}
int main()
{
    struct matrix m;
    int x;
    int j;
    printf("Enter the dimension");
    scanf("%d",&m.n);
    m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
    printf("Enter Elements");
    for(int i=1;i<=m.n;i++)
{
    for( int j=1;j<=m.n;j++)
{   scanf("%d",&x);
    set(&m,i,j,x);
}
}
printf("\n\n");
display(m);
    return 0;
}
