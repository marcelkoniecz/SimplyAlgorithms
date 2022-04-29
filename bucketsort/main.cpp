#include <iostream>
#include <string>
#include <sys/time.h>
#include "dzialania.h"
#include "kolejka.h"
#include "bucketsort.h"
using namespace std;

int main()
{

    int iloscwartosci = 11; /*Zadeklarowanie ilosci wartosci do posorotwnia*/
    int iloscFilmow = 10;  /*Ilosc filmow ktore wczytujemy*/

    string bazaDanych = "projekt2_dane.csv"; /*Nazwa pliku z ktorego odczytujemy dane*/
    string bazaZapisu = "wynik.txt";         /*Nazwa pliku gdzie zapiszemy dane*/

    Film *Baza = new Film[iloscFilmow];              /*Utworzenie tablicy z filmami*/
    Kolejka *Bazalista = new Kolejka[iloscwartosci]; /*Utworzenie tablicy z listami*/

    iloscFilmow = Wczytaj(bazaDanych, iloscFilmow, Baza); /*Wczytanie filmow z pliku*/

    struct timeval begin, end;                   /*Struktura pozwalajaca na mimerzenie czasu*/
    gettimeofday(&begin, 0);                     /*Rozpoczenie mierzenia czasu*/
    Kubelkowe(Baza, Bazalista, iloscFilmow - 1); /*Sortowanie wgranej bazy*/
    gettimeofday(&end, 0);                       /*Koniec mierzenia czasu*/
    /*Zapisanie zmierzonego czasu oraz wypisanie go*/
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    cout << elapsed << endl;

    zapisListy(bazaZapisu, iloscwartosci, Baza, Bazalista); /*Zapis posortowanej bazy z filmami*/
}