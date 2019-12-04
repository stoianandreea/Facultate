// Laboratorul 2 - varianta 2 - exercitiul 3
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("date.in");

struct Activ {
   int nr, deadline, profit;
};

// sortam descrescator in functie de profit
bool Functie(Activ a, Activ b) {
     return (a.profit > b.profit);
}

int main()
{
    int n, i, k = 1;
    f >> n;
    Activ a[n];
    for(i = 0; i < n; i++){
        a[i].nr = k; k++;
        f >> a[i].profit;
        f >> a[i].deadline;
    }
    int pt = 0; // pt= profit total
    sort(a, a+n, Functie);
    // act = vectorul de activitati; slot = vector in care retinem slot-urile libere
    int act[n], slot[n];
    // Initializam slot-urile
    for(i = 0; i < n; i++)
        slot[i] = 0;
    for(i = 0; i <n ; i++) {
        // gasim un slot liber in care sa planificam activitatea
       for(int j = min(n, a[i].deadline)-1; j >= 0; j--) {
          if(slot[j] == 0) { // am gasit slot liber
             act[j] = i;  // adaugam activitatea
             slot[j] = 1; // marcam slotul ca fiind ocupat
             pt += a[i].profit;
             break;
          }
       }
    }
    for (int i=0; i<n; i++)
       if (slot[i])
         cout << a[act[i]].nr << " ";
    cout << endl << "Profit " << pt;
    return 0;
}

/*
    Complexitate: O(n*n)
Initializari: O(n)
Sortare: O(n*log n)
Verificare activitati + cautare slot liber: O(n*n)

    Corectitudine:
Vom demonstra prin inductie dupa n, asemanator cu demonstratia corectitudinii algoritmului lui Kruskal.
Pentru n = 0, este evident.
Pentru n >= 2, presupunem ca algoritmul Greedy construieste o solutie optima pentru orice multime de (n-1)
activitati si aratam ca afirmatia este adevarata si in cazul unei multimi de n activitati.
    (i) La pasul 1 adaugam in solutie activitatea A1, care apartine intervalului [k-1, k].
        Acum, daca A1 nu apartine solutiei optime O:
            Caz 1: in intervalul [k-1, k] exista deja o activitate, deci, pornind de la solutia O, putem construi
            o alta solutie, in care in acest interval plasam activitatea A1 si obtinem o nou solutie, optima fata
            de O, de unde avem o contradictie.
            Caz 2: in intervalul [k-1, k] nu exista nicio activitate, deci daca am adauga activitatea A1 in acest
            interval, am obtine o solutie optima fata de O, contradictie.
    (ii) Am presupus ca algoritmul este corect pentru n-1 activitati. La pasul n, se va cauta un interval liber in
         care putem plasa activitatea n din vector (acesta este sortat descrescator). Daca in vectorul slot gasim
         doar 1 (pe pozitiile in care putem pune activitatea), inseamna ca nu s-a gasit niciun interval liber si
         trecem la urmatoarea activitate. In caz contrar, daca va gasi o pozitie in slot = 0, atunci activitatea
         va fi adaugata in intervalul [k-1, k], iar in vectorul slot se va actualiza pozitia, insemnand ca acel
         interval este acum ocupat.

*/
