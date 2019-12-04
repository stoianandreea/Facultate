#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, i, j, x, y, sum=0;
    ifstream f("date.in");
    f>>n;                                      /// n=nr noduri
    vector <int> sg;                           /// sg=secventa de grade
    vector <int> se;                          /// se=etichetele
    vector <int> fin;
    for(i=0;i<n;i++){
        f>>x>>y;
        se.push_back(x);
        sg.push_back(y);
    }
    for(i=0;i<n;i++)
        sum+=sg[i];
    if(sum%2!=0){
        cout<<"Nu se poate construi un graf cu secventa data";
        return 0;
    }
    for(i=0;i<n;i++)
    if(sg[i]<0 || sg[i]>n-1){
        cout<<"Nu se poate construi un graf cu secventa data";
        return 0;
    }
    for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++)
    if(sg[i]<sg[j]){
        swap(sg[i], sg[j]);
        swap(se[i], se[j]);
    }
    }
    cout<<"Muchiile grafului sunt:"<<endl;
    while(!sg.empty()){
    for(i=1;i<=sg[0];i++){
        sg[i]--;
        if(sg[i]<0){
            cout<<"Nu se poate construi un graf cu secventa data";
            return 0;
        }
        fin.push_back(se[0]);
        fin.push_back(se[i]);
    }
    for(i=0;i<sg.size()-1;i++){
    for(j=i+1;j<sg.size();j++)
    if(sg[i]<sg[j]){
        swap(sg[i], sg[j]);
        swap(se[i], se[j]);
    }
    }
    sg.erase(sg.begin());
    se.erase(se.begin());
    }
    for(i=0;i<fin.size();i++){
        cout<<fin[i]<<fin[i+1]<<endl;
        i++;
    }
    f.close();
    return 0;
}
