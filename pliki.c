#include <stdio.h>
#include <stdlib.h>
#include "pliki.h"

void zapisz_do_pliku(Ocalaly* head, char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "w");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku do zapisu!\n");
        return;
    }

    Ocalaly* obecny = head;

    while (obecny != NULL) {
        fprintf(plik, "%s;%d;%d;%d;%d;%d\n",
                obecny->imie,
                obecny->rola,
                obecny->ilosc_racji,
                obecny->stan_zdrowia,
                obecny->poziom_zagrozenia,
                obecny->stan);

        obecny = obecny->next;
    }

    fclose(plik);
    printf("Dane zostaly zapisane do pliku: %s\n", nazwa_pliku);
}