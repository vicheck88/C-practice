#if 0
//������(��)
//����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ���� �ִ�.�� ��ȭ�� ���� ����, ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ �����̸� �������� ���� ��ȭ���� ���� �����ϵ��� ���δ�.�̷��� ������� �����̸� �� �� �Ǵ� ���� �� ���� �� �����̰� ���� ���� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���� 100, ���� 100�� �迭�� ����� �־��� ��ǥ�� ���� �������� ������ �ش��ϴ� �κ��� �ٸ� ���ڷ� ä��
//�ٸ� ���ڵ��� ������ ���ϸ� ��ü ���̸� ���� �� ����
#include <stdio.h>
int paper[100][100] = { 0 };
int main(void)
{
	int n;
	int width;
	int height;
	int i, j, k;
	int cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &width, &height);
		for (j = width; j < width + 10; j++)
		{
			for (k = height; k < height + 10; k++)
			{
				paper[j][k] = 1; //�����̿� �ش��ϴ� �κ��� 1�� ä��
			}
		}
	}
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (paper[i][j] == 1) cnt++; //1�� ������ ����
		}
	}
	printf("%d", cnt);
	return 0;
}
#endif // 0
#if 0
//������(��)
//����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ���� �ִ�. �� ��ȭ�� ���� ����, ������ ũ�Ⱑ ���� 10�� ���簢�� ����� ������ �����̸� �������� ���� ��ȭ���� ���� �����ϵ��� ���δ�. �̷��� ������� �����̸� �� �� �Ǵ� ���� �� ���� �� �����̰� ���� ���� ������ �ѷ��� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//�迭�� ���� �������� ������ 1�� ä��. �� �� 0�� �´�� �ִ� 1�� ������ ���Ͽ� �ѷ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int paper[102][102] = { 0 };
int main(void)
{
	int n;
	int width;
	int height;
	int i, j, k;
	int cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &width, &height);
		for (j = width + 1; j <= width + 10; j++)
		{
			for (k = height + 1; k <= height + 10; k++)
			{
				paper[j][k] = 1;
			}
		}
	}
	for (i = 0; i < 102; i++)
	{
		for (j = 0; j < 102; j++)
		{
			if (paper[i][j] == 1) //1�� �κ��� ��ó�� 0�� �ִ����� �Ǵ��Ͽ� �ѷ��� ����
			{
				if (paper[i - 1][j] == 0 || paper[i + 1][j] == 0 ||
					paper[i][j - 1] == 0 || paper[i][j + 1] == 0) cnt++;

				if (paper[i - 1][j] == 0 && paper[i][j - 1] == 0) cnt++;
				else if (paper[i - 1][j] == 0 && paper[i][j + 1] == 0) cnt++;
				else if (paper[i + 1][j] == 0 && paper[i][j - 1] == 0) cnt++;
				else if (paper[i + 1][j] == 0 && paper[i][j + 1] == 0) cnt++;
			}

		}
	}
	printf("%d", cnt);
	return 0;
}
#endif // 0

#if 0
//�Ǽ�
//R�� C���� ���� ����� ������ �� ���� ����� �� �ִ�.�� ���ڿ��� �ִ� �� ���� ����� �ִ�.
//�� ������� �ڽŰ� ������ ����� ��Ȯ�� �� ���� �Ǽ��ϴµ�, ������ ����� �Ʒ� �׸��� ���� ���� 8���⿡ �ִ� ����� ���Ѵ�.
//�����̴� �� ������ �� ���� �� �� ���� ���� �� �������� �Ͼ �Ǽ��� �� Ƚ���� �ִ밡 �ǰ� �Ϸ��� �Ѵ�.�����̰� �� �� �� �������� �Ͼ �Ǽ��� �� Ƚ���� ���Ͽ���.���� �� ���ڰ� ���ٸ� �����̴� �ƹ� �ൿ�� ���� �ʴ´�.

