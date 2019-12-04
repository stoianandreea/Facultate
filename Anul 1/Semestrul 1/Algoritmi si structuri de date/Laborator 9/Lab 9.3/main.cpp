#include <iostream>
#define MinInt -100
using namespace std;
struct arb
     {int info;
      arb *st, *dr;
     }*rad;
void insertion(arb *&t,int x)
     {if(t==NULL)
        {t=new arb;
         t->info=x;
         t->st=t->dr=NULL;
        }
      else
         {if(x<=t->info)
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
void cheie(arb*t,int k1,int k2)
    {if(t==NULL)
        return;
     if(t->info>k1&&t->info<k2)
        {cout<<t->info<<' ';
         cheie(t->st,k1,k2);
         cheie(t->dr,k1,k2);
        }
     else
        {if(t->info<k1)
            cheie(t->dr,k1,k2);
         if(t->info>k2)
            cheie(t->st,k1,k2);
        }
     }
arb*t=NULL;
int k1,k2;
int main()
{cin>>k1>>k2;
insertion(t,5);
insertion(t,3);
insertion(t,0);
insertion(t,2);
insertion(t,7);
insertion(t,6);
insertion(t,9);
SRD(t); cout<<endl;
cheie(t,k1,k2);
    return 0;
}
