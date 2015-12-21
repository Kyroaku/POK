#include <stdlib.h>
#include <stdio.h>

/* funkcja obliczajaca wyznacznik macierzy 2x2, zapisanej w ten sposob:
|a	b|
|c	d|
*/
float det(float a, float b, float c, float d)
{
	/* zwracamy wartosc wyrazenia (a*d - b*c), czyli wyznacznik */
	return (a*d - b*c);
}

int main()
{
	/* uklad rownan:
	ax + by = e
	cx + dy = f
	*/
    float a, b, c, d, e, f;
    printf("Podaj 2 rownania w postaci:\nax + by = e\ncx + dy = f\n\n");
    scanf("%fx + %fy = %f", &a, &b, &e);
    scanf("%fx + %fy = %f", &c, &d, &f);

	/* dla x tworzymy macierz:
	|e	b|
	|f	d|
	(zamienilismy pierwsza kolumne)
	i dzielimy jej wyznacznik przez wyznacznik glowny */
	float x = det(e, b, f, d) / det(a, b, c, d);
	/* dla y podobnie, ale zamieniamy druga kolumne zamiast pierwszej:
	|a	e|
	|c	f| */
	float y = det(a, e, c, f) / det(a, b, c, d);
	printf("x = %f\ny = %f\n", x, y);
	
    system("pause");
    return 0;
}
