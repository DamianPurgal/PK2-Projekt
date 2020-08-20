#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "struktury.h"

int jaki_kontynent(char* kraj);
int kontynent_na_liczbe(char* kontynent);
char* liczba_na_kontynent(int a);
int napis_na_liczbe(char* napis);
char* lancuch_znakow_na_duze_litery(char* a);
int ilosc_elementow_w_liscie_pracownikow(lista_pracownikow* pHead);
int porownaj_daty(data a, data b);
void dodaj_pracownika_do_listy(lista_pracownikow** pHead, lista_pracownikow** pracownik);
void dodaj_lot_do_listy(lista_lotow** pHead, lista_lotow** lot);
void wyswietl_liste_pracownikow(lista_pracownikow* pHead);
void wyswietl_liste_lotow(lista_lotow* pHead, data dataOd, data dataDo);
void wyswietl_zestawienie_lotow_pracownika_do_kontynentow(lista_pracownikow* pHead, data dataOd, data dataDo);
void wyswietl_pracownikow_i_ich_loty(lista_pracownikow* pHead, data dataOd, data dataDo);
void usun_liste_pracownikow(lista_pracownikow** pHead);
void usun_liste_lotow(lista_lotow** pHead);
lista_pracownikow* wczytaj_dane_z_pliku(char* nazwa_pliku);
char* wczytaj_napis(FILE* plik);
void wyswietl_zestawienie_lotow_pracownikow_do_kontynentu(lista_pracownikow* pHead, data dataOd, data dataDo, char* kontynent);
#endif