#if 0
//���Ӻκ��ִ��
//N���� ���� �Ǽ��� ���� ��, �� �� �̻��� ���ӵ� ������ ���� �ִ밡 �Ǵ� �κ��� ã��, �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���� ������ų ��, ������� 1���� �۾��� ��� �������� �ʱ�ȭ, �ش� ��ġ���� �ٽ� ���� ����

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

		mul *= a[i]; //���� ���� ����
		if (mul_former<mul) mul_former = mul; //���� ���� ���� ������ ���� ��� �״�� ����
		if (mul < 1) mul = 1; //�������� 1���� ���� ��� �ʱ�ȭ

	}
	printf("%.3f", mul_former);
}
#endif // 0

#if 0
//��ģ����
//������ ���� ������ �ִ�. 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5... (���� k�� ���޾� k�� ������ ����).���� n�� �־����� ��, �ش� �������� n��° ������ ���ڸ� ����ϴ� ���α׷��� �ۼ��϶�.������ ù ��° ���Ҵ� 1�̴�.

//���� ������ Ȱ��, ��谪�� �˾Ƴ� ���� �ذ�
//���� �ſ� ũ�ٴ� ���� ���, long long�� ����ϴ� �Ϳ� ����
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

	i = sqrt(2 * n + 0.25); //���� ������ Ȱ��

	if (i*(i + 1) >= 2 * n) printf("%lld", i);
	else printf("%lld", i + 1);
}
#endif // 0

#if 0
//��������
//���簢�� ������ ���� ���� ������ �� ���� ������ ���� ���� ������ ����� �Ѵ�.
//���� ���̿� ���� �ڱ����� ���縦 ^��, ���� V�� ��Ÿ�� ��, ���簢�� ���̸� �� �� ������ ���⸦ ������ �� ������� ��ġ��, ���� �ڱ��� ���ʿ��� ���������� ���ʴ�� ^VV�� ����� �ȴ�. ���簢�� ���̸� �� �� ������ ���⸦ ������ �� ������� ��ġ��, ���� �ڱ��� ���ʿ��� ���������� ���ʴ�� ^^VV^VV�� ����� �ȴ�.
 
//���簢�� ���̸� ������ ���⸦ ������ �� ������� ��ĥ ��, ���� �ڱ��� ���ʿ��� ���������� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���̸� ���� �� ���� ����� ���� ^V^V...�� ����� �ݺ��ϸ� ���ο� ������ ���� �ִ� ���� ���̿� ������
//���� ���� ����� ���� ��ġ�� �ֱ⸦ ã�Ƴ��� ���� �Է�
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


		for (i = 0; i < m; i++) //���̸� ���� �� ���� ����� ������ ǥ�� 
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
//���ڿ� �����⥱
//�ִ� ���� 50������ ���ڿ��� �Է� �޾� �ܾ� ���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// �ִ� ���� 50������ ���ڿ��� �Էµȴ�.
�׸��� ".", "!"�� �ܾ� �� �ڿ��� �� �� ������, "!!"�� ���� ����ǥ�� ���� �� �����ؼ� �Էµ� �� �ִ�.

//���ڿ� �������� ��ġ�� �̵���Ű�� ī��Ʈ�� ����, "."�� "!"�� �� �� �ݴ�� ���ڿ� ���
char ch[51];
void reverse(int n, char *p) //���ڿ��� �Ųٷ� ����ϴ� �Լ�
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
		//�ش� ���ڿ��� ���� �� �ݴ�� ����� �� ������ ���
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
//N���� ���ڿ��� �־����� ��, ������ ���ڿ��� �����ϴ��� �Ǵ��ϴ� ���α׷��� �ۼ��϶�.

//���ڿ����� ������ ��, �̵��� �յڷ� ���ϸ鼭 ���ϼ� üũ
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
			if (strcmp(str[i], str[j]) == 0 && str[j][0] != 0) //���ڿ� ����
			{
				unique = 0;
				strnull(str[j]);
				if (again == 0) //���ڿ� ���
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
//�ܾ� ����
//������ ������ �Է� �޾� �� �ܾ� ���� ���� �Ŀ� �ܾ���� �ߺ��Ǵ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//(1) �Էµ� ��Ʈ���� ������ ������ ����. �� �����̳� ', ' � �Է����� ��� �� �� �ִ�.
//(2) �Էµ� ���忡�� �� �ܾ� ������ ������ �������� �Ѵ�.
//(3) �ܾ�� ������ ������ �ܾ�鸸�� ���Եȴ�.

//������ ������ ��, ������ ���ڵ��� �迭�� ����
//�̸� ���� �ߺ��Ǵ� �ܾ���� ���� ����
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
		if (strcmp(ch, "END") == 0) break; //���� ����
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
				if (strcmp(str[i], str[j]) == 1) //���ڿ� ����
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
