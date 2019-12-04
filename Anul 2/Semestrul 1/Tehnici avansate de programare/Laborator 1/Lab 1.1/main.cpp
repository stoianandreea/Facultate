#include <iostream>
#include <fstream>
#include <utility>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

ifstream f("date.in");

unordered_set<string> triplete;
vector<int> v;

int main()
{
    int n, x, i, st, dr;
    f >> n;
    for(i = 0; i < n; i++){
         f >> x;
         v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(i = 0; i <= n-3; i++){
        st = i+1;
        dr = n-1;
        while(st < dr){
            if(v[i] + v[st] + v[dr] == 0){
                string pereche = to_string(v[i]) + " " + to_string(v[st]) + " " + to_string(v[dr]);
                if(triplete.find(pereche) == triplete.end()){
                    triplete.insert(pereche);
                    cout << pereche << endl;
                }
                st++;
                dr--;
            }
            else if(v[i] + v[st] + v[dr] < 0)
                st++;
            else dr--;
        }
    }
    return 0;
}
