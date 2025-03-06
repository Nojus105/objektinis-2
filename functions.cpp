#include "header.h"

void Manual(Stud &laik, vector<Stud> &grupe)
{
    int StudSkaicius = 0;
    while (true)
    {
    EnterName:
        Stud laik;
        try
        {
            cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
            cin >> laik.vard;
            string temp = laik.vard;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if (temp == "STOP" && StudSkaicius == 0)
                throw std::exception();
            if (temp == "STOP")
                break;
            cout << "Iveskite studento pavarde: ";
            cin >> laik.pav;
            StudSkaicius++;
        }
        catch (std::exception &e)
        {
            cout << "Iveskite bent viena studenta" << endl;
            goto EnterName;
        }
        cout << "Iveskite studento pazymius (atskirti tarpais): ";
    Ivedimas:
        cin.ignore(); // nekyla problemu su praeita cin operacija
        string line;
        getline(cin, line);
        std::stringstream ss(line);
        string temp;
        while (ss >> temp)
        {
            try
            {
                double x = std::stod(temp);
                if (x > 0 && x <= 10 && x == (int)x)
                    laik.paz.push_back(x);
                else
                    throw std::exception();
            }
            catch (std::exception &e)
            {
                cout << "Iveskite tinkamus pazymius (0-10): ";
                laik.paz.clear();
                goto Ivedimas;
            }
        }
        if (laik.paz.empty())
        {
            cout << "Turite ivesti bent viena pazymi" << endl;
            goto Ivedimas;
        }
        cout << "Iveskite studento egzamino pazymi: ";
        try
        {
            double egz;
            cin >> egz;
            if (egz <= 0 || egz > 10 || egz != (int)egz)
                throw std::exception();
            laik.egz = egz;
        }
        catch (std::exception &e)
        {
            double egz;
            while (egz <= 0 || egz > 10 || egz != (int)egz)
            {
                cout << "Neteisingas pazymys, iveskite is naujo: ";
                // isvalo klaidinga ivesti
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> egz;
            }
            laik.egz = egz;
        }
        grupe.push_back(laik);
    }
}
void Semi(Stud &laik, vector<Stud> &grupe)
{
    int StudSkaicius = 0;
    while (true)
    {
    EnterName1:
        Stud laik;
        try
        {
            cout << "Iveskite studento varda (arba 'STOP' norint baigti): ";
            cin >> laik.vard;
            string temp = laik.vard;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if (temp == "STOP" && StudSkaicius == 0)
                throw std::exception();
            if (temp == "STOP")
                break;
            cout << "Iveskite studento pavarde: ";
            cin >> laik.pav;
            StudSkaicius++;
        }
        catch (std::exception &e)
        {
            cout << "Iveskite bent viena studenta" << endl;
            goto EnterName1;
        }
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
void Skaityti(Stud &laik, vector<Stud> &grupe, double &TotalTime)
{
    cout << "Iveskite failo pavadinima: ";
    string failas;
    cin >> failas;
    ifstream fd;
    try
    {
        fd.open(failas);
        if (!fd)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        while (!fd)
        {
            cout << "Failas nerastas. Iveskite failo pavadinima: ";
            cin >> failas;
            fd.open(failas);
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << failas << " studentu failo skaitymo laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
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
void Skirstymas(vector<Stud> grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
    {
        for (auto n : grupe)
        {
            int sum = 0;
            // visu pazymiu suma
            for (int m : n.paz)
            {
                sum += m;
            }
            if ((double)((0.4 * sum / n.paz.size()) + (0.6 * n.egz)) < 5)
                vargsiukai.push_back(n);
            else
                galvociai.push_back(n);
        }
    }
    else if (gal == '1')
    {
        for (auto n : grupe)
        {
            std::sort(n.paz.begin(), n.paz.end());
            if (n.paz.size() % 2 != 0)
            {
                if (n.paz[n.paz.size() / 2] < 5)
                    vargsiukai.push_back(n);
                else
                    galvociai.push_back(n);
            }
            else
            {
                if ((double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 < 5)
                    vargsiukai.push_back(n);
                else
                    galvociai.push_back(n);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu skirstymo i dvi grupes laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}
void Faile(vector<Stud> &grupe, char gal, double &TotalTime)
{
    cout << "Paskirstyti i 2 grupes?" << endl;
    cout << "0 - Ne, 1 - Taip" << endl;
    char pasirinkimas;
    try
    {
        pasirinkimas = getch();
        if (pasirinkimas != '0' && pasirinkimas != '1')
            throw std::exception();
    }
    catch (std::exception &e)
    {
        while (true)
        {
            cout << "Neteisingas pasirinkimas" << endl;
            pasirinkimas = getch();
            if (pasirinkimas == '0' || pasirinkimas == '1')
                break;
        }
    }
    if (pasirinkimas == '1')
    {
        ofstream fr("vargsiukai.txt");
        ofstream fr1("galvociai.txt");
        if (gal == '0')
        {
            fr << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
            fr1 << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
        }
        else if (gal == '1')
        {
            fr << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
            fr1 << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
        }
        for (int i = 0; i < 50; i++)
        {
            fr << "-";
            fr1 << "-";
        }
        fr << endl;
        fr1 << endl;
        vector<Stud> vargsiukai;
        vector<Stud> galvociai;
        Skirstymas(grupe, gal, vargsiukai, galvociai, TotalTime);
        auto start = std::chrono::high_resolution_clock::now();
        for (auto n : vargsiukai)
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
                if (n.paz.size() % 2 == 0)
                    fr << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2]) << endl;
                else
                    fr << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 << endl;
            }
        }
        for (auto n : galvociai)
        {
            fr1 << setw(19) << std::left << n.pav << setw(15) << n.vard;
            int sum = 0;
            // visu pazymiu suma
            if (gal == '0')
            {
                for (int m : n.paz)
                {
                    sum += m;
                }
                fr1 << fixed << setprecision(2) << (double)((0.4 * sum / n.paz.size()) + (0.6 * n.egz)) << endl;
            }
            else if (gal == '1')
            {
                std::sort(n.paz.begin(), n.paz.end());
                if (n.paz.size() % 2 == 0)
                    fr1 << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2]) << endl;
                else
                    fr1 << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 << endl;
            }
        }
        fr.close();
        fr1.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        cout << "Studentu isvedimo i failus laikas: " << elapsed.count() << endl;
        TotalTime += elapsed.count();
    }
    else
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
                if (n.paz.size() % 2 == 0)
                    fr << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2]) << endl;
                else
                    fr << fixed << setprecision(2) << (double)(n.paz[n.paz.size() / 2] + n.paz[n.paz.size() / 2 - 1]) / 2 << endl;
            }
        }

        fr.close();
    }
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
void GeneruotiFaila(double &TotalTime)
{
    int name;
    cout << "Kiek studentu generuoti: ";
    try
    {
        cin >> name;
        if (name <= 0)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        while (name <= 0)
        {
            cout << "Ivestas netinkamas skaicius. Iveskite is naujo: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> name;
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    ofstream fr(to_string(name) + ".txt");
    fr << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde";
    int num_grades = rand() % 16 + 5;
    for (int i = 0; i < num_grades; i++)
    {
        fr << setw(8) << "ND" + to_string(i + 1);
    }
    fr << setw(8) << "Egz." << endl;
    for (int i = 0; i < name; i++)
    {
        fr << setw(20) << "Vardas" + to_string(i + 1) << setw(20) << "Pavarde" + to_string(i + 1);
        for (int j = 0; j < num_grades; j++)
        {
            fr << setw(8) << rand() % 10 + 1;
        }
        fr << setw(8) << rand() % 10 + 1 << endl;
    }
    fr.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << name << " studentu failo generavimo laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}