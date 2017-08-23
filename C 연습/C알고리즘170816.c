//가장 가까운 짝수인 7의 배수
#if 0
int main(void)
{
	int i,n;
	scanf("%d",&n);
	if(n<=14)
	{
		printf("14");
		return 0;
	}
	else
	{
		for(i=14;i<n;i+=14);
		if (i - n>=n - i + 14) printf("%d", i - 14);
		else printf("%d", i);
		return 0;
	}
}
#endif // 0

// 공배수의 개수
#if 0
int main(void)
{
	int a[10] = { 12, 18, 21, 36, 15, 19, 22, 24, 31, 55 };
	int n1, n2;
	int cnt = 0, i;
	scanf("%d%d", &n1, &n2);
	for (i = 0; i < 10; i++)
	{
		if (a[i] % n1 == 0 && a[i] % n2 == 0) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
#endif // 0

//가장 먼 실수와 가장 가까운 실수
#if 0
double abs(double x)
{
	return (x > 0) ? x : -x;
}

int main(void)
{
	double a[5];
	double b[5];
	double max, min;
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%lf", &a[i]);
		b[i] = abs(3.5-a[i]);
		if (i == 0) max = min = a[0];
		else
		{
			if (abs(3.5-max) < b[i]) max = a[i];
			if (abs(3.5-min) > b[i]) min = a[i];
		}
	}
	printf("%f %f", min, max);
	return 0;
}
#endif // 1

//16진수 구구단
#if 0
int main(void)
{
	int n;
	int i;
	scanf("%x", &n);
	for (i = 1; i < 16; i++)
	{
		printf("%X*%X=%X\n", n, i, n*i);
	}
	return 0;
}
#endif // 1

//숫자의 종류
#if 0
int main(void)
{
	int n;
	int i,j;
	int cnt = 0;
	int a[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] != 0 && a[i] == a[j]) a[j] = 0;
		}
		if (a[i] != 0) cnt++;
	}
	printf("%d", cnt);
}
#endif // 1

//합의 회문수
#if 0
int reverse(int x)
{
	int cnt = 0;
	int rev[7];
	int r = 0;
	int y = 1;
	int i;
	while (x)
	{
		rev[cnt] = x % 10;
		x /= 10;
		cnt++;
	}
	for (i = cnt - 1; i >= 0; i--)
	{
		r += rev[i] * y;
		y *= 10;
	}
	return r;
}

int main(void)
{
	int n;
	int i,j;
	int cnt = 0;
	int a[100];
	int b[7];
	char result[100][4];
	int sum;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum = a[i] + reverse(a[i]);
		while (sum)
		{
			b[cnt] = sum % 10;
			sum /= 10;
			cnt++;
		}
		
		for (j = 0; j < cnt / 2; j++)
		{
			if (b[j] != b[cnt - j - 1]) break;
		}
		if (j == cnt / 2) printf("YES\n");
		else printf("NO\n");
		cnt = 0;
	}
	return 0;
}
#endif // 1

//정수론 몫과 나머지
#if 0
int abs(int x, int y)
{
	return (x > y) ? x - y: y - x;
}

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

int main(void)
{
	int a[3];
	int n[3];
	int gc;
	int i;
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	a[0] = abs(n[0], n[1]);
	a[1] = abs(n[0], n[2]);
	a[2] = abs(n[1], n[2]);
	
	gc = gcd(gcd(a[0], a[1]), a[2]);
	printf("%d", gc);
}
#endif // 1

//앞뒤 같은 제곱
#if 0
int a[100] = { 0 };
int b[30] = { 0 };
int decimal(int x, int decimal)
{
	int r = 1;
	int cnt = 0;
	while (x)
	{
		b[cnt] = x%decimal;
		x /= decimal;
		cnt++;
	}
	return cnt;
}
int decimal_square(int x, int decimal)
{
	int r=1;
	int cnt=0;
	while (x)
	{
		a[cnt] = x%decimal;
		x /= decimal;
		cnt++;
	}
	return cnt;
}


int main(void)
{
	int n;
	int dec;
	int i,j,k;
	int rev=0;
	scanf("%d", &n);


	for (i = 1; i <= 300; i++)
	{
		dec = decimal_square(i*i, n);
		
		for (j = 0; j < dec/2; j++)
		{
			if (a[j] != a[dec - 1 - j]) break;
		}

		if (j == dec / 2)
		{
			for (k = decimal(i, n) - 1; k >= 0; k--)
			{
				if (b[k] >= 10) printf("%c", b[k] + 55);
				else printf("%d", b[k]);
			}
			printf(" ");
	
			for (k = 0; k < dec; k++)
			{
				if (a[k] >= 10) printf("%c", a[k] + 55);
				else printf("%d", a[k]);
			}
			printf("\n");
		}
	}
}
#endif // 1

