# Opgaver til IMPR Lektion 9
For de fleste af dagens opgaver er det passende at 
1) implementere funktionen i et lille bibliotek (evt. kan alle opgaverne ligge i samme programbibliotek), og
2) skrive en eller flere tests af funktionen ved brug af CTest

## Gruppeopgaver
Disse opgaver laves sammen i gruppen. Der er rigeligt med opgaver.
Arbejd grundigt med de opgaver, I kan nå, i den skemalagte tid.

### [Opgave A](src/opgave-a.c): Flertals navneord
Dette er Kurt Nørmark's [opgave 10.3](https://homes.cs.aau.dk/~normark/impr-c/strings-extra-opgaver-slide-exercise-1.html).
Du kan skrive dit program i filen [`opgave-a.c`](src/opgave-a.c).

> Skriv et program som oversætter udvalgte engelske navneord fra ental til flertal. Følgende regler skal overholdes:
> 1. Hvis et navneord ender i et "y" fjernes "y" og der tilføjes "ies".
> 2. Hvis et navneord ender i et "s", "ch" eller "sh" tilføjes et "es".
> 3. I alle andre tilfælde tilføjes et "s" til navneordet.
> 
> Udskriv hvert navneord i både ental og flertal.
> 
> Som altid skal du designe en funktion med et passende navn, og med parametre (input og evt. output). Og som altid laver vi top-down programmering ved trinvis forfinelse. Ønsker du at bruge returværdien af funktionen til noget?
> 
> Afprøv dit program på følgende engelske navneord:
> - `chair dairy boss circus fly dog church clue dish`
> 
> Alloker plads til disse i en passende array af tekststrenge.
> 
> _Hints_: Måske er funktionen `strrchr` fra `string.h` nyttig i denne opgave. 
> Den søger efter et tegn fra bagenden af strengen. 
> Husk også at du blot kan tilgå tegn i en tekststreng med array subscripting operatoren: `str[i]`. 
> Du kan teste om et tegn i din streng svarer til et bestemt tegn: `str[i] == 'y'`.

---
### [Opgave B](src/opgave-b.c): Funktionen strrev
Dette er Kurt Nørmark's [opgave 10.1](https://homes.cs.aau.dk/~normark/impr-c/strings-string-mutation-slide-exercise-1.html).
Du kan skrive dit program i filen [`opgave-b.c`](src/opgave-b.c).

> Strengomvending består i at bytte om på tegnene i en tekststreng, således at de første tegn ender med at være de sidste. 
> Eksempelvis er strengomvendingen af "streng" lig med "gnerts".
> 
> Programmer funktionen `strrev(char *str)`, som omvender tegnene i parameteren `str`. 
> Bemærk at parameteren `str` både tjener som input og output parameter. 
> Vi ønsker altså at bytte om på tegnene i det `char` array, som `str` peger på.

---
### [Opgave C](src/opgave-c.c): Længste fælles endelse af to ord
Dette er Kurt Nørmark's [opgave 10.4](https://homes.cs.aau.dk/~normark/impr-c/strings-extra-opgaver-slide-exercise-2.html).
Du kan skrive dit program i filen [`opgave-c.c`](src/opgave-c.c).

> Skriv et program med en funktion der finder og returnerer det længste fælles endelse (suffix) af to ord.
> 
> Funktionen skal have tre parametre: De to ord (to tekststrenge) skal overføres som input parametre. 
> Og den længste fælles endelse skal returneres i en output parameter (også en tekststreng). 
> 
> Overvej: 
> - Hvordan markerer du forskellen på en input parameter og en output parameter, som begge er tekststrenge? 
> - Hvordan bliver der allokeret plads til tesktstrengen med den fælles endelse? Vil du bruge statisk eller dynamisk allokering?.
> 
> Som et eksempel er "logi" den længste fælles endelse af ordene "datalogi" og "biologi". 
> Og den længste fælles endelse af "program" og "diagram" er "gram".

---
### [Opgave D](src/opgave-d.c): Associative arrays
Dette er Kurt Nørmark's [opgave 9.9](https://homes.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-7.html).
Du kan skrive dit program i filen [`opgave-d.c`](src/opgave-d.c).

Der findes en [video](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-associative-arrays&course-id=impr&lecture-number=9&course-year=2026) der motiverer og introducerer associative arrays. 
Denne video, og arbejdet med opgaven om associative arrays, bliver relevant for miniprojekt 3. 

