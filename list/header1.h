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

struct Stud
{
    string vard, pav;
    vector<int> paz;
    int egz;
};

void Manual(Stud &laik, list<Stud> &grupe);
void Semi(Stud &laik, list<Stud> &grupe);
void Auto(list<Stud> &grupe);
void Skaityti(Stud &laik, list<Stud> &grupe, double &TotalTime);
void Ekrane(list<Stud> &grupe, char gal);
void Skirstymas1(list<Stud> grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Skirstymas2(list<Stud> &grupe, char gal, vector<Stud> &vargsiukai, double &TotalTime);
void Skirstymas3(list<Stud> grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Faile(list<Stud> &grupe, char gal, double &TotalTime);
void Rusiuoti(list<Stud> &grupe, char rusiavimas, char gal, double &TotalTime);
void GeneruotiFaila(double &TotalTime);