#include <stdio.h>
#include <stdlib.h>

float func(float a[20], int N, float x)
{
	float w[2]; /* ta tablica bedzie przechowywac wartosci w[0] = Wi, w[1] = Wi+1, potrzebne we wzorze */
	w[0] = a[N-1]; /* W1 = aN (w tresci zadania) */
	for(int i = 1; i < N; i++) /* zaczynamy od i=1, poniewaz pierwsza wartosc juz mamy obliczona linijke wyzej */
	{
		w[1] = w[0]*x + a[N-i-1]; /* po prostu podstawiamy do wzoru z tresci zadania (Wi+1 = Wix + aN-1),
										pamietajac, ze my zaczynamy indeksowanie od 0 */
		w[0] = w[1]; /* przepisujemy wartosc, poniewaz w polu w[0] musimy trzymac wartosc poprzedniego wyrazenia */
	}
	/* zwracamy wynik */
	return w[1];
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
