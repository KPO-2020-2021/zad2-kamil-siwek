#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.666;
    y.im = 0.666;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.666;
    y.im = 0.666;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dodawanie,znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dodaj,{1,1}};
    LZespolona t ={2,2};
    
  
    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona odejmowanie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Odejmij,{1,1}};
    LZespolona t ={0,0};
    
  
    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona mnozenie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Mnoz,{1,1}};
    LZespolona t ={0,2};
    
  
    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona dzielenie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dziel,{1,1}};
    LZespolona t ={1,0};
    
  
    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona ststystyka") {
    Statystyki a={5,10,0,0};
    
  Oblicz(a);
    CHECK(a.pr_dobrze== 50);
    CHECK(a.pr_zle== 50);
}

TEST_CASE("LZespolona - dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("LZespolona - wyswietlanie standard") {
    LZespolona x;
   
    x.re = 2;
    x.im = 2;
    
    std::ostringstream out;
    
    out << setprecision(2)<<fixed<<x ;
    std::cout << out.str() << std::endl;
    CHECK( "(2.00+2.00i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane") {
    LZespolona x;
   
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;
    
    std::ostringstream out;
    
    out << setprecision(2)<<fixed<<x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.67+0.67i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie standard") {
    LZespolona x;
    
    std::istringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out <<setprecision(2)<<fixed<< x; // lub strcmp? ew. == dla LZesp
    
    CHECK( "(10.00+10.10i)" == out.str() );
}

TEST_CASE("WyrazenieZesp - wyswietlanie zaokraglane") {
    WyrazenieZesp x={{10,10},Op_Dodaj,{10,10}};
   
   
    
    std::ostringstream out;
    
    out << setprecision(2)<<fixed<<x;
    std::cout << out.str() << std::endl;
    CHECK( "(10.00+10.00i)+(10.00+10.00i)" == out.str() );
}

TEST_CASE("WyrazenieZesp - wczytywanie standard") {
    WyrazenieZesp x={{1,1},Op_Dodaj,{1,1}};
    
    std::istringstream in("(10+10.10i)+(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out <<setprecision(2)<<fixed<< x; // lub strcmp? ew. == dla LZesp
    
    CHECK( "(10.00+10.10i)+(10.00+10.10i)" == out.str() );
}