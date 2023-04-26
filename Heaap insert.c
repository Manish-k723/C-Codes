#include<stdio.h>
void insert(int A[],int n)
{
    int temp,i=n;
    temp=A[n];

    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void swap(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    return;
}
int Delete(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
     A[1]=A[n];
     A[n]=val;
    i=1,j=2*i;

    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
}
int main()
{
    int A[]={0,10,20,30,25,5,40,35,32};
    int i,ch,m,k,p;
    for(i=2;i<=7;i++)
        insert(A,i);
        insert(A,8);
    for(i=1;i<=7;i++)
        printf("\n%d",A[i]);
        //printf("\nDeleted value is %d",Delete(A,7));
        //printf("\nDeleted value is %d",Delete(A,6));
        //for(i=1;i<=7;i++)
        //printf("\n%d",A[i]);
        do{
    printf("\nDo you want to \n 1). Insert \n 2). Delete \n 3).exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter value for insertion ");
                scanf("%d",&m);
               insert(A,m);
                break;

        case 2:for(k=8;k>=1;k--)
               {
                   Delete(A,k);
               }
                break;

    }
}while(ch<3);
 for(p=1;p<=8;p++)
        printf("\n%d",A[p]);
}
