/// folosim matrice; construim w[][] matricea costurilor; initial, d[][]=w[][]; in cazul in care nu exista muchie
/// intre x si y, w[][] si d[][]=infinit, iar p[][]=0; altfel, p[i][]=i;
/// for(k) for(i) for(j) -> vezi formula
/// afisam recursiv cu functia void drum(i,j)-> daca i!=j, reapelam functia cu (i,p[i][j])

#include <iostream>
#include <fstream>
using namespace std;

int d[100][100], w[100][100], p[100][100];
void drum(int i, int j){
    if(i!=j)
        drum(i, p[i][j]);
    cout<<j<<" ";
}
int main()
{
    int i, j, k, n, m, x, y, c;
    ifstream f("date.in");
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        w[i][j]=100000;
    }
    for(i=1;i<=n;i++){
        f>>x>>y>>c;
        w[x][y]=w[y][x]=c;
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        d[i][j]=w[i][j];
        if(w[i][j]==100000)
            p[i][j]=0;
        else
            p[i][j]=i;
    }
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
       if(d[i][j]>d[i][k]+d[k][j]){
           d[i][j]=d[i][k]+d[k][j];
           p[i][j]=p[k][j];
        }
    drum(1,5);
    return 0;
}
