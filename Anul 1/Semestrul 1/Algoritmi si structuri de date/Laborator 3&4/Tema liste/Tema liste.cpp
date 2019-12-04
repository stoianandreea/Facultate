#include <iostream>
using namespace std;
   struct nod {int info;
               nod *next;}*prim,*ultim;
     void adi(int x)
            {if (prim==NULL)
                 {prim=ultim=new nod;
                  prim->info=x;
                  prim->next=NULL;}
             else{nod *p=new nod;
                  p->info=x;
                  p->next=prim;
                  prim=p;}
            }
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
      void cv(int x)
            {int c=1; nod*p=prim;
            while(p!=NULL)
            {if(p->info==x)
                {cout<<c; break;}
             c++;p=p->next;}
             if(p==NULL)
                cout<<"-1";
             }
      void cp(int x)
            {int c=1; nod*p=prim;
            while(p!=NULL)
            {if(x==c)
                {cout<<p->info; break;}
             c++;p=p->next;}
             if(p==NULL)
                cout<<"-1";
             }
       void iv(int x)
             {nod*p=prim;
              while(p!=NULL&&p->info!=x)
              p=p->next;
              if(p==NULL) return;
              if(p==ultim)
              {nod *t=new nod;
               t->info=0;
               t->next=NULL;
               ultim->next=t;
               ultim=t;}
              else{nod *t=new nod;
                   t->info=0;
                   t->next=p->next;
                   p->next=t;}
             }
       void ip(int i)
             {nod*p=prim;
              int c=1;
              if(i==0)
                 {nod *t=new nod;
                 t->info=0;
                 t->next=prim;
                 prim=t;}
              else{while(p!=NULL&&c!=i)
              {p=p->next; c++;}
              if(p==NULL) return;
              else{nod *t=new nod;
                   t->info=0;
                   t->next=p->next;
                   p->next=t;}
             }}
        void sv(int x)
        { nod *last=NULL;
        nod *p=prim;
       while(p!=NULL&&p->info!=x)
           {last=p; p=p->next;}
        if(p==NULL) return;
        if(p==prim)
          {prim=prim->next;
           if(ultim==p)
           ultim=NULL;
           delete p;}
        else if(p==ultim)
           {last->next=NULL;
            ultim=last;
            delete p;}
        else
            {last->next=p->next;
             delete p;}
        }

     void sp(int i)
      {nod*last=NULL;
       nod *p=prim; int c=1;
       while(p!=NULL&&c!=i)
           {last=p; p=p->next; c++;}
        if(p==NULL) return;
        if(p==prim)
          {prim=prim->next;
           if(ultim==p)
           ultim=NULL;
           delete p;}
        else if(p==ultim)
           {last->next=NULL;
            ultim=last;
            delete p;}
        else
            {last->next=p->next;
             delete p;}
        }




int main()
{af(); cout<<endl;
 adi(1); adi(2); adi(3); af(); cout<<endl;
 adf(4); af(); cout<<endl;
 cv(5); cout<<endl;
 cv(1); cout<<endl;
 cp(5); cout<<endl;
 cp(3); cout<<endl;
 sp(1); af(); cout<<endl;
 sp(1); af(); cout<<endl;
 sv(4); af(); cout<<endl;
 adf(5); af(); cout<<endl;
 sv(1); sp(1); af(); cout<<endl;
 adf(8); af();
 }
