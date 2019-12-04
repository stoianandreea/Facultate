/// sa se determine multimile I si J astfel incat
/// I reunit cu J = toate cele 4 puncte
/// I intersectat cu J = multimea vida
/// intersectia acoperirilor convexe ale celor doua multimi sa fie diferita de multimea vida
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("date.in");

struct punct {
    double x, y;
};
int orientare(punct a, punct b, punct c) {
    int val = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
    if(val == 0) return 0;     // coliniare
    if(val > 0) return 1;      // sensul acelor de ceasornic (dreapta)
    return 2;                  // sensul opus acelor de ceasornic (stanga)
}

int main()
{
    int i;
    punct A[4];
    for(i = 0; i < 4; i++)
        f >> A[i].x >> A[i].y;
    // Aflam cel mai din stanga punct - dupa x
    int mini = A[0].x, l = 0;
    int maxi = A[0].x, M = 0;
    for(i = 1; i < 4; i++) {
        if(mini > A[i].x) {
            mini = A[i].x;
            l = i;            // retin pozitia punctului
        }
        if(maxi < A[i].x) {
            maxi = A[i].x;
            M = i;            // daca toate sunt coliniare
        }
    }
    // daca toate sunt coliniare => cautam punctul cu y maxim
    if(l == M){
        maxi = A[0].y;
        for(i = 1; i < 4; i++)
            if(maxi < A[i].y) {
                maxi = A[i].y;
                M = i;
            }
    }

    vector<int> aux;  // lista cu pozitiile punctelor
    // aflam succesorul
    int p = l, b;
    do {
        // adaugam punctul curent la rezultat
        aux.push_back(p);
        // Aleg pivot aleator:
        if(p != 0) b = 0;
        else b = 1;
        // gasim cel mai din dreapta punct fata de p (punctul curent)
        for(i = 0; i < 4; i++)
            //daca punctul A[i] este la dreapta muchiei A[p]A[b] => actualizam b
            if(orientare(A[p], A[b], A[i]) == 2)
                b = i;
        p = b;
    }while(l != p); // pana la punctul initial

    //Nr de puncte din lista determina cazul
    int poz;
    // Daca toate punctele sunt coliniare
    // I = primul si ultimul punct de pe dreapta
    // J = punctele din centru
    if(aux.size() == 2) {
        cout << "I: (" << A[l].x << "," << A[l].y << "); (";
        cout << A[M].x << "," << A[M].y << ")" << endl;
        cout << "J: ";
        for(i = 0; i < 4; i++)
            if(i != l && i != M)
                cout << "(" << A[i].x << "," << A[i].y << "); ";
    }
    // Triunghi
    // I = varfurile triunghiului
    // J = punctul interior triunghiului
    else if(aux.size() == 3){
        cout << "I: (" << A[l].x << "," << A[l].y << "); (";
        poz = aux[1];
        cout << A[poz].x << "," << A[poz].y << "); (";
        poz = aux[2];
        cout << A[poz].x << "," << A[poz].y << ")"<<endl;
        cout << "J: (";
        for(i = 0; i < 4; i++)
            if(i != aux[0] && i != aux[1] && i != aux[2])
                cout << A[i].x << "," << A[i].y << ")" << endl;
    }
    // Patrulater
    // multimile reprezinta diagonalele
    else
    {
        cout << "I: (";
        poz = aux[0];
        cout << A[poz].x << "," << A[poz].y << "); (";
        poz = aux[2];
        cout << A[poz].x << "," << A[poz].y << ");" << endl;
        cout << "J: (";
        poz = aux[1];
        cout << A[poz].x << "," << A[poz].y << "); (";
        poz = aux[3];
        cout << A[poz].x << "," << A[poz].y << ");" << endl;
    }
    return 0;
}
