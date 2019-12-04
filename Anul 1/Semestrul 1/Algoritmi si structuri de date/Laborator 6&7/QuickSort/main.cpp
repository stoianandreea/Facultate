#include <iostream>
using namespace std;
int alegere_pivot(int v[],int p,int q)
{int aux,i=p,j=q,di=0,dj=1;
while(i<j)
    {if(v[i]>v[j])
        {swap(v[i],v[j]);
         swap(di,dj);}
    i+=di;j-=dj;
    }
return i;
}
void QuickSort(int v[],int st,int dr)
{if(st>=dr) return;
int p=alegere_pivot(v,st,dr);
QuickSort(v,st,p-1);
QuickSort(v,p+1,dr);
}
int main()
{int i,n,v[100];
cin>>n;
for(i=1;i<=n;i++)
    cin>>v[i];
QuickSort(v,1,n);
for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
    return 0;
}
