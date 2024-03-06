#include "pagalbines.h"
using namespace std;

int pasirinkimas;
int c;
int x;
int s;
int i=0;
double laiku_suma = 0.0;

std::vector<Pazymiai> P, Z;


int main ()
{


    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Nuskaityti is failo" << endl;
        cout << "5. Failu generavimas" << endl;
        cout << "6. Baigti programa" << endl;
        if (!(cin >> pasirinkimas)) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki 5. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pasirinkimas){
            case 1:{

                Pazymiai C;
                C.vid=0.0;
                do{

                    double suma=0.0;

                    cout<<"Iveskite "<<i+1<<" pavarde (noretume baigti spauskite 4):   "<<endl;
                    cin>>C.pav;
                    if(C.pav=="4" || C.var=="4"){
                        break;
                    }
                    cout<<"Iveskite "<<i+1<<" varda (noretume baigti spauskite 4):   "<<endl;
                    cin>>C.var;
                    if(C.pav=="4" || C.var=="4"){
                        break;
                    }

                    int j=0;

                    do{
                        cout<<"Iveskite "<<j+1<<" pazymi nuo 1 iki 10(noredami baigti spauskite 11): ";
                        cin>>x;

                        if(x==11){
                            break;
                        }

                        while (cin.fail() || x < 1 || x > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                                cout<<"Iveskite "<<j+1<<" pazymi nuo 1 iki 10(noredami baigti spauskite 11): ";
                                cin >> x;
                                if(x==11){
                                    break;
                                }
                        }

                        C.paz.push_back(x);
                        suma = suma + x;
                        j++;
                    } while(x!=11);

                    C.vid=suma/j;

                    cout << "Iveskite egzamino rezultata: " << endl;

                    try {
                        cin >> C.egz;

                        while (cin.fail() || C.egz < 1 || C.egz > 10) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                            cin >> C.egz;
                        }
                    } catch (const std::exception& e) {
                        
                        cerr << "Exception: " << e.what() << endl;
                        
                    }

                    C.galutinis=(C.vid*0.4)+(0.6*C.egz);
                    sort(C.paz.begin(), C.paz.end());

                    C.med=mediana(j,C);

                    P.push_back(C);
                    i++;
                } while(C.pav!="4" || C.var!="4");

                rezultatai(P);
                break;
            }

            case 2:{

                Pazymiai C;
                do  {
                    double suma = 0.0;

                    cout << "Iveskite " << i + 1 << " pavarde (noredami sustoti iveskite 4):   " << endl;
                    cin >> C.pav;
                    if (C.pav == "4" || C.var == "4") {
                        break;
                    }

                    cout << "Iveskite " << i + 1 << " varda (noredami sustoti iveskite 4):   " << endl;
                    cin >> C.var;
                    if (C.pav == "4" || C.var == "4") {
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
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.paz[h] << endl;
                            cout << "Ar norite testi generavima? taip arba ne: ";
                            cin >> y;
                            if (y != "taip" && y != "ne") {
                                cout << "Klaida. Prasome ivesti taip arba ne: ";
                                cin>>y;
                            }
                            suma = suma + C.paz[h];
                            h++;
                        }
                        C.vid = suma / h;
                        sort(C.paz.begin(), C.paz.end());
                        C.med=mediana(h,C);
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
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.paz[l] << endl;
                            suma = suma + C.paz[l];
                        }
                        C.vid = suma / k;
                        sort(C.paz.begin(), C.paz.end());

                        C.med=mediana(k,C);
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
                        C.egz = (rand() % 10) + 1;
                        cout << "Egzamino rezultatas: " << C.egz << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;

                        try {
                            cin >> C.egz;

                            while (cin.fail() || C.egz < 1 || C.egz > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                                cin >> C.egz;
                            }
                        } catch (const std::exception& e) {
                            // Handle the exception
                            cerr << "Exception: " << e.what() << endl;
                            // Optionally, take further action or exit the program
                            }
                        cout << endl;
                    }

                    C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);
                    P.push_back(C);
                    i++;
                } while (C.pav != "4" || C.var != "4");

                rezultatai(P);
                break;
            }

            case 3:{
                int qq = 0;
                string vardai[] = {"Paulina", "Adriana", "Gitanas", "Donald", "Ugne", "Kamile", "Rugile", "Roberta", "Valdemaras", "Jurgis"};
                string pavardes[] = {"Podgaiska", "Obama", "Trump", "Nauseda", "Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte", "Jankauskas"};

                while (qq != 1) {
                    Pazymiai C;
                    C.pav = pavardes[rand() % 10];
                    C.var = vardai[rand() % 10];
                    cout << "Pavarde ir vardas: " << C.pav << " " << C.var << endl;

                    cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl;
                    cout<< "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
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
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << h + 1 << " : " << C.paz[h] << endl;
                            cout << "Ar norite testi generavima? Taip arba Ne: ";
                            cin >> y;
                            cout << endl;
                            suma = suma + C.paz[h];
                            h++;
                        }
                        C.vid = suma / h;

                        sort(C.paz.begin(), C.paz.end());

                        C.med=mediana(h,C);
                    }

                    if (x == 2) {
                        double suma = 0.0;
                        int k;
                        cout << "Iveskite pazymiu kieki: ";

                        while (!(cin >> k) || (k < 1 )) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Iveskite skaiciu nuo 1 : ";
                        }

                        for (int l = 0; l < k; l++) {
                            C.paz.push_back((rand() % 10) + 1);
                            cout << "Pazymis " << l + 1 << " : " << C.paz[l] << endl;
                            suma = suma + C.paz[l];
                        }

                        C.vid = suma / k;

                        sort(C.paz.begin(), C.paz.end());

                        C.med=mediana(k,C);
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
                        C.egz = (rand() % 10) + 1;
                        cout << "Egzamino rezultatas: " << C.egz << endl;
                    }

                    if (w == 2) {
                        cout << "Iveskite egzamino rezultata: " << endl;

                        try {
                            cin >> C.egz;

                            while (cin.fail() || C.egz < 1 || C.egz > 10) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
                                cin >> C.egz;
                            }
                        } catch (const std::exception& e) {
                            // Handle the exception
                            cerr << "Exception: " << e.what() << endl;
                            // Optionally, take further action or exit the program
                        }
                        cout << endl;
                    }

                    C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);

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

            case 4:{

                Pazymiai C;

                int z;
                int o;
                int stud;
                string zodziai;
                int xyz;
                int pv=0;
                int numeris;
                string wp;
                double laiku_suma=0.0;

                cout<<"Pasirinkite is kurio failo norite nuskaityti: "<<endl;
                cout<<"1. studentai10000 "<<"2. studentai100000 "<<"3. studentai1000000 "<<"4. kursiokai5 "<<endl;

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

                                while( zodziai != "Egz."){
                                    F>>zodziai;
                                    pv++;
                                }

                                pv=pv-3;

                                for(int l=0; l<stud; l++){
                                    double suma=0.0;
                                    C.paz.clear();
                                    F>>C.pav>>C.var;

                                    for(int i=0; i<pv; i++){
                                        F>>z;
                                        C.paz.push_back(z);
                                        suma=suma+z;
                                    }

                                    sort(C.paz.begin(), C.paz.end());

                                    C.vid=suma/pv;

                                    F>>C.egz;

                                    C.galutinis=(C.vid*0.4)+(0.6*C.egz);

                    C.med=mediana(pv,C);

                    P.push_back(C);

                }

                vector<double> laikai;

                F.close();
                auto end = chrono::steady_clock::now();
                double laikas=chrono::duration <double> (end - start).count();
                laikai.push_back(laikas);
                cout<<"Trukme: "<< laikas << " s"<<endl;

                /*for (auto laikas : laikai) {
                    laiku_suma += laikas;
                }
                double laiku_vidurkis =(laikai.size() > 0) ? (laiku_suma / laikai.size()) : 0.0;
                cout << "Vidutine trukme: " << laiku_vidurkis << " s" << endl;
                */

                cout<<"Jeigu norite rusiuoti pagal pavarde spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal varda spauskite 2: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 4: "<<endl;

                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(xyz==1){
                    sort(C.pav.begin(),C.pav.end());
                }
                if(xyz==2){
                    sort(C.var.begin(),C.var.end());
                }
                if(xyz==3){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.galutinis < b.galutinis;
                    });
                }
                if(xyz==4){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                }

                cout<<"Jeigu norite isvesti i ekrana- spauskite 1: "<<endl;
                cout<<"Jeigu norite isvesti i faila- spauskite 2: "<<endl;
                cout<<"Jusu pasirinkimas: ";

                while (!(cin >> o)) {
                    cout << "Klaida. Iveskite skaiciu 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if(o==1){
                    rezultatai(P);
                }
                if(o==2){
                    rezultataifailas(P, "isvestis.txt");
                }

                break;
            }

            case 5:{
                auto viskas = chrono::steady_clock::now();
                Pazymiai C;
                //pirmas---------------
                auto start_time = std::chrono::high_resolution_clock::now();

    std::ofstream V("1k.txt");
    V <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kiki;
    kiki = (rand() % 15) + 5;
    for(int i=0; i<kiki; i++){
    V<< "ND"<<i+1<<" ";
    }
    V<< "Egz."<<std::endl;

    for(int i=0; i<1000; i++){

        V<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<kiki+1; j++){
            int nd=(rand() % 10) + 1;
            V<<nd<<" ";
        }
        V<<std::endl;
    }
    V.close();
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
std::cout << "1k Generavimo trukme: " << duration << " milisekundes." << std::endl;
//antras----------------------
auto start_timef = std::chrono::high_resolution_clock::now();
    std::ofstream Vf("10k.txt");
    Vf <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kikif;
    kikif = (rand() % 15) + 5;
    for(int i=0; i<kikif; i++){
    Vf<< "ND"<<i+1<<" ";
    }
    Vf<< "Egz."<<std::endl;

    for(int i=0; i<10000; i++){

        Vf<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<kikif+1; j++){
            int ndf=(rand() % 10) + 1;
            Vf<<ndf<<" ";
        }
        Vf<<std::endl;
    }
    Vf.close();
    auto end_timef = std::chrono::high_resolution_clock::now();

    auto durationf = std::chrono::duration_cast<std::chrono::milliseconds>(end_timef - start_timef).count();


    std::cout << "10k Generavimo trukme: " << durationf << " milisekundes." << std::endl;
