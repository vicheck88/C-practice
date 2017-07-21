#include <stdio.h>
//1번
#if 0
void main()
{
	int x, y, sum = 0, i;
	scanf("%d%d", &x, &y);

	for (i = (x + x % 2); i <= y; i += 2)
	{
		sum += i;
	}
	printf("%d", sum);
}
#endif // 0

//2번-1
#if 0
void main()
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		printf(" %3d", i);
		if (i % 10 == 0) printf("\n");
	}
}
#endif // 0
//2번-2
#if 0
void main()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			printf(" %3d", i * 10 + j);
		}
		printf("\n");
	}
}
#endif // 0

//3번
#if 0
void main()
{
	int i, j;
	for (i = 0; i <= 25; i++)
	{
		for (j = 0; j <= 25; j++)
		{
			printf("%c", ((i + j) % 26) + 65);
		}
		printf("\n");
	}
}
#endif // 0

//4번
#if 0
void main()
{
	int i, j, k;
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			for (k = 1; k <= 6; k++)
			{
				printf("%d %d %d\n", i, j, k);
			}
		}
	}
}
#endif // 0

//5번
#if 0
void main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (;;)
	{
		sum += n % 10;
		n /= 10;
		if (n == 0) break;
	}
	printf("%d", sum);
}
#endif // 0


//6번
#if 0
void main()
{
	int i, j, k;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++) printf("*");
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 4 - i; j > 0; j--) printf(" ");
		for (k = 0; k <= i; k++) printf("*");
		printf("\n");
	}


	printf("\n");
	for (i = 0; i < 5; i++)
	{
		for (k = 0; k < i; k++) printf(" ");
		for (j = 0; j < 5 - i; j++) printf("*");
		printf("\n");
	}
}
#endif // 0

//7번
#if 0
void main()
{
	int i, sum = 0;
	for (i = 3;; i += 3)
	{
		sum += i;
		if (sum >= 1000)
		{
			printf("%d", i - 3);
			break;
		}

	}
}
#endif // 0

//8번
#if 0
int fact(int n)
{
	if (n == 0) return 1;
	return n*fact(n - 1);
}
void main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += fact(i);
	}
	printf("%d", sum);
}
#endif // 0

//9번
#if 0
void prime(int n)
{
	int j;

	for (j = 2; j <= n / 2; j++)

	{
		if (n % j == 0)
		{
			printf("NO\n");  break;
		}
	}

	if (j == n / 2 + 1) printf("YES\n");
}

void main()
{
	int n, i, m;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		prime(m);
	}
}
#endif // 0

//10번
#if 0
void main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i%j == 0) printf("%d ", j);
		}
		printf("\n");
	}
}
#endif // 0


//11번
#if 0
void main()
{
	int m, n, i, j, cnt, cnt_max = 0, max = 0;
	scanf("%d%d", &n, &m);
	for (i = n; i <= m; i++)
	{
		cnt = 0;
		for (j = 1; j < i; j++)
		{
			if (i%j == 0) cnt++;
		}
		if (cnt > cnt_max)
		{
			max = j;
			cnt_max = cnt;
		}
	}
	printf("%d", max);
}
#endif // 0


//12번
#if 0
int days(int y, int m, int d)
{
	int yoon = 0, feb=28, apr=30, jun=30, sep=30, nov=30;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) yoon = 1;
	if (yoon == 1) feb++;
	switch (m)
	{
	case 1: return d; break;
	case 2: return d + 31; break;
	case 3: return 31 + feb + d; break;
	case 4: return feb + 62 + d; break;
	case 5: return 92 + feb + d; break;
	case 6: return feb + apr + 93 + d; break;
	case 7: return feb + apr + jun + 93 + d; break;
	case 8: return feb + apr + jun + 124 + d; break;
	case 9:return feb + apr + jun + 155 + d; break;
	case 10:return 365 + yoon - 92 + d; break;
	case 11: return 365 + yoon - 31 - 30 + d; break;
	default: return 365 + yoon - 31 + d;
	}
}


void main()
{
	int y, m, d, i, j, yoon = 0;
	scanf("%d%d%d", &y, &m, &d);
	printf("%d", days(y, m, d));

}
#endif

#if 0
int days(int y, int m, int d)
{
	int sum = 0, day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) day[1] = 29;
	for (i = 0; i < m - 1; i++)
	{
		sum += day[i];
	}
	return sum + d;

}


void main()
{
	int y, m, d, i, j, yoon = 0;
	scanf("%d%d%d", &y, &m, &d);
	printf("%d", days(y, m, d));

}
#endif // 0
