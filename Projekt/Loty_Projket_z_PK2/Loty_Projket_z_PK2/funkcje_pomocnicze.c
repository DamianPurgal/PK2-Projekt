#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struktury.h"
#include "funkcje_wczytujace_dane.h"
#include "funkcje_do_wyswietlania.h"
#include "funkcje_zarzadzajace_listami.h"

char* kontynenty[6][6] = {
	{ "POLSKA","NIEMCY","HISZPANIA","FRANCJA","WLOCHY","UK" },
	{ "CHINY","JAPONIA","TAJLANDIA", "INDIE", "", "" },
	{ "AUSTRALIA", "", "", "", "", "" },
	{ "USA","KANADA", "", "", "", "" },
	{ "BRAZYLIA","ARGENTYNA", "", "", "", "" },
	{ "SUDAN","EGIPT","KENIA", "", "", ""}
};

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
char* lancuch_znakow_na_duze_litery(char* a)
{
	if (a == NULL)
		return NULL;
	int l = strlen(a);
	char* wynik = malloc(sizeof(char) * (l + 1));
	for (int i = 0; i < l; i++)
	{
		if (a[i] > 96 && a[i] < 147)
			wynik[i] = a[i] - 32;
		else
			wynik[i] = a[i];
	}
	wynik[l] = '\0';
	return wynik;
}
int jaki_kontynent(char* kraj)
{
	char* krajDuze = lancuch_znakow_na_duze_litery(kraj);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (strcmp(krajDuze, kontynenty[i][j]) == 0)
			{
				free(krajDuze);
				return i;
			}
		}
	}
	return 404;
}
int kontynent_na_liczbe(char* kontynent)
{
	int wynik = 404;
	char* kontynent_duze_litery = lancuch_znakow_na_duze_litery(kontynent);
	if (strcmp(kontynent_duze_litery, "EUROPA") == 0)
		wynik = 0;
	else if (strcmp(kontynent_duze_litery, "AZJA") == 0)
		wynik = 1;
	else if (strcmp(kontynent_duze_litery, "AUSTRALIA") == 0)
		wynik = 2;
	else if (strcmp(kontynent_duze_litery, "AMERYKA_POLNOCNA") == 0)
		wynik = 3;
	else if (strcmp(kontynent_duze_litery, "AMERYKA_POLUDNIOWA") == 0)
		wynik = 4;
	else if (strcmp(kontynent_duze_litery, "AFRYKA") == 0)
		wynik = 5;
	free(kontynent_duze_litery);
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
	return wynik;
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
