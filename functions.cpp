#include "header.h"

void Manual(Stud &laik, vector<Stud> &grupe)
{
    while (true)
    {
        Stud laik;
        cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
        cin >> laik.vard;
        string temp = laik.vard;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "STOP")
            break;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        cout << "Iveskite studento pazymius (atskirti tarpais): ";
        cin.ignore(); // nekyla problemu su praeita cin operacija
        string line;
        getline(cin, line);
        std::stringstream ss(line);
        int x;
        while (ss >> x)
        {
            if (x > 0 && x <= 10)
                laik.paz.push_back(x);
            else
                cout << "Neteisingas pazymys: " << x << endl;
        }
        while (laik.paz.empty())
        {
            cout << "Turite ivesti bent viena pazymi. Iveskite studento pazymius (atskirti tarpais): ";
            getline(cin, line);
            std::stringstream ss(line);
            while (ss >> x)
            {
                if (x > 0 && x <= 10)
                    laik.paz.push_back(x);
                else
                    cout << "Neteisingas pazymys: " << x << endl;
            }
        }
        cout << "Iveskite studento egzamino pazymi: ";
        cin >> laik.egz;
        while (laik.egz <= 0 || laik.egz > 10)
        {
            cout << "Neteisingas pazymys, iveskite is naujo: ";
            // isvalo klaidinga ivesti
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> laik.egz;
        }
        grupe.push_back(laik);
    }
}
void Semi(Stud &laik, vector<Stud> &grupe)
{
    while (true)
    {
        Stud laik;
        cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
        cin >> laik.vard;
        string temp = laik.vard;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "STOP")
            break;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i)
        {
            laik.paz.push_back(rand() % 10 + 1);
        }
        laik.egz = rand() % 10 + 1;
        grupe.push_back(laik);
    }
}
void Auto(vector<Stud> &grupe)
{
    vector<string> vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Tomas", "Lukas", "Andrius", "Paulius", "Darius"};
    vector<string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marijonas", "Tomaitis", "Lukauskas", "Andriukaitis", "Paulauskas", "Darauskas"};

    int num_students = rand() % 10 + 1;
    for (int i = 0; i < num_students; ++i)
    {
        Stud laik;
        int index = rand() % 10;
        laik.vard = vardai[index];
        index = rand() % 10;
        laik.pav = pavardes[index];
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i)
        {
            laik.paz.push_back(rand() % 10 + 1);
        }
        laik.egz = rand() % 10 + 1;
        grupe.push_back(laik);
    }
}
void Skaityti(Stud &laik, vector<Stud> &grupe)
{
    cout << "Iveskite failo pavadinima: ";
    string failas;
    cin >> failas;
    ifstream fd(failas);
    if (!fd)
    {
        cout << "Failas nerastas" << endl;
        exit(1);
    }
    string x;
    int count = 0;
    fd >> x >> x;
    while (true)
    {
        fd >> x;
        if (x == "Egz.")
            break;
        count++;
    }
    while (!fd.eof())
    {
        fd >> laik.vard >> laik.pav;
        laik.paz.clear();
        for (int i = 0; i < count; i++)
        {
            int temp;
            fd >> temp;
            laik.paz.push_back(temp);
        }
        fd >> laik.egz;
        grupe.push_back(laik);
    };
    fd.close();
}
void Ekrane(vector<Stud> &grupe, char gal)
{
    if (gal == '0')
        cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
    else if (gal == '1')
        cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    for (auto n : grupe)
    {
        cout << setw(19) << std::left << n.pav << setw(15) << n.vard;
        int sum = 0;
        // visu pazymiu suma
        if (gal == '0')
        {
            for (int m : n.paz)
            {
                sum += m;
            }
            cout << fixed << setprecision(2) << (double)((0.4 * sum / n.paz.size()) + (0.6 * n.egz)) << endl;
        }
        else
        {
            std::sort(n.paz.begin(), n.paz.end());
            if (n.paz.size() % 2 != 0)
                cout << n.paz[n.paz.size() / 2] << endl;
            else
                cout << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 << endl;
        }
    }
}
void Faile(vector<Stud> &grupe, char gal)
{
    ofstream fr("rezultatai.txt");
    if (gal == '0')
        fr << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
    else if (gal == '1')
        fr << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 50; i++)
        fr << "-";
    fr << endl;

    for (auto n : grupe)
    {
        fr << setw(19) << std::left << n.pav << setw(15) << n.vard;
        int sum = 0;
        // visu pazymiu suma
        if (gal == '0')
        {
            for (int m : n.paz)
            {
                sum += m;
            }
            fr << fixed << setprecision(2) << (double)((0.4 * sum / n.paz.size()) + (0.6 * n.egz)) << endl;
        }
        else if (gal == '1')
        {
            std::sort(n.paz.begin(), n.paz.end());
            if (n.paz.size() % 2 != 0)
                fr << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2]) << endl;
            else
                fr << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 << endl;
        }
    }

    fr.close();
}
void Rusiuoti(vector<Stud> &grupe, char rusiavimas, char gal)
{
    if (rusiavimas == 'v')
    {
        sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
             { return a.vard < b.vard; });
    }
    else if (rusiavimas == 'p')
    {
        sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
             { return a.pav < b.pav; });
    }
    else if (rusiavimas == 'g')
    {
        if (gal == '0') // vidurkis
        {
            sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
                 {
                 double sumA = 0;
                 for (int grade : a.paz) sumA += grade;
                 double avgA = (0.4 * sumA / a.paz.size()) + (0.6 * a.egz);

                 double sumB = 0;
                 for (int grade : b.paz) sumB += grade;
                 double avgB = (0.4 * sumB / b.paz.size()) + (0.6 * b.egz);

                 return avgA < avgB; });
        }
        else if (gal == '1') // mediana
        {
            sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
                 {
                 auto median = [](const vector<int> &paz) -> double {
                     vector<int> sortedPaz = paz;
                     std::sort(sortedPaz.begin(), sortedPaz.end());
                     if (sortedPaz.size() % 2 != 0)
                         return sortedPaz[sortedPaz.size() / 2];
                     else
                         return (sortedPaz[sortedPaz.size() / 2] + sortedPaz[sortedPaz.size() / 2 - 1]) / 2.0;
                 };
                 double medA = median(a.paz);
                 double medB = median(b.paz);
                 return medA < medB; });
        }
    }
}