#include "header.h"
#include "functions.cpp"

int main()
{
    srand(time(0));
    vector<Stud> grupe;
    cout << "1 - manual ivedimas, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes, 4 - skaityti faila" << endl;
    Stud laik;
    while (true)
    {
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
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }
    cout << "0 - Vidurkis, 1 - Mediana" << endl;
    char gal;
    while (true)
    {
        gal = getch();
        if (gal == '0' || gal == '1')
            break;
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }
    cout << "Rusiavimas pagal varda (v), pavarde(p), galutini bala (g)" << endl;
    while (true)
    {
        char rusiavimas = getch();
        if (rusiavimas == 'v' || rusiavimas == 'p' || rusiavimas == 'g')
        {
            Rusiuoti(grupe, rusiavimas, gal);
            break;
        }
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }
    cout << "0 - ekrane, 1 - faile" << endl;
    while (true)
    {
        char pasirinkimas = getch();
        if (pasirinkimas == '0')
        {
            Ekrane(grupe, gal);
            break;
        }
        else if (pasirinkimas == '1')
        {
            Faile(grupe, gal);
            break;
        }
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }

    return 0;
}