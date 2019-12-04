#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <map>
#include <list>
#include <utility>
using namespace std;

ifstream f("date.in");

void Sort (int &x, int &y, int &z)
{
    int mi = min(min(x, y), z);
    int ma = max(max(x, y), z);
    y = x + y + z - mi - ma;
    x = mi; z = ma;
}

int main()
{
    map <pair<int, int>, int> m;
    map <pair<int, int>, int>:: iterator it;
    list< vector<int> > L;
    list< vector<int> >::iterator p;
    int n, i;
    int lu, la, in;
    double r = 0;
    /// citim elementele din fisier si le punem in lista de vectori
    f >> n;
    for(i = 0; i < n; i++){
        f >>lu >> la >> in;
        L.push_back({lu,la,in});
    }
    /// luam fiecare vector din lista
    for(p = L.begin(); p!= L.end(); p++){
        /// il sortam crescator
        Sort((*p)[0], (*p)[1], (*p)[2]);
        /// verificam daca raza maxima este in functie de primul element din vector
        if((*p)[0]/2 > r)
            r = (*p)[0]/2;
        /// luam perechea formata din celelalte 2 numere
        pair <int, int> l;
        l = {(*p)[1], (*p)[2]};
        /// daca o gasim deja in map, vedem daca se modifica raza
        if(m.find(l) != m.end()){
            it = m.find(l);
            /// maximul (raza curenta si minimul dintre elementul mijlociu(comun) suma dintre cele 2 prime elemente (din pair si din map))
            r = max(r, min((*p)[1]/2.0, ((*p)[0] + it->second)/2.0));
            /// pastram in map perechea cu primul element mai mare
            if(it->second < (*p)[0])
                it->second = (*p)[0];
        }
        else
            m.insert({l,(*p)[0]});
    }
    cout << "Raza = " << r << endl;
    return 0;
}
