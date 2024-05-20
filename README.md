# Įsitikinu, kad mano Vector konteineris veikia lygiai taip pat, kaip std::vector. Atkartoju std::vector funkijas ir palyginu rezultatus.

__push_back()__
            
            std::vector<int> myvector;
            int myint;
            std::cout << "Please enter some integers (enter 0 to end):\n";

            do {
                        std::cin >> myint;
                        myvector.push_back(myint);
            } while (myint);

            std::cout << "std::vector stores " << int(myvector.size()) << " numbers.\n";

            Vector<int> myvectorr;
            int myintp;
            std::cout << "Please enter some integers (enter 0 to end):\n";

            do {
                        std::cin >> myintp;
                        myvectorr.push_back(myintp);
            } while (myintp);

            std::cout << "Vector stores " << int(myvectorr.size()) << " numbers.\n";
            
![image](https://github.com/paulynaa/Darbas3/assets/147087833/a001506b-b7c2-4672-a0b9-b0ee9777fb7e)

__clear()__

            std::vector<int> myvector;
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);
            std::cout << "std::vector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                        std::cout << ' ' << myvector[i];
            std::cout << '\n';
            myvector.clear();
            myvector.push_back (1101);
            myvector.push_back (2202);
            std::cout << "std::vector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                        std::cout << ' ' << myvector[i];
            std::cout << '\n';

            Vector<int> myvectorr;
            myvectorr.push_back (100);
            myvectorr.push_back (200);
            myvectorr.push_back (300);
            std::cout << "Vector contains:";
            for (unsigned i=0; i<myvectorr.size(); i++)
                        std::cout << ' ' << myvectorr[i];
            std::cout << '\n';
            myvectorr.clear();
            myvectorr.push_back (1101);
            myvectorr.push_back (2202);
            std::cout << "Vector contains:";
            for (unsigned i=0; i<myvectorr.size(); i++)
                        std::cout << ' ' << myvectorr[i];
            std::cout << '\n';
            
