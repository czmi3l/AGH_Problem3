#include "Sklep.h"


bool WczytajZPliku(Wektor<Firma>&);

int main(){

	Wektor<Firma> wektor;
	string buforNaFirme;
	string buforNaZabawke;
	double buforNaCene;

	if (WczytajZPliku(wektor))
		cout << "Wczytano dane z pliku!" << endl;
	cout << "[Sklep] [Zabawka] [Cena] [q - aby zakonczyc]" << endl;
	while (buforNaFirme != "q"){
		cin >> buforNaFirme;
		if (buforNaFirme == "q")
			break;
		cin >> buforNaZabawke;
		cin >> buforNaCene;

		for (int i = 0; i < wektor.Size(); i++)
		{
			if (wektor[i].nazwaFirmy == buforNaFirme){
				wektor[i].DodajZabawke(buforNaZabawke, buforNaCene);
			}
		}

	}

	/*for (int i = 0; i < wektor.Size(); i++)
	{
		wektor[i].WypiszWszystkie();
	}*/

	//Wersja Iteratorowa:
	Wektor<Firma>::Iterator iter = wektor.begin();
	while (iter != wektor.end())
	{
		(iter++).WypiszWszystkie();
	}

	cin.get();
	cin.get();
	return 0;
}

bool WczytajZPliku(Wektor<Firma>& wektor){
	ifstream wejscie;
	string path = "wejscie.txt";
	wejscie.open(path.c_str());
	if (!wejscie)
		return false;
	string buforNazwaFirmy;
	string ulicaSklepu;
	int numerSklepu;
	int i;
	while (!wejscie.eof())
	{
		wejscie >> buforNazwaFirmy;
		wejscie >> ulicaSklepu;
		wejscie >> numerSklepu;
		//********************** KONWERSJA int DO string
		ostringstream ss;
		ss << numerSklepu;
		string numerSklepuString = ss.str();
		//**********************
		ulicaSklepu = ulicaSklepu + " " + numerSklepuString;
		for (i = 0; i < wektor.Size(); i++)
		{
			if (wektor[i].nazwaFirmy == buforNazwaFirmy){
				wektor[i].DodajSklep(ulicaSklepu);
				break;
			}
		}
		if (wektor.Size() == 0 || i == wektor.Size()){
			Firma firma(buforNazwaFirmy, ulicaSklepu);
			wektor.PushBack(firma);
		}
	}

	wejscie.close();
	return true;
}