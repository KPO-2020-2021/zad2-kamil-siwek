#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct Statystyki
{
    int poprawne;
    int wszystke;
};

void wypisz(Statystyki stat);

#endif
