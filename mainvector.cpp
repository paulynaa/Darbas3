#include "pagalbinesvector.h"
using namespace std;

int pasirinkimas;
int c;
int x;
int s;
int i=0;
std::vector<Pazymiai> S, P, Z;
/**
 * @brief Pagrindinë funkcija, vykdoma programos pradþioje.
 *
 * @return int Graþinamas nulis, nes funkcija yra tipas int.
 */



int main ()
{

    while (true){
        cout << "Pasirinkite norimà veiksmà: " << endl; // Informacija apie pasirinkimo galimybes
        cout << "1. Ávesti duomenis ranka" << endl; // Galimybë ranka ávesti duomenis
        cout << "2. Generuoti paþymius" << endl; // Galimybë sugeneruoti paþymius
        cout << "3. Generuoti studentø vardus, pavardes ir paþymius" << endl; // Galimybë sugeneruoti studentø duomenis
        cout << "4. Nuskaityti ið failo" << endl; // Galimybë nuskaityti duomenis ið failo
        cout << "5. Generuoti failus" << endl; // Galimybë sugeneruoti failus
        cout << "6. Sugeneruotø failø skaièiavimas" << endl; // Galimybë apskaièiuoti sugeneruotø failø duomenis
        cout << "7. Klasës testavimas" << endl; // Galimybë atlikti klasës testavimà
        cout << "8. Baigti programà" << endl; // Baigti programos darbà
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida. Áveskite skaièiø nuo 1 iki 7. " << endl; // Praneðimas apie klaidà, jei ávestas netinkamas skaièius
            cin.clear(); // Iðvaloma klaidinga ávestis
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Praleidþiamas klaidingas ávesties srautas
        }

        switch (pasirinkimas){
            case 1:{

                // Atvejis 1: Ivesti duomenis ranka
    // Ði dalis leidþia vartotojui ávesti studentø duomenis rankiniu bûdu.

    // Inicializuojamas Pazymiai objektas, skirtas saugoti studentø duomenis
    Pazymiai C;

    // Vartotojas kvieèiamas ávesti studentø duomenis, kol áves "4" arba "4" pavardës laukà
    do {
        // Skaitomi studentø duomenys ið vartotojo
        std::cin >> C;

        // Tikrinama, ar ávestas "4" vienoje ið pavardës arba vardo vietø, nurodydama duomenø ávedimo pabaigà
        if (C.getPav() == "4" || C.getVar() == "4") {
            break; // Iðeiti ið ciklo, jei sàlyga pasiekta
        }

        // Átraukti ávestus studentø duomenis á studentø vektoriø (P)
        P.push_back(C);
    } while (true); // Kartoti, kol pasiekiama pabaigos sàlyga

    // Kai duomenø ávedimas baigtas, atvaizduojami ávesti studentø duomenys
    rezultatai(P);

    break; // Iðeiti ið switch atvejo
            }

            case 2:{

                // Atvejis 2: Generuoti pazymius
    // Ði dalis leidþia vartotojui generuoti studentø duomenis su atsitiktiniais paþymiais.

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas saugoti vieno studento duomenims
    string xx, yy; // Laikini kintamieji vardo ir pavardës saugojimui
    int egg; // Kintamasis saugantis egzamino rezultatà

    do  {
        double suma = 0.0; // Kintamasis saugantis paþymiø sumà

        // Vartotojui leidþiama ávesti vardà ir pavardæ
        cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
        cin >> xx;
        C.setPav(xx);
        if (C.getPav() == "4" || C.getVar() == "4") {
            break; // Iðeiti ið ciklo, jei vartotojas nurodo duomenø ávedimo pabaigà
        }

        cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
        cin >> yy;
        C.setVar(yy);
        if (C.getPav() == "4" || C.getVar() == "4") {
            break; // Iðeiti ið ciklo, jei vartotojas nurodo duomenø ávedimo pabaigà
        }

        // Vartotojas pasirenka, ar nori generuoti atsitiktinius paþymius arba pasirinkti kieká
        cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
        cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
        while (!(cin >> x) || (x != 1 && x != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Vartotojas pasirenka atsitiktiniø arba pasirinktø paþymiø generavimà
        if (x == 1) {
            // Atsitiktiniø paþymiø generavimas
            string y;
            int h = 0;
            while (y != "ne") {
                C.setOnePaz((rand() % 10) + 1); // Generuojamas atsitiktinis paþymys
                cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                cout << "Ar norite testi generavima? taip arba ne: ";
                cin >> y;
                if (y != "taip" && y != "ne") {
                    cout << "Klaida. Prasome ivesti taip arba ne: ";
                    cin>>y;
                }
                suma = suma + C.getPazN(C.getPaz(),h); // Sumuojami paþymiai
                h++;
            }
            C.setVid(suma / h); // Apskaièiuojama paþymiø vidurkis
            C.setMed(mediana(h,C)); // Apskaièiuojama paþymiø mediana
        }

        if (x == 2) {
            // Pasirinktø paþymiø generavimas
            int k;
            cout << "Iveskite pazymiu kieki: ";

            // Tikrinama, ar vartotojas ávedë tinkamà kieká paþymiø
            while (!(cin >> k) || (k < 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite skaiciu nuo 1: ";
            }
            for (int l = 0; l < k; l++) {
                // Generuojamas pasirinktas paþymys
                C.setOnePaz((rand() % 10) + 1);
                cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                suma = suma + C.getPazN(C.getPaz(),l); // Sumuojami paþymiai
            }
            C.setVid(suma / k); // Apskaièiuojama paþymiø vidurkis
            C.sortPaz(C); // Surikiuojami paþymiai didëjimo tvarka
            C.setMed(mediana(k,C)); // Apskaièiuojama paþymiø mediana
        }

        // Vartotojas pasirenka, ar nori atsitiktinai sugeneruoti egzamino rezultatà arba ávesti rankiniu bûdu
        int w;
        cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
        cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
        while (!(cin >> w) || (w != 1 && w != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Vartotojas pasirenka atsitiktinio arba rankinio egzamino rezultato generavimà
        if (w == 1) {
            // Atsitiktinio egzamino rezultato generavimas
            C.setEgz((rand() % 10) + 1); // Generuojamas atsitiktinis egzamino rezultatas
            cout << "Egzamino rezultatas: " << C.getEgz() << endl;
        }

        if (w == 2) {
            // Rankinio egzamino rezultato ávedimas
            cout << "Iveskite egzamino rezultata: " << endl;

            try {
                cin >> egg; // Vartotojo ávestas egzamino rezultatas
                C.setEgz(egg); // Nustatomas egzamino rezultatas

                // Tikrinama, ar vartotojo ávestas egzamino rezultatas tinkamas
                while (cin.fail() || egg < 1 || egg > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                    cin >> egg; // Vartotojo ávestas egzamino rezultatas
                    C.setEgz(egg); // Nustatomas egzamino rezultatas
                }
            } catch (const std::exception& e) {
                cerr << "Exception: " << e.what() << endl; // Klaidos praneðimas, jei ávyksta klaida
            }
            cout << endl; // Tarpas ekrane
        }

        // Apskaièiuojamas galutinis balas pagal formulæ
        C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

        // Átraukti studento duomenis á studentø vektoriø (P)
        P.push_back(C);

        i++; // Padidinti studento skaièiavimo skaitiklá
    } while (C.getPav() != "4" || C.getVar() != "4"); // Ciklas kartojamas tol, kol pasiekiamas duomenø ávedimo pabaigos sàlyga

    // Atvaizduojami ávesti studentø duomenys
    rezultatai(P);

    break; // Iðeiti ið switch atvejo
            }

            case 3:{
                // Atvejis 3: Generuoti ir studentu vardus, pavardes ir pazymius
    // Ði dalis leidþia automatiðkai generuoti studentø duomenis su atsitiktiniais paþymiais.

    int qq = 0; // Kintamasis nusakantis, ar reikia generuoti daugiau studentø
    int egg; // Kintamasis saugantis egzamino rezultatà
    string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"}; // Vardø masyvas
    string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"}; // Pavardþiø masyvas
    string xx, yy; // Laikini kintamieji vardo ir pavardës saugojimui

    // Ciklas kartojamas tol, kol vartotojas nenorës baigti generuoti studentø duomenø
    while (qq != 1) {
        Pazymiai C; // Sukuriamas Pazymiai objektas skirtas saugoti vieno studento duomenims

        // Atsitiktinio vardo ir pavardës pasirinkimas ið masyvø
        xx = pavardes[rand() % 10];
        C.setPav(xx);

        yy = vardai[rand() % 10];
        C.setVar(yy);

        // Atvaizduojami studento vardas ir pavardë
        cout << "Pavarde ir vardas: " << C.getPav() << " " << C.getVar() << endl;

        // Vartotojui leidþiama pasirinkti, ar generuoti atsitiktinius ar pasirinktus paþymius
        cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
        cout << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
        while (!(cin >> x) || (x != 1 && x != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Generuojami arba ávedami paþymiai pagal vartotojo pasirinkimà
        if (x == 1) {
            // Atsitiktiniai paþymiai
            string y;
            int h = 0;
            double suma = 0.0;

            while (y != "Ne") {
                C.setOnePaz((rand() % 10) + 1); // Generuojamas atsitiktinis paþymys
                cout << "Pazymis " << h + 1 << " : " << C.getPazN(C.getPaz(),h) << endl;
                cout << "Ar norite testi generavima? Taip arba Ne: ";
                cin >> y;
                cout << endl;
                suma = suma + C.getPazN(C.getPaz(),h); // Sumuojami paþymiai
                h++;
            }
            C.setVid(suma / h); // Apskaièiuojamas paþymiø vidurkis
            C.sortPaz(C); // Surikiuojami paþymiai didëjimo tvarka
            C.setMed(mediana(h,C)); // Apskaièiuojama paþymiø mediana
        }

        if (x == 2) {
            // Pasirinkti paþymiai
            double suma = 0.0;
            int k;
            cout << "Iveskite pazymiu kieki: ";

            // Tikrinama, ar vartotojas ávedë tinkamà kieká paþymiø
            while (!(cin >> k) || (k < 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite skaiciu nuo 1 : ";
            }

            for (int l = 0; l < k; l++) {
                C.setOnePaz((rand() % 10) + 1); // Generuojamas pasirinktas paþymys
                cout << "Pazymis " << l + 1 << " : " << C.getPazN(C.getPaz(),l) << endl;
                suma = suma + C.getPazN(C.getPaz(),l); // Sumuojami paþymiai
            }

            C.setVid(suma / k); // Apskaièiuojamas paþymiø vidurkis
            C.sortPaz(C); // Surikiuojami paþymiai didëjimo tvarka
            C.setMed(mediana(k,C)); // Apskaièiuojama paþymiø mediana
        }

        // Vartotojui leidþiama pasirinkti, ar generuoti atsitiktiná ar ávestà egzamino rezultatà
        int w;
        cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
        cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
        while (!(cin >> w) || (w != 1 && w != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Generuojamas arba ávedamas egzamino rezultatas pagal vartotojo pasirinkimà
        if (w == 1) {
            // Atsitiktinis egzamino rezultatas
            C.setEgz((rand() % 10) + 1); // Generuojamas atsitiktinis egzamino rezultatas
            cout << "Egzamino rezultatas: " << C.getEgz() << endl;
        }

        if (w == 2) {
            // Ávestas egzamino rezultatas
            cout << "Iveskite egzamino rezultata: " << endl;

            try {
                cin >> egg;
                C.setEgz(egg); // Nustatomas egzamino rezultatas

                // Tikrinama, ar ávestas egzamino rezultatas tinkamas
                while (cin.fail() || egg < 1 || egg > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                    cin >> egg; // Vartotojo ávestas egzamino rezultatas
                    C.setEgz(egg); // Nustatomas egzamino rezultatas
                }
            } catch (const std::exception& e) {
                cerr << "Exception: " << e.what() << endl; // Klaidos praneðimas, jei ávyksta klaida
            }
            cout << endl; // Tarpas ekrane
        }

        // Apskaièiuojamas galutinis balas pagal formulæ
        C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

        // Vartotojui leidþiama pasirinkti, ar generuoti daugiau studentø duomenø
        cout << "Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";

        // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
        while (!(cin >> qq) || (qq != 1 && qq != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu 1 arba 2: ";
        }

        // Átraukiami studento duomenys á studentø vektoriø (P)
        P.push_back(C);
    }

    // Atvaizduojami ávesti studentø duomenys
    rezultatai(P);

    break; // Iðeiti ið switch atvejo
            }

            case 4:{

                // Atvejis 4: Nuskaityti duomenis ið failo

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas saugoti vieno studento duomenims

    int z; // Laikinas kintamasis skaiciui saugoti
    int o; // Vartotojo pasirinkimas, kur iðvesti rezultatus (ekranas ar failas)
    int stud; // Kiek studentø duomenø nuskaityti ið failo
    string zodziai; // Laikinas kintamasis simboliams saugoti
    int xyz; // Vartotojo pasirinkimas, kaip rusiuoti studentus

    int pv = 0; // Kintamasis saugantis paskutiná egzamino rezultato stulpelio numerá
    int numeris; // Kintamasis saugantis vartotojo pasirinktà failo numerá
    string wp; // Kintamasis saugantis failo pavadinimà

    string xx, yy; // Laikini kintamieji studento vardo ir pavardës saugojimui
    int egg; // Laikinas kintamasis egzamino rezultatui saugoti

    // Vartotojui leidþiama pasirinkti, ið kurio failo nuskaityti duomenis
    cout << "Pasirinkite is kurio failo norite nuskaityti: " << endl;
    cout << "1. studentai10000 " << "2. studentai100000 " << "3. studentai1000000 " << "4. kursiokai5 " << endl;

    // Tikrinama, ar vartotojas ávedë tinkamà failo numerá
    while (!(cin >> numeris) || numeris < 1 || numeris > 4) {
        cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Nustatomas pasirinktas failo pavadinimas pagal vartotojo pasirinkimà
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

    // Tikrinama, ar failas egzistuoja
    ifstream file(wp);
    if (!file.is_open()) {
        cout << "Failas " << wp << " neegzistuoja!" << endl;
        break;
    }
    file.close();

    // Skaitoma failo eiluèiø skaièius
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    // Vartotojui leidþiama pasirinkti, kiek studentø duomenø nuskaityti ið failo
    do {
        cout << "Kiek nuskaityti studentu? " << endl;

        // Tikrinama, ar vartotojas ávedë tinkamà studentø kieká
        while (!(cin >> stud) || stud <= 0 || stud > lineCount) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki " << lineCount << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (stud <= 0 || stud > lineCount);

    // Atidaromas failas nuskaitymui
    ifstream F(wp);

    auto start = chrono::steady_clock::now(); // Pradedamas laiko matavimas

    // Skaitomi studentø duomenys ið failo
    while (zodziai != "Egz.") {
        F >> zodziai;
        pv++;
    }

    pv = pv - 3; // Nustatomas paskutinis paþymiø stulpelio numeris

    // Skaitomi duomenys ið failo ir saugomi Pazymiai objekte
    for (int l = 0; l < stud; l++) {
        double suma = 0.0;

        // Nuskaitoma studento vardo ir pavardës informacija
        F >> xx >> yy;
        C.setPav(xx);
        C.setVar(yy);

        // Nuskaitomi studento paþymiai ir skaièiuojamas jø vidurkis
        for (int i = 0; i < pv; i++) {
            F >> z;
            C.setOnePaz(z);
            suma = suma + z;
        }

        // Surikiuojami paþymiai didëjimo tvarka
        C.sortPaz(C);

        // Apskaièiuojamas vidurkis ir pridedamas prie objekto
        C.setVid(suma / pv);

        // Nuskaitomas egzamino rezultatas ir pridedamas prie objekto
        F >> egg;
        C.setEgz(egg);

        // Apskaièiuojamas galutinis balas ir pridedamas prie objekto
        C.setGalutinis((C.getVid() * 0.4) + (0.6 * C.getEgz()));

        // Apskaièiuojama mediana ir pridedama prie objekto
        C.setMed(mediana(pv,C));

        // Pridedami studento duomenys á studentø vektoriø (P)
        P.push_back(C);
    }

    // Uþdaromas failas
    F.close();

    auto end = chrono::steady_clock::now(); // Baigiamas laiko matavimas
    double laikas = chrono::duration <double> (end - start).count(); // Apskaièiuojamas laikas
    cout << "Trukme: " << laikas << " s" << endl; // Atvaizduojama laiko trukmë

    // Vartotojui leidþiama pasirinkti, kaip surikiuoti studentus
    cout << "Jeigu norite rusiuoti pagal pavarde spauskite 1: " << endl;
    cout << "Jeigu norite rusiuoti pagal varda spauskite 2: " << endl;
    cout << "Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: " << endl;
    cout << "Jeigu norite rusiuoti pagal mediana spauskite 4: " << endl;

    // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
    while (!(cin >> xyz)) {
        cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Surikiuojami studentai pagal vartotojo pasirinkimà
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

    // Vartotojui leidþiama pasirinkti, kur iðvesti surikiuotus duomenis
    cout << "Jeigu norite isvesti i ekrana- spauskite 1: " << endl;
    cout << "Jeigu norite isvesti i faila- spauskite 2: " << endl;
    cout << "Jusu pasirinkimas: ";

    // Tikrinama, ar vartotojas ávedë tinkamà pasirinkimà
    while (!(cin >> o)) {
        cout << "Klaida. Iveskite skaiciu 1 arba 2." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Atvaizduojami rezultatai pagal vartotojo pasirinkimà
    if (o == 1) {
        rezultatai(P); // Atvaizduojami rezultatai ekrane
    }
    if (o == 2) {
        rezultataifailas(P, "isvestis.txt"); // Atvaizduojami rezultatai faile
    }

    break; // Baigtas atvejis 4
            }

            case 5:{
                // Atvejis 5: Failø generavimas su atsitiktiniais duomenimis

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas laikinai saugoti duomenims

    // Generuojami failai su atsitiktiniais duomenimis
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

    break; // Baigtas atvejis 5
            }

            case 6:{
                // Atvejis 6: Sugeneruotø failø skaitymas ir apdorojimas

    Pazymiai C; // Sukuriamas Pazymiai objektas skirtas laikinai saugoti duomenims

    // Vartotojui parodomas pasirinkimas strategijos
    cout << "Pasirinkite strategija 1, 2, 3, 4: ";
    int strategy;
    cin >> strategy;

    // Failø vardai
    const vector<string> filenames = {"1k.txt", "10k.txt", "100k.txt", "1kk.txt", "10kk.txt"};
    const vector<string> lopukaiFilenames = {"lopukai1.txt", "lopukai2.txt", "lopukai3.txt", "lopukai4.txt", "lopukai5.txt"};
    const vector<string> saunuoliukaiFilenames = {"saunuoliukai1.txt", "saunuoliukai2.txt", "saunuoliukai3.txt", "saunuoliukai4.txt", "saunuoliukai5.txt"};

    // Iteruojama per visus failus
    for (size_t i = 0; i < filenames.size(); ++i) {
        cout << filenames[i] << " :" << endl;

        // Pasirinktai strategijai atliekami veiksmai su failu
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

        // Rezultatø spausdinimas á failus
        spausdintuvas(lopukaiFilenames[i], saunuoliukaiFilenames[i], P, Z);
    }

    break; // Baigtas atvejis 6
            }

            case 7:{
                // Atvejis 7: Klasiø testavimas
    testai(); // Iðkvieèiamas funkcijos testai() metodas
    break; // Baigtas atvejis 7
            }
            case 8:{
                // Atvejis 8: Programos pabaiga
    cout << "Programa baigta." << endl; // Informacija apie programos pabaigà
    return 0; // Gràþinamas nulis, nurodant, kad programa sëkmingai baigë darbà
    break; // Baigtas atvejis 8 (nereikalingas, nes return funkcija baigia vykdymà)
            }
        }
    }
    return 0;
}

