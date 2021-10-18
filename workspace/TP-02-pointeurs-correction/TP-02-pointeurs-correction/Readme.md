# Correction du TP2

## Compilation manuelle

Exemples :

```shell
clang -Wall -W -stc=c99 -o 01-echangeContenu 01-echangeContenu.c
clang -Wall -W -stc=c99 -o 02-02-convexe-main 02-convexe-main.c 02-convexe.c
```

## Compilation automatique avec CMake

```shell
$ unzip TP-02-pointeurs-correction.zip
$ cd TP-02-pointeurs-correction
$ ls
01-echangeContenu.c  02-convexe.h       03-matrices.c  03-matrices-main.c  04-dates.h       04-dates.txt  CMakeLists.txt
02-convexe.c         02-convexe-main.c  03-matrices.h  04-dates.c          04-dates-main.c  build/        Readme.md
$ mkdir build
$ cd build
$ cmake .. # .. est le chemin vers le répertoire contenant le fichier CMakeLists.txt
$ make
```
Pour une introduction à CMake, cf. Slides **Slides-03-Outils**

## Exécution

```shell
./02-convexe-main

# exemple avec redirection d'entrée pour que les scanf prennent les infos depuis un fichier txt
./04-dates-main < ../04-dates.txt
```
