#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Material {
public:
    string nazwa;
    string typ;
    string oddzial;
    int ilosc;
    string lokalizacja;

    Material(string n, string t, string o, int i, string l)
        : nazwa(n), typ(t), oddzial(o), ilosc(i), lokalizacja(l) {}

    void wyswietlInfo() const {
        cout << "Material: " << nazwa << " | Typ: " << typ << " | Oddzial: " << oddzial << " | Ilosc: " << ilosc << " | Lokalizacja: " << lokalizacja << endl;
    }
};

class StacjaMaterialowa {
private:
    vector<Material> materialy;
public:
    void dodajMaterial(const Material& m) {
        materialy.push_back(m);
    }

    void wyswietlMaterialy() const {
        for (const auto& m : materialy) {
            m.wyswietlInfo();
        }
    }
};

int main() {
    StacjaMaterialowa stacja;
    stacja.dodajMaterial(Material("Obudowa", "Specjalna", "GRP-2", 3, "Sekcja A"));
    stacja.dodajMaterial(Material("Pusty", "Woz", "GZL", 2, "Sekcja B"));

    cout << "Aktualny magazyn: " << endl;
    stacja.wyswietlMaterialy();

    return 0;
}