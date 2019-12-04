#include <iostream>
#include <fstream>
using namespace std;
class nr_complex {
	int a, b;               //a=partea reala    b=partea imaginara
public:
	nr_complex();
	friend istream& operator>>(istream&, nr_complex&);
	friend ostream& operator<<(ostream&, nr_complex);
	friend nr_complex operator+(const nr_complex&, const nr_complex&);
	friend nr_complex operator-(const nr_complex&, const nr_complex&);
	friend nr_complex operator*(const nr_complex&, const nr_complex&);
	friend nr_complex operator*(const nr_complex&, int);
	nr_complex& operator=(const int&);
	friend int operator!=(nr_complex&, const int&);
	friend class matrice;
};
nr_complex::nr_complex(){
	a=0;
	b=0;
}
//supraincarcarea operatorului >> pentru numere complexe
istream& operator>>(istream& input, nr_complex& z) {
	input>>z.a;   //partea reala
	input>>z.b;   //partea imaginara
	return input;
}
//supraincarcarea operatorului << pentru numere complexe
ostream& operator<<(ostream& output, nr_complex z) {
	if (z.b>=0)
		output<<z.a<<"+"<<z.b<<"i"<<' ';
	else
		output<<z.a<<z.b<<"i"<<' ';
	return output;
}
//supraincarcarea operatorului =
nr_complex& nr_complex::operator=(const int& t) {
	this->a=t;
	this->b=t;
	return *this;
}
//supraincarcarea operatorului !=
int operator!=(nr_complex& z, const int& t) {
	if ((z.a!=t) && (z.b!=t))
		return 1;
	else
		return 0;
}
//supraincarcarea operatorului + pentru numere complexe
nr_complex operator+(const nr_complex& z1, const nr_complex& z2) {
	nr_complex z3;
	z3.a=z1.a+z2.a;
	z3.b=z1.b+z2.b;
	return z3;
}
//supraincarcarea operatorului - pentru numere complexe
nr_complex operator-(const nr_complex& z1, const nr_complex& z2) {
	nr_complex z3;
	z3.a=z1.a-z2.a;
	z3.b=z1.b-z2.b;
	return z3;
}
//supraincarcarea operatorului * pentru numere complexe
nr_complex operator*(const nr_complex& z1, const nr_complex& z2) {
	nr_complex z3;
	z3.a=(z1.a*z2.a)-(z1.b*z2.b);
	z3.b=(z1.a*z2.b)+(z1.b*z2.a);
	return z3;
}
//supraincarcarea operatorului * pentru numere complexe & int
nr_complex operator*(const nr_complex& z1, int t) {
	nr_complex z2;
	z2.a=z1.a*t;
	z2.b=z1.b*t;
	return z2;
}
class matrice {
	int n, m;       // n=nr linii; m=nr coloane
	nr_complex *mat;
public:
	matrice();
	matrice(int, int);
	~matrice();
	matrice(const matrice &obj);
	matrice& operator=(const matrice&);

