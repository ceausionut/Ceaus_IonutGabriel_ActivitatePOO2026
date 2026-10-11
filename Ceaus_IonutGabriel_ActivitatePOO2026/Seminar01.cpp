#include<iostream>
#include<string>

using namespace std;

class Cofetarie {
private:
	const int id;
	string denumire;
	int nrProduse;
	float* preturi;
public:
	static int nrCofetarii;
	Cofetarie() :id(++nrCofetarii) {
		//this->id = 0;
		this->denumire = "Cofetarie generala";
		this->nrProduse = 0;
		this->preturi = nullptr;
	}

	Cofetarie(int id, string denumire, int nrProduse, float* preturi) :id(id) {
		//this->id = 0;
		nrCofetarii++;
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;
	}

	void afisare() {
		cout << endl << "Id: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Nr. produse: " << this->nrProduse;
		if (this->nrProduse > 0) {
			cout << " cu urmatoarele preturi: ";
			for (int i = 0; i < this->nrProduse - 1; i++)
			{
				cout << this->preturi[i] << " lei, ";
			}
			cout << this->preturi[this->nrProduse - 1] << " lei.";
		}
	}
};

int Cofetarie::nrCofetarii = 0;

void main() {
	Cofetarie cofetarieGenerala;
	cofetarieGenerala.afisare();

	float* preturi = new float[] {18.5, 24, 15.5};
	Cofetarie* cofetarieRomana = new Cofetarie(7, "CofetarieRomana", 3, preturi);
	cofetarieRomana->afisare();

	delete cofetarieRomana;

	cout << endl << "Numar cofetarii: " << Cofetarie::nrCofetarii;
}