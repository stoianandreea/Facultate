#include <iostream>
using namespace std;
int n,m,i,j,k,a[100],b[100],c[200];
int main()
{cin>>n>>m;
    for(i=0;i<=n;i++)
        cin>>a[i];
    for(i=0;i<=m;i++)
        cin>>b[i];
      for(k=0;k<=n;k++)
        for(j=0;j<=m;j++)
        c[k+j]+=a[k]*b[j];
      for(i=0;i<=n+m;i++)
        cout<<c[i]<<' ';

    return 0;
}
