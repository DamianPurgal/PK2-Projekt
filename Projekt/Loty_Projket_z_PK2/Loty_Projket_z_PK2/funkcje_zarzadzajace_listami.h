#ifndef FUNKCJE_ZARZADZAJACE_LISTAMI
#define FUNKCJE_ZARZADZAJACE_LISTAMI
#include "struktury.h"
/** Funkcja zwracaj¹ca wskaŸnik na wybranego pracownika
	@param pHead wskaŸnik na g³owê listy pracowników
	@param imie pracownika
	@param nazwisko pracownika
	@return wskaŸnik na wyszukanego pracownika
	*/
lista_pracownikow* znajdz_pracownika_w_liscie(lista_pracownikow* pHead, char* imie, char* nazwisko);
/** Funkcja zwraca iloœæ elementów w liœcie pracowników
	@param pHead wskaŸnik na g³owê listy pracowników 
	@return iloœæ elementów w liœcie pracowników
	*/
int ilosc_elementow_w_liscie_pracownikow(lista_pracownikow* pHead);
/** Funkcja dodaje element do listy pracowników
	@param pHead wskaŸnik na g³owê listy pracowników
	@param pracownik wskaŸnik na pracownika
	*/
void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik);
/** Funkcja dodaje element do listy lotów
	@param pHead wskaŸnik na g³owê listy lotów
	@return wskaŸnik na lot
	*/
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot);
/** Funkcja usuwa wszystkie elementy w liœcie pracowników
	@param pHead wskaŸnik na g³owê listy pracowników
	*/
void usun_liste_pracownikow(lista_pracownikow** pHead);
/** Funkcja usuwa wszystkie elementy w liœcie lotów
	@param pHead wskaŸnik na g³owê listy lotów
	*/
void usun_liste_lotow(lista_lotow** pHead);

#endif