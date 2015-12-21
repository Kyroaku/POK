#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
	float min, max;
	srand(time(0)); /* ustawiamy ziarnko zalezne od czasu, zeby funkcja rand() nie zwracala tych samych wartosci */
	
/* ZAPISANIE DO PLIKU "dane.txt" 10 000 losowych liczb rzeczywistych z rozkladu normalnego (Gaussa) */
	FILE *file = fopen("dane.txt", "wt");
	for(int i = 0; i < 10000; i++)
	{
		float x = ( (float)(rand()+1) / (RAND_MAX+1) ); /* losowa liczba z przedzialu (0; 1> */
		float y = ( (float)(rand()+1) / (RAND_MAX+1) ); /* losowa liczba z przedzialu (0; 1> */
		/* transformacja 2 losowych liczb z rozkladu jednorodnego (prostokatnego) w liczbe z rozkladu normalnego (gaussa) */ 
		float z = cos(2*M_PI*y)*sqrt(-2.0*log(x));
		
		/* Przy okazji znajdziemy tez maksymalna i minimalna wartosc w pliku */
		/* jesli to pierwszy przebieg petli, zapisz 'z' jako minimalna i jednoczesnie maksymalna wartosc */
		if(i == 0) { min = max = z; }
		else /* dla kolejnych przebiegow petli */
		{
			/* wiadomo */
			if(z > max) max = z;
			if(z < min) min = z;
		}
		
		fprintf(file, "%f\n", z);
	}
	fclose(file);
	
	printf("min: %f\nmax: %f\n", min, max);
	
/* PODZIAL NA N PRZEDZIALOW 
	wartosci <min; max> trzeba podzielic na N rownych przedzialow */
	/* wczytywanie N z klawiatury */
	int N;
	int ilosc_liczb[10] = { 0 }; /* tablica przechowujaca ilosc liczb w poszczegolnych przedzialach (przedzialow moze byc maksymalnie 10) */
	printf("Podaj N: ");
	scanf("%d", &N);
	
	/* otwieramy plik "dane.txt" do odczytu */
	file = fopen("dane.txt", "rt");
	/* dopoki nie ma konca pliku */
	while(!feof(file))
	{
		/* wczytujemy liczbe z pliku "dane.txt" */
		float x;
		fscanf(file, "%f\n", &x);
		/* sprawdzamy, do ktorego przedzialu nalezy x */
		for(int i = 0; i < N; i++)
		{
			/* jesli x jest mniejsze, niz koniec i-tego przedzialu, to znaczy, ze do niego nalezy
			(pisac, jesli niezrozumiale :D) */
			if(x < ((max-min)/N)*i + (max-min)/N + min) {
				ilosc_liczb[i]++; /* inkrementujemy przedzial, do ktorego nalezy x */
				break; /* wychodzimy z petli, poniewaz znalezlismy przedzial */
			}
		}
	}
	/* oczywiscie zamykamy plik */
	fclose(file);
	
/* RYSUJEMY HISTOGRAM */
	/* Dla kazdego z N przedzialow */
	for(int i = 0; i < N; i++)
	{
		/* wypisujemy znaczek reprezentujacy ilosc liczb w przedziale.
			podzielilem przez 60, zeby znaczki w miare miescily sie w jednej linijce w konsoli.
			Jesli komus sie nie miesci, wystarczy zwiekszyc ta wartosc */
		for(int j = 0; j < ilosc_liczb[i]/60; j++)
			printf("#");
		
		/* przechodimy do nastepnej linii, zeby narysowac kolejny przedzial */
		printf("\n");
	}
	
	system("pause");
	return 0;
}
