#include <iostream>
#include <cstring>
using namespace std;

class Candidat{
private:
    char nume[100];
    int tip_doc;                       /// 1=CI; 2=pasaport
    char serie_CI[10];                 /// serie si nr CI
    char nr_pasaport[10];
    float medie_bac;
    int nr_fac;                      /// 1=prima facultate; 2=a doua facultate
public:
    Candidat();
    //virtual ~Candidat();
    Candidat(const Candidat&);
    Candidat& operator=(const Candidat&);
    friend istream& operator>>(istream&, Candidat&);
    friend ostream &operator<<(ostream&, Candidat);
    int getFacultate(){
        return nr_fac;
    };
    int getBAC(){
        return medie_bac;
    };
};
Candidat::Candidat(){
    nume[0]='\0';
    tip_doc=0;
    serie_CI[0]='\0';
    nr_pasaport[0]='\0';
    medie_bac=0.0;
    nr_fac=0;
}
Candidat::Candidat(const Candidat &x){
    this->tip_doc=x.tip_doc;
    this->medie_bac=x.medie_bac;
    this->nr_fac=x.nr_fac;
    //this->nume=x.nume;
    //this->serie_CI=x.serie_CI;
    //this->nr_pasaport=x.nr_pasaport;
    unsigned int i;
    for(i=0;i<strlen(x.nume);i++)
        this->nume[i]=x.nume[i];
    for(i=0;i<strlen(x.serie_CI);i++)
        this->serie_CI[i]=x.serie_CI[i];
    for(i=0;i<strlen(x.nr_pasaport);i++)
        this->nr_pasaport[i]=x.nr_pasaport[i];
}
Candidat& Candidat::operator=(const Candidat &x){
    tip_doc=x.tip_doc;
    medie_bac=x.medie_bac;
    nr_fac=x.nr_fac;
    unsigned int i;
    for(i=0;i<strlen(x.nume);i++)
        nume[i]=x.nume[i];
    for(i=0;i<strlen(x.serie_CI);i++)
        serie_CI[i]=x.serie_CI[i];
    for(i=0;i<strlen(x.nr_pasaport);i++)
        nr_pasaport[i]=x.nr_pasaport[i];
    return *this;
}
istream& operator>>(istream& input, Candidat& x){
    input>>x.nume;
    input>>x.tip_doc;
    if(x.tip_doc==1)
        input>>x.serie_CI;
    else if(x.tip_doc==2)
        input>>x.nr_pasaport;
    input>>x.medie_bac;
    input>>x.nr_fac;
    return input;
}
ostream& operator<<(ostream &output, Candidat x){
    output<<"Numele candidatului: "<<x.nume<<endl;
    if(x.tip_doc==1)
        output<<"CI seria si nr: "<<x.serie_CI<<endl;
    else if(x.tip_doc==2)
        output<<"NR pasaport: "<<x.nr_pasaport<<endl;
    output<<"Medie bac: "<<x.medie_bac<<endl;
    return output;
}
/// avem clasa PrimaFacultate (mostenim Candidat)
class PrimaFacultate: public Candidat{
private:
    int tip_exam;                       /// 1=IF; 2=ID
    int cod;
    float nota_mate, nota_scris, nota_oral;
public:
    PrimaFacultate();
    //~PrimaFacultate();
    PrimaFacultate(const PrimaFacultate&);
    int getMedie();
    friend istream& operator>>(istream&, PrimaFacultate&);
    friend ostream& operator<<(ostream&, PrimaFacultate);
};
PrimaFacultate::PrimaFacultate(): Candidat(){
    tip_exam=0;
    cod=0;
    nota_mate=0.0;
    nota_scris=0.0;
    nota_oral=0.0;
}
PrimaFacultate::PrimaFacultate(const PrimaFacultate &x): Candidat(x){
    this->tip_exam=x.tip_exam;
    this->cod=x.cod;
    this->nota_mate=x.nota_mate;
    this->nota_scris=x.nota_scris;
    this->nota_oral=x.nota_oral;
}
istream& operator>>(istream &input, PrimaFacultate &x){
    input>>x.tip_exam;
    input>>x.cod;
    if(x.tip_exam==1)
        input>>x.nota_scris;
    else if(x.tip_exam==2)
        input>>x.nota_oral>>x.nota_mate;
    return input;
}
ostream& operator<<(ostream &output, PrimaFacultate x){
    output<<"Cod candidat: ";
    if(x.tip_exam==2)
        output<<"ID_";
    output<<x.cod<<endl;
    output<<"Medie admitere: "<<x.getMedie()<<endl;
    return output;
}
int PrimaFacultate::getMedie(){
    float m=0;
    if(this->tip_exam==1)
        m=0.8*(this->nota_scris)+0.2*(this->getBAC());
    if(this->tip_exam==2)
        m=0.6*(this->nota_oral)+0.4*(this->nota_mate);
    return m;
}
/// avem clasa Facultatea2 (mostenim Candidat)
class Facultatea2: public Candidat{
private:
    int tip_exam;
    char fac_abs[100];          /// numele facultatii absolvite
    float medie_abs;         /// media de absolvire
    int cod;
public:
    Facultatea2();
    //~Facultatea2();
    Facultatea2(const Facultatea2&);
};
Facultatea2::Facultatea2():Candidat(){
    tip_exam=0;
    cod=0;
    fac_abs[0]='\0';
    medie_abs=0.0;
}
Facultatea2::Facultatea2(const Facultatea2 &x): Candidat(x){
    this->tip_exam=x.tip_exam;
    this->cod=x.cod;
    this->medie_abs=x.medie_abs;
    for(unsigned int i=0;i<strlen(fac_abs);i++)
        this->fac_abs[i]=x.fac_abs[i];
}

int main()
{
    return 0;
}
