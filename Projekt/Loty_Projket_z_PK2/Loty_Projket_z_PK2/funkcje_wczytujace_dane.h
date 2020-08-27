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
	@param kraj nazwa kraju
	@return liczba odpowiadaj�ca nazwie kontynentu
	*/
lista_pracownikow* wczytaj_dane_z_pliku(char* nazwa_pliku);

argumenty odczytaj_argumenty(int argc, char* argv[]);

#endif