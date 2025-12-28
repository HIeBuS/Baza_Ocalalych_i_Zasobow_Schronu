#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "dane.h"
#include "lista.h"

void wyswietl_menu() {
    printf("----------------------------------------------\n");
    printf("        SYSTEM ZARZADZANIA SCHRONEM 17\n");
    printf("----------------------------------------------\n");
    printf("--- ZARZADZANIE BAZA ---\n");
    printf("1. Dodaj nowego ocalalego\n");
    printf("2. Edytuj dane ocalalego\n");
    printf("3. Usun ocalalego\n");
    printf("--- WYSZUKIWANIE I FILTROWANIE ---\n");
    printf("4. Wyswietl wszystkich ocalalych\n");
    printf("5. Wyszukaj ocalalego\n");
    printf("6. Sortuj liste\n");
    printf("--- PLIKI ---\n");
    printf("7. Zapisz stan schronu do pliku\n");
    printf("8. Wczytaj stan schronu z pliku\n");
    printf("--- SYSTEM ---\n");
    printf("0. Zakoncz program\n");
    printf("----------------------------------------------\n");
    printf("Twoj wybor: ");
}

Ocalaly* dodaj_ocalalego() {
    char imie[100];
    int specjalizacja, ilosc_racji, stan_zdrowia, poziom_zagrozenia, status;

    printf("\n--- DODAWANIE NOWEGO OCALALEGO ---\n");

    while (getchar() != '\n');

    printf("Podaj imie: ");
    if (fgets(imie, sizeof(imie), stdin)) {
        imie[strcspn(imie, "\n")] = 0;
    }

    printf("Wybierz specjalizacje (0-Brak, 1-Medyk, 2-Inzynier, 3-Zwiadowca, 4-Technik, 5-Biolog, 6-Mechanik, 7-Strateg, 8-Wojownik, 9-Szpieg, 10-Naukowiec): ");
    scanf("%d", &specjalizacja);

    printf("Ilosc racji: ");
    scanf("%d", &ilosc_racji);

    printf("Stan zdrowia (0-100): ");
    scanf("%d", &stan_zdrowia);

    printf("Poziom zagrozenia (0-10): ");
    scanf("%d", &poziom_zagrozenia);

    printf("Status (0-Aktywny, 1-Chory, 2-Ranny, 3-Poza schronem, 4-Zaginiony, 5-Martwy): ");
    scanf("%d", &status);

    return utworz_ocalalego(imie, (Specjalizacja)specjalizacja, ilosc_racji, stan_zdrowia, poziom_zagrozenia, (Status)status);
}

