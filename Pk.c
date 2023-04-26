#include<stdio.h>
struct Array
{
 int A[10];
 int size;
 int length;

};

void Display(struct Array arr)
{
 int i;
 printf("Elements are");
 for(i=0;i<arr.length;i++)
   printf("%d\n",arr.A[i]);
}

void InsertSort(struct Array * arr,int x)
{
 int i=arr->length-1;
 if(arr->length==arr->size)
       return ;
 while(i>=0&&arr->A[i]>x)
 {
  arr->A[i+1]=arr->A[i];
  i--;
 }
  arr->A[i+1]=x;
  arr->length++;
}

int IsSort(struct Array arr)
{
 int i;
 for(i=0;i<arr.length-1;i++)
 {
  if(arr.A[i]>arr.A[i+1])
     return 0;
 }
 return 1;
}

void swap(int *x , int *y)
{
 int temp;
 temp= *x;
 *x= *y;
 *y= temp;
}

void Rearrange(struct Array *arr)
{
 int i,j;
 i=0;
 j=arr->length;

 while(i<j)
 {

  while(arr->A[i]<0)i++;
  while(arr->A[j]>0)j--;
  if(i<j)
    swap(&arr->A[i],&arr->A[j]);
 }
}

int main()
{
 struct Array arr ={{4,6,9,12,15,22},10,6};
 InsertSort(&arr,7);
 printf("%d\n",IsSort(arr));
 Rearrange(&arr);
 Display(arr);
 return 0;
}

