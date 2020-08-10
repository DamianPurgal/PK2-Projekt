#define _CRT_SECURE_NO_DEPRECATE
#define MAX_ZNAKOW 10
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struktury.h"
#include "funkcje.h"

char* kontynenty[6][6] = {
	{ "Polska","Niemcy","Hiszpania","Francja","Wlochy","UK" },
	{ "Chiny","Japonia","Tajlandia", "", "", "" },
	{ "Australia", "", "", "", "", "" },
	{ "USA","Kanada", "", "", "", "" },
	{ "Brazylia","Argentyna", "", "", "", "" },
	{ "Sudan","Egipt","Kenia", "", "", ""}
};
/*
0-Europa
1-Azja
2-Australia i oceania
3-Ameryka polnocna
4-Ameryka poludniowa
5-Afryka
*/

int jakiKontynent(char* kraj)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (strcmp(kraj, kontynenty[i][j])==0)
				return i;
		}
	}
	return 404;
}
void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik)
{
	(*pracownik)->next = *pHead;
	*pHead = *pracownik;
}
void wyswietl_liste_pracownikow(lista_pracownikow* pHead)
{
	while (pHead != NULL)
	{
		printf("imie: %s nazwisko: %s stanowisko: %s \n", pHead->imie, pHead->nazwisko, pHead->stanowisko);
		pHead = pHead->next;
	}
}
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot)
{
	(*lot)->next = *pHead;
	*pHead = *lot;
}
void wyswietl_liste_lotow(lista_lotow* pHead, data dataOd, data dataDo)
{
	while (pHead != NULL)
	{
		if (porownaj_daty(dataOd, pHead->data) <= 0 && porownaj_daty(dataDo, pHead->data) >= 0)
		{
			printf("z: %s do: %s data: %d-%d-%d mile: %d  czas lotu: %d g %d m \n", pHead->kraj_poczatkowy, pHead->kraj_koncowy,
				pHead->data.dzien, pHead->data.miesiac, pHead->data.rok, pHead->mile_lotu, pHead->godziny_lotu, pHead->minuty_lotu);
		}
		pHead = pHead->next;
	}
}
void wyswietl_pracownikow_i_ich_loty(lista_pracownikow* pHead, data dataOd, data dataDo)
{
	while (pHead != NULL)
	{
		printf("imie: %s nazwisko: %s stanowisko: %s \n", pHead->imie, pHead->nazwisko, pHead->stanowisko);
		wyswietl_liste_lotow(pHead->loty, dataOd, dataDo);
		printf("----------------------------------------------------------------------\n");
		pHead = pHead->next;
	}
}
char* liczba_na_kontynent(int a)
{
	switch (a)
	{
		case 0:
			return "Europa";
			break;
		case 1:
			return "Azja";
			break;
		case 2:
			return "Australia i oc.";
			break;
		case 3:
			return "Ameryka polnocna";
			break;
		case 4:
			return "Ameryka poludniowa";
			break;
		case 5:
			return "Afryka";
			break;
		default:
			return "BLAD";
	}
}
void wyswietl_zestawienie_lotow_pracownika_do_kontynentow(lista_pracownikow* pHead, data dataOd, data dataDo)
{
	int mile[6], godziny[6], minuty[6];
	for (int i = 0; i < 6; i++)
		mile[i] = godziny[i] = minuty[i] = 0;
	lista_lotow* loty = pHead->loty;
	while (loty != NULL)
	{ 
		if (porownaj_daty(dataOd, loty->data) <= 0 && porownaj_daty(dataDo, loty->data) >= 0)
		{
			mile[jakiKontynent(loty->kraj_koncowy)] += loty->mile_lotu;
			godziny[jakiKontynent(loty->kraj_koncowy)] += loty->godziny_lotu;
			minuty[jakiKontynent(loty->kraj_koncowy)] += loty->minuty_lotu;
		}
		loty = loty->next;
	}
	int a;
	for (int i = 0; i < 6; i++)
	{
		a = minuty[i] / 60;
		godziny[i] += a;
		minuty[i] -= a * 60;
		printf("Kontynent: %s mile: %d godziny: %d minuty: %d \n", liczba_na_kontynent(i), mile[i], godziny[i], minuty[i]);
	}

}
void usun_liste_pracownikow(lista_pracownikow** pHead)
{
	lista_pracownikow* tymczasowa;
	while (*pHead != NULL)
	{
		tymczasowa = *pHead;
		*pHead = (*pHead)->next;
		usun_liste_lotow(&(tymczasowa->loty));//dodane
		free(tymczasowa->imie);
		free(tymczasowa->nazwisko);
		free(tymczasowa->stanowisko);
		free(tymczasowa);
	}
}
void usun_liste_lotow(lista_lotow** pHead)
{
	lista_lotow* tymczasowa;
	while (*pHead != NULL)
	{
		tymczasowa = *pHead;
		*pHead = (*pHead)->next;
		free(tymczasowa->kraj_koncowy);
		free(tymczasowa->kraj_poczatkowy);
		free(tymczasowa);
	}
}
char* wczytaj_napis(FILE* plik)
{
	char tresc[MAX_ZNAKOW];
	char znak = fgetc(plik);
	int i = 0;
	while (znak != ' ' && znak != '\n' && znak!=EOF)
	{
		tresc[i] = znak;
		i++;
		znak = fgetc(plik);
	}
	tresc[i] = '\0';
	char* wynik = malloc((i+1) * sizeof(char));
	strcpy(wynik, tresc);
	tresc[i] = 'x';
	return wynik;
}
lista_lotow* wczytaj_lot(FILE* plik)
{
	lista_lotow* wynik = malloc(sizeof(lista_lotow));
	wynik->data.dzien = napis_na_liczbe(wczytaj_napis(plik));
	wynik->data.miesiac = napis_na_liczbe(wczytaj_napis(plik));
	wynik->data.rok = napis_na_liczbe(wczytaj_napis(plik));
	wynik->kraj_poczatkowy = wczytaj_napis(plik);
	wynik->kraj_koncowy = wczytaj_napis(plik);
	wynik->godziny_lotu = napis_na_liczbe(wczytaj_napis(plik));
	wynik->minuty_lotu = napis_na_liczbe(wczytaj_napis(plik));
	wynik->mile_lotu= napis_na_liczbe(wczytaj_napis(plik));
	wynik->next = NULL;
	return wynik;
}
int napis_na_liczbe(char* napis)
{
	int dlugosc = strlen(napis);
	int potega = dlugosc - 1;
	int wynik = 0;
	for (int i = 0; i < dlugosc; i++)
	{
		wynik += (napis[i] - 48) * pow(10, potega);
		potega--;
	}
	free(napis);
	return wynik;
}
lista_pracownikow* wczytaj_pracownika(FILE* plik)
{
	lista_pracownikow* pracownik;
	pracownik = malloc(sizeof(lista_pracownikow));
	pracownik->imie = wczytaj_napis(plik);
	pracownik->nazwisko = wczytaj_napis(plik);
	pracownik->stanowisko = wczytaj_napis(plik);
	pracownik->next = NULL;
	pracownik->loty = NULL;
	return pracownik;
}
lista_pracownikow* wczytaj_dane_z_pliku(char* nazwa_pliku)
{
	FILE* plik;
	lista_pracownikow* pHead = NULL;
	plik=fopen(nazwa_pliku, "r");
	if (plik)
	{
		char typ;
		lista_pracownikow* pracownik = NULL;
		lista_lotow* lot = NULL;
		while ((typ = fgetc(plik)) != EOF)
		{
			if (typ == 'P')
			{
				fgetc(plik);
				pracownik = wczytaj_pracownika(plik);
				dodaj_pracownika_do_listy(&pHead, &pracownik);
			}
			else if (typ == 'L')
			{
				fgetc(plik);
				lot = wczytaj_lot(plik);
				if(pracownik && lot)
					dodaj_lot_do_listy(&(pracownik->loty), &lot);
			}
		}
	fclose(plik);
	}
	free(plik);
	return pHead;
}
int porownaj_daty(data a, data b)
{
	if (a.rok > b.rok)
		return 1;
	else if (a.rok < b.rok)
		return -1;
	else
	{
		if (a.miesiac > b.miesiac)
			return 1;
		else if (a.miesiac < b.miesiac)
			return -1;
		else
		{
			if (a.dzien > b.dzien)
				return 1;
			else if (a.dzien < b.dzien)
				return -1;
			else
			{
				return 0;
			}
		}
	}
}