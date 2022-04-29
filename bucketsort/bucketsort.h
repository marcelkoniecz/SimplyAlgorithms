#include <iostream>
#include <string>
#include "kolejka.h"
#include "film.h"

/*Funkcja przypisujaca odpowiedni film do kubla*/
void Kubelkowe(Film tabfilm[], Kolejka tablista[], int ostatni)
{
    int pomocnicza; /*Liczba pomocnicza okreslajaca do ktorego kubla trafi film*/

    /*Petla okreslajaca kubel kazdego filmu*/
    for (int i = 0; i <= ostatni; i++)
    {
        pomocnicza = tabfilm[i].ocena;
        tablista[pomocnicza].dodaj(tabfilm[i].nazwa, tabfilm[i].ocena);
    }
}