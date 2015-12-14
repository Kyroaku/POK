#include <stdio.h>
#include <stdlib.h>

int func(char *L, char *L1)
{
	int n = 0;
	int i = 0;
	while(L[i] != '\0')
	{
		bool wystapil = true;
		for(int j = 0; L1[j] != '\0'; j++)
		{
			if(L[i] != L1[j]) {
				wystapil = false;
				i++;
				break;
			}
			i++;
		}
		if(wystapil)
			n++;
	}
	return n;
}

int main()
{
	char L[256], L1[256];
	printf("Podaj lancuch: ");
	scanf("%s", L);
	printf("Podaj lancuch szukany: ");
	scanf("%s", L1);
	
	printf("Lancuch L1 wyspil w lancuchu L %d razy\n", func(L, L1));
    
    system("pause");
    return 0;
}
