#include <iostream>
#include <string>
#include "film.h"
#include "kolejka.h"
using namespace std;

/*Funkcja nie zwracajaca nic, dodajaca wezel do kolejki*/
void Kolejka::dodaj(string tytul, int ocena)
{
    /*Aby dodac nowy wezel do kolejki trzeba sprawdzic czy jest ona pusta*/
    if (czyPusta())
    {
        Wezel *nowyfilm = new Wezel(tytul, ocena, NULL); /*Dodanie nowego wezla*/
        poczatek = nowyfilm;                             /*Przesuniecie wskaznika poczatkowego na nowy wezel*/
        koniec = nowyfilm;                               /*Przesuniecie wskaznika koncowego na nowy wezel*/
    }
    else
    {
        Wezel *nowyfilm = new Wezel(tytul, ocena, NULL); /*Dodanie nowego wezla*/
        koniec->nastepny = nowyfilm;                     /*Ustawienie wkaznika pomiedzy nowym a ostatnim wezlem*/
        koniec = nowyfilm;                               /*Przesuniecie wskaznika koncowego na nowy wezel*/
    }
    iloscCalkowita++; /*Dodanie calkowitej ilosci wezlow*/
    iloscAktualna++;  /*Dodanie aktualnej ilosci wezlow*/
}

/*Funkcja usuwajaca wezel z kolejki */
void Kolejka::usunPierwsza()
{
    if (czyPusta() == 0) /*Sprawdzenie czy jest pusta*/
    {
        Wezel *pomocniczy = new Wezel;   /* Stworzenie nowego wezla aby mozna bylo skopiować element kolejki*/
        pomocniczy = poczatek;           /*Skopiowanie wartosci poczatku do obiektu pomocniczego*/
        delete poczatek;                 /*Usuniecie pierwszego wezla */
        poczatek = pomocniczy->nastepny; /*Przypisanie nastepnego wezla jako pierwszy*/
        iloscAktualna--;                 /*Zmniejszenie aktualnej ilosci wezlow w kolejce*/
    }
    else
    {
        std::cout << "Kolejka jest pusta" << std::endl; /*Jezli kolejka jest pusta funkcja informuje o tym */
    }
}

/*Funkcja sprawdzajaca czy kolejka jest pusta*/
bool Kolejka::czyPusta()
{
    if (iloscAktualna == 0) /*Sprawdzenie czy cos jest w kolejce za pomoca  klasy*/
    {
        return 1; /* Jezeli nie ma funkcja zwraca 1*/
    }
    else
    {
        return 0; /*Jezeli jest funkcja zwraca 0*/
    }
}