//trecias------------------
    auto start_timeb = std::chrono::high_resolution_clock::now();
    std::ofstream Vb("100k.txt");
    Vb <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kikib;
    kikib = (rand() % 15) + 5;
    for(int i=0; i<kiki; i++){
    Vb<< "ND"<<i+1<<" ";
    }
    Vb<< "Egz."<<std::endl;

    for(int i=0; i<100000; i++){

        Vb<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<kikib+1; j++){
            int ndb=(rand() % 10) + 1;
            Vb<<ndb<<" ";
        }
        Vb<<std::endl;
    }
    V.close();
    auto end_timeb = std::chrono::high_resolution_clock::now();

    auto durationb = std::chrono::duration_cast<std::chrono::milliseconds>(end_timeb - start_timeb).count();


    std::cout << "100k Generavimo trukme: " << durationb << " milisekundes." << std::endl;
//ketvirtas-------------------------
    auto start_timex = std::chrono::high_resolution_clock::now();
    std::ofstream Vx("1kk.txt");
    Vx <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kikix;
    kikix = (rand() % 15) + 5;
    for(int i=0; i<kikix; i++){
    Vx<< "ND"<<i+1<<" ";
    }
    Vx<< "Egz."<<std::endl;

    for(int i=0; i<1000000; i++){

        Vx<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<kikix+1; j++){
            int ndx=(rand() % 10) + 1;
            Vx<<ndx<<" ";
        }
        Vx<<std::endl;
    }
    V.close();
    auto end_timex = std::chrono::high_resolution_clock::now();

    auto durationx = std::chrono::duration_cast<std::chrono::seconds>(end_timex - start_timex).count();


    std::cout << "1mln Generavimo trukme: " << durationx << " sekundes." << std::endl;
