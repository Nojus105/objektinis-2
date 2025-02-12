#include "header.h"
#include "functions.cpp"

int main(){
    srand(time(0));
    vector<Stud> grupe;
    cout << "1 - manual ivedimas, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes" << endl;
    char pasirinkimas=getch();
    Stud laik;
    if (pasirinkimas=='1'){
        Manual(laik, grupe);
    }
    else if(pasirinkimas=='2'){
        Semi(laik, grupe);
    }
    else if(pasirinkimas=='3'){
        Auto(grupe);
    }
    else{
        cout << "Neteisingas pasirinkimas" << endl;
        return 1;
    }
    cout << "0 - Vidurkis, 1 - Mediana" << endl;
    char gal=getch();
    cout << "Pavarde" << setw(12) << "Vardas" << setw(24);
    if (gal=='0')
        cout << "Galutinis (Vid.)" << endl;
    else cout << "Galutinis (Med.)" << endl;
    for (int i=0; i<40; i++) cout << "-";
    cout << endl;
    for (auto n :grupe){
        cout << n.pav << setw(12) << n.vard;
        int sum=0;
        //visu pazymiu suma
        if (gal=='0'){
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