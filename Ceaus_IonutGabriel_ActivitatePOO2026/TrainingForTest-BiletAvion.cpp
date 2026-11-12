#include <iostream>
#include <string>

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

    // NOTA 4: Constructor cu 2 parametri (numePasager si durataZbor, in aceasta ordine) + validari
    BiletAvion(string numePasager, int durataZbor) : numarBilet(++nrBilet) {
        if (numePasager.empty()) {
            this->numePasager = "Necunoscut";
        }
        else {
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

    // NOTA 4: Destructor fara memory leaks
    ~BiletAvion() {
        if (this->distante != nullptr) {
            delete[] this->distante;
        }
    }

    // NOTA 5: Constructor de copiere
    BiletAvion(const BiletAvion& copie) : numarBilet(++nrBilet) {
        this->numePasager = copie.numePasager;
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
    BiletAvion b1("Ionut", 4);

    // Testare setDistante (Nota 5)
    double traseu[] = { 450.5, 1200.0, 320.5 };
    b1.setDistante(traseu, 3);

    // Testare constructor de copiere (Nota 5)
    BiletAvion b2 = b1;

    b1.afisare();
    b2.afisare();

    return 0;
}