#include <stdio.h>

void main()
{
	int i, j;
	int n, num = 1;
	int x, y;
	int a[100][100] = { 0 };
	scanf("%d", &n);
	int m = n / 2 + 1;
	x = 1; y = m;

	for (i = 0; i <= n + 1; i++)
	{
		a[0][i] = a[n + 1][i] = 1;
		a[i][0] = a[i][n + 1] = 1;
	}

	for (i = 1; i <= n * n; i++)
	{
		a[x][y] = i;
		if (i % n == 0) { x++; }
		else 
		{ 
			x--; y--;
			if (x == 0) x = n;
			if (y == 0) y = n;
		}
	}











	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

