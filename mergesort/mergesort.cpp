#include <string>
#include <iostream>
#include "mergesort.h"

/*Funkcja scalajaca w odpowiedniej kolejnosci*/
void Scalenie(Film tab[], int indeksPierwszy, int srodek, int indeksOstatni)
{
    int liczba= (indeksOstatni-indeksPierwszy+1);
    Film *pom;
    pom = new Film[liczba]; /*Utworzenie tablicy pomocniczej*/

    /*Zmienne potrzebne przy scalaniu oraz kopiowaniu*/
    int i = 0;
    int p = indeksPierwszy;
    int j = srodek + 1;
    int m = j - indeksPierwszy;

    /*Petla przepisujaca z tablicy bazy danych do tablicy pomocniczej*/
    for (int i = 0; i <= (indeksOstatni - indeksPierwszy); i++)
    {
        pom[i] = tab[p];
        p++;
    }

    /*Petla ktora scala tablice w wlasciwej kolejnosci(sortuje)*/
    for (int k = indeksPierwszy; k <= indeksOstatni; k++)
    {
        if (i <= (srodek - indeksPierwszy)) /*Sprawdzenie czy jest koniec tablicy pierwszej*/
        {
            if (m <= (indeksOstatni - indeksPierwszy)) /*Sprawdzenie czy jest juz koniec tablicy drugiej*/
            {
                if (pom[m].ocena < pom[i].ocena) /*Jezeli element pierwszej tablicy jest wiekszy od elementu z drugiej tablicy*/
                {
                    tab[k].ocena = pom[m].ocena; /*Zapisujemy pierwszy element do tablicy */
                    m++;
                }
                else
                {
                    tab[k].ocena = pom[i].ocena; /*Zapisujemy drugi element do tablicy */
                    i++;
                }
            }
            else
            {
                /*Przypisujemy elementy tablicy pierwszej do wlasciwej tablicy*/
                /*Tablica druga jest juz pusta*/
                tab[k].ocena = pom[i].ocena;
                i++;
            }
        }
        else
        {
            /*Przypisujemy elementy tablicy drugiej do wlasciwej tablicy*/
            /*Tablica pierwsza jest juz pusta*/
            tab[k].ocena = pom[m].ocena;
            m++;
        }
    }

    delete[] pom; /*Usuniecie tablicy pomocniczej*/
}

/*Rekurencyjna funkcja sortowania przez scalenie*/
void sortScalenie(Film tab[], int indeksPierwszy, int indeksOstatni)
{
    /*Jezeli indeksPierwszy jest mniejszy niż ostatni dzielimy 
    tablice na mniejsze czesci oraz na koncu  sortujemy i laczymy*/
    if (indeksPierwszy < indeksOstatni)
    {
        int srodek = (indeksPierwszy + indeksOstatni) / 2;    /*Wyznaczamy srodek aby podzielic tablice na 2 czesci*/
        sortScalenie(tab, indeksPierwszy, srodek);            /*Wywolanie rekurencyjne funkcji z polowa tablicy*/
        sortScalenie(tab, srodek + 1, indeksOstatni);         /*Wywolanie rekurencyjne funkcji z druga polowa tablicy*/
        Scalenie(tab, indeksPierwszy, srodek, indeksOstatni); /*Wywolanie funkcji ktora scali  oraz posortuje tablice*/
    }
}