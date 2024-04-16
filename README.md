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

# Rule of five

Atliekant užduotį reikėjo įgyvendinti visus reikiamus "Rule of five" metodus, t.y. copy konstruktorius, copy assignment operatorius, move konstruktorius, move assignment operatorius, destruktorius, taip pat įvesties/išvesties operatorius, kurie veiktų su mano klase.


Copy konstruktorius: Šis metodas yra naudojamas norint sukurti naują objektą, kuris yra kopija iš esamo objekto. Tai padaryta panaudojant const nuorodą į esamą objektą.

Copy assingment operatorius: Šis metodas leidžia priskirti vieną objektą kitam objektui. Yra tikrinama, ar priskiriamas objektas nėra toks pats, kaip ir objektas, kuriam priskiriame.

Move konstruktorius: Šis metodas leidžia perkelti turinį iš vieno objekto į kitą. Jis naudoja rvalue nuorodą, kad pasisavintų kitą objektą.

Move assignment operatorius: Šis metodas leidžia perkelti turinį iš vieno objekto į kitą naudojant priskyrimo operatorių. Taip pat tikrina, ar priskiriamas objektas nėra toks pats, kaip ir objektas, kuriam priskiriame.

Kiekvienas iš šių metodų užtikrina, kad objektų duomenys būtų teisingai kopijuojami arba perkelti į naujus objektus, taip išvengiam klaidų.

# Įvestis / išvestis
Visų pirma klasėje implementuoju input/output operatorius ir juos testuoju.

![image](https://github.com/paulynaa/Darbas2/assets/147087833/a3e9db3e-645e-4235-adcf-4dd03a4cb5ad)


Rezultatas::

![image](https://github.com/paulynaa/Darbas2/assets/147087833/c0e28de0-ace9-4cc9-93bd-2fcf6c047a6b)


Pakeičiam 7 į 6, testas turėtų būti nesėkmingas.

![image](https://github.com/paulynaa/Darbas2/assets/147087833/8170ea78-5784-4867-ac11-eb5e406ea368)


Rezultatas::

![image](https://github.com/paulynaa/Darbas2/assets/147087833/ef912db2-027b-4064-8e8f-1992c02ab7f6)




