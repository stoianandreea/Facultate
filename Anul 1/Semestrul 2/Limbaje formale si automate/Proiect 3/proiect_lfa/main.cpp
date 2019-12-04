#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("date.in");
char g[50][50], CYK[50][50][50], neterm[50];
int nr_net;
void Algoritm(char* s1, char* s2, int x, int y){
    char Sir[3];
    int i, j, k;
    for(i=0;i<strlen(s1);i++)
    for(j=0;j<strlen(s2);j++){
        Sir[0]=s1[i];
        Sir[1]=s2[j];
        Sir[2]='\0';
        for(k=0;k<nr_net;k++)
            if(strstr(g[k], Sir) && !strchr(CYK[x][y], neterm[k]))
            /// daca sirul se gaseste pe linia din g si nu a mai fost scris pana acum
                CYK[x][y][strlen(CYK[x][y])]=neterm[k];
    }
}
void matrice(char w[50]){
    int i,j,k1,k2;
    /// Completez prima linie a matricei
    /// apar productiile cu litere mici corespunzatoare literei i din cuvantul verificat
    for(i=0;i<strlen(w);i++)
    for(j=0;j<nr_net;j++)
        if(strchr(g[j],w[i]))
            CYK[0][i][strlen(CYK[0][i])]=neterm[j];
    /// Completez celelalte linii ale matricei
    for(i=1;i<strlen(w);i++)
    for(j=0;j<strlen(w)-i;j++){
        for(k1=i-1,k2=0;k1>=0;k1--,k2++)
            if(CYK[k1][j][0]!='0' && CYK[k2][i+j-k2][0]!='0')
                Algoritm(CYK[k1][j],CYK[k2][i+j-k2],i,j);
        if(CYK[i][j][0]==0)
            CYK[i][j][0]='0';
    }
}
int main()
{
    int i, j, k1, k2, t=0;
    char a, b, c, w[50];
    f>>w;                            /// w=cuvantul verificat
    f>>nr_net;                       /// nr_net=nr neterminale
    for(i=0;i<nr_net;i++)
        f>>neterm[i];                /// neterm[]=vector neterminale
    /// g=matrice cu toate literele productiei
    while(!f.eof()){
        f>>a;
        f>>b;
        if(b>='A' && b<='Z')
            f>>c;
        for(i=0;i<nr_net;i++)
        if(neterm[i]==a){
            if(b>='A' && b<='Z'){
                g[i][strlen(g[i])]=b;
                g[i][strlen(g[i])]=c;
                g[i][strlen(g[i])]='/';
            }
            else{
                g[i][strlen(g[i])]=b;
                g[i][strlen(g[i])]=b;
                g[i][strlen(g[i])]='/';
            }
        }
    }
    /// Construiesc matricea
    matrice(w);
    if(strchr(CYK[strlen(w)-1][0],'S'))
        cout<<"Cuvantul este acceptat";
    else
        cout<<"Cuvantul nu este acceptat";
    return 0;
}
