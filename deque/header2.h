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
using std::deque;

struct Stud
{
    string vard, pav;
    vector<int> paz;
    int egz;
};

void Manual(Stud &laik, deque<Stud> &grupe);
void Semi(Stud &laik, deque<Stud> &grupe);
void Auto(deque<Stud> &grupe);
void Skaityti(Stud &laik, deque<Stud> &grupe, double &TotalTime);
void Ekrane(deque<Stud> &grupe, char gal);
void Skirstymas(deque<Stud> grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Faile(deque<Stud> &grupe, char gal, double &TotalTime);
void Rusiuoti(deque<Stud> &grupe, char rusiavimas, char gal);
void GeneruotiFaila(double &TotalTime);