//�� �� �ִ� �κ��� �ֺ��� �����Ͽ� ������ �� �� �Ǽ� Ƚ���� ���� ���� �þ�� ������ �˻�
//����, ��ü �Ǽ� Ƚ�� �˻�: �Ǽ��� �ᱹ �� ���� �մ� ������ �� �� ������, ������ ��ü degree�� ���� ���ݰ� ��ġ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int mat[55][55];
int handshake(int i, int j)
{
	int cnt = 0;
	int k, r;
	for (k = i - 1; k <= i + 1; k++)
	{
		for (r = j - 1; r <= j + 1; r++)
		{
			cnt += (mat[k][r] == 'o');
		}
	}
	return cnt - 1;
}


int main(void)
{
	int r, c;
	int i, j;
	int cnt = 0;
	int cnt2 = 0;
	int hand = 0;
	int indi, indj;
	int max = 0x80000000;
	scanf("%d %d", &r, &c);
	for (i = 1; i <= r; i++) 
	{
		for (j = 1; j <= c; j++)
		{
			scanf(" %c", &mat[i][j]);
			if (mat[i][j] == 'o') cnt++;
		}
	}
	if (cnt < r*c)
	{
		for (i = 1; i <= r; i++)
		{
			for (j = 1; j <= c; j++)
			{
				if (mat[i][j] == '.')
				{
					cnt2 = handshake(i, j); //�����̰� �� �� �Ǽ��� ���� ���� �þ�� ���� �˻�
					cnt2++;

					if (max < cnt2)
					{
						max = cnt2;
						indi = i;
						indj = j;
					}
				}
				cnt2 = 0;
			}
		}
	}
	cnt = 0;
	mat[indi][indj] = 'o'; //������ ���ϴ� ��ġ�� ����
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (mat[i][j] == 'o')
			{
				cnt += handshake(i, j); //��ü �Ǽ� Ƚ�� ���
			}
		}
	}
	printf("%d", cnt / 2);
	return 0;
}
#endif // 0

#if 0
//�ּ� ������� ���� �ٽ� �ϱ�
//���� ���忡���� �䱸�� ���� �پ��� ������ ������ ��� �ִ� ������ �ϰ� �ִ�.��� �� ���ڱ� ���� �̺�Ʈ�� ���ܼ� ���忡 �ִ� ��� �������� Ǯ� �ϳ��� ���� �ؾ� �Ѵ�.
//A, B, C 3���� ���� ������ ���� �� �� ������� �ѹ��� �ϳ��� ��ĥ ���� ����, �ѹ��� 2������ ��ĥ �� �ִ�.���� ��� A�� B�� ���� ��ģ �� C�� �ٽ� ��ġ�ų� A�� C�� ���� ��ġ�� B�� ��ġ��, Ȥ�� B�� C�� ���� ��ġ�� A�� ��ĥ �� �ִ�.
//���� ������ Ǯ���ٰ� �ٽ� ��ġ�� ������ �ſ� �߿��ѵ�, �� ������ �� ������ ���� ��ü ����� �޶����� �����̴�.
//���� ���� A�� B�� ���� a���� b���� ������ ����ִٰ� �� �� �� ���� ��ġ�� ����� a + b��� �Ѵ�.�׷��Ƿ� A�� B�� ���� ��ġ�� C�� ��ġ�� ��� �� ��ü ����� a + b + a + b + c�̸�, B�� C�� ���� ��ġ�� A�� ��ġ�� ����� b + c + b + c + a �̹Ƿ� �� ���� ���� ���� ���� �� �ִ�.
//���� ���, ���� 2, 2, 5���� ����Ǿ� �ִٸ� A(2)�� B(2)�� ��ġ�� ����� 4. ������ ��(4)�� C(5)�� ��ġ�� ����� 9�� �� 13�� �ּҺ���̴�.
//���� ���忡 ����Ǿ� �ִ� ���� ���� N�� ���� ���忡 ����ִ� ������ ���� ni�� �־��� ��, �̵��� �ϳ��� ��ġ�µ� ���� ����� �ּ�(C)�� ���϶�.

