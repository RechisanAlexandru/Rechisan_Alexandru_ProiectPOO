#include <iostream>
//Domeniu Oras

using namespace std;
class Cartier {
private:
	const int nrCartier;
	string nume;
	static string oras;
	int locuitori;
	int nrBlocuri;
	string* blocuri;
	static int straziAsfaltate;
public:
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
	Cartier(const Cartier& cartier) :nrCartier(cartier.nrCartier) {
		this->nume = cartier.nume;
		this->locuitori = cartier.locuitori;
		this->nrBlocuri = cartier.nrBlocuri;
		this->blocuri = new string[this->nrBlocuri];
		for (int i = 0; i < nrBlocuri; i++)
			this->blocuri[i] = cartier.blocuri[i];
	}
	const Cartier& operator=(const Cartier& cartier) {
		if (this != &cartier)
		{
			if (this->blocuri != NULL)
				delete[]this->blocuri;
			this->nume = cartier.nume;
			this->locuitori = cartier.locuitori;
			this->blocuri = cartier.blocuri;
			this->blocuri = new string[this->nrBlocuri];
			for (int i = 0; i < nrBlocuri; i++)
				this->blocuri[i] = cartier.blocuri[i];
			return *this;
		}
	}
	Cartier operator+(const Cartier& cartier) {
		Cartier aux;
		aux.nume = this->nume;
		aux.locuitori = this->locuitori + cartier.locuitori;
		aux.nrBlocuri = this->nrBlocuri;
		if (aux.blocuri != NULL)
			delete[] aux.blocuri;
		aux.blocuri = new string[aux.nrBlocuri];
		for (int i = 0; i < this->nrBlocuri; i++)
			aux.blocuri[i] = this->blocuri[i];
		return aux;
	}
	
	~Cartier() {
		if (this->blocuri != NULL)
			delete[]this->blocuri;
	}

