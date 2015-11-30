#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
	float suma = 0.0;
	int ilosc_liczb = 0;
	float srednia = 0.0;
	float odchylenie = 0.0;
	
	srand(time(0)); /* ustawiamy ziarnko zalezne od czasu, zeby funkcja rand() nie zwracala tych samych wartosci */
	
/* TWORZENIE PLIKU Z WYLOSOWANYMI WARTOSCIAMI */

	/* otworz plik "dane.txt" w trybie zapisu pliku tekstowego ("wt") */
    FILE *file = fopen("dane.txt", "wt");
    /* wylosuj ilosc liczb, ktore zostana zapisane do pliku (w tym przypadku z przedzialu <5000; 10000) */
    int N = ( rand()%10000 ) + 5000; /* zakladam, ze pozniej nie znam tej wartosci i nie wiem, ile liczb jest w pliku */
    /* zapisz do pliku N losowych liczb rzeczywistych */
    for(int i = 0; i < N; i++)
    {
	/* LOSOWANIE LICZBY Z ROZKLADU NORMALNEGO (GAUSSA) */
		float x = ( (float)(rand()+1) / (RAND_MAX+1) ); /* losowa liczba z przedzialu (0; 1> */
		float y = ( (float)(rand()+1) / (RAND_MAX+1) ); /* losowa liczba z przedzialu (0; 1> */
		/* transformacja 2 losowych liczb z rozkladu jednorodnego (prostokatnego) w liczbe z rozkladu normalnego (gaussa) */ 
		float z = cos(2*M_PI*y)*sqrt(-2.0*log(x));
		/* zapisanie wylosowanej liczby do pliku "dane.txt" */
		fprintf(file, "%f\n", z);
	}
	fclose(file);
	
/* OBLICZANIE WARTOSCI SREDNIEJ */

	/* otworz plik "dane.txt" w trybie odczytu pliku tekstowego ("rt") */
	file = fopen("dane.txt", "rt");
	/* wykonuj, dopoki nie ma konca pliku */
	while(!feof(file))
	{
		/* wczytaj wartosc z pliku "dane.txt" do zmiennej x */
		float x;
		fscanf(file, "%f\n", &x);
		
		/* do obliczenia sredniej */
		suma += x;
		ilosc_liczb++;
	}
	
	srednia = suma / ilosc_liczb;
	
	/* przejdz do poczatku pliku */
	rewind(file);
	
/* OBLICZANIE ODCHYLENIA */

	while(!feof(file))
	{
	    /* wczytaj wartosc z pliku do zmiennej x */
		float x;
		fscanf(file, "%f\n", &x);
		
		/* wykorzystamy zmienna suma do obliczenia odchylenia */
		suma += pow( (srednia - x), 2.0);
	}
	odchylenie = sqrt( suma / (ilosc_liczb-1) );
	
	/* Wartosci srednia i odchylenie powinny dazyc do wartosci 0.0 oraz 1.0 */
	printf("Srednia: %f\nOdchylenie: %f\n", srednia, odchylenie);
	
	rewind(file);
	
/* WYZNACZENIE ILOSCI LICZB Z DANYCH PRZEDZIALOW */

	int p1 = 0, /* <srednia-odchylenie; srednia+odchylenie> */
		p2 = 0, /* <srednia-2*odchylenie; srednia+2*odchylenie> */
		p3 = 0; /* <srednia-3*odchylenie; srednia+3*odchylenie> */
		
	while(!feof(file))
	{
	    /* wczytaj liczbe z pliku "dane.txt" */
		float x;
		fscanf(file, "%f\n", &x);
		/* sprawdzanie, czy wczytana wartosc nalezy do przedzialow.
			Bez uzycia "else", poniewaz wartosc moze nalezec do kilku przedzialow jednoczesnie */
		if(x >= srednia-odchylenie && x <= srednia+odchylenie)
			p1++;
		if(x >= srednia-2.0*odchylenie && x <= srednia+2.0*odchylenie)
			p2++;
		if(x >= srednia-3.0*odchylenie && x <= srednia+3.0*odchylenie)
			p3++;
	}
	/* Plik "dane.txt" juz nie bedzie potrzebny, wiec zamykamy */
	fclose(file);
	
	/* wartosci p1, p2, p3 powinny dazyc do wartosci ~68.2, ~95.4, ~99.7 */
	printf("p1: %d (%f%%)\np2: %d (%f%%)\np3: %d (%f%%)\n",
		p1, (float)p1/ilosc_liczb,
		p2, (float)p2/ilosc_liczb,
		p3, (float)p3/ilosc_liczb);
	
/* ZAPIS DANYCH DO PLIKU "raport.txt" */
	
	/* Otwieramy plik "raport.txt" w trybie zapisu pliku tekstowego (jesli go nie ma, to sie utworzy) */
	file = fopen("raport.txt", "wt");
	fprintf(file, "%f %f %d %d %d",
		srednia, odchylenie, p1, p2, p3);
    
	fclose(file);
		
/* ================================== ZADANIE 2 ================================== */
    /* otwieramy ponownie plik "dane.txt". Bedziemy w nim szukac liczb z danego przedzialu */
	file = fopen("dane.txt", "rt");
	/* otwiera plik "ndane.txt" w trybie zapisu pliku tekstowego */
	FILE *fileN = fopen("ndane.txt", "wt");
	/* dopoki nie ma konca pliku "dane.txt" */
	while(!feof(file))
	{
	    /* wczytaj wartosc do zmiennej x z pliku "dane.txt" */
		float x;
		fscanf(file, "%f\n", &x);
		if(x >= srednia-odchylenie && x <= srednia+odchylenie) /* jesli x nalezy do przedzialu */
			/* zapisz x do pliku "ndane.txt" */
			fprintf(fileN, "%f\n", x);
	}
	/* zamykamy otwarte pliki */
	fclose(file);
	fclose(fileN);
	
    system("pause");
    return 0;
}
