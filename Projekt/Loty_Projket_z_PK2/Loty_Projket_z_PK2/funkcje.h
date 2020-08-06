#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "struktury.h"

int jakiKontynent(char* kraj);
void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik);
void wyswietl_liste_pracownikow(lista_pracownikow* pHead);
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot);
void wyswietl_liste_lotow(lista_lotow* pHead);
void usun_liste_pracownikow(lista_pracownikow** pHead);
void usun_liste_lotow(lista_lotow** pHead);
lista_pracownikow* wczytaj_dane_z_pliku(char* nazwa_pliku);
char* wczytaj_napis(FILE* plik);
int napis_na_liczbe(char* napis);
#endif