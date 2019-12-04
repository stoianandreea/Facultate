#include <iostream>
#include<string.h>
using namespace std;
struct arb
     {char info[21];
      arb *st, *dr;
     }*rad;
void insertion(arb *&t,char x[])
     {if(t==NULL)
        {t=new arb;
         strcpy(t->info,x);
         t->st=t->dr=NULL;
        }
      else
         {if(strcmp(x,t->info)<=0)
            insertion(t->st,x);
          else
            insertion(t->dr,x);
         }
      }
void SRD(arb*t)
    {if(t!=NULL)
        {SRD(t->st);
         cout<<t->info<<' ';
         SRD(t->dr);}
    }
arb*t=NULL;
int main()
{int n,i;
char s[21];
cin>>n;
for(i=0;i<n;i++)
   {cin.get();
    cin.get(s,21);
    insertion(t,s);
   }
SRD(t);

    return 0;
}
