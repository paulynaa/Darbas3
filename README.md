# Trijų vienodų programų veikimas su skirtingais konteineriais
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Baigti programą.
2. Pasirinkus 1., 2. arba 3. variantą, vartotojas tik suvedimo metu nusprendžia kada jis nori atitinkamai baigti studentų ar pažymių generavimą/suvedimą.
3. Pasirinkus 4. variantą vartotojas turi galimybę pasirinkti failą, nuo kurio bus nuskaityti duomenys (taip pat vartotojas gali pats nustatyti kiek studentų nori nuskaityti).
4. Priklausomai nuo pasirinktos pozicijos, vartotojas suvedęs paskutinius duomenis mato lentelę su rezultatais, kurią galima tęsti pildyti arba paspaudus 5. - baigti programą.
5. Pozicijoje 4. galima pasirinkti duomenų išvedimo būdą: į ekraną arba į tekstinį failą, bei rūšiavimą pagal pavardę, vardą, galutinį pažymį ir medianą.
6. Rezultatų lentelėje/faile išvedami studentų: Pavardė, Vardas, Galutinis(Vid.) ir Galutinis(Med.).
7. Pasirinkus 5. poziciją, vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti, nuskaityti, surūšiuoti ir išvesti i du naujus failus: viename paskirstyti visi studentai, kurių galutinis pažymis didesnis arba lygus 5, kitame studentai, kurių pažymis mažesnis nei 5.
# Pirmas testas
Ištirsime, kaip pasikeistų programos sparta naudojant skirtingo tipo konteinerius: std::vector<Pazymiai>, std::list<Pazymiai> ir std::deque<Pazymiai>. Testavimo tikslumui naudosiu tuos pačius sugeneruotus studentų failus su 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų ir fiksuosiu šiuos žingsnius: duomenų nuskaitymą iš failų į atitinkamą konteinerį, studentų rūšiavimą didėjimo tvarką konteineryje, studentų skirstymą  į dvi grupes/kategorijas.
# Testavimo sistemos parametrai
1. CPU: 11th Gen Intel Core i7-1165G7 2.80GHz
2. RAM: 16,0 GB
3. HDD: SAMSUNG MZVL2512HCJQ-00BL7
# Pirmo testo rezultatas
|  <td colspan="3"> vector </td> <td colspan="3"> deque </td> <td colspan="3"> list </td> ||||||||||
|----|------|---------|---------|----------|------------|----------|---------|-----|-----|
|Failai| Nuskaitymas | Rūšiavimas | Išvedimas |  Nuskaitymas | Rūšiavimas | Išvedimas |  Nuskaitymas | Rūšiavimas | Išvedimas | 
| 1 000 | 0.007 s.| 0 s.| 0.009 s. | 0.008 s.| 0 s. | 0.008 s. | 0.016 s. | 0 s.| 0.019 s.|
| 10 000| 0.048 s. | 0.016 s.| 0.064 s.| 0.057 s.| 0.032 s.| 0.064 s.| 0.132 s.| 0.013 s.| 0.09 s.|
| 100 000|0.194 s.| 0.161 s.| 0.507 s.| 0.297 s.| 0.352 s.| 0.612 s.| 0.557 s.| 0.081 s.| 0.697 s.|
| 1 000 000| 3.686 s.| 1.826 s. | 4.932 s.| 5.280 s.| 4.809 s.| 6.144 s.|11.613 s.| 1.398 s.| 8.976 s.|
| 10 000 000| 47.372 s.| 23.126 s.| 61.237 s.| 62. 396 s. |65.301 s.| 119.168 s.| 127.846 s.| 23.214 s.| 105.681 s.|