// 주사위 눈의 합
#if 0
int main(void)
{
	int n;
	double p[13] = { 0 };
	int i, j;
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			p[i + j]++;
		}
	}
	scanf("%d", &n);
	printf("%.4f%%", p[n] / 36*100);
	
}
#endif // 1

//숫자 뒤집기
#if 0
int main(void)
{
	int n;
	scanf("%d", &n);
	while (n)
	{
		printf("%d", n % 10);
		n /= 10;
	}
}
#endif // 1

//꼭지점 개수
#if 0
int corner(int iter)
{
	if (iter == 0) return 2;
	return corner(iter - 1) * 2 - 1;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", corner(n)*corner(n));
}
#endif // 1

//CD 만들기
#if 0
int main(void)
{
	int m[200];
	int n, t;
	int i,j;
	int tmp;
	int cnt = 0;
	int sum = 0;
	scanf("%d %d", &n, &t);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
	}
	for (i = 0; i < n ; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (m[i]>m[j])
			{
				tmp = m[i];
				m[i] = m[j];
				m[j] = tmp;
			}
		}
		sum += m[i];
		if (sum > t) break;
		cnt++;
	}
	printf("%d", cnt);
}
#endif // 1

//분수의 합 구하기
#if 0
int abs(int x)
{
	return (x > 0) ? x : -x;
}
int gcd(int x, int y)
{
	int tmp;
	if (x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}

	int m = 1;
	while (m)
	{
		m = x%y;
		x = y; y = m;
	}
	return x;
}
int lcm(int x, int y)
{
	return x*y / gcd(x, y);
}

int main(void)
{
	int n;
	int a[100][2];
	int i;
	int sum[2];
	int den;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i][0], &a[i][1]);
		if (i == 0)
		{
			sum[0] = a[i][0];
			sum[1] = a[i][1];
		}
		else
		{
			den = lcm(sum[1], abs(a[i][1]));
			a[i][0] = (den / a[i][1])*a[i][0];
			sum[0] = (den / sum[1])*sum[0] + a[i][0];
			sum[1] = den;
		}
	}
	if (sum[0] == 0) printf("0");
	else printf("%d/%d", sum[0] / gcd(abs(sum[0]), abs(sum[1])), sum[1] / gcd(abs(sum[0]), abs(sum[1])));

	return 0;
}
#endif // 0

//연속부분최대곱
#if 0
int main(void)
{
	int n;
	int i,j;
	int max=1;
	double mul=1;
	double mul_former = 0;
	int cnt = 0;
	double a[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
		
		mul *= a[i];
		if (mul_former<mul) mul_former = mul;
		if (mul < 1) mul = 1;
		
	}
	printf("%.3f", mul_former);
}
#endif // 1

//미친수열
#if 0
long long sqrt(double n)
{
	double tmp=0ll;
	double x = 100000000ll;
	while (!(tmp - x < 0.005 && tmp - x > -0.005))
	{
		tmp = x;
		x = n / (2 * x) + x / 2;
	}
	return (long long)x;
}

int main(void)
{
	long long n;
	long long i;
	long long k = 1;
	scanf("%lld", &n);

	i = sqrt(2 * n+0.25);

	if (i*(i+1)>=2*n) printf("%lld", i);
	else printf("%lld", i + 1);
}
#endif // 1

//도미노
#if 0
int main(void)
{
	int n;
	int i;
	int k = 1;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		k = i + 1;
		sum += k;
	}
	printf("%d", sum);
}
#endif // 1

//합이 가장 큰 행과 열
#if 0
int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int col[4];
int row[5];
int main(void)
{
	int max=0x80000000;
	int max_col, max_row;
	int i,j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			col[i] += a[i][j];
			row[j] += a[i][j];
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (max < col[i])
		{
			max = col[i];
			max_col = i + 1;
		}
	}
	for (i = 0; i < 5; i++)
	{
		if (max < row[i])
		{
			max = row[i];
			max_row = i + 1;
		}
	}
	printf("%d %d", max_col, max_row);
	return 0;
}
#endif // 1

