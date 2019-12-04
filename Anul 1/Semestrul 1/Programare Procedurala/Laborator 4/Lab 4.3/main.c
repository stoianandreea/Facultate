#include <stdio.h>
#include <stdlib.h>
struct Angajat
{short int varsta;
char nume[30], cnp[14];
char norma;
}v[100];
int main()
{printf("%d\n", sizeof(struct Angajat));
int n,i;
scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%hd %s %s %c", &v[i].varsta, &v[i].nume[30], &v[i].cnp[14], &v[i].norma);
  for(i=0;i<n;i++)
       if(v[i].cnp[0]=='1')
             if((v[i].varsta&(1<<5))==0&&(v[i].varsta&(1<<6))==0)
             printf("%s", v[i].nume);
    return 0;
}
