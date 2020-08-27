#ifndef FUNKCJE_ZARZADZAJACE_LISTAMI
#define FUNKCJE_ZARZADZAJACE_LISTAMI
#include "struktury.h"
/** Funkcja zwracajπca wskaünik na wybranego pracownika
	@param pHead wskaünik na g≥owÍ listy pracownikÛw
	@param imie pracownika
	@param nazwisko pracownika
	@return wskaünik na wyszukanego pracownika
	*/
lista_pracownikow* znajdz_pracownika_w_liscie(lista_pracownikow* pHead, char* imie, char* nazwisko);
int ilosc_elementow_w_liscie_pracownikow(lista_pracownikow* pHead);
void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik);
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot);
void usun_liste_pracownikow(lista_pracownikow** pHead);
void usun_liste_lotow(lista_lotow** pHead);

#endif