#include <iostream>
#define nmax 1500
using namespace std;
void CountingSort(int v[], int r[], int n, int k)
    {int i,f[k]={};
    for(i=1;i<=n;i++)
        f[v[i]]++;
    for(i=1;i<=k;i++)
        f[i]+=f[i-1];
    for(i=n;i>=1;i--)
        {r[f[v[i]]]=v[i];
        f[v[i]]--;}
    }
void afisare(int v[], int n)
       {int i;
        for(i=1;i<=n;i++)
        cout<<v[i]<<' ';
        }
int main()
{int i,n,v[nmax],r[nmax],m=0;
    cin>>n;
    for(i=1;i<=n;i++)
        {cin>>v[i];
        m=max(m,v[i]);}
    CountingSort(v,r,n,m);
    afisare(r,n);
    return 0;
}
