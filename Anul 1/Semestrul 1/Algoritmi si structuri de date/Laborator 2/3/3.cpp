#include <iostream>
using namespace std;
int k,n,t,v[100],i,j,a=0;
 int main ()
 {cin>>k>>n>>t;
  for(i=1;i<=n;i++)
    cin>>v[i];
    cout<<"vector initial:";
    for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
    cout<<endl;
   for(i=1;i<=n;i++)
   {if(v[i]==k)
     {for(j=n+1;j>i;j--)
          v[j]=v[j-1];
       v[i+1]=t; a=1; n++;
       break;
     }
   }
   cout<<"vector final:";
   for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
    if(a==0)
        cout<<' '<<"fara schimbari";
     return 0;
 }
