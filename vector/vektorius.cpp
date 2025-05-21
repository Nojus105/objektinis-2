#include "header.h"

/**
 * @brief Pagrindinė programos funkcija.
 *
 * Ši funkcija leidžia vartotojui pasirinkti įvairias operacijas, tokias kaip studentų duomenų generavimas,
 * įvedimas, rikiavimas, skirstymas ir išvedimas į ekraną arba failą.
 *
 * @return int Programos vykdymo rezultatas.
 */
int main()
{
    cout << "Skaiciuoti perskirstymus? (y/n)" << endl;
    char perskirstymas;
    while (true)
    {
        perskirstymas = getch();
        if (perskirstymas == 'y' || perskirstymas == 'n')
            break;
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }
    if (perskirstymas == 'y')
    {
        unsigned int sz = 100000000;
        int count = 0;
        std::vector<int> v1;
        auto laikas1=std::chrono::high_resolution_clock::now();
        for (unsigned int i = 1; i <= sz; ++i)
        {
            v1.push_back(i);
            if (v1.capacity() == v1.size())
                count++;
        }
        auto laikas2=std::chrono::high_resolution_clock::now();
        cout << "std::vector perskirstymu: " << count << endl;
        cout << "std::vector laikas: " << std::chrono::duration_cast<std::chrono::milliseconds>(laikas2-laikas1).count() << " ms" << endl;
        count = 0;
        Vektorius<int> v2;
        auto laikas3=std::chrono::high_resolution_clock::now();
        for (unsigned int i = 1; i <= sz; ++i)
        {
            v2.push_back(i);
            if (v2.capacity() == v2.size())
                count++;
        }
        auto laikas4=std::chrono::high_resolution_clock::now();
        cout << endl << "Klases Vektorius perskirstymu: " << count << endl;
        cout << "Vektorius laikas: " << std::chrono::duration_cast<std::chrono::milliseconds>(laikas4-laikas3).count() << " ms" << endl;
        return 0;
    }

    // Uzkomentuota eilutė, rodanti, kad abstrakčios klasės objektų kūrimas negalimas
    // Zmogus testas;

    /**
     * @brief Tikrinama, ar vartotojas nori testuoti Rule of Five taisyklę.
     */
    char test;
    cout << "Ar norite atlikti 'Rule of five' testa? (y/n)" << endl;
    while (true)
    {
        test = getch();
        if (test == 'y' || test == 'n')
            break;
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }
    if (test == 'y')
    {
        testRuleOfFive();
    }

    srand(time(0));
    Vektorius<Zmogus *> grupe;
    double TotalTime = 0;
    Stud laik;

    /**
     * @brief Tikrinama, ar vartotojas nori sugeneruoti studentų failą.
     */
    cout << "Sugeneruoti studentu faila?" << endl;
    cout << "0 - Ne, 1 - Taip" << endl;
    while (true)
    {
        char pasirinkimas = getch();
        if (pasirinkimas == '1')
        {
            GeneruotiFaila(TotalTime);
            break;
        }
        else if (pasirinkimas == '0')
            break;
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }

    /**
     * @brief Leidžiama pasirinkti studentų duomenų įvedimo būdą.
     */
    cout << "1 - manual ivedimas, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes, 4 - skaityti faila" << endl;
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
            laik.Skaityti(grupe, TotalTime);
            break;
        }
        else
            cout << "Neteisingas pasirinkimas" << endl;
    }

    /**
     * @brief Pasirenkama, ar naudoti vidurkį, ar medianą.
     */
    cout << "0 - Vidurkis, 1 - Mediana" << endl;
    char gal;
    while (true)
    {
    Pasirinkimas:
        try
        {
            gal = getch();
            if (gal == '0' || gal == '1')
                break;
            else
                throw std::exception();
        }
        catch (std::exception &e)
        {
            cout << "Neteisingas pasirinkimas" << endl;
            goto Pasirinkimas;
        }
    }

    /**
     * @brief Pasirenkamas rikiavimo kriterijus.
     */
    cout << "Rusiavimas pagal varda (v), pavarde(p), galutini bala (g)" << endl;
    while (true)
    {
    Pasirinkimas2:
        try
        {
            char rusiavimas = getch();
            if (rusiavimas == 'v' || rusiavimas == 'p' || rusiavimas == 'g')
            {
                Rusiuoti(grupe, rusiavimas, gal, TotalTime);
                break;
            }
            else
                throw std::exception();
        }
        catch (std::exception &e)
        {
            cout << "Neteisingas pasirinkimas" << endl;
            goto Pasirinkimas2;
        }
    }

    /**
     * @brief Pasirenkama, ar duomenis išvesti į ekraną, ar į failą.
     */
    cout << "0 - ekrane, 1 - faile" << endl;
    char pasirinkimas = getch();
    while (pasirinkimas != '0' && pasirinkimas != '1')
    {
        cout << "Neteisingas pasirinkimas" << endl;
        pasirinkimas = getch();
    }
    if (pasirinkimas == '0')
        Ekrane(grupe, gal, TotalTime);
    else if (pasirinkimas == '1')
        Faile(grupe, gal, TotalTime);

    /**
     * @brief Išvedamas bendras programos veikimo laikas.
     */
    cout << "Programa veike: " << TotalTime << " s" << endl;

    return 0;
}