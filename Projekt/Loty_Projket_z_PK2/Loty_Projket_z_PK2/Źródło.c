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
	data a = { 1,1,2020 };
	data b = { 1,1,2030 };

	pHead=wczytaj_dane_z_pliku("loty2.txt");
	wyswietl_pracownikow_i_ich_loty(pHead, a, b);
	wyswietl_zestawienie_lotow_pracownika_do_kontynentow(pHead->next, a, b);
	usun_liste_pracownikow(&pHead);
	_CrtDumpMemoryLeaks();
	return 0;
}
