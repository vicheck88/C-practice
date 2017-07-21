#include <stdio.h>
//void main()
//{
//	int a = 3;
//	printf("%d",++++a);
//}

//예제 2,3
#if 0
void main()
{
	int i;
	//for (i = 0; i <= 20; i += 2) printf("%d ", i);
	for (i = 0; i <= 20; i += 3) printf("%d ", i);
}
#endif // 0

//예제 4~7
#if 0
void main()
{
	int j;
	char i;

	//for(j=0;j<15;j++) printf("*"); //예제 4

	//for(j=0;j<8;j++) printf("%d ",j+7); //예제 5

	//for(i='A';i<='K';i++) printf("%c ",i); //예제 6

	for (i = 'D'; i <= 'X'; i += 2) printf("%c ", i); //예제 7
}
#endif // 0

//예제 8-1
#if 0
void main()
{
	int i;
	for (i = 1; i <= 99; i++)
	{				
		if ((i % 3 == 0) || (i % 10 == 3) || (i / 10 == 3)) printf(" %% ");
		else printf("%02d ", i);
		if (i % 10 == 0) printf("\n");
	}
	printf("\n성공!@#$%\n");
}
#endif // 1

//예제 8-2
#if 0
void main()
{
	int i, cnt = 0;
	for (i = 1; i <= 99; i++)
	{
		if (!((i % 3 == 0) || (i % 10 == 3) || (i / 10 == 3)))
		{
			printf("%02d ", i);
			cnt++;
			if (cnt % 10 == 0) printf("\n");
		}
	}
	printf("\n성공!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}
#endif // 0

//예제 9
#if 0
void main()
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
#endif // 0

//예제 10
#if 0
void main()
{
	int i, j;
	for (i = 2; i < 10; i++)
	{
		printf("%d단\n", i);
		for (j = 1; j < 10; j++)
		{
			printf("%d * %d = %d\n", i, j, i*j);
		}
		printf("===========\n");
	}
}
#endif // 0

//예제 14
#if 0
void main()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0, printf("Loop => %d\n", i); j < 10; i++, j++)
		{
			if (j == 4) break;
		}
		if (i % 3) continue;
		printf("====================\n");
	}
}
#endif // 0

//예제 15,16
#if 0
void no_two_three(int n)
{
	int i, cnt = 0;
	if (n > 999) printf("not available\n");
	else{
		for (i = 1; i <= n; i++)
		{
			if (!(i % 2 == 0 || i % 3 == 0))
			{
				printf("%3d ", i);
				cnt++;
				if (cnt % 9 == 0) printf("\n");
			}
		}
	}
}

//예제 16
void prime(int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= i / 2; j++)
		{
			if (i % j == 0) break;
		}
		if (j==i/2+1) printf("%d ", i);
	}
}
void main()
{
	int n;
	scanf("%d", &n);
	//no_two_three(n);  //15번 실행

	prime(n);  // 16번 실행
}
#endif // 0

//예제 19
#if 0
void three(int n)
{
	while (n-- + 1)
	{
		if ((n + 1) % 3 == 0) printf("%d ", n + 1);
	}
}
void main()
{
	int n;
	scanf("%d", &n);
	three(n);
}
#endif // 0

//예제 20
#if 0
void main()
{
	int n = 1, m;
	while (n++ <= 8)
	{
		m = 0;
		printf("%d단\n", n);
		while (m++ <= 8)
		{
			printf("%d * %d = %d\n", n, m, n*m);
		}
		printf("==============\n");
	}
}
#endif // 0

//예제 21
#if 0
void main()
{
	int max, n;
	scanf("%d", &max);
	n = max;
	while (n >= 10)
	{
		if (n / 10 + n % 10 == 3) break;
		else if (n / 10 + n % 10 == 7) printf("%d\n", n);
		n--;
	}
}
#endif // 0

//예제 22
#if 0
void lotto(int n)
{
	int cnt = 0;
	while (n >= 1)
	{
		if (n % 42 == 0)
		{
			printf("1등은 %d\n", n);
			cnt = 1; break;
		}
		n--;

	}
	if (cnt == 0) printf("꽝!\n");
}
void main()
{
	int n;
	printf("로또 번호는? ");
	scanf("%d", &n);
	lotto(n);
}
#endif // 0

//예제 26
#if 0
void prime(int n, int m)
{
	int i, j;
	for (i = n; i <= m; i++)
	{
		for (j = 2; j <= i / 2; j++)
		{
			if (i % j == 0) break;
		}
		if (j == (i / 2 + 1)) printf("%d ", i);
	}
}
void main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (n <= 0 || m <= 0)
	{
		printf("양수만!\n");
		scanf("%d%d", &n, &m);
	}
	if (n > m) prime(m, n);
	else prime(n, m);
}
#endif // 0

