#include "header.h"

struct Stud{
    string vard, pav;
    vector<int> paz;
    int egz;
};

int main(){
    vector<Stud> grupe;
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
    cout << "Vidurkis - ivestis 0, mediana - ivestis 1" << endl;
    bool gal;
    cin >> gal;
    cout << "Pavarde" << setw(12) << "Vardas" << setw(24);
    if (gal==false)
        cout << "Galutinis (Vid.)" << endl;
    else cout << "Galutinis (Med.)" << endl;
    for (int i=0; i<40; i++) cout << "-";
    cout << endl;
    for (auto n :grupe){
        cout << n.pav << setw(12) << n.vard;
        int sum=0;
        //visu pazymiu suma
        if (gal==false){
            for (auto m : n.paz){
                sum+=m;
            }
            cout << setw(24) << fixed << setprecision(2) << (double)((0.4*sum/n.paz.size())+(0.6*n.egz)) << endl;
        }
        else{
            std::sort(n.paz.begin(), n.paz.end());
            if (n.paz.size()%2!=0)
                cout << setw(24) << n.paz[n.paz.size()/2] << endl;
            else
                cout << setw(24) << fixed << setprecision(2) << (double)(n.paz[n.paz.size()/2]+n.paz[n.paz.size()/2-1])/2 << endl;
        }
    }

    return 0;
}