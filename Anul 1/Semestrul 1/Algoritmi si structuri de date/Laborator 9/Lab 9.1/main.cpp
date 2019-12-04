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
void RSD(arb*t)
     {if(t!=NULL)
        {cout<<t->info<<' ';
         RSD(t->st);
         RSD(t->dr);}
     }
void SRD(arb*t)
    {if(t!=NULL)
        {SRD(t->st);
         cout<<t->info<<' ';
         SRD(t->dr);}
    }
void SDR(arb*t)
    {if(t!=NULL)
         {SDR(t->st);
          SDR(t->dr);
          cout<<t->info<<' ';}
    }
int cauta(arb*t,int x)
    {if(t==NULL)
         return 0;
     if(t->info==x)
         return 1;
     else
        {if(t->info<x)
            cauta(t->dr,x);
         else cauta(t->st,x);
        }
}
int m=MinInt;
int Max(arb*t)
     {m=t->info;
      if(t->dr)
         Max(t->dr);
      return m;
     }
arb*t=NULL;
int main()
{insertion(t,5);
insertion(t,3);
insertion(t,0);
insertion(t,2);
insertion(t,7);
insertion(t,6);
insertion(t,9);
SRD(t); cout<<endl;
if(cauta(t,7)==1)
    cout<<"DA"<<endl;
else cout<<"NU"<<endl;
cout<<Max(t);
    return 0;
}
