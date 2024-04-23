/**
 * @file pagalbinesvector.h
 * @brief Declaration of the Pazymiai class.
 */
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
#include <cassert>
/**
 * @brief Klasë Pazymiai saugo informacijà apie studentø paþymius.
 */
class Pazymiai {
    private:
        std::string var_; /**< Studento vardas */
        std::string pav_; /**< Studento pavardë */
        double vid_; /**< Vidurkis */
        int egz_; /**< Egzamino rezultatas */
        std::vector<int> paz_; /**< Paþymiø sàraðas */
        double galutinis_; /**< Galutinis paþymys */
        double med_; /**< Mediana */

    public:
        /**
     * @brief Numatytasis konstruktorius, inicializuoja narius nuliais.
     */
        Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

        /**
     * @brief Parametrizuotas konstruktorius, inicializuoja narius su duotomis reikðmëmis.
     * @param var Studento vardas
     * @param pav Studento pavardë
     * @param vid Vidurkis
     * @param egz Egzamino rezultatas
     * @param paz Paþymiø sàraðas
     * @param galutinis Galutinis paþymys
     * @param med Mediana
     */

        Pazymiai(std::string var, std::string pav, double vid, int egz, const std::vector<int>& paz,
                 double galutinis, double med)
            : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

            /**
     * @brief Desktruktorius, iðvalo vektoriø ir stringus.
     */
        ~Pazymiai() {paz_.clear(); var_.clear(), pav_.clear();}

    // Copy constructor
    /**
     * @brief Kopijavimo konstruktorius.
     */
        Pazymiai(const Pazymiai& other)
            : var_(other.var_), pav_(other.pav_), vid_(other.vid_), egz_(other.egz_),
              paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}

    // Copy assignment operator
    /**
     * @brief Kopijavimo priskyrimo operatorius.
     */
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
    /**
     * @brief Perkëlimo konstruktorius.
     */
        Pazymiai(Pazymiai&& other) noexcept
            : var_(std::move(other.var_)), pav_(std::move(other.pav_)),
              vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
              galutinis_(other.galutinis_), med_(other.med_) {}

    // Move assignment operator
    /**
     * @brief Perkëlimo priskyrimo operatorius.
     */
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

        /**
     * @brief Nustato studento vardà.
     */
        void setVar(const std::string& newVar) { var_ = newVar; }
        /**
     * @brief Nustato studento pavardæ.
     */
        void setPav(const std::string& newPav) { pav_ = newPav; }
        /**
     * @brief Nustato studento vidurká.
     */
        void setVid(double newVid) { vid_ = newVid; }
        /**
     * @brief Nustato egzamino rezultatà.
     */
        void setEgz(int newEgz) { egz_ = newEgz; }
        /**
     * @brief Áterpia vienà paþymá á sàraðà..
     */
        void setOnePaz(int newPaz) { paz_.push_back(newPaz); }
        /**
     * @brief Nustato paþymiø sàraðà.
     */
        void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }
        /**
     * @brief Nustato galutiná paþymá.
     */
        void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }
        /**
     * @brief Nustato medianà.
     */
        void setMed(double newMed) { med_ = newMed; }
