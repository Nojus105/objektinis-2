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
            string vardas;
            cin >> vardas;
            laik.setVardas(vardas);
            string temp = vardas;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if (temp == "STOP" && StudSkaicius == 0)
                throw std::exception();
            if (temp == "STOP")
                break;

            cout << "Iveskite studento pavarde: ";
            string pavarde;
            cin >> pavarde;
            laik.setPavarde(pavarde);

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
        vector<int> pazymiai;
        while (ss >> temp)
        {
            try
            {
                double x = std::stod(temp);
                if (x > 0 && x <= 10 && x == (int)x)
                    pazymiai.push_back(x);
                else
                    throw std::exception();
            }
            catch (std::exception &e)
            {
                cout << "Iveskite tinkamus pazymius (1-10): ";
                pazymiai.clear();
                goto Ivedimas;
            }
        }
        if (pazymiai.empty())
        {
            cout << "Turite ivesti bent viena pazymi" << endl;
            goto Ivedimas;
        }

        cout << "Iveskite studento egzamino pazymi: ";
        try
        {
            int egz;
            cin >> egz;
            if (egz <= 0 || egz > 10 || egz != (int)egz)
                throw std::exception();
            laik.setEgzaminas(egz);
        }
        catch (std::exception &e)
        {
            int egz;
            while (egz <= 0 || egz > 10 || egz != (int)egz)
            {
                cout << "Neteisingas pazymys, iveskite is naujo: ";
                // isvalo klaidinga ivesti
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> egz;
            }
            laik.setEgzaminas(egz);
        }
        double vid = 0;
        for (auto i : pazymiai)
            vid += i;
        vid = (vid / pazymiai.size()) * 0.4 + laik.getEgzaminas() * 0.6;
        laik.setVidurkis(vid);
        sort(pazymiai.begin(), pazymiai.end());
        double med;
        if (pazymiai.size() % 2 != 0)
            med = pazymiai[pazymiai.size() / 2];
        else
            med = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2.0;
        laik.setMediana(med);
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
            string vardas;
            cin >> vardas;
            laik.setVardas(vardas);
            string temp = vardas;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if (temp == "STOP" && StudSkaicius == 0)
                throw std::exception();
            if (temp == "STOP")
                break;

            cout << "Iveskite studento pavarde: ";
            string pavarde;
            cin >> pavarde;
            laik.setPavarde(pavarde);

            StudSkaicius++;
        }
        catch (std::exception &e)
        {
            cout << "Iveskite bent viena studenta" << endl;
            goto EnterName1;
        }
        vector<int> pazymiai;
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i)
        {
            pazymiai.push_back(rand() % 10 + 1);
        }
        laik.setEgzaminas(rand() % 10 + 1);
        double vid = 0;
        for (auto i : pazymiai)
            vid += i;
        vid = (vid / pazymiai.size()) * 0.4 + laik.getEgzaminas() * 0.6;
        laik.setVidurkis(vid);
        sort(pazymiai.begin(), pazymiai.end());
        double med;
        if (pazymiai.size() % 2 != 0)
            med = pazymiai[pazymiai.size() / 2];
        else
            med = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2.0;
        laik.setMediana(med);
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
        laik.setVardas(vardai[index]);
        index = rand() % 10;
        laik.setPavarde(pavardes[index]);

        vector<int> pazymiai;
        int num_grades = rand() % 10 + 1;
        for (int i = 0; i < num_grades; ++i)
        {
            pazymiai.push_back(rand() % 10 + 1);
        }
        laik.setEgzaminas(rand() % 10 + 1);
        double vid = 0;
        for (auto i : pazymiai)
            vid += i;
        vid = (vid / pazymiai.size()) * 0.4 + laik.getEgzaminas() * 0.6;
        laik.setVidurkis(vid);
        sort(pazymiai.begin(), pazymiai.end());
        double med;
        if (pazymiai.size() % 2 != 0)
            med = pazymiai[pazymiai.size() / 2];
        else
            med = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2.0;
        laik.setMediana(med);
        grupe.push_back(laik);
    }
}

