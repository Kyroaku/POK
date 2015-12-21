#include <stdio.h>
#include <stdlib.h>

void func(int M[20][20], int N, int R[20][20])
{
	for(int i = 0; i < N; i++) /* dla kazdego wiersza */
	{
		for(int j = 0 ; j < N; j++) /* dla kazdej skladowej wiersza i */
		{
			R[i][j] = M[j][i]; /* zamieniamy wiersze z kolumnami i zapisujemy wynik do tablicy R */
		}
	}
	/* R jest wskaznikiem (poniewaz tablica to wskaznik), a wiec zmiany beda "zapamietane" na zewnatrz funkcji */
}

int main()
{
	int M[20][20],
		N,
		R[20][20];
	
	printf("Podaj N: ");
	scanf("%d", &N);
	
	/* wypelniamy macierz losowymi wartosciami z zakresu 0-9 i przy okazji wyswietlamy macierz na ekranie */
	for(int i = 0; i < N; i++) {
		for(int j = 0 ; j < N; j++) {
			M[i][j] = rand()%10;
			printf("%d ", M[i][j]);
		}
		printf("\n"); /* po wypisaniu calego wiersza trzeba przejsc do kolejnej linijki */
	}
	printf("\n\n");
	
	/* Jako argument podajemy tablice R, w ktorej zapisana zostanie transponowana macierz M */
	func(M, N, R);
	
	/* podobnie, jak wczesniej, wypisujemy macierz na ekran. Tym razem macierz R */
	for(int i = 0; i < N; i++) {
		for(int j = 0 ; j < N; j++) {
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}
