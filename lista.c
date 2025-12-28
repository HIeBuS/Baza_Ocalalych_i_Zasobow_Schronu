#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Ocalaly* utworz_ocalalego(const char* imie, Specjalizacja rola, int ilosc_racji, int stan_zdrowia, int poziom_zagrozenia, Status stan) {
    
    Ocalaly* nowy = (Ocalaly*) malloc(sizeof(Ocalaly));

    if (nowy == NULL) {
        fprintf(stderr, "Nie udalo sie przydzielic pamięci dla nowego ocalalego!\n");
        return NULL;
    }

    strncpy(nowy->imie, imie, 99);
    nowy->imie[99] = '\0'; 

    nowy->rola = rola;
    nowy->ilosc_racji = ilosc_racji;
    nowy->stan_zdrowia = stan_zdrowia;
    nowy->poziom_zagrozenia = poziom_zagrozenia;
    nowy->stan = stan; 

    nowy->next = NULL;

    return nowy; 
}

Ocalaly* dodaj_na_poczatek(Ocalaly* head, Ocalaly* nowy) {
    if (nowy == NULL) {
        return head; 
    }

    nowy->next = head;

    return nowy; 
}

const char* nazwy_specjalizacji[] = { "Brak specjalizacji", "Medyk", "Inzynier", "Zwiadowca", "Technik", "Biolog", "Mechanik", "Strateg", "Wojownik", "Szpieg", "Naukowiec" };
const char* nazwy_statusu[] = { "Aktywny", "Chory", "Ranny", "Poza schronem", "Zaginiony", "Martwy" };

void wypisz_pojedynczego(Ocalaly* o) {
    if (o == NULL) return;
    printf("Imie: %-20s | Specjalizacja: %-12s | Ilosc racji: %3d | Stan zdrowia: %3d | Zagrozenie: %2d | Status: %s\n",
           o->imie,
           nazwy_specjalizacji[o->rola],
           o->ilosc_racji,
           o->stan_zdrowia,
           o->poziom_zagrozenia,
           nazwy_statusu[o->stan]);
}

void wypisz_liste(Ocalaly* head) {
    if (head == NULL) {
        printf("Lista ocalalych jest pusta!\n");
        return;
    }

    Ocalaly* obecny = head;
    printf("\n--- LISTA OCALALYCH ---\n");
    while (obecny != NULL) {
        wypisz_pojedynczego(obecny);
        obecny = obecny->next;
    }
    printf("-----------------------\n");
}