#include <iostream>
using namespace std;
int k,n,v[100],i,j,a=0;
 int main ()
 {cin>>k>>n;
 for(i=1;i<=n;i++)
    cin>>v[i];
    cout<<"vector initial:";
    for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
    cout<<endl;
   for(i=1;i<=n;i++)
   { if(v[i]==k)
     { for(j=i;j<=n;j++)
          v[j]=v[j+1];
          n--; i--; a=1;
     }
   }
   cout<<"vector final:";
   for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
    if(a==0)
        cout<<' '<<"fara schimbari";
     return 0;
 }
