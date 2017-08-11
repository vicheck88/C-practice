//배열 transpose
#if 0
void main()
{
	int i, j,num=0;
	int a[4][4];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			a[i][j] = ++num;
		}
	}
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			printf("%2d ", a[2-i][3-j]);
		}
		printf("\n");
	}
}
#endif

//배열 transpose 응용
#if 0
void main()
{
	int i, j, k, cnt = 0;
	int a[100][100] = { 0 };
	int n;
	scanf("%d", &n);
	if (!(1 <= n && n <= 100 && n % 2 == 1)) printf("INPUT ERROR");
	else
	{
		for (i = 0; i < n / 2 + 1; i++)
		{
			for (j = n / 2 - i; j <= n / 2 + i; j++) a[i][j] = (cnt++ % 26) + 65;
		}

		for (j = 0; j < n; j++)

		{
			for (i = 0; i < n / 2 + 1; i++)
			{
				if (a[n / 2 - i][j] == 0) printf("  ");
				else printf("%c ", a[n / 2 - i][j]);
			}
			printf("\n");
		}
	}
}
#endif // 0

// 가위 바위 보 예제
#if 0
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main()
{
	int n, i, cnt = 0;
	int pc;
	int result[10];
	char s[3][10] = { "가위", "바위", "보" };
	char win[3][30] = { "Same", "You win", "Pc win" };
	int table[3][3] = { 0, 1, 1, 2, 0, 1, 2, 2, 0 };

	srand((unsigned int)time(0));

	for (;;)
	{
		scanf("%d", &n);
		printf("You : %s\n", s[n]);
		pc = rand() % 3;
		printf("PC : %s\n", s[pc]);
		printf("%s\n", win[table[pc][n]]);

		if (table[pc][n] == 1) cnt++;
		if (cnt == 3) break;
	}
}
#endif // 0



//빙고

#if 0
#include <stdio.h>

int a[6][6];
int arr[25];
int cross[2];

void get_array();
void get_random_array();
void find_num(int);
void display_table();
int check_bingo();

void main()
{
	int n;
	int check;
	get_array();
	display_table();
	do
	{
		printf("번호를 입력하세요 : ");
		scanf("%d", &n);
		find_num(n);
		display_table();
		if (check_bingo() == 1) printf("BINGO!!!!\n");
	} while (check_bingo() != 1);

}

void get_array()
{
	int i, j, cnt = 0;

	get_random_array();

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = arr[5 * i + j];
			a[i][5] += a[i][j];
			a[5][j] += a[i][j];
		}
		cross[0] += a[i][i];
		cross[1] += a[i][4 - i];
	}
}

void get_random_array()
{
	int cnt = 0;
	int n, i;
	srand((unsigned int)time(0));
	while (cnt < 25)
	{
		n = rand() % 25 + 1;
		for (i = 0; i < cnt; i++)
		{
			if (arr[i] == n) break;
		}
		if (i == cnt)
		{
			arr[cnt] = n;
			cnt++;
		}
	}
}

void find_num(int num)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		if (arr[i] == num)
		{
			a[i / 5][i % 5] = 0;
			a[i / 5][5] -= num;
			a[5][i % 5] -= num;
			if (i / 5 == i % 5) cross[0] -= num;
			else if (i / 5 == 4 - i % 5) cross[1] -= num;
			break;
		}
	}
}

void display_table()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] == 0) printf("%2c ", 'X');
			else { printf("%2d ", a[i][j]); }
		}
		printf("\n");
	}
}

int check_bingo()
{
	int i, sum = 1;
	for (i = 0; i < 5; i++)
	{
		if (a[i][5] == 0 || a[5][i] == 0)
		{
			return 1;
		}
	}
	if (i == 5 && (cross[0] == 0 || cross[1] == 0)) return 1;
	else return 0;
}
#endif // 0

