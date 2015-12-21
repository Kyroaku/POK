#include <stdio.h>
#include <stdlib.h>

/* funkcja zwracajaca wartosc x^p */
float func(float x, int p)
{
	float w = 1.0; /* wynik bedzie iloczynem, dlatego musimy ustawic poczatkowa wartosc na 1 */
	/* p razy mnozymy w przez x */
	for(int i = 0; i < p; i++)
		w *= x;
	return w;	
}

int main()
{
	/* pobieramy dane */
	float x;
	int p;
	printf("Podaj x: ");
	scanf("%f", &x);
	printf("Podaj p: ");
	scanf("%d", &p);
	
	/* wypisujemy zwrocona wartosc na ekran.
		Funkcja traktowana jest jako wartosc, ktora zwraca, dlatego nie trzeba wykorzystywac dodatkowej zmiennej
		do zapisania wyniku dzialania funkcji */
	printf("x^p = %f\n", func(x, p));
	
	system("pause");
	return 0;
}
