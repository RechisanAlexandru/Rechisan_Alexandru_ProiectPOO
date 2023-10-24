#include <iostream>
//Domeniu Oras

using namespace std;
class Cartier {
public:
	const int nrCartier;
	string nume;
	static string oras;
	int locuitori;
	int nrBlocuri;
	string* blocuri;
	static int straziAsfaltate;

	Cartier() : nrCartier(1) {
		this->nume = "Nu are nume";
		this->locuitori = 0;
		this->nrBlocuri = 0;
		this->blocuri = NULL;
	}
	Cartier(int nrCartier, string nume, int nrBlocuri, string* blocuri,
		int locuitori) :nrCartier(nrCartier) {
		this->nume = nume;
		this->locuitori = locuitori;
		this->nrBlocuri = nrBlocuri;
		this->blocuri = new string[nrBlocuri];
		for (int i = 0; i < nrBlocuri; i++)
			this->blocuri[i] = blocuri[i];
	}
	Cartier(int nrCartier, string nume, int locuitori) :nrCartier(nrCartier) {
		this->nume = nume;
		this->locuitori = locuitori;
		this->nrBlocuri = nrBlocuri;
		this->blocuri = NULL;
	}
	~Cartier() {
		if (this->blocuri != NULL)
			delete[]this->blocuri;
	}
	void afisare() {
		cout << "Cartierul " << this->nume << " se afla in orasul " << this->oras << " are " << this->locuitori
			<< " locuitori" << " ce locuiesc in " << this->nrBlocuri << " blocuri ce sunt denumite astfel:\n";
		for (int i = 0; i < this->nrBlocuri; i++) {
			cout << this->blocuri[i];
			cout << "\n";
		}
		cout << "In ultimele 2 luni au fost asfaltate " << this->straziAsfaltate << " strazi noi \n";
	}
	
	float populatieMedie() {
		return (float)this->locuitori / this->nrBlocuri;
	}

	static void setOras(string oras) {
		Cartier::oras = oras;
	}
	static void adaugareStrazi(int straziNoi) {
		Cartier::straziAsfaltate += straziNoi;
	}
};
string Cartier::oras = "Mangalia";
int Cartier::straziAsfaltate = 0;

class Parc {
public:
	string nume;
	int vizitatori;
	static string oras;
	const int nrParc;
	int nrTerenJoaca;
	string* terenJoaca;

	Parc() :nrParc(1) {
		this->nume = "Nu are nume ";
		this->vizitatori = 0;
		this->nrTerenJoaca = 0;
		this->terenJoaca = NULL;
	}
	Parc(string nume, int vizitatori, int nrParc,int nrTerenJoaca,string* terenJoaca):
		nrParc(nrParc)  {
		this->nume = nume;
		this->vizitatori = vizitatori;
		this->nrTerenJoaca = nrTerenJoaca;
		this->terenJoaca = new string[nrTerenJoaca];
		for (int i = 0; i < this->nrTerenJoaca; i++)
			this->terenJoaca[i] = terenJoaca[i];
	}
	Parc(string nume, int vizitatori, int nrParc, int nrTerenJoaca) :
		nrParc(nrParc) {
		this->nume = nume;
		this->vizitatori = vizitatori;
		this->nrTerenJoaca = nrTerenJoaca;
		this->terenJoaca = NULL;
	}
	void afisare() {
		cout << "Parcul " << this->nume << "din orasul " << this->oras << " are zilnic " << this->vizitatori << " de vizitatori"
			<< ", are un numar de " << this->nrTerenJoaca << " tipuri de terenuri de joaca, acestea fiind de: " << endl;
		if (nrTerenJoaca != 0 && terenJoaca != NULL) {
			for (int i = 0; i < this->nrTerenJoaca; i++) {
				cout << terenJoaca[i];
				cout << endl;
			}
		}
		else
			cout << "Tipurile terenurilor nu au fost introduse" << endl << endl;
	}
	~Parc() {
		if (this->terenJoaca != NULL)
			delete[]this->terenJoaca;
	}
	static void setOras(string oras) {
		Parc::oras = oras;
	}
};
string Parc::oras = "Mangalia";

