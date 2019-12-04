#include <stdio.h>
#include <stdlib.h>
int n,i,k,v[100],st,dr,poz,m;
int main()
{scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
scanf("%d",&k);
st=1;dr=n;
while(st!=dr)
    {m=(st+dr)/2;
    if(v[m]==k)
        poz=m;
    else if(k<v[m])
            dr=m-1;
            else st=m+1;
    }
if(poz!=0) printf("%d",poz);
else printf("-1");

    return 0;
}
