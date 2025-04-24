#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <utility>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <deque>
#include <numeric>
#include <cassert>
#pragma once

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::setw;
using std::string;
using std::to_string;
using std::vector;

// Bazine/abstrakti klase
class Zmogus
{
protected:
    string vard, pav;

public:
    // Default konstruktorius
    Zmogus() : vard(""), pav("") {}
    Zmogus(const string &vardas, const string &pavarde) : vard(vardas), pav(pavarde) {}

    // Virtualus destruktorius
    virtual ~Zmogus() = default;

    // Getteriai
    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pav; }

    // Setteriai
    inline void setVardas(const string &vardas) { vard = vardas; }
    inline void setPavarde(const string &pavarde) { pav = pavarde; }

    // Pure virtual function to enforce implementation in derived classes
    virtual void Skaityti(deque<Zmogus *> &grupe, double &TotalTime) = 0;
};

// Derived klase
class Stud : public Zmogus
{
private:
    vector<int> paz;
    int egz;
    double vid;
    double med;

public:
    // Default konstruktorius
    Stud() : Zmogus(), egz(0), vid(0.0), med(0.0) {}
    Stud(const string &vardas, const string &pavarde, const vector<int> &pazymiai, int egzaminas)
        : Zmogus(vardas, pavarde), paz(pazymiai), egz(egzaminas), vid(0.0), med(0.0) {}
    ~Stud();

    // Copy konstruktorius
    Stud(const Stud &other)
        : Zmogus(other.vard, other.pav), paz(other.paz), egz(other.egz), vid(other.vid), med(other.med) {}

    // Copy assignment operatorius
    Stud &operator=(const Stud &other)
    {
        if (this == &other)
            return *this;
        Zmogus::operator=(other);
        paz = other.paz;
        egz = other.egz;
        vid = other.vid;
        med = other.med;
        return *this;
    }

    // Move konstruktorius
    Stud(Stud &&other) noexcept
        : Zmogus(std::move(other.vard), std::move(other.pav)), paz(std::move(other.paz)),
          egz(other.egz), vid(other.vid), med(other.med)
    {
        other.egz = 0;
        other.vid = 0.0;
        other.med = 0.0;
    }

    // Move assignment operatorius
    Stud &operator=(Stud &&other) noexcept
    {
        if (this == &other)
            return *this;
        Zmogus::operator=(std::move(other));
        paz = std::move(other.paz);
        egz = other.egz;
        vid = other.vid;
        med = other.med;

        other.egz = 0;
        other.vid = 0.0;
        other.med = 0.0;
        return *this;
    }

    // Getteriai
    inline vector<int> getPazymiai() const { return paz; }
    inline int getEgzaminas() const { return egz; }
    inline double getVidurkis() const { return vid; }
    inline double getMediana() const { return med; }

    // Setteriai
    inline void setPazymiai(const vector<int> &pazymiai) { paz = pazymiai; }
    inline void setEgzaminas(int egzaminas) { egz = egzaminas; }
    inline void setVidurkis(double vidurkis) { vid = vidurkis; }
    inline void setMediana(double mediana) { med = mediana; }

    // Overriding the pure virtual function
    void Skaityti(deque<Zmogus *> &grupe, double &TotalTime) override;
};

void Manual(Stud &laik, deque<Zmogus *> &grupe);
void Semi(Stud &laik, deque<Zmogus *> &grupe);
void Auto(deque<Zmogus *> &grupe);
void Ekrane(deque<Zmogus *> &grupe, char gal, double &TotalTime);
void Skirstymas1(deque<Zmogus *> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Skirstymas2(deque<Zmogus *> &grupe, char gal, vector<Stud> &vargsiukai, double &TotalTime);
void Skirstymas3(deque<Zmogus *> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Faile(deque<Zmogus *> &grupe, char gal, double &TotalTime);
void Rusiuoti(deque<Zmogus *> &grupe, char rusiavimas, char gal, double &TotalTime);
void GeneruotiFaila(double &TotalTime);
void testRuleOfFive();