//별삼각형1
#if 0
void main()
{
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	if (n > 100 || n < 0 || m < 1 || m>3) printf("INPUT ERROR!");
	else{
		switch (m)
		{
		case 1:
			for (i = 0; i < n; i++)
			{
				for (j = 0; j <= i; j++)
				{
					printf("*");
				}
				printf("\n");
			} break;
		case 2:
			for (i = 0; i < n; i++)
			{
				for (j = n - i; j >= 1; j--)
				{
					printf("*");
				}
				printf("\n");
			} break;
		default:
			for (i = 0; i < n; i++)
			{
				for (j = n - 1 - i; j > 0; j--)
				{
					printf(" ");
				}
				for (k = 0; k < 2 * i + 1; k++)
				{
					printf("*");
				}
				printf("\n");
			}
		}
	}
}
#endif // 1

//문자사각형1
#if 0
void main(void)
{
	int a[100][100];
	int i, j;
	int num = 0;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[n - j-1][n - i-1] = (num++) % 26;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c ", a[i][j]+65);
		}
		printf("\n");
	}
}
#endif // 1

//달팽이사각형
#if 0
int main(void)
{
	int n;
	int a[100][100];
	int i, j,k=0;
	int num = 0;
	scanf("%d", &n);
	for (i = 0; num!=n*n; i++)
	{
		if (i == n - i - 1) a[k][i] = ++num;
		for (j = i; j < n-i-1; j++)
		{
			a[k][j] = ++num;
		}
		if (num == n*n) break;
		for (k = i; k < n-i-1; k++)
		{
			a[k][j] = ++num;
		}
		if (num == n*n) break;
		for (j = n-1-i; j > i; j--)
		{
			a[k][j] = ++num;
		}
		if (num == n*n) break;
		for (k = n-1-i; k > i; k--)
		{
			a[k][j] = ++num;
		}
		if (num == n*n) break;
		k++;

	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
#endif // 1

//달팽이삼각형
#if 0
int main(void)
{
	int n;
	int a[100][100] = { 0 };
	int i, j, k = 0;
	int num = 0;
	scanf("%d", &n);
	for (i = 0; num <= n*(n+1)/2; i++)
	{
		if (i == n - 2 * i - 1) a[j + i][i] = (num++)%10;
		for (j = i; j < n - 2*i - 1; j++)
		{
			a[j+i][j] = (num++) % 10;
		}
		if (num >= n*(n + 1) / 2) break;
		for (k = n - 2*i - 1; k > i; k--)
		{
			a[j+i][k] = (num++) % 10;
		}
		if (num >= n*(n + 1) / 2) break;
		for (j = n - 2*i - 1; j > i; j--)
		{
			a[j+i][k] = (num++) % 10;
		}
		if (num >= n*(n + 1) / 2) break;
		j++;

	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
#endif // 1

//마방진
#if 0
int main(void)
{
	int i, j;
	int n, num = 1;
	int x, y;
	int a[100][100] = { 0 };
	scanf("%d", &n);
	int m = n / 2 + 1;
	x = 1; y = m;

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
	return 0;
}
#endif // 1

//회전
#if 0
int main(void)
{
	int n;
	int angle=1;
	int i, j;
	int a[50][50];
	int b[50][50];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	while (angle != 0)
	{
		scanf("%d", &angle);
		switch (angle)
		{
		case 90:
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					b[i][j] = a[n-j-1][i];
					printf("%d ", b[i][j]);
				}
				printf("\n");
			}
			break;
		case 180:
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					b[i][j] = a[n-i-1][n-1-j];
					printf("%d ", b[i][j]);
				}
				printf("\n");
			}
			break;
		case 270:
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					b[i][j] = a[j][n - 1 - i];
					printf("%d ", b[i][j]);
				}
				printf("\n");
			}
			break;
		case 360:
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					b[i][j] = a[i][j];
					printf("%d ", b[i][j]);
				}
				printf("\n");
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
}
#endif // 1

//문자까지의 문자열
#if 0
int main(void)
{
	int i;
	char n;
	scanf("%c", &n);
	if ('A' <= n && n <= 'Z')
	{
		for (i = n; i <= 'Z'; i++)
		{
			printf("%c", i);
		}
	}
	else if ('a' <= n && n <= 'z')
	{
		for (i = 'a'; i <= n; i++)
		{
			printf("%c", i);
		}
	}
	else printf("Error");
}
#endif // 1

