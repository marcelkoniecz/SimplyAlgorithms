#include "kolejka.h"
#include "film.h"
#include <sstream>
#include <string>
#include <fstream>

/*Funkcja rozdzielajaca ocene oraz tytul*/
bool rozdzielSlowa(string linia, Film &Nowy)
{
    string slowa;          /*Pomocniczy string*/
    stringstream s(linia); /*Stworzenie strumienia znakow*/
    if (linia[0] == '\"')  /*Sprawdzenie jaki jest pierwszy znak*/
    {
        /*Wczytywanie niepotrzebnych znakow */
        getline(s, slowa, ',');
        getline(s, slowa, '\"');
        getline(s, slowa, '\"');
        getline(s, slowa, '\"');
        Nowy.nazwa = slowa; /*Zapisanie tytulu*/
        /*Wczytywanie niepotrzebnych znakow */
        getline(s, slowa, '\"');
        getline(s, slowa, ',');
        getline(s, slowa, '\"');
        /*Sprawdzenie czy udalo sie zapisac ocene*/
        try
        {
            Nowy.ocena = stoi(slowa); /*Zapisanie oceny*/
            return true;              /*Zwrocenie true jako udane rozdzielnie */
        }
        catch (exception e)
        {
            return false; /*Zwrocenie false jako nieudane udane rozdzielnie */
        }
    }
    else
    {
        /*Wczytywanie niepotrzebnych znakow */
        getline(s, slowa, ',');
        getline(s, slowa, ',');

        Nowy.nazwa = slowa; /*Zapisanie tytulu*/
        /*Wczytywanie niepotrzebnych znakow */
        getline(s, slowa, ';');
        /*Sprawdzenie czy udalo sie zapisac ocene*/
        try
        {
            Nowy.ocena = stoi(slowa); /*Zapisanie oceny*/
            return true;              /*Zwrocenie true jako udane rozdzielnie */
        }
        catch (exception e)
        {
            return false; /*Zwrocenie false jako nieudane udane rozdzielnie */
        }
    }
}

/*Funkcja wczytujaca filmy*/
int Wczytaj(string nazwa, int ilosc, Film Baza[])
{
    fstream plikcsv;                /*Strumien wejscia do pliku*/
    plikcsv.open(nazwa);            /*Otwirzenie pliku*/
    string linia, slowa;            /*Stringi pomocnicze*/
    getline(plikcsv, linia);        /*Wczytanie pierwszej lini ktora jest niepotrzebna*/
    for (int i = 0; i < ilosc; i++) /*Petla wczytujaca linie dokumentu*/
    {
        getline(plikcsv, linia);               /*Pobranie lini*/
        while (!rozdzielSlowa(linia, Baza[i])) /*Sprawdzenie czy jest możliwy odczyt z tej lini*/
        {
            getline(plikcsv, linia);
            ilosc--; /*Jesli wczytanie sie nie udalo to zmiejszamy liczbe filmow w bazie*/
        }
    }
    return ilosc; /*Zwrocenie ilosci filmow w bazie*/
}

/*Funkcja zapisujaca baze z filmami w pliku*/
void Zapis(string nazwaDoZapisania, int ilosc, Film Baza[])
{
    ofstream zapis(nazwaDoZapisania); /*Strumien do zapisu*/
    for (int i = 0; i < ilosc; i++)   /*Petla odczytujaca baze i zapisujaca filmy w pliku*/
    {
        zapis << i << ". " << Baza[i].nazwa << " " << Baza[i].ocena << endl;
    }
    zapis.close(); /*Zamkniecie strumienia*/
}
/*Funkcja zapisujaca kubly z filmami w pliku*/
void zapisListy(string nazwaDoZapisania, int iloscwartosci, Film Baza[], Kolejka Bazalista[])
{
    ofstream zapis(nazwaDoZapisania); /*Strumien do zapisu*/
    int ilosc = 1;                    /*Zmienna o numerze zapisu*/
    /*Podwojna petla najpierw wybiera kubel potem wypisuje dane z danego kubla*/
    for (int i = 0; i < iloscwartosci; i++)
    {
        for (int j = 0; j < Bazalista[i].iloscCalkowita; j++)
        {
            /*Zapis do pliku*/
            zapis << ilosc << ". " << Bazalista[i].poczatek->zwrocTytul() << " " << Bazalista[i].poczatek->zwrocOcena() << endl;
            /*Usuniecie zapisanego pliku*/
            Bazalista[i].usunPierwsza();
            ilosc++;
        }
    }
    zapis.close(); /*Zamkniecie strumienia*/
}