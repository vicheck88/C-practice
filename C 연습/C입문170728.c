//8과 예제 14
#if 0
struct stu
{
	char name[20];
	int score;
};

struct stu student[10];

void get_data()
{
	int i;
	for (i = 0; i < sizeof(student)/sizeof(student[0]); i++)
	{
	score:
		printf("%d번째 학생\n", i + 1);
		printf("이름: ");
		scanf("%s", student[i].name);
		printf("점수: ");
		scanf("%d", &student[i].score);
		if (student[i].score < 0 || student[i].score>100)
		{
			printf("잘못된 점수입니다. 다시 입력하세요.\n");
			goto score;
		}
	}
}

void sort()
{
	int i, j;
	struct stu tmp;
	for (i = 0; i < sizeof(student) / sizeof(student[0])-1; i++)
	{
		for (j = i + 1; j < sizeof(student) / sizeof(student[0]); j++)
		{
			if (student[i].score>student[j].score)
			{
				tmp = student[i];
				student[i] = student[j];
				student[j] = tmp;
			}
		}
	}
}

double avg(void)
{
	int i, sum = 0;
	for (i = 0; i < sizeof(student) / sizeof(student[0]); i++)
	{
		sum += student[i].score;
	}
	return (double)sum / (sizeof(student) / sizeof(student[0]));
}

void print_score(void)
{
	int i;
	for (i = 0; i < sizeof(student) / sizeof(student[0]); i++)
	{
		printf("이름: %s  점수: %d\n", student[i].name, student[i].score);
	}
}

void main()
{
	int i, j, tmp;
	get_data();
	sort();
	print_score();
	printf("평균: %.1f\n", avg());
}
#endif // 0


//워크샵 1번
#if 0
void main()
{
	int i, j, a[25], b[5][5];
	int cnt = 0;
	int n;
	srand((unsigned int)time(0));

	while (cnt <= 24)
	{
		n = rand() % 99 + 1;
		for (j = 0; j < cnt; j++)
		{
			if (n == a[j]) break;
		}
		if (j == cnt)
		{
			a[j] = n;
			cnt++;
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			b[i][j] = a[5 * i + j];
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

}
#endif // 0

// 워크샵 2번
#if 0
void main()
{
	char ch[101];
	int i, cnt;
	scanf("%s", ch);

	for (i = 0; i < 101; i++)
	{
		if (ch[i] == '\0')
		{
			cnt = i;
			break;
		}
	}
	for (i = cnt - 1; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}
}
#endif // 0

//워크샵 3번
#if 0
void main()
{
	char a[51], b[51];
	int i, j, cnta, cntb, cnt = 0;
	scanf("%s", a);
	scanf("%s", b);
	for (i = 0; i < 51; i++)
	{
		if (a[i] == '\0')
		{
			cnta = i; break;
		}
	}
	for (i = 0; i < 51; i++)
	{
		if (b[i] == '\0')
		{
			cntb = i; break;
		}
	}

	for (i = 0; i < cnta; i++)
	{
		if (a[i] == b[0])
		{
			for (j = i; j < i + cntb; j++)
			{
				if (a[j] == '\0') break;
				else if (a[j] != b[j - i]) break;
				else cnt++;
			}
			if (cnt == cntb) break;
			cnt = 0;
		}
		if (cnt == cntb) break;
	}
	if (cnt == 0) printf("NO\n");
	else printf("YES\n");
}
#endif // 0

//워크샵 4번
#if 0
void main()
{
	int a[10][10];
	int i, j, k, m;
	int sum = 0, max = 0x80000000;
	int max_elt[2];
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			for (k = i; k < i + 3; k++)
			{
				for (m = j; m < j + 3; m++)
				{
					sum += a[k][m];
				}
			}
			if (sum > max)
			{
				max = sum;
				max_elt[0] = k - 3;
				max_elt[1] = m - 3;
			}
			sum = 0;
		}
	}
	printf("%d %d %d", max_elt[0], max_elt[1], max);
}
#endif // 0

//워크샵 5번

#if 1
void main()
{
	int i, j, k, n;
	int ans[3];
	int cnt = 0;
	int guess[3];
	int strike = 0, ball = 0;
	int tmp;
	int sum = 1;

	//srand((unsigned int)time(0));

	while (cnt < 3)
	{
		n = rand() % 8 + 1;
		for (j = 0; j < cnt; j++)
		{
			if (n == ans[j]) break;
		}
		if (j == cnt)
		{
			ans[j] = n;
			cnt++;
		}
	}
	printf(">>>>> 야구 게임 <<<<<\n");
	printf("규칙 : 1~9사이, 중복없이 3자리 입력\n");
	for (i = 0; i < 10; i++)
	{
		printf("입력 : ");
		scanf("%d%d%d", &guess[0], &guess[1], &guess[2]);
		printf("===> ");

		for (j = 0; j < 3; j++)
		{
			strike += (ans[j] == guess[j]);
			if (strike == 0)
			{
				for (k = 0; k < 3; k++)
				{
					if (ans[j] == guess[k]) ball++;
				}
			}
		}

		if (strike == 3)
		{
			printf("정답\n");
			break;
		}

		else printf("%d strike %d ball\n", strike, ball);
		ball = 0;
		strike = 0;
	}
}
#endif // 0

#if 0
void main()
{
	int i, cnt = 0, tmp;
	int a[10], b[10] = { 0 };
	int n;
	srand((unsigned int)time(0));
	for (i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	for (i = 10; i > 0; i--)
	{
		n = rand() % i;
		tmp = a[i - 1];
		a[i - 1] = a[n];
		a[n] = tmp;
		b[i - 1] = a[i - 1] + 1;
	}
	for (i = 0; i < 10; i++) printf("%d ", b[i]);
}
#endif // 1
