#include <stdio.h>
#include <stdlib.h>
int sumad(int x)
{int d,s=0;
for(d=1;d<x;d++)
    if(x%d==0)
    s=s+d;
return s;
}
int main()
{int n,a,b;
scanf("%d", &n);
for(a=1;a<=n;a++)
for(b=1;b<=n;b++)
{if(sumad(a)==b&&sumad(b)==a)
  printf("(%d,%d)",a,b);
}

    return 0;
}
