//Algoritmul lui Kruskal - varianta cu arbori pentru retinerea reprezentantilor
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int h[100], t[100];
vector <pair <int, pair <int,int> > > E;
vector <pair <int,int> > T;
int Find(int x){
    if(x==t[x])
        return x;
    t[x]=Find(t[x]);
    return t[x];
}
void Union(int x, int y){
    int r1=Find(x);
    int r2=Find(y);
    if(h[r1]<h[r2])
        t[r1]=r2;
    else if(h[r2]<h[r1])
        t[r2]=r1;
    else{
        t[r2]=r1;
        h[r1]++;
    }
}
int main()
{
    int n, m, c, x, y, i, nms=0, ok=1;       /// nms=nr muchii selectate
    ifstream f("date.in");
    f>>n>>m;                                 /// n=nr noduri; m=nr muchii
    for(i=0;i<m;i++){
        f>>x>>y>>c;
        E.push_back({c,{x,y}});
    }
    sort(E.begin(), E.end());
    i=0;
    for(int i=1;i<=n;i++){
        t[i]=i;
        h[i]=0;
    }
    while(nms<n-1){
        if(i==m) {
        cout<<"Nu exista APCM!";
        ok=0; break;
        }
        pair<int, int> muchie=E[i].second;
        i++;
        if(Find(muchie.first)!=Find(muchie.second)){
            T.push_back(muchie);
            nms++;
            Union(muchie.first, muchie.second);
        }
    }
    if(ok)
        for(i=0;i<n-1;i++)
            cout<<T[i].first<<' '<<T[i].second<<endl;
    f.close();
    return 0;
}
