	#include <iostream>
	#include <fstream>
	//Domeniu Oras

	using namespace std;
	class AbsCartier {
	public:
		virtual void printAbsCartier() = 0;
	};
	class Cartier:public AbsCartier {
	private:
		const int nrCartier;
		string nume;
		static string oras;
		int locuitori;
		int nrBlocuri;
		string* blocuri;
		static int straziAsfaltate;
	public:
		void printAbsCartier() {
			cout << "Cartierul " << this->nume << " are " << this->locuitori << " locuitori." << endl;
		}
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
		string& operator[](int index) {
			if (index >= 0 && index < nrBlocuri) {
				return blocuri[index];
			}
			else {
				static string gol = " ";
				return gol;
			}
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
		void setNumeC(const std::string& newNume) {
			this->nume = newNume;
		}
		string getNumeC() const {
			return nume;
		}
		void desfasoaraEveniment(class Parc& parc);
		friend int adunaLocuitori(Cartier, int);
		friend ofstream& operator<<(ofstream& out, const Cartier& cartier);
		friend ifstream& operator>>(ifstream& in, Cartier& cartier);
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
	ofstream& operator<<(ofstream& out, const Cartier& cartier){
		out << cartier.nume<< endl << cartier.locuitori <<endl;

		for (int i = 0; i < cartier.nrBlocuri; i++)
			out << cartier.blocuri[i] << " ";
		out << endl;
		return out;
	}
	ifstream& operator>>(ifstream& in, Cartier& cartier) {
		in >> cartier.nume;
		in >> cartier.locuitori;
		in >> cartier.nrBlocuri;
		if (cartier.blocuri != NULL)
			delete[]cartier.blocuri;
		cartier.blocuri = new string[cartier.nrBlocuri];
		for (int i = 0; i < cartier.nrBlocuri; i++)
			in >> cartier.blocuri[i];
		return in;
	}

	class AbsParc {
	public:
		virtual void printAbsParc() = 0;
	};
	class Parc:public AbsParc {
	private:
		string nume;
		int vizitatori;
		static string oras;
		const int nrParc;
		int nrTerenJoaca;
		string* terenJoaca;
	public:
		void printAbsParc() {
			cout << "Parcul " << this->nume << " are " << this->vizitatori << " vizitatori." << endl;
		}
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

			string* aux = new string[this->nrTerenJoaca + 1];
			for (int i = 0; i < this->nrTerenJoaca; i++)
				aux[i] = this->terenJoaca[i];
			aux[this->nrTerenJoaca] = teren;

			delete[]this->terenJoaca;
			this->terenJoaca = aux;

			this->nrTerenJoaca++;

		}
		void desfasoaraEveniment(class Cartier& cartier);
		friend ofstream& operator<<(ofstream& out, const Parc& parc);
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
		void scrieInFisierBinar(const char* numeFisier) {
			ofstream fisier(numeFisier, ios::binary | ios::out);


			fisier.write((char*)&nrParc, sizeof(int));
			fisier.write((char*)&vizitatori, sizeof(int));


			int lungimeNume = nume.length() + 1;
			fisier.write((char*)&lungimeNume, sizeof(int));
			fisier.write(nume.c_str(), lungimeNume);


			fisier.write((char*)&nrTerenJoaca, sizeof(int));
			for (int i = 0; i < nrTerenJoaca; ++i) {
				int lungimeTeren = terenJoaca[i].length() + 1;
				fisier.write((char*)&lungimeTeren, sizeof(int));
				fisier.write(terenJoaca[i].c_str(), lungimeTeren);
			}

			fisier.close();
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
	ofstream& operator<<(ofstream& out, const Parc& parc) {
		out << parc.nume << endl << parc.vizitatori << endl;

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
		operator int() {
			return elevi;
		}
		string* getSaliSpeciale() {
			return saliSpeciale;
		}
		void addSalaSpeciala(string sali) {

			string* aux = new string[this->nrSaliSpeciale + 1];
			for (int i = 0; i < this->nrSaliSpeciale; i++)
				aux[i] = this->saliSpeciale[i];
			aux[this->nrSaliSpeciale] = sali;

			delete[]this->saliSpeciale;
			this->saliSpeciale = aux;

			this->nrSaliSpeciale++;

		}
		friend int plecareElevi(Scoala, int);
		friend ofstream& operator<<(ofstream& out, const Scoala& scoala);
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

		void scrieInFisierBinar(const char* numeFisier) {
			ofstream fisier(numeFisier, ios::binary | ios::out);

			
			fisier.write((char*)&nrScoala, sizeof(int));
			fisier.write((char*)&elevi, sizeof(int));

			
			int lungimeNume = nume.length() + 1;
			fisier.write((char*)&lungimeNume, sizeof(int));
			fisier.write(nume.c_str(), lungimeNume);

			
			fisier.write((char*)&nrSaliSpeciale, sizeof(int));
			for (int i = 0; i < nrSaliSpeciale; ++i) {
				int lungimeSala = saliSpeciale[i].length() + 1;
				fisier.write((char*)&lungimeSala, sizeof(int));
				fisier.write(saliSpeciale[i].c_str(), lungimeSala);
			}

			fisier.close();
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
	ofstream& operator<<(ofstream& out, const Scoala& scoala) {
		out << scoala.nume << endl << scoala.elevi << endl;

		for (int i = 0; i < scoala.nrSaliSpeciale; i++)
			out << scoala.saliSpeciale[i] << " ";
		out << endl;
		return out;
	}
	class Sector {
	private:
		const int nrSector;
		string nume;
		float suprafata;
		static string oras;
		int nrCartiere;
		Cartier* cartiere;

	public:
		Sector() : nrSector(1) {
			this->nume = "Nu are nume";
			this->suprafata = 0;
			this->nrCartiere = 0;
			this->cartiere = NULL;
		}
		Sector(int nrSector, string nume, int nrCartiere, Cartier* cartiere,float suprafata) :nrSector(nrSector) {
			this->nume = nume;
			this->suprafata = suprafata;
			this->nrCartiere = nrCartiere;
			this->cartiere = new Cartier[nrCartiere];
			for (int i = 0; i < nrCartiere; i++)
				this->cartiere[i] = cartiere[i];
		}
		Sector(const Sector& sector) :nrSector(sector.nrSector) {
			this->nume = sector.nume;
			this->suprafata = sector.suprafata;
			this->nrCartiere = sector.nrCartiere;
			this->cartiere = new Cartier[this->nrCartiere];
			for (int i = 0; i < nrCartiere; i++)
				this->cartiere[i] = sector.cartiere[i];
		}
		const Sector& operator=(const Sector& sector) {
			if (this != &sector)
			{
				if (this->cartiere != NULL)
					delete[]this->cartiere;
				this->nume = sector.nume;
				this->suprafata = sector.suprafata;
				this->cartiere = sector.cartiere;
				this->cartiere = new Cartier[this->nrCartiere];
				for (int i = 0; i < nrCartiere; i++)
					this->cartiere[i] = sector.cartiere[i];
				return *this;
			}
		}
		~Sector() {
			delete[]this->cartiere;
		}
		friend ostream& operator<<(ostream& out, Sector& sector);
		friend ofstream& operator<<(ofstream& out, Sector& sector);
		friend ifstream& operator>>(ifstream& in, Sector& sector);
		friend istream& operator>>(istream& in, Sector& sector) {
			cout << "Nume: ";
			in >> sector.nume;
			cout << "\nSuprafata: ";
			in >> sector.suprafata;
			cout << "\nNumar cartiere: ";
			in >> sector.nrCartiere;
			if (sector.cartiere != NULL) {
				delete[]sector.cartiere;
			}
			sector.cartiere = new Cartier[sector.nrCartiere];
			for (int i = 0; i < sector.nrCartiere; i++) {
				cout << "Cartierul " << i + 1 << ": ";
				in >> sector.cartiere[i];
			}
			return in;
		}
		void afisare() {
			cout << "Sectorul " << this->nume << " cu numarul " << this->nrSector << " din orasul " << this->oras << " are o suprafata de " << this->suprafata
				<< ", are un numar de " << this->nrCartiere<< " cartiere, acestea fiind numite: " << endl;
			if (nrCartiere != 0 && cartiere != NULL) {
				for (int i = 0; i < this->nrCartiere; i++) {
					cout << "Cartier " << i + 1 << ": " << cartiere[i].getNume() << endl;
					cout << endl;
				}
			}
			else
				cout << "Cartierele nu au fost introduse" << endl << endl;
		}
		Cartier* getCartiere() const {
			return cartiere;
		}
		static void setOras(string oras) {
			Sector::oras = oras;
		}
		int getnrSector() {
			return this->nrSector;
		}
		static string getOras() {
			return Sector::oras;
		}
		void setNume(string nume) {
				this->nume = nume;
		}
		string getNume() {
			return this->nume;
		}

		void setSuprafata(float suprafata) {
			this->suprafata = suprafata;
		}
		int getSuprafata() {
			return this->suprafata;
		}
		void setNrCartiere(int nrCartiere, Cartier* cartier) {
			if (nrCartiere > 0) {
				this->nrCartiere = nrCartiere;
				if (this->cartiere != NULL)
					delete[]this->cartiere;
				cartiere = new Cartier[this->nrCartiere];
				for (int i = 0; i < nrCartiere; i++)
					this->cartiere[i] = cartier[i];
			}
		}
		Cartier* getCartier() {
			return cartiere;
		}

		operator int() {
			return suprafata;
		}
		
	};
	string Sector::oras = "Mangalia";
	ostream& operator<<(ostream& out, Sector& sector)
	{
		out << "Sectorul " << sector.nume << " are numarul " << sector.nrSector << ", se afla in orasul " << sector.oras << ", are suprafata de " <<
			sector.suprafata << ". Are " << sector.nrCartiere << " cartiere, acestea fiind: "<<endl;
		if (sector.nrCartiere == 0)
			out << " -";
		else
			for (int i = 0; i < sector.nrCartiere; i++)
				out << sector.cartiere[i] << " ";
		out << endl;
		return out;
	}
	ofstream& operator<<(ofstream& out, Sector& sector) {
		out << sector.nume << endl << sector.suprafata << endl;

		for (int i = 0; i < sector.nrCartiere; i++)
			out << sector.cartiere[i] << " ";
		out << endl;
		return out;
	}
	ifstream& operator>>(ifstream& in, Sector& sector) {
		in >> sector.nume;
		in >> sector.suprafata;
		in >> sector.nrCartiere;
		sector.cartiere = new Cartier[sector.nrCartiere];
		for (int i = 0; i < sector.nrCartiere; i++) {
			cout << "Cartier " << i + 1 << ":" << endl;
			in >> sector.cartiere[i];
		}

		return in;
	}

	class ModernCartier : public Cartier {
	private:
		int aniModernizare;
		char* numeModernizare;
	public:
		void printAbsCartier() {
			cout << "Cartierul a fost modernizat pe o perioada de " << this->aniModernizare << " ani." << endl;
		}
		ModernCartier() :Cartier(12, "Berceni", 199) {
			this->aniModernizare = 4;
			this->numeModernizare = new char[strlen("Treceri de pietoni luminate") + 1];
			strcpy_s(this->numeModernizare, strlen("Treceri de pietoni luminate") + 1, "Treceri de pietoni luminate");
		}
		ModernCartier(int aniModernizare, const char* numeModernizare) :Cartier() {
			this->aniModernizare = aniModernizare;
			this->numeModernizare = new char[strlen(numeModernizare) + 1];
			strcpy_s(this->numeModernizare, strlen(numeModernizare) + 1, numeModernizare);
		}
		ModernCartier(int aniModernizare, const char* numeModernizare, string nume, int nrBlocuri, string* blocuri, int locuitori) :Cartier(1, nume, nrBlocuri, blocuri, locuitori) {
			this->aniModernizare = aniModernizare;
			this->numeModernizare = new char[strlen(numeModernizare) + 1];
			strcpy_s(this->numeModernizare, strlen(numeModernizare) + 1, numeModernizare);
		}
		ModernCartier(const ModernCartier& mc) :Cartier(mc) {
			this->aniModernizare = mc.aniModernizare;
			this->numeModernizare = new char[strlen(mc.numeModernizare) + 1];
			strcpy_s(this->numeModernizare, strlen(mc.numeModernizare) + 1, mc.numeModernizare);
		}
		ModernCartier operator=(const ModernCartier& mc) {
			if (this != &mc) {
				Cartier::operator=(mc);
				this->aniModernizare = mc.aniModernizare;
				if (this->numeModernizare) {
					delete[]this->numeModernizare;
				}
				this->numeModernizare = new char[strlen(mc.numeModernizare) + 1];
				strcpy_s(this->numeModernizare, strlen(mc.numeModernizare) + 1, mc.numeModernizare);
			}
			return *this;
		}
		~ModernCartier() {
			if (this->numeModernizare) {
				delete[]this->numeModernizare;
			}
		}
		void setAniModernizare(int aniModernizare) {
			this->aniModernizare = aniModernizare;
		}
		int getAniModernizare() {
			return this->aniModernizare;
		}
		void setNumeModernizare(char* numeModernizare) {
			this->numeModernizare = numeModernizare;
		}
		char* getNumeModernizare() {
			return this->numeModernizare;
		}
		friend ostream& operator<<(ostream& ecran, const ModernCartier& mc) {
			ecran << (Cartier)mc;
			ecran << mc.numeModernizare << " ";
			ecran <<mc.aniModernizare << endl;
			return ecran;
		}

		friend istream& operator>>(istream& tast, ModernCartier& mc) {
			tast >> (Cartier&)mc;
			cout << "Ani modernizare:";
			tast >> mc.aniModernizare;
			if (mc.numeModernizare)
			{
				delete[]mc.numeModernizare;
			}
			cout << "Nume modernizare:";
			char buffer[30];
			tast >> buffer;
			mc.numeModernizare = new char[strlen(buffer) + 1];
			strcpy_s(mc.numeModernizare, strlen(buffer) + 1, buffer);
			return tast;
		}
	};

	class CuratareParc :public Parc {
	private:
		int perioadaCuratare;
		char* zonaCuratata;
	public:
		void printAbsParc() {
			cout << "Parcul a fost curatat pe o perioada de " << this->perioadaCuratare << " zile." << endl;
		}
		CuratareParc() :Parc("Central",5678,5,0) {
			this->perioadaCuratare = 2;
			this->zonaCuratata = new char[strlen("Zona locurilor de joaca") + 1];
			strcpy_s(this->zonaCuratata, strlen("Zona locurilor de joaca") + 1, "Zona locurilor de joaca");
		}
		CuratareParc(int perioadaCuratare, const char* zonaCuratata) :Parc() {
			this->perioadaCuratare = perioadaCuratare;
			this->zonaCuratata = new char[strlen(zonaCuratata) + 1];
			strcpy_s(this->zonaCuratata, strlen(zonaCuratata) + 1, zonaCuratata);
		}
		CuratareParc(int perioadaCuratare, const char* zonaCuratata, string nume, int vizitatori, int nrParc, int nrTerenJoaca, string* terenJoaca) :Parc(nume,vizitatori,3, nrTerenJoaca, terenJoaca) {
			this->perioadaCuratare = perioadaCuratare;
			this->zonaCuratata = new char[strlen(zonaCuratata) + 1];
			strcpy_s(this->zonaCuratata, strlen(zonaCuratata) + 1, zonaCuratata);
		}
		CuratareParc(const CuratareParc& cp) :Parc(cp) {
			this->perioadaCuratare = cp.perioadaCuratare;
			this->zonaCuratata = new char[strlen(cp.zonaCuratata) + 1];
			strcpy_s(this->zonaCuratata, strlen(cp.zonaCuratata) + 1, cp.zonaCuratata);
		}
		CuratareParc operator=(const CuratareParc& cp) {
			if (this != &cp) {
				Parc::operator=(cp);
				this->perioadaCuratare = cp.perioadaCuratare;
				if (this->zonaCuratata) {
					delete[]this->zonaCuratata;
				}
				this->zonaCuratata = new char[strlen(cp.zonaCuratata) + 1];
				strcpy_s(this->zonaCuratata, strlen(cp.zonaCuratata) + 1, cp.zonaCuratata);
			}
			return *this;
		}
		~CuratareParc() {
			if (this->zonaCuratata) {
				delete[]this->zonaCuratata;
			}
		}
		void setPeroiadaCuratare(int perioadaCuratare) {
			this->perioadaCuratare = perioadaCuratare;
		}
		int getPerioadaCuratare() {
			return this->perioadaCuratare;
		}
		void setZonaCuratata(char* zonaCuratata) {
			this->zonaCuratata = zonaCuratata;
		}
		char* getZonaCuratata() {
			return this->zonaCuratata;
		}
		friend ostream& operator<<(ostream& ecran, const CuratareParc& cp) {
			ecran << (Parc)cp;
			ecran << cp.zonaCuratata << " ";
			ecran << cp.perioadaCuratare << endl;
			return ecran;
		}

		friend istream& operator>>(istream& tast, CuratareParc& cp) {
			tast >> (Cartier&)cp;
			cout << "Ani modernizare:";
			tast >> cp.perioadaCuratare;
			if (cp.zonaCuratata)
			{
				delete[]cp.zonaCuratata;
			}
			cout << "Nume modernizare:";
			char buffer[30];
			tast >> buffer;
			cp.zonaCuratata = new char[strlen(buffer) + 1];
			strcpy_s(cp.zonaCuratata, strlen(buffer) + 1, buffer);
			return tast;
		}
	};

	class Oras {
	private:
		int nrSectoare;
		AbsCartier* *sectoare;
	public:
		Oras() {
			nrSectoare = 5;
			sectoare = new AbsCartier * [5];
			for (int i = 0; i < 5; i++) {
				this->sectoare[i] = new Cartier();
			}
		}
		AbsCartier*& operator[](int index) {
			if (index >= 0 && index < this->nrSectoare) {
				return this->sectoare[index];
			}
			else {
				throw 404;
			}
		}
	};
	
	class Park {
	private:
		int nrParcuri;
		AbsParc* *parcuri;
	public:
		Park() {
			nrParcuri = 5;
			parcuri = new AbsParc * [5];
			for (int i = 0; i < 5; i++) {
				this->parcuri[i] = new Parc();
			}
		}
		AbsParc*& operator[](int index) {
			if (index >= 0 && index < this->nrParcuri) {
				return this->parcuri[index];
			}
			else {
				throw 404;
			}
		}
	};
	
	void functiePrintare(AbsCartier* c) {
		c->printAbsCartier();
	}
	void functiePrint(AbsParc* p) {
		p->printAbsParc();
	}
	void functiePrinta(CuratareParc cp) {
		cp.printAbsParc();
	}
	void functiePrintMC(ModernCartier mc) {
		mc.printAbsCartier();
	}

	void Cartier::desfasoaraEveniment(Parc& parc) {
		int popCartier = getLocuitori();
		int popAdunata = popCartier / 4;

		setLocuitori(popAdunata);
		parc.setVizitatori(parc.getVizitatori() + popAdunata);
		cout << "Eveniment intre Cartierul " << this->getNume() << " si Parcul " << parc.getNume() << ":\n";
		cout << "Un sfert din locuitorii cartierului " << this->getNume() << " participa la evenimentul din parcul " << parc.getNume()
			<<". Aici participa si vizitatorii parcului" << ".\n";
	}
	void Parc::desfasoaraEveniment(Cartier& cartier) {
		int vizitatoriParc = getVizitatori();

	}
	void evenimentIntalnire(Cartier& cartier, Parc& parc) {
		cartier.desfasoaraEveniment(parc);
		parc.desfasoaraEveniment(cartier);
	}

	void main()
	{
		Cartier cartierX(1, "Cartier A", 500);
		Parc parcY("Parc Central", 1000, 2, 0);

		evenimentIntalnire(cartierX, parcY);
		cout << "Locuitorii din cartierul " << cartierX.getNume() << " ce participa la eveniment: " << cartierX.getLocuitori() << "\n";
		cout << "Numarul total de participanti al evenimentului din parcul " << parcY.getNume() << ": " << parcY.getVizitatori() << "\n";

		//Cartier cartier1;
		//cartier1.afisare();

		//string* numeBlocuri = new string[6];
		//numeBlocuri[0] = "A1";
		//numeBlocuri[1] = "A2";
		//numeBlocuri[2] = "B1";
		//numeBlocuri[3] = "B2";
		//numeBlocuri[4] = "C1";
		//numeBlocuri[5] = "C2";
		//Cartier cartier2(2, "Colonisti", 6, numeBlocuri, 500);
		//cartier2.afisare();

		//cout << "Populatia medie pe bloc este de " << cartier2.populatieMedie() << endl;

		//Cartier cartier3(3, "Militari", 100000);
		//Cartier::setOras("Bucuresti");
		//Cartier::adaugareStrazi(5);
		//cartier3.afisare();
		//cout << endl;
		//Cartier cartier4(cartier3);

		//cartier4.afisare();
		//cout << endl;

		//cartier4.setNume("Titan");
		//cout << endl << cartier4.getNume();
		//cartier4.setOras("Tokyo");
		//cout << endl << cartier4.getOras();
		//cartier4.setLocuitori(275);
		//cout << endl << cartier4.getLocuitori();
		//cartier4.setStraziAsfaltate(10);
		//cout << endl << cartier4.getStraziAsfaltate();
		//string* v1 = new string[7]{ "A1","A2","A3","A4","A5","A6","A7" };
		//cartier4.setNrBlocuri(7, v1);
		//cout << endl;
		//cartier4.afisare();
		//cout << endl;


		//Cartier cartier5;
		//cartier5.setLocuitori(100);
		//cartier5.afisare();
		//int numarAdunat = 50;
		//int locuitoriDupaAdunare = adunaLocuitori(cartier5, numarAdunat);
		//cout << "Dupa venirea a " << numarAdunat << " locuitori, cartierul are " << locuitoriDupaAdunare << " locuitori." << endl;

		//cout << endl;
		//Cartier cartier6;
		//cartier6 = cartier3;
		//cartier6.afisare();
		//cout << endl;

		//cout << endl;
		//cout << cartier2 << endl;
		//cin >> cartier2;
		//cout << cartier2;
		//cout << endl;

		//cout << endl;
		//Cartier cartier7;
		//cartier7 = cartier3 + cartier3;
		//cout << cartier7;

		//cout << endl;
		//Cartier cartier8;
		//cartier8.setNrBlocuri(3, new string[3]{ "Bloc A", "Bloc B", "Bloc C" });
		//cartier8[2] = "Bloc D";
		//cout << cartier8;
		//cout << endl;


		//Cartier* v_cartier = new Cartier[3];
		//for (int i = 0; i < 3; i++) {
		//	cout << "Introduceti informatii pentru Cartier " << i + 1 << ": " << endl;
		//	cin >> v_cartier[i];
		//}
		//for (int i = 0; i < 3; i++) {
		//	cout << "Cartier " << i + 1 << endl;
		//	cout << v_cartier[i];
		//}


		//Cartier** m_cartier = new Cartier * [3];
		//for (int i = 0; i < 2; i++) {
		//	for (int j = 0; j < 2; j++) {
		//		m_cartier[i] = new Cartier();
		//		cout << "Introduceti informatii pentru Cartier " << i + 1 << ": " << endl;
		//		cin >> *m_cartier[i];
		//	}
		//}
		//for (int i = 0; i < 2; i++) {
		//	for (int j = 0; j < 2; j++) {
		//		cout << "Cartier " << i + 1 << endl;
		//		cout << *m_cartier[i];
		//	}
		//}
		//cout << endl;

		//cout << endl;
		//Parc parc1;
		//parc1.afisare();
		//string* terenJoaca = new string[2];
		//terenJoaca[0] = "Fotbal";
		//terenJoaca[1] = "Baschet";

		//Parc parc2("Portului ", 5000, 2, 2, terenJoaca);
		//parc2.afisare();
		//cout << endl;

		//Parc parc3("Magicieni ", 3000, 3, 0);
		//Parc::setOras("Bucuresti");
		//parc3.afisare();
		//cout << endl;

		//Parc parc4(parc2);
		//parc4.afisare();
		//cout << endl;

		//parc4.setNume("Tosca ");
		//cout << endl << parc4.getNume();
		//parc4.setOras("Furtunesti");
		//cout << endl << parc4.getOras();
		//parc4.setVizitatori(900);
		//cout << endl << parc4.getVizitatori();
		//parc4.addNouTeren("Tenis");
		//cout << endl;
		//parc4.afisare();

		//Parc parc5;
		//parc5 = parc3;
		//parc5.afisare();

		//cout << endl;
		//cout << parc2 << endl;
		//cin >> parc2;
		//cout << parc2;
		//cout << endl;

		//cout << endl;
		//Parc parc7;
		//parc7 = parc3 + parc3;
		//cout << parc7;

		//Parc* v_parc = new Parc[3];
		//for (int i = 0; i < 3; i++) {
		//	cout << "Introduceti informatii pentru parc " << i + 1 << ": " << endl;
		//	cin >> v_parc[i];
		//}

		//for (int i = 0; i < 3; i++) {
		//	cout << "Parc " << i + 1 << endl;
		//	cout << v_parc[i];
		//}

		//cout << endl;
		//Scoala scoala1;
		//scoala1.afisare();
		//string* saliSpeciale = new string[2];
		//saliSpeciale[0] = "Chimie";
		//saliSpeciale[1] = "Biologie";

		//cout << endl;
		//Scoala scoala2("Sf. Andrei", 350, 2, 2, saliSpeciale);
		//scoala2.afisare();

		//cout << endl;
		//Scoala scoala3("Gala Galaction", 400, 3);
		//Scoala::setOras("Bucuresti");
		//scoala3.afisare();

		//cout << endl;
		//Scoala scoala4(scoala2);
		//scoala4.afisare();
		//cout << endl;
		//scoala4.setNume("Callatis ");
		//cout << endl << scoala4.getNume();
		//scoala4.setOras("Calarasi");
		//cout << endl << scoala4.getOras();
		//scoala4.setElevi(700);
		//cout << endl << scoala4.getElevi();
		//scoala4.addSalaSpeciala("Fizica");
		//cout << endl;
		//scoala4.afisare();


		//Scoala scoala5;
		//scoala5.setElevi(350);
		//scoala5.afisare();
		//int eleviPlecati = 120;
		//int eleviDupaPlecare = plecareElevi(scoala5, eleviPlecati);
		//cout << "Dupa plecarea a " << eleviPlecati << " elevi, scoala a ramas cu " << eleviDupaPlecare << " elevi " << endl;

		//Scoala scoala6;
		//scoala6 = scoala3;
		//scoala6.afisare();

		//cout << endl;
		//cout << scoala2 << endl;
		//cin >> scoala2;
		//cout << scoala2;
		//cout << endl;

		//cout << endl;
		//Scoala scoala7;
		//scoala7 = scoala3 + scoala3;
		//cout << scoala7;

		//int numarElevi = scoala3;
		//cout << numarElevi;

		//cout << endl;
		//Scoala* v_scoala = new Scoala[3];
		//for (int i = 0; i < 3; i++) {
		//	cout << "Introduceti informatii pentru scoala " << i + 1 << ": " << endl;
		//	cin >> v_scoala[i];
		//}
		//for (int i = 0; i < 3; i++) {
		//	cout << "Scoala " << i + 1 << endl;
		//	cout << v_scoala[i];
		//}
		//cout << endl;
		//Cartier* cartiere = new Cartier[2];

		//Sector sector1(1, "Sector 1", 2, cartiere, 500.2);
		//sector1.getCartiere()[0].setNumeC("Cartier A");
		//sector1.getCartiere()[1].setNumeC("Cartier B");
		//sector1.afisare();

		//Sector sector2(sector1);
		//cin >> sector2;
		//cout << sector2;
		//int suprafataC = sector2;
		//cout << suprafataC << endl;
		//Sector sector3(sector1);
		//sector3.setNume("S3");
		//cout << endl << sector3.getNume();
		//sector3.setOras("Bucuresti");
		//cout << endl << sector3.getOras();
		//sector3.setSuprafata(275);
		//cout << endl << sector3.getSuprafata();
		//Cartier* v2 = new Cartier[3];
		//sector3.setNrCartiere(3, v2);
		//cout << endl;
		//cout << sector3;
		//cout << endl;

		//ofstream f("cartier.txt", ios::out);
		//Cartier cartier9;
		//cin >> cartier9;
		//f << cartier9;
		//f.close();
		//ifstream g("cartier.txt", ios::in);
		//Cartier c9;
		//g >> c9;
		//cout << c9;
		//g.close();


		//string* v4 = new string[2];
		//v4[0] = "Tenis";
		//v4[1] = "Baschet";

		//Parc parc10("Portului ", 5000, 2, 2, v4);
		//parc10.scrieInFisierBinar("parc.bin");

		//string* v3 = new string[2];
		//v3[0] = "Chimie";
		//v3[1] = "Biologie";

		//cout << endl;
		//Scoala scoala9("Sf. Andrei", 350, 2, 2, v3);
		//scoala9.scrieInFisierBinar("scoala.bin");

		///*ofstream f("sector.txt", ios::out);
		//Sector sector4;
		//cin >> sector4;
		//f <<sector4;
		//f.close();
		//ifstream g("sector.txt", ios::in);
		//Sector s4;
		//g >> s4;
		//cout << s4;
		//g.close();*/
		//ModernCartier mc1;
		//ModernCartier mc2(20, "Semafoare");
		//ModernCartier mc3 = mc1;
		//ModernCartier mc4;
		//mc4 = mc2;
		//string blocuri[5]{ "F1","F2","F3","F4","F5" };
		//mc1.setNrBlocuri(5, blocuri);
		//cout << mc1;
		//cin >> mc2;
		//cout << mc2;
		//mc4.setAniModernizare(10);
		//cout << mc4;

		//CuratareParc cp1;
		//CuratareParc cp2(15, "Banci");
		//CuratareParc cp3 = cp1;
		//CuratareParc cp4;
		//cp4 = cp2;
		//string terenuriJoaca[3]{ "Fotbal","Baschet","Tenis" };
		//cp1.setNrTerenJoaca(3, terenuriJoaca);
		//cout << cp1;
		//cout << cp2;
		//cp4.setPeroiadaCuratare(20);
		//cout << cp4<<endl;

		//Oras oras;
		//oras[0] = new Cartier(0, "C1", 333);
		//oras[1] = new ModernCartier(7, "Senzori pe autobuze");
		//oras[2] = new Cartier(2, "C2", 234);
		//oras[3] = new ModernCartier(11, "Magistrala noua");
		//oras[4] = new ModernCartier(12, "Statie noua autobuz");
		//for (int i = 0; i < 5; i++) {
		//	oras[i]->printAbsCartier();
		//}
		//cout << endl;

		//Park park;
		//park[0] = new Parc("P1", 3000, 1, 2);
		//park[1] = new CuratareParc(7, "Tenis");
		//park[2] = new Parc("P2", 2000,2,3);
		//park[3] = new CuratareParc(5, "Fotbal");
		//park[4] = new CuratareParc(4, "Baschet");
		//for (int i = 0; i < 5; i++) {
		//	park[i]->printAbsParc();
		//}
	}