	nr_complex* operator ()(int, int);
	friend istream& operator>>(istream&, matrice&);
	friend ostream& operator<<(ostream&, matrice);
	friend matrice operator+(matrice&, matrice&);
	friend matrice operator*(matrice&, matrice&);
	friend class nr_complex;
	nr_complex determinant0(matrice a);
	matrice& submatrice(int, int, int, matrice&, matrice&);
	nr_complex determ(matrice&, int);
	friend matrice transpusa(matrice&);
};
matrice::matrice() {
	n=0;
	m=0;
	mat=NULL;
}
matrice::matrice(int i, int j) {
	n=i;
	m=j;
	mat=new nr_complex[n*m];
}
matrice::~matrice() {
	delete[] mat;
}
matrice& matrice::operator=(const matrice &obj) {
	m=obj.m;
	n=obj.n;
	mat=new nr_complex[obj.m*obj.n];
	for(int i=0;i<obj.m*obj.n;i++)
		mat[i]=obj.mat[i];
	return *this;
}
matrice::matrice(const matrice &obj){
	*this=obj;
}
// supraincarcarea operatorului ()
nr_complex* matrice::operator()(int i, int j) {
	return mat+(i*m+j);                // elementul de pe linia i si coloana j
}
//supraincarcarea operatorului >> pentru matrici
istream& operator>>(istream& input, matrice& a) {
	int i, j;
	a.mat=new nr_complex[a.m*a.n];           /// trebuie alocata memorie pentru fiecare matrice
	for(i=0;i<a.n;i++)
    for(j=0;j<a.m;j++)
        input>>*a(i,j);
	return input;
}
//supraincarcarea operatorului << pentru matrici
ostream& operator<<(ostream& output, matrice a) {
	int i, j;
	printf("%d %d \n", a.m, a.n);             // dimensiunea fiecarei matrici
	for(i=0;i<a.n;i++) {
		for(j=0;j<a.m;j++)
			output<<*a(i,j)<<' ';
		output<<endl;
	}
	return output;
}
//supraincarcarea operatorului + pentru matrici
matrice operator+(matrice& a1, matrice& a2) {
	matrice a3;
	a3.n=a1.n;
	a3.m=a1.m;
	a3.mat=new nr_complex[a3.m*a3.n];             /// trebuie alocata memorie
	int i, j;
	if(a1.n!=a2.n || a1.m!=a2.m) {
		cout<<"Nu au aceeasi dimensiune"<<endl;
		return a3;
	}
	else
		for(i=0;i<a1.n;i++)
        for(j=0;j<a1.m;j++)
            *a3(i,j)=(*a1(i,j))+(*a2(i,j));
	return a3;
}
//supraincarcarea operatorului * pentru matrici
matrice operator*(matrice& a1, matrice& a2) {
	matrice a3(a1.n, a2.m), b(a1.n, a2.m);
	int i, j, k;
	a3.n=a1.n;
	a3.m=a2.m;
	b.n=a1.n;
	b.m=a2.m;
	a3.mat=new nr_complex[a3.m*a3.n];             /// trebuie alocata memorie
	b.mat=new nr_complex[b.m*b.n];
	for(i=0;i<a1.n;i++)
    for(j=0;j<a2.m;j++)
        *(a3(i,j))=0;
	if(a1.m!=a2.n) {
		cout<<"Nu se pot inmulti\n";
		return a3;
	}
	else {
		for(i=0;i<a1.n;i++)
        for(j=0;j<a2.m;j++)
        for(k=0;k<a1.m;k++) {
            *b(i,j)=(*a1(i,k))*(*a2(k,j));
            *a3(i,j)=(*a3(i,j))+(*b(i,j));
        }
	}
	return a3;
}
matrice& matrice::submatrice(int n, int lin, int col, matrice& a, matrice& b) {
	int i, j, c=-1, x=0;
	for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(i!=lin && j!=col) {
            c++;
            if(c==(n-1)) {
                c=0; x++;
            }
            *b(x,c)=*a(i,j);
        }
	return b;
}
//calculam recursiv determinantul (cu formula)
nr_complex matrice::determ(matrice& a, int n) {
	nr_complex det, x, y, t;
	int j, sign=1;
	det=0; t=0;
	matrice b(n,n);
	if(n==1)
        return *a(0,0);
	else if(n==2) {
		x=(*a(0,0))*(*a(1,1));
		y=(*a(0,1))*(*a(1,0));
		det=x-y;
		return det;
	}
	for(j=0;j<n;j++) {
		submatrice(n,0,j,a,b);
		t=(*a(0,j))*sign;
		sign=-sign;
		t=t*determ(b,n-1);
		det=det+t;
	}
	return det;
}
//verificam cazurile det=0//triunghi
nr_complex matrice::determinant0(matrice a) {
	nr_complex det;
	det=1;
	int i, j, s, t, x, y;
	//verific daca exista o linie/coloana de 0-uri; daca exista, det=0
	for(i=0;i<a.n;i++) {
		s=0; t=0;
		for(j=0;j<a.n;j++) {
			if(*a(i,j)!=0)
				s++;
			if(*a(j,i)!=0)
				t++;
		}
		if(s==0 || t==0) {
			det=0;
			break;
		}
	}
	s=t=x=y=0;
	for(i=0;i<a.n;i++)
    for(j=0;j<a.n;j++) {
        if(i<j && (*a(i,j)!=0))
            s++;
        if(i>j && (*a(i,j)!=0))
            t++;
        if((i+j)<a.n-1 && (*a(i,j)!=0))
            x++;
        if((i+j)>a.n-1 && (*a(i,j)!=0))
            y++;
    }
	if(s==0||t==0){
        for(i=0;i<a.n;i++)
             det=det+(*a(i,i));
    }
    if(x==0||y==0)
        for(i=0;i<a.n;i++)
        for(j=0;j<a.n;j++)
          if(i+j==n-1)
             det=det+(*a(i,j));
	return det;
}
matrice transpusa(matrice& a) {
	matrice t;
	t.n=t.m=a.n;
	t.mat=new nr_complex[t.n*t.m];
	int i, j;
	for(i=0;i<a.n;i++)
    for(j=0;j<a.n;j++)
        *t(i,j)=*a(j,i);
	return t;
}
int main()
{
	ifstream f("numere.txt");
	int n1, m1, n2, m2;
	f>>n1>>m1>>n2>>m2;
	matrice a1(n1,m1), a2(n2,m2), a3, a4;
	f>>a1>>a2;
	cout<<a1<<endl<<a2<<endl;
	a3=a1+a2;
	cout<<"Suma a 2 matrici:\n"<<a3<<endl;
	a4=a1*a2;
	cout<<"Produsul a 2 matrici:\n"<<a4<<endl;
	nr_complex det;
	det=a1.determinant0(a1);
	if(det!=0)
		det=a1.determ(a1, n1);
	cout<<"Determinantul matricei este: "<<det<<endl;
	a3=transpusa(a1);
	cout<<a3<<endl;

	return 0;
}