class Scoala {
public:
	string nume;
	int elevi;
	const int nrScoala;
	int nrSaliSpeciale;
	string* saliSpeciale;
	static string oras;

	Scoala() :nrScoala(1) {
		this->nume = "Nu se stie numele scolii";
		this->elevi = 0;
		this->nrSaliSpeciale = 0;
		this->saliSpeciale = NULL;
	}
	Scoala(string nume, int elevi, int nrScoala, int nrSaliSpeciale, string* saliSpeciale)
		: nrScoala(nrScoala) {
		this->nume = nume;
		this->elevi = 400;
		this->nrSaliSpeciale = nrSaliSpeciale;
		this->saliSpeciale = new string[nrSaliSpeciale];
		for (int i = 0; i < nrSaliSpeciale; i++)
			this->saliSpeciale[i] = saliSpeciale[i];
	}
	Scoala(string nume, int elevi, int nrScoala) :nrScoala(nrScoala) {
		this->nume = nume;
		this->elevi = elevi;
		this->nrSaliSpeciale = 0;
		this->saliSpeciale = NULL;
	}
	~Scoala() {
		if (this->saliSpeciale != NULL)
			delete[]this->saliSpeciale;
	}
	void afisare() {
		cout << "Scoala " << this->nume << " din " << this->oras << " cu numarul " << nrScoala << " are un numar de "
			<< elevi << " elevi, si are " << nrSaliSpeciale << " sali speciale, aceste fiind de " << endl;
		if (this->nrSaliSpeciale != 0 && this->saliSpeciale != NULL) {
			for (int i = 0; i < this->nrSaliSpeciale; i++)
				cout << this->saliSpeciale[i] << endl;
		}
		else {
			cout << "Nu are sali speciale" << endl;
		}
	}
	static void setOras(string oras) {
		Scoala::oras = oras;
	}
};
string Scoala::oras = "Mangalia";
int main()
{
	Cartier cartier1;
	cartier1.afisare();

	string* numeBlocuri = new string[6];
	numeBlocuri[0] = "A1";
	numeBlocuri[1] = "A2";
	numeBlocuri[2] = "B1";
	numeBlocuri[3] = "B2";
	numeBlocuri[4] = "C1";
	numeBlocuri[5] = "C2";
	Cartier cartier2(2, "Colonisti", 6, numeBlocuri, 500);
	cartier2.afisare();

	cout << "Populatia medie pe bloc este de " << cartier2.populatieMedie() << "\n";

	Cartier cartier3(3, "Militari", 100000);
	Cartier::setOras("Bucuresti");
	Cartier::adaugareStrazi(5);
	cartier3.afisare();
	cout << endl;

	cout << endl;
	Parc parc1;
	parc1.afisare();
	string* terenJoaca = new string[2];
	terenJoaca[0] = "Fotbal";
	terenJoaca[1] = "Baschet";

	Parc parc2("Portului ", 5000, 2,2,terenJoaca);
	parc2.afisare();
	cout << endl;

	Parc parc3("Magicieni ", 3000, 3, 4);
	Parc::setOras("Bucuresti");
	parc3.afisare();
	cout << endl;

	cout << endl;
	Scoala scoala1;
	scoala1.afisare();
	string* saliSpeciale = new string[2];
	saliSpeciale[0] = "Chimie";
	saliSpeciale[1] = "Biologie";
	
	Scoala scoala2("Sf. Andrei", 350, 2, 2, saliSpeciale);
	scoala2.afisare();

	Scoala scoala3("Gala Galaction", 400, 3);
	Scoala::setOras("Bucuresti");
	scoala3.afisare();
}