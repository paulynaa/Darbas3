#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
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
    int c;
    int n;
    int kiek;

    cout<<"Iveskite studentu skaiciu:   "<<endl;

    while (!(cin >> n) || n < 1 || n >= 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite studentu skaiciu:   " << endl;
    }
    Pazymiai P[n];


    for(int i=0; i<n; i++)
    {
        double suma=0.0;
        cout<<"Iveskite "<<i+1<<" pavarde:   "<<endl;
        cin>>P[i].pav;

        cout<<"Iveskite "<<i+1<<" varda:   "<<endl;
        cin>>P[i].var;

        cout<<"Kiek yra tarpiniu pazymiu?   "<<endl;
        while (!(cin >> kiek) || kiek < 1 || kiek > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Kiek yra tarpiniu pazymiu?  " << endl;
        }

        for(int j=0; j<kiek; j++)
        {
            cout<<"Iveskite "<<j+1<<" pazymi:  "<<endl;
            while (!(cin >> P[i].paz[j]) || P[i].paz[j] < 1 || P[i].paz[j] > 10) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite " << j + 1 << " pazymi nuo 1 iki 10: ";
            }
            suma=suma+P[i].paz[j];
        }



        P[i].vid=suma/kiek;

        cout <<"Iveskite egzamino rezultata: "<<endl;
        while (!(cin >> P[i].egz) || P[i].egz < 1 || P[i].egz > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite egzamino rezultata nuo 1 iki 10: ";
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
    for(int i=0; i<n; i++)
    {
        cout<<left<<setw(15)<<P[i].pav<<setw(15)<<P[i].var<<setw(17)<<fixed<<setprecision(2)<<P[i].galutinis<<setw(17)<<fixed<<setprecision(2)<<P[i].med<<endl;

    }

    return 0;
}
