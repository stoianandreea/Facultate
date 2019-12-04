#ifndef MATRICE_PATRATICA_H_INCLUDED
#define MATRICE_PATRATICA_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include "complex.h"
#include "matrice.h"
using namespace std;
class m_patratica: public matrice{
    int dim;
    Complex **mat;
public:
    m_patratica(int, Complex **mat);
    m_patratica(int);
    ~m_patratica();
    m_patratica& operator=(const m_patratica&);
	Complex& operator ()(int, int);
	friend istream& operator>>(istream&, m_patratica&);
	friend ostream& operator<<(ostream&, m_patratica);
    Complex determinant0(m_patratica a);
	m_patratica& submatrice(int, int, int, m_patratica&, m_patratica&);
	Complex determ(m_patratica&, int);
	int diagonala(m_patratica);
};
m_patratica::m_patratica(int dim, Complex **mat):matrice(mat) {
	dim=0;
}
m_patratica::m_patratica(int i):matrice(mat) {
	dim=i;
	mat=new Complex*[dim];
	for(int i=0;i<dim;i++)
        mat[i]=new Complex[dim];
}
m_patratica::~m_patratica() {
	delete[] mat;   /// dezalocare cu for ^
}
m_patratica& m_patratica::operator=(const m_patratica &obj) {
	dim=obj.dim;
	*mat=new Complex[obj.dim*obj.dim];
	for(int i=0;i<obj.dim*obj.dim;i++)
		mat[i]=obj.mat[i];
	return *this;
}
// supraincarcarea operatorului ()
Complex& m_patratica::operator()(int i, int j) {
	return *(*mat+(i*dim+j));                // elementul de pe linia i si coloana j
}
//supraincarcarea operatorului >> pentru matrici
istream& operator>>(istream& input, m_patratica& a) {
	int i, j;
	*a.mat=new Complex[a.dim*a.dim];
	for(i=0;i<a.dim;i++)
    for(j=0;j<a.dim;j++)
        input>>a(i,j);
	return input;
}
m_patratica& m_patratica::submatrice(int n, int ln, int c, m_patratica& a, m_patratica& b) {
	int i, j, t=-1, x=0;
	for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(i!=ln && j!=c) {
            t++;
            if(t==(n-1)) {
                t=0; x++;
            }
            b(x,t)=a(i,j);
        }
	return b;
}
//calculam recursiv determinantul (cu formula)
Complex m_patratica::determ(m_patratica& a, int n) {
	Complex det, x, y, t;
	int j;
	float sign=1.0;
	det=0.0; t=0.0;
	m_patratica b(n);
	if(n==1)
        return a(0,0);
	else if(n==2) {
		x=a(0,0)*a(1,1);
		y=a(0,1)*a(1,0);
		det=x-y;
		return det;
	}
	for(j=0;j<n;j++) {
		submatrice(n,0,j,a,b);
		t=a(0,j)*sign;
		sign=-sign;
		t=t*determ(b,n-1);
		det=det+t;
	}
	return det;
}
//verificam cazurile det=0//triunghi
Complex m_patratica::determinant0(m_patratica a) {
	Complex det;
	det=1.0;
	int i, j, s, t, x, y;
	//verific daca exista o linie/coloana de 0-uri
	for(i=0;i<a.dim;i++) {
		s=0; t=0;
		for(j=0;j<a.dim;j++) {
			if(a(i,j)!=0)
				s++;
			if(a(j,i)!=0)
				t++;
		}
		if(s==0 || t==0) {
			det=0.0;
			break;
		}
	}
	s=t=x=y=0;
	for(i=0;i<a.dim;i++)
    for(j=0;j<a.dim;j++) {
        if(i<j && a(i,j)!=0)
            s++;
        if(i>j && a(i,j)!=0)
            t++;
        if((i+j)<a.dim-1 && a(i,j)!=0)
            x++;
        if((i+j)>a.dim-1 && a(i,j)!=0)
            y++;
    }
	if(s==0||t==0){
        for(i=0;i<a.dim;i++)
             det=det+a(i,i);
    }
    if(x==0||y==0)
        for(i=0;i<a.dim;i++)
        for(j=0;j<a.dim;j++)
          if(i+j==dim-1)
             det=det+a(i,j);
	return det;
}
int m_patratica::diagonala(m_patratica a){
    int ok=1;
    for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      if(i!=j && a(i,j)!=0.0){
        ok=0; break;
      }
    return ok;
}
//supraincarcarea operatorului << pentru matrici
ostream& operator<<(ostream& output, m_patratica a) {
	int i, j;
	printf("%d %d \n", a.dim, a.dim);             // dimensiunea fiecarei matrici
	for(i=0;i<a.dim;i++) {
		for(j=0;j<a.dim;j++)
			output<<a(i,j)<<' ';
		output<<endl;
	}
	Complex det;
	det=a.determinant0(a);
	if(det!=0.0)
		det=a.determ(a, a.dim);
	output<<"Determinantul matricei este: "<<det<<endl;
	int ok;
	ok=a.diagonala(a);
	if(ok==0)
        output<<"Matricea este diagonala"<<endl;
    else
        output<<"Matricea nu este diagonala"<<endl;
	return output;
}
#endif // MATRICE_PATRATICA_H_INCLUDED
