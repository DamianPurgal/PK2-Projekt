#ifndef FUNKCJE_WCZYTUJACE_DANE
#define FUNKCJE_WCZYTUJACE_DANE
#include "struktury.h"

/** Funkcja zwracaj¹ca strukturê "data" pozyskan¹ z tekstu w formacie "dd-mm-rrrr" lub "dd.mm.rrrr"
	@param data data w formie ³añcuchu znaków
	@return struktura "data"
	*/
data wczytaj_date_z_tekstu(char* data);
/** Funkcja wczytuj¹ca ³añcuch znaków koñcz¹cy siê znakiem ' '
	@param plik plik z którego wczytany ma zostaæ ³añcuch znaków
	@return ³añcuch znaków
	*/
char* wczytaj_napis(FILE* plik);
/** Funkcja wczytuj¹ca wszystkie dane z pliku 
	@param nazwa_pliku nazwa pliku z do odczytu
	@return wskaŸnik na g³owê listy pracowników
	*/
lista_pracownikow* wczytaj_dane_z_pliku(char* nazwa_pliku);
/** Funkcja odczytuje prze³¹czniki programu i zwraca je w strukturze "argumenty"
	@param argc iloœæ elementów w tablicy
	@param argv tablica ³ancuchów znaków
	@return odczytane prze³¹czniki w strukturze "argumenty"
	*/
argumenty odczytaj_argumenty(int argc, char* argv[]);

#endif