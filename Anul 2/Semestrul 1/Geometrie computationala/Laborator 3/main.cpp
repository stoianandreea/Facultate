#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");

struct Punct {
    double x, y;
};

int intersectie(Punct a, Punct t, Punct b) {
    if(t.x <= max(a.x, b.x) && t.x >= min(a.x, b.x) && t.y <= max(a.y, b.y) && t.y >= min(a.y, b.y))
        return 1;
    else
        return 0;
}

int main()
{
    Punct A[4];
    for(int i = 0; i < 4; i++)
        f >> A[i].x >> A[i].y;
    double a1, a2, b1, b2, c1, c2;
    a1 = A[1].y - A[0].y;
    b1 = A[0].x - A[1].x;
    c1 = (-a1)*(A[0].x) + (-b1)*(A[0].y);
    a2 = A[3].y - A[2].y;
    b2 = A[2].x - A[3].x;
    c2 = (-a2)*(A[2].x) + (-b2)*(A[2].y);
    //cout << c1 << ' ' << c2 << endl;
    double det, x, y;                 // d = determinant
    det = a1*b2 - b1*a2;
    if(det != 0){
        x = (-c1)*b2 - b1*(-c2); x = x/det;
        y = a1*(-c2) - (-c1)*a2; y = y/det;
        Punct i; i.x = x; i.y = y;
        // verificam daca (x, y) apartine dreptelor A[0]A[1] si A[2]A[3]
        if( intersectie(A[0], i, A[1]) == 1 && intersectie(A[2], i, A[3]) == 1 )
                cout << "Se intersecteaza in punctul: (" << x << ", " << y << ")";
        else
                cout << "Nu se intersecteaza";
    }
    else {
        // rang M* = 1
        if (a1*b2 - b1*a2 == 0 && a1*c2 - c1*a2 == 0 && b1*c2 - c1*b2 == 0){
            // A0  A2---A1  A3
            if(intersectie(A[0], A[2], A[1]) && intersectie(A[2], A[1], A[3])) {
                cout << "Intersectia: segmentul cu capetele ";
                cout << "(" << A[2].x << ", " << A[2].y << "); (" << A[1].x << ", " << A[1].y << ")";
            }
            // A0  A3---A1  A2
            else if(intersectie(A[0], A[3], A[1]) && intersectie(A[3], A[1], A[2])) {
                cout << "Intersectia: segmentul cu capetele ";
                cout << "(" << A[3].x << ", " << A[3].y << "); (" << A[1].x << ", " << A[1].y << ")";
            }
            // A1  A2---A0  A3
            else if(intersectie(A[1], A[2], A[0]) && intersectie(A[2], A[0], A[3])) {
                cout << "Intersectia: segmentul cu capetele ";
                cout << "(" << A[2].x << ", " << A[2].y << "); (" << A[0].x << ", " << A[0].y << ")";
            }
            // A1  A3---A0  A2
            else if(intersectie(A[0], A[3], A[1]) && intersectie(A[2], A[0], A[3])){
                cout << "Intersectia: segmentul cu capetele ";
                cout << "(" << A[0].x << ", " << A[0].y << "); (" << A[3].x << ", " << A[3].y << ")";
            }
            // A0 A2---A3 A1
            else if(intersectie(A[0], A[2], A[3]) && intersectie(A[2], A[3], A[1])){
                cout << "Intersectia: segmentul cu capetele ";
                cout << "(" << A[2].x << ", " << A[2].y << "); (" << A[3].x << ", " << A[3].y << ")";
            }
            // A2 A0---A1 A3
            else if(intersectie(A[2], A[0], A[1]) && intersectie(A[0], A[1], A[3])){
                cout << "Intersectia: segmentul cu capetele ";
                cout << "(" << A[0].x << ", " << A[0].y << "); (" << A[1].x << ", " << A[1].y << ")";
            }

            else
                cout << "Nu se intersecteaza" << endl;
        }
        // rang = 2
        else
            cout << "Nu se intersecteaza";
    }
    return 0;
}
