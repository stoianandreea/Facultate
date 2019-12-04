#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char a[1001][1001][26];                        // a=matricea cu literele din alfabet
int ok=0;
// w=cuvantul; sc=stare curenta; v=vector stari finale; poz=pozitia curenta in cuvant; n=nr total de stari
void verificare(char w[], int sc, int v[], int poz, int n){
    int i,k;
    k=strlen(w);
    if(poz<k){
       for(i=0;i<=n;i++)
         if(strchr(a[sc][i], w[poz])!=0)
            verificare(w, i, v, poz+1, n);
    }
    else {
        if(v[sc]!=0)
            ok=1;
        }
}
int main()
{int n, m, t, x, i, j, v[1001];
ifstream f("automat.txt");
f>>n;                                          // n=nr total de stari;
cout<<"Nr total de stari: "<<n<<endl;
f>>x;                                          // x=starea initiala
cout<<"Starea initiala: "<<x<<endl;
f>>m;                                          // m=nr stari finale
cout<<"Nr stari finale: "<<m<<endl;
for(i=0;i<n;i++)                               // v=vectorul starilor finale
    v[i]=0;
cout<<"Stari finale: ";
for(i=0;i<m;i++){
    f>>t;
    cout<<t<<' ';
    v[t]=1;
}
cout<<endl;
f.get();
char linie[1001];
char *p;
for(i=0;i<n;i++){
    j=0;
    f.get(linie, 1001);
    p=strtok(linie, " ");
    while(p!=NULL){
        strcpy(a[i][j], p);
        j++;
        p=strtok(NULL, " ");
    }
    f.get();
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        cout<<a[i][j]<<' ';
    cout<<endl;
}
char w[1001];
cout<<"Verificarea cuvantului: ";
cin>>w;
if(strchr(w,'*')){
    if(v[x]!=0)
       ok=1;
}
else
    verificare(w,x,v,0,n);
if(ok==1)
    cout<<"Cuvant acceptat";
else
    cout<<"Cuvant incompatibil";
    return 0;
}