//penktas--------------------------
    auto start_timev = std::chrono::high_resolution_clock::now();
    std::ofstream Vv("10kk.txt");
    Vv <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kikiv;
    kikiv = (rand() % 15) + 5;
    for(int i=0; i<kikiv; i++){
    Vv<< "ND"<<i+1<<" ";
    }
    Vv<< "Egz."<<std::endl;

    for(int i=0; i<10000000; i++){

        V<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<kikiv+1; j++){
            int ndv=(rand() % 10) + 1;
            Vv<<ndv<<" ";
        }
        V<<std::endl;
    }
    Vv.close();
    auto end_timev = std::chrono::high_resolution_clock::now();

    auto durationv = std::chrono::duration_cast<std::chrono::seconds>(end_timev - start_timev).count();


    std::cout << "10mln Generavimo trukme: " << durationv << " sekundes." << std::endl;
    
                
//pirmas----------------------------
std::cout<<"1k:"<<endl;
int z;
    std::ifstream file("1k.txt");

    if (!file.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    file.close();
    int lineCount = 0;
    std::string line;
    file.open("1k.txt");
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    std::ifstream F("1k.txt");
    std::string zodziai;
    int pv=0;

auto nus = std::chrono::high_resolution_clock::now();
    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }

    pv=pv-3;
