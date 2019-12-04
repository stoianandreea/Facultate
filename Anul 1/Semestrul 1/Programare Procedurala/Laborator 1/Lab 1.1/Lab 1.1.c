#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int a,b,c,d;
  float x1, x2;
int main()
{ scanf("%d %d %d",&a,&b,&c);
    d=b*b-4*a*c;
      if(d>=0)
     {x1=(-b+sqrt(d))/(2*a);
      x2=(-b-sqrt(d))/(2*a);
     printf("%f  %f", x1, x2);
     }

     if(d<0)
     { printf("%.2f+i%.2f",(float)((-b)/(2*a)), (sqrt(-d))/(2*a));
     printf("%.2f-i%.2f",(float)((-b)/(2*a)), (sqrt(-d))/(2*a));
       }

     return 0;

}
