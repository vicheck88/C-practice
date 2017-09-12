#if 0
//색종이(초)
//가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다.이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 넓이를 구하는 프로그램을 작성하시오.

//가로 100, 세로 100의 배열을 만들고 주어진 좌표에 따라 색종이의 영역에 해당하는 부분을 다른 숫자로 채움
//다른 숫자들의 개수를 구하면 전체 넓이를 구할 수 있음
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
				paper[j][k] = 1; //색종이에 해당하는 부분을 1로 채움
			}
		}
	}
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (paper[i][j] == 1) cnt++; //1의 개수를 구함
		}
	}
	printf("%d", cnt);
	return 0;
}
#endif // 0
#if 0
//색종이(중)
//가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다. 이 도화지 위에 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다. 이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 둘레의 길이를 구하는 프로그램을 작성하시오.
//배열을 통해 색종이의 영역을 1로 채움. 그 뒤 0과 맞닿고 있는 1의 개수를 구하여 둘레를 구함
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
			if (paper[i][j] == 1) //1인 부분의 근처에 0이 있는지를 판단하여 둘레를 구함
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
//악수
//R행 C열의 격자 모양의 지역에 몇 명의 사람이 서 있다.한 격자에는 최대 한 명의 사람이 있다.
//각 사람들은 자신과 인접한 사람과 정확히 한 번씩 악수하는데, 인접한 사람은 아래 그림과 같이 주위 8방향에 있는 사람을 말한다.
//민혁이는 이 지역의 빈 격자 중 한 곳에 들어가서 이 지역에서 일어난 악수의 총 횟수가 최대가 되게 하려고 한다.민혁이가 들어간 후 이 지역에서 일어난 악수의 총 횟수를 구하여라.만약 빈 격자가 없다면 민혁이는 아무 행동도 하지 않는다.

//들어갈 수 있는 부분의 주변을 조사하여 민혁이 들어갈 때 악수 횟수가 가장 많이 늘어나는 지점을 검색
//그후, 전체 악수 횟수 검색: 악수는 결국 두 점을 잇는 선으로 볼 수 있으며, 때문에 전체 degree의 합의 절반과 일치

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
					cnt2 = handshake(i, j); //민혁이가 들어갈 떄 악수가 가장 많이 늘어나는 지점 검색
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
	mat[indi][indj] = 'o'; //민혁을 원하는 위치에 투입
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (mat[i][j] == 'o')
			{
				cnt += handshake(i, j); //전체 악수 횟수 계산
			}
		}
	}
	printf("%d", cnt / 2);
	return 0;
}
#endif // 0

#if 0
//최소 비용으로 포장 다시 하기
//사탕 공장에서는 요구에 따라 다양한 개수의 사탕을 담고 있는 포장을 하고 있다.어느 날 갑자기 대형 이벤트가 생겨서 공장에 있는 모든 사탕들을 풀어서 하나로 포장 해야 한다.
//A, B, C 3개의 사탕 포장이 있을 때 이 포장들을 한번에 하나로 합칠 수는 없고, 한번에 2개씩만 합칠 수 있다.예를 들면 A와 B를 먼저 합친 후 C를 다시 합치거나 A와 C를 먼저 합치고 B를 합치기, 혹은 B와 C를 먼저 합치고 A를 합칠 수 있다.
//사탕 포장을 풀었다가 다시 합치는 순서는 매우 중요한데, 그 이유는 그 순서에 따라 전체 비용이 달라지기 때문이다.
//사탕 포장 A와 B에 각각 a개와 b개의 사탕이 들어있다고 할 때 이 둘을 합치는 비용은 a + b라고 한다.그러므로 A와 B를 먼저 합치고 C를 합치는 경우 그 전체 비용은 a + b + a + b + c이며, B와 C를 먼저 합치고 A를 합치는 비용은 b + c + b + c + a 이므로 그 둘은 서로 같지 않을 수 있다.
//예를 들어, 각각 2, 2, 5개가 포장되어 있다면 A(2)와 B(2)를 합치는 비용은 4. 합쳐진 것(4)과 C(5)를 합치는 비용은 9로 총 13이 최소비용이다.
//현재 공장에 포장되어 있는 포장 개수 N과 각각 포장에 들어있는 사탕의 개수 ni가 주어질 때, 이들을 하나로 합치는데 들어가는 비용의 최소(C)를 구하라.

