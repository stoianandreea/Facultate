#include <iostream>
using namespace std;
int partitie(int v[],int p,int q)
{int i=p,x=v[q],j;
for(j=p;j<q;j++)
    if(v[j]<=x)
        {swap(v[i],v[j]);
        i++;}
swap(v[i],v[q]);
return i;}
int k_element (int v[],int l,int r, int k)
{if(k>0&&k<=r-l+1)
    {int p=partitie(v,l,r);
    if(p-l==k-1)
        return v[p];
    if(p-l>k-1)
        return k_element(v,l,p-1,k);
    return k_element(v,p+1,r,k);
    }
return -1;
}
int main()
{int n,v[100],k,i;
cin>>n;
for(i=0;i<n;i++)
    cin>>v[i];
cin>>k;
cout<<k_element(v,1,n,k);
    return 0;
}
