#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct tranzitie{
    int nr_s1;                       /// nr_s1=nr stari din care porneste litera
    int s1[100];                     /// s1[]=starile din care porneste litera
    char c;                          /// c=litera tranzitiei
    int nr_s2;                       /// nr_s2= nr stari care primesc litera
    int s2[100];                     /// s2[]=starile care primesc litera
};
struct automat{
    int q;                           /// q=nr total stari
    int si;                          /// si=starea initiala
    int nr_sf;                       /// nr_sf=nr stari finale
    int sf[100];                     /// sf[]=vector stari finale
    int l;                           /// l=nr de litere din alfabet
    char L[30];                      /// L[]=alfabetul de intrare
    int t;                           /// t=nr de tranzitii
    tranzitie T[100];                /// T[]=vector de tranzitii
}AFN, AFD;

int verificare(int i){
    int j, k;
    for(j=0;j<AFD.t;j++)
    if(AFD.T[i].nr_s2==AFD.T[j].nr_s1){        /// verific daca nr starilor al T[i] care primesc litera =
                                               /// = nr starilor al T[j] din care pleaca litera
        for(k=0;k<AFD.T[i].nr_s2;k++)
            if(AFD.T[i].s2[k]!=AFD.T[j].s1[k]) break;      /// daca starile ^ nu coincid, adaugam starea noua
        if(k==AFD.T[i].nr_s2) return 1;
    }
    return 0;
}
void reuniune(int i){
    int j, k, z=AFD.T[i].c-'a', poz, nr=0;  ///z=valoare literei din tranzitie; nr=nr stari finale tranzitie curenta
    for(j=0;j<AFD.T[i].nr_s1;j++){
        poz=AFD.T[i].s1[j]*AFN.l+z;         ///pozitia tranzitiei curente (merge din l in l pozitii in AFN + litera curenta)
        for(k=0; k<AFN.T[poz].nr_s2; k++){   ///luam din AFN toate starile din s2[] si le punem in AFD s2[]
            AFD.T[i].s2[nr]=AFN.T[poz].s2[k];
            nr++;
        }
    }
    for(j=0;j<nr-1;j++)
    for(k=j+1;k<nr;k++)
        if(AFD.T[i].s2[j]>AFD.T[i].s2[k])
            swap(AFD.T[i].s2[j], AFD.T[i].s2[k]);    ///sortam starile din s2[]
    for(j=0;j<nr-1;j++)
        if(AFD.T[i].s2[j]==AFD.T[i].s2[j+1]){        ///eliminam starile identice
            for(k=j+1;k<nr-1;k++)
                AFD.T[i].s2[k]=AFD.T[i].s2[k+1];
            nr--;
            j--;
        }
    AFD.T[i].nr_s2=nr;
}
void adaugare(int i){
    if(AFD.T[i].nr_s2==0) return;                   ///in cazul in care avem multime vida
    int j, k;
    for(j=0;j<AFN.l;j++){
        AFD.T[AFD.t+j].nr_s1=AFD.T[i].nr_s2;       ///nr starilor al T[AFD.t+j] din care pleaca litera=nr starilor al T[i] care primesc litera
        for(k=0;k<AFD.T[i].nr_s2;k++)
            AFD.T[AFD.t+j].s1[k]=AFD.T[i].s2[k];   ///copiem starile AFD.T[i].s2[] in AFD.T[AFD.t+j].s1[]
        AFD.T[AFD.t+j].c='a'+j;                    ///scriem litera
        reuniune(AFD.t+j);                         ///reunim starile in care ajunge fiecare stare din s1
    }
    AFD.t+=AFN.l;                                  ///crestem nr de tranzitii cu nr de litere din alfabet
}
void stari_finale() {
    int i, j, k, z=0;
    int ok;
    for(i=0;i<AFD.t;i+=AFN.l){ //pt fiecare stare a AFD
        ok=0;
        for(j=0;j<AFD.T[i].nr_s1;j++){ //pt fiecare cifra dintr-o stare
            for(k=0;k<AFN.nr_sf;k++) //pt fiecare stare finala din AFN
                if(AFN.sf[k]==AFD.T[i].s1[j]){
                    AFD.sf[z]=i;
                    z++;
                    ok=1;
                    break;
                }
            if(ok==1) break;
        }
    }
    AFD.nr_sf=z;
}
int main()
{   /// Citesc AFN din fisier
    int i, j, a, b;
    ifstream f("automat.txt");
    f>>AFN.q;
    f>>AFN.si;
    f>>AFN.nr_sf;
    for(i=0;i<AFN.nr_sf;i++)
        f>>AFN.sf[i];
    f>>AFN.l;
    for(i=0;i<AFN.l;i++)
        f>>AFN.L[i];
    f>>AFN.t;
    for(i=0;i<AFN.t;i++){
        f>>AFN.T[i].nr_s1>>AFN.T[i].s1[0];    /// folosesc s1[0] pt ca AFN are doar o stare din care se pleaca
        f>>AFN.T[i].c>>AFN.T[i].nr_s2;
        for(j=0;j<AFN.T[i].nr_s2;j++)
            f>>AFN.T[i].s2[j];
    }
    f.close();
    /// Construim AFD
    AFD.q=1;
    AFD.si=AFN.si;                  /// starea initiala a AFD este aceeasi cu a AFN
    AFD.nr_sf=0;
    AFD.t=0;
    /// copiem starea initiala cu tranzitiile pt fiecare litera
    for(j=0; j<AFN.l; j++){
        AFD.T[j].nr_s1=1;
        AFD.T[j].s1[0]=AFD.si;
        AFD.T[j].c='a'+j;
        AFD.T[j].nr_s2=AFN.T[j].nr_s2;
        for(a=0;a<AFD.T[j].nr_s2;a++)
            AFD.T[j].s2[a]=AFN.T[j].s2[a];
        AFD.t++;
    }
    for(i=0;i<AFD.t;i++)
    if(verificare(i)==0)                    ///verificam daca mai apare tranzitia
        adaugare(i);
    stari_finale();
    AFD.q=AFD.t/AFN.l;
/// Afisare AFD
    cout<<"AFD:"<<endl;
    cout<<"Nr total de Stari: "<<AFD.q<<endl;
    cout<<"Starea Initiala: "<< AFD.si<<endl;
    cout<<"Nr Stari Finale: "<<AFD.nr_sf<<endl;
    cout<<"Stari Finale: ";
    for(i=0;i<AFD.nr_sf;i++){
        for(j=0;j<AFD.T[AFD.sf[i]].nr_s1;j++)
            cout<<AFD.T[AFD.sf[i]].s1[j];
        cout<<' ';
    }
    cout<<endl<<"Tranzitii:"<<endl;
    for(i=0;i<AFD.t;i+=AFN.l){
        cout<<"Starea ";
        for(j=0;j<AFD.T[i].nr_s1;j++)
            cout<<AFD.T[i].s1[j];
        cout<<":"<<endl;
        for(a=0;a<AFN.l;a++){
            cout<<"     "<<AFD.T[i+a].c<<"->";
            if(AFD.T[i+a].nr_s2==0)
            cout << "Multime Vida";
            else for(j=0;j<AFD.T[i+a].nr_s2;j++)
            cout<<AFD.T[i+a].s2[j];
            cout<<endl;
        }
    }
    return 0;
}
