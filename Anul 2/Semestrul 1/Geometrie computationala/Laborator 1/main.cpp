#include <iostream>
using namespace std;

class punct{
public:
    float x, y, z;
    punct(int i=0, int j=0, int k=0) { x=i; y=j; z=k; }
};

int main()
{
    float a;
    int ok = 0;
    punct A1(0,0,0), A2(0,0,0), A3(0,0,1);
    if(A1.x != A2.x || A1.y != A2.y || A1.z != A2.z){
        if(A2.x != A1.x)
            a = (float)(A3.x - A1.x)/(A2.x - A1.x);
        else if(A2.y != A1.y)
            a = (float)(A3.y - A1.y)/(A2.y - A1.y);
        else if(A2.z != A1.z)
            a = (float)(A3.z - A1.z)/(A2.z - A1.z);
        if((A3.x-A1.x)==a*(A2.x-A1.x) && (A3.y-A1.y)==a*(A2.y-A1.y) && (A3.z-A1.z)==a*(A2.z-A1.z))
            ok = 1;

        if(ok == 0)
        cout << "Nu sunt coliniare";
        else {
            cout << "Sunt coliniare\n";
            if(a<0)
                cout << "A3 = " << 1-a << "A1" << a << "A2";
            else
                cout << "A3 = " << 1-a << "A1 +" << a << "A2";
        }
    }
    else {
        cout << "Sunt coliniare\n";
        cout << "A2 = 1A1 + 0A3";
    }

    return 0;
}

