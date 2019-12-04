#include <iostream>
using namespace std;
struct nod {int info;
               nod *next;}*prim1,*prim2,*ultim1,*ultim2;
       void ad1(int x)
            {if(prim1==NULL)
                {prim1=ultim1=new nod;
                 prim1->info=x;
                 prim1->next=NULL;}
             else{nod *p1=new nod;
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
             else{nod *p2=new nod;
                  p2->info=x;
                  p2->next=NULL;
                  ultim2->next=p2;
                  ultim2=p2;}
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
      void suma()
           {int carry=0, sum=0;
           nod*p1=prim1;
           nod*p2=prim2;
           while(p1!=NULL&&p2!=NULL)
                 {sum=p1->info+p2->info+carry;
                     p1->info=sum%10;
                     carry=sum/10;
                  p1=p1->next;
                  p2=p2->next;
                 }
            if(p2!=NULL)
               {p1=ultim1;
               p1->next=p2;
               p1=p1->next;}
               nod*last=NULL;
             while(p1!=NULL)
                 {if(carry!=0)
                    {sum=p1->info+carry;
                     p1->info=sum%10;
                     carry=sum/10;}
                     last=p1;
                     p1=p1->next;}

            if(p1==NULL)
                if(carry!=0)
                    {nod*t=new nod;
                     t->info=carry%10;
                     last->next=t;
                     t->next=NULL;
                     ultim1=t;
             }
             }
int main()
{ad1(2); ad1(4); ad1(5); af1(); cout<<endl;
 ad2(4); ad2(3); af2(); cout<<endl;
 suma(); af1();
 /* ad1(9); ad1(9); ad1(9); af1(); cout<<endl;
 ad2(1); af2(); cout<<endl;
 suma(); af1(); */
 /* ad1(9); ad1(1); af1(); cout<<endl;
 ad2(1); ad2(1); af2(); cout<<endl;
 suma(); af1(); */
    return 0;
}
