#ifndef FUNKCJE_POMOCNICZE
#define FUNKCJE_POMOCNICZE
#include "struktury.h"
/** Funkcja ?????????????????????????????????????????????????????
	@param argc ilo�� argument�w przes�anych do programu
	@param argv[] tablica argument�w przes�anych do programu
	@param pHead wska�nik na g�ow� listy pracownik�w
	*/
void wyszukaj_zapytanie(int argc, char* argv[], lista_pracownikow* pHead);
/** Funkcja okre�laj�ca na jakim kontynencie le�y dany kraj
	@param kraj nazwa kraju
	@return liczba odpowiadaj�ca nazwie kontynentu
	*/
int jaki_kontynent(char* kraj);
/** Funkcja zwracaj�ca liczb� odpowiadaj�c� nazwie przekazanego do funkcji kontynentu
	@param kontynent nazwa kontynentu
	@return liczba odpowiadaj�ca nazwie kontynentu
	*/
int kontynent_na_liczbe(char* kontynent);
/** Funkcja zwracaj�ca nazwe kontynentu na podstawie odpowiadaj�cej jej liczbie
	@param a liczba
	@return nazwa kontynentu odpowiadaj�ca liczbie
	*/
char* liczba_na_kontynent(int a);
/** Funkcja konwertuj�ca napis na liczb�
	@param napis napis
	@return liczba
	*/
int napis_na_liczbe(char* napis);
/** Funkcja zwracaj�ca �ancuch znak�w z wszystkimi literami zmienionymi na du�e litery
	@param a �a�cuch znak�w
	@return �a�cuch znak�w z samymi du�ymi literami
	*/
char* lancuch_znakow_na_duze_litery(char* a);
/** Funkcja por�wnuj�ca dwie daty
	@param a pierwsza data
	@param b druga data
	@return funkcja zwraca 1 gdy data a jest wi�ksza od daty b. 0 gdy daty s� identyczne. -1 gdy data a jest mniejsza od daty b.
	*/
int porownaj_daty(data a, data b);

#endif