#include <stdio.h>
#include <stdlib.h>

void func(float a, float b, float c, float w[2])
{
	float delta = b*b - 4*a*c; /* zwykly wzor na delte */
	w[0] = -b/(2*a); /* wsporzedna x-owa wierzcholka ze wzoru: -b/2a */
	w[1] = -delta/(4*a); /* wspolrzedna y-owa wierzcholka ze wzoru: -delta/4a */
}

int main()
{
	/* pobieramy wspolczynniki dla funkcji kwadratowej w postaci: ax^2 + bx + c */
    float a, b, c;
    printf("Podaj wspolczynniki: ");
    scanf("%f %f %f", &a, &b, &c);
    
    float w[2]; /* wspolrzedne wierzcholka paraboli */
    /* przekazujemy do funkcji wartosci wspolczynnikow a, b, c oraz WSKAZNIK na tablice
		(a konkretniej na pierwszy element tej tablicy) */
	func(a, b, c, w);
    
    printf("w = (%f, %f)\n", w[0], w[1]);
    
    system("pause");
    return 0;
}
