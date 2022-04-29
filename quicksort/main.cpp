#include <sys/time.h>
#include "dzialania.h"
#include "quicksort.h"

int main()
{
    string bazaDanych = "projekt2_dane.csv";  /*Nazwa pliku z ktorego odczytujemy dane*/
    string bazaZapisu = "wynik.txt";          /*Nazwa pliku gdzie zapiszemy dane*/
    
    int ilosc = 10;                          /*Ilosc filmow ktore wczytujemy*/
    Film *Baza = new Film[ilosc];             /*Utworzenie tablicy z filmami*/
   
    ilosc = Wczytaj(bazaDanych, ilosc, Baza); /*Wczytanie filmow z pliku*/
  
    struct timeval begin, end;                /*Struktura pozwalajaca na mimerzenie czasu*/
    gettimeofday(&begin, 0);                  /*Rozpoczenie mierzenia czasu*/
    Quicksort(Baza, 0, ilosc - 1);            /*Sortowanie wgranej bazy*/
    gettimeofday(&end, 0);                    /*Koniec mierzenia czasu*/
    /*Zapisanie zmierzonego czasu oraz wypisanie go*/
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    cout << elapsed << endl;
    
    Zapis(bazaZapisu, ilosc, Baza); /*Zapis posortowanej bazy z filmami*/
}