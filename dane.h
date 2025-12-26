#ifndef DANE_H
#define DANE_H

typedef enum {
    BRAK_SPECJALIZACJI=0,
    MEDYK,
    INŻYNIER,
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
    char imie[50];
    Specjalizacja rola;
    int ilosc_racji;
    int stan_zdrowia;
    int poziom_zagrozenia;
    Status stan;

    struct Ocalaly *next;
} Ocalaly;

#endif