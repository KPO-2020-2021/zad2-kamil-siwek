#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct Statystyki
{
    int poprawne;
    int wszystke;
    double pr_dobrze;
    double pr_zle;
};

void wypisz(Statystyki stat);
void Oblicz(Statystyki &stat);
#endif
