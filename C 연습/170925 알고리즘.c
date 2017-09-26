#if 0
//Dessert
//농부 존은 소들의 저녁식사 줄 세우는 새로운 방법을 개발 했다. N(1~15)마리의 소들을 순서대로 세워놓은 후, 각 소들 사이에 +, - , . 셋 중 1가지가 써져있는 냅킨을 배치해서 최종 결과가 0 이 되게 해야 하는 것이다. 점(.)이 써져있는 냅킨을 통해 더 큰 수를 만들 수 있게 된다. 아래와 같은 경우를 보자. (ps .이 써져있는 냅킨은 '공백'이라고 생각하면 된다.)
//1 - 2 . 3 - 4 . 5 + 6 . 7
//이와 같은 배치는 1-23-45+67 을 나타낸다. 결과는 0 이다. 10.11은 1011 로 해석된다.

//버퍼를 두어 각 계산별로 맞는 행동을 취함
//그 후 DFS를 통해 전체 경로를 탐색
#include <stdio.h>
int N;
int ar[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
char br[15];
int pow[2] = { 10, 100 };
char sign[3] = { '+', '-', '.' };
int cnt;
int stop;

int cal(int n, int m, char sign)
{
	switch (sign)
	{
	case '+': return n + m;
	case '-': return n - m;
	case '.':
		if (n >= 0) return n*pow[m / 10] + m;
		else return n*pow[m / 10] - m;
	}
}

void DFS(int n, int sum, int buf)
{
	int i, tmp_sum, tmp_buf;
	if (n + 1 >= N)
	{
		if (!(sum + buf))
		{
			if (cnt < 20)
			{
				printf("%d", 1);
				for (i = 1; i < N; i++) printf(" %c %d", br[i], ar[i]);
				printf("\n");
			}
			cnt++;
		}
		return;
	}

	for (i = 0; i < 3; i++)
	{
		br[n + 1] = sign[i];
		if (i != 2)
		{
			tmp_sum = sum + buf;
			tmp_buf = cal(0, ar[n + 1], sign[i]);
		}
		else
		{
			tmp_sum = sum;
			tmp_buf = cal(buf, ar[n + 1], sign[i]);
		}
		DFS(n + 1, tmp_sum, tmp_buf);
	}
}



int main(void)
{
	scanf("%d", &N);
	DFS(0, 0, 1);
	printf("%d", cnt);
}
#endif // 0

#if 0
//비행기게임
//게임의 룰은 다음과 같다.
//1)    비행기는 최초 맵의 최하단 중앙점에서 시작하게 된다. (행-13/열 – 3)
//시작위치에 적이나 동전은 존재하지 않는다.
//2)    비행기는 매 초마다 반드시 한 행 위로 올라가게 되는데, 이때 좌측상단, 상단, 우측상단 이렇게 세 방향 중 한 곳으로 이동 가능하다.
//3)    비행기가 이동한 위치에 ‘동전’이 있을 경우, 점수 10점을 획득하게 된다.
//4)    비행기가 이동한 위치에 ‘적’이 있을 경우, 점수가 -7점 감소한다.
//5)    비행기는 처음에 폭탄을 하나 가지고 게임을 시작하게 되는데, 이 폭탄을 사용하면, 폭탄을 사용하려는 위치로부터 5행 이내의 적들은 모두 제거된다. (동전은 제거되지 않는다.)
//6)    맵의 제일 윗줄로 올라가면 게임은 종료된다. 

// n==13이므로 DFS가 가능(총 6진트리)
// 6진 중 폭탄을 사용할 경우에는 따로 변수를 두어 가지치기
#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
char mat[20][20];
int T;
int max=-100;

void DFS(int n, int nj, int score, int bomb, int flag)
{
	int score_tmp=score, bomb_tmp=bomb;
	if (nj < 0 || nj >= 5) return;
	if (n < 1)
	{
		max = MAX(score, max);
		return;
	}
	
	if (mat[n][nj] == '*') score_tmp = score + 10;
	if (!flag && mat[n][nj]=='X')
	{
		DFS(n - 1, nj - 1, score_tmp, 5, 1);
		DFS(n - 1, nj, score_tmp, 5, 1);
		DFS(n - 1, nj + 1, score_tmp, 5, 1);
	}
	if (mat[n][nj] == 'X' && bomb<=1) score_tmp = score - 7;
	if (flag) bomb_tmp=bomb-1;
	DFS(n - 1, nj - 1, score_tmp, bomb_tmp, flag);
	DFS(n - 1, nj, score_tmp, bomb_tmp, flag);
	DFS(n - 1, nj + 1, score_tmp, bomb_tmp, flag);
}

int main(void)
{
	int i;
	scanf("%d", &T);
	while (T--)
	{
		for (i = 1; i <= 13; i++) scanf("%s", mat[i]);
		DFS(13, 2, 0, 0, 0);
		printf("%d\n", max);
		max = -100;
	}
	return 0;
}

#endif

#if 0
//빙산
//지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.
//행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보
//빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 따라서 그림 1의 빙산은 일년 후에 그림 2와 같이 변형된다.
//그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다. 2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.
//한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

//첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. N과 M은 3 이상 300 이하이다. 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0 이상 10 이하이다. 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

typedef struct
{
	int i, j;
}Q_t;
Q_t Q[1000000];
int row, col;
int mat[310][310];
int tmp[310][310];
int chk[310][310];
int flag;
int cnt;
int num;
int total;
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };
int r, c;

int BFS(int i, int j)
{
	int ti, tj, ni, nj, k,num=0;
	int wp =0, rp = 0;
	Q[wp].i = i; Q[wp++].j = j;
	chk[i][j] = flag; num++;
	while (rp < wp)
	{
		ti = Q[rp].i; tj = Q[rp++].j;
		for (k = 0; k < 4; k++)
		{
			ni = ti + dirow[k];
			nj = tj + dicol[k];
			if (ni<1 || ni>row || nj<1 || nj>col) continue;
			if (!mat[ni][nj] || chk[ni][nj] == flag) continue;
			Q[wp].i = ni; Q[wp++].j = nj; chk[ni][nj] = flag; num++;
		}
	}
	return num;
}

void check(void)
{
	int i, j,k;
	int ni, nj;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++) tmp[i][j] = mat[i][j];
	}

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (mat[i][j])
			{
				for (k = 0; k < 4; k++)
				{
					ni = i + dirow[k];
					nj = j + dicol[k];
					if (mat[ni][nj]) continue;
					if (mat[i][j] && !tmp[ni][nj])
					{
						mat[i][j]--;
						if (!mat[i][j]) total--;
					}
				}
			}
		}
	}
}

int main(void)
{
	int i, j,result;
	scanf("%d %d", &row, &col);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			scanf("%d", &mat[i][j]);
			if (mat[i][j]) total++;
		}
	}
	while (total)
	{
 		cnt++;
		check();
		num = 0; flag++;
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (mat[i][j])
				{
					r = i; c = j; goto back;
				}
			}
		}
	back:
		//result = BFS(r, c);
		//if (result < total) break;
		if (BFS(r, c) < total) break;
	}
	if (!total) printf("0");
	else printf("%d", cnt);
	return 0;
}

#endif