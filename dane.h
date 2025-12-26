#ifndef DANE_H
#define DANE_H

typedef enum {
    BRAK_SPECJALIZACJI=0,
    MEDYK,
    INZYNIER,
    ZWIADOWCA,
    TECHNIK,
    BIOLOG,
    MECHANIK,
    STRATEG,
    WOJOWNIK,
    SZPIEG,
    NAUKOWIEC
} Specjalizacja;

typedef enum {
    AKTYWNY = 0,
    CHORY,
    RANNY,
    POZA_SCHRONEM,
    ZAGINIONY,
    MARTWY
} Status;

typedef struct Ocalaly {
    char imie[100];
    Specjalizacja rola;
    int ilosc_racji;
    int stan_zdrowia;
    int poziom_zagrozenia;
    Status stan;

    struct Ocalaly *next;
} Ocalaly;

#endif