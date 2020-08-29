#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struktury.h"
#include "funkcje_wczytujace_dane.h"
#include "funkcje_zarzadzajace_listami.h"
#include "funkcje_pomocnicze.h"
#define MAX_ZNAKOW 25

char* wczytaj_napis(FILE* plik)
{
	char tresc[MAX_ZNAKOW];
	char znak = fgetc(plik);
	int i = 0;
	while (znak != ' ' && znak != '\n' && znak != EOF)
	{
		tresc[i] = znak;
		i++;
		znak = fgetc(plik);
	}
	if (i != 0)
	{
		tresc[i] = '\0';
		char* wynik = malloc((i + 1) * sizeof(char));
		strcpy(wynik, tresc);
		tresc[i] = 'x';
		return wynik;
	}else
	return NULL;
}
lista_lotow* wczytaj_lot(FILE* plik)
{
	lista_lotow* wynik = malloc(sizeof(lista_lotow));
	char* tekst = wczytaj_napis(plik);
	wynik->data = wczytaj_date_z_tekstu(tekst);
	free(tekst);
	wynik->kraj_poczatkowy = wczytaj_napis(plik);
	wynik->kraj_koncowy = wczytaj_napis(plik);
	tekst = wczytaj_napis(plik);
	wynik->godziny_lotu = napis_na_liczbe(tekst);
	free(tekst);
	tekst = wczytaj_napis(plik);
	wynik->minuty_lotu = napis_na_liczbe(tekst);
	free(tekst);
	tekst = wczytaj_napis(plik);
	wynik->mile_lotu = napis_na_liczbe(tekst);
	free(tekst);
	wynik->next = NULL;
	return wynik;
}
lista_pracownikow* wczytaj_pracownika(FILE* plik)
{
	lista_pracownikow* pracownik = malloc(sizeof(lista_pracownikow));
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
	plik = fopen(nazwa_pliku, "r");
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
				if (pracownik && lot)
					dodaj_lot_do_listy(&(pracownik->loty), &lot);
			}
		}
		fclose(plik);
	}
	free(plik);
	return pHead;
}
data wczytaj_date_z_tekstu(char* tekst)
{ 
	data wynik;
	int l = strlen(tekst);
	int a = 0;
	int b = 0;
	char tab[8];
	int tabData[3];
	int td = 0;
	char* liczba;
	for (int i = 0; i < 3; i++)
	{
		b = 0;
		while (!(tekst[a] == '.' || tekst[a] == '-' || tekst[a] == '\0'))
		{
			tab[b] = tekst[a];
			a++;
			b++;
		}
		a++;
		tab[b] = '\0';
		liczba = malloc(sizeof(char) * (b + 1));
		strcpy(liczba, tab);
		tabData[td] = napis_na_liczbe(liczba);
		td++;
		tab[b] = 'z';
		b = 0;
		free(liczba);
	}
	wynik.dzien = tabData[0];
	wynik.miesiac = tabData[1];
	wynik.rok = tabData[2];
	return wynik;
}
argumenty odczytaj_argumenty(int argc, char* argv[])
{
	argumenty wynik = { NULL,NULL,NULL,NULL,NULL,{0,0,0},{99,99,9999} };
	for (int i = 0; i < argc - 1; i++)
	{
		if (strcmp(argv[i], "-p") == 0){
			i++;
			wynik.plik_odczyt = argv[i];
		}else if (strcmp(argv[i], "-t") == 0){
			i++;
			wynik.typ = argv[i];
		}else if (strcmp(argv[i], "-i") == 0){
			i++;
			wynik.imie = argv[i];
		}else if (strcmp(argv[i], "-n") == 0){
			i++;
			wynik.nazwisko = argv[i];
		}else if (strcmp(argv[i], "-k") == 0){
			i++;
			wynik.kontynent = argv[i];
		}else if (strcmp(argv[i], "-dod") == 0){
			i++;
			wynik.dataOd = wczytaj_date_z_tekstu(argv[i]);
		}else if (strcmp(argv[i], "-ddo") == 0 && i + 1 < argc){
			i++;
			wynik.dataDo = wczytaj_date_z_tekstu(argv[i]);
		}
	}
	return wynik;
}