/**
 * @file mainVector.cpp
 * @brief Pagrindinio failo vykdymas
 */
#include "pagalbinesvector.h"
#include "vector.h"
using namespace std;

int pasirinkimas;
int c;
int x;
int s;
int i=0;
Vector<Pazymiai> S, P, Z;
/**
 * @brief Vartotojas is meniu pasirenka norima veiksma ir pagal pasirinkima, veda arba generuoja studentu duomenis.
 */
int main ()
{
    /**
     * @brief Meniu:
     */
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Nuskaityti is failo" << endl;
        cout << "5. Generuoti failus" << endl;
        cout << "6. Sugeneruotu failu skaiciavimas" << endl;
        cout << "7. Klases testavimas" << endl;
        cout << "8. Baigti programa" << endl;
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki 7. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pasirinkimas){
            /**
            * @brief Atvejis 1: Ivesti duomenis ranka
            *Si dalis leidzia vartotojui ivesti studentu duomenis rankiniu budu. Vartotojas gali vesti studentu duomenis, kol ives "4" i studento vardo arba pavardes lauka.
            *Kai duomenu ivedimas baigtas, atvaizduojami ivesti studentu duomenys ekrane
            * @param P Vektorius, i kuri pridedami ivesti duomenys.
            * @param Pazymiai C; Objektas,  kuri laikinai saugomi ivesti duomenys.
            */
            case 1:{
                Pazymiai C;
                do {
                    cin >> C;
                    if (C.getPav() == "4" || C.getVar() == "4") {
                        break;
                    }
                    P.push_back(C);
                } while (true);
                rezultatai(P);
                break;
            }
            /**
            * @brief Atvejis 2: Generuoja tik pazymius.
            *Si dalis leidzia vartotojui generuoti studentu duomenis su atsitiktiniais pazymiais.
            *Vartotojui leidziama ivesti varda ir pavarde
            *Vartotojas pasirenka, ar nori generuoti atsitiktinius pazymius arba pasirinkti kieki
            * Atvaizduojami ivesti studentu duomenys ekrane
            * @param P Vektorius, i kuri pridedami studentu duomenys.
            * @param int i; Skaiciuoja kiek studentu iraso vartotojas.
            * @param Pazymiai C; Studento objektas, i kuri laikinai saugomi studento duomenys.
            * @param string xx, yy; Laikini kintamieji, kuriuose saugomi studento vardas ir pavarde.
            * @param int egg; Kintamasis, kuriame laikinai saugomas studento egzamino rezultatas.
            * @param double suma = 0.0; Kintamasis, kuriame laikinai saugoma pazymiu suma.
            * @param x Laikinas kintamasis, kuriame saugomas vartotojo atsakymas apie generavima.
            * @param string y; Laikinas kintamasis, kuriame saugomas vartotojo atsakymas apie generavimo tesima.
            * @param int h = 0; Skaiciuoja pazymiu kieki.
            * @param int k; Kintamasis, kuriame saugomas pasirinktu pazymiu skaicius.
            * @param int w; Kintamasis, kuriame saugomas vartotojo pasirinkimas apie egzamino rezultata.
            */
            case 2:{
                Pazymiai C;
                string xx, yy;
                int egg;
                do  {
                    double suma = 0.0;
                    cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
                    cin >> xx;
                    C.setPav(xx);
                    if (C.getPav() == "4" || C.getVar() == "4") {
                        break;
                    }
                    cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
                    cin >> yy;
                    C.setVar(yy);
                    if (C.getPav() == "4" || C.getVar() == "4") {
                        break;
                    }

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> x) || (x != 1 && x != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }
                    if (x == 1) {
                        string y;
                        int h = 0;
                        while (y != "ne") {
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                            cout << "Ar norite testi generavima? taip arba ne: ";
                            cin >> y;
                            if (y != "taip" && y != "ne") {
                                cout << "Klaida. Prasome ivesti taip arba ne: ";
                                cin>>y;
                            }
                            suma = suma + C.getPazN(C.getPaz(),h);
                            h++;
                        }
                        C.setVid(suma / h);
                        C.setMed(mediana(h,C));
                    }
                    if (x == 2) {
                        int k;
                        cout << "Iveskite pazymiu kieki: ";
                        while (!(cin >> k) || (k < 1)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1: ";
                        }
                        for (int l = 0; l < k; l++) {
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                            suma = suma + C.getPazN(C.getPaz(),l);
                        }
                        C.setVid(suma / k);
                        C.sortPaz(C);
                        C.setMed(mediana(k,C));
                    }
                    int w;
                    cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
                    cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> w) || (w != 1 && w != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }
                    if (w == 1) {
                        C.setEgz((rand() % 10) + 1);
                        cout << "Egzamino rezultatas: " << C.getEgz() << endl;
                    }
                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;
                        try {
                            cin >> egg;
                            C.setEgz(egg);
                            while (cin.fail() || egg < 1 || egg > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                                cin >> egg;
                                C.setEgz(egg);
                            }
                        } catch (const std::exception& e) {
                            cerr << "Exception: " << e.what() << endl;
                        }
                        cout << endl;
                    }
                    C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));
                    P.push_back(C);
                    i++;
                } while (C.getPav() != "4" || C.getVar() != "4");
                rezultatai(P);
                break;
            }
            /**
            * @brief Atvejis 3: Generuoja studentu vardus, pavardes ir pazymius.
            *Si dalis leidzia automatiskai generuoti studentu duomenis su atsitiktiniais pazymiais.
            *Vartotojui atsitiktinai bus generuojamas studeno vardas ir pavarde kol nebus pasirinkta stabdyti generavima.
            *Vartotojui leidziama pasirinkti, ar generuoti atsitiktinius ar pasirinktus pazymius.
            *Vartotojui leidziama pasirinkti, ar generuoti daugiau studentu duomenu.
            *Atvaizduojami studentu rezultatai ekrane.
            * @param P Vektorius, i kuri pridedami studentu duomenys.
            * @param Pazymiai C; Studento objektas, i kuri laikinai saugomi studento duomenys.
            * @param string xx, yy; Laikini kintamieji, kuriuose saugomi studento vardas ir pavarde.
            * @param x Laikinas kintamasis, kuriame saugomas vartotojo atsakymas apie generavimo buda.
            * @param string y; Laikinas kintamasis, kuriame saugomas vartotojo atsakymas apie generavimo tesima.
            * @param int h = 0; Skaiciuoja pazymiu kieki.
            * @param int k; Kintamasis, kuriame saugomas pasirinktu pazymiu skaicius.
            * @param int w; Kintamasis, kuriame saugomas vartotojo pasirinkimas apie egzamino rezultata.
            * @param int qq=0; Indikuoja, ar norima testi studentu generavima. Jei qq == 1, baigiama studentu generavimo procedura.
            * @param int egg; Saugomas gzamino rezultatas, jei pasirinkta ivesti ranka.
            * @param string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"}; Masyvas, kuriame saugomi studentu vardai, is kuriu bus atsitiktinai generuojami duomenys.
            * @param string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"}; Masyvas, kuriame saugomos studentu pavardes, is kuriu bus atsitiktinai generuojami duomenys.
            */
            case 3:{
                int qq = 0;
                int egg;
                string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"};
                string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"};
                string xx, yy;
                while (qq != 1) {
                    Pazymiai C;
                    xx = pavardes[rand() % 10];
                    C.setPav(xx);
                    yy = vardai[rand() % 10];
                    C.setVar(yy);
                    cout << "Pavarde ir vardas: " << C.getPav() << " " << C.getVar() << endl;

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> x) || (x != 1 && x != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }
                    if (x == 1) {
                        string y;
                        int h = 0;
                        double suma = 0.0;
                        while (y != "Ne") {
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                            cout << "Ar norite testi generavima? Taip arba Ne: ";
                            cin >> y;
                            cout << endl;
                            suma = suma + C.getPazN(C.getPaz(),h);
                            h++;
                        }
                        C.setVid(suma / h);
                        C.sortPaz(C);
                        C.setMed(mediana(h,C));
                    }
                    if (x == 2) {
                        double suma = 0.0;
                        int k;
                        cout << "Iveskite pazymiu kieki: ";
                        while (!(cin >> k) || (k < 1)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1 : ";
                        }
                        for (int l = 0; l < k; l++) {
                            C.setOnePaz((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                            suma = suma + C.getPazN(C.getPaz(),l);
                        }
                        C.setVid(suma / k);
                        C.sortPaz(C);
                        C.setMed(mediana(k,C));
                    }
                    int w;
                    cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
                    cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> w) || (w != 1 && w != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }
                    if (w == 1) {
                        C.setEgz((rand() % 10) + 1);
                        cout << "Egzamino rezultatas: " << C.getEgz() << endl;
                    }
                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;
                        try {
                            cin >> egg;
                            C.setEgz(egg);
                            while (cin.fail() || egg < 1 || egg > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                                cin >> egg;
                                C.setEgz(egg);
                            }
                        } catch (const std::exception& e) {
                            cerr << "Exception: " << e.what() << endl;
                        }
                        cout << endl;
                    }
                    C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));
                    cout << "Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 " << endl;
                    cout << "Jusu pasirinkimas: ";
                    while (!(cin >> qq) || (qq != 1 && qq != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite skaiciu 1 arba 2: ";
                    }
                    P.push_back(C);
                }
                rezultatai(P);
                break;
            }
            /**
            * @brief Atvejis 4: Nuskaito duomenis is pasirinktu failu.
            *Vartotojui leidziama pasirinkti, is kurio failo nuskaityti duomenis.
            *Nustatomas pasirinktas failo pavadinimas pagal vartotojo pasirinkima.
            *Vartotojui leidziama pasirinkti, kiek studentu duomenu nuskaityti is failo.
            *Vartotojui leidziama pasirinkti, kaip surikiuoti studentus.
            *Vartotojui leidziama pasirinkti, kur isvesti surikiuotus duomenis.
            * @param P Vektorius, i kuri pridedami studentu duomenys.
            * @param Pazymiai C; Studento objektas, i kuri laikinai saugomi generuojami duomenys.
            * @param int z; Laikinas kintamasis pazymiui saugoti.
            * @param int o; Vartotojo pasirinkimas, kur isvesti rezultatus (ekranas ar failas).
            * @param int stud; Vartotojo pasirinkimas, kiek studentu duomenu nuskaityti is failo.
            * @param string zodziai; Laikinas kintamasis pirmos eilutes su pavadinimais nuskaitymui.
            * @param int xyz; Vartotojo pasirinkimas, kaip rusiuoti studentus.
            * @param int pv = 0; Kintamasis saugantis nuskaitytu pazymiu kieki.
            * @param int numeris; Kintamasis saugantis vartotojo pasirinkta failo numeri.
            * @param string wp; Kintamasis saugantis failo pavadinima.
            * @param string xx, yy; Laikini kintamieji studento vardo ir pavardes saugojimui.
            * @param int egg; Laikinas kintamasis egzamino rezultatui saugoti.
            */
            case 4:{
                Pazymiai C;
                int z;
                int o;
                int stud;
                string zodziai;
                int xyz;
                int pv = 0;
                int numeris;
                string wp;
                string xx, yy;
                int egg;
                cout << "Pasirinkite is kurio failo norite nuskaityti: " << endl;
                cout << "1. studentai10000 " << "2. studentai100000 " << "3. studentai1000000 " << "4. kursiokai5 " << endl;
                while (!(cin >> numeris) || numeris < 1 || numeris > 4) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                switch (numeris) {
                    case 1:
                        wp = "studentai10000.txt";
                        break;
                    case 2:
                        wp = "studentai100000.txt";
                        break;
                    case 3:
                        wp = "studentai1000000.txt";
                        break;
                    case 4:
                        wp = "kursiokai.txt";
                        break;
                    default:
                        break;
                }
                ifstream file(wp);
                if (!file.is_open()) {
                    cout << "Failas " << wp << " neegzistuoja!" << endl;
                    break;
                }
                file.close();
                int lineCount = 0;
                string line;
                file.open(wp);
                while (getline(file, line)) {
                    lineCount++;
                }
                file.close();
                do {
                    cout << "Kiek nuskaityti studentu? " << endl;
                    while (!(cin >> stud) || stud <= 0 || stud > lineCount) {
                        cout << "Klaida. Iveskite skaiciu nuo 1 iki " << lineCount << "." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (stud <= 0 || stud > lineCount);
                ifstream F(wp);
                auto start = chrono::steady_clock::now();
                while (zodziai != "Egz.") {
                    F >> zodziai;
                    pv++;
                }
                pv = pv - 3;
                for (int l = 0; l < stud; l++) {
                    double suma = 0.0;
                    F >> xx >> yy;
                    C.setPav(xx);
                    C.setVar(yy);
                    for (int i = 0; i < pv; i++) {
                        F >> z;
                        C.setOnePaz(z);
                        suma = suma + z;
                    }
                    C.sortPaz(C);
                    C.setVid(suma / pv);
                    F >> egg;
                    C.setEgz(egg);
                    C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));
                    C.setMed(mediana(pv,C));
                    P.push_back(C);
                }
                F.close();
                auto end = chrono::steady_clock::now();
                double laikas = chrono::duration <double> (end - start).count();
                cout << "Trukme: " << laikas << " s" << endl;
                cout << "Jeigu norite rusiuoti pagal pavarde spauskite 1: " << endl;
                cout << "Jeigu norite rusiuoti pagal varda spauskite 2: " << endl;
                cout << "Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: " << endl;
                cout << "Jeigu norite rusiuoti pagal mediana spauskite 4: " << endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (xyz == 1) {
                    sort(C.getPav().begin(), C.getPav().end());
                }
                if (xyz == 2) {
                    sort(C.getVar().begin(), C.getVar().end());
                }
                if (xyz == 3) {
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                }
                if (xyz == 4) {
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.getMed() < b.getMed();
                    });
                }
                cout << "Jeigu norite isvesti i ekrana- spauskite 1: " << endl;
                cout << "Jeigu norite isvesti i faila- spauskite 2: " << endl;
                cout << "Jusu pasirinkimas: ";
                while (!(cin >> o)) {
                    cout << "Klaida. Iveskite skaiciu 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (o == 1) {
                    rezultatai(P);
                }
                if (o == 2) {
                    rezultataifailas(P, "isvestis.txt");
                }
                break;
            }

            /**
            * @brief Atvejis 5: Generuoja failus su atsitiktiniais duomenimis duomenimis.
            *Generuojami failai yra skirtingu dydziu(1000, 10 000, 100 000, 1 000 000, 10 000 000).
            * @param Pazymiai C; Studento objektas, i kuri laikinai saugomi generuojami duomenys.
            */
            case 5:{
                Pazymiai C;
                cout << "1k :" << endl;
                generuojam(1000, "1k.txt");
                cout << "10k :" << endl;
                generuojam(10000, "10k.txt");
                cout << "100k :" << endl;
                generuojam(100000, "100k.txt");
                cout << "1mln :" << endl;
                generuojam(1000000, "1kk.txt");
                cout << "10mln :" << endl;
                generuojam(10000000, "10kk.txt");
                cout << "Failai sugeneruoti! " << endl;
                cout << endl;
                break;
            }
            /**
            * @brief Atvejis 6: Sugeneruotu failu skaitymas ir apdorojimas.
            *Vartotojas pasirenka strategijas, pagal kurias failai bus skaiciuojami.
            *Rezultatai isspausdinami i failus.
            * @param Pazymiai C; Studento objektas, i kuri laikinai saugomi generuojami duomenys.
            * @param S Vektorius, i kuri pridedami visu studentu duomenys.
            * @param P Vektorius, i kuri pridedami studentu duomenys, kuriu vidurkis didesnis nei 5.
            * @param Z Vektorius, i kuri pridedami studentu duomenys, kuriu vidurkis mazesnis uz 5.
            * @param int strategy; Pasirinkta strategija, pagal kuria vykdomas failu apdorojimas.
            * @param const Vector<string> filenames = {"1k.txt", "10k.txt", "100k.txt", "1kk.txt", "10kk.txt"}; Vektorius, saugantis failu pavadinimus, kurie bus apdorojami.
            * @param const Vector<string> lopukaiFilenames = {"lopukai1.txt", "lopukai2.txt", "lopukai3.txt", "lopukai4.txt", "lopukai5.txt"}; Vektorius, saugantis failu pavadinimus, kuriuose bus isvedami rezultatai.
            * @param const Vector<string> saunuoliukaiFilenames = {"saunuoliukai1.txt", "saunuoliukai2.txt", "saunuoliukai3.txt", "saunuoliukai4.txt", "saunuoliukai5.txt"}; Vektorius, saugantis failu pavadinimus, kuriuose bus isvedami rezultatai.
            */
            case 6:{
                Pazymiai C;
                cout << "Pasirinkite strategija 1, 2, 3, 4: ";
                int strategy;
                cin >> strategy;
                const Vector<string> filenames = {"1k.txt", "10k.txt", "100k.txt", "1kk.txt", "10kk.txt"};
                const Vector<string> lopukaiFilenames = {"lopukai1.txt", "lopukai2.txt", "lopukai3.txt", "lopukai4.txt", "lopukai5.txt"};
                const Vector<string> saunuoliukaiFilenames = {"saunuoliukai1.txt", "saunuoliukai2.txt", "saunuoliukai3.txt", "saunuoliukai4.txt", "saunuoliukai5.txt"};
                for (size_t i = 0; i < filenames.size(); ++i) {
                    cout << filenames[i] << " :" << endl;
                    switch (strategy) {
                        case 1:
                            failuskaickstrategija1(filenames[i], C, S, P, Z);
                            break;
                        case 2:
                            failuskaickstrategija2(filenames[i], C, P, Z);
                            break;
                        case 3:
                            failuskaickstrategija3(filenames[i], C, S, P, Z);
                            break;
                        case 4:
                            failuskaick(filenames[i], C, P, Z);
                            break;
                        default:
                            cout << "Tokia strategija neegzistuoja!" << endl;
                            break;
                    }
                    spausdintuvas(lopukaiFilenames[i], saunuoliukaiFilenames[i], P, Z);
                }
                break;
            }
            /**
            * @brief Atvejis 7: Klasiu testavimas.
            *Iskvieciamas funkcijos testai() ir ekrane matome testu rezultata.
            */
            case 7:{

                testai();
                unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
            Vector<int> v1;
            int std_vector_perskirstymas = 0;
            for (int i = 1; i <= sz; ++i) {
                v1.push_back(i);
                if (v1.capacity() == v1.size()) {
                    ++std_vector_perskirstymas;
                }
            }
            cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

            Vector<int> v2;
            int vector_perskirstymas = 0;
            for (int i = 1; i <= sz; ++i) {
                v2.push_back(i);
                if (v2.capacity() == v2.size()) {
                    ++vector_perskirstymas;
                }
            }
            cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;

                break;
            }
            /**
            * @brief Atvejis 8: Programos pabaiga
            * @return Grazinamas nulis, nurodantis, kad programa sekmingai baige darba
            */
            case 8:{
                cout << "Programa baigta." << endl;
                return 0;
                break;
            }
        }
    }
    return 0;
}

