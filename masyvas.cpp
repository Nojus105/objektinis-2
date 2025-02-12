#include "header.h"

struct Stud {
    string vard, pav;
    int* paz;
    int paz_count=0;
    int egz;

    Stud() : paz(nullptr){}
    
    //pasalina dinamiskai priskirta atminti, preventina memory leaks
    ~Stud() {
        delete[] paz;
    }
    // Delete copy constructor and copy assignment operator to avoid shallow copying.
    Stud(const Stud&) = delete;
    Stud& operator=(const Stud&) = delete;
    
    // Move constructor: transfers ownership of resources.
     Stud(Stud&& other) noexcept
        : vard(move(other.vard)), pav(move(other.pav)),
        paz(other.paz), paz_count(other.paz_count), egz(other.egz)
    {
        other.paz = nullptr;
        other.paz_count = 0;
    }
    
    // Move assignment operator: releases current resources and takes ownership of the other's.
    Stud& operator=(Stud&& other) noexcept {
        if (this != &other) {
            delete[] paz;
            vard = move(other.vard);
            pav = move(other.pav);
            paz = other.paz;
            paz_count = other.paz_count;
            egz = other.egz;
            other.paz = nullptr;
            other.paz_count = 0;
        }
        return *this;
    }

    void addGrade(int grade) {
        int* new_paz = new int[paz_count + 1];
        for (int i = 0; i < paz_count; i++) {
            new_paz[i] = paz[i];
        }
        new_paz[paz_count] = grade;
        delete[] paz;
        paz = new_paz;
        paz_count++;
    }
};

int main() {
    vector<Stud> grupe;
    while (true) {
        Stud laik;
        cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
        cin >> laik.vard;
        string temp = laik.vard;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "STOP") break;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        cout << "Iveskite studento pazymius (atskirti tarpais): ";
        cin.ignore(); //nekyla problemu su praeita cin operacija
        string line;
        getline(cin, line);
        std::stringstream ss(line);
        int x;
        while (ss >> x) {
            if (x > 0 && x <= 10) 
                laik.addGrade(x);
            else
                cout << "Neteisingas pazymys: " << x << endl;
        }
        cout << "Iveskite studento egzamino pazymi: ";
        cin >> laik.egz;
        while (laik.egz <= 0 || laik.egz > 10) {
            cout << "Neteisingas pazymys, iveskite is naujo: ";
            cin >> laik.egz;
        }
        //move panaudotas, kad avoidint Stud kopiju
        grupe.push_back(std::move(laik));
    }
    cout << "Vidurkis - ivestis 0, mediana - ivestis 1" << endl;
    bool gal;
    cin >> gal;
    cout << "Pavarde" << setw(12) << "Vardas" << setw(24);
    if (gal == false)
        cout << "Galutinis (Vid.)" << endl;
    else cout << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 40; i++) cout << "-";
    cout << endl;
    for (auto& n : grupe) {
        cout << n.pav << setw(12) << n.vard;
        int sum = 0;
        // visu pazymiu suma
        if (gal == false) {
            for (int i = 0; i < n.paz_count; ++i) {
                sum += n.paz[i];
            }
            cout << setw(24) << fixed << setprecision(2) << (double)((0.4 * sum / n.paz_count) + (0.6 * n.egz)) << endl;
        } else {
            std::sort(n.paz, n.paz + n.paz_count);
            if (n.paz_count % 2 != 0)
                cout << setw(24) << n.paz[n.paz_count / 2] << endl;
            else
                cout << setw(24) << fixed << setprecision(2) << (double)(n.paz[n.paz_count / 2] + n.paz[n.paz_count / 2 - 1]) / 2 << endl;
        }
    }

    return 0;
}