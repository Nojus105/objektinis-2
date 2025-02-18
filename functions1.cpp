#include "header.h"

using namespace std;

struct Stud {
    string vard, pav;
    int* paz;
    int paz_count = 0;
    int egz;

    Stud() : paz(nullptr) {}

    // Destructor to prevent memory leaks
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

void Manual(Stud &laik, vector<Stud> &grupe) {
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
        while (laik.paz_count == 0) {
            cout << "Turite ivesti bent viena pazymi. Iveskite studento pazymius (atskirti tarpais): ";
            getline(cin, line);
            std::stringstream ss(line);
            while (ss >> x) {
                if (x > 0 && x <= 10)
                    laik.addGrade(x);
                else
                    cout << "Neteisingas pazymys: " << x << endl;
            }
        }
        cout << "Iveskite studento egzamino pazymi: ";
        while (!(cin >> laik.egz) || laik.egz <= 0 || laik.egz > 10) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Neteisingas pazymys, iveskite is naujo: ";
        }
        grupe.push_back(move(laik));
    }
}

void Semi(Stud &laik, vector<Stud> &grupe) {
    while (true) {
        Stud laik;
        cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
        cin >> laik.vard;
        string temp = laik.vard;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "STOP") break;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i) {
            laik.addGrade(rand() % 10 + 1);
        }
        laik.egz = rand() % 10 + 1;
        grupe.push_back(move(laik));
    }
}

void Auto(vector<Stud> &grupe) {
    vector<string> vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Tomas", "Lukas", "Andrius", "Paulius", "Darius"};
    vector<string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marijonas", "Tomaitis", "Lukauskas", "Andriukaitis", "Paulauskas", "Darauskas"};

    int num_students = rand() % 10 + 1;
    for (int i = 0; i < num_students; ++i) {
        Stud laik;
        int index = rand() % 10;
        laik.vard = vardai[index];
        index = rand() % 10;
        laik.pav = pavardes[index];
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i) {
            laik.addGrade(rand() % 10 + 1);
        }
        laik.egz = rand() % 10 + 1;
        grupe.push_back(move(laik));
    }
}