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
    int s;
    int n; //namu darbai
    int m; //studentai
    int kiek;
    int i=0;
Pazymiai P[25];
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, pavardes ir pazymius" << endl;
        cout << "4. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
        case 1:{

        while(P[i].pav!="-1" || P[i].var!="-1")
        {

        double suma=0.0;

        cout<<"Iveskite "<<i+1<<" pavarde:   "<<endl;
        cin>>P[i].pav;

        cout<<"Iveskite "<<i+1<<" varda:   "<<endl;
        cin>>P[i].var;


        int j=0;
       while(P[i].paz[j]!=-1){


            cout<<"Iveskite "<<j+1<<" pazymi:  "<<endl;
            cin>>P[i].paz[j];
            while (P[i].paz[j] < 1 || P[i].paz[j] > 10) {
                cout << "Iveskite "<<j+1<<" pazymi nuo 1 iki 10: ";
                cin >> P[i].paz[j];
            }
            suma=suma+P[i].paz[j];
        j++;
       }

        P[i].vid=suma/kiek;

        cout <<"Iveskite egzamino rezultata: "<<endl;
        cin>>P[i].egz;
        while (P[i].egz < 1 || P[i].egz > 10) {
            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
            cin >> P[i].egz;
        }


        P[i].galutinis=(P[i].vid*0.4)+(0.6*P[i].egz);

        for(int k=0; k<kiek-1; k++)
        {
            for(int l=k+1; l<kiek; l++)
            {
            if(P[i].paz[k] > P[i].paz[l]) {
                c = P[i].paz[k];
                P[i].paz[k] = P[i].paz[l];
                P[i].paz[l] = c;
                }
            }
        }
        if (kiek%2==0)
        {
        int pirmas=kiek/2-1;
        int antras=kiek/2;
        P[i].med = (P[i].paz[pirmas] + P[i].paz[antras])/2.0;
        }
        else{
            int vidurys = kiek / 2;
            P[i].med = P[i].paz[vidurys];
            }
            i++;
        }

        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int z=0; z<i; z++)
    {
        cout<<left<<setw(15)<<P[i].pav<<setw(15)<<P[i].var<<setw(17)<<fixed<<setprecision(2)<<P[i].galutinis<<setw(17)<<fixed<<setprecision(2)<<P[i].med<<endl;

    }

        break;
        }

        case 2:{
           do {

        double suma=0.0;

        cout<<"Iveskite "<<i+1<<" pavarde (noredami sustoti iveskite 4):   "<<endl;
        cin>>P[i].pav;
        if(P[i].pav=="4" || P[i].var=="4"){
            break;
        }
        cout<<"Iveskite "<<i+1<<" varda (noredami sustoti iveskite 4):   "<<endl;
        cin>>P[i].var;
        if(P[i].pav=="4" || P[i].var=="4"){
            break;
        }
        cout<<"Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 "<<endl<<"Jeigu norite generuoti pasirinkta skaiciu spauskite 2 "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>x;
        if(x==1){
                string y;
                int h=0;
            while(y!="Ne"){

                P[i].paz[h]=(rand()%10)+1;
                cout<<"Pazymis "<<h+1<<" : "<<P[i].paz[h]<<endl;
                cout<<"Ar norite testi generavima? Taip arba Ne: ";
                cin>>y; cout<<endl;
                suma=suma+P[i].paz[h];
                h++;
                }
               P[i].vid=suma/h;

                sort(P[i].paz+0, P[i].paz+h);

                if (h%2==0)
        {
        int pirmas=h/2-1;
        int antras=h/2;
        P[i].med = (P[i].paz[pirmas] + P[i].paz[antras])/2.0;
        }
        else{
            int vidurys = h / 2;
            P[i].med = P[i].paz[vidurys];
            }

            }

            if (x==2){
                    int k;
                cout<<"Iveskite pazymiu kieki: "; cin>>k;
            for(int l=0; l<k; l++){
                P[i].paz[l]=(rand()%10)+1;
                cout<<"Pazymis "<<l+1<<" : "<<P[i].paz[l]<<endl;
                suma=suma+P[i].paz[l];
            }
            P[i].vid=suma/k;

            sort(P[i].paz+0, P[i].paz+k);

            if (k%2==0)
        {
        int pirmas=k/2-1;
        int antras=k/2;
        P[i].med = (P[i].paz[pirmas] + P[i].paz[antras])/2.0;
        }
        else{
            int vidurys = k / 2;
            P[i].med = P[i].paz[vidurys];
            }


            }


        int w;
        cout<<"Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: "<<endl;
        cout<<"Jeigu norite ivesti egzamino rezultata spauskite 2: "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>w;
        if(w==1){
            P[i].egz=(rand()%10)+1;
            cout<<"Egzamino rezultatas: "<<P[i].egz<<endl;
        }
        if(w==2){
            cout<<"Iveskite egzamino rezultata: ";
            cin>>P[i].egz;
            cout<<endl;
        }

        P[i].galutinis=(P[i].vid*0.4)+(0.6*P[i].egz);



        i++;
        }
        while(P[i].pav!="4" || P[i].var!="4");

 cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int q=0; q<i; q++)
    {
        cout<<left<<setw(15)<<P[q].pav<<setw(15)<<P[q].var<<setw(17)<<fixed<<setprecision(2)<<P[q].galutinis<<setw(17)<<fixed<<setprecision(2)<<P[q].med<<endl;

    }
        break;
        }
        case 3:{
            int qq=0;
        string vardai[] = {"Paulina","Adriana","Gitanas","Donald", "Ugne", "Kamile", "Rugile", "Roberta","Valdemaras","Jurgis"};
        string  pavardes[] = { "Podgaiska","Obama","Trump","Nauseda","Sirokyte", "Mockute", "Zobelaite", "Macaite", "Jurpalyte","Jankauskas"};
        while(qq!=1){

            P[i].pav=pavardes[rand()%10];
            P[i].var=vardai[rand()%10];
            cout<<"Pavarde ir vardas: "<<P[i].pav<<" "<<P[i].var<<endl;





        cout<<"Jeigu norite generuoti po viena atsitiktini skaiciu spauskite 1 "<<endl<<"Jeigu norite generuoti pasirinkta skaiciu spauskite 2 "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>x;
        if(x==1){
                string y;
                int h=0;
                double suma=0.0;
            while(y!="Ne"){

                P[i].paz[h]=(rand()%10)+1;
                cout<<"Pazymis "<<h+1<<" : "<<P[i].paz[h]<<endl;
                cout<<"Ar norite testi generavima? Taip arba Ne: ";
                cin>>y; cout<<endl;
                suma=suma+P[i].paz[h];
                h++;
                }
               P[i].vid=suma/h;

                sort(P[i].paz+0, P[i].paz+h);

                if (h%2==0)
        {
        int pirmas=h/2-1;
        int antras=h/2;
        P[i].med = (P[i].paz[pirmas] + P[i].paz[antras])/2.0;
        }
        else{
            int vidurys = h / 2;
            P[i].med = P[i].paz[vidurys];
            }


            }


            if (x==2){
                    double suma=0.0;
                    int k;
                cout<<"Iveskite pazymiu kieki: "; cin>>k;
            for(int l=0; l<k; l++){
                P[i].paz[l]=(rand()%10)+1;
                cout<<"Pazymis "<<l+1<<" : "<<P[i].paz[l]<<endl;
                suma=suma+P[i].paz[l];
            }
            P[i].vid=suma/k;

            sort(P[i].paz+0, P[i].paz+k);

            if (k%2==0)
        {
        int pirmas=k/2-1;
        int antras=k/2;
        P[i].med = (P[i].paz[pirmas] + P[i].paz[antras])/2.0;
        }
        else{
            int vidurys = k / 2;
            P[i].med = P[i].paz[vidurys];
            }


            }


        int w;
        cout<<"Jeigu norite atsitiktinai sugeneruoti egzamino rezultata spauskite 1: "<<endl;
        cout<<"Jeigu norite ivesti egzamino rezultata spauskite 2: "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>w;
        if(w==1){
            P[i].egz=(rand()%10)+1;
            cout<<"Egzamino rezultatas: "<<P[i].egz<<endl;
        }
        if(w==2){
            cout<<"Iveskite egzamino rezultata: ";
            cin>>P[i].egz;
            cout<<endl;
        }

        P[i].galutinis=(P[i].vid*0.4)+(0.6*P[i].egz);

        cout<<"Noredami baigti studentu generavima spauskite 1, noredami testi spauskite 2 "<<endl;
        cout<<"Jusu pasirinkimas: "; cin>>qq;
        i++;
        }
        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        for(int q=0; q<i; q++)
        {
            cout<<left<<setw(15)<<P[i].pav<<setw(15)<<P[i].var<<setw(17)<<fixed<<setprecision(2)<<P[i].galutinis<<setw(17)<<fixed<<setprecision(2)<<P[i].med<<endl;

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








    /*for(int i=0; i<s; i++)
    {
        double suma=0.0;
        cout<<"Iveskite "<<i+1<<" pavarde:   "<<endl;
        cin>>P[i].pav;

        cout<<"Iveskite "<<i+1<<" varda:   "<<endl;
        cin>>P[i].var;

        cout<<"Kiek yra tarpiniu pazymiu?   "<<endl;
        cin>>kiek;

        while (kiek < 1 || kiek > 10) {
            cout << "Kiek yra tarpiniu pazymiu?  "<<endl;
            cin >> kiek;
        }

        for(int j=0; j<kiek; j++)
        {
            cout<<"Iveskite "<<j+1<<" pazymi:  "<<endl;
            cin>>P[i].paz[j];
            while (P[i].paz[j] < 1 || P[i].paz[j] > 10) {
                cout << "Iveskite "<<j+1<<" pazymi nuo 1 iki 10: ";
                cin >> P[i].paz[j];
            }
            suma=suma+P[i].paz[j];
        }



        P[i].vid=suma/kiek;

        cout <<"Iveskite egzamino rezultata: "<<endl;
        cin>>P[i].egz;
        while (P[i].egz < 1 || P[i].egz > 10) {
            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
            cin >> P[i].egz;
        }


        P[i].galutinis=(P[i].vid*0.4)+(0.6*P[i].egz);

        for(int k=0; k<kiek-1; k++)
        {
            for(int l=k+1; l<kiek; l++)
            {
            if(P[i].paz[k] > P[i].paz[l]) {
                c = P[i].paz[k];
                P[i].paz[k] = P[i].paz[l];
                P[i].paz[l] = c;
                }
            }
        }
        if (kiek%2==0)
        {
        int pirmas=kiek/2-1;
        int antras=kiek/2;
        P[i].med = (P[i].paz[pirmas] + P[i].paz[antras])/2.0;
        }
        else{
            int vidurys = kiek / 2;
            P[i].med = P[i].paz[vidurys];
            }
    }
    cout<<endl;

    cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i=0; i<s; i++)
    {
        cout<<left<<setw(15)<<P[i].pav<<setw(15)<<P[i].var<<setw(17)<<fixed<<setprecision(2)<<P[i].galutinis<<setw(17)<<fixed<<setprecision(2)<<P[i].med<<endl;

    }
*/
    return 0;
}
