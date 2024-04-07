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

__Įvestis__

Įvesčiai naudojami setter'iai.

Pvz.: setVar įrašo studento vardą.
Gavęs vardą, jis jį saugo var_ private member kintamajame.

__Rankinis įvedimas__

![image](https://github.com/paulynaa/Darbas2/assets/147087833/b3dd4fbf-0cf5-4d19-9a15-70dda8680927)


__Automatinė įvestis__

![image](https://github.com/paulynaa/Darbas2/assets/147087833/01ae4b0c-c8ac-4b3a-96e3-312a28f621f7) 

![image](https://github.com/paulynaa/Darbas2/assets/147087833/4a822ad0-47d7-4dc3-9be7-0d6d245a25b4)


__Įvestis iš failo__

![image](https://github.com/paulynaa/Darbas2/assets/147087833/e8c0fd41-1dc6-47c0-8e6d-372b309b98ae)

![image](https://github.com/paulynaa/Darbas2/assets/147087833/b135d0ab-fb74-4966-b9e7-868a5470c8d4)



__Išvestis__

Išvesčiai naudojami getter'iai. 

Pvz.: getVar metodas gauna studento vardą iš private srities naudodamas getVar metodą. 
Tada jį galima atvaziduoti ekrane arba įrašyti į failą (priklausomai nuo pasirinkimo). 


__Rodymas ekrane__

![image](https://github.com/paulynaa/Darbas2/assets/147087833/423a366b-62f1-4a00-a2f6-ab4fc9f6b982)


__Rodymas faile__

![image](https://github.com/paulynaa/Darbas2/assets/147087833/9c0c96b8-c967-4b47-9a6d-c2efcde1b727)

