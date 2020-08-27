#ifndef FUNKCJE_DO_WYSWIETLANIA
#define FUNKCJE_DO_WYSWIETLANIA
#include "struktury.h"
/** Funkcja wyœwietlaj¹ca listê pracowników
	@param pHead WskaŸnik na g³owê listy pracowników
	*/
void wyswietl_liste_pracownikow(lista_pracownikow* pHead);
/** Funkcja wyœwietlaj¹ca loty znajduj¹ce siê w liœcie lotów w danym przedziale czasu
	@param pHead WskaŸnik na g³owê listy lotów
	@param dataOd data od której wyœwietlane maj¹ byæ loty
	@param dataDo data do której wyœwietlane maj¹ byæ loty
	*/
void wyswietl_liste_lotow(lista_lotow* pHead, data dataOd, data dataDo);
/** Funkcja wyœwietlaj¹ca loty jednego pracownika w danym przedziale czasu
	@param pHead WskaŸnik na pracownika
	@param dataOd data od której wyœwietlane maj¹ byæ loty
	@param dataDo data do której wyœwietlane maj¹ byæ loty
	*/
void wyswietl_pracownika_i_jego_loty(lista_pracownikow* pHead, data dataOd, data dataDo);
/** Funkcja wyœwietlaj¹ca loty wszystkich pracowników w danym przedziale czasu
	@param pHead WskaŸnik na g³owê listy lotów
	@param dataOd data od której wyœwietlane maj¹ byæ loty
	@param dataDo data do której wyœwietlane maj¹ byæ loty
	*/
void wyswietl_pracownikow_i_ich_loty(lista_pracownikow* pHead, data dataOd, data dataDo);
/** Funkcja wyœwietlaj¹ca zestawienie lotów jednego pracownika do wszystkich kontynentów w danym przedziale czasu
	@param pHead WskaŸnik na pracownika
	@param dataOd data od której wyœwietlane ma byæ zestawienie
	@param dataDo data do której wyœwietlane ma byæ zestawienie
	*/
void wyswietl_zestawienie_lotow_pracownika_do_kontynentow(lista_pracownikow* pHead, data dataOd, data dataDo);
/** Funkcja wyœwietlaj¹ca zestawienie lotów wszystkich pracowników do danego kontynentów w danym przedziale czasu
	@param pHead WskaŸnik na g³owê listy pracowników
	@param dataOd data od której wyœwietlane ma byæ zestawienie
	@param dataDo data do której wyœwietlane ma byæ zestawienie
	@param kontynent nazwa kontynentu
	*/
void wyswietl_zestawienie_lotow_pracownikow_do_kontynentu(lista_pracownikow* pHead, data dataOd, data dataDo, char* kontynent);

void wyswietl_dane_zestawienie(argumenty arg, lista_pracownikow * pHead);
#endif