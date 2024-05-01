/**
 * @file pagalbinesvector.h
 * @brief Pazymiai ir Zmogus klasiu deklaracija ir funkciju reiksmiu priskyrimas.
 */
#ifndef PAGALBINESVECTOR_H_INCLUDED
#define PAGALBINESVECTOR_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
#include <stdexcept>
#include <cassert>
/**
* @class Zmogus
 * @brief Klase Zmogus saugo informacija apie studento varda ir pavarde.
 */
class Zmogus {
protected:
    std::string var_; /**< Zmogaus vardas */
    std::string pav_; /**< Zmogaus pavarde */

public:
    /**
     * @brief Numatytasis konstruktorius.
     */
    Zmogus() = default;

    /**
     * @brief Parametrizuotas konstruktorius, inicializuoja varda ir pavarde.
     * @param var Zmogaus vardas
     * @param pav Zmogaus pavarde
     */
    Zmogus(const std::string& var, const std::string& pav) : var_(var), pav_(pav) {}

    /**
     * @brief Virtualus destruktorius.
     */
    virtual ~Zmogus() {}

    /**
     * @brief Nustato studento varda.
     */
    virtual void setVar(const std::string& newVar) { var_ = newVar; }

    /**
     * @brief Nustato studento pavarde.
     */
    virtual void setPav(const std::string& newPav) { pav_ = newPav; }

    /**
     * @brief Grazina zmogaus varda.
     */
    virtual std::string getVar() const = 0;

    /**
     * @brief Grazina zmogaus pavarde.
     */
    virtual std::string getPav() = 0;
};

/**
* @class Pazymiai
 * @brief Klase Pazymiai saugo informacija apie studentu pazymius.
 */
class Pazymiai : public Zmogus {
private:
    double vid_; /**< Vidurkis */
    int egz_; /**< Egzamino rezultatas */
    std::vector<int> paz_; /**< Pazymiu sarasas */
    double galutinis_; /**< Galutinis pazymys */
    double med_; /**< Mediana */

public:
    /**
     * @brief Numatytasis konstruktorius, inicializuoja narius nuliais.
     */
    Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

    /**
     * @brief Parametrizuotas konstruktorius, inicializuoja narius su duotomis reiksmemis.
     * @param var Studento vardas
     * @param pav Studento pavarde
     * @param vid Vidurkis
     * @param egz Egzamino rezultatas
     * @param paz Pazymiu sarasas
     * @param galutinis Galutinis pazymys
     * @param med Mediana
     */
    Pazymiai(const std::string& var, const std::string& pav, double vid, int egz, const std::vector<int>& paz,
             double galutinis, double med)
        : Zmogus(var, pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

    /**
     * @brief Desktruktorius, isvalo vektoriu.
     */
    ~Pazymiai() { paz_.clear(); }
    /**
     * @brief Kopijavimo konstruktorius.
     */
    Pazymiai(const Pazymiai& other)
        : Zmogus(other.getVar(), other.getPav()), vid_(other.vid_), egz_(other.egz_),
          paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}
    /**
     * @brief Perkelimo konstruktorius.
     */
    Pazymiai(Pazymiai&& other) noexcept
        : Zmogus(std::move(other.var_), std::move(other.pav_)),
          vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
          galutinis_(other.galutinis_), med_(other.med_) {}
    /**
     * @brief Kopijavimo priskyrimo operatorius.
     */
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
    /**
     * @brief Perkelimo priskyrimo operatorius.
     */
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

    /**
    * @brief Grazina nurodyta pazymi is saraso pagal pozicija.*/
    int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }

    /**
     * @brief Isvalo vektoriu.
     */
    void clearPaz() { paz_.clear(); }
     /**
    * @brief Nustato studento vidurki.*/
    void setVid(double newVid) { vid_ = newVid; }

    /**
    * @brief Nustato egzamino rezultata.*/
    void setEgz(int newEgz) { egz_ = newEgz; }

    /**
    * @brief Iterpia viena pazymi i sarasa..*/
    void setOnePaz(int newPaz) { paz_.push_back(newPaz); }

    /**
    * @brief Nustato pazymiu sarasa.*/
    void setPazymiai(const std::vector<int>& pazymiai) { paz_ = pazymiai; }

     /**
    * @brief Nustato galutini pazymi.*/
    void setGalutinis(double newGalutinis) { galutinis_ = newGalutinis; }

    /**
    * @brief Nustato mediana.*/
    void setMed(double newMed) { med_ = newMed; }

    /**
    * @brief Rikiuoja pazymiu sarasa.*/
    void sortPaz(Pazymiai& C) { std::sort(C.paz_.begin(), C.paz_.end()); }

    /**
    * @brief Grazina vidurki.*/
    double getVid() const { return vid_; }

    /**
    * @brief Grazina egzamino rezultata.*/
    int getEgz() const { return egz_; }

    /**
    * @brief Grazina pazymiu sarasa.*/
    std::vector<int> getPaz() const { return paz_; }

    /**
    * @brief Grazina galutini pazymi.*/
    double getGalutinis() const { return galutinis_; }

    /**
    * @brief Grazina mediana.*/
    double getMed() const { return med_; }

    /**
     * @brief Grazina zmogaus varda.
     */
    std::string getVar() const override { return var_; }

    /**
     * @brief Grazina zmogaus pavarde.
     */
    std::string getPav() override { return pav_; }

    /**
     * @brief Skaiciuoja mediana.
     * @param u Pazymiu skaicius
     * @param h Pazymiai objektas
     * @return Mediana*/
    friend double mediana(int u, const Pazymiai h);

    /**
     * @brief Ivedimo operatorius, skirtas nuskaityti objekto duomenis is ivesties srauto.
     * @param is Ivesties srautas
     * @param obj Pazymiai objektas, i kuri nuskaitomi duomenys
     * @return Ivesties srautas*/
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
     * @brief Isvedimo operatorius, skirtas isvesti objekto duomenis i isvesties srauta.
     * @param os Isvesties srautas
     * @param obj Pazymiai objektas
     * @return Isvesties srautas
     */
    friend std::ostream& operator<<(std::ostream& os, const Pazymiai& obj) {
        os << std::left << std::setw(15) << obj.var_ << std::setw(15) << obj.pav_ << std::setw(17)
           << std::fixed << std::setprecision(2) << obj.galutinis_ << std::setw(17) << std::fixed
           << std::setprecision(2) << obj.med_ << std::endl;
        return os;
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

void testai();

#endif // PAGALBINES_H_INCLUDED
