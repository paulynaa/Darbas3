# Programos veikimas su vector konteineriu
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Skaičiuoti sugeneruotus failus; 7.Baigti programą.
2. Pasirinkus 1., 2. arba 3. variantą, vartotojas tik suvedimo metu nusprendžia kada jis nori atitinkamai baigti studentų ar pažymių generavimą/suvedimą.
3. Pasirinkus 4. variantą vartotojas turi galimybę pasirinkti failą, nuo kurio bus nuskaityti duomenys (taip pat vartotojas gali pats nustatyti kiek studentų nori nuskaityti).
4. Priklausomai nuo pasirinktos pozicijos, vartotojas suvedęs paskutinius duomenis mato lentelę su rezultatais, kurią galima tęsti pildyti arba paspaudus 5. - baigti programą.
5. Pozicijoje 4. galima pasirinkti duomenų išvedimo būdą: į ekraną arba į tekstinį failą, bei rūšiavimą pagal pavardę, vardą, galutinį pažymį ir medianą.
6. Rezultatų lentelėje/faile išvedami studentų: Pavardė, Vardas, Galutinis(Vid.) ir Galutinis(Med.).
7. Pasirinkus 5. poziciją, vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti.
8. Pasirinkus 6. poziciją, prieš tai sugeneruotus failus programa nuskaito ir surūšiuoja į du naujus failus:viename paskirstyti visi studentai, kurių galutinis pažymis didesnis arba lygus 5, kitame studentai, kurių pažymis mažesnis nei 5. Yra galimybė pasirinkti pagal ką (didėjimo tvarka) bus išvesti rezultatai į naujus failus: pagal galutinį pažymį arba medianą. Taip pat pateikiamas laikas, per kurį sugeneruoti failai buvo nuskaityti, surūšiuoti ir išvesti i du naujus failus.
# Repozitorijos klonavimas
Visų pirma repozitorija "Darbas1" buvo nuklonuota ir padaryta nauja repozitorija "Darbas2". Tai buvo padaryta naudojant šias komandas terminale:
git clone --mirror https://github.com/paulynaa/Darbas1.git

git clone --bare C:\Users\Paulina\Darbas1.git Darbas2

git branch -a

git remote set-url origin https://github.com/paulynaa/Darbas2.git

git push --mirror
# Testavimo sistemos parametrai
1. CPU: 11th Gen Intel Core i7-1165G7 2.80GHz
2. RAM: 16,0 GB
3. HDD: SAMSUNG MZVL2512HCJQ-00BL7
# Pirmas testas
Palyginsime abiejų programų:naudojančių struct iš ankstesniojo darbo ir naudojančių class iš dabartinės realizacijos spartą, naudojant vector konteinerį ir 3 dalijimo strategiją su 1 000 000 ir 10 000 000 dydžio failus.
# Pirmo testo rezultatas
# struct 
|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 3.061 s.| 0.533 s.| 1.550 s.|
|10 000 000| 17.022 s.| 3.996 s.| 18.480 s.|

# class
|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 5.761 s.| 0.673 s.| 2.650 s.|
|10 000 000| 51.122 s.| 5.286 s.| 24.780 s.|

# Antras testas
Išanalizuosime, kaip keičiasi programos sparta priklausomai nuo kompiliatoriaus optimizavimo lygio , nurodomo per flag'us: -O1, -O2, -O3. Palyginsime programas naudojančias struct ir class. Taip pat matysime kaip keiciasi exe dydis priklausomai nuo naudojamo flag'o.
# Antro testo rezultatai
# struct 
|flag -O |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 3.061 s.| 0.533 s.| 1.550 s.|
|10 000 000| 17.022 s.| 3.996 s.| 18.480 s.|

|flag -O1 |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 2.401 s.| 0.212 s.| 1.120 s.|
|10 000 000| 22.022 s.| 2.596 s.| 15.980 s.|

|flag -O2 |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 1.801 s.| 0.219 s.| 1.220 s.|
|10 000 000| 18.722 s.| 2.186 s.| 15.480 s.|

|flag -O3 |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 1.791 s.| 0.156 s.| 0.220 s.|
|10 000 000| 21.522 s.| 1.786 s.| 2.880 s.|

Pastebime, kad didejant flagams, gereja programos sparta, ypac gerai pasirodo -O3 flagas rūšiuojant studentus.

# class

|flag -O |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 5.761 s.| 0.673 s.| 2.650 s.|
|10 000 000| 51.122 s.| 5.286 s.| 24.780 s.|

|flag -O1 |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 2.601 s.| 0.502 s.| 1.420 s.|
|10 000 000| 28.722 s.| 3.986 s.| 19.280 s.|

|flag -O2 |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 2.101 s.| 0.319 s.| 0.720 s.|
|10 000 000| 22.722 s.| 3.186 s.| 10.660 s.|

|flag -O3 |Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 2.101 s.| 0.290 s.| 1.780 s.|
|10 000 000| 22.722 s.| 3.186 s.| 10.480 s.|

Pastebime, kad tokio didelio šuolio rūšiuojant, kaip tai buvo su struct nėra, taipogi nėra didelio skirtumo greityje tarp flago -O2 ir -O3. Visais atvejais programa su struct veikia greičiau.

# .exe file

|flag | -O | -O1 | - O2| -O3|
|---|-----|-----------|------------------|--------|
|struct| 1 139 KB| 2 608 KB| 2 753 KB| 4 272 KB |
|class| 1 203 KB | 2 539 KB| 3 551 KB | 4 052 KB|
