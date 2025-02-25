#include "header.h"
#include "functions.cpp"

int main()
{
    srand(time(0));
    vector<Stud> grupe;
    cout << "1 - manual ivedimas, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes, 4 - skaityti faila" << endl;
    Stud laik;
    while(true){
        char pasirinkimas = getch();
        if (pasirinkimas == '1')
        {
            Manual(laik, grupe);
            break;
        }
        else if (pasirinkimas == '2')
        {
            Semi(laik, grupe);
            break;
        }
        else if (pasirinkimas == '3')
        {
            Auto(grupe);
            break; 
        }
        else if (pasirinkimas == '4')
        {
            Skaityti(laik, grupe);
            break;
        }
        else cout << "Neteisingas pasirinkimas" << endl;
    }
    cout << "0 - Vidurkis, 1 - Mediana" << endl;
    //cout << "0 - ekrane, 1 - faile" << endl;
    char gal;
    while(true){
        gal = getch();
        if (gal == '0'){
            cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
            break;
        }
        else if(gal == '1'){
            cout << "Pavarde" << setw(18) << "Vardas" << setw(25)<< "Galutinis (Med.)" << endl;
            break;
        }
        else cout << "Neteisingas pasirinkimas" << endl;
    }
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    for (auto n : grupe)
    {
        cout << n.pav << setw(18) << n.vard;
        int sum = 0;
        // visu pazymiu suma
        if (gal == '0')
        {
            for (int m : n.paz)
            {
                sum += m;
            }
            cout << setw(25) << fixed << setprecision(2) << (double)((0.4 * sum / n.paz.size()) + (0.6 * n.egz)) << endl;
        }
        else
        {
            std::sort(n.paz.begin(), n.paz.end());
            if (n.paz.size() % 2 != 0)
                cout << setw(25) << n.paz[n.paz.size() / 2] << endl;
            else
                cout << setw(25) << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 << endl;
        }
    }

    return 0;
}