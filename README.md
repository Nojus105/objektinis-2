# Programos versijos

### Versijos istorija:
1. **v.pradine** - Pradinė versija. Duomenų įvedimas ranka, surūšiuota išvestis ekrane.
2. **v0.1** - Studentų ir pažymių generavimas, galimybė pasirinkti tarp vektoriaus ir masyvo naudojimo.
3. **v0.2** - Failo skaitymas, išvestis į failą, rūšiavimas pagal naudotojo pasirinkimą.
4. **v0.3** - Geresnė programavimo praktika, pridėtas klaidų apdorojimas (exception handling).
5. **v0.4** - Studentų skirstymas į pogrupius, failų generavimas.
6. **v1.0** - Pilna versija. Sukurtas Makefile, kelios versijos su skirtingais konteineriais, optimizacija.
7. **v1.1** - Pertvarkyta struktūrą pakeičiant į klasę.

---

## Naudojimo instrukcija
**Viskas vykdoma terminale.**

### Failų generavimas:
```sh
make all
```

### Failų paleidimas:
Pereikite į vykdomųjų failų direktoriją:
```sh
cd bin
```
- **Vektoriai:** `./vector_program`
- **List:** `./list_program`
- **Deque:** `./deque_program`

### Sugeneruotų failų ištrynimas:
Grįžkite į pradinę direktoriją:
```sh
cd ..
```
Valymo komanda:
```sh
make clean
```

