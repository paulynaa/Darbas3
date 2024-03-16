#include "pagalbineslist.h"
using namespace std;

double mediana(int u, Pazymiai h){

    int vidurys = u / 2;
    if (u % 2 == 0){
        auto it1 = h.paz.begin();
        auto it2 = h.paz.begin();
        std::advance(it1, vidurys - 1);
        std::advance(it2, vidurys);
        h.med = double((*it1 + *it2) / 2.0);
    }
    else{
        auto it = h.paz.begin();
        std::advance(it, vidurys);
        h.med = double(*it);
    }
    return h.med;
}

void rezultatai(std::list<Pazymiai> hh){

        cout<<left<<setw(15)<<"Pavarde "<<setw(15)<< "Vardas"<<setw(17)<<"Galutinis (Vid.)"<<" / "<<setw(17)<<"Galutinis (Med.)"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        for(const auto &studentas : hh){
            cout << left << setw(15) << studentas.pav << setw(15) << studentas.var << setw(17)
                << fixed << setprecision(2) << studentas.galutinis << setw(17) << fixed
                << setprecision(2) << studentas.med << endl;
        }


    }

void rezultataifailas(std::list<Pazymiai> hh, string failiukas){
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


void generuojam(int studentusk, std::string failopav){
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ofstream V(failopav);
    stringstream laik;
    laik <<"Pavarde "<<" "<< "Vardas "<<" ";
    int pazymiusk;
    pazymiusk = (rand() % 15) + 5;
    for(int i=0; i<pazymiusk; i++){
    laik<< "ND"<<i+1<<" ";
    }
    laik<< "Egz."<<std::endl;

    for(int i=0; i<studentusk; i++){

        laik<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<pazymiusk+1; j++){
            int nd=(rand() % 10) + 1;
            laik<<nd<<" ";
        }
        laik<<std::endl;
    }
    V<<laik.str();
    V.close();
    laik.clear();
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();


    std::cout << "Generavimo trukme: " << duration << " milisekundes." << std::endl;

}

void failuskaick(string wp, Pazymiai hi, list<Pazymiai>& S, list<Pazymiai>& P, list<Pazymiai>& Z){

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

        hi.paz.sort();

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);

        if(hi.galutinis>=5){
            P.push_back(hi);
        }
        else {Z.push_back(hi);}


    }

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

                 auto pra = std::chrono::high_resolution_clock::now();
                if(xyz==1){
                   P.sort([](const Pazymiai &a, const Pazymiai &b) {
                        return a.galutinis < b.galutinis;
                    });

                    Z.sort([](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.galutinis < bb.galutinis;
                    });
                }
                if(xyz==2){
                    P.sort([](const Pazymiai &a, const Pazymiai &b) {
                        return a.med < b.med;
                    });

                    Z.sort([](const Pazymiai &aa, const Pazymiai &bb) {
                        return aa.med < bb.med;
                    });

                }
                auto pab = std::chrono::high_resolution_clock::now();

                float trukme = std::chrono::duration_cast<std::chrono::milliseconds>(pab - pra).count();
                suum=suum+trukme;
                std::cout << "Rusiavimo trukme: " << suum << " milisekundes." << std::endl;


}

void spausdintuvas(std::string zekai, std::string malaciai , list<Pazymiai> P, list<Pazymiai> Z){
    auto p = std::chrono::high_resolution_clock::now();
    rezultataifailas(Z, zekai);
    rezultataifailas(P, malaciai);
    auto b = std::chrono::high_resolution_clock::now();

    auto isvestis = std::chrono::duration_cast<std::chrono::milliseconds>(b - p).count();


    std::cout << "Isvedimo trukme: " << isvestis << " milisekundes." << std::endl;

}



