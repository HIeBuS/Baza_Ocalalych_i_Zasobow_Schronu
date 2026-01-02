#ifndef LOGIKA_H
#define LOGIKA_H

#include "dane.h"

void wyszukaj_po_imieniu(Ocalaly* head, char* fragment);
void wyszukaj_po_specjalizacji(Ocalaly* head, Specjalizacja rola);
void wyszukaj_po_statusie(Ocalaly* head, Status stan);
Ocalaly* edytuj_ocalalego(Ocalaly* head, char* imie);
Ocalaly* usun_ocalalego(Ocalaly* head, char* imie, int* kod_wyniku);
void sortuj_alfabetycznie(Ocalaly* head);
void sortuj_po_zdrowiu(Ocalaly* head);

#endif