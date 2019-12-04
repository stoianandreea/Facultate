#include <iostream>
using namespace std;
struct nod {int info;
               nod *next;}*prim,*ultim;
       void ad(int x)
            {if(prim==NULL)
                {prim=ultim=new nod;
                 prim->info=x;
                 prim->next=NULL;}
             else{nod*p=new nod;
                  p->info=x;
                  p->next=NULL;
                  ultim->next=p;
                  ultim=p;}
            }
      void af()
           {nod*p=prim;
           if(p==NULL)
                cout<<"lista vida";
            while(p!=NULL)
                 {cout<<p->info<<' ';
                  p=p->next;}
           }
      void produs(int x)
           {int carry=0, prod=0;
           nod*p=prim;
           while(p!=NULL)
               {prod=p->info*x+carry;
                p->info=prod%10;
                carry=prod/10;
                p=p->next;
               }
            while(carry!=0)
                {nod*t=new nod;
                 t->info=carry%10;
                 carry=carry/10;
                 ultim->next=t;
                 t->next=NULL;
                 ultim=t;
                }
             }
int main()
{ ad(5); ad(2); af(); cout<<endl;
 produs(4); af();

    return 0;
}
