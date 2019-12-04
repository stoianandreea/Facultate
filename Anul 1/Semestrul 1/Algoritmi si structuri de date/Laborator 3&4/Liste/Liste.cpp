#include <iostream>
using namespace std;
   struct nod {
          int info;
          nod *next;
              }*prim,*ultim;
         //adaugare la finalul listei

      void ad_f(int x)
    {if (prim==NULL)
       {prim=ultim=new nod;
        prim->info=x;
        prim->next=NULL;
       }
    else
        {nod *p=new nod;
         p->info=x;
         p->next=NULL;
         ultim->next=p;
         ultim=p;
        }
     }
          //afisarea listei

       void af()
     {nod*p=prim;
      while(p!=NULL)
         {cout<<p->info;
          p=p->next;
         }
      }
          //stergere

        void stergere(int x)
      {nod*last=NULL;
       nod *p=prim;
       while(p!=NULL&&p->info!=x)
           {last=p; p=p->next;}
        if(p==NULL) return;
        if(p==prim)
          {prim=prim->next;
           if(ultim==p) //verifica daca adresa din ultim=adresa din p
           ultim=NULL;
           delete p;
           }
        else if(p==ultim)
           {last->next=NULL;
            ultim=last;
            delete p;
            }
        else
            {last->next=p->next;
             delete p;
            }
         }
int main()
{ ad_f(1); ad_f(2); ad_f(3);
  stergere(1); stergere(2); stergere(3);
  ad_f(1); ad_f(2); ad_f(3);
  af();
}
