#include <iostream>
#define nmax 1500
using namespace std;
int Max(int v[], int n)
    {int m=v[1],i;
    for(i=2;i<=n;i++)
        m=max(m,v[i]);
    return m;
}
void Countsort(int v[], int n, int e)
   {int r[n],f[10]={},i;
    for(i=1;i<=n;i++)
        f[(v[i]/e)%10]++;
    for(i=1;i<10;i++)
        f[i]+=f[i-1];
    for(i=n;i>=1;i--)
        {r[f[(v[i]/e)%10]]=v[i];
        f[(v[i]/e)%10]--;}
    for(i=1;i<=n;i++)
        v[i]=r[i];
    }
void Radixsort(int v[], int n)
    {int m=Max(v,n);
    for(int e=1;m/e>0;e*=10)
        Countsort(v,n,e);
    }
void Afisare(int v[], int n)
    {for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
}
int main()
{ int n,v[nmax],i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    Radixsort(v,n);
    Afisare(v,n);
    return 0;
}
