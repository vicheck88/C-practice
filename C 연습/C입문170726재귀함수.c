#include <stdio.h>
#if 0
//연습문제 D
void func(int n)
{
	if (n == 0) return;
	func(n - 1);
	printf("%d\n", n);

}

void main(void)
{
	int n;
	scanf("%d", &n);
	func(n);
}
#endif // 0

//연습문제 E
#if 0
int N;

void func(int num)
{
	if (num > N) return;
	func(num + 1);
	printf("%d\n", num);
}
void main(void)
{
	scanf("%d", &N);
	func(1);
}
#endif // 0

//연습문제 F
#if 0
int sum(int num)
{
	if (num == 0) return 0;
	return num + sum(num - 1);
}
int main(void)
{
	int N;
	// 여기서부터 작성
	scanf("%d", &N);
	printf("%d", sum(N));

	return 0;
}
#endif // 0


//연습문제 G

#if 0
int N;

void star(int num)
{
	int i;
	static int dir = 1;
	if (num == 0) return;

	if (num == N) dir = -1;

	for (i = 0; i < num; i++) printf("*");
	printf("\n");
	star(num + dir);
}

int main(void)
{
	scanf("%d", &N);
	star(1);
	return 0;
}
#endif // 1

#if 0
void main(){
	int i, a[4];
	for (i = 0; i < 4; i++)
	{
		a[i] = i * 10;
	}
	printf("%d %d %d %d", a[0], a[1], a[2], a[3]);
}
#endif // 0


//예제 3
#if 0
void main()
{
	int n;
	int i;
	int b[10] = { 34, 11, 56, 74, 34, 76, 10, 45, 92, 10 };
	scanf("%d", &n);
	for (i = 0; i < 10; i++)
	{
		if (b[i] == n) break;
	}
	if (i == 10) printf("꽝!\n");
	else printf("%d %d\n", n, i + 1);
}
#endif // 0

//예제 4
#if 0
void main()
{
	int a[20];
	int i, min =0x7fffffff, max = 0x80000000;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		scanf("%d", &a[i]);
		if (min>a[i]) min = a[i];
		if (max < a[i]) max = a[i];
	}

	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
		
	}
	printf("%d,%d", min, max);
}
#endif // 1

//예제 6
#if 0
void main()
{
	int a[5], cnt = 0;
	int i;
	for (i = 15; i <= 100; i += 15)
	{
		a[cnt++] = i;
		printf("%d ", a[cnt - 1]);
		if (cnt == 5) break;
	}
}
#endif // 0


//예제 7
#if 0
void main()
{
	int a[10], cnt = 0;
	int i;
	for (i = 15; i <= 100; i += 15)
	{
		a[cnt++] = i;
		if (cnt == 10) break;
	}
	for (i = 0; i < cnt; i++)
	{
		printf("%d ", a[i]);
	}
}
#endif // 0
#if 0
void main()
{
	int a[10], cnt = 0;
	int i;
	for (i = 15; i <= 100; i += 15)
	{
		a[cnt++] = i;
		printf("%d ", a[cnt - 1]);
		if (cnt == 10) break;
	}
}
#endif // 0

//예제 8
#if 0
void main()
{
	int a[20];
	int i, j;
	int tmp;
	for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		for (j = i + 1; j < sizeof(a) / sizeof(a[0]); j++)
		{
			if (a[i]>a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		printf("%d ", a[i]);
	}
}
#endif // 1

//예제 9,10번
#if 0
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, pass;
	char password[27] = "QWERTYUIOPLKJHGFDSAZXCVBNM";
	printf("A-Z 사이 문자를 입력하시오. 이외 글자는 종료합니다\n");
	/*for (;;)
	{
	pass = getch();
	if (pass<'A' || pass>'Z') break;
	else printf("%c => %c\n", pass,password[pass - 'A']);
	}*/ //9번

	for (;;)
	{
		pass = getch();
		if (pass<'A' || pass>'Z') break;
		else
		{
			for (i = 0; i < 27; i++)
			{
				if (pass == password[i])
				{
					printf("%c => %c\n", pass, 'A' + i);
					break;
				}
			}
		}
	} // 10번
}
#endif // 0

