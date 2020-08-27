#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "struktury.h"
#include "funkcje_do_wyswietlania.h"
#include "funkcje_pomocnicze.h"
#include "funkcje_wczytujace_dane.h"
#include "funkcje_zarzadzajace_listami.h"

main(int argc, char* argv[])
{
	argumenty zapytanie = odczytaj_argumenty(argc, argv);
	if (zapytanie.plik_odczyt != NULL)
	{
		lista_pracownikow* pHead = wczytaj_dane_z_pliku(zapytanie.plik_odczyt);
		wyswietl_dane_zestawienie(zapytanie, pHead);
		usun_liste_pracownikow(&pHead);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
