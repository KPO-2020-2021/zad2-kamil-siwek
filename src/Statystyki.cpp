#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void wypisz(Statystyki stat)
{
    cout<<"dobre odpowiedzi " << stat.poprawne<< endl;
    cout<<"zle odpowiedzi "<< stat.wszystke - stat.poprawne<< endl;
    cout<<"wynik procentowy "<< stat.poprawne * 100.0 / stat.wszystke;

}

void Oblicz(Statystyki &stat)
{
stat.pr_dobrze=stat.poprawne*100.0/stat.wszystke;
stat.pr_zle=(stat.wszystke-stat.poprawne)*100.0/stat.wszystke;
}