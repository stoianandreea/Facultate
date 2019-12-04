#include <iostream>
#define Max_Size 100
using namespace std;
struct Stack_node
       {char info;
        Stack_node *next;}*first,*last;
int top=0;
void push(char x)
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
       char a=first->info;
       Stack_node *p=first;
       first=first->next;
       if(last==p)
           last=NULL;
       delete p;
       return a;
       }
int empty()
     {if(top==0)
           return 1;
      return 0;}
int main()
{char c;
int n,i,ok=1;
cin>>n;
for(i=0;i<n;i++)
    {cin>>c;
     if(c=='(')
        push(c);
     else
        {if(c==')')
             if(empty()==1)
                {cout<<"incorect"; ok=0;
                 break;}
             else pop();
         }
    }
if(ok==1)
   {if(empty()==1)
         cout<<"corect";
    else cout<<"incorect";
   }
return 0;
}
