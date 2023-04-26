#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    return;
}
int findmax(int A[],int n)
{
    int max= -64322;
    for(int i=0;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}
void selection(int A[],int n)
{
    int k;
    for(int i=0;i<n-1;i++)
    {
        for(int j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[k],&A[i]);
    }
}
void insertionsort(int A[],int n)
{
    int j,x;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
void bubblesort(int A[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        {
             break;
        }

    }
}
int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=1,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
            do{j--;}while(A[j]>pivot);
            if(i<j)
                swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}
void Quicksort(int A[],int l, int h)
{
    int j;

    if(l<h)
    {
       j=partition(A,l,h);
       Quicksort(A,l,j);
       Quicksort(A,j+1,h);
    }
}
void merge(int A[],int l,int mid,int h)
{
    int i,j,k;
    i=l;
    j=mid+1;
    k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];

        else B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
    A[i]=B[i];
}
void Imergesort(int A[], int n)
{
    int p,i,l,mid,h;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=p+i)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        merge(A,0,p/2-1,n-1);
}

void Rmergesort(int A[],int l,int h)
{
   int mid;
   if(l<h)
   {
       mid=(l+h)/2;
       Rmergesort(A,l,mid);
       Rmergesort(A,mid+1,h);
       merge(A,l,mid,h);
   }
}
void countsort(int A[],int n)
{
    int max,i,j;
    max=findmax(A,n);
    int *C= (int *)malloc(sizeof(int)*max+1);
    for(i=0;i<max+1;i++)
    {
        C[i]=0;
    }
    for(i=0;i<n;i++)
    {
        C[A[i]]++;
    }
    i=0,j=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++]=j;
            C[j]--;
        }
        else j++;
    }
}
void shellsort(int A[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
       for(i=gap;i<n;i++)
       {
           temp=A[i];
           j=i-gap;
           while(j>=0 && A[j]>temp)
           {
               A[j+gap]=A[j];
               j=j-gap;
           }
            A[j+gap]=temp;
       }
    }
}
void binsort(int A[],int n)
{
    int max,i,j;
    struct Node *node=**bins;
    max=findmax(A,n);
    bins=(struct Node*)malloc(sizeof(struct Node)*(max+1));
    for(i=0;i<max+1;i++)
    {
        bins[i]=NULL;
        for(i=0;i<n;i++)
        {
            Insert(bins[A[i],A[i]);
        }
        i=0,j=0;
        while(i<max+1)
        {
          while(bins[i]!=NULL)
          {
              A[j++]=Delete(bins[i]);
          }
          i++;
        }
    }
}
int main()
{
    int A[]={72,46,53,23,44,56,43,7,14};
    int n=9;
    printf("\n");
    for(int i=0;i<n;i++)
        printf(" %d ",A[i]);
         printf("\n");
    shellsort(A,n);
    for(int i=0;i<n;i++)
        printf(" %d ",A[i]);
    return 0;
}