//11번
#if 0
char grade(int score)
{
	char grades[7] = "XFDCBA";
	if (!(0 <= score && score <= 100)) return grades[0];
	else{
		score = 1 + (score - 1) / 60 + (score - 1) / 70 + (score - 1) / 80 + (score - 1) / 90;
		return grades[score];
	}
}

void main()
{
	int n;
	scanf("%d", &n);
	printf("Score:%4d ==> %c", n, grade(n));
}
#endif // 0

//워크샵 2번
#if 0
void hello(int n)
{
	printf("Hello\n");
	if (n == 1) return;
	hello(n - 1);
}
void main()
{
	int n;
	scanf("%d",&n);
	hello(n);
}
#endif // 0

//워크샵 3번
#if 0
int sum(int n)
{
	if (n == 0) return 0;
	return n + sum(n - 1);
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", sum(n));
}
#endif // 0
//워크샵 4번
#if 0
int odd_sum(int n)
{
	if (n < 1) return 0;
	return (n - 1 + n % 2) + odd_sum(n - 2);
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", odd_sum(n));
}
#endif // 0

//워크샵 5번
#if 0
int pow(int x, int y)
{
	if (y == 0) return 1;
	return x*pow(x, y - 1);
}
void main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d", pow(x, y));
}
#endif // 0

//워크샵 7번
#if 0
void main()
{
	int a[5];
	int i, j, tmp;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 4; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}

}
#endif // 0

//워크샵 8번
#if 0
void main()
{
	int a[5];
	int i, max = 0x80000000;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
		if (max < a[i]) max = a[i];
	}
	printf("%d\n", max);
}
#endif // 0

//워크샵 9번
#if 0
void main()
{
	int a[5];
	int i, sum=0,avg;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	avg = sum / 5;
	for (i = 0; i < 5; i++)
	{
		if (a[i] < avg) printf("%d ", avg - a[i]);
		else printf("%d ", a[i] - avg);
	}
}
#endif // 0

//워크샵 10번
#if 0
void main()
{
	int n, m;
	int i, j, cnt = 0;
	int a[10];
	scanf("%d%d", &n, &m);
	for (i = n; i <= m; i++)
	{
		for (j = 2; j <= i / 2; j++)
		{
			if (i%j == 0) break;
		}
		if (j == i / 2 + 1) a[cnt++] = i;
		if (cnt == 10) break;
	}
	for (i = 0; i < cnt; i++)
	{
		printf("%d ", a[i]);
	}
}
#endif // 0

//워크샵 11번
#if 0
void main()
{
	int i, j, tmp;
	int a[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (a[i] < a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		printf("%d ", a[i]);
	}
}
#endif // 0

//워크샵 12번
#if 0
void main()
{
	char string[51], ch;
	int i, cnt = 0;

	scanf("%s %c", string, &ch);

	for (i = 0; i < 50; i++)
	{
		if (string[i] == '\0') break;
		else
		{
			if (string[i] == ch)
			{
				cnt++;
			}
		}

	}
	printf("%d\n", cnt);
}
#endif // 0

//워크샵 14번
#if 0
void main()
{
	char num[51];
	int i, j, cnt[10] = { 0 };
	scanf("%s", num);
	for (i = 0; i < 50; i++)
	{
		if (num[i] == '\0') break;
		cnt[num[i] - '0']++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", cnt[i]);
	}
}
#endif // 0

//워크샵 15번
#if 0
void main()
{
	char string[51];
	int i, cnt = 0,k;
	scanf("%s", string);
	for (i = 0; i < 50; i++)
	{
		if (string[i] == '\0') break;
		else
		{
			if (islower((int)string[i]))
			{
				cnt++;
				printf("%c", string[i]);
				if (cnt == 10) break;


			}
		}
	}
}
#endif // 1

