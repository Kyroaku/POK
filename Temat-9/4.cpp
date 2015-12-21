#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Funkcja zwracajaca najwiekszy element tablicy */
int func(int tab[100], int N)
{
	/* ustawiamy max na pierwszy element tablicy, zeby miec co porownywac w petli */
	int max = tab[0];
	/* pierwszy element juz zapisalismy, wiec zaczynamy petle od 1, a nie od 0 */
	for(int i = 1; i < N; i++)
	{
		/* sprawdzamy, czy element jest wiekszy, niz najwiekszy do tej pory */
		if(tab[i] > max)
			max = tab[i];
	}
	/* zwracamy zmienna "max" */
	return max;
}

int main()
{
	/* ustawiamy seed'a dla funkcji rand() */
	srand(time(0));
	int N; /* ilosc elementow w tablicy */
	int tablica[100];
	/* pobieramy ilosc elementow z klawiatury */
	printf("Podaj ilosc elementow: ");
	scanf("%d", &N);
	
	/* wypelniamy N poczatkowych elementow tablicy wartosciami pseudo-losowymi */
	for(int i = 0; i < N; i++)
	{
		tablica[i] = rand() % 1000;
		printf("%d\n", tablica[i]);
	}
	
	/* przekazujemy do funkcji tablice, ktora wypelnilismy oraz ilosc elementow, ktorych faktycznie uzywamy.
		Funkcja zwroci nam najwiekszy element tablicy, wiec zapisujemy ta wartosc do zmiennej "max" */
	int max = func(tablica, N);
	
	printf("max: %d\n", max);
	
	system("pause");
	return 0;
}