//워크샵 2번
#if 0
void main()
{
	int i, j, cnt = 0;
	int a[4][5] = { 0 };

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][4] += a[i][j];
			a[3][j] += a[i][j];
		}
		/*cross[0] += a[i][i];
		cross[1] += a[i][4 - i];*/
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d ", a[i][4]);
	}
	printf("\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d ", a[3][i]);
	}
	printf("\n");

	/*cross[0] += a[i][i];
	cross[1] += a[i][4 - i];*/
}
#endif // 0


//워크샵 3번

#if 0
void main()
{
	int a[3][3];
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 2; i >= 0; i--)
	{
		for (j = 2; j >= 0; j--)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
#endif // 0

// 워크샵 4번
#if 0
void main()
{
	int n, max, min;
	int i, j;
	int a[10][10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand();
		}
	}
	max = a[0][0];
	min = a[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] > max) max = a[i][j];
			if (a[i][j] < min) min = a[i][j];
		}
	}
	printf("%d %d", min, max);
}
#endif // 0

//워크샵 5
#if 0
void main()
{
	int i, j;
	int n, cnt;
	int a[10][10];
	scanf("%d", &n);
	cnt = n*n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) printf("%d ", cnt--);
		printf("\n");
	}
}
#endif // 0

//워크샵 6
#if 0
void main()
{
	int i, j, a[19][19] = { 0 };
	int n, cnt = 1;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for(j=n-1-i;j<=n-1+i;j++)
			a[i][j]=cnt++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2*n-1; j++)
		{
			if (a[i][j] == 0) printf("   ");
			else printf("%3d", a[i][j]);
		}
		printf("\n");

	}
}
#endif // 0



//워크샵 7
#if 0
void main()
{
	int i, j, cross[2] = { 0 };
	int a[4][4] = { 0 }, sum = 0;;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][3] += a[i][j];
			a[3][j] += a[i][j];
			sum += a[i][j];
		}
		cross[0] += a[i][i];
		cross[1] += a[i][2 - i];
	}
	a[3][3] = sum;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", cross[1], cross[0]);
}
#endif // 0

//워크샵 추가 1
#if 0
void main()
{
	int i, j, cross[2] = { 0 };
	int a[4][4] = { 0 }, sum = 0;;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][3] += a[i][j];


		}

	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

}
#endif // 0

//워크샵 추가 2
#if 0
void main()
{
	int i, j, max, max_stu;
	int a[4][4] = { 0 }, sum = 0;;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][3] += a[i][j];
		}
	}
	max = a[0][3];
	max_stu = 0;
	for (i = 0; i < 4; i++)
	{
		if (a[i][3] > max)
		{
			max = a[i][3];
			max_stu = i;
		}
	}
	printf("%d", max_stu);
}

#endif // 0

//워크샵 추가 3
#if 0
void main()
{
	int i, j, max, max_stu;
	int a[4][4] = { 0 }, sum = 0;;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	max = a[0][2];
	max_stu = 0;
	for (i = 0; i < 4; i++)
	{
		if (a[i][2] > max)
		{
			max = a[i][2];
			max_stu = i;
		}
	}
	printf("%d", max_stu);
}
#endif // 0

//워크샵 추가 4
#if 0
void main()
{
	int i, j, min, min_stu;
	int a[5][4] = { 0 }, sum = 0;;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
			a[4][j] += a[i][j];
		}
	}
	min = a[4][0];
	min_stu = 0;
	for (i = 0; i < 3; i++)
	{
		if (a[4][i] < min)
		{
			min = a[4][i];
			min_stu = i;
		}
	}
	printf("%d", min_stu);
}
#endif // 0

//워크샵 추가 5
#if 0
void main()
{
	int a[10];
	int i;
	int cnt = 0;
	int del;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &del);
	for (i = 0; i < 10; i++)
	{
		if (a[i] == del)
		{
			cnt = i;
			break;
		}
	}
	if (i == 10) printf("ERROR");
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (i != cnt) printf("%d ", a[i]);
		}
		printf("0 ");
	}
}
#endif // 0
