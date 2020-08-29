#ifndef FUNKCJE_WCZYTUJACE_DANE
#define FUNKCJE_WCZYTUJACE_DANE
#include "struktury.h"

/** Funkcja zwracaj�ca struktur� "data" pozyskan� z tekstu w formacie "dd-mm-rrrr" lub "dd.mm.rrrr"
	@param data data w formie �a�cuchu znak�w
	@return struktura "data"
	*/
data wczytaj_date_z_tekstu(char* data);
/** Funkcja wczytuj�ca �a�cuch znak�w ko�cz�cy si� znakiem ' '
	@param plik plik z kt�rego wczytany ma zosta� �a�cuch znak�w
	@return �a�cuch znak�w
	*/
char* wczytaj_napis(FILE* plik);
/** Funkcja wczytuj�ca wszystkie dane z pliku 
	@param nazwa_pliku nazwa pliku z do odczytu
	@return wska�nik na g�ow� listy pracownik�w
	*/
lista_pracownikow* wczytaj_dane_z_pliku(char* nazwa_pliku);
/** Funkcja odczytuje prze��czniki programu i zwraca je w strukturze "argumenty"
	@param argc ilo�� element�w w tablicy
	@param argv tablica �ancuch�w znak�w
	@return odczytane prze��czniki w strukturze "argumenty"
	*/
argumenty odczytaj_argumenty(int argc, char* argv[]);

#endif