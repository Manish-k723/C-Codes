#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hash(int key)
{
    return key%SIZE;
}
int hash2(int key)
{
    return 7-(key%7);
}
int probe(int H[],int key)
{
    int index=hash(key);
    int pin=hash2(key);
    int i=0;
    //while((H[(index+i)%SIZE])!=0)
    while(H[((index)+i*pin)%SIZE]!=0)
    i++;
    return (index+pin)%SIZE;

}
void insert(int H[],int key)
{
    int index=hash(key);

    if(H[index]!=0)
    {
        index=probe(H,key);
    }
    H[index]=key;
}
int search(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while((H[(index+i)%SIZE])!=key)
    {
     if((H[(index+i)%SIZE])!=' ')
     {
         printf("Not found");
         return -1;
     }
        i++;
    }

    return (index+i)%SIZE;
}
int main()
{
    printf("Hello world!\n");
    int HT[10]={0};
    insert(HT,5);
    insert(HT,15);
     insert(HT,105);
    insert(HT,35);
    insert(HT,95);
    for(int i=0;i<10;i++)
        printf("%d\n",HT[i]);
   // printf("\nKey found at %d",search(HT,76));
    return 0;
}