### Naudojimo pavyzdžiai:
![](https://github.com/user-attachments/assets/d2972b82-278a-4785-9a52-673036cec0cf)
![](https://github.com/user-attachments/assets/675f3a26-68f0-4576-af1d-6014f2ec60b9)
![](https://github.com/user-attachments/assets/5059e332-cc1d-4cbc-a4d8-47aef0c31453)

---

## Spartos analizė

### **Vector**
| Studentų skaičius | Failo kūrimas | Failo skaitymas | Rūšiavimas | Paskirstymas | Spausdinimas | Iš viso | Paskirstymas (2) | Paskirstymas (3) |
|------------------|--------------|--------------|------------|-------------|------------|---------|-----------------|-----------------|
| **1k** | 0.035 s | 0.015 s | 0 s | 0 s | 0.011 s | 0.061 s | 0.028 s | 0 s |
| **10k** | 0.219 s | 0.105 s | 0.017 s | 0.004 s | 0.077 s | 0.422 s | 0.076 s | 0.001 s |
| **100k** | 1.798 s | 0.392 s | 0.138 s | 0.021 s | 0.771 s | 3.120 s | 180.122 s | 0.012 s |
| **1m** | 16.223 s | 7.795 s | 0.996 s | 0.098 s | 9.040 s | 34.152 s | >5 min | 0.048 s |
| **10m** | 167.577 s | 87.541 | 12.792 | crash | 88.551 | 356.461 | crash | crash |

### **List**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas | Spausdinimas | Iš viso | Paskirstymas (2) | Paskirstymas (3) |
|------------------|--------------|------------|-------------|------------|---------|-----------------|-----------------|
| **1k** | 0.012 s | 0 s | 0 s | 0.026 s | 0.039 s | 0 s | 0 s |
| **10k** | 0.117 s | 0.013 s | 0.006 s | 0.107 s | 0.244 s | 0 s | 0.001 s |
| **100k** | 0.422 s | 0.114 s | 0.025 s | 0.923 s | 1.483 s | 0.024 s | 0.015 s |
| **1m** | 7.131 s | 0.579 s | 0.216 s | 9.120 s | 17.046 s | 0.182 s | 0.397 s |
| **10m** | 86.119 s | 10.844 s | crash | 89.815 s | 188.504 s | 1.726 s | 4.288 s |

### **Deque**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas | Spausdinimas | Iš viso | Paskirstymas (2) | Paskirstymas (3) |
|------------------|--------------|------------|-------------|------------|---------|-----------------|-----------------|
| **1k** | 0.015 s | 0 s | 0.002 s | 0.029 s | 0.046 s | 0 s | 0 s |
| **10k** | 0.108 s | 0.014 s | 0.008 s | 0.097 s | 0.227 s | 0 s | 0.003 s |
| **100k** | 0.407 s | 0.155 s | 0.029 s | 0.919 s | 1.510 s | 0.025 s | 0.012 s |
| **1m** | 7.214 s | 1.092 s | 0.102 s | 9.293 s | 17.701 s | 0.059 s | 0.059 s |
| **10m** | 85.353 s | 12.767 s | crash | 89.707 s | 188.283 s | 0.456 s | 0.470 s |

### **Deque naudojant klasę (be flag)**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas (3) | Spausdinimas | Iš viso |
|-------------------|-----------------|------------|-----------------|--------------|---------|
| **100k**          | 1.231 s          | 0.367 s    | 0.031 s         | 0.944 s      | 2.574 s |
| **1m**            | 9.717 s          | 4.968 s    | 0.251 s         | 9.448 s      | 24.384 s |

.exe failo dydis - 372 KB

---

### **Deque naudojant klasę (-O2)**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas (3) | Spausdinimas | Iš viso |
|-------------------|-----------------|------------|-----------------|--------------|---------|
| **100k**          | 0.954 s          | 0.100 s    | 0.007 s         | 0.892 s      | 1.954 s |
| **1m**            | 7.641 s          | 1.027 s    | 0.042 s         | 9.015 s      | 17.725 s |

.exe failo dydis - 195 KB

---

### **Deque naudojant klasę (-O3)**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas (3) | Spausdinimas | Iš viso |
|-------------------|-----------------|------------|-----------------|--------------|---------|
| **100k**          | 0.938 s          | 0.094 s    | 0.006 s         | 0.896 s      | 1.935 s |
| **1m**            | 7.488 s          | 1.040 s    | 0.045 s         | 8.895 s      | 17.468 s |

### **Deque naudojant struct (-03)**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas (3) | Spausdinimas | Iš viso |
|-------------------|-----------------|------------|-----------------|--------------|---------|
| **100k**          | 0.407 s          | 0.155 s    | 0.012 s         | 0.919 s      |  s |
| **1m**            | 7.214 s          | 1.092 s    | 0.059 s         | 8.895 s      |  s |

.exe failo dydis - 190 KB

---

## Sistemos parametrai
- **CPU:** i7-13650HX
- **RAM:** 24GB 4800MHz
- **Storage:** NVMe M.2 SSD 1TB

### Išvados
**Vektoriai** veikė prasčiausiai atminties atžvilgiu, crashino. **1 strategija** pasižymi prastu atminties išnaudojimu (su dideliais kiekiais taip pat sukėlė crash). **2 strategija** pasižymi didžiausiu spartumu (išskyrus su vektoriais). Naudojamos atminties kiekis tarp **deque ir list konteinerių** kito minimaliai, todėl spartos atžvilgiu **deque konteineris su strategija Nr. 2** yra geriausias pasirinkimas.

![](https://github.com/user-attachments/assets/a45d0f40-fdef-4fcb-845b-b67f36220885)

**Klasės konteineris** užtrunka šiek tiek ilgiau skaitymo funkcijoje, tačiau visas kitas funkcijas atlieka greičiau (skirtumas nėra didelis).

Naudojant -O2 ir -O3 **Optimizavimo flag'us** matomas didelis spartos skirtumas palyginus be flag'o. Skirtumas tarp -O2 ir -O3 yra minimalus, bet vistiek pastebime, kad -O3 veikia sparčiausiai. Su -O1 flag'u kilo problemų, yra errorų tarp naudojamos mingw32 versijos ir -O1 flag.

---

Kilus klausimams ar pastaboms, susisiekite el. paštu: **nojus.petrusis@mif.stud.vu.lt**

