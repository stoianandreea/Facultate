#include <iostream>
using namespace std;
   void interclasare(int v[],int p,int m,int q)
        {int i=p,j=m+1,w[200],k=1;
         while(i<=m&&j<=q)
            {if(v[i]<v[j])
               {w[k]=v[i];
               i++; k++;}
             else {w[k]=v[j];
                   k++; j++;}
            }
         while(i<=m)
             {w[k]=v[i];
             k++; i++;}
         while(j<=q)
             {w[k]=v[j];
             k++; j++;}
             k=1;
         for(i=p;i<=q;i++)
         {v[i]=w[k]; k++;}
        }
   void mergesort(int v[],int p,int q)
        {if(p>=q) return;
         mergesort(v,p,p+(q-p)/2);
         mergesort(v,p+(q-p)/2+1,q);
         interclasare(v,p,p+(q-p)/2,q);
        }

int main()
{int i,n,v[200];
cin>>n;
for(i=1;i<=n;i++)
    cin>>v[i];
mergesort(v,1,n);
for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
    return 0;
}
