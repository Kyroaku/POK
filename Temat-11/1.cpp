#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

/* funkcja zamieniająca ciąg znaków na liczbę */
int func(char *arr)
{
	int w = 0; /* nasza zmienna, przechowująca wartość szukanej liczby */
	for(int i = 0; i < strlen(arr); i++) /* przechodzimy przez caly ciąg ( strlen() zwraca długość ciągu ) */
	{
		/* wzór dla "1234":
			1 * 10^3 + 2 * 10^2 + 3 * 10^1 + 4 * 10^0
			(arr[i]-'0') - daje nam wartość znaku (tzn zamienia '1' na 1). Odejmujemy '0', ponieważ
			cyfry w tablicy ASCII ustawione są kolejno, zaczynając od indeksu 48 (dla zera).
			Jeśli więc od znaku cyfry (przykładowo '5') odejmiemy '0' (czyli 48), otrzymamy 5. (indeks '5' to 53. 53-48 = 5)
			pow(10, strlen(arr)-i-1) daje nam potęgę dziesiątki, zależnie od pozycji w ciągu.
			ponieważ indeks zero jest "najbardziej znaczący", musimy potęgę brać "od końca"
			strlen(arr)-i-1 zamieni nam indeks tak, żeby nie szedł od 0 do n, ale od n do 0. 
		*/
		w += (arr[i]-'0') * pow(10, strlen(arr)-i-1);
	}
	/* zwracamy wynik */
	return w;
}

int main()
{
	printf("%d\n", func("1234"));
	system("pause");
	return 0;
}
