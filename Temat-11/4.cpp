#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>

/* funkcja obliczająca iloczyn macierzy
	m1w oraz m1h to szerokość oraz wysokość pierwszej macierzy.
	m2w oraz m2h to szerokość oraz wysokość drugiej macierzy.
	mw i mh to wysokość i szerokość macierzy wynikowej. Zapisałem, jako referencja, żeby użytkownik po obliczeniu
	iloczynu mógł również odczytać rozmiar macierzy.
	
	UWAGA:
		szerokość to liczba kolumn.
		wysokosc to liczba wierszy
		oraz
		tablice są zapisywane tak, że dla type[i][j], i oznacza ilość wierszy, natomiast j ilość składowych wiersza (czyli ilość kolumn)
		tak więc:
		
		m1w - liczba kolumn
		m1h - liczba wierszy
		
		analogicznie dla pozostałych
*/
void func(int M1[50][50], int m1w, int m1h, int M2[50][50], int m2w, int m2h, int M[50][50], int &mw, int &mh)
{
	/* macierz wynikowa będzie miała szerokość równą szerokości DRUGIEJ macierzy */
	mw = m2w;
	/* oraz wysokość równą wysokości PIERWSZEJ macierzy */
	mh = m1h;
	
	/* jeśli szerokość pierwszej i wysokość drugiej macierzy nie są sobie równe, nie da się obliczyć iloczynu */
	if(m1w != m2h) {
		/* wypisujemy błąd */
		printf("Blad !\n");
		/* wychodzimy z funkcji */
		return;
	}
	
	/* Każdy element a(i,j) macierzy wynikowej jest równy iloczynowi skalarnemu i-tego wiersza pierwszej macierzy
		i j-tej kolumny drugiej macierzy, więc możemy po prostu przejść po całej macierzy wynikowej (bo znamy jej rozmiar)
		i dla każdego elementu obliczyć jego wartość */
	for(int i = 0; i < mh; i++) /* przejście po wszystkich wierszach macierzy wynikowej */
	{
		for(int j = 0; j < mw; j++) /* przejście po wszystkich elementach wiersza macierzy wynikowej */
		{
			/* w tym momencie M[i][j] oznacza każdy element macierzy wynikowej.
			 Iloczyn skalarny to suma iloczynów kolejnych składowych obu wektorów.
			 Dla nas pierwszym wektorem jest wiersz o indeksie i pierwszej macierzy, czyli elementy M1[i][n]
			 natomiast drugim wektorem jest kolumna o indeksie j drugiej macierzy, czyli elementy M2[n][j]
			 n = m1w = m2h oraz jest rozmiarem obu wektorów. Jeśli jest inaczej, funkcja wcześniej wypisze błąd.
			*/
			M[i][j] = 0; /* zerujemy element, ponieważ będziemy tu zapisywać sumę */
			for(int k = 0; k < m1w; k++) /* dla każdej składowej wektorów, z których liczymy iloczyn skalarny */
			{
				M[i][j] += M1[i][k] * M2[k][j]; /* to już powinno być jasne */
			}
		}
	}
}

/* pomocnicza funkcja wypisująca macierz na ekranie */
void printMatrix(int M[50][50], int w, int h)
{
	for(int i = 0; i < w; i++)
	{
		for(int j = 0; j < h; j++)
		{
			printf("%d\t", M[i][j]); /* '\t' oznacza tabulator */
		}
		printf("\n");
	}
}

int main()
{
	srand(time(0));
	
	int M1[50][50], M2[50][50], M[50][50];
	int w, h,
		m1w = 2, m1h = 3, /* rozmiar pierwszej macierzy */
		m2w = 3, m2h = 2; /* rozmiar drugiej macierzy */
	
	/* wypełniamy liczbami losowymi obie macierze, które będziemy mnożyć */
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			M1[i][j] = rand()%100;
			M2[i][j] = rand()%100;
		}
	}
	
	/* wywołujemy funkcję. Argumenty w i h to referencje, więc po wyjściu z funkcji rozmiar macierzy wynikowej będziemy mieli zapisany w tych zmiennych */
	func(M1, m1w, m1h, M2, m2w, m2h, M, w, h);
	
	printf("M1:\n");
	printMatrix(M1, m1w, m1h);
	printf("\n\n");
	
	printf("M2:\n");
	printMatrix(M2, m2w, m2h);
	printf("\n\n");
	
	printf("M:\n");
	printMatrix(M, w, h);
	printf("\n\n");
	
	system("pause");
	return 0;
}
