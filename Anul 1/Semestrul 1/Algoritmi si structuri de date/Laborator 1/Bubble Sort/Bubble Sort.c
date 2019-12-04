#include <stdio.h>
#include <stdlib.h>
int n,v[100],i,m,ok;
int main()
{ scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
m=n;
do
    {ok=1;
     for(i=1;i<m;i++)
     if(v[i]>v[i+1])
            {int aux=v[i];v[i]=v[i+1];v[i+1]=aux;
             ok=0;
            }
     m--;
    }
while(ok==0);
for(i=1;i<=n;i++)
    printf(" %d",v[i]);
    return 0;
}
