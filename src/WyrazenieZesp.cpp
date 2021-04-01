#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void WyrazenieZesp::Wyswietl()
{
    Arg1.Wyswietl();
    switch (Op)
    {
    case Op_Dodaj:
        cout<<"+";
        break;
        case Op_Mnoz:
        cout<<"*";
        break;
    
        case Op_Odejmij:
        cout<<"-";
        break;
    
        case Op_Dziel:
        cout<<"/";
        break;
    
    default:
        break;
    }
    Arg2.Wyswietl();
}

LZespolona WyrazenieZesp::Oblicz()
{
    LZespolona wynik;
    switch (Op)
    {
    case Op_Dodaj:
    wynik=  Arg1+  Arg2;
        break;
        case Op_Mnoz:
         wynik=  Arg1*  Arg2;
        break;
    
        case Op_Odejmij:
        wynik=  Arg1-  Arg2;
        break;
    
        case Op_Dziel:
         wynik=  Arg1/  Arg2;
        break;
    
  
    }
    return wynik;
}

void WyrazenieZesp::Wczytaj()
{
    char znak;
      Arg1.Wczytaj();
        cin>>znak;
    switch (znak)
    {
    case '+':
       Op=Op_Dodaj;
        break;
   case '-':
       Op=Op_Odejmij;
        break;
    
   case '*':
       Op=Op_Mnoz;
        break;
    
    case '/':
        Op=Op_Dziel;
        break;
    
    default:
        break;
    }
     Arg2.Wczytaj();
}


istream &operator >>(istream &wej,  WyrazenieZesp &WyrZ )
{
    char znak;
     wej>>WyrZ.Arg1;
        wej>>znak;
    switch (znak)
    {
    case '+':
       WyrZ.Op=Op_Dodaj;
        break;
   case '-':
       WyrZ.Op=Op_Odejmij;
        break;
    
   case '*':
       WyrZ.Op=Op_Mnoz;
        break;
    
    case '/':
        WyrZ.Op=Op_Dziel;
        break;
    
    default:
    wej.setstate(ios::failbit);
        break;
    }
      wej>>WyrZ.Arg2;
      return wej;
}

ostream &operator <<(ostream &wyj, const WyrazenieZesp &WyrZ )
{
        wyj<<(WyrZ.Arg1);
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        wyj<<"+";
        break;
        case Op_Mnoz:
        wyj<<"*";
        break;
    
        case Op_Odejmij:
        wyj<<"-";
        break;
    
        case Op_Dziel:
        wyj<<"/";
        break;
    
    default:
        break;
    }
    wyj<<(WyrZ.Arg2);
    return wyj;
}