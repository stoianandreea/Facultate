// Laboratorul 2 - varianta 1 - exercitiul 1
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

ifstream f("date.in");

vector<pair<int,int> > v, s;  // v = vector intervale; s = vector solutii
vector<pair<int,int> >::iterator it;
// sortam crescator v dupa primul element crescator
// in cazul egalitatii, sortam descrescator dupa al doilea element
bool functie(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.first != b.first)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}
int main()
{
    int a, b, n, x, y;
    f >> a >> b;                  // intervalul initial
    f >> n;                       // nr de intervale date
    while (f >> x >> y){
        if(x>b || y<a) continue;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(), functie);
    if(v[0].first>a){
        cout << "-1"; return 0;
    }
    s.push_back(v[0]);
    for(int i=1; i<n; i++){
// primul if => pt cazul in care s.size==1
// dintre intervalul deja existent in s si urmatorul din v, daca v.first<=a, verificam daca v.second > s.second
// in acest fel, alegem intervalul care il cuprinde pe a si cat mai mult din interval (ne apropiam de b)
// [a,b]=[10,20]; s[0]=[4,15], v[i]=[5,17]; alegem [5,17]
        if(v[i].first<=a && v[i].second>s[0].second)
            s[0]=v[i];
// acelasi lucru, dar verificam pentru penultimul interval din s, nu pt a
        else if(v[i].first<=s[s.size()-2].second && v[i].second>s[s.size()-1].second)
            s[s.size()-1]=v[i];
// verificam daca v.first apartine intervalului din s (adica v.first<=s.second)
// si daca v.second NU apartine intervalului (incercam sa extindem intervalul final spre b)
        else if(v[i].first<=s[s.size()-1].second && v[i].second>s[s.size()-1].second)
            s.push_back(v[i]);
        if(s[s.size()-1].second >= b)
            break;
    }
    if(s[s.size()-1].second < b){
        cout<<"-1"; return 0;
    }
    for(it=s.begin(); it!=s.end();it++)
        cout<<(*it).first<<' '<<(*it).second<<endl;
    return 0;
}
/*
    Complexitate: O(n*log n)
Sortare: O(n*log n)
Parcurgerea intervalelor: O(n)

    Solutie:
Ordonam intervalele crescator dupa ai si descrescator dupa bi
In cazul in care primul interval nu il cuprinde pe a, ie a<ai => nu avem solutie
Altfel, adaugam primul interval [ai, bi] din vector in solutie
Daca in vector exista un alt interval unde ak<=a si bk>(ultimul b din solutie) (bk>bi), modificam solutia si pastram intervalul pentru care bk e maxim
(Altfel spus, cautam primul interval [ag1,bg1] unde ag1<=a si bg1=max{bj|a<=bj})
In acest moment, avem in solutie un interval [ag1, bg1] ce il cuprinde pe a si cat mai mult din [a,b]
Pentru a gasi numarul minim de intervale ce cuprind [a,b], la fiecare pas in care ak<=(penultimul ag din solutie), bk trebuie sa fie maxim
(ie, la fiecare pas cautam primul interval [ag(t), bg(t)] unde ag(t)<=ag(t-2) si bg(t)=max{bj|bg(t-2)<=bj}
Verificam si cazul in care intervalul curent din v apartine intervalului solutiei; in cazul in care se apartine, nu il adaugam la solutie
Daca ultimul bk din solutie >= b ne oprim (am gasit deja nr minim de intervale)

    Corectitudine:
Fie o={[ao1,bo1],[ao2,bo2],...,[aop,bop]} o acoperire optima a lui [a,b] inclus in reuniune de la k=1 pana la p a intervalelor [aok,bok]
unde    - p=nr minim de intervale cu care poate fi acoperit [a,b]
        - ao1 <= a <= bo1
        - aop <= b <= bop
        - ao1 <= ao2 <= ... <= aop

Pas 1:
Aratam ca o'={[ag1,bg1],[ao2,bo2],...,[aop,bop]} este solutie optima
Cum bo1 <= bg1 rezulta ca [a,bo1] inclus in [a,bg1]
Deci [a,b] inclus in reuniune de la k=2 pana la p a intervalelor [aok,bok] reunit cu [ag1,bg1]
Rezulta ca o' e o acoperire cu p intervale (este optima)

Pas 2:
Fie o={[ag1,bg1],[ao2,bo2],...,[aop,bop]} o solutie optima
Aratam ca o'={[ao2,bo2],...,[aop,bop]} este o acoperire optima pt [bg1,b]
Pp prin reducere la absurd ca o'={[ao2,bo2],...,[aop,bop]} NU este o acoperire optima pt [bg1,b]
Fie t={[at1,bt1],..,[atq,btq]} acoperire optima a lui [bg1,b] cu tq < p-1
Atunci t'={[ag1,bg1],[at1,bt1],...,[atq,btq]} este o acoperire a lui [a,b] cu tq+1 < p intervale
Contradictie, rezulta ca o'={[ao2,bo2],...,[aop,bop]} este o acoperire optima pt [bg1,b]

Conform pas 1, exista o''={[ag2,bg2],[ao2,bo2],...,[aop,bop]} solutie optima pentru [bg1,b]

Astfel, repetand pasii 1 si 2 prin inductie, rezulta ca multimea intervalelor alese de algoritmul Greedy g={[ag1,bg1],[ag2,bg2],...,[agp,bgp]} este solutie optima

*/

