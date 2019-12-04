#include <stdio.h>
#include <stdlib.h>

void numere(long int n,int c,long int *par, long int *impar)
{int p=10;
    if(c%2!=0)
    {while(n)
     {*impar=*impar+n%10*p;
     n=n/10;
     *par=*par+n%10*p;
     n=n/10;
     p=p*10;
    }
    }
    else {while(n)
     {*par=*par+n%10*p;
     n=n/10;
     *impar=*impar+n%10*p;
     n=n/10;
     p=p*10;
    }}
}
int main()
{long int n,x,c,par,impar;
scanf("%d", &n);
x=n;
while(x)
{c++; x=x/10;}
numere(n,c,&par,&impar);
printf("Pozitii pare: %d\n",par);
printf("Pozitii impare: %d", impar);
    return 0;
}