//10글자까지만 거꾸로
#if 0
int main(void)
{
	char ch[256];
	int i;
	int cnt = 0;
	scanf("%s", ch);
	for (i = 0; ch[i]; i++)
	{
		if (cnt == 10 || !(('A' <= ch[cnt] && ch[cnt] <= 'Z') ||
			('a' <= ch[cnt] && ch[cnt] <= 'z'))) break;
		cnt++;
	}
	for (i = cnt - 1; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}

	return 0;
}
#endif // 1

//문자열 뒤집기 1
#if 0
int main(void)
{
	char ch[51];
	int i;
	int cnt=0;
	gets(ch);
	while (ch[cnt++]);
	for (i = cnt - 2; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}
}
#endif // 1

//문자열 뒤집기 2
#if 0
char ch[51];
void reverse(int n, char *p)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if ('a' <= p[-i] && p[-i] <= 'z')
		{
			printf("%c", p[-i]-('a'-'A'));
		}
		else printf("%c", p[-i]);
	}
}

int main(void)
{
	char * p;
	int i;
	int cnt = 0;
	gets(ch);
	p = ch;
	while (*p)
	{
		if (*p == '.' || *p == '!' || *p==' ' || *p==0)
		{
			if (cnt != 0)
			{
				reverse(cnt,p);
				cnt = 0;
			}
			printf("%c", *p);
		}
		else cnt++; 
		p++;
	}
	if (*p == 0)
	{
		reverse(cnt, p);
	}

}
#endif // 1

//문자열 찾기
#if 0
int str_subcmp(char *p, char *q)
{
	for (;;)
	{
		if (!*q) return 0;
		if ((*p<*q) || (*p>*q)) return 1;
		p++; q++;
	}
}
int main(void)
{
	char *p = "KOI";
	char *q = "IOI";
	char ch[10000];
	char *r;
	int n1 = 0;
	int n2 = 0;
	gets(ch);
	r = ch;
	while (*r)
	{
		if (str_subcmp(r, p) == 0) n1++;
		else if (str_subcmp(r, q) == 0) n2++;
		r++;
	}
	printf("%d\n%d", n1, n2);
	return 0;
}
#endif // 1

//문자열 변환
#if 0
int main(void)
{
	int i,j;
	int find = 0;
	int n;
	char ch[50][2];
	int m;
	char str[100000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(" %c %c", &ch[i][0], &ch[i][1]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf(" %c", &str[i]);
		for (j = 0; j < n; j++)
		{
			if (str[i] == ch[j][0])
			{
				printf("%c", ch[j][1]);
				break;
			}
		}
		if (j==n) printf("%c", str[i]);
	
	}
}
#endif // 1

//UNIQUENESS
#if 0
int strcmp(char *p, char *q)
{
	for (;;)
	{
		if (*p > *q) return 1;
		if (*p < *q) return -1;
		if (!*q) return 0;
		p++; q++;
	}
}

int main(void)
{
	char str[10000][21] = { 0 };
	int a[10000][2];
	int i,j;
	int n;
	int unique = 1;
	int again = 0;
	int print = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (strcmp(str[i], str[j]) == 0 && str[j][0] != 0)
			{
				unique = 0;
				str[j][0] = 0;
				if (again == 0)
				{
					printf("%s %d %d", str[i], i+1,j+1);
					again = 1;
					print = 1;
				}
				else if (again == 1)
				{
					printf(" %d", j + 1);
					print = 1;
				}
			}
		}
		again = 0;
		if (print==1) printf("\n");
		print = 0;
	}
	if (unique == 1) printf("unique");
}
#endif // 1

//단어 세기
#if 0
int strcmp(char *p, char *q)
{
	for (;;)
	{
		if (*p > *q) return 1;
		if (*p < *q) return -1;
		if (!*q) return 0;
		p++; q++;
	}
}
void strcpy(char *p, char *q)
{
	while (*p++ = *q++);
}

