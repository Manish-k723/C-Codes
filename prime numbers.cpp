#include<iostream>
using namespace std;
int main()
{
    int x,n=2,flag=0;
    cout<<" Enter the number to check=";
    cin>>x;
    while(n!=x)
    {
        int a;
        a=x%n;
        if(a==0)
        {
            flag=1;
            break;
        }
        n++;
    }
    if(flag==1)
        cout<<endl<<"It's a composite number";
    else
        cout<<endl<<"A prime number";
   return 0;
}

