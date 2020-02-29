// avem 4 puncte (dintre care 3 necoliniare)
// verificam daca patrulaterul format din cele 4 puncte este sau nu convex
// in cazul in care este, sa se studieze pozitia punctului A3 faa de cercul
// circumscris a triunghiului A0 A1 A2
// daca suma unghiurilor A1 si A3 este PI => A3 apartine cercului
// daca este > PI => A3 apartine interiorului cercului
// daca este < PI => A3 apartine exteriorului cercului

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
#define PI 3.14159265359
ifstream f("date.in");

struct punct {
    double x, y;
};
int peSegment(punct A, punct M, punct B){ // daca M apartine segment AB
    if(M.x <= max(A.x, B.x) && M.x >= min(A.x, B.x) &&
       M.y <= max(A.y, B.y) && M.y >= min(A.y, B.y))
       return 1;
    return 0;
}
double distanta(punct A, punct B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
double cosinus(punct B, punct A, punct C) {
    punct AB, AC;
    double prod;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    AC.x = C.x - A.x;
    AC.y = C.y - A.y;
    prod = AB.x * AC.x + AB.y * AC.y;
    return prod/(distanta(A, B) * distanta(A, C));
}

int main()
{
    punct A[4];
    int i;
    for(i = 0; i < 4; i++)
        f >> A[i].x >> A[i].y;
    double a1, a2, b1, b2, c1, c2;
    //Segment A0A2 - Ecuatie prima diagonala
    a1 = A[2].y - A[0].y;
    b1 = A[0].x - A[2].x;
    c1 = (-a1)*(A[0].x) + (-b1)*(A[0].y);
    //Segment A1A3 - Ecuatie a doua diagonala
    a2 = A[3].y - A[1].y;
    b2 = A[2].x - A[1].x;
    c2 = (-a2)*(A[2].x) + (-b2)*(A[2].y);

    //Calcul determinant pt a verifica daca diagonalele se intersecteaza
    double det, x, y;                 // d = determinant
    det = a1*b2 - b1*a2;
    if(det != 0){ //Intersectia e un punct => patrulaterul este convex
        x = (-c1)*b2 - b1*(-c2); x = x/det;
        y = a1*(-c2) - (-c1)*a2; y = y/det;
        punct q; q.x = x; q.y = y;
        if(peSegment(A[0], q, A[2]) == 1 && peSegment(A[1], q, A[3]) == 1){
            //Daca punctul apartine ambelor segmente
            cout << "Patrulaterul este convex" << endl;
            double u1, u2, u; //unghiul A1(A0A1A2), A3(A0A3A2)
            u1 = acos(cosinus(A[0], A[1], A[2])); //acos = transforma cos in valoarea lui in radieni
            u2 = acos(cosinus(A[0], A[3], A[2]));
            u = (u1 + u2)*180.0/PI;
            if(u > 179.99 && u < 180.01)
                cout << "A4 este pe cerc";
            else if(u > 180)
                cout << "A4 este in interiorul cercului";
            else
                cout << "A4 este in exteriorul cercului";
        }
        else
            cout << "Patrulaterul NU este convex" << endl;
    }
    else //Patrulaterul NU este convex (da multime vida)
        cout << "Patrulaterul NU este convex" << endl;

    return 0;
}
