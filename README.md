### Programos versijos:
1. **v.pradine** Pradine versija. Duomenu ivedimas ranka, surusiuota isvestis ekrane.
2. **v0.1** Studentu ir pazymiu generavimas, pasirinktinai vietoje vektoriaus masyvo naudojimas.
3. **v0.2** Failo skaitymas, isvestis i faila, rusiavimas pagal user parinkti.
4. **v0.3** Pritaikoma geresne programavimo praktika, naudojamas exception handling.
5. **v0.4** Studentu skirstymas i pogrupius, failo generavimas.
6. **v1.0** Galutine versija. Sukurtas Makefile, kelios versijos su skirtingais konteineriais, optimizacija.

### Naudojimo instrukcija:
Viskas vykdoma terminale.
**Failu kurimas** make all
**Failu paleidimas** ieiname i failu direktorija: "cd bin"
vektoriai - "./vector_program"
list - "./list_program"
deque - "./deque.program"
**Valymas** (istrina sugeneruotus failus) "cd .." grizti i pradine direktorija
"make clean" isvalyti

Naudojimo pavyzdziai
![](images/1.png)
![](images/2.png)
![](images/3.png)

### Spartos Analize (vector)

1. **1k**: file create - 0.035 s, file read - 0.007 s, file sort - 0 s, file distribution - 0 s, print - 0.011 s, total - 0.054 s
file distribution(2) - 0.028 s
file distribution(3) - 0 s
2. **10k**: file create - 0.219 s, file read - 0.095 s, file sort - 0.017 s, file distribution - 0.004 s, print - 0.077 s, total - 0.412 s
file distribution(2) - 0.076 s
file distribution(3) - 0.001 s
3. **100k**: file create - 1.798 s, file read - 0.687 s, file sort - 0.138 s, file distribution - 0.021 s, print - 0.771 s, total - 3.415 s
file distribution(2) - 180.122 s
file distribution(3) - 0.012 s
4. **1m**: file create - 16.223 s, file read - 5.462 s, file sort - 1.597 s, file distribution - 0.220 s,, print - 7.575 s, total - 31.077 s
file distribution(2) - too long...
file distribution(3) - 0.101
5. **10m**: file create - 167.577 s, file read - crash
file distribution(2) - ...
file distribution(3) - ...

### Spartos Analize (list)

1. **1k**: file read - 0.012 s, file sort - 0 s, file distribution - 0 s, print - 0.026 s, total - 0.039 s
file distribution(2) - 0 s
file distribution(3) - 0 s
2. **10k**: file read - 0.120 s, file sort - 0.013 s, file distribution - 0.006 s, print - 0.107 s, total - 0.247 s
file distribution(2) - 0 s
file distribution(3) - 0.001 s
3. **100k**: file read - 0.896 s, file sort - 0.114 s, file distribution - 0.025 s, print - 0.923 s, total - 1.957 s
file distribution(2) - 0.024 s
file distribution(3) - 0.015 s
4. **1m**: file read - 6.827 s, file sort - 1.373 s, file distribution - 0.240 s, print - 9.042 s, total - 17.482 s
file distribution(2) -  0.284 s
file distribution(3) - 0.124 s
5. **10m**: file read - 85.4399 s, file sort - 19.862 s, file distribution - crash
file distribution(2) -  ...
file distribution(3) - ...

### Spartos Analize (deque)

1. **1k**: file read - 0.011 s, file sort - 0 s, file distribution - 0.002 s, print - 0.029 s, total - 0.042 s
file distribution(2) - 0 s
file distribution(3) - 0 s
2. **10k**: file read - 0.122 s, file sort - 0.014 s, file distribution - 0.008 s, print - 0.097 s, total - 0.241 s
file distribution(2) - 0 s
file distribution(3) - 0.003
3. **100k**: file read - 0.872 s, file sort - 0.155 s, file distribution - 0.029 s, print - 0.919 s, total - 1.975 s
file distribution(2) -  0.025 s
file distribution(3) - 0.012 s
4. **1m**: file read - 6.814 s, file sort - 2.071 s, file distribution - 0.276 s, print - 9.293 s, total - 18.454 s
file distribution(2) - 0.243 s
file distribution(3) - 0.116 s
5. **10m**: file read - 82.723 s, file sort - 29.637 s, file distribution - crash
file distribution(2) - ...
file distribution(3) - ...

## Sistemos Parametrai
**CPU** i7-13650HX
**RAM** 24GB 4800MHz
**Storage** NVMe M.2 SSD 1TB

Matoma, kad 2 strategija visur veike leciausiai (ypac pasizymejo su vektoriais). Naudojamas atminties kiekis priklausant nuo konteineriu ir strategijos kito labai minimaliai. Todel, sprednziant tik pagal programos veikimo greiti, galima teigti, kad vektoriaus konteineris ir 3 strategija yra sparciausi.
![](images/3.png)



Kilus klausimams ar pastaboms, susisiekti el. paštu: nojus.petrusis@mif.stud.vu.lt