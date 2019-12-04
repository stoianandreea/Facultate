#include <stdio.h>
#include <stdlib.h>
int n,v[100],i,j,minim,aux;
int main()
{scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
for(i=1;i<n;i++)
    {minim=i;
    for(j=i+1;j<=n;j++)
        if(v[j]<v[minim])
            minim=j;
    aux=v[i];v[i]=v[minim];v[minim]=aux;
    }
 for(i=1;i<=n;i++)
    printf("%d %c",v[i],' ');
    return 0;
}
