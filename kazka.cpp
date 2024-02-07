#include <iostream>
#include <iomanip>
using namespace std;

struct vienas{
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
    vienas V[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Iveskite "<<i+1<<" pavarde   "<<endl;
        cin>>V[i].pav;
        cout<<"Iveskite "<<i+1<<" varda   "<<endl;
        cin>>V[i].var;
        cout<<"Kiek yra tarpiniu pazymiu   "<<endl;
        cin>>kiek;
        for(int j=0; j<kiek; j++)
        {
            cout<<"Iveskite "<<j+1<<" pazymi   "<<endl;
            cin>>paz;
            suma=suma+paz;
        }
        V[i].vid=suma/kiek;
        cout <<"Iveskite egzamino rezultata   "<<endl;
        cin>>V[i].egz;
        V[i].galutinis=V[i].vid*0.4+0.6*V[i].egz;
    }

    cout<<endl;

    cout<<"Pavarde\t "<< "Vardas\t"<<"Galutinis\t"<<endl;
    cout<<"------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<V[i].pav<<"\t"<<V[i].var<<"\t"<<setprecision(3)<<V[i].galutinis<<endl;

    }

    return 0;
}
