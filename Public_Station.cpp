#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Klasa bazowa - abstrakcyjna
class Material {
private:
    static int nextId;
    int id;

public:
    Material() : id(nextId++) {}
    virtual void wyswietlInfo() const = 0;
    int getId() const { return id; }
    virtual ~Material() {}
};

int Material::nextId = 1;

class Obudowa : public Material {
public:
    string rodzaj;
    string typ;
    string oddzial;
    int ilosc;

    Obudowa(const string& r, const string& t, const string& o, int i)
        : rodzaj(r), typ(t), oddzial(o), ilosc(i) {}

    void wyswietlInfo() const override {
        cout << "ID: " << getId() << " | Obudowa | Rodzaj: " << rodzaj 
             << " | Typ: " << typ << " | Oddzial: " << oddzial 
             << " | Ilosc: " << ilosc << endl;
    }
};

class Drewno : public Material {
public:
    string rodzaj;
    string typ;
    string oddzial;
    int ilosc;

    Drewno(const string& r, const string& t, const string& o, int i)
        : rodzaj(r), typ(t), oddzial(o), ilosc(i) {}

    void wyswietlInfo() const override {
        cout << "ID: " << getId() << " | Drewno | Rodzaj: " << rodzaj 
             << " | Typ: " << typ << " | Oddzial: " << oddzial 
             << " | Ilosc: " << ilosc << endl;
    }
};

class ElementyKonstrukcji : public Material {
public:
    string rodzaj;
    string typ;
    string oddzial;
    int ilosc;

    ElementyKonstrukcji(const string& r, const string& t, const string& o, int i)
        : rodzaj(r), typ(t), oddzial(o), ilosc(i) {}

    void wyswietlInfo() const override {
        cout << "ID: " << getId() << " | Elementy konstrukcji | Rodzaj: " << rodzaj 
             << " | Typ: " << typ << " | Oddzial: " << oddzial 
             << " | Ilosc: " << ilosc << endl;
    }
};

class StacjaMaterialowa {
    private:
        vector<Material*> materialy;
    
    public:
        void dodajMaterial(Material* material) {
            materialy.push_back(material);
        }
    
        void usunMaterialPoId(int id) {
            auto it = find_if(materialy.begin(), materialy.end(), [id](Material* material) {
                return material->getId() == id;
            });
    
            if (it != materialy.end()) {
                delete *it;  // Usuwamy materiał z pamięci
                materialy.erase(it);  // Usuwamy wskaźnik z listy
                cout << "Material o ID " << id << " zostal usuniety." << endl;
            } else {
                cout << "Material o ID " << id << " nie zostal znaleziony." << endl;
            }
        }
    
        void wyswietlMaterialy() const {
            if (materialy.empty()) {
                cout << "Brak materialow w magazynie." << endl;
                return;
            }
    
            for (const auto& material : materialy) {
                material->wyswietlInfo();
            }
        }
    
        Material* znajdzMaterialPoId(int id) {
            auto it = find_if(materialy.begin(), materialy.end(), [id](Material* material) {
                return material->getId() == id;
            });
    
            return (it != materialy.end()) ? *it : nullptr;
        }
    };
    

void wyswietlOddzialy() {
    cout << "Wybierz oddzial:" << endl;
    cout << "1. GRP" << endl;
    cout << "2. G" << endl;
    cout << "3. GZL" << endl;
    cout << "4. WW" << endl;
    cout << "5. GT" << endl;
    cout << "6. MD" << endl;
    cout << "7. ED" << endl;
}

void wyswietlOddzialGRP() {
    cout << "Wybierz pododdzial GRP:" << endl;
    cout << "1. GRP-1" << endl;
    cout << "2. GRP-2" << endl;
    cout << "3. GRP-3" << endl;
}

void wyswietlOddzialG() {
    cout << "Wybierz pododdzial G:" << endl;
    cout << "1. G1" << endl;
    cout << "2. G2" << endl;
    cout << "3. G3" << endl;
}

void wyswietlOddzialGZL() {
    cout << "Wybierz pododdzial GZL:" << endl;
    cout << "1. GZL-1" << endl;
    cout << "2. GZL-2" << endl;
}

void wyswietlOddzialWW() {
    cout << "Wybierz pododdzial WW:" << endl;
    cout << "1. WW" << endl;
}

void wyswietlOddzialGT() {
    cout << "Wybierz pododdzial GT:" << endl;
    cout << "1. GTK" << endl;
    cout << "2. GTD" << endl;
    cout << "3. GTU" << endl;
}

void wyswietlOddzialMD() {
    cout << "Wybierz pododdzial MD:" << endl;
    cout << "1. MD-1" << endl;
    cout << "2. MD-2" << endl;
    cout << "3. MD-3" << endl;
}

void wyswietlOddzialED() {
    cout << "Wybierz pododdzial ED:" << endl;
    cout << "1. ED-1" << endl;
    cout << "2. ED-2" << endl;
    cout << "3. ED-3" << endl;
}

