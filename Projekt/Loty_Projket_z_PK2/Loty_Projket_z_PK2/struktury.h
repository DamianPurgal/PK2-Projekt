#ifndef STRUKTURY_H
#define STRUKTURY_H
/**
  Struktura przechowuj¹ca datê
 */
typedef struct data
{
	int dzien;	/**< Zmienna przechowuj¹ca dzieñ */
	int miesiac;/**< Zmienna przechowuj¹ca miesi¹c */
	int rok;	/**< Zmienna przechowuj¹ca rok */
}data;
/**
  Struktura przechowuj¹ca listê jednokierunkow¹ lotów
 */
typedef struct lista_lotow
{
	data data;					/**< Zmienna przechowuj¹ca datê */
	char* kraj_poczatkowy;		/**< Zmienna przechowuj¹ca nazwê kraju pocz¹tkowego */
	char* kraj_koncowy;			/**< Zmienna przechowuj¹ca nazwê kraju koñcowego */
	int godziny_lotu;			/**< Zmienna przechowuj¹ca godziny lotu */
	int minuty_lotu;			/**< Zmienna przechowuj¹ca minuty lotu */
	int mile_lotu;				/**< Zmienna przechowuj¹ca mile lotu*/
	struct lista_lotow* next;	/**< Zmienna przechowuj¹ca wskaŸnik na kolejny element w liœcie*/
}lista_lotow;
/**
  Struktura przechowuj¹ca listê jednokierunkow¹ pracowników i ich lotów
 */
typedef struct lista_pracownikow
{
	char* imie;						/**< Zmienna przechowuj¹ca imiê */
	char* nazwisko;					/**< Zmienna przechowuj¹ca nazwisko */
	char* stanowisko;				/**< Zmienna przechowuj¹ca stanowisko */
	struct lista_pracownikow* next;	/**< Zmienna przechowuj¹ca wskaŸnik na kolejny element w liœcie*/
	lista_lotow* loty;				/**< Zmienna przechowuj¹ca wskaŸnik na g³owê listy lotów */
}lista_pracownikow;
/**
  Struktura przechowuj¹ca argumenty pozwalaj¹ce wyszukaæ odpowiednie zestawienie
 */
typedef struct argumenty
{
	char* plik_odczyt;	/**< Zmienna przechowuj¹ca nazwê pliku do odczytu */
	char* typ;			/**< Zmienna przechowuj¹ca nazwê typu zestawienia */
	char* imie;			/**< Zmienna przechowuj¹ca imiê */
	char* nazwisko;		/**< Zmienna przechowuj¹ca nazwisko */
	char* kontynent;	/**< Zmienna przechowuj¹ca nazwê kontynentu */
	data dataOd;		/**< Zmienna przechowuj¹ca date od której wyszukiwane s¹ dane */
	data dataDo;		/**< Zmienna przechowuj¹ca date do której wyszukiwane s¹ dane */
}argumenty;
#endif
