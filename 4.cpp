#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int M[20][20], int N, int &minmax, int pos[2])
{
	int a = M[0][0];
	int b[2] = { 0, -1 };
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(minmax == 0) //min
			{
				if(M[i][j] < a)
				{
					a = M[i][j];
				
					if(pos[0] == -1) //first
					{
						if(b[0] == -1) {
							b[0] = i + 1;
							b[1] = j + 1;
						}
					}
					else //last
					{
						b[0] = i + 1;
						b[1] = j + 1;
					}
				}
			}
			else //max
			{
				if(M[i][j] > a)
				{
					a = M[i][j];
					
					if(pos[0] == -1) //first
					{
						if(b[0] == -1) {
							b[0] = i + 1;
							b[1] = j + 1;
						}
					}
					else //last
					{
						b[0] = i + 1;
						b[1] = j + 1;
					}
				}
			}
		}
	}
	
	minmax = a;
	pos[0] = b[0];
	pos[1] = b[1];
	if(pos[1] == -1)
		pos[1] = 0;
}

int main()
{
	srand(time(0));
	
	int M[20][20],
		N = 4,
		minmax = 0,
		pos[2] = { 1, 0 };
		
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			M[i][j] = rand()%10;
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	
	func(M, N, minmax, pos);
	
	printf("minmax = %d\n", minmax);
	printf("pos = (%d, %d)\n", pos[0], pos[1]);
	
	system("pause");
	return 0;
}
