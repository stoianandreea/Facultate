#include <stdio.h>
#include <stdlib.h>
int main()
{FILE*f=fopen("siruri.txt","r");
 if(f==NULL)
    {printf("Eroare la deschiderea fisierului");
     return 0;}
 int **a;
 **a=(int**)calloc(100,sizeof(int));
 int x,i=1,t,j=1,k=1,b,max=0;
 while(fscanf(f, "%d", &x)==1)
     {if(k%2!=0)
         {*(*(a+i)+j)=x;
         k++; b=x; j=1; i++;
         if(max<x)
            max=x;
         }
      else
         {if(b==1)
            {k++; i++;
            *(*(a+i)+j)=x;}
         else
            {*(*(a+i)+j)=x;
             b--; j++;
            }
         }
      }
for(t=1;t<=i;t++)
   {for(j=1;j<=max;j++)
       printf("%p ",*(*(a+i)+j));
    printf("\n");
    }
    return 0;
}
