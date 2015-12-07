#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* funkcja wyznaczajaca wyznacznik macierzy 2x2 (z pierwszego zadania) */
float det(float a, float b, float c, float d)
{
	return a*c - b*d;
}

/* funkcja z tresci zadania */
float f(float x, float y)
{
	/* "eps" jest potrzebny, poniewaz dla liczb zmienno-przecinkowych 0 != 0 przez to, ze typy takich zmiennych maja ograniczona dokladnosc.
	Przykladowo dla typu float, kazda cyfra po szostej po przecinku, to bedzie bzdura. */
	float eps = 0.000001;
	if(x < y-eps) /* x < y */
		return 2.0*x + 2.0*y;
	else if(x < y+eps) /* x == y */
		return 3.0;
	else /* x > y */
		return x*x - sin(y);
	
	/* mozna by warunki zapisac tez tak: */
	/*
	
	if(x < y-eps) // x < y 
		return 2.0*x + 2.0*y;
	if(x >= y-eps && x <= y+eps) // x == y 
		return 3.0;
	if(x > y+eps) // x > y 
		return x*x - sin(y);
	
	*/
	/* ale ten sposob jest lamerski */
}

int main()
{
	/* pobieramy potrzebne dane */
    float x0, y0, dx, dy;
    int Np, Nk;
    printf("Podaj x0: ");
    scanf("%f", &x0);
    printf("Podaj y0: ");
    scanf("%f", &y0);
    printf("Podaj dx: ");
    scanf("%f", &dx);
    printf("Podaj dy: ");
    scanf("%f", &dy);
    printf("Podaj Np: ");
    scanf("%d", &Np);
    printf("Podaj Nk: ");
    scanf("%d", &Nk);
    
    /* liczymy sume, wiec trzeba wyzerowac wczesniej zmienna */
    float wynik = 0;
    for(int i = Np; i<= Nk; i++)
    {
    	/* dodajemy do naszej zmiennej wynik dzialania funkcji f (wartosc zwracana przez ta funkcje) */
		wynik += f(x0 + i*dx, y0 - i*dy);
	}
	printf("y = %f\n", wynik);
    
    system("pause");
    return 0;
}
