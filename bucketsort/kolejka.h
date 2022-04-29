#ifndef KOLEJKA_H_
#define KOLEJKA_H_
#include <iostream>
#include <string>
#include "film.h"
using namespace std;

class Wezel
{

public:
    Wezel() = default; /* Domyslny konstruktor*/
    Wezel(string nowyfilm, int ocenaFilmu, Wezel *poprzednifilm)
        : tytul(nowyfilm), nastepny(poprzednifilm), ocena(ocenaFilmu) {} /*Kostruktor  z lista inicjalizujaca*/
    string tytul;                                                        /*Pole klasy  ktore zawiera tytul filmu */
    int ocena;                                                           /*Pole klasy  ktore zawiera ocene filmu */
    Wezel *nastepny = NULL;                                              /*Wzkaznik na kolejy wezel */
    string zwrocTytul() { return this->tytul; };                         /*Funkcja zwracajaca tytul filmu */
    int zwrocOcena() { return this->ocena; };                            /*Funkcja zwracajaca ocene filmu */
};

/*Klasa Kolejka zawierajaca w sobie wezly*/
class Kolejka
{
public:
    Wezel *poczatek = NULL; /*Wskaznik wskazajacy na aktualni pierwszy wezel*/
    Wezel *koniec = NULL;   /*Wskaznik wskazujacy na aktualni wezel*/
    int iloscCalkowita = 0; /*Pole przedstawiajace ile jest wezlow*/
    int iloscAktualna = 0;  /*Pole przestawiajace aktualna ilosc wezlow*/

    void dodaj(string tytul, int ocena);    /*Funkcja nie zwracajaca nic, dodajaca wezel do kolejki*/
    void usunPierwsza();                    /*Funkcja usuwajaca wezel z kolejki */
    bool czyPusta();                        /*Funkcja sprawdzajaca czy kolejceka jest pusta*/
    int rozmiar() { return iloscAktualna; } /*Funkcja zwracajaca aktualna ilosc wezlow w kolejce*/
};
#endif