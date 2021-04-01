#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
using namespace std;

#define _USE_MATH_DEFINES
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  const bool  operator == (   LZespolona  Skl2) const;
LZespolona  operator - (   LZespolona  Skl2);
LZespolona  operator * (   LZespolona  Skl2);
LZespolona  operator / (   LZespolona  Skl2);
LZespolona  operator + (   LZespolona  Skl2);

double arg();
LZespolona operator +=(LZespolona Lz1);
LZespolona operator /=(LZespolona Lz1);

LZespolona operator / (double Skl2);
LZespolona Sprzezenie(); 
double Modul2();
void Wyswietl();
void Wczytaj();
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


ostream &operator <<(ostream &wyj, const LZespolona &Skl );
istream &operator >>(istream &wej,  LZespolona &Skl );
#endif