void Stud::Skaityti(vector<Stud> &grupe, double &TotalTime)
{
    cout << "Iveskite failo pavadinima: ";
    string failas;
    cin >> failas;
    ifstream fd(failas, std::ios::in | std::ios::binary);
    while (!fd)
    {
        cout << "Failas nerastas. Iveskite failo pavadinima: ";
        cin >> failas;
        fd.open(failas, std::ios::in | std::ios::binary);
    }

    const size_t bufferSize = 8 * 1024 * 1024;
    std::unique_ptr<char[]> buffer(new char[bufferSize]); // smart pointeris automatiskam atminties valdymui
    string leftover;

    auto start = std::chrono::high_resolution_clock::now();

    string x;
    int count = 0;

    fd >> x >> x;

    while (fd >> x)
    {
        if (x == "Egz.")
            break;
        count++;
    }

    fd.clear();
    fd.seekg(0, std::ios::beg);

    getline(fd, x);

    while (fd)
    {
        fd.read(buffer.get(), bufferSize);
        size_t bytesRead = fd.gcount();
        std::stringstream ss(leftover + string(buffer.get(), bytesRead));

        string line;
        leftover.clear();
        while (getline(ss, line))
        {
            if (ss.eof() && line.back() != '\n') // issaugo neuzbaigtus duomenis
            {
                leftover = line;
                break;
            }

            std::stringstream lineStream(line);
            string vardas, pavarde;
            if (!(lineStream >> vardas >> pavarde))
                continue;

            setVardas(vardas);
            setPavarde(pavarde);

            vector<int> pazymiai;
            for (int i = 0; i < count; i++)
            {
                int temp;
                if (!(lineStream >> temp))
                    break;
                pazymiai.push_back(temp);
            }

            int egz;
            if (!(lineStream >> egz))
                continue;
            setEgzaminas(egz);

            double vid = 0;
            for (auto i : pazymiai)
                vid += i;
            vid = (vid / pazymiai.size()) * 0.4 + egz * 0.6;
            setVidurkis(vid);

            sort(pazymiai.begin(), pazymiai.end());

            double med;
            if (pazymiai.size() % 2 != 0)
                med = pazymiai[pazymiai.size() / 2];
            else
                med = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2.0;
            setMediana(med);

            grupe.push_back(*this);
        }
    }

    fd.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << failas << " studentu failo skaitymo laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}
void Ekrane(vector<Stud> &grupe, char gal, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
        cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
    else if (gal == '1')
        cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    for (auto &n : grupe)
    {
        cout << setw(19) << std::left << n.getPavarde() << setw(15) << n.getVardas();
        if (gal == '0')
        {
            cout << fixed << setprecision(2) << n.getVidurkis() << endl;
        }
        else if (gal == '1')
        {
            cout << fixed << setprecision(2) << n.getMediana() << endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu isvedimo i ekrana laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}

void Skirstymas1(vector<Stud> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
    {
        for (auto &n : grupe)
        {
            if (n.getVidurkis() < 5)
                vargsiukai.push_back(std::move(n));
            else
                galvociai.push_back(std::move(n));
        }
    }
    else if (gal == '1')
    {
        for (auto &n : grupe)
        {
            if (n.getMediana() < 5)
                vargsiukai.push_back(std::move(n));
            else
                galvociai.push_back(std::move(n));
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu skirstymo i dvi grupes laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}

void Skirstymas2(vector<Stud> &grupe, char gal, vector<Stud> &vargsiukai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
    {
        for (auto n = grupe.begin(); n != grupe.end();)
        {
            if (n->getVidurkis() < 5)
            {
                vargsiukai.push_back(*n);
                n = grupe.erase(n);
            }
            else
                n++;
        }
    }
    else if (gal == '1')
    {
        for (auto n = grupe.begin(); n != grupe.end();)
        {
            if (n->getMediana() < 5)
            {
                vargsiukai.push_back(*n);
                n = grupe.erase(n);
            }
            else
                n++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu skirstymo i dvi grupes laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}

void Skirstymas3(vector<Stud> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();

    if (gal == '0')
    {
        auto it = std::partition(grupe.begin(), grupe.end(), [](const Stud &n)
                                 { return n.getVidurkis() < 5; });
        vargsiukai.assign(grupe.begin(), it);
        galvociai.assign(it, grupe.end());
    }
    else if (gal == '1')
    {
        auto it = std::partition(grupe.begin(), grupe.end(), [](const Stud &n)
                                 { return n.getMediana() < 5; });
        vargsiukai.assign(grupe.begin(), it);
        galvociai.assign(it, grupe.end());
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
        cout << "Pasirinkite strategija (1, 2, 3): " << endl;
        char strategija = getch();
        while (strategija != '1' && strategija != '2' && strategija != '3')
        {
            cout << "Neteisingas pasirinkimas" << endl;
            strategija = getch();
        }
        vector<Stud> vargsiukai;
        vector<Stud> galvociai;
        if (strategija == '1')
            Skirstymas1(grupe, gal, vargsiukai, galvociai, TotalTime);
        if (strategija == '2')
            Skirstymas2(grupe, gal, vargsiukai, TotalTime);
        if (strategija == '3')
            Skirstymas3(grupe, gal, vargsiukai, galvociai, TotalTime);
        auto start = std::chrono::high_resolution_clock::now();
        for (auto &n : vargsiukai)
        {
            fr << setw(19) << std::left << n.getPavarde() << setw(15) << n.getVardas();
            if (gal == '0')
            {
                fr << fixed << setprecision(2) << n.getVidurkis() << endl;
            }
            else if (gal == '1')
            {
                fr << fixed << setprecision(2) << n.getMediana() << endl;
            }
        }
        if (strategija == '1' || strategija == '3')
        {
            for (auto &n : galvociai)
            {
                fr1 << setw(19) << std::left << n.getPavarde() << setw(15) << n.getVardas();
                if (gal == '0')
                {
                    fr1 << fixed << setprecision(2) << n.getVidurkis() << endl;
                }
                else if (gal == '1')
                {
                    fr1 << fixed << setprecision(2) << n.getMediana() << endl;
                }
            }
        }
        else if (strategija == '2')
        {
            for (auto &n : grupe)
            {
                fr1 << setw(19) << std::left << n.getPavarde() << setw(15) << n.getVardas();
                if (gal == '0')
                {
                    fr1 << fixed << setprecision(2) << n.getVidurkis() << endl;
                }
                else if (gal == '1')
                {
                    fr1 << fixed << setprecision(2) << n.getMediana() << endl;
                }
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
        auto start = std::chrono::high_resolution_clock::now();
        ofstream fr("rezultatai.txt");
        if (gal == '0')
            fr << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
        else if (gal == '1')
            fr << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
        for (int i = 0; i < 50; i++)
            fr << "-";
        fr << endl;

        for (auto &n : grupe)
        {
            fr << setw(19) << std::left << n.getPavarde() << setw(15) << n.getVardas();
            if (gal == '0')
            {
                fr << fixed << setprecision(2) << n.getVidurkis() << endl;
            }
            else if (gal == '1')
            {
                fr << fixed << setprecision(2) << n.getMediana() << endl;
            }
        }

        fr.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        cout << "Studentu isvedimo i failus laikas: " << elapsed.count() << endl;
        TotalTime += elapsed.count();
    }
}

void Rusiuoti(vector<Stud> &grupe, char rusiavimas, char gal, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (rusiavimas == 'v')
    {
        sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
             { return a.getVardas() < b.getVardas(); });
    }
    else if (rusiavimas == 'p')
    {
        sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
             { return a.getPavarde() < b.getPavarde(); });
    }
    else if (rusiavimas == 'g')
    {
        if (gal == '0') // vidurkis
        {
            sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
                 { return a.getVidurkis() < b.getVidurkis(); });
        }
        else if (gal == '1') // mediana
        {
            sort(grupe.begin(), grupe.end(), [](const Stud &a, const Stud &b)
                 { return a.getMediana() < b.getMediana(); });
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu rusiavimo laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
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