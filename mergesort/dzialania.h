#include "film.h"
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

bool rozdzielSlowa(string linia, Film &Nowy);                                                  /*Funkcja rozdzielajaca ocene oraz tytul*/
int Wczytaj(string nazwa, int ilosc, Film Baza[]);                                             /*Funkcja wczytujaca filmy*/
void Zapis(string nazwaDoZapisania, int ilosc, Film Baza[]);                                   /*Funkcja zapisujaca baze z filmami w pliku*/

