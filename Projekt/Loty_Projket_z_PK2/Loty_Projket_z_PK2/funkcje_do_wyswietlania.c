#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struktury.h"
#include "funkcje_do_wyswietlania.h"
#include "funkcje_pomocnicze.h"
#include "funkcje_zarzadzajace_listami.h"

void wyswietl_liste_pracownikow(lista_pracownikow* pHead)
{
	printf("=================================================\n");
	printf("                 LISTA PRACOWNIKOW               \n");
	printf("=================================================\n");
	printf("   %-12s %-12s %-12s\n", "Imie:", "Nazwisko:", "Stanowisko:");
	printf("-------------------------------------------------\n");
	while (pHead != NULL)
	{
		printf("   %-12s %-12s %-12s\n", pHead->imie, pHead->nazwisko, pHead->stanowisko);
		pHead = pHead->next;
	}
}
void wyswietl_liste_lotow(lista_lotow* pHead, data dataOd, data dataDo)
{
	printf("%-16s %-15s %-12s %-6s %-10s\n", "Kraj_poczatkowy", "Kraj_koncowy", "Data", "Mile", "Czas lotu");
	printf("======================================================================\n");
	while (pHead != NULL)
	{
		if (porownaj_daty(dataOd, pHead->data) <= 0 && porownaj_daty(dataDo, pHead->data) >= 0)
		{
			printf("%-16s %-15s %-.2d-%-.2d-%-6d %-6d %-4dgodz. %-2d min.\n", pHead->kraj_poczatkowy, pHead->kraj_koncowy,
				pHead->data.dzien, pHead->data.miesiac, pHead->data.rok, pHead->mile_lotu, pHead->godziny_lotu, pHead->minuty_lotu);
		}
		pHead = pHead->next;
	}
}
void wyswietl_pracownikow_i_ich_loty(lista_pracownikow* pHead, data dataOd, data dataDo)
{
	printf("----------------------------------------------------------------------\n");
	printf("                        Loty pracownikow:\n");
	if (dataOd.rok != 0 && dataDo.rok != 9999)
		printf("                  od %-.2d-%-.2d-%-.2d do %-.2d-%-.2d-%-.2d\n", dataOd.dzien, dataOd.miesiac, dataOd.rok, dataDo.dzien, dataDo.miesiac, dataDo.rok);
	else if (dataOd.rok != 0 && dataDo.rok == 9999)
		printf("                           od %-.2d-%-.2d-%-.2d \n", dataOd.dzien, dataOd.miesiac, dataOd.rok);
	else if (dataOd.rok == 0 && dataDo.rok != 9999)
		printf("                           do %-.2d-%-.2d-%-.2d\n", dataDo.dzien, dataDo.miesiac, dataDo.rok);
	else
		printf("\n");
	printf("----------------------------------------------------------------------\n");
	while (pHead != NULL)
	{
		printf("imie: %s nazwisko: %s stanowisko: %s \n", pHead->imie, pHead->nazwisko, pHead->stanowisko);
		wyswietl_liste_lotow(pHead->loty, dataOd, dataDo);
		printf("----------------------------------------------------------------------\n");
		pHead = pHead->next;
	}
}
void wyswietl_pracownika_i_jego_loty(lista_pracownikow* pHead, data dataOd, data dataDo)
{
	if (pHead)
	{
		printf("----------------------------------------------------------------------\n");
		printf("                         Loty pracownika:\n");
		if (dataOd.rok != 0 && dataDo.rok != 9999)
			printf("                  od %-.2d-%-.2d-%-.2d do %-.2d-%-.2d-%-.2d\n", dataOd.dzien, dataOd.miesiac, dataOd.rok, dataDo.dzien, dataDo.miesiac, dataDo.rok);
		else if (dataOd.rok != 0 && dataDo.rok == 9999)
			printf("                           od %-.2d-%-.2d-%-.2d \n", dataOd.dzien, dataOd.miesiac, dataOd.rok);
		else if (dataOd.rok == 0 && dataDo.rok != 9999)
			printf("                           do %-.2d-%-.2d-%-.2d\n", dataDo.dzien, dataDo.miesiac, dataDo.rok);
		else
			printf("\n");
		printf("----------------------------------------------------------------------\n");

		printf("imie: %s nazwisko: %s stanowisko: %s \n", pHead->imie, pHead->nazwisko, pHead->stanowisko);
		wyswietl_liste_lotow(pHead->loty, dataOd, dataDo);
		printf("----------------------------------------------------------------------\n");
	}
	else
		printf("Nie znaleziono pracownika\n");
}
void wyswietl_zestawienie_lotow_pracownika_do_kontynentow(lista_pracownikow* pHead, data dataOd, data dataDo)
{
	if (pHead)
	{
		int mile[6], godziny[6], minuty[6];
		for (int i = 0; i < 6; i++)
			mile[i] = godziny[i] = minuty[i] = 0;
		lista_lotow* loty = pHead->loty;
		while (loty != NULL)
		{
			if (porownaj_daty(dataOd, loty->data) <= 0 && porownaj_daty(dataDo, loty->data) >= 0)
			{
				mile[jaki_kontynent(loty->kraj_koncowy)] += loty->mile_lotu;
				godziny[jaki_kontynent(loty->kraj_koncowy)] += loty->godziny_lotu;
				minuty[jaki_kontynent(loty->kraj_koncowy)] += loty->minuty_lotu;
			}
			loty = loty->next;
		}
		int a;
		printf("========================================\n");
		printf("    Zestawienie lotow do kontynentow\n");
		if (dataOd.rok != 0 && dataDo.rok != 9999)
			printf("      od %-.2d-%-.2d-%-.2d do %-.2d-%-.2d-%-.2d\n", dataOd.dzien, dataOd.miesiac, dataOd.rok, dataDo.dzien, dataDo.miesiac, dataDo.rok);
		else if (dataOd.rok != 0 && dataDo.rok == 9999)
			printf("             od %-.2d-%-.2d-%-.2d \n", dataOd.dzien, dataOd.miesiac, dataOd.rok);
		else if (dataOd.rok == 0 && dataDo.rok != 9999)
			printf("             do %-.2d-%-.2d-%-.2d\n", dataDo.dzien, dataDo.miesiac, dataDo.rok);
		else
			printf("\n");
		printf("========================================\n");
		printf("%-20s %-8s %-5s %-5s \n", "Kontynent", "Mile", "godz.", "min.");
		printf("----------------------------------------\n");
		for (int i = 0; i < 6; i++)
		{
			a = minuty[i] / 60;
			godziny[i] += a;
			minuty[i] -= a * 60;
			printf("%-20s %-8d %-5d %-5d \n", liczba_na_kontynent(i), mile[i], godziny[i], minuty[i]);
		}
	}else
		printf("Nie znaleziono pracownika\n");
}
void wyswietl_zestawienie_lotow_pracownikow_do_kontynentu(lista_pracownikow* pHead, data dataOd, data dataDo, char* kontynent)
{
	int kontynent_liczba = kontynent_na_liczbe(kontynent);
	if (kontynent_liczba == 404){
		printf("Taki kontynent nie istnieje!");
		return;
	}
	int mile = 0, godziny = 0, minuty = 0;
	int a;
	lista_lotow* loty;
	printf("============================================\n");
	printf("    Zestawienie lotow do: %s \n", kontynent);
	if (dataOd.rok != 0 && dataDo.rok != 9999)
		printf("    od %-.2d-%-.2d-%-.2d do %-.2d-%-.2d-%-.2d\n", dataOd.dzien, dataOd.miesiac, dataOd.rok, dataDo.dzien, dataDo.miesiac, dataDo.rok);
	else if (dataOd.rok != 0 && dataDo.rok == 9999)
		printf("             od %-.2d-%-.2d-%-.2d \n", dataOd.dzien, dataOd.miesiac, dataOd.rok);
	else if (dataOd.rok == 0 && dataDo.rok != 9999)
		printf("             do %-.2d-%-.2d-%-.2d\n", dataDo.dzien, dataDo.miesiac, dataDo.rok);
	else
		printf("\n");
	printf("============================================\n");
	printf("%-12s %-12s %-7s %-5s %-5s \n", "Imie", "Nazwisko", "Mile", "godz.", "min.");
	printf("--------------------------------------------\n");
	while (pHead != NULL){
		loty = pHead->loty;
		while (loty != NULL){
			if (jaki_kontynent(loty->kraj_koncowy) == kontynent_liczba){
				if (porownaj_daty(dataOd, loty->data) <= 0 && porownaj_daty(dataDo, loty->data) >= 0){
					mile += loty->mile_lotu;
					godziny += loty->godziny_lotu;
					minuty += loty->minuty_lotu;
				}
			}
			loty = loty->next;
		}
		a = minuty / 60;
		godziny += a;
		minuty -= a * 60;
		printf("%-12s %-12s %-7d %-5d %-5d \n", pHead->imie, pHead->nazwisko, mile, godziny, minuty);
		minuty = godziny = mile = 0;
		pHead = pHead->next;
	}
}
void wyswietl_dane_zestawienie(argumenty arg, lista_pracownikow * pHead)
{
	if (arg.typ != NULL)
	{
		char* typ = lancuch_znakow_na_duze_litery(arg.typ);
		if (strcmp(typ, "LP") == 0)
		{
			wyswietl_liste_pracownikow(pHead);
		}else if (strcmp(typ, "LLWP") == 0){
			wyswietl_pracownikow_i_ich_loty(pHead, arg.dataOd, arg.dataDo);
		}else if (strcmp(typ, "ZLWPDK") == 0 && arg.kontynent != NULL){
			wyswietl_zestawienie_lotow_pracownikow_do_kontynentu(pHead, arg.dataOd, arg.dataDo, arg.kontynent);
		}else if(arg.imie != NULL && arg.nazwisko != NULL){
			if (strcmp(typ, "LLP") == 0)
			{
				wyswietl_pracownika_i_jego_loty(znajdz_pracownika_w_liscie(pHead, arg.imie, arg.nazwisko), arg.dataOd, arg.dataDo);
			}else if (strcmp(typ, "ZLPDWK") == 0){
				wyswietl_zestawienie_lotow_pracownika_do_kontynentow(znajdz_pracownika_w_liscie(pHead, arg.imie, arg.nazwisko), arg.dataOd, arg.dataDo);
			}
		}else
			printf("Podano zle dane\n");
		free(typ);
	}
}