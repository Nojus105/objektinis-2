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

class Stud
{
private:
    string vard, pav;
    vector<int> paz;
    int egz;
    double vid;
    double med;

public:
    // default konstruktorius
    Stud() : vard(""), pav(""), egz(0), vid(0.0), med(0.0) {}
    Stud(const string &vardas, const string &pavarde, const vector<int> &pazymiai, int egzaminas)
        : vard(vardas), pav(pavarde), paz(pazymiai), egz(egzaminas), vid(0.0), med(0.0) {}
    ~Stud();

    // copy konstruktorius
    Stud(const Stud &other)
        : vard(other.vard), pav(other.pav), paz(other.paz), egz(other.egz), vid(other.vid), med(other.med) {}

    // copy assignment operatorius
    Stud &operator=(const Stud &other)
    {
        if (this == &other)
            return *this;
        vard = other.vard;
        pav = other.pav;
        paz = other.paz;
        egz = other.egz;
        vid = other.vid;
        med = other.med;
        return *this;
    }

    // move konstructorius
    Stud(Stud &&other) noexcept
        : vard(std::move(other.vard)), pav(std::move(other.pav)), paz(std::move(other.paz)),
          egz(other.egz), vid(other.vid), med(other.med)
    {
        other.egz = 0;
        other.vid = 0.0;
        other.med = 0.0;
    }

    // move assignment operatorius
    Stud &operator=(Stud &&other) noexcept
    {
        if (this == &other)
            return *this;
        vard = std::move(other.vard);
        pav = std::move(other.pav);
        paz = std::move(other.paz);
        egz = other.egz;
        vid = other.vid;
        med = other.med;

        other.egz = 0;
        other.vid = 0.0;
        other.med = 0.0;
        return *this;
    }

    // getteriai
    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pav; }
    inline vector<int> getPazymiai() const { return paz; }
    inline int getEgzaminas() const { return egz; }
    inline double getVidurkis() const { return vid; }
    inline double getMediana() const { return med; }
    // setteriai
    inline void setVardas(const string &vardas) { vard = vardas; }
    inline void setPavarde(const string &pavarde) { pav = pavarde; }
    inline void setPazymiai(const vector<int> &pazymiai) { paz = pazymiai; }
    inline void setEgzaminas(int egzaminas) { egz = egzaminas; }
    inline void setVidurkis(double vidurkis) { vid = vidurkis; }
    inline void setMediana(double mediana) { med = mediana; }
    std::istream &Skaityti(std::istream &);
    void Skaityti(deque<Stud> &grupe, double &TotalTime);
};

void Manual(Stud &laik, deque<Stud> &grupe);
void Semi(Stud &laik, deque<Stud> &grupe);
void Auto(deque<Stud> &grupe);
void Ekrane(deque<Stud> &grupe, char gal, double &TotalTime);
void Skirstymas1(deque<Stud> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Skirstymas2(deque<Stud> &grupe, char gal, vector<Stud> &vargsiukai, double &TotalTime);
void Skirstymas3(deque<Stud> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Faile(deque<Stud> &grupe, char gal, double &TotalTime);
void Rusiuoti(deque<Stud> &grupe, char rusiavimas, char gal, double &TotalTime);
void GeneruotiFaila(double &TotalTime);