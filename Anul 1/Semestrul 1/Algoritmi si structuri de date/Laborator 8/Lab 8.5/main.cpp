#include <iostream>
#define Max_Size 100
using namespace std;
struct Queue_node
       {int coordi, coordj ;
        Queue_node *next;}*first,*last;
int top=0;
void push(int i, int j)
     {if(top==Max_Size)
         {cout<<"Queue_Overflow";
          return;}
      if(first==NULL)
          {first=last=new Queue_node;
           first->coordi=i;
           first->coordj=j;
           first->next=NULL;}
      else
         {Queue_node *p=new Queue_node;
          p->coordi=i;
          p->coordj=j;
          p->next=NULL;
          last->next=p;
          last=p;}
      top++;
      }
void pop()
      {if(top==0)
          cout<<"-1";
       top--;
       Queue_node *p=first;
       first=first->next;
       if(last==p)
           last=NULL;
       delete p;
       }
int empty()
     {if(top==0)
           return 1;
      return 0;}
int M[100][100],m;
int main()
{cin>>m;
int i,j,a=1;
for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
        cin>>M[i][j];
for(i=0;i<=m+1;i++)
    for(j=0;j<=m+1;j++)
        if(i==0||j==0||i==m+1||j==m+1)
           M[i][j]=0;
for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
        {if(M[i][j]==1)
         {push(i,j);a++;}
         while(empty()==0)
             {M[first->coordi][first->coordj]=a;
              if(M[first->coordi-1][first->coordj]==1)
                 {push(first->coordi-1,first->coordj);
                  M[first->coordi-1][first->coordj]=a;}
              if(M[first->coordi][first->coordj-1]==1)
                 {push(first->coordi,first->coordj-1);
                  M[first->coordi][first->coordj-1]=a;}
              if(M[first->coordi][first->coordj+1]==1)
                 {push(first->coordi,first->coordj+1);
                  M[first->coordi][first->coordj+1]=a;}
              if(M[first->coordi+1][first->coordj]==1)
                 {push(first->coordi+1,first->coordj);
                  M[first->coordi+1][first->coordj]=a;}
               pop();
             }
        }
cout<<endl;
for(i=1;i<=m;i++)
    {for(j=1;j<=m;j++)
        cout<<M[i][j]<<' ';
     cout<<endl;}
    return 0;
}
