#if 0
//연속부분최대곱
//N개의 양의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오.

//곱을 누적시킬 때, 결과값이 1보다 작아질 경우 누적값을 초기화, 해당 위치에서 다시 누적 시작

int main(void)
{
	int n;
	int i, j;
	int max = 1;
	double mul = 1;
	double mul_former = 0;
	int cnt = 0;
	double a[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);

		mul *= a[i]; //값의 곱을 누적
		if (mul_former<mul) mul_former = mul; //곱한 값이 원래 값보다 작을 경우 그대로 유지
		if (mul < 1) mul = 1; //누적값이 1보다 작을 경우 초기화

	}
	printf("%.3f", mul_former);
}
#endif // 0

#if 0
//미친수열
//다음과 같은 수열이 있다. 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5... (숫자 k가 연달아 k번 나오는 수열).정수 n이 주어졌을 때, 해당 수열에서 n번째 나오는 숫자를 출력하는 프로그램을 작성하라.수열의 첫 번째 원소는 1이다.

//근의 공식을 활용, 경계값을 알아내 문제 해결
//값이 매우 크다는 점을 고려, long long을 사용하는 것에 주의
long long sqrt(double n)
{
	double tmp = 0ll;
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

	i = sqrt(2 * n + 0.25); //근의 공식을 활용

	if (i*(i + 1) >= 2 * n) printf("%lld", i);
	else printf("%lld", i + 1);
}
#endif // 0

#if 0
//종이접기
//직사각형 종이의 왼쪽 반을 오른쪽 반 위로 오도록 접는 것을 오른쪽 접기라 한다.
//접은 종이에 남은 자국에서 마루를 ^로, 골을 V로 나타낼 때, 직사각형 종이를 두 번 오른쪽 접기를 수행한 후 원래대로 펼치면, 접은 자국은 왼쪽에서 오른쪽으로 차례대로 ^VV의 모양이 된다. 직사각형 종이를 세 번 오른쪽 접기를 수행한 후 원래대로 펼치면, 접은 자국은 왼쪽에서 오른쪽으로 차례대로 ^^VV^VV의 모양이 된다.
 
//직사각형 종이를 오른쪽 접기를 수행한 후 원래대로 펼칠 때, 접은 자국을 왼쪽에서 오른쪽으로 마루와 골을 출력하는 프로그램을 작성하시오.

//종이를 접을 때 새로 생기는 값은 ^V^V...의 모습을 반복하며 새로운 값들은 원래 있던 값들 사이에 존재함
//따라서 새로 생기는 값의 위치의 주기를 찾아내어 값을 입력
int pow(int x, int y)
{
	int i;
	int sol = 1;
	for (i = 0; i < y; i++)
	{
		sol *= x;
	}
	return sol;
}


int a[1500000];
int main(void)
{
	int n;
	int i = 1;
	int j;
	int a1 = 1;
	int m = 1;
	int d;
	int sol = -1;
	scanf("%d", &n);
	d = pow(2, n - 1);
	a1 = pow(2, n - 1) - 1;
	d = pow(2, n);
	for (;;)
	{
		if (d == 1) break;


		for (i = 0; i < m; i++) //종이를 접을 때 새로 생기는 구역을 표시 
		{
			a[a1 + i*d] = sol;
			sol = -!sol;
		}
		i = 0;
		d /= 2;
		a1 /= 2;
		m *= 2;
	}
	for (i = 0; i < pow(2, n) - 1; i++)
	{
		if (a[i] == -1) printf("V");
		else printf("^");
	}
	return 0;
}
#endif // 0

#if 0
//문자열 뒤집기Ⅱ
//최대 길이 50이하인 문자열을 입력 받아 단어 별로 뒤집어서 출력하는 프로그램을 작성하시오.
// 최대 길이 50이하인 문자열이 입력된다.
그리고 ".", "!"는 단어 맨 뒤에만 올 수 있으며, "!!"과 같이 느낌표는 여러 번 연속해서 입력될 수 있다.

//문자열 포인터의 위치를 이동시키며 카운트를 세다, "."나 "!"이 올 때 반대로 문자열 출력
char ch[51];
void reverse(int n, char *p) //문자열을 거꾸로 출력하는 함수
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if ('a' <= p[-i] && p[-i] <= 'z')
		{
			printf("%c", p[-i] - ('a' - 'A'));
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
		if (*p == '.' || *p == '!' || *p == ' ' || *p == 0)
		//해당 문자열을 만날 때 반대로 출력한 뒤 나머지 출력
		{
			if (cnt != 0)
			{
				reverse(cnt, p);
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
#endif // 0

#if 0
//Uniqueness
//N개의 문자열이 주어졌을 때, 동일한 문자열이 존재하는지 판단하는 프로그램을 작성하라.

//문자열들을 정렬한 뒤, 이들을 앞뒤로 비교하면서 유일성 체크
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
void strnull(char *p)
{
	*p = 0;
}

int main(void)
{
	char str[10000][21] = { 0 };
	int a[10000][2];
	int i, j;
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
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(str[i], str[j]) == 0 && str[j][0] != 0) //문자열 정렬
			{
				unique = 0;
				strnull(str[j]);
				if (again == 0) //문자열 출력
				{
					printf("%s %d %d", str[i], i + 1, j + 1);
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
		if (print == 1) printf("\n");
		print = 0;
	}
	if (unique == 1) printf("unique");
}
#endif // 0

#if 0
//단어 세기
//임의의 문장을 입력 받아 각 단어 별로 나눈 후에 단어들의 중복되는 개수를 구하는 프로그램을 작성하시오.
//(1) 입력된 스트링은 글자의 제한은 없다. 즉 공백이나 ', ' 등도 입력으로 들어 올 수 있다.
//(2) 입력된 문장에서 각 단어 사이의 구분은 공백으로 한다.
//(3) 단어에는 공백을 제외한 단어들만이 포함된다.

//공백을 만났을 때, 이전의 문자들을 배열에 저장
//이를 통해 중복되는 단어들의 숫자 측정
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
	int i, j, k;
	int cnt;
	for (;;)
	{
		gets(ch);
		if (strcmp(ch, "END") == 0) break; //종료 조건
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
				if (strcmp(str[i], str[j]) == 1) //문자열 정렬
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
#endif // 0
