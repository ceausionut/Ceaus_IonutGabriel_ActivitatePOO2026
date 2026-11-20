#define _CRT_SECURITY_NO_WARNING
#include <iostream>
#include <string>
using namespace std;
enum gen { masculin = 1, feminim = 2, nespecificat = 3 };
class Vapor {
private :
	const int id;
	int capacitate;
	int persoane_imbarcate;
	int* varstaPasageri;
	gen gender;

public :
	static int contor;
	Vapor() :id(contor++) {
		this->capacitate = 0;
		this->persoane_imbarcate = 0;
		this->varstaPasageri = nullptr;
		this->gender = nespecificat;

	}
	Vapor(int capacitate, int persoane_imbarcate, int* varstaPasageri, gen gender):id(contor++) {
		if (capacitate >= 0) {
			this->capacitate = capacitate;
		}
		else {
			this->capacitate = 0;
		}
		if (persoane_imbarcate >= 0) {
			this->persoane_imbarcate = persoane_imbarcate;
		}
		else {
			this->persoane_imbarcate = 0;
		}
		if (persoane_imbarcate > capacitate) {
			this->persoane_imbarcate = capacitate;
			persoane_imbarcate = capacitate;
		}
		this->gender = gender;
		this->varstaPasageri = nullptr;
		if (varstaPasageri != nullptr && persoane_imbarcate > 0) {
			this->varstaPasageri = new int[persoane_imbarcate];
			
			for (int i = 0; i < this->persoane_imbarcate; i++) {
				this->varstaPasageri[i] = varstaPasageri[i];
			}
		}
		else {
			this->varstaPasageri = nullptr;
	
		}
		

	}
	Vapor(const Vapor& copie) :id(contor++) {
		this->capacitate = copie.capacitate;
		this->persoane_imbarcate = copie.persoane_imbarcate;
		this->gender = copie.gender;
		
			this->varstaPasageri = nullptr;
		if (copie.varstaPasageri != nullptr && copie.persoane_imbarcate > 0) {
			this->varstaPasageri = new int[copie.persoane_imbarcate];
			for (int i = 0; i < copie.persoane_imbarcate; i++) {
				this->varstaPasageri[i] = copie.varstaPasageri[i];
			}

		}
		else {
			this->varstaPasageri = nullptr;
		}


	}
	gen getgender() {
		return this->gender;
	}
	int* getvarstapasager() {
		if (this->varstaPasageri != nullptr && persoane_imbarcate > 0) {
			int* varstaPasageri = new int[this->persoane_imbarcate];
			for (int i = 0; i < this->persoane_imbarcate; i++) {
				varstaPasageri[i] = this->varstaPasageri[i];
			}
			return varstaPasageri;
		}
		else {
			return nullptr;
		}
		delete[] varstaPasageri;
	}
	void setcapacitate(int capacitate) {
		this->capacitate = capacitate;
	}
	void operator=(const Vapor& copie) {
		if (copie.capacitate >= 0) {
			this->capacitate = copie.capacitate;
		}
		else {
			this->capacitate = 0;
		}
		if (copie.persoane_imbarcate >= 0) {
			this->persoane_imbarcate = copie.persoane_imbarcate;
		}
		else {
			this->persoane_imbarcate = 0;
		}
		if (copie.persoane_imbarcate > copie.capacitate) {
			this->persoane_imbarcate = copie.capacitate;
			this->persoane_imbarcate = copie.capacitate;
		}
		this->gender = copie.gender;
		if (this->varstaPasageri != nullptr) {
			delete[] this->varstaPasageri;
			this->varstaPasageri = nullptr;
		}
		if (copie.varstaPasageri != nullptr && copie.persoane_imbarcate > 0) {
			this->varstaPasageri = new int[copie.persoane_imbarcate];

			for (int i = 0; i < copie.persoane_imbarcate; i++) {
				this->varstaPasageri[i] = copie.varstaPasageri[i];
			}
		}
		else {
			this->varstaPasageri = nullptr;

		}

	}
	int operator()(){

		return this->capacitate - this->persoane_imbarcate;

	}

	friend void operator <<(ostream& out, Vapor copie) {
		out << endl << copie.id << endl;
		out << endl << copie.capacitate << endl;
		out << endl << copie.persoane_imbarcate << endl;
		if (copie.varstaPasageri != nullptr) {
			for (int i = 0; i < copie.persoane_imbarcate; i++) {
				out << copie.varstaPasageri[i] << " ";
			}
		}
		if (copie.gender == 1) {
			out << endl << "gender masculin";
		}
		if (copie.gender == 2) {
			out << endl << "gender feminin";
		}
		if (copie.gender == 3) {
			out << endl << "gender nespecificat";
		}
		



	}

	~Vapor() {
		if (this->varstaPasageri != nullptr) {
			delete[] this->varstaPasageri;
		}

	}


};
int Vapor::contor = 1;
int main() {
	Vapor uno;
	int varste[3] = { 2, 3, 4 };
	Vapor due(10, 3,varste, masculin);
	Vapor tre = due;
	cout << tre.getvarstapasager();
	cout << tre;
	cout << "locuri ramase:" << tre();


	return 0;

}