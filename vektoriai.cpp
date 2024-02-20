#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <fstream>
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
        cout << "4. Nuskaityti is failo" << endl;
        cout << "5. Baigti programa" << endl;
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

                    while (cin.fail() || x < 1 || x > 10) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Iveskite " << j + 1 << " pazymi nuo 1 iki 10: ";
                        cin >> x;
                    }

                    C.paz.push_back(x);
                    suma = suma + x;
        j++;
        }
        while(x!=11);

        C.vid=suma/j;

        cout <<"Iveskite egzamino rezultata: "<<endl;
        cin>>C.egz;

        while (cin.fail() || C.egz < 1 || C.egz > 10) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

        while (!(cin >> x) || (x != 1 && x != 2)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Iveskite skaiciu 1 arba 2: ";
    }

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

            while (!(cin >> C.egz) || (C.egz <1 || C.egz >10)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
    }
            cout << endl;
        }

        C.galutinis = (C.vid * 0.4) + (0.6 * C.egz);
        P.push_back(C);
        i++;
    }
    while (C.pav != "4" || C.var != "4");

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

        Pazymiai C;


        int z;
        int o;
        int stud;
        string hoe;
        int xyz;
        int pv=0;

        cout<<"Kiek nuskaityti studentu? "<<endl;
        cin>>stud;

        ifstream F("kursiokai.txt");

        while( hoe != "Egz."){
    F>>hoe;
    //cout<<hoe;
    pv++;
    //cout<<pv;
    }

        pv=pv-3;


        for(int l=0; l<stud; l++){
        double suma=0.0;

        F>>C.pav>>C.var;

        for(int i=0; i<pv; i++){
            F>>z;
            C.paz.push_back(z);
            cout<<z<<endl;

            suma=suma+z;
        }
        sort(C.paz.begin(), C.paz.end());
cout<<endl;
        C.vid=suma/pv;
        //cout<<C.vid<<endl;
        cout<<endl;
        F>>C.egz;
        //cout<<C.egz<<endl;
        cout<<endl;
        C.galutinis=(C.vid*0.4)+(0.6*C.egz);
//cout<<C.galutinis<<endl;
cout<<endl;


        if (pv%2==0)
        {
        int pirmas=pv/2-1;
        int antras=pv/2;
        C.med = (C.paz[pirmas] + C.paz[antras])/2.0;
        }
        else{
            int vidurys = pv / 2;
            C.med = C.paz[vidurys];
            }

cout<<C.med<<endl;
cout<<endl;
         P.push_back(C);

        }

            F.close();
            cout<<"Jeigu norite rusiuoti pagal pavarde spauskite 1: "<<endl;
            cout<<"Jeigu norite rusiuoti pagal varda spauskite 2: "<<endl;
            cout<<"Jeigu norite rusiuoti pagal galutini pazymi spauskite 3: "<<endl;
            cout<<"Jeigu norite rusiuoti pagal mediana spauskite 4: "<<endl;
            cin>>xyz;

            if(xyz==1){
                sort(C.pav.begin(),C.pav.end());
            }
            if(xyz==2){
                sort(C.var.begin(),C.var.end());
            }
            if(xyz==3){

                /*for(int m=0; m<sk-1; m++)
                {
                for(int n=m+1; n<sk; n++)
                    {
                        if(C.galutinis[m]>C.galutinis[n])
                        {
                            t=C.galutinis;
                            C.galutinis[m]=C.galutinis[n];
                            C.galutinis[n]=t;
                        }
                    }
                }
                */

            }
            if(xyz==4){

            }

            cout<<"Jeigu norite isvesti i ekrana- spauskite 1: "<<endl;
            cout<<"Jeigu norite isvesti i faila- spauskite 2: "<<endl;
            cout<<"Jusu pasirinkimas: ";
            cin>>o;
            if(o==1){

               cout << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"<< " / " << setw(17) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------" << endl;

            for (const auto &studentas : P) {
                cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                    << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                    << setprecision(2) << studentas.med << endl;
    }
            }
            if(o==2){

            ofstream R("isvestis.txt");

            R << left << setw(15) << "Pavarde " << setw(15) << "Vardas" << setw(17) << "Galutinis (Vid.)"
         << " / " << setw(17) << "Galutinis (Med.)" << endl;
    R << "--------------------------------------------------------" << endl;

    for (const auto &studentas : P) {
        R << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
             << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
             << setprecision(2) << studentas.med << endl;
             R.close();
        }
        }

        break;
        }
        case 5:{
        cout<<"Programa baigta."<<endl;
        return 0;
        break;
        }
        }
        }


    return 0;
}
