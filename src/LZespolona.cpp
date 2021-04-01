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

 const bool   LZespolona::operator == (   LZespolona  Skl2)const{
 
    if (abs(  re - Skl2.re) <= MIN_DIFF && abs(  im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if ((  re == Skl2.re) && (  im == Skl2.im))
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
LZespolona  LZespolona::operator + (   LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re =   re + Skl2.re;
  Wynik.im =   im + Skl2.im;
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
LZespolona  LZespolona::operator / (   double  Skl2){
  LZespolona  Wynik={0,0};
if(Skl2==0)
{
throw "dzielnie przez zero";
}
  Wynik.re =   re / Skl2;
  Wynik.im =   im / Skl2;
  return Wynik;
}

LZespolona  LZespolona::operator - (   LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re =   re - Skl2.re;
  Wynik.im =   im - Skl2.im;
  return Wynik;
}
LZespolona  LZespolona::operator * (   LZespolona  Skl2)
{
LZespolona  Wynik;

  Wynik.re =   re * Skl2.re-  im * Skl2.im;
  Wynik.im =   re * Skl2.im+  im * Skl2.re;
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
LZespolona  LZespolona::operator / (   LZespolona  Skl2)
{
return *this*Skl2.Sprzezenie()/Skl2.Modul2();
}

/*!
 * Realizuje sprzezenia
 * Argumenty:
 *    Skl - skladnik sprzezenia
 * Zwraca:
 *    liczbe zespolona po zmianie znaku przy czeci urojonej
 */
LZespolona LZespolona::Sprzezenie()
{
 LZespolona  Wynik;

  Wynik.re = re;
  Wynik.im = -im;
  return Wynik;
}
/*!
 * Realizuje obliczenie modullu kwadrat z liczby zespolonej
 * Argumenty:
 *    Skl - skladnik sprzezenia
 * Zwraca:
 *    zwraca warosc rzeczwista bedaca kwadratem modolu
 */
double LZespolona::Modul2()
{
return re *re+im * im;
}

void LZespolona::Wyswietl()
{
  cout<<"("<<re<<showpos<<im<<noshowpos<<"i)";
}

void LZespolona::Wczytaj()
{
  char znak;
  cin>>znak>>re>>im>>znak>>znak;
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

double LZespolona::arg()
  {
      double wynik;
      if(re>0)
      {
          wynik=atan2(im,re) * 180 / M_PI;
      }
      else if (re<0)
      {
          wynik=atan2(im,re) + M_PI * 180 / M_PI;
      }
      else
      {
          throw " argument a jest zero wyjatek";
      }
      return wynik;

  }
LZespolona LZespolona::operator +=(LZespolona Lz1)
{
    *this=*this+Lz1;
    return *this;
}
LZespolona LZespolona::operator /=(LZespolona Lz1)
{
    *this=*this/Lz1;
    return *this;
}