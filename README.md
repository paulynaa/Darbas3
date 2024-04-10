# Programos veikimas su vector konteineriu
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Skaičiuoti sugeneruotus failus; 7.Testuoti klase; 8.Baigti programą.
2. Pasirinkus 1., 2. arba 3. variantą, vartotojas tik suvedimo metu nusprendžia kada jis nori atitinkamai baigti studentų ar pažymių generavimą/suvedimą.
3. Pasirinkus 4. variantą vartotojas turi galimybę pasirinkti failą, nuo kurio bus nuskaityti duomenys (taip pat vartotojas gali pats nustatyti kiek studentų nori nuskaityti).
4. Priklausomai nuo pasirinktos pozicijos, vartotojas suvedęs paskutinius duomenis mato lentelę su rezultatais, kurią galima tęsti pildyti arba paspaudus 5. - baigti programą.
5. Pozicijoje 4. galima pasirinkti duomenų išvedimo būdą: į ekraną arba į tekstinį failą, bei rūšiavimą pagal pavardę, vardą, galutinį pažymį ir medianą.
6. Rezultatų lentelėje/faile išvedami studentų: Pavardė, Vardas, Galutinis(Vid.) ir Galutinis(Med.).
7. Pasirinkus 5. poziciją, vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti.
8. Pasirinkus 6. poziciją, prieš tai sugeneruotus failus programa nuskaito ir surūšiuoja į du naujus failus:viename paskirstyti visi studentai, kurių galutinis pažymis didesnis arba lygus 5, kitame studentai, kurių pažymis mažesnis nei 5. Yra galimybė pasirinkti pagal ką (didėjimo tvarka) bus išvesti rezultatai į naujus failus: pagal galutinį pažymį arba medianą. Taip pat pateikiamas laikas, per kurį sugeneruoti failai buvo nuskaityti, surūšiuoti ir išvesti i du naujus failus.
9. Pasirinkus 7 poziciją, programa testuoja ar konstruktoriai, copy ir move metodai, destruktorius veikia atitinkamai.


# Zmogus klases objektu kurimas negalimas

![image](https://github.com/paulynaa/Darbas2/assets/147087833/005e966a-789f-4409-8747-d96442a90b68)

# class Pazymiai VS bazine class Zmogus ir derived class Pazymiai

 __class__
 
|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 5.761 s.| 0.673 s.| 2.650 s.|
|10 000 000| 51.122 s.| 5.286 s.| 24.780 s.|


 __bazine ir derived__

|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000 000| 8.911 s.| 0.801 s.| 0.950 s.|
|10 000 000| 80.872 s.| 8.186 s.| 13.680 s.|