//예제 27
#if 0
int fact(int n)
{
	int i, mul = 1;
	if (n == 0) return 0;
	for (i = 1; i <= n; i++)
	{
		mul *= i;
	}
	return mul;
}
void main()
{
	int n;
	scanf("%d", &n);
	if (n < 0)
	{
		printf("음수는 안되!\n");
		scanf("%d", &n);
	}
	printf("%d\n", fact(n));
}
#endif // 0

//예제 28
#if 0
int median(int n, int m)
{
	return (n + m) / 2;
}
void main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", median(n, m));
}
#endif // 0

//예제 29
#if 0
void type_star(int n)
{
	int i, j, k;
	switch (n)
	{
	case 1:
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++) printf("*");
			printf("\n");
		}
		break;

	case 2:
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5 - i; j++) printf("*");
			printf("\n");
		}
		break;
	default:
		for (i = 1; i <= 5; i++)
		{
			for (j = 4 - i; j >= 0; j--)
			{
				printf(" ");
			}
			for (k = 1; k <= 2 * i - 1; k++) printf("*");
			printf("\n");
		}
	}
}
void main()
{
	int n;
	scanf("%d", &n);
	if (1>n || n > 3)
	{
		printf("다시 입력하세요\n");
		scanf("%d", &n);
	}
	type_star(n);
}
#endif // 0

//예제 30
#if 0
void main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < 2*n; i++) printf("*");
	printf("\n");
	for (i = 1; i < n; i++)
	{
		printf("*");
		for (j = 0; j < i - 1; j++) printf(" ");
		printf("*");
		for (j = (2*n-2) - 2 * i; j > 0; j--) printf(" ");
		printf("*");
		for (j = 0; j < i - 1; j++) printf(" ");
		printf("*\n");
	}
	for (i = n-1; i >= 1; i--)
	{
		printf("*");
		for (j = 0; j < i - 1; j++) printf(" ");
		printf("*");
		for (j = (2 * n - 2) - 2 * i; j > 0; j--) printf(" ");
		printf("*");
		for (j = 0; j < i - 1; j++) printf(" ");
		printf("*\n");
	}
	for (i = 0; i < 2*n; i++) printf("*");
	printf("\n");
}
#endif // 0

//워크샵 1
#if 0
void main()
{
	int n, i, cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 1) cnt++;
	}
	printf("%d\n", cnt);
}
#endif // 0

//워크샵 2
#if 0
void main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 1) sum+=i;
	}
	printf("%d\n", sum);
}
#endif // 0

//워크샵 3
#if 0
void main()
{
	int n;
	scanf("%d", &n);
	while (n > 0)
	{
		if (n % 2 == 1) printf("%d ", n);
		n--;
	}
}
#endif // 0

//워크샵 4
#if 0
void main()
{
	int n, cnt = 0, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i % 15 == 0)
		{
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\n%d\n", cnt);
}
#endif // 0

//워크샵 5
#if 0
void main()
{
	int i;
	for (i = 1; i <= 100; i += 2)
	{
		printf("%2d ", i);
		if ((i + 1) / 2 % 15 == 0) printf("\n");
	}
}
#endif // 0

//워크샵 6
#if 0
void main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}
}
#endif // 0

//워크샵 7
#if 0
void main()
{
	int i, j, k;
	for (i = 1; i <= 9; i++)
	{
		for (j = 9 - i; j > 0; j--) printf(" ");
		for (k = 1; k <= i; k++) printf("%d", k);
		printf("\n");
	}
}
#endif // 0

//워크샵 8
#if 0
void main()
{
	char i, j;
	for (i = 'A'; i <= 'Z'; i++)
	{
		for (j = 'A'; j <= i; j++)
		{
			printf("%c", j);
		}
		printf("\n");
	}
}
#endif // 0

//워크샵 9
#if 0
void main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 2; j <= 9; j++)
		{
			printf(" %d* %d=%2d", j, i, i*j);
		}
		printf("\n");
	}
}
#endif // 0

//워크샵 10
#if 0
void main()
{
	int i, j;
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			printf("%d %d\n", i, j);
		}

	}
}
#endif // 0

//워크샵 11
#if 0
void main()
{
	int n, x = 1, sum = 0;
	scanf("%d", &n);
	while (1)
	{
		sum += x;
		if (sum >= n) break;
		x++;
	}
	printf("%d", x);
}
#endif // 0

//워크샵 12
#if 0
void main()
{
	int n, power = 1, new = 0, power_up = 1;
	scanf("%d", &n);
	while (1)
	{
		power *= 10;
		if (n / (power * 10) == 0) break;
	}
	while (power >= 1)
	{
		new += n / power*power_up;
		n -= n / power*power;
		power /= 10;
		power_up *= 10;
	}
	printf("%d", new);
}
#endif // 1

//워크샵 12 모범답안
#if 0
void main()
{
	int n;
	scanf("%d", &n);
	for (;;)
	{
		printf("%d", n % 10);
		n /= 10;
		if (n == 0) break;
	}
}
#endif // 0
