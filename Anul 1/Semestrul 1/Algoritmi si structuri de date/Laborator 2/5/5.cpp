#include <iostream>
#include <math.h>
using namespace std;
int n,t,k,p=0,ak;
int main()
{cin>>n>>t;
for(k=0;k<=n;k++)
    {cin>>ak;
     p=p+ak*pow(t,k);
    }
    cout<<p;
    return 0;
}