> Et array i C indiceres altid med et heltal, hvilket sikrer simpel og effektiv tilgang til elementer i arrayet. 
> Men i mange sammenhænge er det fristende og nyttigt at indicere et array med værdier af andre typer, så som en tekststreng.
> 
> Lad os eksempelvis antage, at vi ønsker at holde styr på alderen af navngivne personer ved brug af et array, `alder_af_person`. 
> For `"Peter"` kan vi dermed tilgå alderen med `alder_af_person["Peter"]`.
> 
> `alder_af_person` kan ikke være et array i C, men konceptuelt kan vi opfatte `alder_af_person` som et _associativt array_: 
> Et sådant array associerer navnet på en person med personen alder. Generelt giver det god mening, på denne måde, 
> at associere en vilkårlig værdi/objekt s af typen S til en værdi t i typen T via et associativt array a. 
> Vi slår T-værdien op med a[s], givet s i typen S.
> 
> Spørgsmålet er nu hvordan vi kan bruge arrays i C til at arbejde med associative arrays. Ideen er simpel nok. 
> Lad os illustrere den med S som en teksstreng, og T som int, og a som `alder_af_person`. 
> Personens navn skal først, med en funktion `h`, konverteres til et lovligt indeks i et C-array. 
> `h("Peter")` skal returnere et ikke-negativt heltal, nemlig det heltal hvor alderen af `"Peter"` skal findes. 
> Hermed kan vi fra personens navn, `"Peter"`, tilgå Peter's alder med
> ```c++
> alder[h("Peter")]
> ```
> hvor alder er et C array:
> ```c++
> int alder[MAX_PERSON_INDEX];
> ```
> Hvis vi først antager, at vi har et lille univers af mulige tekststrenge, kan vi ret let skrive en `h`-funktion, 
> som eksplicit afbilder et navn (en streng) til et indeks (et heltal). 
> Denne `h`-funktion sikrer at hver tekststreng tildeles hvert sit indeks. 
> Skriv en sådan `h`-funktion for navnene på dine medstuderende i din projektgruppe, 
> således at du kan indsætte og slå alderen af en studerende op i et associativt array (undgå danske bogstaver i navnene).
> 
> Hvis vi derimod antager, at vi har et meget stort univers af mulige teksstrenge, så som hele Danmarks befolkning, 
> bliver det meget besværligt at skrive funktionen `h`. Hvis vi forsøger vil det sikkert også bliver meget dyrt at kalde den, 
> fordi funktionen muligvis vil lave et arbejde proportionalt med befolkningens størrelse. 
> Men vi kan forsøge at beregne et passende heltal ud fra tegnene i personens navn, og normalisere tallet til et indeks i det ønskede interval. 
> (Funktionen kan eksempelvis tage alle, eller udvalgte, tegn i navnet, addere dem som de små heltal de jo er, og normalisere summet med modulo operatoren). 
> Problemet er nu, at to forskelle navne kan afbildes til det samme indeks. Vi siger at der sker en _kollision_.
> 
> Skriv, som en øvelse, en `h`-funktion efter denne ide, og prøv den af på navnene i jeres projektgruppe. 
> Oplever I kollisionsproblemet i denne øvelse?
> 
> Vi har med dette introduceret ideen om [hashtabeller og hashfunktioner](https://en.wikipedia.org/wiki/Hash_table), 
> som er vigtige i mange praktiske sammenhænge, hvor vi også skal udtænke strategier til håndtering af kollision.

---
## Hjemmeopgaver:
Dette er opgaver, som I kan arbejde med derhjemme.
Enten som forberedelse inden lektionen, eller som afrunding og repetition efter lektionen.

### [Opgave E](src/opgave-e.c)
Dette er opgave 2 på side 490 i afsnit 8.2 i Problem Solving and Program Design in C, eighth edition.
Du kan arbejde videre i filen [`opgave-e.c`](src/opgave-e.c).

> Complete function `trim_blanks` whose purpose is to take a single string input parameter (`to_trim`) 
> and return a copy of the string with leading and trailing blanks removed. Use `strncpy` in `trim_blanks`.
> 
> On the input `"  a phrase    "` it should return `"a phrase"`.

---
### [Opgave F](src/opgave-f.c)
Dette er opgave 1 på side 518 i afsnit 8.7 i Problem Solving and Program Design in C, eighth edition.
Du kan skrive dit program i filen [`opgave-f.c`](src/opgave-f.c).

> Write a type `int` function `strtoint` and a type `double` function `strtodouble` 
> that converts string representations of numbers to their numeric equivalents.
> - `strtoint("-8")` gives the value `-8`
> - `strtodouble("-75.812")` gives the value `-75.812`
 

---
### [Opgave G](src/opgave-g.c)
Dette er opgave 8 på side 539 i afslutningen af kapitel 8 i Problem Solving and Program Design in C, eighth edition.
Du kan skrive dit program i filen [`opgave-g.c`](src/opgave-g.c).

> Write a C program that displays the total number of vowels and consonants in the sentence (string) given as input by the user.
> Check the program for the following input: 
> ```
> Welcome to C Programming
> ```
