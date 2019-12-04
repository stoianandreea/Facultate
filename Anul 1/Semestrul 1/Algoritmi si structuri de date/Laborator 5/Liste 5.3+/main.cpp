#include <iostream>
using namespace std;
  struct nod {int info;
               nod *next;}*prim,*ultim;
         void adf(int x)
            {if(prim==NULL)
                {prim=ultim=new nod;
                 prim->info=x;
                 prim->next=NULL;}
             else{nod *p=new nod;
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
       void inversare()
            {nod*prev=prim;
            nod*curent=prim->next;
            nod*urm=prim->next->next;
            while(urm!=NULL)
                 {curent->next=prev;
                 if(prim==prev)
                    {prim->next=NULL;
                    ultim=prim;}
                  prev=curent;
                  curent=urm;
                  urm=curent->next;
                  }
            curent->next=prev;
            prim=curent;
            }
int main()
{adf(1); adf(2); adf(3); adf(4); inversare(); af();
    return 0;
}
