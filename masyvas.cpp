#include "header.h"
#include "functions1.cpp"

int main()
{
    srand(time(0));
    vector<Stud> grupe;
    cout << "1 - manual ivedimas, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes" << endl;
    char pasirinkimas = getch();
    Stud laik;
    if (pasirinkimas == '1')
    {
        Manual(laik, grupe);
    }
    else if (pasirinkimas == '2')
    {
        Semi(laik, grupe);
    }
    else if (pasirinkimas == '3')
    {
        Auto(grupe);
    }
    else
    {
        while (true)
        {
            cout << "Neteisingas pasirinkimas" << endl;
            pasirinkimas = getch();
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
        }
    }
    cout << "0 - Vidurkis, 1 - Mediana" << endl;
    char gal = getch();
    cout << "Pavarde" << setw(12) << "Vardas" << setw(24);
    if (gal == '0')
        cout << "Galutinis (Vid.)" << endl;
    else
        cout << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 40; i++)
        cout << "-";
    cout << endl;
    for (auto &n : grupe)
    {
        cout << n.pav << setw(12) << n.vard;
        // visu pazymiu suma
        if (gal == false)
        {
            int sum = 0;
            for (int i = 0; i < n.paz_count; ++i)
            {
                sum += n.paz[i];
            }
            cout << setw(24) << fixed << setprecision(2) << (double)((0.4 * sum / n.paz_count) + (0.6 * n.egz)) << endl;
        }
        else
        {
            std::sort(n.paz, n.paz + n.paz_count);
            if (n.paz_count % 2 != 0)
                cout << setw(24) << n.paz[n.paz_count / 2] << endl;
            else
                cout << setw(24) << fixed << setprecision(2) << (double)(n.paz[n.paz_count / 2] + n.paz[n.paz_count / 2 - 1]) / 2 << endl;
        }
    }

    return 0;
}