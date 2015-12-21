#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* funkcja zamieniająca liczbę na liczbę binarną w postaci ciągu znakowego */
void func(int a, char *arr)
{
	for(int i = 0; a > 0; i++) /* dopóki (a > 0) */
	{
		arr[i] = a%2 + '0'; /* bierzemy resztę z dzielenia przez 2 (więc dostajemy 0, lub 1)
								i dodajemy '0' (więc dostajemy '0', lub '1') */
		a/=2; /* dzielimy przez 2, bo tak trzeba ;) */
	}
	/* dalsza część kodu to odwrócenie ciągu znaków, który otrzymaliśmy, ponieważ liczby binarne zapisuje się 
		z najmniej znaczącym bitem z prawe strony (my mamy go z lewej) */
	int n = strlen(arr); /* pobieramy długość ciągu */
	for(int i = 0; i < n/2; i++) /* idziemy po tym ciągu tylko do połowy,
									ponieważ inaczej odwrócilibyśmy ciąg 2 razy (czyli wcale) */
	{
		char t = arr[i]; /* zapisujemy znak, żeby się nie zgubił */
		/* 2 kolejne linijki to po prostu zamiana znaków. indeks 'i' jest kolejnym indeksem, natomiast 'n-i-1'
			jego tak jakby odbiciem (tzn indeksem, który porusza się od tyłu */
		arr[i] = arr[n-i-1];
		arr[n-i-1] = t;
	}
}

int main()
{
	char arr[256];
	func(43, arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
