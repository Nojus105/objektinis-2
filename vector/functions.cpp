#include "header.h"

Stud::~Stud()
{
    // destruktorius
    paz.clear();
    egz = 0;
    vid = 0.0;
    med = 0.0;
}

void Manual(Stud &laik, Vektorius<Zmogus *> &grupe)
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
        Vektorius<int> pazymiai;
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
        grupe.push_back(new Stud(std::move(laik)));
    }
}

void Semi(Stud &laik, Vektorius<Zmogus *> &grupe)
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
        Vektorius<int> pazymiai;
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
        grupe.push_back(new Stud(std::move(laik)));
    }
}

void Auto(Vektorius<Zmogus *> &grupe)
{
    Vektorius<string> vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Tomas", "Lukas", "Andrius", "Paulius", "Darius"};
    Vektorius<string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marijonas", "Tomaitis", "Lukauskas", "Andriukaitis", "Paulauskas", "Darauskas"};

    int num_students = rand() % 10 + 1;
    for (int i = 0; i < num_students; ++i)
    {
        Stud laik;
        int index = rand() % 10;
        laik.setVardas(vardai[index]);
        index = rand() % 10;
        laik.setPavarde(pavardes[index]);

        Vektorius<int> pazymiai;
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
        grupe.push_back(new Stud(std::move(laik)));
    }
}

void Stud::Skaityti(Vektorius<Zmogus *> &grupe, double &TotalTime)
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
    char *buffer = new char[bufferSize];
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
        fd.read(buffer, bufferSize);
        size_t bytesRead = fd.gcount();
        std::stringstream ss(leftover + string(buffer, bytesRead));

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

            Vektorius<int> pazymiai;
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

            grupe.push_back(new Stud(*this));
        }
    }

    delete[] buffer; // destruktorius atlaisvinti atminti

    fd.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << failas << " studentu failo skaitymo laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}
