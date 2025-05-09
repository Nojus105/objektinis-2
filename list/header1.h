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
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>
#pragma once

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using std::setw;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::list;
using std::sort;

/**
 * @brief Struktūra, aprašanti studento duomenis.
 */
struct Stud
{
    string vard; /**< Studentų vardas. */
    string pav;  /**< Studentų pavardė. */
    vector<int> paz; /**< Studentų pažymiai. */
    int egz; /**< Egzamino rezultatas. */
    double vid; /**< Galutinis rezultatas pagal vidurkį. */
    double med; /**< Galutinis rezultatas pagal medianą. */
};

/**
 * @brief Funkcija studentų duomenų įvedimui rankiniu būdu.
 * 
 * @param laik Laikinas studento objektas.
 * @param grupe Studentų grupė.
 */
void Manual(Stud &laik, list<Stud> &grupe);

/**
 * @brief Funkcija studentų duomenų įvedimui pusiau automatiniu būdu.
 * 
 * @param laik Laikinas studento objektas.
 * @param grupe Studentų grupė.
 */
void Semi(Stud &laik, list<Stud> &grupe);

/**
 * @brief Funkcija studentų duomenų generavimui automatiškai.
 * 
 * @param grupe Studentų grupė.
 */
void Auto(list<Stud> &grupe);

/**
 * @brief Funkcija studentų duomenų skaitymui iš failo.
 * 
 * @param laik Laikinas studento objektas.
 * @param grupe Studentų grupė.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skaityti(Stud &laik, list<Stud> &grupe, double &TotalTime);

/**
 * @brief Funkcija studentų duomenų išvedimui į ekraną.
 * 
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param TotalTime Bendras operacijos laikas.
 */
void Ekrane(list<Stud> &grupe, char gal, double &TotalTime);

/**
 * @brief Funkcija studentų skirstymui į dvi grupes pagal vidurkį arba medianą.
 * 
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param vargsiukai Grupė studentų, kurių rezultatai mažesni nei 5.
 * @param galvociai Grupė studentų, kurių rezultatai didesni arba lygūs 5.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skirstymas1(list<Stud> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);

/**
 * @brief Funkcija studentų skirstymui į dvi grupes su pašalinimu iš pradinės grupės.
 * 
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param vargsiukai Grupė studentų, kurių rezultatai mažesni nei 5.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skirstymas2(list<Stud> &grupe, char gal, vector<Stud> &vargsiukai, double &TotalTime);

/**
 * @brief Funkcija studentų skirstymui į dvi grupes naudojant `std::partition`.
 * 
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param vargsiukai Grupė studentų, kurių rezultatai mažesni nei 5.
 * @param galvociai Grupė studentų, kurių rezultatai didesni arba lygūs 5.
 * @param TotalTime Bendras operacijos laikas.
 */
void Skirstymas3(list<Stud> &grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);

/**
 * @brief Funkcija studentų duomenų išvedimui į failą.
 * 
 * @param grupe Studentų grupė.
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param TotalTime Bendras operacijos laikas.
 */
void Faile(list<Stud> &grupe, char gal, double &TotalTime);

/**
 * @brief Funkcija studentų rikiavimui pagal pasirinktą kriterijų.
 * 
 * @param grupe Studentų grupė.
 * @param rusiavimas Rikiavimo kriterijus ('v' - vardas, 'p' - pavardė, 'g' - galutinis rezultatas).
 * @param gal Pasirinkimas, ar naudoti vidurkį ('0') ar medianą ('1').
 * @param TotalTime Bendras operacijos laikas.
 */
void Rusiuoti(list<Stud> &grupe, char rusiavimas, char gal, double &TotalTime);

/**
 * @brief Funkcija studentų failo generavimui.
 * 
 * @param TotalTime Bendras operacijos laikas.
 */
void GeneruotiFaila(double &TotalTime);