	void afisare() {
		cout << "Cartierul " << this->nume <<" cu numarul "<< this->nrCartier<< " se afla in orasul " << this->oras << " are " << this->locuitori
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

	static void adaugareStrazi(int straziNoi) {
		Cartier::straziAsfaltate += straziNoi;
	}

	int getnrCartier() {
		return this->nrCartier;
	}
	static void setOras(string oras) {
		Cartier::oras = oras;
	}
	static string getOras() {
		return Cartier::oras;
	}
	void setNume(string nume) {
		if (nume.length() > 3)
			this->nume = nume;
	}
	string getNume() {
		return this->nume;
	}

	void setLocuitori(int locuitori) {
		this->locuitori = locuitori;
	}
	int getLocuitori() {
		return this->locuitori;
	}
	void setNrBlocuri(int nrBlocuri, string* bloc) {
		if (nrBlocuri > 0) {
			this->nrBlocuri = nrBlocuri;
			if (this->blocuri != NULL)
				delete[]this->blocuri;
			blocuri = new string[this->nrBlocuri];
			for (int i = 0; i < nrBlocuri; i++)
				this->blocuri[i] = bloc[i];
		}	
	}
	string* getBlocuri() {
		return blocuri;
	}
	static void setStraziAsfaltate(int straziAsfaltate) {
		Cartier::straziAsfaltate = straziAsfaltate;
	}
	static int getStraziAsfaltate() {
		return straziAsfaltate;
	}
	friend int adunaLocuitori(Cartier, int);
	friend ostream& operator<<(ostream& out, const Cartier& cartier);
	friend istream& operator>>(istream& in, Cartier& cartier) {
		cout << "Nume: ";
		in >> cartier.nume;
		cout << "\nLocuitori: ";
		in >> cartier.locuitori;
		cout << "\nNumar blocuri: ";
		in >> cartier.nrBlocuri;
		if (cartier.blocuri != NULL) {
			delete[]cartier.blocuri;
		}
		cartier.blocuri = new string[cartier.nrBlocuri];
		for (int i = 0; i < cartier.nrBlocuri; i++) {
			cout << "Blocul " << i + 1 << ": ";
			in >> cartier.blocuri[i];
		}
		return in;
	}
};
string Cartier::oras = "Mangalia";
int Cartier::straziAsfaltate = 0;
ostream& operator<<(ostream& out, const Cartier& cartier)
{
	out << "Cartierul " << cartier.nume << " are numarul " << cartier.nrCartier << ", se afla in orasul " << cartier.oras << ", are " <<
		cartier.locuitori << " locuitori impartiti in " << cartier.nrBlocuri << " blocuri. Blocurile sunt: ";
	if (cartier.nrBlocuri == 0)
		out << "-";
	else
		for (int i = 0; i < cartier.nrBlocuri; i++)
			out << cartier.blocuri[i] << " ";
	out << endl;
	return out;
}

int adunaLocuitori(Cartier c, int numarAdunat) {
	c.locuitori += numarAdunat;
	return c.locuitori;
}

class Parc {
private:
	string nume;
	int vizitatori;
	static string oras;
	const int nrParc;
	int nrTerenJoaca;
	string* terenJoaca;
public:
	Parc() :nrParc(1) {
		this->nume = "Nu are nume ";
		this->vizitatori = 0;
		this->nrTerenJoaca = 0;
		this->terenJoaca = NULL;
	}
	Parc(string nume, int vizitatori, int nrParc, int nrTerenJoaca, string* terenJoaca) :
		nrParc(nrParc) {
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
		cout << "Parcul " << this->nume << " cu numarul "<<this->nrParc<< " din orasul " << this->oras << " are zilnic " << this->vizitatori << " de vizitatori"
			<< ", are un numar de " << this->nrTerenJoaca << " terenuri de joaca, acestea fiind de: " << endl;
		if (nrTerenJoaca != 0 && terenJoaca != NULL) {
			for (int i = 0; i < this->nrTerenJoaca; i++) {
				cout << terenJoaca[i];
				cout << endl;
			}
		}
		else
			cout << "Tipurile terenurilor nu au fost introduse" << endl << endl;
	}
	Parc(const Parc& parc) :nrParc(parc.nrParc) {
		this->nume = parc.nume;
		this->vizitatori = parc.vizitatori;
		this->nrTerenJoaca = parc.nrTerenJoaca;
		this->terenJoaca = new string[parc.nrTerenJoaca];
		for (int i = 0; i < nrTerenJoaca; i++)
			this->terenJoaca[i] = parc.terenJoaca[i];
	}
	const Parc& operator=(const Parc& parc) {
		if (this != &parc)
		{
			if (this->terenJoaca != NULL)
				delete[]this->terenJoaca;
			this->nume = parc.nume;
			this->vizitatori = parc.vizitatori;
			this->terenJoaca = parc.terenJoaca;
			this->terenJoaca = new string[this->nrTerenJoaca];
			for (int i = 0; i < nrTerenJoaca; i++)
				this->terenJoaca[i] = parc.terenJoaca[i];
			return *this;
		}

	}
	Parc operator+( Parc& parc) {
		Parc aux;
		aux.nume = this->nume;
		aux.vizitatori = this->vizitatori + parc.vizitatori;
		aux.nrTerenJoaca = this->nrTerenJoaca;
		if (aux.terenJoaca != NULL)
			delete[] aux.terenJoaca;
		aux.terenJoaca = new string[aux.nrTerenJoaca];
		for (int i = 0; i < this->nrTerenJoaca; i++)
			aux.terenJoaca[i] = this->terenJoaca[i];
		return aux;
	}
	~Parc() {
		if (this->terenJoaca != NULL)
			delete[]this->terenJoaca;
	}
	static void setOras(string oras) {
		Parc::oras = oras;
	}
	int getnrParc() {
		return this->nrParc;
	}
	static string getOras() {
		return Parc::oras;
	}
	void setNume(string nume) {
		if (nume.length() > 3)
			this->nume = nume;
	}
	string getNume() {
		return this->nume;
	}

