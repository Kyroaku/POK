#include <stdio.h>
#include <stdlib.h>

float func(float a[20], int N, float x)
{
	float w;
	w = a[N-1]; /* W1 = aN (w tresci zadania) */
	for(int i = 1; i < N; i++) /* zaczynamy od i=1, poniewaz pierwsza wartosc juz mamy obliczona linijke wyzej */
	{
		w = w*x + a[N-i-1]; /* po prostu podstawiamy do wzoru z tresci zadania (Wi+1 = Wix + aN-1),
										pamietajac, ze my zaczynamy indeksowanie od 0 */
		/* w tym momencie zmienna 'w' przechowuje nam wartosc poprzednia (Wi) i mozemy ja wykorzystac do obliczenia nowej wartosci
		    w tej samej zmiennej */
	}
	/* zwracamy wynik */
	return w;
}

int main()
{
	float a[20]; /* tablica wspolczynnikow */
	int N; /* stopien wielomianu */
	float x; /* wartosc x, dla ktorej szukamy wartosci wielomianu W(x) */
	
	/* wypelniamy tablice wspolczynnikow wartosciami losowymi z zakresu 0-9 */
	for(int i = 0; i < 20; i++) {
		a[i] = (int)(rand()%10);
	}
	
	/* pobieramy potrzebne dane */
	printf("Podaj N: ");
	scanf("%d", &N);
	printf("Podaj x: ");
	scanf("%f", &x);
	
	/* liczymy W(x) za pomoca naszej funkcji */
	float w = func(a, N, x);
	
	printf("w = %f\n", w);
	
	system("pause");
	return 0;
}
