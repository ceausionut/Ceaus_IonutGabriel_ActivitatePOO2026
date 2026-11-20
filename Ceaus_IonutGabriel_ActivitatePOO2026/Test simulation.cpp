//#define _crt_secure_no_warnings
//#include <iostream>
//#include <string>
//
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
//	companie() :id(contor++) {
//		this->cifra_afaceri = 0.0;
//		this->nume_companie = nullptr;
//	}
//
//	companie(char* nume_companie) :id(contor++) {
//		if (nume_companie != nullptr) {
//			this->nume_companie = new char[strlen(nume_companie) + 1];
//			strcpy(this->nume_companie, nume_companie);
//		}
//		else {
//			this->nume_companie = nullptr;
//
//		}
//		this->cifra_afaceri = 0.0;
//	}
//	companie(const companie& copie) :id(contor++) {
//		this->cifra_afaceri = copie.cifra_afaceri;
//		if (copie.nume_companie != nullptr) {
//			this->nume_companie = new char[strlen(copie.nume_companie) + 1];
//			strcpy(this->nume_companie, copie.nume_companie);
//		}
//		else {
//			this->nume_companie = nullptr;
//		}
//
//	}
//	double getcifra_afaceri() {
//		return this->cifra_afaceri;
//	}
//	int getid() {
//		return this->id;
//	}
//	void setnume_companie(char* nume_companie) {
//		if (this->nume_companie != nullptr) {
//			delete[] this->nume_companie;
//			this->nume_companie = nullptr;
//		}
//		if (nume_companie != nullptr) {
//			this->nume_companie = new char[strlen(nume_companie) + 1];
//			strcpy(this->nume_companie, nume_companie);
//		}
//		else {
//			this->nume_companie = nullptr;
//		}
//
//	}
//	void operator= (const companie& copie) {
//		if (this->nume_companie != nullptr) {
//			delete[] this->nume_companie;
//			this->nume_companie = nullptr;
//		}
//		if (copie.nume_companie != nullptr) {
//			this->nume_companie = new char[strlen(copie.nume_companie) + 1];
//			strcpy(this->nume_companie, copie.nume_companie);
//		}
//		else {
//			this->nume_companie = nullptr;
//		}
//		this->cifra_afaceri = copie.cifra_afaceri;
//
//	}
//
//	void afisare() {
//		cout << endl << "id :" << this->id;
//		if (this->nume_companie != nullptr) {
//			cout << endl << "nume companie: ";
//			for (int i = 0; i < (strlen(this->nume_companie)); i++)
//			{
//				cout << this->nume_companie[i];
//			}
//		}
//		else cout << endl << "nume companie : anonim ";
//		cout << endl << "cifra afaceri: " << this->cifra_afaceri;
//	}
//
//	friend void operator << (ostream& out, companie c) {
//		out << endl << "id: " << c.id << " ";
//		out << "cifra afacere: " << c.cifra_afaceri << " ";
//		if (c.nume_companie != nullptr) {
//			out << "nume companie: ";
//			for (int i = 0; i < strlen(c.nume_companie); i++) {
//				out << c.nume_companie[i];
//
//			}
//		}
//		else {
//			out << " nume companie anonim";
//		}
//	}
//		
//	
//	~companie() {
//		if (this->nume_companie != nullptr) {
//			delete[] this->nume_companie;
//		}
//	}
//};
//int companie::contor = 1;
//int main() {
//	companie oracle;
//	char* nume1 = new char[strlen("gigelescu") + 1];
//	strcpy(nume1, "gigelescu");
//	oracle.setnume_companie(nume1);
//	cout << oracle;
//	delete[] nume1;
//	return 0;
//}