	void setVizitatori(int vizitatori) {
		this->vizitatori = vizitatori;
	}
	int getVizitatori() {
		return this->vizitatori;
	}
	void setNrTerenJoaca(int nrTerenJoaca, string* teren) {
		if (nrTerenJoaca > 0) {
			this->nrTerenJoaca = nrTerenJoaca;
			if (this->terenJoaca != NULL)
				delete[]this->terenJoaca;
			terenJoaca = new string[this->nrTerenJoaca];
			for (int i = 0; i < nrTerenJoaca; i++)
				this->terenJoaca[i] = teren[i];
		}
	}
	string* getTerenJooaca() {
		return terenJoaca;
	}
	void addNouTeren(string teren) {

		string* a = new string[this->nrTerenJoaca + 1];
		for (int i = 0; i < this->nrTerenJoaca; i++)
			a[i] = this->terenJoaca[i];
		a[this->nrTerenJoaca] = teren;

		delete[]this->terenJoaca;
		this->terenJoaca = a;

		this->nrTerenJoaca++;

	}
	friend ostream& operator<<(ostream& out, const Parc& parc);
	friend istream& operator>>(istream& in, Parc& parc) {
		cout << "Nume: ";
		in >> parc.nume;
		cout << "\nVizitatori: ";
		in >> parc.vizitatori;
		cout << "\nNumar terenuri joaca: ";
		in >> parc.nrTerenJoaca;
		if (parc.terenJoaca != NULL) {
			delete[]parc.terenJoaca;
		}
		parc.terenJoaca = new string[parc.nrTerenJoaca];
		for (int i = 0; i < parc.nrTerenJoaca; i++) {
			cout << "Terenul de joaca " << i + 1 << ": ";
			in >> parc.terenJoaca[i];
		}
		return in;
	}
};
string Parc::oras = "Mangalia";
ostream& operator<<(ostream& out, const Parc& parc)
{
	out << "Parcul " << parc.nume << " are numarul " << parc.nrParc << ", se afla in orasul " << parc.oras << ", are " <<
		parc.vizitatori << " vizitatori zilnic. Are " << parc.nrTerenJoaca << " terenuri de joaca, acestea fiind de :";
	if (parc.nrTerenJoaca == 0)
		out << " -";
	else
		for (int i = 0; i < parc.nrTerenJoaca; i++)
			out << parc.terenJoaca[i] << " ";
	out << endl;
	return out;
}

class Scoala {
private:
	string nume;
	int elevi;
	const int nrScoala;
	int nrSaliSpeciale;
	string* saliSpeciale;
	static string oras;
public:
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
	Scoala(const Scoala& scoala) :nrScoala(scoala.nrScoala) {
		this->nume = scoala.nume;
		this->elevi = scoala.elevi;
		this->nrSaliSpeciale = scoala.nrSaliSpeciale;
		this->saliSpeciale = new string[scoala.nrSaliSpeciale];
		for (int i = 0; i < nrSaliSpeciale; i++)
			this->saliSpeciale[i] = scoala.saliSpeciale[i];
	}
	const Scoala& operator=(const Scoala& scoala) {
		if (this != &scoala)
		{
			if (this->saliSpeciale != NULL)
				delete[]this->saliSpeciale;
			this->nume = scoala.nume;
			this->elevi = scoala.elevi;
			this->saliSpeciale = scoala.saliSpeciale;
			this->saliSpeciale = new string[this->nrSaliSpeciale];
			for (int i = 0; i < nrSaliSpeciale; i++)
				this->saliSpeciale[i] = scoala.saliSpeciale[i];
			return *this;
		}

	}
	Scoala operator+(Scoala& scoala) {
		Scoala aux;
		aux.nume = this->nume;
		aux.elevi = this->elevi + scoala.elevi;
		aux.nrSaliSpeciale = this->nrSaliSpeciale;
		if (aux.saliSpeciale != NULL)
			delete[] aux.saliSpeciale;
		aux.saliSpeciale = new string[aux.nrSaliSpeciale];
		for (int i = 0; i < this->nrSaliSpeciale; i++)
			aux.saliSpeciale[i] = this->saliSpeciale[i];
		return aux;
	}
	static void setOras(string oras) {
		Scoala::oras = oras;
	}
	int getnrScoala() {
		return this->nrScoala;
	}
	static string getOras() {
		return Scoala::oras;
	}
	void setNume(string nume) {
		if (nume.length() > 3)
			this->nume = nume;
	}
	string getNume() {
		return this->nume;
	}

