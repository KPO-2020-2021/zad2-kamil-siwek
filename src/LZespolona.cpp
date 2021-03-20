#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
 
    if (abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false; 
  */
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik={0,0};
if(Skl2==0)
{
return Wynik;
}
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re-Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im+Skl1.im * Skl2.re;
  return Wynik;
}
/*!
 * Realizuje dzielenia dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielna,
 *    Skl2 - drugi skladnik dzielnik.
 * Zwraca:
 *    dzielenie dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
return Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
}

/*!
 * Realizuje sprzezenia
 * Argumenty:
 *    Skl - skladnik sprzezenia
 * Zwraca:
 *    liczbe zespolona po zmianie znaku przy czeci urojonej
 */
LZespolona Sprzezenie(LZespolona Skl)
{
 LZespolona  Wynik;

  Wynik.re = Skl.re;
  Wynik.im = -Skl.im;
  return Wynik;
}
/*!
 * Realizuje obliczenie modullu kwadrat z liczby zespolonej
 * Argumenty:
 *    Skl - skladnik sprzezenia
 * Zwraca:
 *    zwraca warosc rzeczwista bedaca kwadratem modolu
 */
double Modul2(LZespolona Skl)
{
return Skl.re * Skl.re+Skl.im * Skl.im;
}

void Wyswietl(LZespolona Skl)
{
  cout<<"("<<Skl.re<<showpos<<Skl.im<<noshowpos<<"i)";
}

void Wczytaj(LZespolona &Skl)
{
  char znak;
  cin>>znak>>Skl.re>>Skl.im>>znak>>znak;
}

ostream &operator <<(ostream &wyj, const LZespolona &Skl )
{
   wyj<<"("<<Skl.re<<showpos<<Skl.im<<noshowpos<<"i)";
   return wyj;
}
istream &operator >>(istream &wej,  LZespolona &Skl )
{
    char znak;
  wej>>znak;
  if(znak!='(')
  {
      wej.setstate(ios::failbit);
  }
  wej>>Skl.re;
  wej>>Skl.im;
   wej>>znak;
  if(znak!='i')
  {
      wej.setstate(ios::failbit);
  }
   wej>>znak;
  if(znak!=')')
  {
      wej.setstate(ios::failbit);
  }
  return wej;
}