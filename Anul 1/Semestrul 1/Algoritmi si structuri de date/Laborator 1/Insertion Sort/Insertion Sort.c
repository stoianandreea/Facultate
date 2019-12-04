#include <stdio.h>
#include <stdlib.h>
int n,v[100],i,j,k;
int main()
{scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
for(i=2;i<=n;i++)
    {k=v[i];
    j=i-1;
    while(j>0&&v[j]>k)
        {v[j+1]=v[j];
        j--;
        }
    v[j+1]=k;
    }
for(i=1;i<=n;i++)
    printf("%d %c",v[i],' ');
    return 0;
}
