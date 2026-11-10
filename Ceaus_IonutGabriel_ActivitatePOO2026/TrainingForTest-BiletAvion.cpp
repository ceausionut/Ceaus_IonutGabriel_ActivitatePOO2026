#include<iostream>
#include<string>
using namespace std;

class BiletAvion {
private:
	const int numarBilet;
	string numePasager;
	int durataZbor;
	double* distante;
	int numarSegmente;
public:
	static int nrBilet;
	

	BiletAvion(string numePasager, int durataZbor) :numarBilet(++nrBilet) {
		if (numePasager.empty()) {
			this->numePasager = "Necunoscut";
		}
		else{
			this->numePasager = numePasager;
		}
		if (durataZbor >= 0) {
			this->durataZbor = durataZbor;

		}
		else {
			this->durataZbor = 0;
		}
		this->distante = nullptr;
		this->numarSegmente = 0;

	}
	BiletAvion(const BiletAvion& copie) {

	}

	void afisare() {
		cout << endl << "Numar bilet: " << this->numarBilet;
		cout << endl << "Nume Pasager : " << this->numePasager;
		cout << endl << "Durata Zbor: " << this->durataZbor;
		cout << endl << "Distanta: " << *(this->distante);
		cout << endl << "Numar segemente: " << this->numarSegmente;
	}
	~BiletAvion(){
		cout << endl << "s-a apelat destructorul";
		if (this->distante != nullptr) {
			delete[] this->distante;
		}


	}
};

int BiletAvion::nrBilet = 0;


void main() {
	BiletAvion bilet("Ionut", 3);
	BiletAvion bilet2("Gigel", 2);
	bilet.afisare();
	bilet2.afisare();
}