double suum=0;
    for(int l=0; l<lineCount-1; l++){
        double suma=0.0;
        C.paz.clear();
        F>>C.pav>>C.var;

        for(int i=0; i<pv; i++){
            F>>z;
            C.paz.push_back(z);
            suma=suma+z;
        }

        sort(C.paz.begin(), C.paz.end());

        C.vid=suma/pv;

        F>>C.egz;

        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
        C.med=mediana(pv,C);
auto pra = std::chrono::high_resolution_clock::now();
        if(C.galutinis>=5){
            P.push_back(C);
        }
        else {Z.push_back(C);}

auto pab = std::chrono::high_resolution_clock::now();

    float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
suum=suum+trukme;
    }
std::cout << "Rusiavimo trukme: " << suum << " milisekundes." << std::endl;
    F.close();
auto nusk = std::chrono::high_resolution_clock::now();

    auto laikas = std::chrono::duration_cast<std::chrono::milliseconds>(nusk - nus).count();


    std::cout << "Nuskaitymo trukme: " << laikas << " milisekundes." << std::endl;
int xyz;
cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(xyz==1){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.galutinis < b.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;
                    });

                }
                if(xyz==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });
                }
//irasymas
auto p = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, "lopukai1.txt");
    rezultataifailas(P, "saunuoliukai1.txt");
auto b = std::chrono::high_resolution_clock::now();

    auto isvestis = std::chrono::duration_cast<std::chrono::milliseconds>(b - p).count();


    std::cout << "Isvedimo trukme: " << isvestis << " milisekundes." << std::endl;

//antras----------------------------
std::cout<<"10k: "<<endl;
    int m;
    std::ifstream filee("10k.txt");

    if (!filee.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    filee.close();
    int lineCoun = 0;
    std::string lines;
    filee.open("10k.txt");
    while (getline(filee, lines)) {
        lineCoun++;
    }
    filee.close();

    std::ifstream g("10k.txt");
    std::string zodzia;
    int pvv=0;

auto nusd = std::chrono::high_resolution_clock::now();
    while( zodzia != "Egz."){
        g>>zodzia;
        pvv++;
    }

    pvv=pvv-3;
double suumd=0;
    for(int l=0; l<lineCoun-1; l++){
        double suma=0.0;
        C.paz.clear();
        g>>C.pav>>C.var;

        for(int i=0; i<pvv; i++){
            g>>m;
            C.paz.push_back(m);
            suma=suma+z;
        }

        sort(C.paz.begin(), C.paz.end());

        C.vid=suma/pvv;

        g>>C.egz;

        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
        C.med=mediana(pvv,C);
auto prad = std::chrono::high_resolution_clock::now();
        if(C.galutinis>=5){
            P.push_back(C);
        }
        else {Z.push_back(C);}

auto pabd = std::chrono::high_resolution_clock::now();

    float trukmed = std::chrono::duration_cast<std::chrono::milliseconds>(pabd - prad).count();
suumd=suumd+trukmed;
    }
std::cout << "Rusiavimo trukme: " << suumd << " milisekundes." << std::endl;
    g.close();
auto nuskd = std::chrono::high_resolution_clock::now();

    auto laikasd = std::chrono::duration_cast<std::chrono::milliseconds>(nuskd - nusd).count();


    std::cout << "Nuskaitymo trukme: " << laikasd << " milisekundes." << std::endl;

int xyzq;
cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyzq)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(xyzq==1){
                    sort(P.begin(), P.end(), [](const Pazymiai &aw, const Pazymiai &bw) {
                        return aw.galutinis < bw.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aaq, const Pazymiai &bbq) {
                        return aaq.galutinis < bbq.galutinis;
                    });

                }
                if(xyzq==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &aw, const Pazymiai &bw) {
                        return aw.med < bw.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aaq, const Pazymiai &bbq) {
                        return aaq.med < bbq.med;
                    });
                }
//isvestis
auto pq = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, "lopukai2.txt");
    rezultataifailas(P, "saunuoliukai2.txt");
auto bq = std::chrono::high_resolution_clock::now();

    auto isvestisq = std::chrono::duration_cast<std::chrono::milliseconds>(bq - pq).count();


    std::cout << "Isvedimo trukme: " << isvestisq << " milisekundes." << std::endl;


