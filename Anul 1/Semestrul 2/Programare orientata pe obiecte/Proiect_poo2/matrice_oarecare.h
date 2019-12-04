#ifndef MATRICE_OARECARE_H_INCLUDED
#define MATRICE_OARECARE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include "complex.h"
#include "matrice.h"
using namespace std;
class m_oarecare: public matrice{
    int lin, col;
    Complex **mat;
public:
    m_oarecare(int, int, Complex **mat);
    m_oarecare(int, int);
    ~m_oarecare();
    m_oarecare& operator=(const m_oarecare&);
	Complex& operator ()(int, int);
	friend istream& operator>>(istream&, m_oarecare&);
	friend ostream& operator<<(ostream&, m_oarecare);
};
m_oarecare::m_oarecare(int lin, int col, Complex **mat): matrice(mat) {
	lin=0;
	col=0;
}
m_oarecare::m_oarecare(int i, int j): matrice(mat) {
	lin=i;
	col=j;
	mat=new Complex*[lin];
	for(int i=0;i<lin;i++)
        mat[i]=new Complex[col];
}
m_oarecare::~m_oarecare() {
	delete[] mat;
}
m_oarecare& m_oarecare::operator=(const m_oarecare &obj) {
	col=obj.col;
	lin=obj.lin;
	*mat=new Complex[obj.col*obj.lin];
	for(int i=0;i<obj.col*obj.lin;i++)
		mat[i]=obj.mat[i];
	return *this;
}
// supraincarcarea operatorului ()
Complex& m_oarecare::operator()(int i, int j) {
	return *(*mat+(i*col+j));                // elementul de pe linia i si coloana j
}
//supraincarcarea operatorului >> pentru matrici
istream& operator>>(istream& input, m_oarecare& a) {
	int i, j;
	*a.mat=new Complex[a.col*a.lin];
	for(i=0;i<a.lin;i++)
    for(j=0;j<a.col;j++)
        input>>a(i,j);
	return input;
}
//supraincarcarea operatorului << pentru matrici
ostream& operator<<(ostream& output, m_oarecare a) {
	int i, j;
	printf("%d %d \n", a.lin, a.col);             // dimensiunea fiecarei matrici
	for(i=0;i<a.lin;i++) {
		for(j=0;j<a.col;j++)
			output<<a(i,j)<<' ';
		output<<endl;
	}
	return output;
}

#endif // MATRICE_OARECARE_H_INCLUDED