int main() {
    StacjaMaterialowa stacja;
    string rodzaj, typ, oddzial;
    int ilosc, wybor, oddzialWybor, pododdzialWybor;

    do {
        cout << "Wybierz opcje:" << endl;
        cout << "1. Dodaj material" << endl;
        cout << "2. Wyswietl materialy" << endl;
        cout << "3. Znajdz material po ID" << endl;
        cout << "4. Zakonczenie" << endl;
        cin >> wybor;

        switch (wybor) {
            case 1: {
                cout << "Wybierz material: " << endl;
                cout << "1. Obudowa" << endl;
                cout << "2. Drewno" << endl;
                cout << "3. Elementy konstrukcji" << endl;
                int typMaterialu;
                cin >> typMaterialu;

                cout << "Podaj rodzaj materialu: ";
                cin.ignore();
                getline(cin, rodzaj);

                cout << "Podaj typ kontenera: ";
                getline(cin, typ);

                wyswietlOddzialy();
                cout << "Wybierz numer oddzialu: ";
                cin >> oddzialWybor;

                switch (oddzialWybor) {
                    case 1:
                        wyswietlOddzialGRP();
                        cout << "Wybierz numer pododdzialu: ";
                        cin >> pododdzialWybor;
                        if (pododdzialWybor == 1) oddzial = "GRP-1";
                        else if (pododdzialWybor == 2) oddzial = "GRP-2";
                        else if (pododdzialWybor == 3) oddzial = "GRP-3";
                        break;
                    case 2:
                        wyswietlOddzialG();
                        cout << "Wybierz numer pododdzialu: ";
                        cin >> pododdzialWybor;
                        if (pododdzialWybor == 1) oddzial = "G1";
                        else if (pododdzialWybor == 2) oddzial = "G2";
                        else if (pododdzialWybor == 3) oddzial = "G3";
                        break;
                    case 3:
                        wyswietlOddzialGZL();
                        cout << "Wybierz numer pododdzialu: ";
                        cin >> pododdzialWybor;
                        if (pododdzialWybor == 1) oddzial = "GZL-1";
                        else if (pododdzialWybor == 2) oddzial = "GZL-2";
                        break;
                    case 4:
                        oddzial = "WW";
                        break;
                    case 5:
                        wyswietlOddzialGT();
                        cout << "Wybierz numer pododdzialu: ";
                        cin >> pododdzialWybor;
                        if (pododdzialWybor == 1) oddzial = "GTK";
                        else if (pododdzialWybor == 2) oddzial = "GTD";
                        else if (pododdzialWybor == 3) oddzial = "GTU";
                        break;
                    case 6:
                        wyswietlOddzialMD();
                        cout << "Wybierz numer pododdzialu: ";
                        cin >> pododdzialWybor;
                        if (pododdzialWybor == 1) oddzial = "MD-1";
                        else if (pododdzialWybor == 2) oddzial = "MD-2";
                        else if (pododdzialWybor == 3) oddzial = "MD-3";
                        break;
                    case 7:
                        wyswietlOddzialED();
                        cout << "Wybierz numer pododdzialu: ";
                        cin >> pododdzialWybor;
                        if (pododdzialWybor == 1) oddzial = "ED-1";
                        else if (pododdzialWybor == 2) oddzial = "ED-2";
                        else if (pododdzialWybor == 3) oddzial = "ED-3";
                        break;
                    default:
                        cout << "Niepoprawny wybor oddzialu!" << endl;
                        break;
                }

                cout << "Podaj ilosc materialu: ";
                cin >> ilosc;

                Material* nowyMaterial = nullptr;
                if (typMaterialu == 1) {
                    nowyMaterial = new Obudowa(rodzaj, typ, oddzial, ilosc);
                } else if (typMaterialu == 2) {
                    nowyMaterial = new Drewno(rodzaj, typ, oddzial, ilosc);
                } else if (typMaterialu == 3) {
                    nowyMaterial = new ElementyKonstrukcji(rodzaj, typ, oddzial, ilosc);
                } else {
                    cout << "Niepoprawny wybor rodzaju materialu!" << endl;
                    break;
                }

                stacja.dodajMaterial(nowyMaterial);
                cout << "Material dodany! ID: " << nowyMaterial->getId() << endl;
                break;
            }

            case 2:
                cout << "Aktualny magazyn: " << endl;
                stacja.wyswietlMaterialy();
                
                // Dodajemy interakcję po wyświetleniu materiałów
                int opcja;
                cout << "Wybierz opcje: " << endl;
                cout << "1. Usun material" << endl;
                cout << "2. Wroc do menu" << endl;
                cin >> opcja;

                if (opcja == 1) {
                    int id;
                    cout << "Podaj ID materialu do usuniecia: ";
                    cin >> id;
                    stacja.usunMaterialPoId(id);  // Wywołanie funkcji usuwania
                }
                break;

            case 3: {
                int id;
                cout << "Podaj ID materialu do znalezienia: ";
                cin >> id;
                Material* znaleziony = stacja.znajdzMaterialPoId(id);
                if (znaleziony) {
                    cout << "Znaleziony material: " << endl;
                    znaleziony->wyswietlInfo();
                } else {
                    cout << "Nie znaleziono materialu o ID " << id << endl;
                }
                break;
            }

            case 4:
                cout << "Zakonczenie programu." << endl;
                break;

            default:
                cout << "Niepoprawna opcja. Sprobuj ponownie." << endl;
        }

    } while (wybor != 4);

    return 0;
}

