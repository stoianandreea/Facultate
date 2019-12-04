#include <stdio.h>
#include <stdlib.h>
int prim(int n)
{int d;
 for(d=2;d*d<=n;d++)
    if(n%d==0) return 0;
 return 1;
}
int prim_st(int n,int*d,int*a)
{d=n-1;
while(d>=0&&prim(d)==0)
{d--; a++;}
    return a;
}
int prim_dr(int n,int*c,int *b)
{c=n+1;
while(prim(c)==0)
{c++; b++;}
}
int main()
{int n,c,d,a,b;
b=1;a=1;
scanf("%d", &n);
if(a>b)
    printf("%d",c);
else printf("%d",d);


    return 0;
}
