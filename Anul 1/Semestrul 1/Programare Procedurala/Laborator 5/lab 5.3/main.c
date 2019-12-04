#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int i,n,a=0;m,v[21],w[21],carry=0;
int max(int a, int b)
{if(a>b) return a;
else return b;
}
int main()
{scanf("%d %d", &n, &m);
for(i=0;i<n;i++)
    scanf("%d", &v[i]);
for(i=0;i<m;i++)
    scanf("%d", &w[i]);
    for(i=max(n,m);i>=0;i--)
  {a=v[i]+w[i-abs(n-m)]+carry;
   v[i]=a%10; carry=a/10;
  }
  if(carry!=0)
  printf("%d", carry);
  for(i=0;i<max(n,m);i++)
   printf("%d",v[i]);


    return 0;
}