![image](https://github.com/paulynaa/Darbas3/assets/147087833/72921c43-a079-46cf-a7ed-ec8e361ee275)

__Relational operators__

            cout << "std::vector: \n";
            std::vector<int> foo (3,100);   // three ints with a value of 100
            std::vector<int> bar (2,200);   // two ints with a value of 200
            if (foo==bar) std::cout << "foo and bar are equal\n";
            if (foo!=bar) std::cout << "foo and bar are not equal\n";
            if (foo< bar) std::cout << "foo is less than bar\n";
            if (foo> bar) std::cout << "foo is greater than bar\n";
            if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
            if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
            
            cout << "Vector :\n";
            Vector<int> fo (3,100);   // three ints with a value of 100
            Vector<int> ba (2,200);   // two ints with a value of 200
            if (foo==bar) std::cout << "foo and bar are equal\n";
            if (foo!=bar) std::cout << "foo and bar are not equal\n";
            if (foo< bar) std::cout << "foo is less than bar\n";
            if (foo> bar) std::cout << "foo is greater than bar\n";
            if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
            if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
              
![image](https://github.com/paulynaa/Darbas3/assets/147087833/8ff11899-9c49-4dce-b9fc-3215b1781990)


__size()__

            cout << "std::vector \n";
            std::vector<int> myints;
            std::cout << "0. size: " << myints.size() << '\n';
            for (int i=0; i<10; i++) myints.push_back(i);
            std::cout << "1. size: " << myints.size() << '\n';
            myints.insert (myints.end(),10,100);
            std::cout << "2. size: " << myints.size() << '\n';
            myints.pop_back();
            std::cout << "3. size: " << myints.size() << '\n';

            cout << "Vector \n";
            Vector<int> myintss;
            std::cout << "0. size: " << myintss.size() << '\n';
            for (int i=0; i<10; i++) myintss.push_back(i);
            std::cout << "1. size: " << myintss.size() << '\n';
            myintss.insert (myintss.end(),10,100);
            std::cout << "2. size: " << myintss.size() << '\n';
            myintss.pop_back();
            std::cout << "3. size: " << myintss.size() << '\n';
            
![image](https://github.com/paulynaa/Darbas3/assets/147087833/667f9837-8a10-4b5d-a507-627e8f763c77)

__resize()__

            std::vector<int> myvector;
            for (int i=1;i<10;i++) myvector.push_back(i);
            myvector.resize(5);
            myvector.resize(8,100);
            myvector.resize(12);
            std::cout << "std::vector contains:";
            for (int i=0;i<myvector.size();i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';

            Vector<int> myvectorr;
            for (int i=1;i<10;i++) myvectorr.push_back(i);
            myvectorr.resize(5);
            myvectorr.resize(8,100);
            myvectorr.resize(12);
            std::cout << "Vector contains:";
            for (int i=0;i<myvectorr.size();i++)
                std::cout << ' ' << myvectorr[i];
            std::cout << '\n';
            
![image](https://github.com/paulynaa/Darbas3/assets/147087833/ca9dd5e6-3ff0-47e2-b809-70e18c349f62)

__begin()__

            std::vector<int> myvector;
            for (int i=1; i<=5; i++) myvector.push_back(i);
            std::cout << "std::vector contains:";
            for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;
            std::cout << '\n';

            Vector<int> myvectorr;
            for (int i=1; i<=5; i++) myvectorr.push_back(i);
            std::cout << "Vector contains:";
            for (Vector<int>::iterator itt = myvectorr.begin() ; itt != myvectorr.end(); ++itt)
                        std::cout << ' ' << *itt;
            std::cout << '\n';
            
![image](https://github.com/paulynaa/Darbas3/assets/147087833/69f01fb0-1f8f-42b6-9777-54604426f480)


# Palyginu kiek vidutiniškai laiko užtrunka  std::vector tipo ir mano Vector tipo tuščius vektorius užpildyti: 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją.


![image](https://github.com/paulynaa/Darbas3/assets/147087833/f351ef5b-210b-4d71-9f00-2bf32c328b88)


            std::vector<size_t> sizes = {10000, 100000, 1000000, 10000000, 100000000};
            for (size_t sz : sizes) {
                        auto start = high_resolution_clock::now();
                        std::vector<int> v1;
                        for (int i = 1; i <= sz; ++i)
                                    v1.push_back(i);
                        auto end = high_resolution_clock::now();
                        duration<double> duration_std = end - start;
                        std::cout << "std::vector uzpilde " << sz << " elementu per " << duration_std.count() << " s\n";
                        start = high_resolution_clock::now();
                        Vector<int> v2;
                        for (int i = 1; i <= sz; ++i)
                                    v2.push_back(i);
                        end = high_resolution_clock::now();
                        duration<double> duration_custom = end - start;
                        std::cout << "Vector uzpilde " << sz << " elementu per " << duration_custom.count() << " s\n";
            }


# Palyginu kiek kartų įvyksta konteinerių (Vector ir std::vector) atminties perskirstymai užpildant 100 000 000 elementų.

            
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


# Atlieku spartos analizę naudojant duomenų failą su 100 000, 1 000 000 ir 10 000 000 studentų įrašų naudojant std::vector ir Vector realizacijas.


|Vector|Nuskaitymas|Skirstymas|Rūšiavimas|Išvedimas|std::vector|Nuskaitymas|Skirstymas|Rūšiavimas|Išvedimas|
|---|-----|-----------|------------------|-----|-----------|------------------|---------|---|---|
|100 000|0.135 s.| 0.034 s.|0.085 s.|0.299 s. |100 000|0.138 s.|0.015 s.|0.023 s.|0.347 s.| 
|1 000 000|2.358 s.| 0.383 s.|0.928 s.| 3.116 s.|1 000 000|2.828 s.|0.266 s.|0.236 s.|3.839 s.| 
|10 000 000|24.349 s.| 3.880 s.| 11.513 s.| 46.485 s.|10 000 000|26.800 s.| 2.756 s.| 3.280 s.|37.218 s.| 

Lygindami laiką su 10 000 000 įrašų matome, kad sumoje, std::vector veikia kažkiek trumpiau, bet didelio skirtumo nepastebime.


# Testuoju savo sukurtą Vector konteinerį su Native testais


Iš viso turiu 13 testų:

![image](https://github.com/paulynaa/Darbas3/assets/147087833/f99e7b74-539f-4d87-a812-fd7c485c0740)


# Sukuriu programos diegimo failą Setup.exe


Tai atlikti naudoju __Inno Setup Compiler__, kuris padeda lengvai ir greitai sukurti Setup.exe failą.


![image](https://github.com/paulynaa/Darbas3/assets/147087833/dea70da3-b0b6-4182-9bf5-2e1ac2c4fecc)


Setup failas atsisiunčia į  __C:/Program files/VU/Paulina-Podgaiska__ aplankalą kartu su testavimo failais, naudojimosi instrukcija. Taip pat Setup failas automatiškai įjungia administravimo teisės paleidžiamai programai.


![image](https://github.com/paulynaa/Darbas3/assets/147087833/06160e0a-aaa5-4c19-91e7-3170f918c206)



