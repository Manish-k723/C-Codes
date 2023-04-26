#include<stdio.h>
int main()
{int a[50],i,n;
int max,min,sum,avg;
max=sum=avg=0;
printf("Enter the length");
scanf("%d",&n);
for(i=0;i<n;i++)
    {printf("a[%d]=",i);
scanf("%d",&a[i]);}
min=a[0];
for(i=0;i<n;i++)
{
    sum=sum+a[i];
    if(a[i]>max)
     {
         max=a[i];
     }
else if(a[i]<min)
{
    min=a[i];
}
}
printf(" Maximum=%d\nMinimum=%d\nAverage=%d",max,min,sum/n);
return 0;

}
