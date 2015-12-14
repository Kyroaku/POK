#include <stdio.h>
#include <stdlib.h>

void func(int M[20][20], int N, int R[20][20])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			R[i][j] = M[j][i];
		}
	}
}

int main()
{
	int M[20][20],
		N,
		R[20][20];
	
	printf("Podaj N: ");
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0 ; j < N; j++) {
			M[i][j] = rand()%10;
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	func(M, N, R);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0 ; j < N; j++) {
			M[i][j] = rand()%10;
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}
