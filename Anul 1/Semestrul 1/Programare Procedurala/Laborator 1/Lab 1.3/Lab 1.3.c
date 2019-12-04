#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 int n,m,t;
int main()
{ scanf("%d", &n);
 /* n=n<<3;
 printf("%d", n);

 n=n>>2;
 printf("%d", n); */

n=(n<<3)+(n<<1);
printf("%d", n);


     return 0;

}
