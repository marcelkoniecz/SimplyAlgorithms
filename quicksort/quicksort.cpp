#include <string>
#include <iostream>
#include "film.h"
#include "quicksort.h"
using namespace std;
/*Funkcja rekurencyjna dzielaca sortujaca tablice*/
void Quicksort(Film tab[], int indeksPierwszy, int indeksOstatni)
{
    if (indeksPierwszy < indeksOstatni)
    {
        int i = Podzial(tab, indeksPierwszy, indeksOstatni); /*Podzial tablicy, wybor piwota oraz posortowanie*/
        Quicksort(tab, indeksPierwszy, i - 1);               /*Wywolanie rekurencyjne funkcji z elemenatmi mniejszymi niz piwot*/
        Quicksort(tab, i + 1, indeksOstatni);                /*Wywolanie rekurencyjne funkcji z elemenatmi wiekszymi niz piwot*/
    }
}

/*Funckja podzialu tablicy wyboru piwota oraz posortowania */
int Podzial(Film tab[], int indeksPierwszy, int indeksOstatni)
{
    int srodek = (indeksOstatni + indeksPierwszy) / 2; /*Wybor srodkowego indeksu*/
    int piwot = tab[srodek].ocena;                     /*Wybor piwota*/
    swap(tab[srodek], tab[indeksOstatni]);             /*Przesuniecie piwota na koniec*/
    int c = indeksOstatni;                             /*Element pomocniczy pomagajacy w operacjach na tablicach*/
    int i = indeksPierwszy;                            /*Element pomocniczy pomagajacy w operacjach na tablicach*/

    /*Podwojna petla segregujaca elementy */
    /*Szukamy elementu od pierwszego indeksu w prawo az znajdziemy wiekszy od piwota */
    /*Nastepnie w drugiej petli szukamy od indeksu ostatniego az znajdujemy mniejszy od piwota*/
    /*Po znaleznieniu tych elemnetow zamieniamy je miejscami*/
    for (i; i <= c; i++)
    {

        if (tab[i].ocena > piwot)
        {
            for (int k = c; k > i; k--)
            {
                if (tab[k].ocena < piwot)
                {
                    swap(tab[i], tab[k]);
                    c--;
                    break;
                }
                c--;
            }
        }
    }
    i--;
    /*Nastepnie sprawdzamy czy w miejscu przeciecia element jest mniejszy od piwota czy wiekszy*/
    /*Jezeli jest mniejszy to zamieniamy piwota z elementem nastepnym*/
    if (tab[i].ocena >= piwot)
    {
        swap(tab[i], tab[indeksOstatni]);
        return i; /*Zwracamy miejsce piwota*/
    }
    /*Jezeli jest wiekszy to zamieniamy piwota z elementem bierzacym*/
    if (tab[i].ocena <= piwot)
    {
        swap(tab[i + 1], tab[indeksOstatni]);
        return i + 1; /*Zwracamy miejsce piwota*/
    }
    return i;
}