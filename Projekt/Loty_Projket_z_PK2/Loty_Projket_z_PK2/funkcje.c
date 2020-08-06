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
void wyswietl_liste_lotow(lista_lotow* pHead)
{
	while (pHead != NULL)
	{
		pHead = pHead->next;
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
	while (znak != ' ' && znak != '\n')
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
	wynik->dzien = napis_na_liczbe(wczytaj_napis(plik));
	wynik->miesiac = napis_na_liczbe(wczytaj_napis(plik));
	wynik->rok = napis_na_liczbe(wczytaj_napis(plik));
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
				dodaj_lot_do_listy(&(pracownik->loty), &lot);
			}
		}
	fclose(plik);
	}
	free(plik);
	return pHead;
}