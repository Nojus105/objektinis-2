#include "header.h"

struct Stud{
    string vard, pav;
    vector<int> paz;
    int egz=0;
};

int main(){
    vector<Stud> grupe;
    for (int i=0; i<1; i++){
        Stud laik;
        cout << "Iveskite studento varda: ";
        cin >> laik.vard;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        cout << "Iveskite studento pazymius: ";
        int x;
        while(true){
            cin >> x;
            if (x <= 0 || x>10) break;
            laik.paz.push_back(x);
        }
        cout << "Iveskite studento egzamino pazymi: ";
        cin >> laik.egz;
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
        else if (n.paz.size()%2!=0)
            cout << setw(24) << n.paz[n.paz.size()/2] << endl;
        else cout << setw(24) << fixed << setprecision(2) << (double)(n.paz[n.paz.size()/2]+n.paz[n.paz.size()/2-1])/2 << endl;
    }

    return 0;
}