/**
     * @brief Rikiuoja paþymiø sàraðà.
     */
        void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}

        /**
     * @brief Graþina studento vardà.
     */
    std::string getVar() const { return var_; }

    /**
     * @brief Graþina studento pavardæ.
     */
    std::string getPav() const { return pav_; }

    /**
     * @brief Graþina vidurká.
     */
    double getVid() const { return vid_; }

    /**
     * @brief Graþina egzamino rezultatà.
     */
    int getEgz() const { return egz_; }

    /**
     * @brief Graþina paþymiø sàraðà.
     */
    std::vector<int> getPaz() const { return paz_; }

    /**
     * @brief Graþina nurodytà paþymá ið sàraðo pagal pozicijà.
     */
    int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }

    /**
     * @brief Graþina galutiná paþymá.
     */
    double getGalutinis() const { return galutinis_; }

    /**
     * @brief Graþina medianà.
     */
    double getMed() const { return med_; }
        /**
     * @brief Skaièiuoja medianà.
     * @param u Paþymiø skaièius
     * @param h Pazymiai objektas
     * @return Mediana
     */

        friend double mediana(int u, const Pazymiai h);
        // Input operator
        /**
     * @brief Ávedimo operatorius, skirtas nuskaityti objekto duomenis ið ávesties srauto.
     * @param is Ávesties srautas
     * @param obj Pazymiai objektas, á kurá nuskaitomi duomenys
     * @return Ávesties srautas
     */
        friend std::istream& operator>>(std::istream& is, Pazymiai& obj) {
            std::cout << "Iveskite studento varda (noredami baigti spauskite 4):" << std::endl;
            is >> obj.var_;
            if (obj.var_ == "4" || obj.pav_ == "4")
                return is;
            std::cout << "Iveskite studento pavarde (noredami baigti spauskite 4):" << std::endl;
            is >> obj.pav_;
            if (obj.var_ == "4" || obj.pav_ == "4")
                return is;

            double suma = 0.0;
            int pazymys;
            int j = 0;

            do {
                std::cout << "Iveskite " << j + 1 << " pazymi (norint baigti spauskite 11): ";
                is >> pazymys;

                if (pazymys == 11)
                    break;

                while (pazymys < 1 || pazymys > 10 || is.fail()) {
                    std::cout << "Klaida. Iveskite skaiciu nuo 1 iki 10: ";
                    is.clear();
                    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    is >> pazymys;
                }

                obj.paz_.push_back(pazymys);
                suma += pazymys;
                j++;
            } while (true);

            obj.vid_ = suma / j;

            std::cout << "Iveskite egzamino rezultata : ";
            is >> obj.egz_;

            while (obj.egz_ < 1 || obj.egz_ > 10 || is.fail()) {
                std::cout << "Klaida. Iveskite skaiciu nuo 1 iki 10: ";
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                is >> obj.egz_;
            }

            obj.galutinis_ = (obj.vid_ * 0.4) + (obj.egz_ * 0.6);

            std::sort(obj.paz_.begin(), obj.paz_.end());

            obj.med_ = mediana(j, obj);

            return is;
        }

        /**
     * @brief Iðvedimo operatorius, skirtas iðvesti objekto duomenis á iðvesties srautà.
     * @param os Iðvesties srautas
     * @param obj Pazymiai objektas
     * @return Iðvesties srautas
     */
        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Pazymiai& obj) {

            os << std::left << std::setw(15) << obj.var_ << std::setw(15) << obj.pav_ << std::setw(17)
               << std::fixed << std::setprecision(2) << obj.galutinis_ << std::setw(17) << std::fixed
               << std::setprecision(2) << obj.med_ << std::endl;
            return os;
        }

};
/*

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
        virtual std::string getVar() const=0;// { return var_; }
        virtual std::string getPav()=0; //const { return pav_; }
};

class Pazymiai : public Zmogus {
    private:
        double vid_;
        int egz_;
        std::vector<int> paz_;
        double galutinis_;
        double med_;

    public:
        Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

        Pazymiai(const std::string& var, const std::string& pav, double vid, int egz, const std::vector<int>& paz,
                 double galutinis, double med)
            : Zmogus(var, pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

        // copy konstruktorius
        Pazymiai(const Pazymiai& other)
            : Zmogus(other.getVar(), other.getPav()), vid_(other.vid_), egz_(other.egz_),
              paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}

        // move konstruktorius
        Pazymiai(Pazymiai&& other) noexcept
            : Zmogus(std::move(other.var_), std::move(other.pav_)),
              vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
              galutinis_(other.galutinis_), med_(other.med_) {}

        // copy assign operatorius
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

        // move assign operatorius
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

        ~Pazymiai() {paz_.clear();}
        std::string getPav() { return pav_; }//
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
        //std::string getVar() const { return Zmogus::getVar(); }
        std::string getVar() const { return var_; }
        //std::string getPav() const override { return Zmogus::getPav(); }
};
*/
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
