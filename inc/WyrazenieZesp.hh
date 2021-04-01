#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  void Wyswietl();
  LZespolona Oblicz();
  void Wczytaj();
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


istream &operator >>(istream &wej,  WyrazenieZesp &WyrZ );
ostream &operator <<(ostream &wyj, const WyrazenieZesp &WyrZ );

#endif
