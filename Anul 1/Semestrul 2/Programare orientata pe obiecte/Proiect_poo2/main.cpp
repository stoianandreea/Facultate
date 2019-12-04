#include <iostream>
#include <fstream>
#include "complex.h"
#include "matrice.h"
#include "matrice_oarecare.h"
#include "matrice_patratica.h"
using namespace std;

int main()
{
    ifstream f("numere.txt");
	int n, lin, col;
	f>>n;
	for(int k=0;k<n;k++){
        f>>lin>>col;
        Complex **v=new Complex*[lin];
        for(int i=0;i<lin;i++)
            v[i]=new Complex[col];
        if(lin==col){
            m_patratica a(lin);
            f>>a;
            cout<<a<<endl;
        }
        else{
            m_oarecare b(lin, col);
            f>>b;
            cout<<b<<endl;
        }
        delete v;
	}
    return 0;
}
