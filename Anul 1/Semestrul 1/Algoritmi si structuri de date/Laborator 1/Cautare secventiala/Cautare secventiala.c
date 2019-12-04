#include <stdio.h>
#include <stdlib.h>
int n,v[100],i,k,poz;
int main()
{ scanf("%d",&n);
 for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
 scanf("%d",&k);
 for(i=1;i<=n;i++)
    if(v[i]==k)
        poz=i;
 if(poz!=0) printf("%d",poz);
 else printf ("-1");

    return 0;
}
