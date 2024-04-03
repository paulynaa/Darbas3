#ifndef PAGALBINESVECTOR_H_INCLUDED
#define PAGALBINESVECTOR_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <string>
#include <stdexcept>
/*
class Pazymiai{
    private:
        std::string var_;
        std::string pav_;
        double vid_;
        int egz_;
        std::vector<int> paz_;
        double galutinis_;
        double med_;
    public:
        Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}
        Pazymiai(std::string var,std::string pav, double vid, int egz, const std::vector<int>& paz, double galutinis, double med)
            : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

        ~Pazymiai() {paz_.clear(), var_.clear(), pav_.clear();}

        void setVar(const std::string& newVar) { var_ = newVar; }
        void setPav(const std::string& newPav) { pav_ = newPav; }
        void setVid(double newVid) { vid_ = newVid; }
        void setEgz(int newEgz) { egz_ = newEgz; }
        void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
        void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
        void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
        void setMed(double newMed) { med_ = newMed; }
        void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}
        std::string getVar() const { return var_; }
        std::string getPav() const { return pav_; }
        double getVid() const { return vid_; }
        int getEgz() const { return egz_; }
        std::vector<int> getPaz() const { return paz_; }
        int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
        double getGalutinis() const { return galutinis_; }
        double getMed() const { return med_; }
};

class Pazymiai {
private:
    std::string var_;
    std::string pav_;
    double vid_;
    int egz_;
    std::vector<int> paz_;
    double galutinis_;
    double med_;

public:
    // Default constructor
    Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

    // Constructor with parameters
    Pazymiai(std::string var, std::string pav, double vid, int egz, const std::vector<int>& paz,
             double galutinis, double med)
        : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

    // Copy constructor
    Pazymiai(const Pazymiai& other)
        : var_(other.var_), pav_(other.pav_), vid_(other.vid_), egz_(other.egz_),
          paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}

    // Copy assignment operator
    Pazymiai& operator=(const Pazymiai& other) {
        if (this != &other) {
            var_ = other.var_;
            pav_ = other.pav_;
            vid_ = other.vid_;
            egz_ = other.egz_;
            paz_ = other.paz_;
            galutinis_ = other.galutinis_;
            med_ = other.med_;
        }
        return *this;
    }

    // Move constructor
    Pazymiai(Pazymiai&& other) noexcept
        : var_(std::move(other.var_)), pav_(std::move(other.pav_)),
          vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
          galutinis_(other.galutinis_), med_(other.med_) {}

    // Move assignment operator
    Pazymiai& operator=(Pazymiai&& other) noexcept {
        if (this != &other) {
            var_ = std::move(other.var_);
            pav_ = std::move(other.pav_);
            vid_ = other.vid_;
            egz_ = other.egz_;
            paz_ = std::move(other.paz_);
            galutinis_ = other.galutinis_;
            med_ = other.med_;
        }
        return *this;
    }

    // Destructor
    ~Pazymiai() {
        // No need to clear member variables as they manage their own resources
    }

    void setVar(const std::string& newVar) { var_ = newVar; }
        void setPav(const std::string& newPav) { pav_ = newPav; }
        void setVid(double newVid) { vid_ = newVid; }
        void setEgz(int newEgz) { egz_ = newEgz; }
        void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
        void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
        void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
        void setMed(double newMed) { med_ = newMed; }
        void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}
        std::string getVar() const { return var_; }
        std::string getPav() const { return pav_; }
        double getVid() const { return vid_; }
        int getEgz() const { return egz_; }
        std::vector<int> getPaz() const { return paz_; }
        int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
        double getGalutinis() const { return galutinis_; }
        double getMed() const { return med_; }
};
*/
class Pazymiai {
private:
    std::string var_;
    std::string pav_;
    double vid_;
    int egz_;
    std::vector<int> paz_;
    double galutinis_;
    double med_;

public:
    // Default constructor
    Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

    // Constructor with parameters
    Pazymiai(std::string var, std::string pav, double vid, int egz, const std::vector<int>& paz,
             double galutinis, double med)
        : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

