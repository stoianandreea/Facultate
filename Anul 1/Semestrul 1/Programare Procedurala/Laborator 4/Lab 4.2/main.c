#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union tip_locuinta
{ int balcon;
  char apartament;
  char casa[20];
};
struct Locuinta
{ int nr_camere, suprafata;
  char adresa[100], tip[30];
  union tip_locuinta x;
}v[100];
char adresamax[100];
int main()
{int n, i, max=0;
scanf("%d", &n);
 for(i=0;i<n;i++)
 {scanf("%d", &v[i].nr_camere);
  scanf("%d", &v[i].suprafata);
  scanf("%s", &v[i].adresa);
  scanf("%s", &v[i].tip);
  if(strcmp(v[i].tip,"garsoniera")==0)
    scanf("%d", &v[i].x.balcon);
  else if(strcmp(v[i].tip,"apartament")==0)
    scanf("%c", &v[i].x.apartament);
  else if(strcmp(v[i].tip,"casa")==0)
    scanf("%s", &v[i].x.casa);
  }
for(i=0;i<n;i++)
 {if(strcmp(v[i].tip,"garsoniera")==0)
      if(v[i].x.balcon==1)
         if(v[i].suprafata>max)
         {max=v[i].suprafata;
           strcpy(adresamax,v[i].adresa);}
          }
          printf("%s", adresamax);
return 0;
}
