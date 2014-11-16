#ifndef SKLEP_H_
#define SKLEP_H_

#define ILOSC_ZABAWEK_NA_SKLEP 20
#define ILOSC_SKLEPOW_NA_FIRME 20
#include <iostream>
#include "WektorHeader.h"
#include <string>

using namespace std;

class Zabawka{
private:
	string nazwa;
	double cena;
public:
	Zabawka(){}
	Zabawka(string n, double c);
	Zabawka(const Zabawka& zabawka);
	void WypiszZabawke();
	Zabawka& operator=(const Zabawka& zabawka);
	friend ostream& operator<<(ostream& os, const Zabawka& zabawka){
		return os << zabawka.nazwa << "  " << zabawka.cena;
	}
};

class Sklep{
private:
	Wektor < Zabawka > zabawki;

public:
	Sklep(){}
	Sklep(string uSklepu);
	Sklep(const Sklep& sklep);
	string ulica;
	void WypiszWszystkie();
	void DodajZabawke(Zabawka zabawka);
	Sklep& operator=(const Sklep& sklep);
};

class Firma{
public:
	Wektor<Sklep> sklepy;
	Firma(){}
	Firma(string nFirmy, string uSklepu);
	Firma(const Firma& firma);
	void WypiszWszystkie();
	void DodajSklep(string ulica);
	void DodajZabawke(string nazwa, double cena);
	string nazwaFirmy;
	Firma& operator=(const Firma& sklep);
	
};


#endif