int main(void)
{
	char ch[200];
	char str[200][200];
	char tmp[200];
	int temp;
	char *p;
	char *q;
	int a[200] = { 0 };
	int i,j,k;
	int cnt;
	for (;;)
	{
		gets(ch);
		if (strcmp(ch, "END") == 0) break;
		p = ch;
		i = j = 0;
		while (*p)
		{
			if (*p == ' ')
			{
				str[i][j] = 0;
				i++;
				j = 0;
			}
			else
			{
				str[i][j] = *p;
				j++;
			}
			p++; 
		}
		str[i][j] = 0;
		cnt = i;
		for (i = 0; i <= cnt; i++)
		{
			for (j = i + 1; j <= cnt; j++)
			{
				if (strcmp(str[i], str[j]) == 1)
				{
					strcpy(tmp, str[i]);
					strcpy(str[i], str[j]);
					strcpy(str[j], tmp);
				}
			}
		}
		for (i = 0; i <= cnt; i++)
		{
			for (j = i; j <= cnt; j++)
			{
				if (strcmp(str[i], str[j]) != 0) break;
				else
				{
					a[i]++; 
					if (i != j)
					{
						for (k = i; k < cnt; k++)
						{
							strcpy(str[k], str[k + 1]);
						}
						str[k + 1][0] = 0;
						cnt--;
						j--;
					}
				}
			}
		}
		
		for (i = 0; i <= cnt; i++)
		{
			printf("%s : %d\n", str[i], a[i]);
			a[i] = 0; 
		}


	}

	return 0;
}
#endif // 1

//종이접기
#if 0
int pow(int x, int y)
{
	int i;
	int sol = 1;
	for (i = 0 ; i < y; i++)
	{
		sol *= x;
	}
	return sol;
}


int a[1500000];
int main(void)
{
	int n;
	int i=1;
	int j;
	int a1=1;
	int m = 1;
	int d;
	int sol = -1;
	scanf("%d", &n);
	d = pow(2, n-1);
	a1 = pow(2, n - 1) - 1;
	d = pow(2, n);
	for (;;)
	{
		if (d == 1) break;
		
		
		for (i = 0; i < m; i++)
		{
			a[a1 + i*d] = sol;
			sol = -!sol;
		}
		i = 0;
		d/=2;
		a1/=2;
		m *= 2;
	}
	for (i = 0; i < pow(2, n) - 1; i++)
	{
		if (a[i] == -1) printf("V");
		else printf("^");
	}
	return 0;
}
#endif // 1

//숫자맞추기
#if 0
void decompose(int n, int *a)
{
	int i=0;
	while (n)
	{
		a[i] = n % 10;
		n /= 10;
		i++;
	}
}

int main(void)
{
	int n[2];
	int a[4];
	int b[4];
	int strike = 0;
	int ball = 0;
	int i,j;
	int tmp;
	scanf("%d %d", &n[0], &n[1]);
	decompose(n[0],a);
	decompose(n[1],b);
	for (i = 0; i < 4; i++)
	{
		if (a[i] == b[i]) strike++;
		else
		{
			for (j = 0; j < 4; j++)
			{
				if (i == j) continue;
				if (a[i] == b[j])
				{
					ball++;
					break;
				}
			}
		}
	}
	printf("%dA%dB", strike, ball);
	return 0;
}
#endif // 1

//초콜릿 이벤트
#if 0
int main(void)
{
	int trial;
	int n, c, m;
	int i;
	int cnt;
	int rem;
	int tmp;
	scanf("%d", &trial);
	for (i = 0; i < trial; i++)
	{
		scanf("%d %d %d", &n, &c, &m);
		cnt = n / c;

		if (cnt >= m)
		{
			rem = cnt;
			while (rem >= m)
			{
				tmp = rem / m;
				cnt = cnt + tmp;
				rem = rem%m + tmp;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
#endif // 1

//줄 세우기
#if 0
int main(void)
{
	int n;
	int a[100];
	int b[100];
	int tmp;
	int i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0) b[i] = i + 1;
		else
		{
			for (j = i-1; j >= i - a[i]; j--)
			{
				b[j + 1] = b[j];
			}
			b[i - a[i]] = i + 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}
#endif // 1

//369 게임
#if 0
int prime(int x)
{
	if (x == 1) return 0;
	int i;
	for (i = 2; i <= x / 2; i++)
	{
		if (!(x%i)) return 0;
	}
	return 1;
}

int main(void)
{
	int n;
	int m;
	int p;
	int i;
	int clap = 0;
	int sqrt[1000];
	scanf("%d %d %d", &n, &m, &p);
	for (i = p+1; i <= m; i += n)
	{
		if (prime(i)) clap++;
	}
	printf("%d\n", clap);
	return 0;
}
#endif // 1

//배열
#if 0
int ar[1000][1000];
int main(void)
{
	int m;
	int n;
	int i, j;
	int cnt=0;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &ar[i][j]);
			if (ar[i][j]) cnt++;
			else cnt = 0;
			printf("%d ",cnt);
		}
		cnt = 0;
		printf("\n");
	}
	return 0;
}
#endif // 1
