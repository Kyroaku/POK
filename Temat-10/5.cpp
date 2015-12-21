#include <stdio.h>
#include <stdlib.h>

int func(char *L, char *L1)
{
	int n = 0; /* ilosc wystapien ciagu L1 w ciagu L */
	int i = 0; /* indeks w tablicy ciagu L */
	/* generalnie chcemy przejsc po calym ciagu L, sprawdzajac, czy pierwszy znak ciagu L1 pokrywa sie z aktualnym znakiem w ciagu L.
		Jesli tak - wykonujemy proste sprawdzenie, czy ciagi sa takie same. Otoz jesli choc jeden znak w nich sie rozni, to caly ciag sie rozni.
		Przechodzimy wiec wtedy po calym ciagu L1, jednoczesnie idac dalej w ciagu L i sprawdzamy kolejne znaki. Jesli ktorys sie rozni, ustawiamy
		nasza zmienna pomocnicza bool na false i konczymy sprawdzanie.
		Jesli zaden sie nie rozni, a przeszlismy caly ciag L1, program wyjdzie z petli, nie zmieniajac zmiennej bool na false, wiec juz latwo mozemy sprawdzic,
		czy znalezlismy ciag.
		
		Dodatkowo, jesli sprawdzane znaki sie roznia, trzeba jeszcze sprawdzic, czy moze ten "bledny" znak nie jest czasem pierwszym znakiem ciagu L1,
		co by znaczylo, ze potencjalnie jest pierwszym znakiem szukanego ciagu. Stad warunek "if(j == 0) i++;" Polecam przeanalizowac ta petle krok po kroku
		na kartce, albo debuggerem. Wtedy wszystko na pewno bedzie jasne ;)
	*/
	while(L[i] != '\0') /* dopoki w ciagu L nie natrafimy na znak '\0' (koniec lancucha) */
	{
		bool wystapil = true; /* ta zmienna pomoze nam sprawdzic, czy znalezlismy ciag znakow */
		
		for(int j = 0; L1[j] != '\0'; j++) /* lecimy po calym lancuchu L1 */
		{
			if(L[i] != L1[j]) { /* jesli choc jeden znak sie rozni, to znaczy, ze caly ciag sie rozni */
				wystapil = false; /* ustawiamy nasza zmienna na false, co oznacza, ze ciagi sie roznia */
				if(j == 0) /* inkrementujemy indeks ciasgu L, ale tylko wtedy, kiedy j==0, czyli sprawdzamy pierwszy znak ciagu L1. Gdyby tego warunku nie bylo,
							program by sie zapetlil w nieskonczonosc */
					i++;
				break; /* wychodzimy z petli */
			}
			i++; /* inkrementujemy indeks tablicy L */
		}
		
		if(wystapil) /* jesli zmienna 'wystapil' nie zostala zmieniona na false, to znaczy, ze znalezlizmy ciag L1 w ciagu L */
			n++; /* inkrementujemy liczbe wystapien */
	}
	return n; /* zwracamy liczbe wystapien */
}

int main()
{
	/* L - ciag znakow, w ktorym bedziemy szukac.
		L1 - ciag znakow, ktorego szukamy w L */
	char L[256], L1[256];
	printf("Podaj lancuch: ");
	scanf("%s", L);
	printf("Podaj lancuch szukany: ");
	scanf("%s", L1);
	
	printf("Lancuch L1 wyspil w lancuchu L %d razy\n", func(L, L1));
    
    system("pause");
    return 0;
}
