#include <stdio.h>

#include "dane.h"
#include "lista.h"
#include "interface.h"
#include "logika.h"
#include "pliki.h"

int main() {
    printf("--- SYSTEM ZARZADZANIA SCHRONEM 17 ---\n");

    Ocalaly* lista = NULL;

    Ocalaly* o1 = utworz_ocalalego("Jan Kowalski", MEDYK, 5, 100, 0, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o1);

    Ocalaly* o2 = utworz_ocalalego("Jan Nowak", INZYNIER, 10, 90, 2, AKTYWNY);
    lista = dodaj_na_poczatek(lista, o2);

    wypisz_liste(lista);

    return 0;
}