//제곱근
#if 0
#include <stdio.h>
double sqrt(const double d)
{
	double tmp = 2;
	double x = 1;
	while (tmp - x > 0.005 || tmp - x < -0.005)
	{
		tmp = x;
		x = d / (2 * x) + x / 2;
	}
	return x;
}
#endif

#if 0

int main(void)
{
	int N;
	int sol;

	scanf("%d", &N);

	sol = (int)sqrt(N);

	printf("%d", sol);

	return 0;
}
#endif // 0

// 약수가 짝수인 수의 개수
#if 0
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", b - a + 1 - (int)sqrt(b) + (int)sqrt(a - 1));
	return 0;
}
#endif // 1

//시간 외 근무수당
#if 0
int main(void)
{
	int i;
	double sum=0;
	double money = 0;
	double s[5], e[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%lf %lf", &s[i], &e[i]);

		if (e[i] - s[i] > 1)
		{
			
			if (e[i] - s[i] - 1 >= 4)
			{
				sum += 4;
				money += 40000;
			}
			else
			{
				sum += e[i] - s[i] - 1;
				money += (e[i] - s[i] - 1) * 10000;
			}
		}
	}

	if (sum >= 15) money *=0.95;
	else if(sum<=5) money *=1.05;

	printf("%d\n", (int)money);
}
#endif // 0

//케이크 자르기
#if 0
int main(void)
{
	int x[2], y[2];
	int tmp;
	scanf("%d %d", &x[0], &x[1]);
	scanf("%d %d", &y[0], &y[1]);
	if (x[0] > x[1])
	{
		tmp = x[0];
		x[0] = x[1];
		x[1] = tmp;
	}
	if (y[0] > y[1])
	{
		tmp = y[0];
		y[0] = y[1];
		y[1] = tmp;
	}

	if (y[0] < x[0])
	{
		if (y[1] > x[1] || y[1]<x[0]) printf("not cross");
		else printf("cross");
	}
	else if (y[0] > x[1]) printf("not cross");
	else if (x[0] < y[0] && y[0] < x[1])
	{
		if (y[1] < x[1]) printf("not cross");
		else printf("cross");
	}
	else printf("cross");
}
#endif // 0

// 합,평균,표준편차 구하기
#if 0
int main(void)
{
	int n;
	int i;
	int *p;
	int sum=0;
	double mean;
	double var=0;
	double std=0;
	scanf("%d", &n);
	p = calloc(n,sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		sum += p[i];
	}
	mean = 1.0*sum / n;
	for (i = 0; i < n; i++)
	{
		var += (p[i] - mean)*(p[i] - mean)/n;
	}
	std = sqrt(var);
	printf("%d\n", sum);
	if ((int)((mean + 0.05)*10) % 10 != 0) printf("%.1f\n", mean);
	else printf("%.0f\n", mean);
	if ((int)((std + 0.05) * 10) % 10 != 0) printf("%.1f\n", std);
	else printf("%.0f\n", std);
	free(p);
	return 0;
}
#endif // 0

//최대공약수, 최소공배수
#if 0
int gcd(int x, int y)
{
	int m = 1;
	while (m)
	{
		m = x%y;
		x = y; y = m;
	}
	return x;
}
#endif

#if 0
int main(void)
{
	int m, n;
	scanf("%d%d", &n, &m);
	printf("%d\n%d\n", gcd(n, m), n*m / gcd(n, m));
	return 0;
}
#endif // 0

//여러개의 최대공약수, 최소공배수
#if 0
int lcd(int x, int y)
{
	return x*y / gcd(x, y);
}

int main(void)
{
	int n;
	int m[10];
	int i;
	int gc = 1;
	int lc = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
		if (i == 0)
		{
			gc = lc = m[0];
		}
		else
		{
			gc = gcd(m[i], gc);
			lc = lcd(m[i], lc);
		}
	}
	printf("%d %d\n", gc, lc);
}
#endif // 0

//찢어진 책
#if 0
int main(void)
{
	int n;
	int sum;
	int dif;
	int real_sum;
	scanf("%d %d", &n, &sum);
	if ((n < 2 || n>500) || (sum < 1 || sum>125000) || n&1) printf("Error");
	real_sum = (1 + n)*n/2;
	dif = real_sum - sum;
	if (!(dif&1) || !(dif / 2 & 1) || dif<0 || n<dif/2+1) printf("Error");
	else printf("%d %d", dif / 2, dif / 2 + 1);
}
#endif // 0

//금메달은 누구
#if 0
int main(void)
{
	int i;
	int j;
	int k = 0;
	int n;
	int tmp;
	int cnt = 0;

	int p[10][6] = { 0 };
	int id[10];
	int medal[3][10] = { 0 };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &p[i][j]);
			if (j!=0) p[i][5] += p[i][j];
		}
		id[i] = p[i][0];
	}

	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (p[i][5] < p[j][5])
			{
				tmp = p[i][5];
				p[i][5] = p[j][5];
				p[j][5] = tmp;

				tmp=id[i]; 
				id[i] = id[j]; 
				id[j]=tmp;
			}
			else if (p[i][5] == p[j][5] && id[i]>id[j])
			{
				tmp = id[i];
				id[i] = id[j];
				id[j] = tmp;
			}
		}
		
		if (i>0 && p[i][5] != p[i - 1][5])
		{
			cnt++;
			k = 0;
		}
		if (cnt > 2) break;
		medal[cnt][k]=id[i];
		k++;
	}

	for (i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0: printf("GOLD :"); break;
		case 1: printf("SILVER :"); break;
		case 2: printf("BRONZE :"); break;
		}
		for (j = 0; j < 10; j++)
		{
			if (medal[i][j] != 0) printf(" %d", medal[i][j]);
			else break;
		}
		printf("\n");
	}
	return 0;
}
#endif // 0

