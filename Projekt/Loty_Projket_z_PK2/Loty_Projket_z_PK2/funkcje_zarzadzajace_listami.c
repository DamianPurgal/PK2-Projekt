#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struktury.h"
#include "funkcje_zarzadzajace_listami.h"
#include "funkcje_pomocnicze.h"

void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik)
{
	(*pracownik)->next = *pHead;
	*pHead = *pracownik;
}
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot)
{
	(*lot)->next = *pHead;
	*pHead = *lot;
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
int ilosc_elementow_w_liscie_pracownikow(lista_pracownikow* pHead)
{
	int wynik = 0;
	while (pHead != NULL)
	{
		wynik++;
		pHead = pHead->next;
	}
	return wynik;
}
lista_pracownikow* znajdz_pracownika_w_liscie(lista_pracownikow* pHead, char* imie, char* nazwisko)
{
	char* imie_duze_litery = lancuch_znakow_na_duze_litery(imie);
	char* nazwisko_duze_litery = lancuch_znakow_na_duze_litery(nazwisko);
	char* t_imie;
	char* t_nazwisko;
	while (pHead != NULL)
	{
		t_imie = lancuch_znakow_na_duze_litery(pHead->imie);
		t_nazwisko = lancuch_znakow_na_duze_litery(pHead->nazwisko);
		if (strcmp(t_imie, imie_duze_litery) == 0 && strcmp(t_nazwisko, nazwisko_duze_litery) == 0)
		{
			free(t_imie);
			free(t_nazwisko);
			break;
		}
		pHead = pHead->next;
		free(t_imie);
		free(t_nazwisko);
	}
	free(imie_duze_litery);
	free(nazwisko_duze_litery);
	return pHead;
}