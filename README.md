std::vector
|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000|0.003 s.|0.001 s.|0.002 s.|
|10 000|0.014 s.|0.001 s.|0.009 s.|
|100 000|0.078 s.|0.008 s.|0.103 s.|
|1 000 000| 8.911 s.| 0.801 s.| 0.950 s.|
|10 000 000| 80.872 s.| 8.186 s.| 13.680 s.|

Vector
|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000|0.015 s.|0.001 s.|0.002 s.|
|10 000|0.015 s.|0.015 s.|0.003 s.|
|100 000|0.135 s.| 0.034 s.|0.085 s.|
|1 000 000|2.358 s.| 0.383 s.|0.928 s.|
|10 000 000|24.349 s.| 3.880 s.| 11.513 s.|


unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
            std::vector<int> v1;
            int std_vector_perskirstymas = 0;
            for (int i = 1; i <= sz; ++i) {
                v1.push_back(i);
                if (v1.capacity() == v1.size()) {
                    ++std_vector_perskirstymas;
                }
            }
            cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

            Vector<int> v2;
            int vector_perskirstymas = 0;
            for (int i = 1; i <= sz; ++i) {
                v2.push_back(i);
                if (v2.capacity() == v2.size()) {
                    ++vector_perskirstymas;
                }
            } 
            cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;


![image](https://github.com/paulynaa/Darbas3/assets/147087833/99dbe095-c580-4bad-8bb2-61a47a026c2e)