void Ekrane(Vektorius<Zmogus *> &grupe, char gal, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
        cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl;
    else if (gal == '1')
        cout << "Pavarde" << setw(18) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    for (const auto &n : grupe)
    {
        if (auto stud = dynamic_cast<Stud *>(n))
        {
            cout << setw(19) << std::left << stud->getPavarde() << setw(15) << stud->getVardas();
            if (gal == '0')
            {
                cout << fixed << setprecision(2) << stud->getVidurkis() << endl;
            }
            else if (gal == '1')
            {
                cout << fixed << setprecision(2) << stud->getMediana() << endl;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu isvedimo i ekrana laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}

void Skirstymas1(Vektorius<Zmogus *> &grupe, char gal, Vektorius<Stud> &vargsiukai, Vektorius<Stud> &galvociai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
    {
        for (auto &n : grupe)
        {
            if ((*dynamic_cast<Stud *>(n)).getVidurkis() < 5)
                vargsiukai.push_back(std::move(*dynamic_cast<Stud *>(n)));
            else
                galvociai.push_back(std::move(*dynamic_cast<Stud *>(n)));
        }
    }
    else if (gal == '1')
    {
        for (auto &n : grupe)
        {
            if ((*dynamic_cast<Stud *>(n)).getMediana() < 5)
                vargsiukai.push_back(std::move(*dynamic_cast<Stud *>(n)));
            else
                galvociai.push_back(std::move(*dynamic_cast<Stud *>(n)));
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu skirstymo i dvi grupes laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}

void Skirstymas2(Vektorius<Zmogus *> &grupe, char gal, Vektorius<Stud> &vargsiukai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (gal == '0')
    {
        for (auto n = grupe.begin(); n != grupe.end();)
        {
            if (auto stud = dynamic_cast<Stud *>(*n))
            {
                if (stud->getVidurkis() < 5)
                {
                    vargsiukai.push_back(*dynamic_cast<Stud *>(*n));
                    n = grupe.erase(n);
                }

                else
                    n++;
            }
        }
    }
    else if (gal == '1')
    {
        for (auto n = grupe.begin(); n != grupe.end();)
        {
            if (dynamic_cast<Stud *>(*n)->getMediana() < 5)
            {
                vargsiukai.push_back(*dynamic_cast<Stud *>(*n));
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

void Skirstymas3(Vektorius<Zmogus *> &grupe, char gal, Vektorius<Stud> &vargsiukai, Vektorius<Stud> &galvociai, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();

    auto it = std::partition(grupe.begin(), grupe.end(), [gal](const Zmogus *n)
                             {
        auto stud = dynamic_cast<const Stud*>(n);
        if (gal == '0') // Partition by average
            return stud && stud->getVidurkis() < 5;
        else if (gal == '1') // Partition by median
            return stud && stud->getMediana() < 5;
        return false; });

    // Move elements to `vargsiukai`
    for (auto i = grupe.begin(); i != it; ++i)
    {
        if (auto stud = dynamic_cast<Stud *>(*i))
        {
            vargsiukai.push_back(std::move(*stud)); // Move the Stud object
        }
    }

    // Move elements to `galvociai`
    for (auto i = it; i != grupe.end(); ++i)
    {
        if (auto stud = dynamic_cast<Stud *>(*i))
        {
            galvociai.push_back(std::move(*stud)); // Move the Stud object
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Studentu skirstymo i dvi grupes laikas: " << elapsed.count() << endl;
    TotalTime += elapsed.count();
}

void Faile(Vektorius<Zmogus *> &grupe, char gal, double &TotalTime)
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
        Vektorius<Stud> vargsiukai;
        Vektorius<Stud> galvociai;
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
                fr1 << setw(19) << std::left << (*n).getPavarde() << setw(15) << (*n).getVardas();
                if (gal == '0')
                {
                    fr1 << fixed << setprecision(2) << (*dynamic_cast<Stud *>(n)).getVidurkis() << endl;
                }
                else if (gal == '1')
                {
                    fr1 << fixed << setprecision(2) << (*dynamic_cast<Stud *>(n)).getMediana() << endl;
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

        for (const auto &n : grupe)
        {
            if (dynamic_cast<Stud *>(n)) // check if cast is valid
            {
                fr << setw(19) << std::left << (*n).getPavarde() << setw(15) << (*n).getVardas();
                if (gal == '0')
                {
                    fr << fixed << setprecision(2) << (*dynamic_cast<Stud *>(n)).getVidurkis() << endl;
                }
                else if (gal == '1')
                {
                    fr << fixed << setprecision(2) << (*dynamic_cast<Stud *>(n)).getMediana() << endl;
                }
            }
        }

        fr.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        cout << "Studentu isvedimo i failus laikas: " << elapsed.count() << endl;
        TotalTime += elapsed.count();
    }
}

void Rusiuoti(Vektorius<Zmogus *> &grupe, char rusiavimas, char gal, double &TotalTime)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (rusiavimas == 'v')
    {
        std::sort(grupe.begin(), grupe.end(), [](const Zmogus *a, const Zmogus *b)
                  { return a->getVardas() < b->getVardas(); });
    }
    else if (rusiavimas == 'p')
    {
        std::sort(grupe.begin(), grupe.end(), [](const Zmogus *a, const Zmogus *b)
                  { return a->getPavarde() < b->getPavarde(); });
    }
    else if (rusiavimas == 'g')
    {
        if (gal == '0') // vidurkis
        {
            std::sort(grupe.begin(), grupe.end(), [](const Zmogus *a, const Zmogus *b)
                      {
            auto studA = dynamic_cast<const Stud*>(a);
            auto studB = dynamic_cast<const Stud*>(b);
            return studA && studB && studA->getVidurkis() < studB->getVidurkis(); });
        }
        else if (gal == '1') // mediana
        {
            std::sort(grupe.begin(), grupe.end(), [](const Zmogus *a, const Zmogus *b)
                      {
            auto studA = dynamic_cast<const Stud*>(a);
            auto studB = dynamic_cast<const Stud*>(b);
            return studA && studB && studA->getMediana() < studB->getMediana(); });
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

void testRuleOfFive()
{
    // Test 1: copy konstruktorius
    Stud original("Jonas", "Jonaitis", {8, 9, 10}, 9);
    Stud copyConstructed(original);
    assert(copyConstructed.getVardas() == "Jonas");
    assert(copyConstructed.getPavarde() == "Jonaitis");
    assert(copyConstructed.getPazymiai() == Vektorius<int>({8, 9, 10}));
    assert(copyConstructed.getEgzaminas() == 9);

    // Test 2: copy assignment operatorius
    Stud copyAssigned;
    copyAssigned = original;
    assert(copyAssigned.getVardas() == "Jonas");
    assert(copyAssigned.getPavarde() == "Jonaitis");
    assert(copyAssigned.getPazymiai() == Vektorius<int>({8, 9, 10}));
    assert(copyAssigned.getEgzaminas() == 9);

    // Test 3: move konstruktorius
    Stud moveConstructed(std::move(original));
    assert(moveConstructed.getVardas() == "Jonas");
    assert(moveConstructed.getPavarde() == "Jonaitis");
    assert(moveConstructed.getPazymiai() == Vektorius<int>({8, 9, 10}));
    assert(moveConstructed.getEgzaminas() == 9);
    assert(original.getVardas().empty());
    assert(original.getPavarde().empty());
    assert(original.getPazymiai().empty());
    assert(original.getEgzaminas() == 0);

    // Test 4: move assignment operatorius
    Stud moveAssigned;
    moveAssigned = std::move(moveConstructed);
    assert(moveAssigned.getVardas() == "Jonas");
    assert(moveAssigned.getPavarde() == "Jonaitis");
    assert(moveAssigned.getPazymiai() == Vektorius<int>({8, 9, 10}));
    assert(moveAssigned.getEgzaminas() == 9);
    assert(moveConstructed.getVardas().empty());
    assert(moveConstructed.getPavarde().empty());
    assert(moveConstructed.getPazymiai().empty());
    assert(moveConstructed.getEgzaminas() == 0);

    // Test 5: destruktorius
    {
        Stud temp("Petras", "Petraitis", {7, 8, 9}, 8);
        // destruktorius automatiskai iskvieciamas
    }
    std::cout << "Rule of five testai sekmingi" << endl;
}