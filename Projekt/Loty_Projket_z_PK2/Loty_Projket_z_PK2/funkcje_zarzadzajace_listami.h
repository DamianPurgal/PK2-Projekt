#ifndef FUNKCJE_ZARZADZAJACE_LISTAMI
#define FUNKCJE_ZARZADZAJACE_LISTAMI
#include "struktury.h"
/** Funkcja zwracaj�ca wska�nik na wybranego pracownika
	@param pHead wska�nik na g�ow� listy pracownik�w
	@param imie pracownika
	@param nazwisko pracownika
	@return wska�nik na wyszukanego pracownika
	*/
lista_pracownikow* znajdz_pracownika_w_liscie(lista_pracownikow* pHead, char* imie, char* nazwisko);
/** Funkcja zwraca ilo�� element�w w li�cie pracownik�w
	@param pHead wska�nik na g�ow� listy pracownik�w 
	@return ilo�� element�w w li�cie pracownik�w
	*/
int ilosc_elementow_w_liscie_pracownikow(lista_pracownikow* pHead);
/** Funkcja dodaje element do listy pracownik�w
	@param pHead wska�nik na g�ow� listy pracownik�w
	@param pracownik wska�nik na pracownika
	*/
void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik);
/** Funkcja dodaje element do listy lot�w
	@param pHead wska�nik na g�ow� listy lot�w
	@return wska�nik na lot
	*/
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot);
/** Funkcja usuwa wszystkie elementy w li�cie pracownik�w
	@param pHead wska�nik na g�ow� listy pracownik�w
	*/
void usun_liste_pracownikow(lista_pracownikow** pHead);
/** Funkcja usuwa wszystkie elementy w li�cie lot�w
	@param pHead wska�nik na g�ow� listy lot�w
	*/
void usun_liste_lotow(lista_lotow** pHead);

#endif