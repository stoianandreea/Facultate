#include <iostream>
using namespace std;
struct nod {float info;
               nod *next;}*prim,*ultim;
     void adf(float x)
          {nod*p=new nod;
           if(prim==NULL)
              {p->info=x;
               p->next=NULL;
               prim=ultim=p;}
            else {p->info=x;
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
      void media()
      {nod*p=prim;
       while(p->next!=NULL)
       {nod*t=new nod;
        t->info=(p->info+p->next->info)/2;
        t->next=p->next;
        p->next=t;
        p=p->next->next;}
      }

int main()
{ adf(1); adf(2); adf(3); adf(4);
  media(); af();

    return 0;
}
