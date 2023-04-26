#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int *A,n,ch,x,i,j;
    printf("Enter the dimension :");
    scanf("%d",&n);
    A=(int *) malloc(n*sizeof(int));
    do{
        printf("Following services are available\n");
        printf(" 1.Create\n 2.Get\n 3.set\n 4.Display\n 5.Exit\n");
        printf(" Enter service you needed=");
        scanf("%d",&ch);
        switch(ch)
              {
                case 1: {for(int i=1;i<=n;i++)
                       {
                           scanf("%d",&A[i-1]);
                        }   break;}
               case 2: {printf("Enter indices");
                       scanf("%d%d",&i,&j);
                       if(i==j)
                        printf("%d",A[i-1]);
                        else
                        printf("0 ");
                        break;}
                case 3: {printf("Enter element and indices =");
                        scanf("%d%d%d",&i,&j,&x);
                        if(i==j)
                            A[i-1]=x;
                            break;}
                case 4: {for(i=1;i<=n;i++)
                        {
                            for(j=1;j<=n;j++)
                            {
                                if(i==j)
                                    printf("%d ",A[i-1]);
                                else
                                    printf("0 ");
                            }
                            printf("\n");
                        }
                        break;}

    }}
    while(ch<5);
    return 0;
}

