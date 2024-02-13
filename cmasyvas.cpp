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
    int paz[20];
    double galutinis;
    double med;
    };
int main ()
{
    int pasirinkimas;
    int c;
    int x;
    int i=0;
Pazymiai C[7];
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
        case 1:{

        do{
        double suma=0.0;

        cout<<"Iveskite "<<i+1<<" pavarde (noretume baigti spauskite 4):   "<<endl;
        cin>>C[i].pav;
        if(C[i].pav=="4" || C[i].var=="4"){
            break;
        }
        cout<<"Iveskite "<<i+1<<" varda (noretume baigti spauskite 4):   "<<endl;
        cin>>C[i].var;
        if(C[i].pav=="4" || C[i].var=="4"){
            break;
        }

        int j=0;

            do{
            cout<<"Iveskite "<<j+1<<" pazymi (noredami baigti spauskite 11):  "<<endl;
            cin>>C[i].paz[j];
            if(C[i].paz[j]==11){
                break;
            }
            while (C[i].paz[j] < 1 || C[i].paz[j] > 10) {
                cout << "Iveskite "<<j+1<<" pazymi nuo 1 iki 10: ";
                cin >> C[i].paz[j];
            }
            suma=suma+C[i].paz[j];
        j++;
        }
        while(C[i].paz[j]!=11);

        C[i].vid=suma/j;

        cout <<"Iveskite egzamino rezultata: "<<endl;
        cin>>C[i].egz;
        while (C[i].egz < 1 || C[i].egz > 10) {
            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
            cin >> C[i].egz;
        }
        C[i].galutinis=(C[i].vid*0.4)+(0.6*C[i].egz);

        for(int k=0; k<j-1; k++)
        {
            for(int l=k+1; l<j; l++)
            {
            if(C[i].paz[k] > C[i].paz[l]) {
                c = C[i].paz[k];
                C[i].paz[k] = C[i].paz[l];
                C[i].paz[l] = c;
                }
            }
        }
        if (j%2==0)
        {
        int pirmas=j/2-1;
        int antras=j/2;
        C[i].med = (C[i].paz[pirmas] + C[i].paz[antras])/2.0;
        }
        else{
            int vidurys = j / 2;
            C[i].med = C[i].paz[vidurys];
            }
            i++;
        }
        while(C[i].pav!="4" || C[i].var!="4");

        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int z=0; z<i; z++)
    {
        cout<<left<<setw(15)<<C[z].pav<<setw(15)<<C[z].var<<setw(17)<<fixed<<setprecision(2)<<C[z].galutinis<<setw(17)<<fixed<<setprecision(2)<<C[z].med<<endl;

    }
        break;
        }

        case 2:{
           do {

        double suma=0.0;

        cout<<"Iveskite "<<i+1<<" pavarde (noredami sustoti iveskite 4):   "<<endl;
        cin>>C[i].pav;
        if(C[i].pav=="4" || C[i].var=="4"){
            break;
        }
        cout<<"Iveskite "<<i+1<<" varda (noredami sustoti iveskite 4):   "<<endl;
        cin>>C[i].var;
        if(C[i].pav=="4" || C[i].var=="4"){
            break;
        }
        cout<<"Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 "<<endl<<"Jeigu norite generuoti pasirinkta skaiciu spauskite 2 "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>x;
        if(x==1){
                string y;
                int h=0;
            while(y!="Ne"){

                C[i].paz[h]=(rand()%10)+1;
                cout<<"Pazymis "<<h+1<<" : "<<C[i].paz[h]<<endl;
                cout<<"Ar norite testi generavima? Taip arba Ne: ";
                cin>>y; cout<<endl;
                suma=suma+C[i].paz[h];
                h++;
                }
               C[i].vid=suma/h;

                sort(C[i].paz+0, C[i].paz+h);

                if (h%2==0)
        {
        int pirmas=h/2-1;
        int antras=h/2;
        C[i].med = (C[i].paz[pirmas] + C[i].paz[antras])/2.0;
        }
        else{
            int vidurys = h / 2;
            C[i].med = C[i].paz[vidurys];
            }

            }

            if (x==2){
                    int k;
                cout<<"Iveskite pazymiu kieki: "; cin>>k;
            for(int l=0; l<k; l++){
                C[i].paz[l]=(rand()%10)+1;
                cout<<"Pazymis "<<l+1<<" : "<<C[i].paz[l]<<endl;
                suma=suma+C[i].paz[l];
            }
            C[i].vid=suma/k;

            sort(C[i].paz+0, C[i].paz+k);

            if (k%2==0)
        {
        int pirmas=k/2-1;
        int antras=k/2;
        C[i].med = (C[i].paz[pirmas] + C[i].paz[antras])/2.0;
        }
        else{
            int vidurys = k / 2;
            C[i].med = C[i].paz[vidurys];
            }
            }
        int w;
        cout<<"Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: "<<endl;
        cout<<"Jeigu norite ivesti egzamino rezultata spauskite 2: "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>w;
        if(w==1){
            C[i].egz=(rand()%10)+1;
            cout<<"Egzamino rezultatas: "<<C[i].egz<<endl;
        }
        if(w==2){
            cout<<"Iveskite egzamino rezultata: ";
            cin>>C[i].egz;
            cout<<endl;
        }

        C[i].galutinis=(C[i].vid*0.4)+(0.6*C[i].egz);
        i++;
        }
        while(C[i].pav!="4" || C[i].var!="4");

 cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int q=0; q<i; q++)
    {
        cout<<left<<setw(15)<<C[q].pav<<setw(15)<<C[q].var<<setw(17)<<fixed<<setprecision(2)<<C[q].galutinis<<setw(17)<<fixed<<setprecision(2)<<C[q].med<<endl;

    }
        break;
        }
        case 3:{
            int qq=0;
        string vardai[] = {"Paulina","Adriana","Gitanas","Donald", "Ugne", "Kamile", "Rugile", "Roberta","Valdemaras","Jurgis"};
        string  pavardes[] = { "Podgaiska","Obama","Trump","Nauseda","Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte","Jankauskas"};
        while(qq!=1){

            C[i].pav=pavardes[rand()%10];
            C[i].var=vardai[rand()%10];
            cout<<"Pavarde ir vardas: "<<C[i].pav<<" "<<C[i].var<<endl;
        cout<<"Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 "<<endl<<"Jeigu norite generuoti pasirinkta skaiciu spauskite 2 "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>x;
        if(x==1){
                string y;
                int h=0;
                double suma=0.0;
            while(y!="Ne"){

                C[i].paz[h]=(rand()%10)+1;
                cout<<"Pazymis "<<h+1<<" : "<<C[i].paz[h]<<endl;
                cout<<"Ar norite testi generavima? Taip arba Ne: ";
                cin>>y; cout<<endl;
                suma=suma+C[i].paz[h];
                h++;
                }
               C[i].vid=suma/h;

                sort(C[i].paz+0, C[i].paz+h);

                if (h%2==0)
        {
        int pirmas=h/2-1;
        int antras=h/2;
        C[i].med = (C[i].paz[pirmas] + C[i].paz[antras])/2.0;
        }
        else{
            int vidurys = h / 2;
            C[i].med = C[i].paz[vidurys];
            }
            }
            if (x==2){
                    double suma=0.0;
                    int k;
                cout<<"Iveskite pazymiu kieki: "; cin>>k;
            for(int l=0; l<k; l++){
                C[i].paz[l]=(rand()%10)+1;
                cout<<"Pazymis "<<l+1<<" : "<<C[i].paz[l]<<endl;
                suma=suma+C[i].paz[l];
            }
            C[i].vid=suma/k;

            sort(C[i].paz+0, C[i].paz+k);

            if (k%2==0)
        {
        int pirmas=k/2-1;
        int antras=k/2;
        C[i].med = (C[i].paz[pirmas] + C[i].paz[antras])/2.0;
        }
        else{
            int vidurys = k / 2;
            C[i].med = C[i].paz[vidurys];
            }
            }
        int w;
        cout<<"Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: "<<endl;
        cout<<"Jeigu norite ivesti egzamino rezultata spauskite 2: "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>w;
        if(w==1){
            C[i].egz=(rand()%10)+1;
            cout<<"Egzamino rezultatas: "<<C[i].egz<<endl;
        }
        if(w==2){
            cout<<"Iveskite egzamino rezultata: ";
            cin>>C[i].egz;
            cout<<endl;
        }

        C[i].galutinis=(C[i].vid*0.4)+(0.6*C[i].egz);

        cout<<"Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>qq;
        i++;
        }
        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        for(int q=0; q<i; q++)
        {
            cout<<left<<setw(15)<<C[q].pav<<setw(15)<<C[q].var<<setw(17)<<fixed<<setprecision(2)<<C[q].galutinis<<setw(17)<<fixed<<setprecision(2)<<C[q].med<<endl;

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