	void setElevi(int elevi) {
		this->elevi = elevi;
	}
	int getElevi() {
		return this->elevi;
	}
	void setNrSaliSpeciale(int nrSaliSpeciale, string* sali) {
		if (nrSaliSpeciale > 0) {
			this->nrSaliSpeciale = nrSaliSpeciale;
			if (this->saliSpeciale != NULL)
				delete[]this->saliSpeciale;
			saliSpeciale = new string[this->nrSaliSpeciale];
			for (int i = 0; i < nrSaliSpeciale; i++)
				this->saliSpeciale[i] = sali[i];
		}
	}
	string* getSaliSpeciale() {
		return saliSpeciale;
	}
	void addSalaSpeciala(string sali) {

		string* au = new string[this->nrSaliSpeciale + 1];
		for (int i = 0; i < this->nrSaliSpeciale; i++)
			au[i] = this->saliSpeciale[i];
		au[this->nrSaliSpeciale] = sali;

		delete[]this->saliSpeciale;
		this->saliSpeciale = au;

		this->nrSaliSpeciale++;

	}
	friend int plecareElevi(Scoala, int);
	friend ostream& operator<<(ostream& out, const Scoala& scoala);
	friend istream& operator>>(istream& in, Scoala& scoala) {
		cout << "Nume: ";
		in >> scoala.nume;
		cout << "\nElevi: ";
		in >> scoala.elevi;
		cout << "\nNumar sali speciale: ";
		in >> scoala.nrSaliSpeciale;
		if (scoala.saliSpeciale != NULL) {
			delete[]scoala.saliSpeciale;
		}
		scoala.saliSpeciale = new string[scoala.nrSaliSpeciale];
		for (int i = 0; i < scoala.nrSaliSpeciale; i++) {
			cout << "Sala speciala " << i + 1 << ": ";
			in >> scoala.saliSpeciale[i];
		}
		return in;
	}
};
string Scoala::oras = "Mangalia";
ostream& operator<<(ostream& out, const Scoala& scoala)
{
	out << "Scoala " << scoala.nume << " are numarul " << scoala.nrScoala << ", se afla in orasul " << scoala.oras << ", are " <<
		scoala.elevi << " elevi. Are " << scoala.nrSaliSpeciale << " sali speciale, acestea fiind de :";
	if (scoala.nrSaliSpeciale == 0)
		out << " -";
	else
		for (int i = 0; i < scoala.nrSaliSpeciale; i++)
			out << scoala.saliSpeciale[i] << " ";
	out << endl;
	return out;
}
int plecareElevi(Scoala s, int eleviPlecati) {
	s.elevi -= eleviPlecati;
	return s.elevi;
}
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

	cout << "Populatia medie pe bloc este de " << cartier2.populatieMedie() << endl;

	Cartier cartier3(3, "Militari", 100000);
	Cartier::setOras("Bucuresti");
	Cartier::adaugareStrazi(5);
	cartier3.afisare();
	cout << endl;
	Cartier cartier4(cartier3);

	cartier4.afisare();
	cout << endl;

