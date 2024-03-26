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
For this part of project I made a clone of my first repository named "PirmaUzduotis" and created a new repository "AntraUzduotis". I did it using terminal in my computer. Commands that I used:

git clone --mirror https://github.com/aran1ja/PirmaUzduotis.git

git clone --bare C:\Users\acer\PirmaUzduotis.git AntraUzduotis

git branch -a

git remote set-url origin https://github.com/aran1ja/AntraUzduotis.git

git push --mirror
# Testavimo sistemos parametrai
1. CPU: 11th Gen Intel Core i7-1165G7 2.80GHz
2. RAM: 16,0 GB
3. HDD: SAMSUNG MZVL2512HCJQ-00BL7
# Pirmas testas
Palyginkite abiejų Jūsų programų: naudojančios struct iš ankstesniojo darbo ir naudojančio class tipo Studentus iš dabartinės realizacijos spartą (veikimo laiką), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100000 ir 1000000 dydžio failus. 

# Pirmo testo rezultatas
struct
|----|------|---------|---------|----------|------------|----------|---------|-----|-----|
| 1 000 000| 1.709 s.| 0.219 s. | 1.320 s.| 1.807 s.| 0.246 s.| 3.197 s.| 8.189 s.| 1.638 s.| 1.976 s.|
| 10 000 000| 14.763 s.| 1.979 s.| 17.176 s.| 17.203 s. | 2.467 s.| 42.384 s.| 96.846 s.| 15.214 s.| 22.681 s.|

class

# Antras testas
Atlikite eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3 i
# Antro testo rezultatai


struct 
|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 3.061 s.| 0.533 s.| 1.550 s.|
|10 000 000| 17.022 s.| 3.996 s.| 18.480 s.|

class 

