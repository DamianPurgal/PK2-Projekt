#ifndef FUNKCJE_DO_WYSWIETLANIA
#define FUNKCJE_DO_WYSWIETLANIA
#include "struktury.h"
/** Funkcja wy�wietlaj�ca list� pracownik�w
	@param pHead Wska�nik na g�ow� listy pracownik�w
	*/
void wyswietl_liste_pracownikow(lista_pracownikow* pHead);
/** Funkcja wy�wietlaj�ca loty znajduj�ce si� w li�cie lot�w w danym przedziale czasu
	@param pHead Wska�nik na g�ow� listy lot�w
	@param dataOd data od kt�rej wy�wietlane maj� by� loty
	@param dataDo data do kt�rej wy�wietlane maj� by� loty
	*/
void wyswietl_liste_lotow(lista_lotow* pHead, data dataOd, data dataDo);
/** Funkcja wy�wietlaj�ca loty jednego pracownika w danym przedziale czasu
	@param pHead Wska�nik na pracownika
	@param dataOd data od kt�rej wy�wietlane maj� by� loty
	@param dataDo data do kt�rej wy�wietlane maj� by� loty
	*/
void wyswietl_pracownika_i_jego_loty(lista_pracownikow* pHead, data dataOd, data dataDo);
/** Funkcja wy�wietlaj�ca loty wszystkich pracownik�w w danym przedziale czasu
	@param pHead Wska�nik na g�ow� listy lot�w
	@param dataOd data od kt�rej wy�wietlane maj� by� loty
	@param dataDo data do kt�rej wy�wietlane maj� by� loty
	*/
void wyswietl_pracownikow_i_ich_loty(lista_pracownikow* pHead, data dataOd, data dataDo);
/** Funkcja wy�wietlaj�ca zestawienie lot�w jednego pracownika do wszystkich kontynent�w w danym przedziale czasu
	@param pHead Wska�nik na pracownika
	@param dataOd data od kt�rej wy�wietlane ma by� zestawienie
	@param dataDo data do kt�rej wy�wietlane ma by� zestawienie
	*/
void wyswietl_zestawienie_lotow_pracownika_do_kontynentow(lista_pracownikow* pHead, data dataOd, data dataDo);
/** Funkcja wy�wietlaj�ca zestawienie lot�w wszystkich pracownik�w do danego kontynent�w w danym przedziale czasu
	@param pHead Wska�nik na g�ow� listy pracownik�w
	@param dataOd data od kt�rej wy�wietlane ma by� zestawienie
	@param dataDo data do kt�rej wy�wietlane ma by� zestawienie
	@param kontynent nazwa kontynentu
	*/
void wyswietl_zestawienie_lotow_pracownikow_do_kontynentu(lista_pracownikow* pHead, data dataOd, data dataDo, char* kontynent);

void wyswietl_dane_zestawienie(argumenty arg, lista_pracownikow * pHead);
#endif