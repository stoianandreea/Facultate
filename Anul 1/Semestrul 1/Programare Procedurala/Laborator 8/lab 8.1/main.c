#include <stdio.h>
#include <stdlib.h>

int main()
{ int x=1;
    if((char*)x==0)
       printf("big endian");
   else
       printf("little endian");
    return 0;
}
