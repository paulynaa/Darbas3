#include <iostream>
#include <iomanip>
using namespace std;

struct Pazymiai{
    string var;
    string pav;
    double vid;
    int egz;
    double galutinis;
    double med;
    };


int main ()
{
    int c;
    int n;
    int kiek;
    int paz[20];
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
            cin>>paz[j];
            suma=suma+paz[j];
        }



        P[i].vid=suma/kiek;
        cout <<"Iveskite egzamino rezultata   "<<endl;
        cin>>P[i].egz;
        P[i].galutinis=P[i].vid*0.4+0.6*P[i].egz;


   for(int k=0; k<kiek-1; k++)
    {
        for(int l=k+1; l<kiek; l++)
       {
           if(paz[k]>paz[l])
           {
               c=paz[k];
            paz[k]=paz[l];
            paz[l]=c;
        }
        }
    }

    if (kiek%2==0)
    {
       int pirmas=kiek/2-1;
       int antras=kiek/2;
       P[i].med=(paz[pirmas]+paz[antras])/2.0;
    }
    else{
        int vidurys = kiek / 2;
            P[i].med = paz[vidurys];
    }
    }
    cout<<endl;

    cout<<"Pavarde\t "<< "Vardas\t"<<"Galutinis (Vid) \ Mediana (Vid)"<<endl;
    cout<<"------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<P[i].pav<<"\t"<<P[i].var<<"\t"<<fixed<<setprecision(2)<<P[i].galutinis<<"\t"<<fixed<<setprecision(2)<<P[i].med<<endl;

    }

    return 0;
}
