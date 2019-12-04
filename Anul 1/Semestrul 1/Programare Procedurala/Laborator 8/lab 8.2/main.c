#include <stdio.h>
#include <stdlib.h>

int main()
{unsigned int x,i;
scanf("%d", &x);
unsigned char *y;
y=&x;
  for(i=0;i<4;i++)
      {printf("%p",*y);
      *y++;
      }
    return 0;
}
