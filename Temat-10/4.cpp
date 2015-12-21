#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* funkcja zapisuje do zmiennej 'minmax' najmniejsza, lub najwieksza wartosc w tablicy M.
	Dodatkowo, poczatkowa wartosc zmiennej 'minmax' okresla, czy funkcja ma szukac najmniejszej, czy najwiekszej wartosci.
	Jesli wywolamy funkcje z tym argumentem rownym 0, funkcje bedzie szukac wartosci najmniejszej. W innym przypadku najwiekszej.
	
	Do tablicy pos[2] zostanie zapisana pozycja pierwszego/ostatniego wystapienia szukanej liczby.
	Jesli poczatkowa wartosc pos[0] jest rowna 0, zapisna zostanie pozycja pierwszego wystapienia wartosci szukanej. W innym przypadku
	- pozjca ostatniego wystapienia.
*/
void func(int M[20][20], int N, int &minmax, int pos[2])
{
	/* tworzymy nowe zmienne na najwieksza/najmniejsza wartosc oraz pozycje jej wystapienia, 
		poniewaz argumenty funkcji 'minmax' oraz 'pos' trzymaja nam jeszcze informacje o tym, jak funkcja ma dzialac, wiec
		nie mozemy tych wartosci zmieniac */
	int a = M[0][0]; /* ustawiamy szukana wartosc na pierwsza wartosc w tablicy, zeby miec z czym pozniej porownywac kolejne wartosci */
	int b[2] = { 1, 1 }; /* ustawiamy pozycje na (1, 1), poniewaz jesli tylko na pierwszym miejscu bedzie szukana wartosc, to ta pozycja
							zostanie zwrocona */
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(minmax == 0) /* 'minmax' == 0 oznacza, ze szukamy wartosci najmniejszej */
			{
				if(M[i][j] == a) /* jesli aktualna liczba jest rowna szukanej, musimy sprawdzic, czy zapisac jej pozycje */
				{
					if(pos[0] != 0) /* jesli 'pos[0]' != 0, znaczy, ze szukamy ostatniego wystapienia szukanej wartosci, dlatego zapisujemy pozycje
										kolejnych wartosci */
					{
						b[0] = i + 1;
						b[1] = j + 1;
					}
				}
				if(M[i][j] < a) /* wiec jesli aktualna wartosc w tablicy jest mniejsza, niz do tej pory najmniejsza */
				{
					/* ustawiamy nowa najmniejsza */
					a = M[i][j];
					/* oraz pozycje tej liczby */
					b[0] = i + 1;
					b[1] = j + 1;
				}
			}
			else /* 'minmax' != 0 oznacza, ze szukamy wartosci najwiekszej */
			{
				if(M[i][j] == a) /* jesli aktualna liczba jest rowna szukanej, musimy sprawdzic, czy zapisac jej pozycje */
				{
					if(pos[0] != 0) /* jesli 'pos[0]' != 0, znaczy, ze szukamy ostatniego wystapienia szukanej wartosci, dlatego zapisujemy pozycje
										kolejnych wartosci */
					{
						b[0] = i + 1;
						b[1] = j + 1;
					}
				}
				if(M[i][j] > a) /* wiec jesli aktualna wartosc w tablicy jest wieksza, niz do tej pory najwieksza */
				{
					/* ustawiamy nowa najwieksza */
					a = M[i][j];
					/* oraz pozycje tej liczby */
					b[0] = i + 1;
					b[1] = j + 1;
				}
			}
		}
	}
	
	/* ostatecznie zapisujemy szukana wartosc oraz pozycje do naszych zmiennych */
	minmax = a;
	pos[0] = b[0];
	pos[1] = b[1];
}

int main()
{
	srand(time(0));
	
	int M[20][20],
		N = 4,
		minmax = 0, /* do tej zmiennej zostanie zapisana najwieksza/najmniejsza liczba w tablicy. */
		pos[2] = { 0, 0 }; /* tutaj zapisana zostanie pozycja pierwszego/ostatniego wysatpienia najmniejszej/najwiekszej liczby. */
	
	/* wypelniamy tablice losowymi wartosciami i wypisujemy je na ekran */
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			M[i][j] = rand()%10;
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	
	/* Dwa ostatnie argumenty funkcji to int(z referencja) oraz int[2]. Referencja oznacza, ze normalnie przekazujemy zmienna do funkcji, ale
		jesli funkcja zmieni jej wartosc, zmieni sie tez wartosc zmiennej, ktora przekazalismy do funkcji. Dokladnie tak, jak w przypadku wskaznikow (czyli funkcji tez) */
	func(M, N, minmax, pos);
	
	printf("minmax = %d\n", minmax);
	printf("pos = (%d, %d)\n", pos[0], pos[1]);
	
	system("pause");
	return 0;
}
