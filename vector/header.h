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
#include <numeric>
#include <future>
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

struct Stud
{
    string vard, pav;
    vector<int> paz;
    int egz;
};

void Manual(Stud &laik, vector<Stud> &grupe);
void Semi(Stud &laik, vector<Stud> &grupe);
void Auto(vector<Stud> &grupe);
void Skaityti(Stud &laik, vector<Stud> &grupe, double &TotalTime);
void Ekrane(vector<Stud> &grupe, char gal);
void Skirstymas(vector<Stud> grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Skirstymas2(vector<Stud> &grupe, char gal, vector<Stud> &vargsiukai, double &TotalTime);
void skirstymas3(vector<Stud> grupe, char gal, vector<Stud> &vargsiukai, vector<Stud> &galvociai, double &TotalTime);
void Faile(vector<Stud> &grupe, char gal, double &TotalTime);
void Rusiuoti(vector<Stud> &grupe, char rusiavimas, char gal, double &TotalTime);
void GeneruotiFaila(double &TotalTime);
void processChunk(const string &chunk, vector<Stud> &grupe, int count);