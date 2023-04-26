#include<iostream.h>
int main()
{
    int x,n=2;
    cout<<"Enter the number to check";
    cin>>x;
    while(n!=x)
    {
        int a;
        a=x%n;
        if(x!=0)
        {
            cout<<"It's a composite number";
            break;
        }
        n++;
    }
   return 0;
}

