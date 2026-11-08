#include <iostream>
#include <string>

using namespace std;

enum TipLibrarie { ONLINE = 1, FIZICA = 2 };

class Librarie {
private:
    const int id;
    TipLibrarie tip;
    string denumire;
    float cifraAfaceri;
    int nrCarti;
    float* preturi; // vector alocat dinamic

public:
    static int nrLibrarii;

    // 1. Constructor fara parametri (default)
    Librarie() : id(++nrLibrarii) {
        this->denumire = "Librarie Generala";
        this->cifraAfaceri = 0.0f;
        this->tip = ONLINE;
        this->nrCarti = 0;
        this->preturi = nullptr;
    }

    // 2. Constructor cu toti parametrii
    Librarie(int idPersonalizat, string denumire, float cifraAfaceri, int nrCarti, const float* preturiInitiale, TipLibrarie tip)
        : id(idPersonalizat) {
        nrLibrarii++;
        this->denumire = denumire;
        this->cifraAfaceri = cifraAfaceri;
        this->tip = tip;
        this->nrCarti = nrCarti;

        if (this->nrCarti > 0 && preturiInitiale != nullptr) {
            this->preturi = new float[this->nrCarti];
            for (int i = 0; i < this->nrCarti; i++) {
                this->preturi[i] = preturiInitiale[i];
            }
        }
        else {
            this->nrCarti = 0;
            this->preturi = nullptr;
        }
    }

    // 3. Constructor de copiere (Deep Copy)
    Librarie(const Librarie& copie) : id(++nrLibrarii) {
        this->denumire = copie.denumire;
        this->cifraAfaceri = copie.cifraAfaceri;
        this->tip = copie.tip;
        this->nrCarti = copie.nrCarti;

        if (copie.preturi != nullptr && copie.nrCarti > 0) {
            this->preturi = new float[this->nrCarti];
            for (int i = 0; i < this->nrCarti; i++) {
                this->preturi[i] = copie.preturi[i];
            }
        }
        else {
            this->preturi = nullptr;
        }
    }

