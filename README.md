# Trijų vienodų programų veikimas su skirtingais konteineriais
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Baigti programą.
2. Pasirinkus 1., 2. arba 3. variantą, vartotojas tik suvedimo metu nusprendžia kada jis nori atitinkamai baigti studentų ar pažymių generavimą/suvedimą.
3. Pasirinkus 4. variantą vartotojas turi galimybę pasirinkti failą, nuo kurio bus nuskaityti duomenys (taip pat vartotojas gali pats nustatyti kiek studentų nori nuskaityti).
4. Priklausomai nuo pasirinktos pozicijos, vartotojas suvedęs paskutinius duomenis mato lentelę su rezultatais, kurią galima tęsti pildyti arba paspaudus 5. - baigti programą.
5. Pozicijoje 4. galima pasirinkti duomenų išvedimo būdą: į ekraną arba į tekstinį failą, bei rūšiavimą pagal pavardę, vardą, galutinį pažymį ir medianą.
6. Rezultatų lentelėje/faile išvedami studentų: Pavardė, Vardas, Galutinis(Vid.) ir Galutinis(Med.).
7. Pasirinkus 5. poziciją, vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti.
8. Pasirinkus 6. poziciją, prieš tai sugeneruotus failus programa nuskaito ir surūšiuoja į du naujus failus:viename paskirstyti visi studentai, kurių galutinis pažymis didesnis arba lygus 5, kitame studentai, kurių pažymis mažesnis nei 5. Yra galimybė pasirinkti pagal ką (didėjimo tvarka) bus išvesti rezultatai į naujus failus: pagal galutinį pažymį arba medianą. Taip pat pateikiamas laikas, per kurį sugeneruoti failai buvo nuskaityti, surūšiuoti ir išvesti i du naujus failus.
# Pirmas testas
Ištirsime, kaip pasikeistų programos sparta naudojant skirtingo tipo konteinerius: std::vector<Pazymiai>, std::list<Pazymiai> ir std::deque<Pazymiai>. Testavimo tikslumui naudosiu tuos pačius sugeneruotus studentų failus su 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų ir fiksuosiu šiuos žingsnius: duomenų nuskaitymą iš failų į atitinkamą konteinerį, studentų rūšiavimą didėjimo tvarką konteineryje, studentų skirstymą  į dvi grupes/kategorijas.
# Testavimo sistemos parametrai
1. CPU: 11th Gen Intel Core i7-1165G7 2.80GHz
2. RAM: 16,0 GB
3. HDD: SAMSUNG MZVL2512HCJQ-00BL7
# Pirmo testo rezultatas
|  <td colspan="3"> vector </td> <td colspan="3"> deque </td> <td colspan="3"> list </td> ||||||||||
|----|------|---------|---------|----------|------------|----------|---------|-----|-----|
|Failai| Nuskaitymas | Skirstymas | Rūšiavimas |  Nuskaitymas | Skirstymas | Rūšiavimas |  Nuskaitymas | Skirstymas | Rūšiavimas | 
| 1 000 | 0.003 s.| 0.001 s.| 0.002 s. | 0.004 s.| 0.001 s. | 0.001 s. | 0.007 s. | 0.001 s.| 0.001 s.|
| 10 000| 0.014 s. | 0.001 s.| 0.009 s.| 0.028 s.| 0.004 s.| 0.018 s.| 0.093 s.| 0.017 s.| 0.008 s.|
| 100 000|0.078 s.| 0.008 s.| 0.103 s.| 0.097 s.| 0.015 s.| 0.238 s.| 0.430 s.| 0.071 s.| 0.077 s.|
| 1 000 000| 1.709 s.| 0.219 s. | 1.320 s.| 1.807 s.| 0.246 s.| 3.197 s.| 8.189 s.| 1.638 s.| 1.976 s.|
| 10 000 000| 14.763 s.| 1.979 s.| 17.176 s.| 17.203 s. | 2.467 s.| 42.384 s.| 96.846 s.| 15.214 s.| 22.681 s.|
