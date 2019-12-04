#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct nr_complex
{ int real,imaginar;
}*v;
int modul(int a, int b)
{sqrt(a*a+b*b);
}
int main()
{int n,i;
scanf("%d",&n);
v=malloc(n*sizeof(int));
for(i=0;i<n;i++)
    scanf("%d %d",&(v+i)->real,&(v+i)->imaginar);

    return 0;
}
