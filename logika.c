#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logika.h"
#include "lista.h"

void wyszukaj_po_imieniu(Ocalaly* head, char* fragment) {
    printf("\n--- WYNIKI WYSZUKIWANIA (Imie zawiera: \"%s\") ---\n", fragment);
    Ocalaly* obecny = head;
    int znaleziono = 0;

    while (obecny != NULL) {
        if (strstr(obecny->imie, fragment) != NULL) {
            wypisz_pojedynczego(obecny);
            znaleziono = 1;
        }
        obecny = obecny->next;
    }

    if (!znaleziono) printf("Nie znaleziono osob o takim imieniu!\n");
    printf("----------------------------------------------------\n");
}

void wyszukaj_po_specjalizacji(Ocalaly* head, Specjalizacja rola) {
    printf("\n--- WYNIKI WYSZUKIWANIA (Specjalizacja) ---\n");
    Ocalaly* obecny = head;
    int znaleziono = 0;

    while (obecny != NULL) {
        if (obecny->rola == rola) {
            wypisz_pojedynczego(obecny);
            znaleziono = 1;
        }
        obecny = obecny->next;
    }

    if (!znaleziono) printf("Brak osob o tej specjalizacji!\n");
    printf("----------------------------------\n");
}

void wyszukaj_po_statusie(Ocalaly* head, Status stan) {
    printf("\n--- WYNIKI WYSZUKIWANIA (Status) ---\n");
    Ocalaly* obecny = head;
    int znaleziono = 0;

    while (obecny != NULL) {
        if (obecny->stan == stan) {
            wypisz_pojedynczego(obecny);
            znaleziono = 1;
        }
        obecny = obecny->next;
    }

    if (!znaleziono) printf("Brak osob o tym statusie!\n");
    printf("------------------------------------\n");
}

Ocalaly* edytuj_ocalalego(Ocalaly* head, char* szukane_imie) {
    Ocalaly* obecny = head;
    
    while (obecny != NULL) {
        if (strcmp(obecny->imie, szukane_imie) == 0) {
            return obecny;
        }
        obecny = obecny->next;
    }

    return NULL;
}

Ocalaly* usun_ocalalego(Ocalaly* head, char* imie, int* kod_wyniku) {
    Ocalaly *obecny = head;
    Ocalaly *poprzedni = NULL;

    while (obecny != NULL) {
        if (strcmp(obecny->imie, imie) == 0) {
            
            if (obecny->stan == POZA_SCHRONEM) {
                *kod_wyniku = 2;
                return head;
            }

            if (poprzedni == NULL) {
                head = obecny->next;
            } else {
                poprzedni->next = obecny->next;
            }

            free(obecny);
            *kod_wyniku = 0;
            return head;
        }

        poprzedni = obecny;
        obecny = obecny->next;
    }

    *kod_wyniku = 1;
    return head;
}

void zamien_dane(Ocalaly* a, Ocalaly* b) {
    char temp_imie[100];
    Specjalizacja temp_rola;
    int temp_racje, temp_zdrowie, temp_zagrozenie;
    Status temp_stan;

    strcpy(temp_imie, a->imie);
    temp_rola = a->rola;
    temp_racje = a->ilosc_racji;
    temp_zdrowie = a->stan_zdrowia;
    temp_zagrozenie = a->poziom_zagrozenia;
    temp_stan = a->stan;

    strcpy(a->imie, b->imie);
    a->rola = b->rola;
    a->ilosc_racji = b->ilosc_racji;
    a->stan_zdrowia = b->stan_zdrowia;
    a->poziom_zagrozenia = b->poziom_zagrozenia;
    a->stan = b->stan;

    strcpy(b->imie, temp_imie);
    b->rola = temp_rola;
    b->ilosc_racji = temp_racje;
    b->stan_zdrowia = temp_zdrowie;
    b->poziom_zagrozenia = temp_zagrozenie;
    b->stan = temp_stan;
}

void sortuj_alfabetycznie(Ocalaly* head) {
    if (head == NULL) return;

    int zamiana;
    Ocalaly* obecny;
    Ocalaly* ostatni = NULL;

    do {
        zamiana = 0;
        obecny = head;

        while (obecny->next != ostatni) {
            if (strcmp(obecny->imie, obecny->next->imie) > 0) {
                zamien_dane(obecny, obecny->next);
                zamiana = 1;
            }
            obecny = obecny->next;
        }
        ostatni = obecny;
    } while (zamiana);
    
    printf("\nLista zostala posortowana alfabetycznie!\n");
}

void sortuj_po_zdrowiu(Ocalaly* head) {
    if (head == NULL) return;

    int zamiana;
    Ocalaly* obecny;
    Ocalaly* ostatni = NULL;

    do {
        zamiana = 0;
        obecny = head;

        while (obecny->next != ostatni) {
            if (obecny->stan_zdrowia > obecny->next->stan_zdrowia) {
                zamien_dane(obecny, obecny->next);
                zamiana = 1;
            }
            obecny = obecny->next;
        }
        ostatni = obecny;
    } while (zamiana);

    printf("\nLista zostala posortowana wedlug zdrowia!\n");
}