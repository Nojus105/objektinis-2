# Programos versijos

### Versijos istorija:
1. **v.pradine** - Pradinė versija. Duomenų įvedimas ranka, surūšiuota išvestis ekrane.
2. **v0.1** - Studentų ir pažymių generavimas, galimybė pasirinkti tarp vektoriaus ir masyvo naudojimo.
3. **v0.2** - Failo skaitymas, išvestis į failą, rūšiavimas pagal naudotojo pasirinkimą.
4. **v0.3** - Geresnė programavimo praktika, pridėtas klaidų apdorojimas (exception handling).
5. **v0.4** - Studentų skirstymas į pogrupius, failų generavimas.
6. **v1.0** - Galutinė versija. Sukurtas Makefile, kelios versijos su skirtingais konteineriais, optimizacija.

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
| **1m** | 16.223 s | 3.508 s | 1.597 s | 0.220 s | 7.575 s | 29.123 s | >5 min | 0.101 s |
| **10m** | 167.577 s | 12.626 | 2.577 | 0.395 | 12.886 | 196.061 | >5 min | 0.186 |

### **List**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas | Spausdinimas | Iš viso | Paskirstymas (2) | Paskirstymas (3) |
|------------------|--------------|------------|-------------|------------|---------|-----------------|-----------------|
| **1k** | 0.012 s | 0 s | 0 s | 0.026 s | 0.039 s | 0 s | 0 s |
| **10k** | 0.117 s | 0.013 s | 0.006 s | 0.107 s | 0.244 s | 0 s | 0.001 s |
| **100k** | 0.422 s | 0.114 s | 0.025 s | 0.923 s | 1.483 s | 0.024 s | 0.015 s |
| **1m** | 3.482 s | 1.373 s | 0.240 s | 9.042 s | 14.137 s | 0.284 s | 0.124 s |
| **10m** | 12.916 s | 2.302 s | 0.400 | 13.862 | 29.481 | 0.410 | 0.243 |

### **Deque**
| Studentų skaičius | Failo skaitymas | Rūšiavimas | Paskirstymas | Spausdinimas | Iš viso | Paskirstymas (2) | Paskirstymas (3) |
|------------------|--------------|------------|-------------|------------|---------|-----------------|-----------------|
| **1k** | 0.015 s | 0 s | 0.002 s | 0.029 s | 0.046 s | 0 s | 0 s |
| **10k** | 0.108 s | 0.014 s | 0.008 s | 0.097 s | 0.227 s | 0 s | 0.003 s |
| **100k** | 0.407 s | 0.155 s | 0.029 s | 0.919 s | 1.510 s | 0.025 s | 0.012 s |
| **1m** | 3.438 s | 2.071 s | 0.276 s | 9.293 s | 15.078 s | 0.243 s | 0.116 s |
| **10m** | 12.666 s | 3.609 s | 0.454 | 14.111 | 30.840 | 0.309 | 0.201 |

---

## Sistemos parametrai
- **CPU:** i7-13650HX
- **RAM:** 24GB 4800MHz
- **Storage:** NVMe M.2 SSD 1TB

### Išvados
Matoma, kad **strategija Nr. 2** veikė lėčiausiai (ypač su vektoriais). Naudojamos atminties kiekis kito minimaliai, todėl spartos atžvilgiu **vektoriaus konteineris su strategija Nr. 3** yra sparčiausias pasirinkimas.

![](https://github.com/user-attachments/assets/a45d0f40-fdef-4fcb-845b-b67f36220885)

---

Kilus klausimams ar pastaboms, susisiekite el. paštu: **nojus.petrusis@mif.stud.vu.lt**

