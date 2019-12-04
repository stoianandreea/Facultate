/// Stoian Andreea
/// Grupa 141
/// Compilator: code blocks
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class bilete{
private:
    char s_plecare[100], s_sosire[100], data[15];
    int clasa;
    float ora, durata, km;
    char cod[2];                         /// R=regio, IR=inter-regio

public:
    bilete();
    //virtual ~bilete();
    bilete(const bilete&);
    friend istream& operator>>(istream&, bilete&);
    friend ostream& operator<<(ostream&, bilete);
    bilete operator=(const bilete&);
    char* getCod(){
        return cod;
    };
    float getKM(){
      return km;
    };
    int getClasa(){
        return clasa;
    };

};
bilete::bilete(){
    s_plecare[0]='\0';
    s_sosire[0]='\0';
    data[0]='\0';
    clasa=0;
    ora=0.0;
    durata=0.0;
    km=0.0;
    cod[0]='\0';
}
bilete::bilete(const bilete& b){
    this->ora=b.ora;
    this->durata=b.durata;
    this->clasa=b.clasa;
    this->km=b.km;
    unsigned int i;
    for(i=0;i<strlen(b.s_plecare);i++)
        this->s_plecare[i]=b.s_plecare[i];
    for(i=0;i<strlen(b.s_sosire);i++)
        this->s_sosire[i]=b.s_sosire[i];
    for(i=0;i<strlen(b.data);i++)
        this->data[i]=b.data[i];
    for(i=0;i<strlen(b.cod);i++)
        this->cod[i]=b.cod[i];
}
/*bilete::bilete operator=(const bilete&){
    this->ora=b.ora;
    this->durata=b.durata;
    this->clasa=b.clasa;
    this->km=b.km;
    unsigned int i;
    for(i=0;i<strlen(b.s_plecare);i++)
        this->s_plecare[i]=b.s_plecare[i];
    for(i=0;i<strlen(b.s_sosire);i++)
        this->s_sosire[i]=b.s_sosire[i];
    for(i=0;i<strlen(b.data);i++)
        this->data[i]=b.data[i];
    for(i=0;i<strlen(b.cod);i++)
        this->cod[i]=b.cod[i];
}
*/
istream& operator>>(istream &input, bilete &b){
    input>>b.s_plecare;
    input>>b.s_sosire;
    input>>b.data>>b.ora;
    input>>b.durata>>b.km;
    input>>b.clasa>>b.cod;
    return input;
}
ostream& operator<<(ostream &output, bilete b){
    output<<"Statie plecare: "<<b.s_plecare<<endl;
    output<<"Statie sosire: "<<b.s_sosire<<endl;
    output<<"Data: "<<b.data<<" si ora: "<<b.ora<<endl;
    output<<"Durata: "<<b.durata<<"     Distanta: "<<b.km<<endl;
    return output;
}

class Regio1:public bilete{
private:
    char seria[20];                     ///<cod><clasa>-<nr>
    char nr_ordine[100];
    float pret, taxa;
public:
    Regio1();
    //~Regio1();
    Regio1(const Regio1&);
    void setSerie();
    void setPret(){
        pret=0.39*(this->getKM());
    };
    void setTaxa(){
        taxa=0.2*(this->pret);
    };
    friend istream& operator>>(istream&, Regio1&);
    friend ostream& operator<<(ostream&, Regio1);

};
Regio1::Regio1(): bilete(){
    seria[0]='\0';
    nr_ordine[0]='\0';
    pret=0.0;
    taxa=0.0;
}
Regio1::Regio1(const Regio1& b): bilete(b){
    this->pret=b.pret;
    this->taxa=b.taxa;
    unsigned int i;
    for(i=0;i<strlen(b.seria);i++)
        this->seria[i]=b.seria[i];
    for(i=0;i<strlen(b.nr_ordine);i++)
        this->nr_ordine[i]=b.nr_ordine[i];
}
void Regio1::setSerie(){
    unsigned int i;
    for(i=0;i<strlen(this->getCod());i++)
        this->seria[i]=this->getCod()[i];
    seria[i]=(char)(this->getClasa()); i++;
    seria[i]='-'; i++;
    for(unsigned int j=0;j<strlen(this->nr_ordine);j++){
        seria[i]=this->nr_ordine[j];
        i++;
    }

}
istream& operator>>(istream &input, Regio1 &b){
    input>>b.nr_ordine;
    return input;
}
ostream& operator<<(ostream &output, Regio1 b){
    output<<"Seria: ";
    b.setSerie();
    output<<b.seria<<endl;
    ///Calculeaza pret (getpret)+calculeaza taxa (gettaxa)= pret total
    output<<"Pret total: ";
    return output;
}
class Regio2: public bilete{
private:
    char seria[20];                     ///<cod><clasa>-<nr>
    char nr_ordine[100];
    int pret;
public:
    Regio2();
    //~Regio2();
    Regio2(const Regio2&);
    void setSerie();
    float getPret;
    friend istream& operator>>(istream&, Regio2&);
    friend ostream& operator<<(ostream&, Regio2);

};
Regio2::Regio2(): bilete(){
    seria[0]='\0';
    nr_ordine[0]='\0';
    pret=0.0;
}
Regio2::Regio2(const Regio2& b): bilete(b){
    this->pret=b.pret;
    unsigned int i;
    for(i=0;i<strlen(b.seria);i++)
        this->seria[i]=b.seria[i];
    for(i=0;i<strlen(b.nr_ordine);i++)
        this->nr_ordine[i]=b.nr_ordine[i];
}
void Regio2::setSerie(){
    unsigned int i;
    for(i=0;i<strlen(this->getCod());i++)
        this->seria[i]=this->getCod()[i];
    seria[i]=(char)(this->getClasa()); i++;
    seria[i]='-'; i++;
    for(unsigned int j=0;j<strlen(this->nr_ordine);j++){
        seria[i]=this->nr_ordine[j];
        i++;
    }
}
istream& operator>>(istream &input, Regio2 &b){
    input>>b.nr_ordine;
    return input;
}
ostream& operator<<(ostream &output, Regio2 b){
    output<<"Seria: ";
    b.setSerie();
    output<<b.seria<<endl;
    output<<"Pret: "<<b.pret<<endl;
    return output;
}
class InterRegio1:public bilete{
private:
    char seria[20];
    char nr_ordine[100];
    int pret, taxa;
public:

};
class InterRegio2: public bilete{
private:
    char seria[20];
    char nr_ordine[100];
    int pret;
public:

};

int main()
{
    bilete T[100];
    //vector <bilete> T[100];
    bilete x;
    int n;
    ifstream f("date.in");
    f>>n;                         ///nr calatori
    for(int i=0;i<n;i++){
        f>>T[i];
       // T[i].push_back(x);
    }
    for(int i=0; i<n;i++){
        cout<<T[i]<<endl;
        //T[i].pop_back();
    }
    return 0;
}
