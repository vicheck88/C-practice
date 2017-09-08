#if 0
//����� ���� ¦���� ��

//�� ���� A, B�� �Է� �޾Ƽ� A�̻� B������ ������ �� ����� ���� ¦���� ���� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ���, A�� 4�̰� B�� 10�� ���, ����� ������ ¦���� ���� 5, 6, 7, 8, 10���� �� 5���� �����Ѵ�.
//����� ���� ����� ����϶�.

//����� ������ Ȧ���� ��: ������������ �ǹ�
//���� ��ü ������ ������������ �����Ͽ� �� ����

#include <stdio.h>

int N;
int sol;

double sqrt(const double d) //������ ���ϱ�
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

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", b - a + 1 - (int)sqrt(b) + (int)sqrt(a - 1)); //���� �� ������ ������������ ����
	return 0;
}
#endif // 0

#if 0
//�ð��� �ٹ� ����
//A���п����� �ð��� �ٹ��� ����� �ۼ��ϰ� �ִ�.�������� K���� �ð��� �ٹ� ������ �������� ó���ϰ��� �Ѵ�.�� ������ �ð��� �ٹ� ���� ������ �Ʒ��� ����.
//
//1. �ð��� �ٹ��� ���� 1�ð��� �����ϸ�, �ִ� 4�ð����� �����Ѵ�.
//2. �ð��� �ٹ��� ���� �ݾ��� 30�п� 5, 000������ �Ѵ�.
//3. 5�ϰ��� �ð��� �ٹ� �հ谡 15�ð� �̻��̸� �޴� �ݾ��� 5 % �� ���Ͽ� �����Ѵ�.
//4. 5�ϰ��� �ð��� �ٹ� �հ谡 5�ð� �����̸� �޴� �ݾ��� 5 % �� ���Ͽ� �����Ѵ�.
//
//�ð��� �ٹ� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���� ���� ������� �ڵ带 �ۼ�, �ذ�

int main(void)
{
	int i;
	double sum = 0;
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

	if (sum >= 15) money *= 0.95;
	else if (sum <= 5) money *= 1.05;

	printf("%d\n", (int)money);
}
#endif // 0

#if 0
//����ũ �ڸ���
//�ձ� ����ũ�� ���� �������� 1~100�� ��ȣ�� �ο���
// ����ũ�� �� �������� �ڸ� �� �����ϴ� �κ��� �ִ����� ����

//�ڸ��� ���� �� �� ������ ����, �ּ� �ִ밪�� ����
//�ٸ� ������ ��ǥ�� ���� ��ǥ�� ���Ͽ� ��� ��ġ�� �ִ����� ����
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

#if 0
//�հ� ���, ǥ������
//���, ǥ�������� ���ϸ� ��
int main(void)
{
	int n;
	int i;
	int *p;
	int sum = 0;
	double mean;
	double var = 0;
	double std = 0;
	scanf("%d", &n);
	p = calloc(n, sizeof(int)); // �����Ҵ��� ���� ���ϴ� ����� �Ҵ�
	for (i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		sum += p[i];
	}
	mean = 1.0*sum / n;
	for (i = 0; i < n; i++)
	{
		var += (p[i] - mean)*(p[i] - mean) / n;
	}
	std = sqrt(var);
	printf("%d\n", sum);
	if ((int)((mean + 0.05) * 10) % 10 != 0) printf("%.1f\n", mean);
	else printf("%.0f\n", mean);
	if ((int)((std + 0.05) * 10) % 10 != 0) printf("%.1f\n", std);
	else printf("%.0f\n", std);
	free(p);
	return 0;
}
#endif // 0

#if 0
//�ִ��������ּҰ����
//�� �ڿ����� �ִ�����, �ּҰ���� ���ϱ�
int gcd(int x, int y)
{
	int m = 1;
	while (m) //��Ŭ���� ȣ���� ���
	{
		m = x%y;
		x = y; y = m;
	}
	return x;
}
int main(void)
{
	int m, n;
	scanf("%d%d", &n, &m);
	printf("%d\n%d\n", gcd(n, m), n*m / gcd(n, m));
	return 0;
}
#endif // 0

