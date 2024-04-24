# Programos veikimas
1. Paleidus programą vartotojas turi galimybę iš meniu pasirinkti: 1.Įvesti visus duomenis ranka; 2.Atsitiktinai generuoti tik pažymius; 3.Atsitiktinai generuoti ir studentus, ir pažymius; 4.Nuskaityti duomenis iš failo; 5.Generuoti failus; 6.Skaičiuoti sugeneruotus failus; 7.Testuoti klase; 8.Baigti programą.
2. Pasirinkus 1., 2. arba 3. variantą, vartotojas tik suvedimo metu nusprendžia kada jis nori atitinkamai baigti studentų ar pažymių generavimą/suvedimą.
3. Pasirinkus 4. variantą vartotojas turi galimybę pasirinkti failą, nuo kurio bus nuskaityti duomenys (taip pat vartotojas gali pats nustatyti kiek studentų nori nuskaityti).
4. Priklausomai nuo pasirinktos pozicijos, vartotojas suvedęs paskutinius duomenis mato lentelę su rezultatais, kurią galima tęsti pildyti arba paspaudus 5. - baigti programą.
5. Pozicijoje 4. galima pasirinkti duomenų išvedimo būdą: į ekraną arba į tekstinį failą, bei rūšiavimą pagal pavardę, vardą, galutinį pažymį ir medianą.
6. Rezultatų lentelėje/faile išvedami studentų: Pavardė, Vardas, Galutinis(Vid.) ir Galutinis(Med.).
7. Pasirinkus 5. poziciją, vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti.
8. Pasirinkus 6. poziciją, prieš tai sugeneruotus failus programa nuskaito ir surūšiuoja į du naujus failus:viename paskirstyti visi studentai, kurių galutinis pažymis didesnis arba lygus 5, kitame studentai, kurių pažymis mažesnis nei 5. Yra galimybė pasirinkti pagal ką (didėjimo tvarka) bus išvesti rezultatai į naujus failus: pagal galutinį pažymį arba medianą. Taip pat pateikiamas laikas, per kurį sugeneruoti failai buvo nuskaityti, surūšiuoti ir išvesti i du naujus failus.
9. Pasirinkus 7 poziciją, programa testuoja ar konstruktoriai, copy ir move metodai, destruktorius veikia atitinkamai.
# v1.1
**Repozitorijos klonavimas**
Visų pirma repozitorija "Darbas1" buvo nuklonuota ir padaryta nauja repozitorija "Darbas2".

**Pirmas testas**

Palyginome abiejų programų:naudojančių struct ir naudojančių class spartą, naudojant vector konteinerį ir 3 dalijimo strategiją su 1 000 000 ir 10 000 000 dydžio failais.

**Antras testas**

Išanalizavome, kaip keičiasi programos sparta priklausomai nuo kompiliatoriaus optimizavimo lygio , nurodomo per flag'us: -O1, -O2, -O3. Palyginome programas naudojančias struct ir class. Taip pat ziurejome kaip keiciasi exe dydis priklausomai nuo naudojamo flag'o.

# v1.2
**Rule of five**

Atliekant užduotį reikėjo įgyvendinti visus reikiamus "Rule of five" metodus, t.y. copy konstruktorius, copy assignment operatorius, move konstruktorius, move assignment operatorius, destruktorius, taip pat įvesties/išvesties operatorius, kurie veiktų su mano klase.

**Įvestis / išvestis**

Kaip pvz, tai yra isvesties operatorius:

![image](https://github.com/paulynaa/Darbas2/assets/147087833/7a79d9e3-cc30-4e50-b64c-8602cf8f6173)

# v1.5
**class Pazymiai VS bazine class Zmogus ir derived class Pazymiai**
Sioje dalyje reikejo vietoje turimos vienos klasės Pazymiai sukurti dvi: bazinę klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę klasę - Pazymiai.
Zmogui skirta bazinė klasė yra abstrakčioji klasė.
Veliau patikrinome, ar keiciasi programos veikimo sparta priklausomai nuo klases. Rezultatai buvo pateikti lenteleje.

# v2.0
**Doxygen diegimo instrukcija**

**CLion**

**Google tests**

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