//주어진 사탕봉지를 오름차순으로 정렬한 뒤, 가장 앞의 두개를 더함
//더한 뒤 다시 정렬을 반복, 결과값이 나올 때까지 해당 행위를 반복

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
		for (j = i + 1; j < n; j++) //정렬
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
		m[i + 1] = m[i] + m[i + 1]; //가장 앞의 두 수를 더함
		sum += m[i + 1];
		m[i] = 0;
		if (m[i + 1] < m[i + 3] || m[i + 3] == 0) //더한 결과값과 결과값보다 두 칸 뒤에 있는 값의 크기 비교
		{
			i++;
			rem--;
			continue;
		}
		else
		{
			for (k = i + 4; k < n; k++) //정렬: 삽입정렬
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
//경비원
//동근이는 무인 경비 회사 경비원으로 항상 대기하고 있다가 호출이 들어오면 경비차를 몰고 그 곳으로 달려가야 한다.동근이가 담당하고 있는 곳은 직사각형 모양의 블록으로 블록 중간을 가로질러 차가 통과할만한 길이 없다.이 블록 경계에 무인 경비를 의뢰한 상점들이 있다.
//예를 들어 가로의 길이가 10, 세로의 길이가 5인 블록의 경계에 무인 경비를 의뢰한 3개의 상점이 있다고 하자. <그림 1>과 같이 이들은 1, 2, 3으로 표시되어 있고, 동근이는 X로 표시한 위치에 있다.
//1번 상점에서 호출이 들어 왔을 때 동근이가 블록을 시계방향으로 돌아 이동하면 이동 거리가 12가 된다.반면 반 시계방향으로 돌아 이동하면 이동 거리는 18이 된다.따라서 동근이가 1번 상점으로 가는 최단 거리는 12가 된다.마찬가지로 동근이의 위치에서 2번 상점까지의 최단 거리는 6, 3번 상점까지의 최단 거리는 5가 된다.
//블록의 크기와 상점의 개수 및 위치 그리고 동근이의 위치가 주어질 때 동근이의 위치와 각 상점 사이의 최단 거리의 합을 구하는 프로그램을 작성하시오.

//직사각형의 모습을 일자로 펴서 문제를 단순화
//특정 지접을 고정한 뒤 경비원과 상점의 위치를 파악하고 가까운 거리를 구함

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
		switch (dir[i]) //상접과 경비원의 위치를 변환
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
		if (check < length) //경비원과 상점 간의 가까운 거리를 측정
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
//퀵 정렬
//시간복잡도는 nlogn(평균),n^2(최악)
#include <stdio.h>

int a[30010];
void quick(int start, int end) //정렬의 처음과 마지막 부분을 지정
{
	int pivot = end; //마지막 원소를 피봇으로 설정(마지막이 아니어도 상관 없음)
	int target = start;
	int left;
	int s1, e1, s2, e2;
	int tmp;
	if (start >= end) return;
	for (left = start; left < end; left++)
	{
		if (a[left] < a[pivot]) //피봇보다 원소가 작을 경우 타겟원소와 교환
		{
			tmp = a[left];
			a[left] = a[target];
			a[target] = tmp;
			target++; //타겟을 하나 전진
		}
		//타겟은 후에 피봇원소가 있어야할 위치를 지정
		//최종 타겟위치를 기준으로, 왼쪽은 피봇보다 작은 원소, 오른쪽은 피봇보다 큰 원소가 위치하게 됨
	}
	tmp = a[pivot];
	a[pivot] = a[target];
	a[target] = tmp; //마지막으로 피봇원소와 타겟원소를 교환
	s1 = start; e1 = target - 1; s2 = target + 1; e2 = end;
	quick(s1, e1); quick(s2, e2); //피봇원소를 중심으로 영역을 둘로 나눈뒤 정렬을 다시 수행
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
//이진 탐색
//정렬의 되어있는 자료에서 원하는 자료를 찾아낼 때 효율적으로 사용할 수 있는 방법
//가운데의 값을 원하는 값과 비교한 뒤, 해당하는 절반의 위치만을 검색하는 행위 반복
//시간복잡도는 logn
#include <stdio.h>

int a[50010];
int at[10010];

int bin_search(int start, int end, int n) //이진탐색함수(오름차순)
{
	int mid = (start + end) / 2; //가운데 인덱스 설정
	if (start>end) return 0; //종료 조건
	if (a[mid] == n) return mid + 1; //가운데의 값이 원하는 값일 경우
	if (a[mid] > n) end = mid - 1; //가운데의 값이 원하는 값보다 큰 경우
	else start = mid + 1; //가운데의 값이 원하는 값보다 작은 경우
	bin_search(start, end, n); //처음과 끝 인덱스를 재조정하여 다시 함수 수행
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
//하노이의 탑
//기본적인 방향: 처음 n-1개의 원판을 목적지가 아닌 부분에 옮긴 뒤 마지막 원판을 목적지에 옮기고, 나머지 n-1개의 원판을 목적지에 옮김
//따라서 원판의 개수, 목적지와 시작점을 찾아 재귀함수를 구현할 수 있음
#include <stdio.h>
int hanoi(int n, int src, int des) //src:처음 시작, des:목적지
{
	if (n == 1) //종료 조건
	{
		printf("%d : %d -> %d\n", n, src, des); 
		return 0;
	}
	hanoi(n - 1, src, 6 - des - src); //n-1개의 원판을 목적지가 아닌 부분에 옮기는 함수
	printf("%d : %d -> %d\n", n, src, des); //n번째 원판을 옮기는 경우
	hanoi(n - 1, 6 - src - des, des); //n-1개의 원판을 목적지에 옮기는 함수
}

int main(void)
{
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 3);
}
#endif // 0
