#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Wyswietl(WyrazenieZesp  WyrZ)
{
    Wyswietl(WyrZ.Arg1);
    switch (WyrZ.Op)
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
    Wyswietl(WyrZ.Arg2);
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona wynik;
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
    wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;
        case Op_Mnoz:
         wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;
    
        case Op_Odejmij:
        wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
    
        case Op_Dziel:
         wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;
    
  
    }
    return wynik;
}

void Wczytaj(WyrazenieZesp &WyrZ)
{
    char znak;
        Wczytaj(WyrZ.Arg1);
        cin>>znak;
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
        break;
    }
    Wczytaj(WyrZ.Arg2);
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