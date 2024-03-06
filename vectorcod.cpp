#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <stdexcept>
using namespace std;

int pasirinkimas;
int c;
int x;
int s;
int i=0;

double laiku_suma = 0.0;

struct Pazymiai{
    string var;
    string pav;
    double vid=0.0;
    int egz;
    vector<int> paz;
    double galutinis;
    double med;
    };
vector<Pazymiai> P, Z;


double mediana(int u, Pazymiai h){

    int vidurys = u / 2;
    if (u%2==0){
       h.med =double( (h.paz[vidurys-1] + h.paz[vidurys])/2.0);
    }
    else{
        h.med = double(h.paz[vidurys]);
    }
    return h.med;
}

void rezultatai(const auto hh){

        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        for(const auto &studentas : hh){
            cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                << setprecision(2) << studentas.med << endl;
        }
    }

void rezultataifailas(const auto hh, string failiukas){
        ofstream R(failiukas);

        R << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"<< " / " << setw(17) << "Galutinis (Med.)" << endl;
        R << "--------------------------------------------------------" << endl;

        for (const auto &studentas : hh) {
            R << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
            << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
            << setprecision(2) << studentas.med << endl;

        }
        R.close();
    }


void generuojam(int bivi, std::string zhiazhi){
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ofstream V(zhiazhi);
    V <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kiki;
    kiki = (rand() % 15) + 5;
    for(int i=0; i<kiki; i++){
    V<< "ND"<<i+1<<" ";
    }
    V<< "Egz."<<std::endl;

    for(int i=0; i<bivi; i++){

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


    std::cout << "Generavimo trukme: " << duration << " milisekundes." << std::endl;

}

void failuskaick(string wp, Pazymiai hi){

    int z;
    ifstream file(wp);

    if (!file.is_open()) {
        cout << "Failas  neegzistuoja!" << endl;
    }
    file.close();
    int lineCount = 0;
    string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    ifstream F(wp);
    string zodziai;
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
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);
auto pra = std::chrono::high_resolution_clock::now();
        if(hi.galutinis>=5){
            P.push_back(hi);
        }
        else {Z.push_back(hi);}

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
                    cout << "Klaida. Iveskite skaiciu nuo 1 arba 2: " ;
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


}

void spausdintuvas(std::string zekai, std::string malaciai ){
auto p = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, zekai);
    rezultataifailas(P, malaciai);
auto b = std::chrono::high_resolution_clock::now();

    auto isvestis = std::chrono::duration_cast<std::chrono::milliseconds>(b - p).count();


    std::cout << "Isvedimo trukme: " << isvestis << " milisekundes." << std::endl;

}

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

                        while (cin.fail() || x < 1 || x > 10 ) {

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
                        cout << "Iveskite egzamino rezultata: ";

                        while (!(cin >> C.egz) || (C.egz < 1 || C.egz > 10)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
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
                //double laiku_suma=0.0;

                cout<<"Pasirinkite is kurio failo norite nuskaityti: "<<endl;
                cout<<"1. studentai10000 "<<"2. studentai100000 "<<"3. studentai1000000 "<<"4. kursiokai5 "<<endl;

                while (!(cin >> numeris) || numeris < 1 || numeris > 5) {
                    cout << "Klaida. Iveskite skaiciu nuo 1 iki 4." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                switch (numeris) {
        case 1:
            wp = "1k.txt";
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
        case 5:
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
                cout<<"1k :"<<endl;
                generuojam(1000, "1k.txt");
                cout<<"10k :"<<endl;
                generuojam(10000, "10k.txt");
                cout<<"100k :"<<endl;
                generuojam(100000, "100k.txt");
                cout<<"1mln :"<<endl;
                generuojam(1000000, "1kk.txt");
                cout<<"10mln :"<<endl;
                generuojam(10000000, "10kk.txt");
                cout<<"Failai sugeneruoti! "<<endl;
                cout<<endl;
                cout<<"1k :"<<endl;
                failuskaick("1k.txt", C);
                spausdintuvas("lopukai1.txt", "saunuoliukai1.txt");
                cout<<"10k :"<<endl;
                failuskaick("10k.txt", C);
                spausdintuvas("lopukai2.txt", "saunuoliukai2.txt");
                cout<<"100k :"<<endl;
                failuskaick("100k.txt", C);
                spausdintuvas("lopukai3.txt", "saunuoliukai3.txt");
                cout<<"1mln :"<<endl;
                failuskaick("1kk.txt", C);
                spausdintuvas("lopukai4.txt", "saunuoliukai4.txt");
                cout<<"10mln :"<<endl;
                failuskaick("10kk.txt", C);
                spausdintuvas("lopukai5.txt", "saunuoliukai5.txt");

                vector<double> laikai;
                auto end = chrono::steady_clock::now();
                double laikas=chrono::duration <double> (end - viskas).count();
                laikai.push_back(laikas);
                cout<<"Trukme: "<< laikas << " s"<<endl;
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
