//#define _crt_secure_no_warnings
//#include <iostream>
//#include <string>
//using namespace std;
//
//class companie {
//private:
//	const int id;
//	char* nume_companie;
//	double cifra_afaceri;
//
//public:
//	static int contor;
//
//	companie() :id(0){
//		this->cifra_afaceri = 0.0;
//		this->nume_companie = nullptr;
//	}
//
//	companie(double cifra_afaceri) :id(contor++){
//		this->nume_companie = nullptr;
//		this->cifra_afaceri = cifra_afaceri;
//	}
//	int getid() {
//		return this->id;
//	}
//	void setnume_companie(const char* nume_companie) {
//		if (nume_companie != nullptr) {
//			delete[] this->nume_companie;
//			this->nume_companie = new char[strlen(nume_companie) + 1];
//			strcpy(this->nume_companie, nume_companie);
//
//
//		}
//	}
//	bool operator<(const companie& copie) {
//		return this->cifra_afaceri < copie.cifra_afaceri;
//	}
//
//	void operator+=(double vanzari_adaugate){
//		 this->cifra_afaceri += vanzari_adaugate;
//	}
//
//	void operator=(const companie& copie) {
//		if (this != &copie) { // pas 1: dacă scrii din greșeală c1 = c1, nu face nimic
//
//			// pas 2: copiem cifra de afaceri din c2 în c1
//			this->cifra_afaceri = copie.cifra_afaceri;
//
//			// pas 3: dacă c1 avea deja un nume scris în memorie, îl ștergem ca să nu rămână gunoi în ram
//			if (this->nume_companie != nullptr) {
//				delete[] this->nume_companie;
//				this->nume_companie = nullptr;
//			}
//
//			// pas 4: dacă c2 are un nume, îi facem lui c1 propria lui zonă de memorie și copiem literele acolo
//			if (copie.nume_companie != nullptr) {
//				this->nume_companie = new char[strlen(copie.nume_companie) + 1];
//				strcpy(this->nume_companie, copie.nume_companie);
//			}
//		}
//	}
//	char& operator[](int index) {
//		if (nume_companie != nullptr && index >= 0 && index < strlen(this->nume_companie)) {
//			return this->nume_companie[index];
//		}
//
//		else {
//			throw exception();
//
//		}
//	}
//	~companie() {
//		if(nume_companie != nullptr) {
//			delete[] this->nume_companie;
//		}
//	}
//		void afisare() {
//			cout << endl << this->id;
//			cout << endl << this->cifra_afaceri ;
//			if (this->nume_companie != nullptr) {
//				cout << endl;
//				for (int i = 0; i < strlen(this->nume_companie); i++) {
//					cout << this->nume_companie[i];
//				}
//			}
//			else {
//				cout << endl << "companie fara nume";
//			}
//
//		
//	}
//};
//
//int companie::contor = 1;
//int main() {
//	companie c1;
//	c1.setnume_companie("sortescu");
//	c1.afisare();
//	companie c2(100.44);
//	c2.setnume_companie("gigelescu");
//	c2.afisare();
//	companie c3(30.44);
//	c3.setnume_companie("popescu");
//	c3.afisare();
//	cout << endl << "id-ul lui c3 este :" << c3.getid();
//	/*c1 = c3;
//	c2 = c3;*/
//	c1.afisare();
//	c2.afisare();
//	c3.afisare();
//	c3 += 230.22;
//	if (c3 < c2) {
//		cout << endl << "cifra afaceri c3 este mai mica de cat c2";
//	}
//	else {
//		cout << endl << "cifra afaceri c2 este mai mica de cat c3";
//	}
//
//	c3.afisare();
//	cout << endl << c3[2];
//
//
//
//	return 0;
//
//}