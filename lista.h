#ifndef LISTA_H
#define LISTA_H

#include "dane.h"

Ocalaly* utworz_ocalalego(const char* imie, Specjalizacja rola, int ilosc_racji, int stan_zdrowia, int poziom_zagrozenia, Status stan);
Ocalaly* dodaj_na_poczatek(Ocalaly* head, Ocalaly* nowy);

void wypisz_pojedynczego(Ocalaly* o);
void wypisz_liste(Ocalaly* head);

#endif