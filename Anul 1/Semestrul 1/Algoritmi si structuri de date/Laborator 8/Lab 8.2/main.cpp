#include <iostream>
#define Max_Size 100
using namespace std;
struct Queue_node
       {int info;
        Queue_node *next;}*first,*last;
int top=0;
void push(int x)
     {if(top==Max_Size)
         {cout<<"Queue_Overflow";
          return;}
      if(first==NULL)
          {first=last=new Queue_node;
           first->info=x;
           first->next=NULL;}
      else
         {Queue_node *p=new Queue_node;
          p->info=x;
          p->next=NULL;
          last->next=p;
          last=p;}
      top++;
      }
int pop()
      {if(top==0)
          return -1;
       top--;
       int a=first->info;
       Queue_node *p=first;
       first=first->next;
       if(last==p)
           last=NULL;
       delete p;
       return a;
       }
int peek()
     {if(top==0)
        {cout<<"QUEUE_UNDERFLOW";
         return -1;}
      return first->info;
     }
int empty()
     {if(top==0)
           return 1;
      return 0;}
int search(int x)
     {int c=1;
      Queue_node*p=first;
      while(p!=NULL)
          {if(p->info==x)
               {return c; break;}
           c++;
           p=p->next;}
      return -1;
      }
void afisare()
      {Queue_node *p=first;
       if(p==NULL)
           cout<<"coada vida";
       else
           {cout<<"out ";
            while(p!=NULL)
                 {cout<<p->info<<' ';
                  p=p->next;}
            cout<<"in";}
       }
int main()
{afisare(); cout<<endl;
 push(1); push(2); push(3);
 afisare(); cout<<endl;
 cout<<search(2)<<endl;
 cout<<search(4)<<endl;
 cout<<empty()<<endl;
 cout<<pop()<<endl;
 afisare(); cout<<endl;
 cout<<peek()<<endl;
 afisare(); cout<<endl;
 pop(); pop();
 afisare(); cout<<endl;
 cout<<pop()<<endl;
 cout<<empty();

    return 0;
}
