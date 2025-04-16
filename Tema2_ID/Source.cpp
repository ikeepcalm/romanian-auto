#include <iostream>
#include <cstring>
#include <string>
#include <utility>

using namespace std;

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor
//Folosirea valorile din teste, doar pentru a le face sa se execute cu succes este considerata frauda

class Autoturism {
private:
    //12. Modificati constructorii astfel incat serieCaroserie
    //sa fie generat unic pe baza campului static
    //campul static fiind comun pentru toate obiectele, poate fi incrementat in constructori
    //iar valoare lui copiata in campul constant serieCaroserie
    //astfel, prima masina va avea serieCaroserie 1, urmatoarea seria 2 s.a.m.d
    //constructorul de copiere va copia valoarea ca atare (dintr-un obiect in altul)
    const int serieCaroserie = 0;
    string marca;
    string model;
    int putere;
    double pret;
    float *distanteParcurse;
    int nrDrumuri; //nr de elemente al vectorului de mai sus
    char *taraDeProductie;
    static int numarAutoturisme;

public:
    //1. Modificati constructorul implicit din clasa Autoturism de mai sus
    //acesta va initializa marca cu "Necunoscuta", modelul cu "Necunoscut"
    //puterea cu 0, pretul cu 5000, vectorul de distante cu NULL si nrDrumuri cu 0
    Autoturism() : serieCaroserie(numarAutoturisme++) {
        this->marca = "Necunoscuta";
        this->model = "Necunoscut";
        this->taraDeProductie = new char[strlen("Necunoscuta") + 1];
        strcpy_s(this->taraDeProductie, strlen("Necunoscuta") + 1, "Necunoscuta");
        this->putere = 0;
        this->pret = 5000;
        this->distanteParcurse = nullptr;
        this->nrDrumuri = 0;
    }

    //2. Modificati constructorul cu 3 parametri: marca, model, putere
    //acesta va initializa cele 3 atribute cu valorile primite
    //restul de atribute nu trebuie sa ramana neinitializate si vor folosi aceleasi valori implicite ca mai sus
    Autoturism(string marca, string model, int putere) : serieCaroserie(numarAutoturisme++) {
        this->marca = std::move(marca);
        this->model = std::move(model);
        this->taraDeProductie = new char[strlen("Necunoscuta") + 1];
        strcpy_s(this->taraDeProductie, strlen("Necunoscuta") + 1, "Necunoscuta");
        this->putere = putere;
        this->pret = 5000;
        this->distanteParcurse = nullptr;
        this->nrDrumuri = 0;
    }

    //3. Modificati constructorul cu 4 parametri pentru a copia valorile
    //primite drept parametri in atributele clasei
    //constructorul nu va lasa atribute neinitializate
    Autoturism(string marca, string model, float *distante, int nrDrumuri) : serieCaroserie(numarAutoturisme++) {
        this->marca = std::move(marca);
        this->model = std::move(model);
        this->taraDeProductie = new char[strlen("Necunoscuta") + 1];
        strcpy_s(this->taraDeProductie, strlen("Necunoscuta") + 1, "Necunoscuta");
        this->putere = 0;
        this->pret = 5000;
        this->distanteParcurse = new float[nrDrumuri];
        this->nrDrumuri = nrDrumuri;
        for (int i = 0; i < nrDrumuri; i++) {
            this->distanteParcurse[i] = distante[i];
        }
    }

    //4. Adaugati un destructor in clasa care sterge zonele de memorie anterior alocate
    //acesta va seta pointerii pe NULL dupa ce face stergerea
    ~Autoturism() {
        if (this->distanteParcurse != nullptr) {
            delete[] this->distanteParcurse;
            this->distanteParcurse = nullptr;
        }

        // delete[] this->marca;
        // this->marca = nullptr;
        // delete[] this->model;
        // this->model = nullptr;

        delete[] this->taraDeProductie;
        this->taraDeProductie = nullptr;
    }

    //5. Adaugati clasei un constructor de copiere astfel incat
    //sa se realizeze o copie in profunzime (deep copy) a obiectelor
    Autoturism(const Autoturism &a) : serieCaroserie(a.serieCaroserie) {
        this->marca = a.marca;
        this->model = a.model;
        this->putere = a.putere;
        this->taraDeProductie = a.taraDeProductie;
        this->pret = a.pret;
        this->nrDrumuri = a.nrDrumuri;
        this->distanteParcurse = new float[a.nrDrumuri];
        if (a.distanteParcurse != nullptr) {
            for (int i = 0; i < a.nrDrumuri; i++) {
                this->distanteParcurse[i] = a.distanteParcurse[i];
            }
        }
    }

