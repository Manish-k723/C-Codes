
#include<stdio.h>
#include<stdlib.h>
struct term
{
    int coeff;
    int exp;
};
struct poly
{
    int n;
    struct term *t;
};
void create(struct poly *p)
{
    printf("Enter no, of terms");
    scanf("%d",&p->n);
    p->t=(struct term *)malloc(p->n*sizeof(struct term));
    for(int i=0;i<p->n;i++)
    {
        printf("Enter term no. %d=",i+1);
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}
void display(struct poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        printf("%dx^%d+",p.t[i].coeff,p.t[i].exp);
    }
}
struct poly *add(struct poly *p1,struct poly *p2)
{
  int i,j,k;
   i=j=k=0;
  struct poly *sum;
  sum=(struct poly*)malloc(sizeof(struct poly));
  sum->t=(struct term*)malloc((p1->n+p2->n)*sizeof(struct term));
  while(i<p1->n && j<p2->n)
  {
      if(p1->t[i].exp>p2->t[j].exp)
        sum->t[k++]=p1->t[i++];
      else if(p2->t[j].exp>p1->t[i].exp)
       sum->t[k++]=p2->t[j++];
      else
       {
        sum->t[k].exp=p1->t[i].exp;
      sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
  }
  }
  for(;i<p1->n;i++)sum->t[k++]=p1->t[i];
   for(;j<p2->n;j++)sum->t[k++]=p2->t[j];
   sum->n=k;
   return sum;
};
int main()
{
    struct poly p1,p2,*p3;
    create (&p1);
    create (&p2);

    p3=add(&p1,&p2);
    printf("\nFirst polynomial\n");
    display(p1);
    printf("\nsecond polynomial\n");
    display(p2);
    printf("\nsum polynomial\n");
    display(*p3);

    return 0;
}
