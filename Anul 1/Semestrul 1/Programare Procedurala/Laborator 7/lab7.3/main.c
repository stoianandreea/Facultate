#include <stdio.h>
#include <stdlib.h>
int munte(int x)
{int c=0,d=0;
 while(x%10<x%100/10 && x>9)
     {x=x/10; c++;}
  if(c!=0)
    while(x%10>x%100/10 && x>9)
        {x=x/10; d++;}
  if(x<=9 && c>0 && d>0) return 1;
  return 0;
}
int main()
{int a,b,x, ok=0;
scanf("%d %d", &a,&b);
for(x=a;x<=b;x++)
{if(munte(x)==1)
    {printf("%d\n",x); ok=1; }}
 if(ok==0) printf("Nu exista");
    return 0;
}
