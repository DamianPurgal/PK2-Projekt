#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "struktury.h"
#include "funkcje.h"

int main()
{
	lista_pracownikow* pHead = NULL;
	//lista_pracownikow* nowy = malloc(sizeof(lista_pracownikow));
	//nowy->imie = "Janusz";
	//nowy->nazwisko = "xD";
	//nowy->next = NULL;
	//nowy->loty = NULL;
	//nowy->stanowisko = "Wyjadacz";
	//dodaj_pracownika_do_listy(&pHead, &nowy);
	//nowy = malloc(sizeof(lista_pracownikow));
	//nowy->imie = "Barbara";
	//nowy->nazwisko = "Nowak";
	//nowy->next = NULL;
	//nowy->loty = NULL;
	//nowy->stanowisko = "Stewardessa";
	//dodaj_pracownika_do_listy(&pHead,&nowy);
	//wyswietl_liste_pracownikow(pHead);


	pHead=wczytaj_dane_z_pliku("loty2.txt");
	wyswietl_liste_pracownikow(pHead);
	//wyswietl_liste_lotow(pHead->loty);;
	usun_liste_pracownikow(&pHead);
	_CrtDumpMemoryLeaks();
	return 0;
}