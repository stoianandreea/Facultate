#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
using namespace std;
ifstream f("date.in");
// int a[20][20]={0};              /// matricea de adiacenta
// int vizDFS[20]={0};             /// vector noduri vizitate
void DFS(int n, int nod, int a[20][20], int vizDFS[20]){
    int i;                      /// n=nr noduri
    vizDFS[nod]=1;
    cout<<nod<<' ';
    for(i=1;i<=n;i++)
        if(vizDFS[i]==0 && a[i][nod]==1)
           DFS(n, i, a, vizDFS);
}
queue <int> sal;
void BFS(int n, int nod, int a[20][20], int vizBFS[20]){
    int i;
    sal.push(nod);
    while(!sal.empty()){
        nod=sal.front();
        vizBFS[nod]=1;
        cout<<nod<<' ';
        for(i=1;i<=n;i++)
        if(vizBFS[i]==0 && a[i][nod]==1){
            sal.push(i);
            vizBFS[i]=1;
        }
        sal.pop();
    }
}
int main()
{   /// eventual declarari globale?
    int a[20][20]={0};              /// matricea de adiacenta
    int vizDFS[20]={0};             /// vector noduri vizitate
    int vizBFS[20]={0};
    int i, n, m, x, y;
    f>>n>>m;                        /// n=nr noduri; m=nr muchii
    for(i=0;i<m;i++){
        f>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    cin>>x;
    DFS(n, x, a, vizDFS);
    cout<<endl;
    BFS(n, x, a, vizBFS);
    f.close();
    return 0;
}