#if 0
//�ִ������� �ּҰ����(������)
//�������� �ִ�����,�ּҰ������ ���ϱ�
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

int lcd(int x, int y) return x*y / gcd(x, y);

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
		scanf("%d", &m[i]); //�ִ�����, �ּҰ������ �����ϸ鼭 ���ϱ�
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

#if 0
//������ å
//������ �缭�� �����̴� ��ȭå�� �� ���� �������ٴ� ���� �˰�, ������ �������� �˾ƺ����� �Ѵ�.�� ��ȭå�� N
//������(N�� ¦��)����, 1, 2���� ���� ���̿� �ְ� �� �ں��� N�ʱ��� �� �ʼ��� �Ű��� �ִ�.�����̴� å�� �ʹ�ȣ
//�� ���� ���ϴ� ��踦 ������ �־��� ������, �ʹ�ȣ�� �� Sum�� ���� �� �־�����, �װ� �̿��ؼ� ������ ������
//�� ��ȣ�� ���ϱ⿡�� �������̾���.
//
//�����̸� ���� ������ �������� ���ϴ� ���α׷��� �ۼ��Ͽ���.

//å�� �������� ¦����� ��, 1,2���� ���� ���̿� �ִٴ� ���� �̿�
//���������� ���� ���̽��� ����ϴ� ���� ������ ��

int main(void)
{
	int n;
	int sum;
	int dif;
	int real_sum;
	scanf("%d %d", &n, &sum);
	if ((n < 2 || n>500) || (sum < 1 || sum>125000) || n & 1) printf("Error");
	real_sum = (1 + n)*n / 2;
	dif = real_sum - sum;
	if (!(dif & 1) || !(dif / 2 & 1) || dif<0 || n<dif / 2 + 1) printf("Error");
	else printf("%d %d", dif / 2, dif / 2 + 1);
}
#endif // 0

#if 0
//�ݸ޴��� ����?
//�� ������ ��ʸ�Ʈ ������� ����Ǹ� 1�� 4��, 2�� 3��, 3�� 2��, �������� 1���� �ش�.���� �򰡴� �� ������
//������ ��� ���Ͽ� ������ ���� ���� ����� 1��, �� ���� ����� 2��...�̷��� ������ ��������, 1���� �ݸ޴�, 2��
//�� ���޴�, 3���� ���޴��� �ش�.�̶� ���� ������ ���� ����� �ϰ� ���� �޴��� �ش�.��, ���� 5, 8, 16, 8, 5, 6
//�̶��, 16���� 1��(�ݸ޴�)1��, 8���� 2�� (���޴�)2��, 6�� 3��(���޴�)1���� �ȴ�.
//
//���� �ο��� �� ������ ������ �־����� �ݸ޴�, ���޴�, ���޴��� �޴� ����� ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���� ������ �̿�, ���ϴ� ����� ����
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
			if (j != 0) p[i][5] += p[i][j];
		}
		id[i] = p[i][0];
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (p[i][5] < p[j][5]) //������ ����
			{
				tmp = p[i][5];
				p[i][5] = p[j][5];
				p[j][5] = tmp;

				tmp = id[i];
				id[i] = id[j];
				id[j] = tmp;
			}
			else if (p[i][5] == p[j][5] && id[i]>id[j]) //������ ���� �� id�� ����
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
		medal[cnt][k] = id[i];
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

#if 0
//����� ��
//���� ���� N(1�̻�, 10, 000�̸�)�� �Է� �޾�, N���� N�� ����� ���� ���ؼ� ���� 10, 000�� ���� �ʵ��� �ϴ� ���� ū N�� ��� K�� �μ��϶�.
//���� ���, N�� 7�̶��, 7 + 14 + 21 + ... + K < 10, 000 �� K �� ���� ū ���� �μ��Ѵ�.
//N�� ������ ����� ���� ���ٰ� �����ϰ�, �̿� ���� ���� ó���� ���� �ʴ´�.

int main(void)
{
	int i;
	int r = 1;
	int sum = 0;
	int n;
	scanf("%d", &n);
	for (i = n; sum < 10000; i += n) //n�� ������� ����
	{
		sum += i;
	}
	printf("%d", i - 2 * n);
	return 0;
}
#endif // 0