//�־��� ���������� ������������ ������ ��, ���� ���� �ΰ��� ����
//���� �� �ٽ� ������ �ݺ�, ������� ���� ������ �ش� ������ �ݺ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int m[5010];
int newm[5000];
int main(void)
{
	int n;
	int tmp;
	int i, j, k;
	int sum = 0;
	int cnt = 1;
	int rem;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++) //����
		{
			if (m[i]>m[j])
			{
				tmp = m[i];
				m[i] = m[j];
				m[j] = tmp;
			}
		}
	}
	i = 0;
	rem = n;
	while (rem != 1)
	{
		m[i + 1] = m[i] + m[i + 1]; //���� ���� �� ���� ����
		sum += m[i + 1];
		m[i] = 0;
		if (m[i + 1] < m[i + 3] || m[i + 3] == 0) //���� ������� ��������� �� ĭ �ڿ� �ִ� ���� ũ�� ��
		{
			i++;
			rem--;
			continue;
		}
		else
		{
			for (k = i + 4; k < n; k++) //����: ��������
			{
				if (m[i + 1] < m[k])
				{
					tmp = m[i + 1];
					for (j = i + 1; j < k - 1; j++)
					{
						m[j] = m[j + 1];
					}
					m[j] = tmp;
					break;
				}
			}
			if (k == n)
			{
				tmp = m[i + 1];
				for (j = i + 1; j < n; j++)
				{
					m[j] = m[j + 1];
				}
				m[n - 1] = tmp;
			}

		}
		i++;
		rem--;
	}
	printf("%d", sum);
	return 0;
}
#endif // 0
#if 0
//����
//�����̴� ���� ��� ȸ�� �������� �׻� ����ϰ� �ִٰ� ȣ���� ������ ������� ���� �� ������ �޷����� �Ѵ�.�����̰� ����ϰ� �ִ� ���� ���簢�� ����� ������� ��� �߰��� �������� ���� ����Ҹ��� ���� ����.�� ��� ��迡 ���� ��� �Ƿ��� �������� �ִ�.
//���� ��� ������ ���̰� 10, ������ ���̰� 5�� ����� ��迡 ���� ��� �Ƿ��� 3���� ������ �ִٰ� ����. <�׸� 1>�� ���� �̵��� 1, 2, 3���� ǥ�õǾ� �ְ�, �����̴� X�� ǥ���� ��ġ�� �ִ�.
//1�� �������� ȣ���� ��� ���� �� �����̰� ����� �ð�������� ���� �̵��ϸ� �̵� �Ÿ��� 12�� �ȴ�.�ݸ� �� �ð�������� ���� �̵��ϸ� �̵� �Ÿ��� 18�� �ȴ�.���� �����̰� 1�� �������� ���� �ִ� �Ÿ��� 12�� �ȴ�.���������� �������� ��ġ���� 2�� ���������� �ִ� �Ÿ��� 6, 3�� ���������� �ִ� �Ÿ��� 5�� �ȴ�.
//����� ũ��� ������ ���� �� ��ġ �׸��� �������� ��ġ�� �־��� �� �������� ��ġ�� �� ���� ������ �ִ� �Ÿ��� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���簢���� ����� ���ڷ� �켭 ������ �ܼ�ȭ
//Ư�� ������ ������ �� ������ ������ ��ġ�� �ľ��ϰ� ����� �Ÿ��� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4

int dir[111];
int len[111];
int new_len[111];
int abs(x)
{
	return (x > 0) ? x : -x;
}
int main(void)
{
	int width, height;
	int n;
	int i, j;
	int sum = 0;
	int length;
	int check;
	scanf("%d %d", &width, &height);
	length = 2 * width + 2 * height;
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		scanf("%d %d", &dir[i], &len[i]);
	}

	for (i = 0; i <= n; i++)
	{
		switch (dir[i]) //������ ������ ��ġ�� ��ȯ
		{
		case 2: new_len[i] = len[i]; break;
		case 4: new_len[i] = width + height - len[i]; break;
		case 1: new_len[i] = 2 * width + height - len[i]; break;
		case 3: new_len[i] = 2 * width + height + len[i]; break;
		}
	}
	check = new_len[n] + length / 2;
	for (i = 0; i < n; i++)
	{
		if (check < length) //������ ���� ���� ����� �Ÿ��� ����
		{
			if (new_len[n] <= new_len[i] && new_len[i] <= check) sum += new_len[i] - new_len[n];
			else
			{
				if (new_len[n] >= new_len[i]) sum += new_len[n] - new_len[i];
				else sum += new_len[n] - new_len[i] + length;
			}
		}
		else
		{
			if (check - length <= new_len[i] && new_len[i] <= new_len[n]) sum += new_len[n] - new_len[i];
			else
			{
				if (new_len[n] <= new_len[i]) sum += new_len[i] - new_len[n];
				else sum += new_len[i] - new_len[n] + length;
			}
		}

	}
	printf("%d", sum);
	return 0;
}
#endif // 0
#if 0
//�� ����
//�ð����⵵�� nlogn(���),n^2(�־�)
#include <stdio.h>

