#include "pagalbines.h"

void rezultatai(std::vector<Pazymiai> hh){
    std::cout << std::left << std::setw(15) << "Pavarde " << std::setw(15) << "Vardas" << std::setw(17) << "Galutinis (Vid.)"
              << " / " << std::setw(17) << "Galutinis (Med.)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for(const auto &studentas : hh){
        std::cout << std::left << std::setw(15) << studentas.pav << std::setw(15) << studentas.var << std::setw(17)
                  << std::fixed << std::setprecision(2) << studentas.galutinis << std::setw(17) << std::fixed
                  << std::setprecision(2) << studentas.med << std::endl;
    }
}

void rezultataifailas(std::vector<Pazymiai> hh, std::string failiukas){
    std::ofstream R(failiukas);

    R << std::left << std::setw(15) << "Pavarde " << std::setw(15) << "Vardas" << std::setw(17) << "Galutinis (Vid.)"
      << " / " << std::setw(17) << "Galutinis (Med.)" << std::endl;
    R << "--------------------------------------------------------" << std::endl;

    for (const auto &studentas : hh) {
        R << std::left << std::setw(15) << studentas.pav << std::setw(15) << studentas.var << std::setw(17)
          << std::fixed << std::setprecision(2) << studentas.galutinis << std::setw(17) << std::fixed
          << std::setprecision(2) << studentas.med << std::endl;
    }
    R.close();
}

double mediana(int u, Pazymiai h){
    int vidurys = u / 2;

    if (u % 2 == 0){
        h.med = double((h.paz[vidurys - 1] + h.paz[vidurys]) / 2.0);
    }
    else{
        h.med = double(h.paz[vidurys]);
    }

    return h.med;
}

void generuojam(int bivi, std::string zhiazhi){
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ofstream V(zhiazhi);
    V <<"Pavarde "<<" "<< "Vardas "<<" ";
    int kiki;
    kiki = (rand() % 15) + 5;
    for(int i=0; i<kiki; i++){
    V<< "ND"<<i+1<<" ";
    }
    V<< "Egz."<<std::endl;

    for(int i=0; i<bivi; i++){

        V<<"Pavarde"<<i+1<<" "<<"Vardas"<<i+1<<" ";
        for(int j=0; j<kiki+1; j++){
            int nd=(rand() % 10) + 1;
            V<<nd<<" ";
        }
        V<<std::endl;
    }
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();


    std::cout << "Programos veikimo laikas: " << duration << " sekundes." << std::endl;

}

void failuskaick(std::string wp, Pazymiai hi, std::vector<Pazymiai> hh, std::vector<Pazymiai> hj){

    int z;
    std::ifstream file(wp);

    if (!file.is_open()) {
        std::cout << "Failas  neegzistuoja!" << std::endl;
    }
    file.close();
    int lineCount = 0;
    std::string line;
    file.open(wp);
    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    std::ifstream F(wp);
    std::string zodziai;
    int pv=0;
    while( zodziai != "Egz."){
        F>>zodziai;
        pv++;
    }

    pv=pv-3;

    for(int l=0; l<lineCount-1; l++){
        double suma=0.0;
        hi.paz.clear();
        F>>hi.pav>>hi.var;

        for(int i=0; i<pv; i++){
            F>>z;
            hi.paz.push_back(z);
            suma=suma+z;
        }

        sort(hi.paz.begin(), hi.paz.end());

        hi.vid=suma/pv;

        F>>hi.egz;

        hi.galutinis=(hi.vid*0.4)+(0.6*hi.egz);
        hi.med=mediana(pv,hi);
        if(hi.galutinis>=5){
            hh.push_back(hi);
        }
        else {hj.push_back(hi);}
//perziuret



    }
    F.close();

}

void spausdintuvas(std::string zekai, std::string malaciai, const auto z, const auto f ){
    rezultataifailas(z, zekai);
    rezultataifailas(f, malaciai);

}
