#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

struct Pazymiai{
    string var;
    string pav;
    double vid=0.0;
    int egz;
    vector<int> paz;
    double galutinis;
    double med;
    };
int main ()
{
    int pasirinkimas;
    int c;
    int x;
    int s;
    int i=0;
    vector<Pazymiai> P;

    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Baigti programa" << endl;
        cin >> pasirinkimas;

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
            cout<<"Iveskite "<<j+1<<" pazymi (noredami baigti spauskite 11):  "<<endl;
            cin>>x;
            if(x==11){
                break;
            }
            while (x < 1 || x > 10) {
                cout << "Iveskite "<<j+1<<" pazymi nuo 1 iki 10: ";
                cin >> x;
            }
            C.paz.push_back(x);
            suma=suma+x;
        j++;
        }
        while(x!=11);

        C.vid=suma/j;

        cout <<"Iveskite egzamino rezultata: "<<endl;
        cin>>C.egz;
        while (C.egz < 1 || C.egz > 10) {
            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
            cin >> C.egz;
        }
        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
        sort(C.paz.begin(), C.paz.end());

        if (j%2==0)
        {
        int pirmas=j/2-1;
        int antras=j/2;
        C.med = (C.paz[pirmas] + C.paz[antras])/2.0;
        }
        else{
            int vidurys = j / 2;
            C.med = C.paz[vidurys];
            }
            P.push_back(C);
            i++;
        }
        while(C.pav!="4" || C.var!="4");



        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(const auto &studentas : P)
    {
        cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                         << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                         << setprecision(2) << studentas.med << endl;
    }
        break;
        }

        case 2:{
            Pazymiai C;
           do  {double suma = 0.0;


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

        cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl
             << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> x;

        if (x == 1) {
            string y;
            int h = 0;
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

            if (h % 2 == 0) {
                int pirmas = h / 2 - 1;
                int antras = h / 2;
                C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
            } else {
                int vidurys = h / 2;
                C.med = C.paz[vidurys];
            }
        }

        if (x == 2) {
            int k;
            cout << "Iveskite pazymiu kieki: ";
            cin >> k;

            for (int l = 0; l < k; l++) {
                C.paz.push_back((rand() % 10) + 1);
                cout << "Pazymis " << l + 1 << " : " << C.paz[l] << endl;
                suma = suma + C.paz[l];
            }

            C.vid = suma / k;

            sort(C.paz.begin(), C.paz.end());

            if (k % 2 == 0) {
                int pirmas = k / 2 - 1;
                int antras = k / 2;
                C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
            } else {
                int vidurys = k / 2;
                C.med = C.paz[vidurys];
            }
        }

        int w;
        cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
        cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> w;

        if (w == 1) {
            C.egz = (rand() % 10) + 1;
            cout << "Egzamino rezultatas: " << C.egz << endl;
        }

        if (w == 2) {
            cout << "Iveskite egzamino rezultata: ";
            cin >> C.egz;
            cout << endl;
        }

        C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);
        P.push_back(C);
        i++;
    } while (C.pav != "4" || C.var != "4");

    cout << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"
         << " / " << setw(17) << "Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (const auto &studentas : P) {
        cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
             << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
             << setprecision(2) << studentas.med << endl;
    }
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

        cout << "Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 " << endl
             << "Jeigu norite generuoti pasirinkta skaiciu spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> x;

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

            if (h % 2 == 0) {
                int pirmas = h / 2 - 1;
                int antras = h / 2;
                C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
            } else {
                int vidurys = h / 2;
                C.med = C.paz[vidurys];
            }
        }

        if (x == 2) {
            double suma = 0.0;
            int k;
            cout << "Iveskite pazymiu kieki: ";
            cin >> k;

            for (int l = 0; l < k; l++) {
                C.paz.push_back((rand() % 10) + 1);
                cout << "Pazymis " << l + 1 << " : " << C.paz[l] << endl;
                suma = suma + C.paz[l];
            }

            C.vid = suma / k;

            sort(C.paz.begin(), C.paz.end());

            if (k % 2 == 0) {
                int pirmas = k / 2 - 1;
                int antras = k / 2;
                C.med = (C.paz[pirmas] + C.paz[antras]) / 2.0;
            } else {
                int vidurys = k / 2;
                C.med = C.paz[vidurys];
            }
        }

        int w;
        cout << "Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: " << endl;
        cout << "Jeigu norite ivesti egzamino rezultata spauskite 2: " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> w;

        if (w == 1) {
            C.egz = (rand() % 10) + 1;
            cout << "Egzamino rezultatas: " << C.egz << endl;
        }

        if (w == 2) {
            cout << "Iveskite egzamino rezultata: ";
            cin >> C.egz;
            cout << endl;
        }

        C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);

        cout << "Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> qq;

        P.push_back(C);
    }

    cout << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"
         << " / " << setw(17) << "Galutinis (Med.)" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const auto &studentas : P) {
        cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
             << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
             << setprecision(2) << studentas.med << endl;
    }

    break;
        }
        case 4:{
        cout<<"Programa baigta."<<endl;
        return 0;
        break;
        }
        }
        }


    return 0;
}
