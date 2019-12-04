#include <iostream>
using namespace std;
struct nod {int info;
               nod *next;}*prim,*ultim;
        void ad(int x)
             {nod*p=prim;
              nod*t=new nod;
              if(prim==NULL)
                 {t->info=x;
                  t->next=NULL;
                  prim=ultim=t;}
             else
                {if(x>prim->info)
                {while(p->next!=NULL&&p->next->info<x)
                       p=p->next;
                  t->info=x;
                  t->next=p->next;
                  p->next=t;}
                  if(x<=prim->info)
                    {t->info=x;
                     t->next=prim;
                     prim=t;}
                }
              }
         void af()
           {nod*p=prim;
           if(p==NULL)
                cout<<"lista vida";
            while(p!=NULL)
                 {cout<<p->info<<' ';
                  p=p->next;}
           }
int main()
{ ad(4); ad(2); ad(5); ad(4); ad(4); ad(1);
 af();
    return 0;
}
