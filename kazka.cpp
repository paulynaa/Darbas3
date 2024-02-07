#include <iostream>
#include <iomanip>
using namespace std;

struct Pazymiai{
    string var;
    string pav;
    double vid;
    int egz;
    double galutinis;
    };


int main ()
{
    int n;
    int kiek;
    int paz;
    int suma=0;
    cout<<"Iveskite studentu skaiciu   "<<endl;
    cin>>n;
    Pazymiai P[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Iveskite "<<i+1<<" pavarde   "<<endl;
        cin>>P[i].pav;
        cout<<"Iveskite "<<i+1<<" varda   "<<endl;
        cin>>P[i].var;
        cout<<"Kiek yra tarpiniu pazymiu   "<<endl;
        cin>>kiek;
        for(int j=0; j<kiek; j++)
        {
            cout<<"Iveskite "<<j+1<<" pazymi   "<<endl;
            cin>>paz;
            suma=suma+paz;
        }
        P[i].vid=suma/kiek;
        cout <<"Iveskite egzamino rezultata   "<<endl;
        cin>>P[i].egz;
        P[i].galutinis=P[i].vid*0.4+0.6*P[i].egz;
    }

    cout<<endl;

    cout<<"Pavarde\t "<< "Vardas\t"<<"Galutinis\t"<<endl;
    cout<<"------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<P[i].pav<<"\t"<<P[i].var<<"\t"<<fixed<<setprecision(2)<<P[i].galutinis<<endl;

    }

    return 0;
}
