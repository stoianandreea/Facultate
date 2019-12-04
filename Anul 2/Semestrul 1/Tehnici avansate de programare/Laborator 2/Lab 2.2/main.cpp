//Laboratorul 2 - varianta 1 - exercitiul 2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
using namespace std;

ifstream f("date.in");

vector<pair<pair<int,int>,int> > v;
vector<pair<pair<int,int>,int> >::iterator x;
list<vector<int> > L, T;
list<vector<int> >::iterator y, z;
// sortam crescator in functie de t si descrescator in functie de l
bool functie(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b) {
    if(a.first.second != b.first.second)
        return (a.first.second < b.first.second);
    else
        return (a.first.first > b.first.first);
}
/*
//sortam crescator in functie de numarul activitatii
bool func(const vector<int> &a, const vector<int> &b){
    return (a[0] < b[0]);
}
*/
int main()
{
    int n, l, t, i=1;
    f >> n;
    while(f >> l >> t){
        v.push_back({{l,t},i});
        i++;
    }
    sort(v.begin(), v.end(), functie);
    // adaugam primul element separat in lista
    // nr activitate; inceput interval; final interval; intarziere
    L.push_back({v[0].second, 0, v[0].first.first, v[0].first.first-v[0].first.second});
    //m = intarzierea maxima
    int m=v[0].first.first-v[0].first.second;
    // adaugam celelalte elemente in lista
    y = L.begin();
    for(i = 1; i < n; i++){
        L.push_back({v[i].second, (*y)[2], (*y)[2]+v[i].first.first, (*y)[2]+v[i].first.first-v[i].first.second});
        // calculam intarzierea maxima
        if(m < (*y)[2]+v[i].first.first-v[i].first.second)
            m = (*y)[2]+v[i].first.first-v[i].first.second;
        y++;
    }
/*
    // am copiat L in alta lista pentru a afisa in ordinea activitatilor
    for(y = L.begin(); y != L.end(); y++){
        T.push_back((*y));
    }
    T.sort(func);
    for(z = T.begin(); z != T.end(); z++)
        cout << (*z)[1] << " " << (*z)[2] << " " << (*z)[3] << endl;
*/
    cout << "Propunerea:\n";
    for(y = L.begin(); y != L.end(); y++)
        cout << (*y)[0] << ": " << (*y)[1] << " " << (*y)[2] << " " << (*y)[3] << endl;
    cout << "Intarziere " << m;
    return 0;
}

/*
    Complexitate: O(n*log n)
Sortare vector: O(n*log n)
Crearea listei: O(n)
Sortare lista: O(n*log n)

    Solutie:
Citim elementele (l si t) si le punem in vector alaturi de numarul activitatii
Sortam vectorul crescator in functie de t si descrescator in functie de l
Punem in lista elementele:
    - (*y)[0] : numarul activitatii
    - (*y)[1] : inceputul intervalului
    - (*y)[2] : sfarsitul intervalului
    - (*y)[3] : intarzierea
Calculam in acelasi timp si intarzierea maxima
Afisam toste elementele din lista si intarzierea

*/
