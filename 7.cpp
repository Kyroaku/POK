#include <stdio.h>
#include <stdlib.h>

/* funkcja zwracajaca wartosc n! */
int func(int n)
{
	/* liczymy iloczyn, wiec wartosc poczatkowa musi byc rowna 1 */
	int w = 1;
	/* n! = 1*2*3*...*n, dlatego "i" ustawiamy poczatkowo na 1 (zeby nie mnozyc zera).
		Poniewaz zaczynamy od 1, a chcemy wykonac petle n-razy, musimy wykonywac petle, dopoki (i < n+1), czyli mozna zapisac (i <= n) */
	for(int i = 1; i <= n; i++)
		w *= i;
	return w;
}

/* a tutaj ta sama funkcja rekurencyjnie */
int func2(int n)
{
	/* Nie chcemy mnozyc zera, ani liczb ujemnych, dlatego kiedy dojdziemy do 0, nie wywolujemy juz funkcji po raz kolejny, tylko
		po prostu zwracamy 1 (element neutralny). Rekurencja sie wtedy skonczy */
	if(n > 0) 	return n*func(n-1);
	else		return 1;
	
	/* przyklad:
	
	dla n = 4
	
	func(4) = 4*func(3)
	func(3) = 3*func(2)
	func(2) = 2*func(1)
	func(1) = 1*func(0)
	func(0) = 1;
	
	func(4):
	1) return 4*func(3)
	2) return 4*3*func(2)
	3) return 4*3*2*func(1)
	4) return 4*3*2*1*func(0)
	5) return 4*3*2*1*1
	
	*/
}

int main()
{
	/* pobieramy dane */
	int n;
	printf("Podaj n: ");
	scanf("%d", &n);
	
	/* wypisujemy wyniki */
	printf("n! (iteracyjnie) = %d\n", func(n));
	
	printf("n! (rekurencyjnie) = %d\n", func2(n));
	
	system("pause");
	return 0;
}
