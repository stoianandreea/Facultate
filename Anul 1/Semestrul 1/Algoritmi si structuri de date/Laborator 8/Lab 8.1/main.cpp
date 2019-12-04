#include <iostream>
#define Max_Size 100
using namespace std;
struct Stack_node
       {int info;
        Stack_node *next;}*first,*last;
int top=0;
void push(int x)
     {if(top==Max_Size)
         {cout<<"Stack_Overflow";
          return;}
      if(first==NULL)
          {first=last=new Stack_node;
           first->info=x;
           first->next=NULL;}
      else{Stack_node *p=new Stack_node;
            p->info=x;
            p->next=first;
            first=p;}
      top++;
      }
int pop()
      {if(top==0)
          return -1;
       top--;
       int a=first->info;
       Stack_node *p=first;
       first=first->next;
       if(last==p)
           last=NULL;
       delete p;
       return a;
       }
int peek()
     {if(top==0)
        {cout<<"STACK_UNDERFLOW";
         return -1;}
      return first->info;
     }
int empty()
     {if(top==0)
           return 1;
      return 0;}
int search(int x)
     {int c=0;
      Stack_node*p=first;
      while(p!=NULL)
          {if(p->info==x)
               {return c; break;}
           c++;
           p=p->next;}
      return -1;
      }
void afisare()
      {Stack_node *p=first;
       if(p==NULL)
           cout<<"stiva vida";
       else
           {cout<<"varf ";
            while(p!=NULL)
                 {cout<<p->info<<' ';
                  p=p->next;}
            cout<<"baza";}
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
