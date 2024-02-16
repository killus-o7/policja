#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Wykroczenie {
    short kod_wyk;
    string nazwa;
    short mandat;
    short punkty;
};

struct Mandat {
    string pesel;
    string data_wyk;
    short kod_wyk;
};

struct Kierowca {
    string pesel;
    string data_prawa_jazdy;
    string miasto;
};

vector<Mandat> mandaty = vector<Mandat>();
vector<Wykroczenie> wykroczenia = vector<Wykroczenie>();
vector<Kierowca> kierowcy = vector<Kierowca>();

void loadData() {
    // MANDATY
    string skip;

    ifstream f("../mandaty.txt");
    getline(f, skip);
    string pesel, d;
    short k = 0;
    while (f >> pesel >> d >> k){
        Mandat mandat {
            pesel,
            d,
            k
        };
        mandaty.push_back(mandat);
    } f.close();


    f.open("wykroczenia.txt", ios::in);
    getline(f, skip);
    string line;
    while (getline(f, line)) {
        Wykroczenie wykroczenie;
        int pos;

        pos = line.find_first_of("\t");
        wykroczenie.kod_wyk = stoi(line.substr(0, pos), 0, 10);
        line = line.substr(pos+1);

        pos = line.find_first_of("\t");
        wykroczenie.nazwa = line.substr(0, pos);
        line = line.substr(pos+1);

        pos = line.find_first_of("\t");
        wykroczenie.mandat = stoi(line.substr(0, pos), 0, 10);
        line = line.substr(pos+1);

        pos = line.find_first_of(" ");
        wykroczenie.punkty = stoi(line.substr(0, pos), 0, 10);

        wykroczenia.push_back(wykroczenie);
    }
    f.close();

    Kierowca kierowca;
    f.open("kierowcy.txt", ios::in);
    do {
        f >> kierowca.pesel;
        f >> kierowca.data_prawa_jazdy;
        f >> kierowca.miasto;
        kierowcy.push_back(kierowca);
    } while (f);
    f.close();
}

int main(){
    loadData();

    cout << mandaty.size();
    return 0;
}

