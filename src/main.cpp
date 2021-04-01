#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
Statystyki stat={0,0};
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona wynik, obliczenie;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " wyrazenie do obliczenia"<<WyrZ_PytanieTestowe;
    for(int i=0; i<3; i++)
    {
      cout<<"twoja odpowiedz to: ";
      cin>>wynik;
      if(cin.good())
      {
        break;
      }
      cin.clear();
      cin.ignore(1024,'\n');

    }
    obliczenie=WyrZ_PytanieTestowe.Oblicz();
    if(obliczenie==wynik)
    {
      cout<<"dobrze"<<endl;
      stat.poprawne++;
    }
    else
    {
      cout<<"zle porawny wynik to :"<<obliczenie <<endl;
    }
    stat.wszystke++;
  }

  wypisz(stat);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
