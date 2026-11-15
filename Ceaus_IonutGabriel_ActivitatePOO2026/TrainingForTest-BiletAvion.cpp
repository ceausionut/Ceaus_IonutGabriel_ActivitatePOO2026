#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class BiletAvion {
private:
    const int numarBilet;
    char* numePasager;
    int durataZbor;
    double* distante;
    int numarSegmente;

public:
    static int nrBilet;

    // NOTA 4: Constructor cu 2 parametri (numePasager si durataZbor, in aceasta ordine) + validari
    BiletAvion(char* numePasager, int durataZbor) : numarBilet(++nrBilet) {
        if (numePasager != nullptr && strlen(numePasager) > 0) {
            this->numePasager = new char[strlen(numePasager) + 1];
            strcpy(this->numePasager,numePasager);
        }
        else {
            this->numePasager = new char[strlen("anonim") + 1];
            strcpy(this->numePasager,"anonim");
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

    // NOTA 4: Destructor fara memory leaks
    ~BiletAvion() {
        if (this->distante != nullptr) {
            delete[] this->distante;
        }
        if (this->numePasager != nullptr) {

            delete[] this->numePasager;
        }
    }

    // NOTA 5: Constructor de copiere
    BiletAvion(const BiletAvion& copie) : numarBilet(++nrBilet) {
        if (copie.numePasager != nullptr && strlen(copie.numePasager) > 0) {
            this->numePasager = new char [strlen(copie.numePasager) + 1];
            strcpy(this->numePasager, copie.numePasager);
        }
        else {
            this->numePasager = new char[strlen("Anonim") + 1];
            strcpy(this->numePasager, "Anonim");
        }
        this->durataZbor = copie.durataZbor;
        this->numarSegmente = copie.numarSegmente;

        if (copie.distante != nullptr && copie.numarSegmente > 0) {
            this->distante = new double[this->numarSegmente];
            for (int i = 0; i < this->numarSegmente; i++) {
                this->distante[i] = copie.distante[i];
            }
        }
        else {
            this->distante = nullptr;
        }
    }

    void operator=(const BiletAvion& copie) {
        if (this != &copie) {
            if (this->numePasager != nullptr) {
                delete[] this->numePasager;
                this->numePasager = nullptr;
            }
            if (this->distante != nullptr) {
                delete[] this->distante;
                this->distante = nullptr;
            }

            if (copie.numePasager != nullptr && strlen(copie.numePasager) > 0) {
                this->numePasager = new char[strlen(copie.numePasager) + 1];
                strcpy(this->numePasager, copie.numePasager);
            }
            else {
                this->numePasager = new char[strlen("Anonim") + 1];
                strcpy(this->numePasager,"Anonim");
            }
            this->durataZbor = copie.durataZbor;
            this->numarSegmente = copie.numarSegmente;


            if (copie.distante != nullptr && copie.numarSegmente > 0) {
                this->distante = new double[copie.numarSegmente];
                for (int i = 0; i < copie.numarSegmente; i++) {
                    this->distante[i] = copie.distante[i];
                }
            }
            else {
                this->distante = nullptr;
            }
        }
    }

    // NOTA 5: Setter setDistante cu validari (distante > 0, numarSegmente > 0)
    void setDistante(double* distanteNoi, int numarSegmenteNoi) {
        if (distanteNoi != nullptr && numarSegmenteNoi > 0) {
            // Verificam ca toate distantele sa fie strict mai mari decat 0
            bool toatePozitive = true;
            for (int i = 0; i < numarSegmenteNoi; i++) {
                if (distanteNoi[i] <= 0) {
                    toatePozitive = false;
                    break;
                }
            }

            if (toatePozitive) {
                if (this->distante != nullptr) {
                    delete[] this->distante;
                }

                this->numarSegmente = numarSegmenteNoi;
                this->distante = new double[this->numarSegmente];

                for (int i = 0; i < this->numarSegmente; i++) {
                    this->distante[i] = distanteNoi[i];
                }
            }
        }
    }

    // Metoda ajutatoare pentru afisare in main
    void afisare() {
        cout << endl << "Numar bilet: " << this->numarBilet;
        cout << endl << "Nume pasager: " << this->numePasager;
        cout << endl << "Durata zbor: " << this->durataZbor;
        cout << endl << "Numar segmente: " << this->numarSegmente;
        cout << endl << "Distante: ";
        if (this->distante != nullptr && this->numarSegmente > 0) {
            for (int i = 0; i < this->numarSegmente; i++) {
                cout << this->distante[i] << " ";
            }
        }
        else {
            cout << "Niciun segment";
        }
        cout << endl;
    }
};

int BiletAvion::nrBilet = 0;

int main() {
    // Testare constructor cu parametri (Nota 4)
    char* a = new char[strlen("ionut")+1];
    strcpy(a, "ionut");
    BiletAvion b1 (a, 4);

    // Testare setDistante (Nota 5)
    double traseu[] = { 450.5, 1200.0, 320.5 };
    b1.setDistante(traseu, 3);

    // Testare constructor de copiere (Nota 5)
    BiletAvion b2 = b1;

    b1.afisare();
    b2.afisare();
    delete[] a;

    return 0;
}