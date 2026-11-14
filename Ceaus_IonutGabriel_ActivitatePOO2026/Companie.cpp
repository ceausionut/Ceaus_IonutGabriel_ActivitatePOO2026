#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Companie {
private:
	const int id;
	char* nume_companie;
	double cifra_afaceri;

public:
	static int contor;

	Companie() :id(0){
		this->cifra_afaceri = 0.0;
		this->nume_companie = nullptr;
	}

	Companie(double cifra_afaceri) :id(contor++){
		this->nume_companie = nullptr;
		this->cifra_afaceri = cifra_afaceri;
	}
	int getId() {
		return this->id;
	}
	void setnume_companie(char* nume_companie) {
		if (nume_companie != nullptr) {
			delete[] this->nume_companie;
			this->nume_companie = new char[strlen(nume_companie) + 1];
			strcpy(this->nume_companie, nume_companie);


		}
	}

		void afisare() {
			cout << endl << this->id;
			cout << endl << this->cifra_afaceri ;
			if (this->nume_companie != nullptr) {
				cout << endl;
				for (int i = 0; i < strlen(this->nume_companie); i++) {
					cout << this->nume_companie[i];
				}
			}
			else {
				cout << endl << "companie fara nume";
			}

		
	}
};

int Companie::contor = 0;
int main() {
	Companie c1;
	char aux[20];
	strcpy(aux, "gigelescu");
	c1.setnume_companie(aux);
	c1.afisare();
	Companie c2(100.44);
	strcpy(aux, "popescu");
	c2.setnume_companie(aux);
	c2.afisare();
	Companie c3(30.44);
	c3.afisare();




	return 0;

}