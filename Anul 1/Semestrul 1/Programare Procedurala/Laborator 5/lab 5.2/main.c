#include <stdio.h>
#include <stdlib.h>
int n,v[100],x,y,i,b;
 int cautare(int v[],int x)
 {int st=0,dr=n-1,a=0, mijl;
 while(st<=dr)
 {mijl=(st+dr)/2;
 if(v[mijl]==x)
 {a=mijl; return a;}
 else if(v[mijl]<x)
 st=(st+dr)/2+1;
 else dr=(st+dr)/2-1;
 }
 }
int main()
{scanf("%d", &n);
for(i=0;i<n;i++)
    scanf("%d", &v[i]);
scanf("%d %d", &x, &y);
  b=cautare(v,x);
  for(i=b+1;i<n&&v[i]<y;i++)
    printf("%d ", v[i]);





    return 0;
}