//trecias--------------------------

std::cout<<"100k: "<<endl;

int q;
    std::ifstream fileq("100k.txt");

    if (!fileq.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    fileq.close();
    int lineCounts = 0;
    std::string linez;
    fileq.open("100k.txt");
    while (getline(fileq, linez)) {
        lineCounts++;
    }
    fileq.close();

    std::ifstream Fw("100k.txt");
    std::string zodziaia;
    int pvq=0;

auto nusw = std::chrono::high_resolution_clock::now();
    while( zodziaia != "Egz."){
        Fw>>zodziaia;
        pvq++;
    }

    pvq=pvq-3;
double suumw=0;
    for(int l=0; l<lineCounts-1; l++){
        double suma=0.0;
        C.paz.clear();
        Fw>>C.pav>>C.var;

        for(int i=0; i<pvq; i++){
            Fw>>q;
            C.paz.push_back(z);
            suma=suma+q;
        }

        sort(C.paz.begin(), C.paz.end());

        C.vid=suma/pvq;

        Fw>>C.egz;

        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
        C.med=mediana(pvq,C);
auto praw = std::chrono::high_resolution_clock::now();
        if(C.galutinis>=5){
            P.push_back(C);
        }
        else {Z.push_back(C);}

auto pabw = std::chrono::high_resolution_clock::now();

    float trukmew = std::chrono::duration_cast<std::chrono::milliseconds>(pabw - praw).count();
suumw=suumw+trukmew;
    }
std::cout << "Rusiavimo trukme: " << suumw << " milisekundes." << std::endl;
    Fw.close();
auto nuskw = std::chrono::high_resolution_clock::now();

    auto laikasw = std::chrono::duration_cast<std::chrono::milliseconds>(nuskw - nusw).count();


    std::cout << "Nuskaitymo trukme: " << laikasw << " milisekundes." << std::endl;

int xy;
cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xy)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(xy==1){
                    sort(P.begin(), P.end(), [](const Pazymiai &ae, const Pazymiai &be) {
                        return ae.galutinis < be.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aae, const Pazymiai &bbe) {
                        return aae.galutinis < bbe.galutinis;
                    });

                }
                if(xy==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &ae, const Pazymiai &be) {
                        return ae.med < be.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aae, const Pazymiai &bbe) {
                        return aae.med < bbe.med;
                    });
                }
//isvestis
auto pt = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, "lopukai3.txt");
    rezultataifailas(P, "saunuoliukai3.txt");
auto bt = std::chrono::high_resolution_clock::now();

    auto isvestist = std::chrono::duration_cast<std::chrono::milliseconds>(bt - pt).count();


    std::cout << "Isvedimo trukme: " << isvestist << " milisekundes." << std::endl;



//ketvirtas---------------------------



std::cout<<"1mln: "<<endl;
int zx;
    std::ifstream filed("1kk.txt");

    if (!filed.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    filed.close();
    int lineCounta = 0;
    std::string linec;
    filed.open("1kk.txt");
    while (getline(filed, linec)) {
        lineCounta++;
    }
    filed.close();

    std::ifstream Fn("1kk.txt");
    std::string zodziait;
    int pvx=0;

auto nusx = std::chrono::high_resolution_clock::now();
    while( zodziait != "Egz."){
        Fn>>zodziait;
        pvx++;
    }

    pvx=pvx-3;
double suumx=0;
    for(int l=0; l<lineCounta-1; l++){
        double sumax=0.0;
        C.paz.clear();
        Fn>>C.pav>>C.var;

        for(int i=0; i<pvx; i++){
            Fn>>zx;
            C.paz.push_back(zx);
            sumax=sumax+z;
        }

        sort(C.paz.begin(), C.paz.end());

        C.vid=sumax/pv;

        Fn>>C.egz;

        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
        C.med=mediana(pvx,C);
auto prax = std::chrono::high_resolution_clock::now();
        if(C.galutinis>=5){
            P.push_back(C);
        }
        else {Z.push_back(C);}

auto pabx = std::chrono::high_resolution_clock::now();

    float trukmex = std::chrono::duration_cast<std::chrono::milliseconds>(pabx - prax).count();
suumx=suumx+trukmex;
    }
std::cout << "Rusiavimo trukme: " << suumx << " milisekundes." << std::endl;
    Fn.close();
auto nuskx = std::chrono::high_resolution_clock::now();

    auto laikasx = std::chrono::duration_cast<std::chrono::milliseconds>(nuskx - nusx).count();


    std::cout << "Nuskaitymo trukme: " << laikasx << " milisekundes." << std::endl;
int xyzz;
cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyzz)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(xyzz==1){
                    sort(P.begin(), P.end(), [](const Pazymiai &az, const Pazymiai &bz) {
                        return az.galutinis < bz.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aaz, const Pazymiai &bbz) {
                        return aaz.galutinis < bbz.galutinis;
                    });

                }
                if(xyzz==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &az, const Pazymiai &bz) {
                        return az.med < bz.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aaz, const Pazymiai &bbz) {
                        return aaz.med < bbz.med;
                    });
                }
