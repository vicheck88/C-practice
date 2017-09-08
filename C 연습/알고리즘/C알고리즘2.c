#if 0
//숫자의 합
//세 자릿수 이하의 양의 정수(1이상, 999이하)를 N(1이상, 100,000이하)개 입력 받아 같은 자릿수의 숫자들끼리만 더해서 각각의 합을 인쇄하라.

//주어진 숫자를 자리수별로 분해, 더함을 반복
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

#if 0
//가장 많은 알파벳은?
//최대 30자의 단어를 입력 받은 후 단어에서 가장 많은 소문자를 인쇄하라.

//문자열을 순차적으로 검색하면서 해당하는 문자의 수를 체크배열을 통해 계산, 구현
int main(void)
{
	char ch[31];
	int i;
	char *p;
	int alphabet[26] = { 0 }; //알파벳의 숫자를 체크하는 배열
	int max = 0;
	char max_alpha;
	scanf("%s", ch);
	p = ch;
	while (*p)
	{
		if (*p >= 'a') alphabet[*p - 'a']++; //문자열을 이동하면서 알파벳 배열에 더함
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
#endif // 0

#if 0
//배열의 순환
//N개의 정수를 입력 받아 왼쪽으로 한 칸씩 Rotate하여 인쇄하라.
//맨 앞의 정수는 맨 뒤로 이동한다.
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

#if 0
//배열 채우기 Ⅱ
//한 정수 n을 입력 받아서 이차원 배열 n*n을 아래와 같이 "ㄹ"자로 채워서 출력하는 프로그램을 작성하시오.
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
			ar[i][(i & 1)*(n - 1) + ((i & 1)*(-2) + 1)* j] = ++num; 
			//ㄹ자로 채울 때의 법칙 파악
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
#endif // 0

#if 0
//숫자 맞추기
//각각의 플레이어는 1이상 100이하의 좋아하는 정수를 카드에 적어서 제출한다.
//각 플레이어는 자신과 같은 수를 쓴 사람이 없을 경우에, 자신이 카드에 쓴 만큼의 점수를 얻는다.
//자신과 같은 수를 쓴 사람이 있는 경우에는 득점할 수 없다.
//경곽이와 친구들은 게임을 3번 했다.각 플레이어가 3번 게임에 대해서 쓴 카드의 정수가 주어질 때, 각 플레이어가 3번 게임에서 얻는 점수의 합계를 구하는 프로그램을 작성하시오.

// 같은 카드가 있을 경우 해당 카드들을 전부 0으로 만듦
int main(void)
{
	int n;
	int i, j, k;
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
			for (k = i + 1; k < n; k++) //i보다 뒤에 있는 카드들을 비교
			{
				if (card[i][j] == card[k][j] && card[i][j] != 0)
				{
					zero = 1; 
					card[k][j] = 0; //같은 카드가 있을 경우
				}
			}
			if (zero == 1) //뒤의 카드들을 0으로 만든 뒤, 해당 카드를 0으로 만듦
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

#endif // 0

#if 0
//순환 순열
//두 자연수 N과 P를 가지고 다음 과정을 거쳐서 나오는 숫자들을 차례대로 출력해보자.
//처음 출력하는 숫자는 N이고, 두 번째 이후 출력하는 숫자들은 N을 곱하고 P로 나눈 나머지를 구하는 과정을 반복하여 구한다.
//즉, 먼저 N에 N을 곱하고, 이 수를 P로 나눈 나머지를 두 번째에 출력한다.
//다음에는 이 나머지에 N을 곱하고 P로 나눈 나머지를 출력한다.다음에는 이 나머지에 을 N곱한 후 P로 나눈 나머지를 출력한다.
//이 과정을 계속 반복해보면 출력되는 숫자들에는 반복되는 부분이 있다.
//예를 들어서, N = 67, P = 31인 경우를 생각해보자.처음 출력되는 숫자는 67이고, 두 번째로 출력되는 숫자는 67 * 67 = 4489를 31로 나눈 나머지 25이다. 다음에는 25 * 67 = 1675를 31로 나눈 나머지 1, 다음에는 1 * 67 = 67을 31로 나눈 나머지 5가 차례대로 출력된다.
//다음에는 5 * 67 = 335를 31로 나눈 나머지 25가 출력되는데, 이 수는 이미 이전에 출력된 수이다.

//체크배열을 준비, 숫자에 해당하는 부분을 하나씩 증가
//숫자가 2가 되는 경우 순환순열이 시작함을 알 수 있음
//2가 되는 수의 뒷부분의 수를 계산하여 원하는 결과 획득

int main(void)
{
	int n;
	int p;
	int i, j;
	int cnt = 0;
	int ar[1000] = { 0 };
	int br[1000] = { 0 };
	scanf("%d %d", &n, &p);
	ar[0] = n;
	br[0] = 1;
	for (i = 1;; i++)
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
		if (br[j] == 2) break; // 배열의 값이 2가 될때까지 순열 계산
	}
	for (i = j; br[i] != 0; i++) ++cnt; //2가 된 배열의 뒷부분의 수를 구함
	printf("%d", cnt);
	return 0;
}
#endif // 0

#if 0
//6174
/ Kaprekar 연산은 네 자리 수 중 모든 자리수가 같지 않은 수(1111, 2222 등을 제외한)의 각 자리의 숫자를 재배열해서 만들 수 있는 가장 큰 수와 가장 작은 수를 만들어서 그 차이를 계산하는데, 그 결과로 나온 새로운 숫자를 갖고 같은 과정을 반복하는 것이다.
//이를 이용하여 계산할 떄, 6174가 나오는 최소의 숫자를 구하라

//6174가 나올 때까지 해당 숫자에서 최대, 최소값을 구해 차이를 계산

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
				if (min[i] < min[j])
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
#endif // 0

#if 0
//합의 회문수
//수 124를 뒤집으면 421이 되고 이 두 수를 합하면 545가 된다. 124와 같이 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되는지 테스트하는 프로그램을 작성하시오.

//수를 뒤집은 뒤 이를 테스트
int reverse(int x) //수를 뒤집어 거꾸로 된 값을 구하는 함수
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
	int i, j;
	int cnt = 0;
	int a[100];
	int b[7];
	char result[100][4];
	int sum;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum = a[i] + reverse(a[i]); //원래값과 거꾸로의 값의 합을 구함
		while (sum)
		{
			b[cnt] = sum % 10; //구한 값이 좌우대칭인지를 테스트
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
#endif // 0

#if 0
//정수론 몫과 나머지
//첫 줄에 3개의 자연수를 같은 수로 나누었을 때, 같은 수의 나머지가 남도록 하는 정수 중에서 가장 큰 것을 출력한다.

//정수 A와 B를 같은 양의 정수 M으로 나누었을 때 나머지가 같다면 (A-B)는 M으로 나누어 떨어진다.
//따라서, 세 수 중 두개씩 골라 차이를 구한 뒤, 그 차이들의 최대공약수를 구하면 문제 해결

int abs(int x, int y)
{
	return (x > y) ? x - y : y - x;
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

	gc = gcd(gcd(a[0], a[1]), a[2]); //차이들의 최대공약수를 구함
	printf("%d", gc);
}
#endif // 0

#if 0
//앞뒤 같은 제곱
//'앞뒤 같은 수'란 앞에서부터 읽으나 뒤에서부터 읽으나 동일한 수를 말한다.수 12321 이 '앞뒤 같은 수'의 예가 될 수 있다.
//N(1≤N≤300, 10진수)중에서 N ^ 2이 B(2≤B≤20, 10진수)진수로 표현했을 때, '앞뒤 같은 수'가 될 때의 N과 N ^ 2를 B진수로 출력하라.
//진수표현에 있어 10, 11 그리고 이상의 수들은 'A', ’B’로 표현한다.

//주어진 값의 각 자리수를 원하는 진법으로 바꾼 뒤 배열에 저장
//이를 통해 제곱의 값들을 테스트한 뒤 원하는 진법으로 변환

int a[100] = { 0 };
int b[30] = { 0 };
int decimal(int x, int decimal) //진법 변환 함수
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
int decimal_square(int x, int decimal) //진법 변환 함수(두번째)
{
	int r = 1;
	int cnt = 0;
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
	int i, j, k;
	int rev = 0;
	scanf("%d", &n);


	for (i = 1; i <= 300; i++)
	{
		dec = decimal_square(i*i, n);

		for (j = 0; j < dec / 2; j++)
		{
			if (a[j] != a[dec - 1 - j]) break; //제곱수를 거꾸로 돌려 차이를 구함
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
#endif // 0
