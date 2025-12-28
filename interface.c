#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

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