    //6. Modificati metodele de acces (getteri si setteri) pentru atributul marca
    //Setterul va accepta denumiri de marci cu o lungime
    //mai mare sau egala de 3 caractere
    //in caz contrar marca ramane cea existenta
    string getMarca() {
        return this->marca;
    }

    void setMarca(string marca) {
        if (marca.length() >= 3) {
            this->marca = marca;
        } else {
            std::cout << "Marca trebuie sa aiba minim 3 caractere!" << std::endl;
        }
    }

    //7. Modificati getter-ul pentru vectorul de distante parcurse
    //Getter-ul va returna o copie a vectorului din clasa
    //Modificati getter-ul si pentru numarul de drumuri
    int getNrDrumuri() {
        return this->nrDrumuri;
    }

    float *getDistanteParcurse() {
        float *copie = new float[this->nrDrumuri];
        for (int i = 0; i < this->nrDrumuri; i++) {
            copie[i] = this->distanteParcurse[i];
        }

        return copie;
    }

    //8. Modificati setter-ul pentru vectorul de distante
    //acesta va modifica simultan vectorul si numarul de elemente
    //si nu va accepta decat vectori nenuli si numar de elemente mai mare decat 0
    void setDistante(float *distanteParcurse, int nrDrumuri) {
        if (nrDrumuri == 0 || distanteParcurse == nullptr) {
            std::cout << "Vectorul de distante nu poate fi null!" << std::endl;
            return;
        }

        this->nrDrumuri = nrDrumuri;
        delete[] this->distanteParcurse;
        this->distanteParcurse = new float[nrDrumuri];
        for (int i = 0; i < nrDrumuri; i++) {
            this->distanteParcurse[i] = distanteParcurse[i];
        }
    }

    //9. Adaugati un camp de tip char* in clasa numit taraDeProductie
    //modificati getter-ul si setter-ul din clasa pentru a returna,
    //respectiv a modifica valoarea acestui camp
    //Metoda AdresaInceputTaraDeProductie intoarce adresa primului element din tara de productie
    //(da, nu e neaparat safe, dar e necesar pentru test)
    //                        +
    //10. Modificati constructorii, destructorul si alte metode necesare
    //astfel incat clasa sa gestioneze corect noul camp
    char *getTaraDeProductie() {
        return this->taraDeProductie;
    }

    void setTaraDeProductie(const char *tara) {
        if (tara != nullptr) {
            delete[] this->taraDeProductie;
            this->taraDeProductie = new char[strlen(tara) + 1];
            strcpy_s(this->taraDeProductie, strlen(tara) + 1, tara);
        } else {
            std::cout << "Tara de productie nu poate fi null!" << std::endl;
        }
    }

    char *AdresaInceputTaraDeProductie() {
        return &this->taraDeProductie[0];
    }

    //11. Modificati supraincarcarea pentru operator=
    //aceasta va realiza o copie in profunzime (deep copy) a obiectelor
    //operatorul accepta apeluri in cascada
    Autoturism operator=(Autoturism a) {
        return Autoturism(a);
    }

    //13. Modificati functia statica calcul_valoare_flota
    //calculati si returnati valoarea totala a flotei de autoturisme
    //prin adunarea preturilor masinilor din flota (vectorul de Autoturisme)
    static double calcul_valoare_flota(Autoturism masini[], int nr_masini) {
        double valoareFlota = 0;
        for (int i = 0; i < nr_masini; i++) {
            valoareFlota += masini[i].pret;
        }
        return valoareFlota;
    }

    //14. Modificati metoda discount pentru a acorda un discount din pret
    //discountul este in procente si poate fi intre 1% si 50% (se face validare)
    //functia modifica pretul cu valoarea sa dupa aplicarea discountului
    void discount(int procent) {
        if (procent < 1 || procent > 50) {
            std::cout << "Discountul trebuie sa fie intre 1% si 50%!" << std::endl;
            return;
        }

        double discount = (this->pret * procent) / 100;
        this->pret -= discount;
        std::cout << "Discount aplicat! Pretul actualizat este: " << this->pret << std::endl;
    }

    int getPutere();

    void setPutere(int putere);

    int getPret();
};

int Autoturism::numarAutoturisme = 0;

