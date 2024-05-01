# Programos veikimas
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Skaičiuoti sugeneruotus failus; 7.Testuoti klase; 8.Baigti programą.
2. Pasirinkus 1., 2. arba 3. variantą, vartotojas tik suvedimo metu nusprendžia kada jis nori atitinkamai baigti studentų ar pažymių generavimą/suvedimą.
3. Pasirinkus 4. variantą vartotojas turi galimybę pasirinkti failą, nuo kurio bus nuskaityti duomenys (taip pat vartotojas gali pats nustatyti kiek studentų nori nuskaityti).
4. Priklausomai nuo pasirinktos pozicijos, vartotojas suvedęs paskutinius duomenis mato lentelę su rezultatais, kurią galima tęsti pildyti arba paspaudus 5. - baigti programą.
5. Pozicijoje 4. galima pasirinkti duomenų išvedimo būdą: į ekraną arba į tekstinį failą, bei rūšiavimą pagal pavardę, vardą, galutinį pažymį ir medianą.
6. Rezultatų lentelėje/faile išvedami studentų: Pavardė, Vardas, Galutinis(Vid.) ir Galutinis(Med.).
7. Pasirinkus 5. poziciją, vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti.
8. Pasirinkus 6. poziciją, prieš tai sugeneruotus failus programa nuskaito ir surūšiuoja į du naujus failus:viename paskirstyti visi studentai, kurių galutinis pažymis didesnis arba lygus 5, kitame studentai, kurių pažymis mažesnis nei 5. Yra galimybė pasirinkti pagal ką (didėjimo tvarka) bus išvesti rezultatai į naujus failus: pagal galutinį pažymį arba medianą. Taip pat pateikiamas laikas, per kurį sugeneruoti failai buvo nuskaityti, surūšiuoti ir išvesti i du naujus failus.
9. Pasirinkus 7 poziciją, programa testuoja ar konstruktoriai, copy ir move metodai, destruktorius veikia atitinkamai.
# v1.1
**Repozitorijos klonavimas**
Visų pirma repozitorija "Darbas1" buvo nuklonuota ir padaryta nauja repozitorija "Darbas2".

**Pirmas testas**

Palyginome abiejų programų:naudojančių struct ir naudojančių class spartą, naudojant vector konteinerį ir 3 dalijimo strategiją su 1 000 000 ir 10 000 000 dydžio failais.

**Antras testas**

Išanalizavome, kaip keičiasi programos sparta priklausomai nuo kompiliatoriaus optimizavimo lygio , nurodomo per flag'us: -O1, -O2, -O3. Palyginome programas naudojančias struct ir class. Taip pat ziurejome kaip keiciasi exe dydis priklausomai nuo naudojamo flag'o.

# v1.2
**Rule of five**

Atliekant užduotį reikėjo įgyvendinti visus reikiamus "Rule of five" metodus, t.y. copy konstruktorius, copy assignment operatorius, move konstruktorius, move assignment operatorius, destruktorius, taip pat įvesties/išvesties operatorius, kurie veiktų su mano klase.

**Įvestis / išvestis**

Kaip pvz, tai yra isvesties operatorius:

![image](https://github.com/paulynaa/Darbas2/assets/147087833/7a79d9e3-cc30-4e50-b64c-8602cf8f6173)

# v1.5
**class Pazymiai VS bazine class Zmogus ir derived class Pazymiai**
Sioje dalyje reikejo vietoje turimos vienos klasės Pazymiai sukurti dvi: bazinę klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę klasę - Pazymiai.
Zmogui skirta bazinė klasė yra abstrakčioji klasė.
Veliau patikrinome, ar keiciasi programos veikimo sparta priklausomai nuo klases. Rezultatai buvo pateikti lenteleje.

# v2.0
Sukūriau dokumentaciją panaudojant Doxygen. Toliau reikėjo realizuoti Unit Testus su klase naudojant labiausiai patinkantį C++ Unit testų framework'ą.
Štai taip atrodė testai:

![image](https://github.com/paulynaa/Darbas2/assets/147087833/0255bd85-7397-4943-9926-47a9713b67ff)
![image](https://github.com/paulynaa/Darbas2/assets/147087833/94e58666-47a4-4da8-ae02-002e82ed7def)
![image](https://github.com/paulynaa/Darbas2/assets/147087833/65c9b7f7-5e19-4143-a6ab-fc1808bc375f)
![image](https://github.com/paulynaa/Darbas2/assets/147087833/8aa751a9-a2a7-4999-8ddc-d2fa95d5dc52)

Rezultatas:
![image](https://github.com/paulynaa/Darbas2/assets/147087833/ee12c7f2-cd3d-43d8-8e47-bf87182f6dfa)


**Užkomentuota v1.2 versijos klasė(doxygen)**

class Pazymiai {

    private:
        std::string var_; / **< Studento vardas */
        std::string pav_; / **< Studento pavarde */
        double vid_; / **< Vidurkis */
        int egz_; / **< Egzamino rezultatas */
        std::vector<int> paz_; / **< Pazymiu sarasas */
        double galutinis_; / **< Galutinis pazymys */
        double med_; / **< Mediana */
    public:
        /**
         * @brief Numatytasis konstruktorius, inicializuoja narius nuliais.*/
        Pazymiai() : vid_(0), egz_(0), galutinis_(0), med_(0) {}

        /**
         * @brief Parametrizuotas konstruktorius, inicializuoja narius su duotomis reiksmemis.
         * @param var Studento vardas
         * @param pav Studento pavarde
         * @param vid Vidurkis
         * @param egz Egzamino rezultatas
         * @param paz Pazymiu sarasas
         * @param galutinis Galutinis pazymys
         * @param med Mediana*/

        Pazymiai(std::string var, std::string pav, double vid, int egz, const std::vector<int>& paz,
                 double galutinis, double med)
            : var_(var), pav_(pav), vid_(vid), egz_(egz), paz_(paz), galutinis_(galutinis), med_(med) {}

            /**
             * @brief Desktruktorius, isvalo vektoriu ir stringus.*/
        ~Pazymiai() {paz_.clear(); var_.clear(), pav_.clear();}

    // Copy constructor
    /**
    * @brief Kopijavimo konstruktorius.*/
        Pazymiai(const Pazymiai& other)
            : var_(other.var_), pav_(other.pav_), vid_(other.vid_), egz_(other.egz_),
              paz_(other.paz_), galutinis_(other.galutinis_), med_(other.med_) {}

    // Copy assignment operator
    /**
    * @brief Kopijavimo priskyrimo operatorius.*/
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
    * @brief Perkelimo konstruktorius.*/
        Pazymiai(Pazymiai&& other) noexcept
            : var_(std::move(other.var_)), pav_(std::move(other.pav_)),
              vid_(other.vid_), egz_(other.egz_), paz_(std::move(other.paz_)),
              galutinis_(other.galutinis_), med_(other.med_) {}

    // Move assignment operator
    /**
    * @brief Perkelimo priskyrimo operatorius.*/
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
        * @brief Nustato studento varda.*/
        void setVar(const std::string& newVar) { var_ = newVar; }
        /**
        * @brief Nustato studento pavarde.*/
        void setPav(const std::string& newPav) { pav_ = newPav; }
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
        void sortPaz(Pazymiai& C) { sort(C.paz_.begin(), C.paz_.end());}

        /**
        * @brief Grazina studento varda.*/
        std::string getVar() const { return var_; }
        /**
        * @brief Grazina studento pavarde.*/
        std::string getPav() const { return pav_; }
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
        * @brief Grazina nurodyta pazymi is saraso pagal pozicija.*/
        int getPazN(const std::vector<int>& newPaz, int pos) const { return newPaz[pos]; }
        /**
        * @brief Grazina galutini pazymi.*/
        double getGalutinis() const { return galutinis_; }
        /**
        * @brief Grazina mediana.*/
        double getMed() const { return med_; }

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
            // Output operator
            friend std::ostream& operator<<(std::ostream& os, const Pazymiai& obj) {

                os << std::left << std::setw(15) << obj.var_ << std::setw(15) << obj.pav_ << std::setw(17)
                   << std::fixed << std::setprecision(2) << obj.galutinis_ << std::setw(17) << std::fixed
                   << std::setprecision(2) << obj.med_ << std::endl;
                return os;
            }

};

# Doxygen diegimo instrukcija
1. https://www.doxygen.nl/manual/index.html paspaudus šį linka spaudžiame mygtuką Download pagal OS
2. Susiinstaliavus spaudžiame Finish.
3. Sukuriame 2 naujus aplankalus, iš kurio doxygenas pasileis, ir kur matysis rezultatas.
4. Atidarome Doxygen UI ir ten parenkame atitinkamus aplankalus. Source code directory: pažymime aplankalą kuriame yra mūsų jau užkomentuota programa(naudojam @brief, @param, @file, @class, @return).
5. Lange Wizard pereiname į Mode ir pažymime: Documented entities only ir Optimize for C++ output. Pereiname į Output ir žymime: plain HTML, With search function, as intermediate format for hyperlinked PDF. Pereiname į Diagrams ir žymime: Use built-in class diagram generator.
6. Lange Run spaudžiame "Run doxygen" ir "Show HTML output".

# Visual Studio Community 2022
1. Paspaudus šį linką https://visualstudio.microsoft.com/vs/community/ pasirenkame Visual Studio Community 2022 ir spaudžiame "Free download".
2. Instaliuojant pasirenkame tik "Desktop development with C++" ir spaudžiame Install.
3. Pasirenkame "Create a new project" ir vėliau "NativeTest" ir Next.
4. Location pasirenkame norimoj vietoj naujame aplankale.
5. Spaudžiame "Project", "Properties", išskleidžiame C/C++, spaudžiame "Precompiled Headers", skiltyje "Platforms" žymime "All Platforms" ir kur Precompiled Header pažymime Not Using.
6. Nukopijuojame reikalingus failus į testų aplankalą, o VS spaudžiame "Project" ir "Add Existing Item". Tokiu būdu prijungiame failus su klase, kuriuos vėliau testuosime.
7. Parašome kodą ir testuojame.
# Programos diegimo instrukcijos
1. Pirma, turite susikurti savo GitHub paskyrą. Galite pasinaudoti instrukcijomis: https://docs.github.com/en/get-started/onboarding/getting-started-with-your-github-account
2. Norėdami rasti kodą, įveskite nuorodą į paieškos eilę. Pavyzdžiui: https://github.com/paulynaa/Darbas1/tree/v1.0
3. Atidarykite "Command Prompt" (komandinę eilutę) savo kompiuteryje.
4. Į terminalą įveskite šią komandą: git clone https://github.com/paulynaa/Darbas1.git
5. Atidarykite programą, kurioje norite paleisti kodą. Pvz. Paleiskite CodeBlocks IDE. Jei dar neparsisiuntėte jos, galite tai padaryti iš oficialios svetainės: https://www.codeblocks.org/downloads/
6. Kai CodeBlocks įdiegtas, atidarykite jį iš jūsų programų sąrašo arba darbalaukio shortcut'o.
7. Sukurkite naują projektą, pasirinkdami "File" > "New" > "Project..." iš meniu.
8. Pasirinkite "Console Application" ir spustelėkite "Go."
9. Pasirinkite "C++" kaip kalbą ir spustelėkite "Next."
10. Įveskite projekto pavadinimą ir pasirinkite direktoriją, kur norite išsaugoti savo projekto failus. Tada spustelėkite "Next."
11. Pasirinkite "GNU GCC Compiler" ir spustelėkite "Finish."
12. Projekto darbalaukyje raskite vietą, kurioje klonavote GitHub saugyklą, naudodami "File" > "Open" meniu parinktį.
13. Pasirinkite aplanką "Darbas1" ir spustelėkite "Open", kad įkeltumėte projekto failus į CodeBlocks.
14. CodeBlocks darbalaukyje turėtumėte pamatyti failus iš klonuotos saugyklos. Dukart spustelėkite pagrindinį šaltinio failą (main***.cpp), kad jį atidarytumėte.
15. Peržiūrėkite kodą ir atlikite bet kokius būtinus pakeitimus ar pridėjimus.
16. Kai esate pasiruošę sukompiliuoti ir paleisti kodą, spustelėkite "Build and run" mygtuką įrankių juostoje arba pasirinkite "Build" > "Build and run" iš meniu.
17. CodeBlocks sukompiliuos kodą ir paleis programą. Jei nėra klaidų, turėtumėte pamatyti rezultatą CodeBlocks konsolės lange.
18. Dirbant su terminalu galite paleisti programą naudojant makefile failus, prikabintus repozitorijoje, priklausomai nuo norimos programos įrašykite :
    * make vektoriai
    * make programa
    * arba
    * make deque
    * make programa
    * arba
    * make list
    * make programa
19. Kaip naudotis ir kokiu principu veikia programa galite matyti pačioj pradžioj README failo.