//isvestis
auto pn = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, "lopukai4.txt");
    rezultataifailas(P, "saunuoliukai4.txt");
auto bn = std::chrono::high_resolution_clock::now();

    auto isvestisn = std::chrono::duration_cast<std::chrono::milliseconds>(bn - pn).count();


    std::cout << "Isvedimo trukme: " << isvestisn << " milisekundes." << std::endl;

//penktas---------------------

std::cout<<"10mln: "<<endl;
int zf;
    std::ifstream filef("10kk.txt");

    if (!filef.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    filef.close();
    int lineCountf = 0;
    std::string linef;
    filef.open("10kk.txt");
    while (getline(filef, linef)) {
        lineCountf++;
    }
    filef.close();

    std::ifstream Ff("10kk.txt");
    std::string zodziaif;
    int pvf=0;

auto nusf = std::chrono::high_resolution_clock::now();
    while( zodziaif != "Egz."){
        Ff>>zodziaif;
        pvf++;
    }

    pvf=pvf-3;
double suumf=0;
    for(int l=0; l<lineCountf-1; l++){
        double sumaf=0.0;
        C.paz.clear();
        Ff>>C.pav>>C.var;

        for(int i=0; i<pvf; i++){
            Ff>>zf;
            C.paz.push_back(zf);
            sumaf=sumaf+z;
        }

        sort(C.paz.begin(), C.paz.end());

        C.vid=sumaf/pvf;

        Ff>>C.egz;

        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
        C.med=mediana(pvf,C);
auto praf = std::chrono::high_resolution_clock::now();
        if(C.galutinis>=5){
            P.push_back(C);
        }
        else {Z.push_back(C);}

auto pabf = std::chrono::high_resolution_clock::now();

    float trukmef = std::chrono::duration_cast<std::chrono::seconds>(pabf - praf).count();
suumf=suumf+trukmef;
    }
std::cout << "Rusiavimo trukme: " << suumf << " sekundes." << std::endl;
    Ff.close();
auto nuskf = std::chrono::high_resolution_clock::now();

    auto laikasf = std::chrono::duration_cast<std::chrono::seconds>(nuskf - nusf).count();


    std::cout << "Nuskaitymo trukme: " << laikasf << " sekundes." << std::endl;
int xyzv;
cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 1: "<<endl;
                cout<<"Jeigu norite rusiuoti pagal mediana spauskite 2: "<<endl;
                while (!(cin >> xyzv)) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(xyzv==1){
                    sort(P.begin(), P.end(), [](const Pazymiai &av, const Pazymiai &bv) {
                        return av.galutinis < bv.galutinis;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aav, const Pazymiai &bbv) {
                        return aav.galutinis < bbv.galutinis;
                    });

                }
                if(xyzv==2){
                    sort(P.begin(), P.end(), [](const Pazymiai &av, const Pazymiai &bv) {
                        return av.med < bv.med;
                    });
                    sort(Z.begin(), Z.end(), [](const Pazymiai &aav, const Pazymiai &bbv) {
                        return aav.med < bbv.med;
                    });
                }
//isvestis
auto pe = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, "lopukai5.txt");
    rezultataifailas(P,"saunuoliukai5.txt");
auto be = std::chrono::high_resolution_clock::now();

    auto isvestise = std::chrono::duration_cast<std::chrono::seconds>(be - pe).count();


    std::cout << "Isvedimo trukme: " << isvestise << " sekundes." << std::endl;



                vector<double> laikai;
                auto endk = chrono::steady_clock::now();
                double laikasr=chrono::duration <double> (endk - viskas).count();
                laikai.push_back(laikasr);
                cout<<"Trukme: "<< laikasr << " s"<<endl;
                break;
            }
            case 6:{
                cout<<"Programa baigta."<<endl;
                return 0;
                break;
            }
        }
    }
    return 0;
}