    // Copy constructor
    Pazymiai(const Pazymiai& other)
        : var_(other.var_), pav_(other.pav_), vid_(other.vid_), egz_(other.egz_),
          paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}

    // Copy assignment operator
    Pazymiai& operator=(const Pazymiai& other) {
        if (this != &other) {
            var_ = other.var_;
            pav_ = other.pav_;
            vid_ = other.vid_;
            egz_ = other.egz_;
            paz_ = other.paz_;
            galutinis_ = other.galutinis_;
            med_ = other.med_;
        }
        return *this;
    }

    // Move constructor
    Pazymiai(Pazymiai&& other) noexcept
        : var_(std::move(other.var_)), pav_(std::move(other.pav_)),
          vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
          galutinis_(other.galutinis_), med_(other.med_) {}

    // Move assignment operator
    Pazymiai& operator=(Pazymiai&& other) noexcept {
        if (this != &other) {
            var_ = std::move(other.var_);
            pav_ = std::move(other.pav_);
            vid_ = other.vid_;
            egz_ = other.egz_;
            paz_ = std::move(other.paz_);
            galutinis_ = other.galutinis_;
            med_ = other.med_;
        }
        return *this;
    }

    // Destructor
    ~Pazymiai() {
        // No need to clear member variables as they manage their own resources
    }

    void setVar(const std::string& newVar) { var_ = newVar; }
        void setPav(const std::string& newPav) { pav_ = newPav; }
        void setVid(double newVid) { vid_ = newVid; }
        void setEgz(int newEgz) { egz_ = newEgz; }
        void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
        void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
        void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
        void setMed(double newMed) { med_ = newMed; }
        void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}
        std::string getVar() const { return var_; }
        std::string getPav() const { return pav_; }
        double getVid() const { return vid_; }
        int getEgz() const { return egz_; }
        std::vector<int> getPaz() const { return paz_; }
        int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
        double getGalutinis() const { return galutinis_; }
        double getMed() const { return med_; }
    // Overloaded output operator
    friend std::ostream& operator<<(std::ostream& os, const Pazymiai& p) {
        os << "Student: " << p.var_ << " " << p.pav_ << "\n"
           << "Vidurkis: " << p.vid_ << "\n"
           << "Egzaminas: " << p.egz_ << "\n"
           << "Pazymiai: ";
        for (int pazymys : p.paz_)
            os << pazymys << " ";
        os << "\nGalutinis: " << p.galutinis_ << "\n"
           << "Mediana: " << p.med_ << std::endl;
        return os;
    }

    // Overloaded input operator
    friend std::istream& operator>>(std::istream& is, Pazymiai& p) {
        std::string var, pav;
        double vid, galutinis, med;
        int egz;
        std::vector<int> paz;

        std::cout << "Enter student's name and surname: ";
        is >> var >> pav;
        std::cout << "Enter average grade: ";
        is >> vid;
        std::cout << "Enter exam grade: ";
        is >> egz;
        std::cout << "Enter grades (enter -1 to finish): ";
        int grade;
        while (is >> grade && grade != -1)
            paz.push_back(grade);
        std::cout << "Enter final grade: ";
        is >> galutinis;
        std::cout << "Enter median grade: ";
        is >> med;

        p = Pazymiai(var, pav, vid, egz, paz, galutinis, med);
        return is;
    }
};
void rezultatai(std::vector<Pazymiai> hh);

void rezultataifailas(std::vector<Pazymiai> hh, std::string failiukas);

double mediana(int u, Pazymiai h);

void generuojam(int studentusk, std::string failopav);

void failuskaick(std::string wp, Pazymiai hi, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void failuskaickstrategija1(std::string wp, Pazymiai hi,std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void failuskaickstrategija2(std::string wp, Pazymiai hi, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void failuskaickstrategija3(std::string wp, Pazymiai hi,std::vector<Pazymiai>& S, std::vector<Pazymiai>& P, std::vector<Pazymiai>& Z);

void spausdintuvas(std::string zekai, std::string malaciai, std::vector<Pazymiai> P, std::vector<Pazymiai> Z );

#endif // PAGALBINES_H_INCLUDED