    // Operator de atribuire (operator=)
    Librarie& operator=(const Librarie& copie) {
        if (this != &copie) { // Protectie la auto-atribuire
            this->denumire = copie.denumire;
            this->cifraAfaceri = copie.cifraAfaceri;
            this->tip = copie.tip;
            this->nrCarti = copie.nrCarti;

            if (this->preturi != nullptr) {
                delete[] this->preturi;
                this->preturi = nullptr;
            }

            if (copie.preturi != nullptr && copie.nrCarti > 0) {
                this->preturi = new float[this->nrCarti];
                for (int i = 0; i < this->nrCarti; i++) {
                    this->preturi[i] = copie.preturi[i];
                }
            }
            else {
                this->preturi = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    ~Librarie() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
            this->preturi = nullptr;
        }
    }

    // Getters si Setters
    int getId() const {
        return this->id;
    }

    string getDenumire() const {
        return this->denumire;
    }

    void setDenumire(string nouaDenumire) {
        if (nouaDenumire.length() > 2) {
            this->denumire = nouaDenumire;
        }
    }

    int getNrCarti() const {
        return this->nrCarti;
    }

    float* getPreturi() const {
        if (this->nrCarti == 0 || this->preturi == nullptr) {
            return nullptr;
        }
        float* copiePreturi = new float[this->nrCarti];
        for (int i = 0; i < this->nrCarti; i++) {
            copiePreturi[i] = this->preturi[i];
        }
        return copiePreturi;
    }

    void setPreturi(const float* noiPreturi, int noulNr) {
        if (noulNr < 0) {
            throw invalid_argument("Numarul de carti nu poate fi negativ!");
        }

        if (this->preturi != nullptr) {
            delete[] this->preturi;
            this->preturi = nullptr;
        }

        this->nrCarti = noulNr;
        if (noiPreturi != nullptr && this->nrCarti > 0) {
            this->preturi = new float[this->nrCarti];
            for (int i = 0; i < this->nrCarti; i++) {
                this->preturi[i] = noiPreturi[i];
            }
        }
        else {
            this->preturi = nullptr;
        }
    }

    // Supraincarcare operatori
    bool operator<(const Librarie& l) const {
        return this->nrCarti < l.nrCarti;
    }

    void operator+=(float valoareAdaugata) {
        this->cifraAfaceri += valoareAdaugata;
    }

    bool operator!() const {
        return this->cifraAfaceri > 0;
    }

    float operator()(float bonusVanzari) const {
        return this->cifraAfaceri + bonusVanzari;
    }

    float& operator[](int index) {
        if (index >= 0 && index < this->nrCarti) {
            return this->preturi[index];
        }
        throw out_of_range("Index in afara limitelor!");
    }

    // Post-incrementare (ob++)
    Librarie operator++(int) {
        Librarie copie = *this;
        this->cifraAfaceri += 1.0f;
        return copie;
    }

    // Pre-incrementare (++ob)
    Librarie& operator++() {
        this->cifraAfaceri += 1.0f;
        return *this;
    }

    // Cast explicit la int
    explicit operator int() const {
        return this->nrCarti;
    }

    // Functii prietene pentru fluxuri
    friend ostream& operator<<(ostream& out, const Librarie& l);
    friend istream& operator>>(istream& in, Librarie& l);
};

int Librarie::nrLibrarii = 0;

ostream& operator<<(ostream& out, const Librarie& l) {
    out << "\n--- Librarie ID [" << l.id << "] ---";
    out << "\nDenumire: " << l.denumire;
    out << "\nCifra afaceri: " << l.cifraAfaceri << " RON";
    out << "\nTip: " << (l.tip == ONLINE ? "ONLINE" : "FIZICA");
    out << "\nNumar titluri: " << l.nrCarti;
    if (l.preturi != nullptr && l.nrCarti > 0) {
        out << "\nLista preturi: ";
        for (int i = 0; i < l.nrCarti; i++) {
            out << l.preturi[i] << (i == l.nrCarti - 1 ? " RON." : " RON, ");
        }
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, Librarie& l) {
    cout << "\nIntroduceti denumirea: ";
    in >> l.denumire;

    cout << "Cifra afaceri: ";
    in >> l.cifraAfaceri;

    cout << "Tip (1 = ONLINE, 2 = FIZICA): ";
    int tipInt;
    in >> tipInt;
    l.tip = (tipInt == 1) ? ONLINE : FIZICA;

    cout << "Numar carti: ";
    in >> l.nrCarti;

    if (l.preturi != nullptr) {
        delete[] l.preturi;
        l.preturi = nullptr;
    }

    if (l.nrCarti > 0) {
        l.preturi = new float[l.nrCarti];
        for (int i = 0; i < l.nrCarti; i++) {
            cout << "Pret carte [" << i << "]: ";
            in >> l.preturi[i];
        }
    }
    return in;
}

int main() {
    Librarie librarieDefault;
    cout << librarieDefault;

    float preturiInit[] = { 45.5f, 89.0f, 32.5f, 120.0f };
    Librarie librarieCarturesti(101, "Carturesti", 500000.0f, 4, preturiInit, FIZICA);

    cout << librarieCarturesti;

    // Testare operatori
    librarieCarturesti += 250.0f;
    librarieCarturesti[0] = 50.0f; // index operator

    cout << "\nNoul pret pentru primul produs: " << librarieCarturesti[0] << " RON";

    // Testare comparator
    if (librarieDefault < librarieCarturesti) {
        cout << "\nLibraria Carturesti are un stoc mai diversificat.";
    }

    // Testare incrementari
    Librarie lCopie = librarieCarturesti++;
    cout << "\nDupa post-incrementare:";
    cout << "\nCifra afaceri veche: " << (float)lCopie(0);
    cout << "\nCifra afaceri actuala: " << (float)librarieCarturesti(0);

    // Cast la int
    cout << "\nNumar de carti via cast explicit: " << int(librarieCarturesti);
    cout << "\nTotal instante create: " << Librarie::nrLibrarii << endl;

    return 0;
}