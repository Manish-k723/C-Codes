#include<iostream>
using namespace std;
class diagonal
{
private:
int*A;
int n;
public:
    diagonal()
{
n=2;
A=new int[2*(2+1)/2];
}
diagonal(int n);
void create();
int get(int i,int j);
void Set(int i, int j, int x);
void display();
~diagonal();
    };
diagonal:: diagonal(int n)
{
    this->n=n;
    A=new int[n];
}
diagonal::~diagonal()
{
  delete []A;
}
void diagonal::create()
{
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
             if(i==j)
             {cin>>x;
                A[i-1]=x;}
        }
    }
}
int diagonal:: get(int i, int j)
{

    if(i==j)
      cout<<A[i-1]<<" ";
    else
        cout<<"0 ";
        return 0;
}
void diagonal:: Set(int i,int j, int x)
{
    if(i==j)
        A[i-1]=x;
}
void diagonal:: display()
{
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                cout<<A[i-1]<<" ";
            else
                cout<<"o ";
        }
        cout<<endl;
    }
}
int main()
{
    int x,n,i,j,ch,y;
    cout<<"Enter the dimension of required array";
    cin>>n;
     diagonal dm(n);
     do{
        cout<<" Following services are available\n";
        cout<<" 1.Create "<<endl<<" 2.Get "<<endl<< " 3.set "<<endl<< " 4.Display "<<endl;
        cout<<" Enter service you needed= ";
        cin>>ch;
        switch(ch)
        {
            case 1:dm.create();
                   break;
            case 2:cout<<"Enter indices";
                   cin>>x>>y;
                   dm.get(x,y);
                   break;
            case 3:cout<<"Enter elements and indices";
                   cin>>i>>j>>x;
                   dm.Set(i,j,x);
                   break;
            case 4:dm.display();
                   break;
        }
     }while(ch<5);

     return 0;
}
