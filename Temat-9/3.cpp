#include <stdio.h>
#include <stdlib.h>

void func(float xp, float xk, float dx)
{
	/* porownujemy tutaj float, wiec znow trzeba uwazac na ograniczona dokladnosc float'ow.
		W tym przypadku chodzi o dzialanie (x <= xk). Gdybysmy potrzebowali tylko (x < xk) nie trzebaby nic robic, ale 
		jesli chcemy dodac jeszcze przypadek dla rownosci, trzeba dodac epsilon */
	float eps = 0.000001;
	/* musimy poruszac sie w przedziale [xp; xk], wiec ustawiamy x na poczatek przedzialu (x = xp) i dodajemy dx, dopoki x <= xk */
	for(float x = xp; x < xk+eps; x+=dx)
	{
		printf("%f, ", x);
	}
	printf("\n");
}

int main()
{
	/* pobieramy potrzebne dane */
	float xp, xk, dx;
	printf("Podaj xp: ");
	scanf("%f", &xp);
	printf("Podaj xk: ");
	scanf("%f", &xk);
	printf("Podaj dx: ");
	scanf("%f", &dx);
	
	/* wywolujemy funkcje */
	func(xp, xk, dx);
	
	system("pause");
	return 0;
}
