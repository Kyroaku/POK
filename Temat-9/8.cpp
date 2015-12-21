#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* pozmienialem typy na double, zeby uzystac wiekszy zakres liczb */

/* funkcja z zadania 6 */
double funcPotega(double x, double p)
{
	float w = 1.0;
	for(int i = 0; i < p; i++)
		w *= x;
	return w;	
}

/* funkcja z zadania 7 */
double funcSilnia(double n)
{
	if(n > 0) 	return n*funcSilnia(n-1);
	else		return 1;
}

/* funkcja obliczajaca e^x [ exp(x) ] */
double funcExp(float x, int N)
{
	/* liczymy sume, wiec ustawiamy wartosc poczatkowa na 0 */
	double suma = 0.0;
	/* tu wszystko powinno byc jasne */
	for(int i = 0; i <= N; i++)
	{
		suma += funcPotega(x, i) / funcSilnia(i);
	}
	return suma;
}

int main()
{
	/* pobieramy dane */
	int Nmax;
	float x;
	printf("Podaj Nmax: ");
	scanf("%d", &Nmax);
	printf("Podaj x: ");
	scanf("%f", &x);
	
	printf("funcExp(x, Nmax) = %lf\n", funcExp(x, Nmax));
	printf("exp(x) = %lf\n", exp(x));
	
	system("pause");
	return 0;
}
