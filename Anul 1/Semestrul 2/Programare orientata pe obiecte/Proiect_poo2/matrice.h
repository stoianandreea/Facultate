#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <iostream>
#include "complex.h"
using namespace std;
class matrice {
	Complex **mat;
public:
	matrice(Complex **mat);
	virtual ~matrice();
	matrice(const matrice &obj);
};
matrice::matrice(Complex **mat) {
	this->mat=mat;
}
matrice::~matrice() {
	delete[] mat;
}
matrice::matrice(const matrice &obj){
	*this=obj;
}

#endif // MATRICE_H_INCLUDED
