#include <iostream>
using namespace std;
struct nod {int info;
               nod *next;}*prim1,*prim2,*ultim1,*ultim2,*prim3,*ultim3;
      void ad1(int x)
            {if(prim1==NULL)
                {prim1=ultim1=new nod;
                 prim1->info=x;
                 prim1->next=NULL;}
             else{nod*p1=new nod;
                  p1->info=x;
                  p1->next=NULL;
                  ultim1->next=p1;
                  ultim1=p1;}
            }
        void ad2(int x)
            {if(prim2==NULL)
                {prim2=ultim2=new nod;
                 prim2->info=x;
                 prim2->next=NULL;}
             else{nod*p2=new nod;
                  p2->info=x;
                  p2->next=NULL;
                  ultim2->next=p2;
                  ultim2=p2;}
            }
      void ad3(int x)
            {if(prim3==NULL)
                {prim3=ultim3=new nod;
                 prim3->info=x;
                 prim3->next=NULL;}
             else{nod*p3=new nod;
                  p3->info=x;
                  p3->next=NULL;
                  ultim3->next=p3;
                  ultim3=p3;}
            }
      void af1()
           {nod*p1=prim1;
           if(p1==NULL)
                cout<<"lista vida";
            while(p1!=NULL)
                 {cout<<p1->info<<' ';
                  p1=p1->next;}
           }
      void af2()
           {nod*p2=prim2;
           if(p2==NULL)
                cout<<"lista vida";
            while(p2!=NULL)
                 {cout<<p2->info<<' ';
                  p2=p2->next;}
           }
        void af3()
           {nod*p3=prim3;
           if(p3==NULL)
                cout<<"lista vida";
            while(p3!=NULL)
                 {cout<<p3->info<<' ';
                  p3=p3->next;}
           }
int main()
{ ad1(4); ad1(6); ad1(8); af1(); cout<<endl;
  ad2(1); ad2(2); ad2(5); ad2(9); ad2(9); af2(); cout<<endl;
  nod*p1=prim1;
  nod*p2=prim2;
  while(p1!=NULL&&p2!=NULL)
      {if(p1->info<=p2->info)
             {ad3(p1->info);
             p1=p1->next;}
      else {ad3(p2->info);
            p2=p2->next;}
      }
  while(p1!=NULL)
  {ad3(p1->info);
  p1=p1->next;}
  while(p2!=NULL)
    {ad3(p2->info);
            p2=p2->next;}

af3();





    return 0;
}
