#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* w tej bibliotece znajduje sie funkcja strlen() */

void func(char lancuch[256], char wynik[256])
{
	int p = 0; /* aktualny indeks w tablicy "wynik" */
	/* lancuch musimy zapisac od tylu, dlatego jako poczatkowa wartosc "i", podajemy ostatni indeks w lancuchu.
		funkcja strlen() zwraca dlugosc lancucha znakowego. Ostatni indeks to strlen()-1, ze wzgledu na to, ze indeksy zaczynaja sie od 0.
		Nalezy zauwazyc, ze petla musi sie wykonac takze dla i==0, stad znak "=" w warunku (i >= 0) */
	for(int i = strlen(lancuch)-1; i >= 0; i--)
	{
		/* sprawdzamy, czy znak jest w przedziale a-z (male litery) */
		if(lancuch[i] >= 'a' && lancuch[i] <= 'z')
			/* jesli tak - zmieniamy male litery na duze.
				W tablicy ASCII duze litery maja indeks o 32 mniejszy, niz male, wiec mozemy latwo je zamienic */
			wynik[p] = lancuch[i] - 32;
		else
			/* jesli znak nie jest mala litera, po prostu kopiujemy znak */
			wynik[p] = lancuch[i];
		/* zwiekszamy indeks tablicy "wynik" */
		p++;
	}
}

int main()
{
	/* otwieramy plik "dane.txt" do odczytu */
	FILE *file = fopen("Dane.txt", "rt");
	
	if(!file) { /* jesli file==0 (wystapil blad przy probie otwarcia pliku */
		printf("Nie mozna otworzyc pliku 'Dane.txt'\n");
		system("pause");
		return 0;
	}
	
	char lancuch[256] = {0}; /* tablica na lancuch znakow pobrany z pliku */
	char wynik[256] = {0}; /* tablica na lancuch znakow potraktowany nasza funkcja */
	
	/* fgets() zwraca null w przypadku konca pliku, lub w przypadku bledu (null mozna traktowac jako 0),
	 wiec wykonujemy petle, dopoki  fgets() zwraca cos roznego od 0 */
	while(fgets(lancuch, 256, file))
	{
		/* w tablicy "lancuch" mamy wczytana linie z pliku, wiec przekazujemy ja jako pierwszy argument naszej funkcji.
		 Drugi argument to tablica, do ktorej zostanie zapisany zmieniony lancuch znakow */
		func(lancuch, wynik);
		/* wypisujemy ciag znakow w konsoli */
		printf("%s", wynik);
	}
	printf("\n");
	
	system("pause");
	return 0;
}
