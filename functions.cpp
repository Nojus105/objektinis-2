#include "header.h"

struct Stud{
    string vard, pav;
    vector<int> paz;
    int egz;
};

void Manual(Stud &laik, vector<Stud> &grupe){
    while (true) {
        Stud laik;
        cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
        cin >> laik.vard;
        string temp=laik.vard;
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
                laik.paz.push_back(x);
            else
                cout << "Neteisingas pazymys: " << x << endl;
        }
        cout << "Iveskite studento egzamino pazymi: ";
        cin >> laik.egz;
        while(laik.egz<=0 || laik.egz>10){
            cout << "Neteisingas pazymys, iveskite is naujo: ";
            cin >> laik.egz;
        }
        grupe.push_back(laik);
    }
}
void Semi(Stud &laik, vector<Stud> &grupe){
    while (true) {
        Stud laik;
        cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
        cin >> laik.vard;
        string temp=laik.vard;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "STOP") break;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i) {
            laik.paz.push_back(rand() % 10 + 1); 
        }
       laik.egz = rand() % 10 + 1;
       grupe.push_back(laik);
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
            laik.paz.push_back(rand() % 10 + 1); 
        }
        laik.egz = rand() % 10 + 1;
            grupe.push_back(laik);
        }
}