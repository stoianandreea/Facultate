#include <iostream>
using namespace std;
int v[100],x;
void insertion(int v[100],int &n,int x)
{int i;
n=n+1;
v[n]=x; i=n;
while(i>1&&v[i]<v[i/2])
{swap(v[i],v[i/2]);
i=i/2;}
}
void extract_min(int v[100],int&n)
{v[1]=v[n];
n--;
int a,b,c,i=1,j,ok=1;
while(i<n)
    {ok=0;
    if(2*i<=n)
        {a=v[2*i];ok=1;}
    if(2*i+1<=n)
        {b=v[2*i+1];ok=1;}
    if(a<b)
        {c=a;j=2*i;}
    else {c=b;j=2*i+1;}
    if(v[i]>c&&ok)
       {swap(v[i],v[j]);i=j;}
     else break;
     }
}
int main()
{int j,t,n=0;
   cin>>t;
    for(j=1;j<=t;j++)
    {cin>>x; insertion(v,n,x);}
    for(j=1;j<=n;j++)
    cout<<v[j]<<' ';
    cout<<endl;
    extract_min(v,n);
    extract_min(v,n);
    for(j=1;j<=n;j++)
    cout<<v[j]<<' ';
    return 0;
}
