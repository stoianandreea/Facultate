#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <queue>
#include <list>
using namespace std;
/// d=distanta la cel mai apropiat vecin de s, t=tata, viz=varfurile vizitate
int d[100], t[100], viz[100];
int main (){
    int n, m, s, i, j, x, y, c;
    vector < pair<int, int> > Graf[100];           /// liste de adiacenta
    ifstream fin("date.in");
    fin>>n>>m;                                    /// n=nr noduri; m=nr muchii
    for(i=0;i<m;i++){
        fin>>x>>y>>c;
        Graf[x].push_back({y, c});
        Graf[y].push_back({x, c});
    }
    for(i=0;i<=n;i++)
        d[i]=100000;
    cout<<"Introduceti Nod Start: ";
    cin>>s;
    d[s]=0;
    priority_queue < pair<int, int> > Q;
    Q.push({-d[s], s});
    while(!Q.empty()){
        x=Q.top().second;
        Q.pop();
        viz[x]++;
        for(auto i: Graf[x]){
            y=i.first;
            j=i.second;
            if(viz[y]==0 && d[y]>j){
                t[y]=x;
                d[y]=j;
                Q.push({-d[y], y});
            }
        }
    }
    for(i=1; i<=n; i++)
        if(t[i]!=0)
            cout<<t[i]<<' '<<i<<endl;
    fin.close();
	return 0;
}
