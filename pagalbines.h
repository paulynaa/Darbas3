#ifndef PAGALBINES_H_INCLUDED
#define PAGALBINES_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <string>
#include <stdexcept>
struct Pazymiai{
    std::string var;
    std::string pav;
    double vid;
    int egz;
    std::vector<int> paz;
    double galutinis;
    double med;
};

void rezultatai(std::vector<Pazymiai> hh);

void rezultataifailas(std::vector<Pazymiai> hh, std::string failiukas);

double mediana(int u, Pazymiai h);

void generuojam(int b, std::string zh);

void failuskaick(std::string wp, Pazymiai hi);

void spausdintuvas(std::string zekai, std::string malaciai, const auto z, const auto f );


#endif // PAGALBINES_H_INCLUDED
