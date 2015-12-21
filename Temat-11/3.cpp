#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

/* funkcja zamieniająca wartość w systemie o dowolnej podstawie na liczbe w systemie dziesiętnym
	a - liczba w postaci łańcucha znakowego
	p - podstawa systemu liczbowego 
	
	Funkcja oczywiście nie obsługuje liter (np w zapisie szesnastkowym), ale system szesnastkowy obsługuje :P
*/
int func(char *a, int p)
{
	int w = 0; /* ważne, żeby wyzerować */
	int n = strlen(a) - 1; /* zapisujemy długość łańcucha */
	for(int i = 0; i <= n; i++) /* odjąłem 1 od n (n = strlen(a) - 1), dlatego dodałem znak '=' w warunku (i <= n) */
	{
		/*
		(a[i]-'0') - zamienia znak na liczbę
		pow(p, n-i) - daje nam odpowiednią potęgę liczby, która jest podstawą. W systemie dziesiętnym, podstawą jest 10,
			dlatego kolejne cyfry w liczbie mnożymy przez potęgę dziesiątki. Tutaj podstawą jest 'p', więc to ją potęgujemy
		W tym przypadku oczywiście też w ciągu poruszamy się od najbardziej znaczącej cyfry (bo od lewej strony),
		więc liczba o indeksie 0 powinna mieć najwyższą potęgę. Stąd zapis "n-i" w "pow(p, n-1)" 
		*/
		
		/* liczba 0.00000001 została dodana, ponieważ pow nie radzi sobie z potęgowaniem dziesiątki.
			Raczej nie trzeba tego wiedzieć, ale wynik wychodził czasami błędny (przy próbie zamiany
			na system dziesiętny [wiem, że bez sensu - z dziesiętnego na dziesiętny :D]).
		*/
		
		w += (a[i]-'0') * (pow(p, n-i)+0.00000001);
	}
	return w;
}

int main()
{
	printf("%d\n", func("555", 8));
	system("pause");
	return 0;
}
