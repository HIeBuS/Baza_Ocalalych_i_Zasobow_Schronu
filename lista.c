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

void wypisz_liste(Ocalaly* head) {
    if (head == NULL) {
        printf("Lista ocalałych jest pusta!\n");
        return;
    }

    Ocalaly* obecny = head;

    printf("\n--- LISTA OCALAŁYCH ---\n");

    while (obecny != NULL) {
        printf("Imie: %s | Specjalizacja: %d | Ilosc racji: %d | Stan zdrowia: %d | Poziom zagrozenia: %d | Status: %d\n", obecny->imie, obecny->rola, obecny->ilosc_racji, obecny->stan_zdrowia, obecny->poziom_zagrozenia, obecny->stan);
        obecny = obecny->next;
    }
    printf("-----------------------\n");
}