	cartier4.setNume("Titan");
	cout << endl << cartier4.getNume();
	cartier4.setOras("Tokyo");
	cout << endl << cartier4.getOras();
	cartier4.setLocuitori(275);
	cout << endl << cartier4.getLocuitori();
	cartier4.setStraziAsfaltate(10);
	cout << endl << cartier4.getStraziAsfaltate();
	string* v1 = new string[7]{ "A1","A2","A3","A4","A5","A6","A7" };
	cartier4.setNrBlocuri(7, v1);
	cout << endl;
	cartier4.afisare(); 
	cout << endl;


	Cartier cartier5;
	cartier5.setLocuitori(100);
	cartier5.afisare();
	int numarAdunat = 50;
	int locuitoriDupaAdunare = adunaLocuitori(cartier5, numarAdunat);
	cout << "Dupa venirea a " << numarAdunat << " locuitori, cartierul are " << locuitoriDupaAdunare << " locuitori." << endl;

	cout << endl;
	Cartier cartier6;
	cartier6 = cartier3;
	cartier6.afisare();
	cout << endl;
	
	cout << endl;
	cout << cartier2 << endl;
	cin >> cartier2;
	cout << cartier2;
	cout << endl;

	cout << endl;
	Cartier cartier7;
	cartier7 = cartier3 + cartier3;
	cout << cartier7;

	cout << endl;
	Parc parc1;
	parc1.afisare();
	string* terenJoaca = new string[2];
	terenJoaca[0] = "Fotbal";
	terenJoaca[1] = "Baschet";

	Parc parc2("Portului ", 5000, 2,2,terenJoaca);
	parc2.afisare();
	cout << endl;

	Parc parc3("Magicieni ", 3000, 3, 0);
	Parc::setOras("Bucuresti");
	parc3.afisare();
	cout << endl;
	
	Parc parc4(parc2);
	parc4.afisare();
	cout << endl;

	parc4.setNume("Tosca ");
	cout << endl << parc4.getNume();
	parc4.setOras("Furtunesti");
	cout << endl << parc4.getOras();
	parc4.setVizitatori(900);
	cout << endl << parc4.getVizitatori();
	parc4.addNouTeren("Tenis");
	cout << endl;
	parc4.afisare();

	Parc parc5;
	parc5 = parc3;
	parc5.afisare();

	cout << endl;
	cout << parc2 << endl;
	cin >> parc2;
	cout << parc2;
	cout << endl;

	cout << endl;
	Parc parc7;
	parc7 = parc3 + parc3;
	cout<<parc7;

	cout << endl;
	Scoala scoala1;
	scoala1.afisare();
	string* saliSpeciale = new string[2];
	saliSpeciale[0] = "Chimie";
	saliSpeciale[1] = "Biologie";
	
	cout << endl;
	Scoala scoala2("Sf. Andrei", 350, 2, 2, saliSpeciale);
	scoala2.afisare();

	cout << endl;
	Scoala scoala3("Gala Galaction", 400, 3);
	Scoala::setOras("Bucuresti");
	scoala3.afisare();

	cout << endl;
	Scoala scoala4(scoala2);
	scoala4.afisare();
	cout << endl;
	scoala4.setNume("Callatis ");
	cout << endl << scoala4.getNume();
	scoala4.setOras("Calarasi");
	cout << endl << scoala4.getOras();
	scoala4.setElevi(700);
	cout << endl << scoala4.getElevi();
	scoala4.addSalaSpeciala("Fizica");
	cout << endl;
	scoala4.afisare();
	
	
	Scoala scoala5;
	scoala5.setElevi(350);
	scoala5.afisare();
	int eleviPlecati = 120;
	int eleviDupaPlecare = plecareElevi(scoala5, eleviPlecati);
	cout << "Dupa plecarea a " << eleviPlecati << " elevi, scoala a ramas cu " << eleviDupaPlecare << " elevi " << endl;

	Scoala scoala6;
	scoala6 = scoala3;
	scoala6.afisare();

	cout << endl;
	cout << scoala2 << endl;
	cin >> scoala2;
	cout << scoala2;
	cout << endl;

	cout << endl;
	Scoala scoala7;
	scoala7 = scoala3 + scoala3;
	cout << scoala7;
}
