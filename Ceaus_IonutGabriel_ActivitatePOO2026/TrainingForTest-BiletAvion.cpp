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
	BiletAvion(const BiletAvion& copie) :numarBilet(++nrBilet){
		this->numePasager = copie.numePasager;
		this->durataZbor = copie.durataZbor;
		this->numarSegmente = copie.numarSegmente;
		if (copie.distante != nullptr && copie.numarSegmente > 0) {
			this->distante = new double[numarSegmente];
			for (int i = 0; i < this->numarSegmente; i++) {
				this->distante[i] = copie.distante[i];
			}
		}
		else
		{
			this->distante = nullptr;

		}

	}

	void afisare() {
		cout << endl << "Numar bilet: " << this->numarBilet;
		cout << endl << "Nume Pasager : " << this->numePasager;
		cout << endl << "Durata Zbor: " << this->durataZbor;

		cout << endl << "Distanta: " << this->distante;
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
	BiletAvion* bilet1 = new BiletAvion("Ionut", 4);
	BiletAvion bilet2("Gigel", 2);
	BiletAvion biletcopiat = bilet;
	bilet.afisare();
	bilet2.afisare();
	biletcopiat.afisare();
}