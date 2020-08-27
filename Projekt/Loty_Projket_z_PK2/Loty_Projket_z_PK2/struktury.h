#ifndef STRUKTURY_H
#define STRUKTURY_H
/**
  Struktura przechowuj�ca dat�
 */
typedef struct data
{
	int dzien;	/**< Zmienna przechowuj�ca dzie� */
	int miesiac;/**< Zmienna przechowuj�ca miesi�c */
	int rok;	/**< Zmienna przechowuj�ca rok */
}data;
/**
  Struktura przechowuj�ca list� jednokierunkow� lot�w
 */
typedef struct lista_lotow
{
	data data;					/**< Zmienna przechowuj�ca dat� */
	char* kraj_poczatkowy;		/**< Zmienna przechowuj�ca nazw� kraju pocz�tkowego */
	char* kraj_koncowy;			/**< Zmienna przechowuj�ca nazw� kraju ko�cowego */
	int godziny_lotu;			/**< Zmienna przechowuj�ca godziny lotu */
	int minuty_lotu;			/**< Zmienna przechowuj�ca minuty lotu */
	int mile_lotu;				/**< Zmienna przechowuj�ca mile lotu*/
	struct lista_lotow* next;	/**< Zmienna przechowuj�ca wska�nik na kolejny element w li�cie*/
}lista_lotow;
/**
  Struktura przechowuj�ca list� jednokierunkow� pracownik�w i ich lot�w
 */
typedef struct lista_pracownikow
{
	char* imie;						/**< Zmienna przechowuj�ca imi� */
	char* nazwisko;					/**< Zmienna przechowuj�ca nazwisko */
	char* stanowisko;				/**< Zmienna przechowuj�ca stanowisko */
	struct lista_pracownikow* next;	/**< Zmienna przechowuj�ca wska�nik na kolejny element w li�cie*/
	lista_lotow* loty;				/**< Zmienna przechowuj�ca wska�nik na g�ow� listy lot�w */
}lista_pracownikow;
/**
  Struktura przechowuj�ca argumenty pozwalaj�ce wyszuka� odpowiednie zestawienie
 */
typedef struct argumenty
{
	char* plik_odczyt;	/**< Zmienna przechowuj�ca nazw� pliku do odczytu */
	char* typ;			/**< Zmienna przechowuj�ca nazw� typu zestawienia */
	char* imie;			/**< Zmienna przechowuj�ca imi� */
	char* nazwisko;		/**< Zmienna przechowuj�ca nazwisko */
	char* kontynent;	/**< Zmienna przechowuj�ca nazw� kontynentu */
	data dataOd;		/**< Zmienna przechowuj�ca date od kt�rej wyszukiwane s� dane */
	data dataDo;		/**< Zmienna przechowuj�ca date do kt�rej wyszukiwane s� dane */
}argumenty;
#endif
