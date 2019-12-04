#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
using namespace std;
class Complex {
	float re, im;               //re=partea reala    im=partea imaginara
public:
	Complex();
	Complex& operator=(const Complex&);
	Complex& operator=(const float&);
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, Complex);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, float);
	friend Complex operator+(const Complex&, const Complex&);
	friend int operator!=(Complex&, const float&);
};
Complex::Complex(){
	re=0.0;
	im=0.0;
}
//supraincarcarea operatorului =
Complex& Complex::operator=(const Complex& t) {
	this->re=t.re;
	this->im=t.im;
	return *this;
}
//supraincarcarea operatorului = (cu float)
Complex& Complex::operator=(const float& t) {
	this->re=t;
	this->im=t;
	return *this;
}
//supraincarcarea operatorului >> pentru numere complexe
istream& operator>>(istream& input, Complex& z) {
	input>>z.re;
	input>>z.im;
	return input;
}
//supraincarcarea operatorului << pentru numere complexe
ostream& operator<<(ostream& output, Complex z) {
	if (z.im>=0.0)
		output<<z.re<<"+"<<z.im<<"i"<<' ';
	else
		output<<z.re<<z.im<<"i"<<' ';
	return output;
}
//supraincarcarea operatorului * pentru numere complexe
Complex operator*(const Complex& z1, const Complex& z2) {
	Complex z3;
	z3.re=(z1.re*z2.re)-(z1.im*z2.im);
	z3.im=(z1.re*z2.im)+(z1.im*z2.re);
	return z3;
}
//supraincarcarea operatorului - pentru numere complexe
Complex operator-(const Complex& z1, const Complex& z2) {
	Complex z3;
	z3.re=z1.re-z2.re;
	z3.im=z1.im-z2.im;
	return z3;
}
//supraincarcarea operatorului * pentru numere complexe & float
Complex operator*(const Complex& z1, float t) {
	Complex z2;
	z2.re=z1.re*t;
	z2.im=z1.im*t;
	return z2;
}
//supraincarcarea operatorului + pentru numere complexe
Complex operator+(const Complex& z1, const Complex& z2) {
    Complex z3;
	z3.re=z1.re+z2.re;
	z3.im=z1.im+z2.im;
	return z3;
}
//supraincarcarea operatorului !=
int operator!=(Complex& z, const float& t) {
	if ((z.re!=t) && (z.im!=t))
		return 1;
	else
		return 0;
}

#endif // COMPLEX_H_INCLUDED