int a[30010];
void quick(int start, int end) //������ ó���� ������ �κ��� ����
{
	int pivot = end; //������ ���Ҹ� �Ǻ����� ����(�������� �ƴϾ ��� ����)
	int target = start;
	int left;
	int s1, e1, s2, e2;
	int tmp;
	if (start >= end) return;
	for (left = start; left < end; left++)
	{
		if (a[left] < a[pivot]) //�Ǻ����� ���Ұ� ���� ��� Ÿ�ٿ��ҿ� ��ȯ
		{
			tmp = a[left];
			a[left] = a[target];
			a[target] = tmp;
			target++; //Ÿ���� �ϳ� ����
		}
		//Ÿ���� �Ŀ� �Ǻ����Ұ� �־���� ��ġ�� ����
		//���� Ÿ����ġ�� ��������, ������ �Ǻ����� ���� ����, �������� �Ǻ����� ū ���Ұ� ��ġ�ϰ� ��
	}
	tmp = a[pivot];
	a[pivot] = a[target];
	a[target] = tmp; //���������� �Ǻ����ҿ� Ÿ�ٿ��Ҹ� ��ȯ
	s1 = start; e1 = target - 1; s2 = target + 1; e2 = end;
	quick(s1, e1); quick(s2, e2); //�Ǻ����Ҹ� �߽����� ������ �ѷ� ������ ������ �ٽ� ����
}


int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	quick(0, n - 1);
	for (i = 0; i < n; i++) printf("%d ", a[i]);
}
#endif // 0
#if 0
//���� Ž��
//������ �Ǿ��ִ� �ڷῡ�� ���ϴ� �ڷḦ ã�Ƴ� �� ȿ�������� ����� �� �ִ� ���
//����� ���� ���ϴ� ���� ���� ��, �ش��ϴ� ������ ��ġ���� �˻��ϴ� ���� �ݺ�
//�ð����⵵�� logn
#include <stdio.h>

int a[50010];
int at[10010];

int bin_search(int start, int end, int n) //����Ž���Լ�(��������)
{
	int mid = (start + end) / 2; //��� �ε��� ����
	if (start>end) return 0; //���� ����
	if (a[mid] == n) return mid + 1; //����� ���� ���ϴ� ���� ���
	if (a[mid] > n) end = mid - 1; //����� ���� ���ϴ� ������ ū ���
	else start = mid + 1; //����� ���� ���ϴ� ������ ���� ���
	bin_search(start, end, n); //ó���� �� �ε����� �������Ͽ� �ٽ� �Լ� ����
}


int main(void)
{
	int n;
	int t;
	int i;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d\n", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d ", &at[i]);
		printf("%d\n", bin_search(0, n - 1, at[i]));
	}
}
#endif // 0
#if 0
//�ϳ����� ž
//�⺻���� ����: ó�� n-1���� ������ �������� �ƴ� �κп� �ű� �� ������ ������ �������� �ű��, ������ n-1���� ������ �������� �ű�
//���� ������ ����, �������� �������� ã�� ����Լ��� ������ �� ����
#include <stdio.h>
int hanoi(int n, int src, int des) //src:ó�� ����, des:������
{
	if (n == 1) //���� ����
	{
		printf("%d : %d -> %d\n", n, src, des); 
		return 0;
	}
	hanoi(n - 1, src, 6 - des - src); //n-1���� ������ �������� �ƴ� �κп� �ű�� �Լ�
	printf("%d : %d -> %d\n", n, src, des); //n��° ������ �ű�� ���
	hanoi(n - 1, 6 - src - des, des); //n-1���� ������ �������� �ű�� �Լ�
}

int main(void)
{
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 3);
}
#endif // 0
