#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re =0.00009;
    x.im = 0.00009;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0;
    z.im = 0;
    
    CHECK(x+y == z);
}
//
/////////////////////////////////////////////////////
TEST_CASE("test LZespolona odejmowanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona odejmowanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1;
    z.im = 1;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona odejmowanie"){
    LZespolona x, y, z;

    x.re =0.49999;
    x.im = 0.49999;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.5;
    z.im = 0.5;
    
    CHECK(x-y == z);
}
////////////////////////////////////////////////////
TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 1;
    
    
    CHECK(x*y == z);
}


TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 2;
    
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0;
    z.im = 0;
    
    
    CHECK(x*y == z);
}


///////////////////////


TEST_CASE("test LZespolona modul"){
    LZespolona x;
    double s=2;
    x.re = 1;
    x.im = 1;

    
    
    CHECK( Modul2(x) == s);
}

TEST_CASE("test LZespolona sprzezenie"){
    LZespolona x, y;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -1;

    
    
    
    CHECK(Sprzezenie(x) == y);
}