# Programos veikimas su vector konteineriu
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Skaičiuoti sugeneruotus failus; 7.Baigti programą.
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
# Antras testas
Optimizuojamas studentų skirstymo į dvi kategorijas (kurių galutinis rezultatas didesnis arba mažesnis 5) realizaciją. Visiems trims konteinerių tipams (vector, list ir deque) išmatuojamas programos veikimo laikas priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:
1. strategija: Bendro studentai konteinerio skirstymas į du naujus to paties tipo konteinerius. Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų.
2. strategija: Bendro studentų konteinerio skirstymas panaudojant tik vieną naują konteinerį. Tokiu būdu, jei studeno galutinis balas<5, jį turime įkelti į naująjį konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik studentai su galutiniu balu >=5.
3. strategija: Bendro studentų konteinerio skirstymas panaudojant greičiausiai veikianti 1 strategija, įtraukiant į ją algoritmus std::partition ir std::copy.
# Antro testo rezultatai
Lyginsime nuskaitymo, skirstymo ir rūšiavimo laikus. Taip pat uzimamos atminties atzvilgiu palyginsime 10 000 000 studentu faila(ekrano kopija).
# VECTOR
|1 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000| 0.0001 s.| 0.001 s.| 0.0002 s.|
|10 000| 0.018 s.| 0.001 s.| 0.008 s.|
|100 000| 0.078 s.| 0.015 s.| 0.102 s.|
|1 000 000| 1.609 s.| 0.169 s.| 1.450 s.|
|10 000 000| 19.022 s.| 2.396 s.| 18.480 s.|
![image](https://github.com/paulynaa/Darbas1/assets/147087833/bcdf6a79-0844-4f53-a1a7-469d132b08f9)

|2 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000| 0.003 s.| 0.0001 s.| 0.001 s.|
|10 000| 0.023 s.| 0.014 s.| 0.011 s.|
|100 000| 0.131 s.| 1.026 s.| 0.426 s.|
|1 000 000| 3.436 s.| 477.169 s.| 1.650 s.|
|10 000 000|...| 4h+|...|
![image](https://github.com/paulynaa/Darbas1/assets/147087833/be87db90-1725-47c3-a87e-90d3cf72dd6f)

|3 strategija|Nuskaitymas|Skirstymas|Rūšiavimas|
|---|-----|-----------|------------------|
|1 000| 0.001 s.| 0.0001 s.| 0.001 s.|
|10 000| 0.013 s.| 0.003 s.| 0.009 s.|
|100 000| 0.122 s.| 0.027 s.| 0.102 s.|
|1 000 000| 3.061 s.| 0.533 s.| 1.550 s.|
|10 000 000| 17.022 s.| 3.996 s.| 18.480 s.|
![image](https://github.com/paulynaa/Darbas1/assets/147087833/24dee990-864e-444c-819c-0e701310e7c6)

1 strategija pasirodė geriausiai spartos ir užimamos atminties atžvilgiu.
2 strategija nors ir neužima daug atminties, bet užtrunka per ilgai ypač su didesniais failais (10mln studentų).
3 strategija užima daugiau atminties, bet nelabai skiriasi nuo pirmos laiko atžvilgiu.
# Programos diegimo instrukcijos
1. Pirma, turite susikurti savo GitHub paskyrą. Galite pasinaudoti instrukcijomis: https://docs.github.com/en/get-started/onboarding/getting-started-with-your-github-account
2. Norėdami rasti kodą, įveskite nuorodą į paieškos eilę. Pavyzdžiui: https://github.com/paulynaa/Darbas1/tree/v1.0
3. Atidarykite "Command Prompt" (komandinę eilutę) savo kompiuteryje.
4. Į terminalą įveskite šią komandą: git clone https://github.com/paulynaa/Darbas1.git
5. Atidarykite programą, kurioje norite paleisti kodą. Pvz. Paleiskite CodeBlocks IDE. Jei dar neparsisiuntėte jos, galite tai padaryti iš oficialios svetainės: https://www.codeblocks.org/downloads/
6. Kai CodeBlocks įdiegtas, atidarykite jį iš jūsų programų sąrašo arba darbalaukio shortcut'o.
7. Sukurkite naują projektą, pasirinkdami "File" > "New" > "Project..." iš meniu.
8. Pasirinkite "Console Application" ir spustelėkite "Go."
9. Pasirinkite "C++" kaip kalbą ir spustelėkite "Next."
10. Įveskite projekto pavadinimą ir pasirinkite direktoriją, kur norite išsaugoti savo projekto failus. Tada spustelėkite "Next."
11. Pasirinkite "GNU GCC Compiler" ir spustelėkite "Finish."
12. Projekto darbalaukyje raskite vietą, kurioje klonavote GitHub saugyklą, naudodami "File" > "Open" meniu parinktį.
13. Pasirinkite aplanką "Darbas1" ir spustelėkite "Open", kad įkeltumėte projekto failus į CodeBlocks.
14. CodeBlocks darbalaukyje turėtumėte pamatyti failus iš klonuotos saugyklos. Dukart spustelėkite pagrindinį šaltinio failą (main***.cpp), kad jį atidarytumėte.
15. Peržiūrėkite kodą ir atlikite bet kokius būtinus pakeitimus ar pridėjimus.
16. Kai esate pasiruošę sukompiliuoti ir paleisti kodą, spustelėkite "Build and run" mygtuką įrankių juostoje arba pasirinkite "Build" > "Build and run" iš meniu.
17. CodeBlocks sukompiliuos kodą ir paleis programą. Jei nėra klaidų, turėtumėte pamatyti rezultatą CodeBlocks konsolės lange.
18. Dirbant su terminalu galite paleisti programą naudojant makefile failus, prikabintus repozitorijoje, priklausomai nuo norimos programos įrašykite :
    * make vektoriai
    * make programa
    * arba
    * make deque
    * make programa
    * arba
    * make list
    * make programa
19. Kaip naudotis ir kokiu principu veikia programa galite matyti pačioj pradžioj README failo.
