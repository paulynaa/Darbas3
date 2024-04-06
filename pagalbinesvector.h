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
        Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

        Pazymiai(std::string var, std::string pav, double vid, int egz, const std::vector<int>& paz,
                 double galutinis, double med)
            : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

        ~Pazymiai() {paz_.clear(); var_.clear(), pav_.clear();}

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

class Zmogus {
protected:
    std::string var_;
    std::string pav_;
public:
    virtual ~Zmogus() {} // Padarome bazin� klas� abstrak�i� su virtualiu destruktoriumi

    // Metodai skirti gauti ir nustatyti vard� ir pavard�
    virtual void setVar(const std::string& newVar) = 0;
    virtual void setPav(const std::string& newPav) = 0;
    virtual std::string getVar() const = 0;
    virtual std::string getPav() const = 0;
};

class Pazymiai : public Zmogus {
private:
    double vid_;
    int egz_;
    std::vector<int> paz_;
    double galutinis_;
    double med_;
public:
    // Konstruktorius
    Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

    // Metodai skirti nustatyti pa�ymi� vidurk�, egzamino rezultat�, gauti pa�ymius ir t.t.
    void setVid(double newVid) { vid_ = newVid; }
    void setEgz(int newEgz) { egz_ = newEgz; }
    void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
    void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
    void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
    void setMed(double newMed) { med_ = newMed; }

    void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}

    double getVid() const { return vid_; }
    int getEgz() const { return egz_; }
    std::vector<int> getPaz() const { return paz_; }
    int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
    double getGalutinis() const { return galutinis_; }
    double getMed() const { return med_; }

    // Implementuojame abstrak�i� metod� nustatym� ir gavim�
    void setVar(const std::string& newVar) override { var_ = newVar; }
    void setPav(const std::string& newPav) override { pav_ = newPav; }
    std::string getVar() const override { return var_; }
    std::string getPav() const override { return pav_; }
};
*/
class Zmogus {
protected:
    std::string var_;
    std::string pav_;

public:
    Zmogus() = default;
    Zmogus(const std::string& var, const std::string& pav) : var_(var), pav_(pav) {}
    virtual ~Zmogus() {}

    virtual void setVar(const std::string& newVar) { var_ = newVar; }
    virtual void setPav(const std::string& newPav) { pav_ = newPav; }
    virtual std::string getVar() const { return var_; }
    virtual std::string getPav() const { return pav_; }
};

class Pazymiai : public Zmogus {
private:
    double vid_;
    int egz_;
    std::vector<int> paz_;
    double galutinis_;
    double med_;

public:
    // Default konstruktorius
    Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

    // Konstruktorius su parametrais
    Pazymiai(const std::string& var, const std::string& pav, double vid, int egz, const std::vector<int>& paz,
             double galutinis, double med)
        : Zmogus(var, pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

    // Copy konstruktorius
    Pazymiai(const Pazymiai& other)
        : Zmogus(other.getVar(), other.getPav()), vid_(other.vid_), egz_(other.egz_),
          paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}

    // Move konstruktorius
    Pazymiai(Pazymiai&& other) noexcept
        : Zmogus(std::move(other.var_), std::move(other.pav_)),
          vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
          galutinis_(other.galutinis_), med_(other.med_) {}

    // Copy priskyrimo operatorius
    Pazymiai& operator=(const Pazymiai& other) {
        if (this != &other) {
            Zmogus::setVar(other.getVar());
            Zmogus::setPav(other.getPav());
            vid_ = other.vid_;
            egz_ = other.egz_;
            paz_ = other.paz_;
            galutinis_ = other.galutinis_;
            med_ = other.med_;
        }
        return *this;
    }

    // Move priskyrimo operatorius
    Pazymiai& operator=(Pazymiai&& other) noexcept {
        if (this != &other) {
            Zmogus::setVar(std::move(other.var_));
            Zmogus::setPav(std::move(other.pav_));
            vid_ = other.vid_;
            egz_ = other.egz_;
            paz_ = std::move(other.paz_);
            galutinis_ = other.galutinis_;
            med_ = other.med_;
        }
        return *this;
    }

    // Destructor
    ~Pazymiai() {}

    // Metodai skirti nustatyti pa�ymi� vidurk�, egzamino rezultat�, gauti pa�ymius ir t.t.
    void setVid(double newVid) { vid_ = newVid; }
    void setEgz(int newEgz) { egz_ = newEgz; }
    void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
    void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
    void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
    void setMed(double newMed) { med_ = newMed; }

    void sortPaz(Pazymiai& C) { std::sort(C.paz_.begin(), C.paz_.end()); }

    double getVid() const { return vid_; }
    int getEgz() const { return egz_; }
    std::vector<int> getPaz() const { return paz_; }
    int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
    double getGalutinis() const { return galutinis_; }
    double getMed() const { return med_; }

    void setVar(const std::string& newVar) override { Zmogus::setVar(newVar); }
    void setPav(const std::string& newPav) override { Zmogus::setPav(newPav); }
    std::string getVar() const override { return Zmogus::getVar(); }
    std::string getPav() const override { return Zmogus::getPav(); }
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

void testai();

#endif // PAGALBINES_H_INCLUDED