// 배수의 합
#if 0
int main(void)
{
	int i;
	int r = 1;
	int sum = 0;
	int n;
	scanf("%d", &n);
	for (i = n; sum < 10000; i += n)
	{
		sum += i;
	}
	printf("%d", i-2*n);
	return 0;
}
#endif // 1

// 숫자의 합
#if 0
int main(void)
{
	int i;
	int j = 0;
	int n;
	int m[100000];
	int sum[3] = { 0 };
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
		if (m[i] / 100 != 0) sum[0] += m[i];
		else if (m[i] / 10 != 0) sum[1] += m[i];
		else sum[2] += m[i];
	}

	for (i = 0; i < 2; i++)
	{
		printf("%d ", sum[i]);
	}
	printf("%d", sum[2]);

	return 0;
}
#endif // 0

//가장 많은 알파벳은
#if 0
int main(void)
{
	char ch[31];
	int i;
	char *p;
	int alphabet[26] = { 0 };
	int max=0;
	char max_alpha;
	scanf("%s", ch);
	p = ch;
	while (*p)
	{
		if (*p >= 'a') alphabet[*p - 'a']++;
		p++;
	}
	for (i = 0; i < 26; i++)
	{
		if (max < alphabet[i])
		{
			max = alphabet[i];
			max_alpha = i + 'a';
		}
		else if (max == alphabet[i] && max_alpha > i + 'a')
		{
			max_alpha = i + 'a';
		}
	}
	printf("%c", max_alpha);

	return 0;
}
#endif // `

//배열의 순환
#if 0
int main(void)
{
	int n;
	int i;
	int tmp;
	int ar[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ar[i]);
	}
	for (i = 1; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("%d", ar[0]);
	return 0;
}
#endif // 0

//배열 채우기 2
#if 0
int main(void)
{
	int n;
	int i, j;
	int num = 0;
	int ar[100][100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			ar[i][(i & 1)*(n-1) + ((i & 1)*(-2) + 1 )* j]=++num;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif // 1

//피보나치 수열
#if 0
int fib(int n)
{
	if (n == 1 || n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", fib(n));
	return 0;
}
#endif // 1

//숫자 맞추기
#if 0
int main(void)
{
	int n;
	int i, j,k;
	int zero = 0;
	int card[200][3];
	int score[200] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &card[i][j]);
		}
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < n - 1; i++)
		{
			for (k = i + 1; k < n; k++)
			{
				if (card[i][j] == card[k][j] && card[i][j] != 0)
				{
					zero = 1;
					card[k][j] =  0;
				}
			}
			if (zero == 1)
			{
				card[i][j] = 0;
				zero = 0;
			}
		}
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < n; i++)
		{
			score[i] += card[i][j];
		}
	}
	
	for (i = 0; i < n; i++)
	{
		printf("%d\n", score[i]);
	}

	return 0;
}
#endif // 1

//순환 순열
#if 0
int main(void)
{
	int n;
	int p;
	int i,j;
	int cnt = 0;
	int ar[1000] = { 0 };
	int br[1000] = { 0 };
	scanf("%d %d", &n, &p);
	ar[0] = n;
	br[0] = 1;
	for (i=1;;i++)
	{
		for (j = 0; j < i; j++)
		{
			if (ar[j] == n*ar[i - 1] % p)
			{
				br[j]++;
				break;
			}
		}
		if (i == j)
		{
			ar[i] = n*ar[i - 1] % p;
			br[i]++;
		}
		if (br[j] == 2) break;
	}
	for (i = j; br[i] != 0; i++) ++cnt;
	printf("%d", cnt);
	return 0;
}
#endif // 1

//6174
#if 0
int main(void)
{
	int n;
	int cnt = 0;
	int i = 0;
	int j;
	int r = 1;
	int max[4], min[4];
	int maxnum = 0, minnum = 0;
	int tmp;
	scanf("%d", &n);


	while (!(n == 6174))
	{
		while (n)
		{
			max[i] = min[i] = n % 10;

			n /= 10;
			i++;
		}
		for (i = 0; i < 4; i++)
		{
			for (j = i + 1; j < 4; j++)
			{
				if (max[i] > max[j])
				{
					tmp = max[i];
					max[i] = max[j];
					max[j] = tmp;
				}
				else if (min[i] < min[j])
				{
					tmp = min[i];
					min[i] = min[j];
					min[j] = tmp;
				}
			}

			maxnum += max[i] * r;
			minnum += min[i] * r;
			r *= 10;
		}
		n = maxnum - minnum;
		cnt++;
		r = 1;
		i = 0;
		maxnum = minnum = 0;
	}
	printf("%d", cnt);
}
#endif // 1
