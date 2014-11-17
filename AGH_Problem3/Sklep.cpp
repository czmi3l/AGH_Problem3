#include "Sklep.h"

void Zabawka::WypiszZabawke(){
	cout << nazwa << "  " << cena << endl;
}

Zabawka::Zabawka(string n, double c){
	nazwa = n;
	cena = c;
}

Zabawka::Zabawka(const Zabawka& zabawka){
	nazwa = zabawka.nazwa;
	cena = zabawka.cena;
}

Zabawka& Zabawka::operator=(const Zabawka& zabawka){
	nazwa = zabawka.nazwa;
	cena = zabawka.cena;
	return *this;
}

ostream& operator<<(ostream& os, const Zabawka& zabawka){
	return os << zabawka.nazwa << "  " << zabawka.cena;
}

Sklep::Sklep(string uSklepu){
	ulica = uSklepu;
}

Firma::Firma(const Firma& firma){
	sklepy.Erase();
	nazwaFirmy = firma.nazwaFirmy;
	for (int i = 0; i < firma.sklepy.Size(); i++)
	{
		sklepy.PushBack(firma.sklepy[i]);
	}
}

void Firma::DodajSklep(string ulica){
	Sklep sklep(ulica);
	sklepy.PushBack(sklep);
}

void Sklep::WypiszWszystkie(){
	cout << "Ulica: "<< ulica << endl;
	cout << "Zabawki: " << endl;
	/*for (int i = 0; i < zabawki.Size(); i++)
	{
		zabawki[i].WypiszZabawke();
	}*/

	Wektor<Zabawka>::Iterator iter = zabawki.begin();
	while (iter != zabawki.end())
	{
		cout << iter++ << endl;
	}
}

void Sklep::DodajZabawke(Zabawka zabawka){

	zabawki.PushBack(zabawka);
}

Sklep::Sklep(const Sklep& sklep){
	zabawki.Erase();
	ulica = sklep.ulica;
	for (int i = 0; i < sklep.zabawki.Size(); i++)
	{
		zabawki.PushBack(sklep.zabawki[i]);
	}
}

Sklep& Sklep::operator=(const Sklep& sklep){
	ulica = sklep.ulica;
	zabawki.Erase();
	for (int i = 0; i < (sklep.zabawki.Size()); i++)
	{
		zabawki.PushBack(sklep.zabawki[i]);
	}
	return *this;
}

void Firma::WypiszWszystkie(){
	cout << "**********************\n";
	cout << "Nazwa firmy: "<< nazwaFirmy << endl;
	/*for (int i = 0; i < (sklepy.Size()); i++)
	{
		sklepy[i].WypiszWszystkie();
	}*/
	Wektor<Sklep>::Iterator iter = sklepy.begin();
	while (iter != sklepy.end())
	{
		(iter++).WypiszWszystkie();
	}

}

Firma::Firma(string nFirmy, string uSklepu){
	nazwaFirmy = nFirmy;
	Sklep sklep(uSklepu);
	sklepy.PushBack(sklep);
}

void Firma::DodajZabawke(string nazwa, double cena){
	for (int i = 0; i < sklepy.Size(); i++)
	{
		Zabawka zabawka(nazwa, cena);
		sklepy[i].DodajZabawke(zabawka);
	}
}

Firma& Firma::operator=(const Firma& firma){
	nazwaFirmy = firma.nazwaFirmy;
	sklepy.Erase();
	for (int i = 0; i < (firma.sklepy.Size()); i++)
	{
		sklepy.PushBack(firma.sklepy[i]);
	}
	firma.sklepy.Size();
	return *this;
}