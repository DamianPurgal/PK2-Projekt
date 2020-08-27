#ifndef FUNKCJE_POMOCNICZE
#define FUNKCJE_POMOCNICZE
#include "struktury.h"
/** Funkcja ?????????????????????????????????????????????????????
	@param argc iloœæ argumentów przes³anych do programu
	@param argv[] tablica argumentów przes³anych do programu
	@param pHead wskaŸnik na g³owê listy pracowników
	*/
void wyszukaj_zapytanie(int argc, char* argv[], lista_pracownikow* pHead);
/** Funkcja okreœlaj¹ca na jakim kontynencie le¿y dany kraj
	@param kraj nazwa kraju
	@return liczba odpowiadaj¹ca nazwie kontynentu
	*/
int jaki_kontynent(char* kraj);
/** Funkcja zwracaj¹ca liczbê odpowiadaj¹c¹ nazwie przekazanego do funkcji kontynentu
	@param kontynent nazwa kontynentu
	@return liczba odpowiadaj¹ca nazwie kontynentu
	*/
int kontynent_na_liczbe(char* kontynent);
/** Funkcja zwracaj¹ca nazwe kontynentu na podstawie odpowiadaj¹cej jej liczbie
	@param a liczba
	@return nazwa kontynentu odpowiadaj¹ca liczbie
	*/
char* liczba_na_kontynent(int a);
/** Funkcja konwertuj¹ca napis na liczbê
	@param napis napis
	@return liczba
	*/
int napis_na_liczbe(char* napis);
/** Funkcja zwracaj¹ca ³ancuch znaków z wszystkimi literami zmienionymi na du¿e litery
	@param a ³añcuch znaków
	@return ³añcuch znaków z samymi du¿ymi literami
	*/
char* lancuch_znakow_na_duze_litery(char* a);
/** Funkcja porównuj¹ca dwie daty
	@param a pierwsza data
	@param b druga data
	@return funkcja zwraca 1 gdy data a jest wiêksza od daty b. 0 gdy daty s¹ identyczne. -1 gdy data a jest mniejsza od daty b.
	*/
int porownaj_daty(data a, data b);

#endif