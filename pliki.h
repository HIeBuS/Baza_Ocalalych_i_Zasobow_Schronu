#ifndef PLIKI_H
#define PLIKI_H

#include "dane.h"
#include <stdio.h>

void zapisz_do_pliku(Ocalaly* head, char* nazwa_pliku);
Ocalaly* wczytaj_z_pliku(Ocalaly* head, char* nazwa_pliku);

#endif