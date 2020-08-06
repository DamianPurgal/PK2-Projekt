#ifndef STRUKTURY_H
#define STRUKTURY_H
typedef struct lista_lotow
{
	int dzien;
	int miesiac;
	int rok;
	char* kraj_poczatkowy;
	char* kraj_koncowy;
	int godziny_lotu;
	int minuty_lotu;
	int mile_lotu;
	struct lista_lotow* next;
}lista_lotow;
typedef struct lista_pracownikow
{
	char* imie;
	char* nazwisko;
	char* stanowisko;
	struct lista_pracownikow* next;
	lista_lotow* loty;
}lista_pracownikow;

#endif