int Autoturism::getPutere() {
    return this->putere;
}

void Autoturism::setPutere(int putere) {
    this->putere = putere;
}

int Autoturism::getPret() {
    return this->pret;
}

//15. Functia globala de mai jos primeste drept parametri o matrice
//de pointeri la Autoturism impreuna cu numarul de linii si de coloane
//Matricea reprezinta cum sunt dispuse masinile intr-o parcare
//Un element null inseamna ca pe acel loc de parcare nu este nicio masina
//Functia va returna o matrice a locurilor de parcare astfel

//100 90 60
//0 160 75
//0 90 0

//Explicatii: Parcarea are 3 linii si cate 3 locuri de parcare pe fiecare linie (3 coloane)
//Pe prima linie sunt parcate 3 masini cu putere de 100, 90 si respectiv 60 cai putere
//pe a doua linie primul loc este neocupat, iar urmatoarele doua locuri
//sunt ocupate de doua masini cu 160, respectiv 75 de cai putere, s.a.m.d.
int **locuri_libere(Autoturism ***matrice, int nrLinii, int nrColoane) {
    int **locuri = new int *[nrLinii];
    for (int i = 0; i < nrLinii; i++) {
        locuri[i] = new int[nrColoane];
        for (int j = 0; j < nrColoane; j++) {
            if (matrice[i][j] == nullptr) {
                locuri[i][j] = 0;
            } else {
                locuri[i][j] = matrice[i][j]->getPutere();
            }
        }
    }
    return locuri;
}

int main() {
    std::cout << "Hello World!\n";

    // 1
    Autoturism car1;
    cout << "Constructor implicit: " << car1.getMarca() << ", " << car1.getPutere() << ", " << car1.getTaraDeProductie()
            << endl;

    // 2
    Autoturism car2("Toyota", "Corolla", 120);
    cout << "Constructor explicit: " << car2.getMarca() << ", " << car2.getPutere() << ", " << car2.getTaraDeProductie()
            << endl;

    // 3
    float distante[] = {100.5, 200.0, 300.75};
    Autoturism car3("Honda", "Civic", distante, 3);

    cout << "Constructor complet explicit: " << car3.getMarca() << ", " << car3.getPutere() << ", Distante: ";
    float *copieDistante = car3.getDistanteParcurse();

    for (int i = 0; i < car3.getNrDrumuri(); i++) {
        cout << copieDistante[i] << " ";
    }

    cout << endl;
    delete[] copieDistante;

    // 4
    Autoturism car4 = car3;
    cout << "Copy constructor: " << car4.getMarca() << ", " << car4.getPutere() << ", Distante: ";
    copieDistante = car4.getDistanteParcurse();

    for (int i = 0; i < car4.getNrDrumuri(); i++) {
        cout << copieDistante[i] << " ";
    }

    cout << endl;
    delete[] copieDistante;

    // 5
    car1.setMarca("BMW");
    cout << "Marca noua: " << car1.getMarca() << endl;

    // 6
    car1.setTaraDeProductie("Germany");
    cout << "Tara noua: " << car1.getTaraDeProductie() << endl;

    // 7
    float distanteNou[] = {50.0, 75.0};

    car1.setDistante(distanteNou, 2);
    copieDistante = car1.getDistanteParcurse();

    cout << "Distante nou dupa setter: ";
    for (int i = 0; i < car1.getNrDrumuri(); i++) {
        cout << copieDistante[i] << " ";
    }

    cout << endl;
    delete[] copieDistante;

    // 8
    car2.discount(10);
    cout << "Pret dupa discount: " << car2.getPret() << endl;

    // 9
    Autoturism cars[] = {car1, car2, car3};
    cout << "Valoare flota: " << Autoturism::calcul_valoare_flota(cars, 3) << endl;

    // 10
    Autoturism ***parcare = new Autoturism **[2];
    for (int i = 0; i < 2; i++) {
        parcare[i] = new Autoturism *[2];
    }
    parcare[0][0] = &car1;
    parcare[0][1] = &car2;
    parcare[1][0] = nullptr;
    parcare[1][1] = &car3;

    int **matriceaLocurilor = locuri_libere(parcare, 2, 2);
    cout << "Matricea cu locuri libere:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriceaLocurilor[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete[] matriceaLocurilor[i];
        delete[] parcare[i];
    }
    delete[] matriceaLocurilor;
    delete[] parcare;

    return 0;
}
