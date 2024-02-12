#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Pazymiai{
    string var;
    string pav;
    double vid;
    int egz;
    int paz[20];
    double galutinis;
    double med;
    };

int main ()
{
    int c;
    int n;
    int kiek;

    cout<<"Iveskite studentu skaiciu:   "<<endl;
    cin>>n;

    Pazymiai P[n];


    for(int i=0; i<n; i++)
    {
        int suma=0;
        cout<<"Iveskite "<<i+1<<" pavarde:   "<<endl;
        cin>>P[i].pav;

        cout<<"Iveskite "<<i+1<<" varda:   "<<endl;
        cin>>P[i].var;

        cout<<"Kiek yra tarpiniu pazymiu?   "<<endl;
        cin>>kiek;

        if(kiek>0 && kiek<=10){
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
        }
        else {
        cout<<"Kiek yra tarpiniu pazymiu   "<<endl;
        cin>>kiek;
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

    cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(15)<<"Galutinis(Vid)"<<"/"<<setw(15)<<"Mediana(Vid)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<left<<setw(15)<<P[i].pav<<setw(15)<<P[i].var<<setw(15)<<fixed<<setprecision(2)<<P[i].galutinis<<setw(15)<<fixed<<setprecision(2)<<P[i].med<<endl;

    }

    return 0;
}
