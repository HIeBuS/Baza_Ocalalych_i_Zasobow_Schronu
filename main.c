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

    Ocalaly* o1 = utworz_ocalalego("Thomas", ZWIADOWCA, 5, 95, 8, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o1);

    Ocalaly* o2 = utworz_ocalalego("Newt", STRATEG, 4, 80, 3, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o2);

    Ocalaly* o3 = utworz_ocalalego("Minho", ZWIADOWCA, 6, 100, 5, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o3);

    Ocalaly* o4 = utworz_ocalalego("Gally", INZYNIER, 5, 95, 9, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o4);

    Ocalaly* o5 = utworz_ocalalego("Teresa Agnes", MEDYK, 3, 90, 6, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o5);

    int wybor = -1;

    while (wybor != 0) {
        wyswietl_menu();
        
        if (scanf("%d", &wybor) != 1) {
            printf("\nTo nie jest liczba! Sprobuj ponownie!\n");
            while(getchar() != '\n');
            continue;
        }

        switch (wybor) {
            case 1: {
                Ocalaly* nowy = dodaj_ocalalego();
                if (nowy != NULL) {
                    lista = dodaj_na_poczatek(lista, nowy);
                    printf("Nowy ocalaly zostal dodany do systemu!\n");
                }
                break;
            }

            case 2: {
                char bufor[100];
                printf("\n--- EDYCJA DANYCH ---\n");
                printf("Podaj imie (i nazwisko) osoby do edycji: ");
                
                while(getchar() != '\n');
                if (fgets(bufor, sizeof(bufor), stdin)) {
                    bufor[strcspn(bufor, "\n")] = 0;
                }

                Ocalaly* cel = edytuj_ocalalego(lista, bufor);

                if (cel == NULL) {
                    printf("Nie znaleziono osoby: %s\n", bufor);
                } else {
                    printf("\nZnaleziono (przed zmiana):\n");
                    wypisz_pojedynczego(cel); 

                    printf("\nCo chcesz zmienic?\n");
                    printf("1. Specjalizacja\n");
                    printf("2. Ilosc racji\n");
                    printf("3. Stan zdrowia\n");
                    printf("4. Poziom zagrozenia\n");
                    printf("5. Status\n");
                    printf("0. Anuluj\n");
                    printf("Wybor: ");

                    int wybor_pola;
                    scanf("%d", &wybor_pola);

                    switch (wybor_pola) {
                        case 1:
                            printf("Nowa specjalizacja (0-Brak, 1-Medyk, 2-Inzynier, 3-Zwiadowca, 4-Technik, 5-Biolog, 6-Mechanik, 7-Strateg, 8-Wojownik, 9-Szpieg, 10-Naukowiec): ");
                            scanf("%d", (int*)&cel->rola);
                            break;
                        case 2:
                            printf("Nowa ilosc racji: ");
                            scanf("%d", &cel->ilosc_racji);
                            break;
                        case 3:
                            printf("Nowy stan zdrowia (0-100): ");
                            scanf("%d", &cel->stan_zdrowia);
                            break;
                        case 4:
                            printf("Nowy poziom zagrozenia (0-10): ");
                            scanf("%d", &cel->poziom_zagrozenia);
                            break;
                        case 5:
                            printf("Nowy status (0-Aktywny, 1-Chory, 2-Ranny, 3-Poza schronem, 4-Zaginiony, 5-Martwy): ");
                            scanf("%d", (int*)&cel->stan);
                            break;
                        case 0:
                            printf("Anulowano!\n");
                            break;
                        default:
                            printf("Bledny wybor!\n");
                    }
                    
                    if (wybor_pola != 0) {
                        printf("Zmieniono dane! Aktualny stan:\n");
                        wypisz_pojedynczego(cel);
                    }
                }
                break;
            }

            case 3: {
                char bufor[100];
                int rezultat = 0;

                printf("\n--- USUWANIE OCALALEGO ---\n");
                printf("Podaj imie (i nazwisko) osoby do usuniecia: ");
                
                while(getchar() != '\n');
                if (fgets(bufor, sizeof(bufor), stdin)) {
                    bufor[strcspn(bufor, "\n")] = 0;
                }

                lista = usun_ocalalego(lista, bufor, &rezultat);

                if (rezultat == 0) {
                    printf("\nOcalaly '%s' zostal usuniety z systemu!\n", bufor);
                } 
                else if (rezultat == 1) {
                    printf("\nNie znaleziono osoby o imieniu: '%s'\n", bufor);
                } 
                else if (rezultat == 2) {
                    printf("\nNie mozna usunac osoby o statusie 'Poza schronem'!\n");
                    printf("Musisz najpierw zmienic jej status (Edycja), aby ja usunac!\n");
                }
                break;
            }

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

            case 7: {
                char nazwa_pliku[50];
                printf("\n--- ZAPIS DO PLIKU ---\n");
                printf("Podaj nazwe pliku: ");
                
                while(getchar() != '\n'); 
                scanf("%s", nazwa_pliku);

                zapisz_do_pliku(lista, nazwa_pliku);
                break;
            }

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