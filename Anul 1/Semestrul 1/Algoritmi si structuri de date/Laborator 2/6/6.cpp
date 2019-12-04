#include <iostream>
using namespace std;
int n,m,i,j,k,a[100],b[100];
int main()
{cin>>n>>m;
    for(i=0;i<=n;i++)
        cin>>a[i];
    for(i=0;i<=m;i++)
        cin>>b[i];
    if(n==m)
      for(k=0;k<=n;k++)
        cout<<a[k]+b[k]<<' ';
    else if(n<m)
        {for(k=0;k<=n;k++)
         cout<<a[k]+b[k]<<' ';
         for(j=k;j<=m;j++)
         cout<<b[j]<<' ';
         }
    else {for(k=0;k<=m;k++)
         cout<<a[k]+b[k]<<' ';
         for(j=k;j<=n;j++)
         cout<<a[j]<<' ';
         }
    return 0;
}
