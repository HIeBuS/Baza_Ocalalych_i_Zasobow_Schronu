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