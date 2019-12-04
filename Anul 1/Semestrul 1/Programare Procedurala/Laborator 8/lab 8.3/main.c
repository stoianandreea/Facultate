#include <stdio.h>
#include <stdlib.h>
int n,i,j,x,y;
int **a;
int main()
{scanf("%d", &n);
a=(int**)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
    *(a+i)=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&(*(*(a+i)+j)));
for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
      printf("%d ",(*(*(a+i)+j)));
      printf("\n");}
printf("%d\n",(*(*(a+n/2)+n/2)));
printf("Diagonala principala:");
printf("\n");
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(i==j)
            printf("%d ",*(*(a+i)+j));
printf("Diagonala secundara:");
printf("\n");
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(i+j==n+1)
            printf("%d ",*(*(a+i)+j));
scanf("%d %d", &x, &y);
for(i=0;i<n;i++)
  {int aux=*(*(a+x)+i);
  *(*(a+x)+i)=*(*(a+y)+i);
  *(*(a+y)+i)=aux;
  }
for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
      printf("%d ",(*(*(a+i)+j)));
      printf("\n");}

    return 0;
}
