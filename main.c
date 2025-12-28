#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dane.h"
#include "lista.h"
#include "interface.h"
#include "logika.h"
#include "pliki.h"

int main() {
    Ocalaly* lista = NULL;

    Ocalaly* o1 = utworz_ocalalego("Jan Kowalski", MEDYK, 5, 100, 0, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o1);

    Ocalaly* o2 = utworz_ocalalego("Jan Nowak", INZYNIER, 10, 90, 2, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o2);

    int wybor = -1;

    while (wybor != 0) {
        wyswietl_menu();
        
        if (scanf("%d", &wybor) != 1) {
            printf("\nTo nie jest liczba! Sprobuj ponownie!\n");
            while(getchar() != '\n');
            continue;
        }

        switch (wybor) {
            case 1:
                printf("\nDodawanie danych\n");
                break;

            case 2:
                printf("Edycja danych\n");
                break;

            case 3:
                printf("\nUsuwanie ocalalego\n");
                break;

            case 4:
                wypisz_liste(lista);
                break;

            case 5: {
                int wybor = 0;
                printf("\n--- WYSZUKIWANIE ---\n");
                printf("1. Szukaj po imieniu\n");
                printf("2. Szukaj po specjalizacji\n");
                printf("3. Szukaj po statusie\n");
                printf("Twoj wybor: ");
                
                if (scanf("%d", &wybor) != 1) {
                    printf("Blad! To nie liczba!\n");
                    while(getchar() != '\n');
                    break;
                }
                
                if (wybor == 1) {
                    char bufor[100];
                    printf("Podaj fragment imienia: ");
                    
                    while(getchar() != '\n'); 
                    fgets(bufor, sizeof(bufor), stdin);
                    bufor[strcspn(bufor, "\n")] = 0; 

                    wyszukaj_po_imieniu(lista, bufor);
                } 
                else if (wybor == 2) {
                    int rola_id;
                    printf("Podaj numer specjalizacji (0-Brak, 1-Medyk, 2-Inzynier, 3-Zwiadowca, 4-Technik, 5-Biolog, 6-Mechanik, 7-Strateg, 8-Wojownik, 9-Szpieg, 10-Naukowiec): ");
                    scanf("%d", &rola_id);
                    wyszukaj_po_specjalizacji(lista, (Specjalizacja)rola_id);
                } 
                else if (wybor == 3) {
                    int stan_id;
                    printf("Podaj numer statusu (0-Aktywny, 1-Chory, 2-Ranny, 3-Poza schronem, 4-Zaginiony, 5-Martwy): ");
                    scanf("%d", &stan_id);
                    wyszukaj_po_statusie(lista, (Status)stan_id);
                }
                else {
                    printf("Bledny wybor!\n");
                }
                break;
            }

            case 6: {
                int wybor = 0;
                printf("\n--- SORTOWANIE LISTY ---\n");
                printf("1. Alfabetycznie (A-Z)\n");
                printf("2. Wedlug zdrowia (od najslabszych)\n");
                printf("Twoj wybor: ");
                scanf("%d", &wybor);

                if (wybor == 1 || wybor == 2) {
                     printf("Wybrano sortowanie nr %d\n", wybor);
                } else {
                     printf("Niepoprawny wybor!\n");
                }
                break;
            }

            case 7:
                printf("\nZapis do pliku\n");
                break;

            case 8:
                printf("Odczyt z pliku\n");
                break;

            case 0:
                printf("\nZamykanie systemu Schron 17...\n");
                exit(0);
                break;

            default:
                printf("\nNieznana opcja menu: %d, wybierz liczbe od 0 do 8 \n", wybor);
        }
    }

    return 0;
}