#include "vector.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <numeric>
#include <cassert>
#pragma once

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::to_string;

/**
 * @brief Bazinė/abstrakti klasė.
 */
class Zmogus
{
protected:
    string vard, pav;

public:
    /**
     * @brief Default konstruktorius.
     */
    Zmogus() : vard(""), pav("") {}

    /**
     * @brief Konstruktorius su parametrais.
     *
     * @param vardas Vardas.
     * @param pavarde Pavardė.
     */
    Zmogus(const string &vardas, const string &pavarde) : vard(vardas), pav(pavarde) {}

    /**
     * @brief Virtualus destruktorius.
     */
    virtual ~Zmogus() = default;

    /**
     * @brief Getteriai.
     */
    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pav; }

    /**
     * @brief Setteriai.
     */
    inline void setVardas(const string &vardas) { vard = vardas; }
    inline void setPavarde(const string &pavarde) { pav = pavarde; }

    /**
     * @brief Grynoji virtuali funkcija, kurią reikia įgyvendinti išvestinėse klasėse.
     *
     * @param grupe Studentų grupė.
     * @param TotalTime Bendras operacijos laikas.
     */
    virtual void Skaityti(Vektorius<Zmogus *> &grupe, double &TotalTime) = 0;
};

/**
 * @brief Išvestinė klasė.
 */
class Stud : public Zmogus
{
private:
    Vektorius<int> paz;
    int egz;
    double vid;
    double med;

public:
    /**
     * @brief Numatytasis konstruktorius.
     */
    Stud() : Zmogus(), egz(0), vid(0.0), med(0.0) {}

    /**
     * @brief Konstruktorius su parametrais.
     *
     * @param vardas Vardas.
     * @param pavarde Pavardė.
     * @param pazymiai Pažymiai.
     * @param egzaminas Egzamino rezultatas.
     */
    Stud(const string &vardas, const string &pavarde, const Vektorius<int> &pazymiai, int egzaminas)
        : Zmogus(vardas, pavarde), paz(pazymiai), egz(egzaminas), vid(0.0), med(0.0) {}

    /**
     * @brief Destruktorius.
     */
    ~Stud();

    /**
     * @brief Copy konstruktorius.
     *
     * @param other Kitas objektas.
     */
    Stud(const Stud &other)
        : Zmogus(other.vard, other.pav), paz(other.paz), egz(other.egz), vid(other.vid), med(other.med) {}

    /**
     * @brief Copy priskyrimo operatorius.
     *
     * @param other Kitas objektas.
     * @return Stud&
     */
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

    /**
     * @brief Move konstruktorius.
     *
     * @param other Kitas objektas.
     */
    Stud(Stud &&other) noexcept
        : Zmogus(std::move(other.vard), std::move(other.pav)), paz(std::move(other.paz)),
          egz(other.egz), vid(other.vid), med(other.med)
    {
        other.vard.clear();
        other.pav.clear();
        other.egz = 0;
        other.vid = 0.0;
        other.med = 0.0;
    }

    /**
     * @brief Move priskyrimo operatorius.
     *
     * @param other Kitas objektas.
     * @return Stud&
     */
    Stud &operator=(Stud &&other) noexcept
    {
        if (this == &other)
            return *this;
        Zmogus::operator=(std::move(other));
        paz = std::move(other.paz);
        egz = other.egz;
        vid = other.vid;
        med = other.med;

        other.vard.clear();
        other.pav.clear();
        other.egz = 0;
        other.vid = 0.0;
        other.med = 0.0;
        return *this;
    }

    /**
     * @brief Getteriai.
     */
    inline Vektorius<int> getPazymiai() const { return paz; }
    inline int getEgzaminas() const { return egz; }
    inline double getVidurkis() const { return vid; }
    inline double getMediana() const { return med; }

    /**
     * @brief Setteriai.
     */
    inline void setPazymiai(const Vektorius<int> &pazymiai) { paz = pazymiai; }
    inline void setEgzaminas(int egzaminas) { egz = egzaminas; }
    inline void setVidurkis(double vidurkis) { vid = vidurkis; }
    inline void setMediana(double mediana) { med = mediana; }

    /**
     * @brief Perrašoma grynoji virtuali funkcija.
     *
     * @param grupe Studentų grupė.
     * @param TotalTime Bendras operacijos laikas.
     */
    void Skaityti(Vektorius<Zmogus *> &grupe, double &TotalTime) override;
};

/**
 * @brief Funkcija studentų duomenų įvedimui rankiniu būdu.
 *
 * @param laik Laikinas studento objektas.
 * @param grupe Studentų grupė.
 */
void Manual(Stud &laik, Vektorius<Zmogus *> &grupe);

/**
 * @brief Funkcija studentų duomenų įvedimui pusiau automatiniu būdu.
 *
 * @param laik Laikinas studento objektas.
 * @param grupe Studentų grupė.
 */
void Semi(Stud &laik, Vektorius<Zmogus *> &grupe);

/**
 * @brief Funkcija studentų duomenų generavimui automatiškai.
 *
 * @param grupe Studentų grupė.
 */
void Auto(Vektorius<Zmogus *> &grupe);

/**
 * @brief Funkcija studentų duomenų išvedimui į ekraną.
 *
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param TotalTime Bendras operacijos laikas.
 */
void Ekrane(Vektorius<Zmogus *> &grupe, char gal, double &TotalTime);

/**
 * @brief Funkcija studentų skirstymui į dvi grupes pagal vidurkį arba medianą.
 *
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param vargsiukai Grupė studentų, kurių rezultatai mažesni nei 5.
 * @param galvociai Grupė studentų, kurių rezultatai didesni arba lygūs 5.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skirstymas1(Vektorius<Zmogus *> &grupe, char gal, Vektorius<Stud> &vargsiukai, Vektorius<Stud> &galvociai, double &TotalTime);

/**
 * @brief Funkcija studentų skirstymui į dvi grupes su pašalinimu iš pradinės grupės.
 *
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param vargsiukai Grupė studentų, kurių rezultatai mažesni nei 5.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skirstymas2(Vektorius<Zmogus *> &grupe, char gal, Vektorius<Stud> &vargsiukai, double &TotalTime);

/**
 * @brief Funkcija studentų skirstymui į dvi grupes naudojant `std::partition`.
 *
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param vargsiukai Grupė studentų, kurių rezultatai mažesni nei 5.
 * @param galvociai Grupė studentų, kurių rezultatai didesni arba lygūs 5.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skirstymas3(Vektorius<Zmogus *> &grupe, char gal, Vektorius<Stud> &vargsiukai, Vektorius<Stud> &galvociai, double &TotalTime);

/**
 * @brief Funkcija studentų duomenų išvedimui į failą.
 *
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param TotalTime Bendras operacijos laikas.
 */
void Faile(Vektorius<Zmogus *> &grupe, char gal, double &TotalTime);

/**
 * @brief Funkcija studentų rikiavimui pagal pasirinktą kriterijų.
 *
 * @param grupe Studentų grupė.
 * @param rusiavimas Rikiavimo kriterijus ('v' - vardas, 'p' - pavardė, 'g' - galutinis rezultatas).
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param TotalTime Bendras operacijos laikas.
 */
void Rusiuoti(Vektorius<Zmogus *> &grupe, char rusiavimas, char gal, double &TotalTime);

/**
 * @brief Funkcija studentų failo generavimui.
 *
 * @param TotalTime Bendras operacijos laikas.
 */
void GeneruotiFaila(double &TotalTime);

/**
 * @brief Funkcija Rule of Five taisyklės testavimui.
 */
void testRuleOfFive();