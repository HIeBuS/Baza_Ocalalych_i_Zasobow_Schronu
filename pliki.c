#include <stdio.h>
#include <stdlib.h>
#include "pliki.h"
#include "lista.h"

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

Ocalaly* wczytaj_z_pliku(Ocalaly* head, char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "r");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku '%s'!\n", nazwa_pliku);
        return head;
    }

    char imie[100];
    int rola, racje, zdrowie, zagrozenie, stan;
    int licznik = 0;

    while (fscanf(plik, "%[^;];%d;%d;%d;%d;%d\n", 
                  imie, &rola, &racje, &zdrowie, &zagrozenie, &stan) == 6) {
        
        Ocalaly* nowy = utworz_ocalalego(imie, (Specjalizacja)rola, racje, zdrowie, zagrozenie, (Status)stan);
        
        head = dodaj_na_poczatek(head, nowy);
        licznik++;
    }

    fclose(plik);
    printf("Wczytano %d osob z pliku '%s'.\n", licznik, nazwa_pliku);
    
    return head;
}