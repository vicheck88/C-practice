//줄세우기
//KOI 어린이집에는 N명의 아이들이 있다.오늘은 소풍을 가는 날이다.선생님은 1번부터 N번까지 번호가 적혀있는 번호표를 아이들의 가슴에 붙여주었다.선생님은 아이들을 효과적으로 보호하기 위해 목적지까지 번호순서대로 일렬로 서서 걸어가도록 하였다.이동 도중에 보니 아이들의 번호순서가 바뀌었다.그래서 선생님은 다시 번호 순서대로 줄을 세우기 위해서 아이들의 위치를 옮기려고 한다.그리고 아이들이 혼란스러워하지 않도록 하기 위해 위치를 옮기는 아이들의 수를 최소로 하려고 한다.예를 들어, 7명의 아이들이 다음과 같은 순서대로 줄을 서 있다고 하자.
//3 7 5 2 6 1 4
//아이들을 순서대로 줄을 세우기 위해, 먼저 4번 아이를 7번 아이의 뒤로 옮겨보자. 그러면 다음과 같은 순서가 된다.
//3 7 4 5 2 6 1
//이제, 7번 아이를 맨 뒤로 옮긴다.
//3 4 5 2 6 1 7
//다음 1번 아이를 맨 앞으로 옮긴다.
//1 3 4 5 2 6 7
//마지막으로 2번 아이를 1번 아이의 뒤로 옮기면 번호 순서대로 배치된다.
//1 2 3 4 5 6 7
//위의 방법으로 모두 4명의 아이를 옮겨 번호 순서대로 줄을 세운다. 위의 예에서 3명의 아이만을 옮겨서는 순서대로 배치할 수가 없다. 따라서, 4명을 옮기는 것이 가장 적은 수의 아이를 옮기는 것이다. N명의 아이들이 임의의 순서로 줄을 서 있을 때, 번호 순서대로 배치하기 위해 옮겨지는 아이의 최소 수를 구하는 프로그램을 작성하시오.

#if 0
#include <stdio.h>
int N;
int num[201];
int D[201];
int path[201];

void Input_Data(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &num[i]);
}

void Print_Path(int idx)
{
	if (idx == 0) return;
	Print_Path(path[idx]);
	printf("%d ", num[idx]);
}


int Find_LIS(void)
{
	int n, k, max = 0,last;
	num[0] = 0;
	D[0] = 0;

	for (n = 1; n <= N; n++)
	{
		for (k = 0; k < n; k++)
		{
			if (num[k] < num[n] && D[n] < D[k] + 1)
			{
				D[n] = D[k] + 1;
				path[n] = k;
			}
			if (D[n] > max)
			{
				max = D[n];
				last = n;
			}
		}
	}
	Print_Path(last);
	printf("\n");
	return max;
}


int main(void)
{
	Input_Data();
	printf("%d", N - Find_LIS());
	return 0;
}
#endif // 01

/*색종이 올려놓기
크기가 모두 다른 직사각형 모양의 색종이가 여러 장 있다. 색종이를 하나씩 올려 놓아, 되도록 많은 장수의 색종이들을 쌓으려고 한다.
새로 한 장의 색종이를 올려 놓을 때는 지금까지 쌓아 놓은 색종이들 중 맨 위의 색종이 위에 올려놓아야 하며 아래의 두 조건을 모두 만족해야 한다.
조건 1 : 새로 올려 놓는 색종이는 맨 위의 색종이보다 크지 않아야 한다. 즉, 맨 위의 색종이 밖으로 나가지 않아야 한다.
조건 2 : 새로 올려 놓는 색종이와 맨 위의 색종이의 변들은 서로 평행해야 한다. (색종이를 90˚돌려 놓을 수 있다.)
예를 들어, 아래의 그림 중에서 위의 두 조건을 모두 만족하는 경우는 (나)뿐이다.
색종이는 두 변의 길이로 표현된다. (3, 5)는 두 변의 길이가 각각 3과 5인 색종이를 나타낸다.
예를 들어, 다음과 같이 7장의 색종이가 주어졌다고 하자: (1, 2), (8, 7), (20, 10), (20, 20), (15, 12), (12, 14), (11, 12)
위의 조건을 만족하면서 가장 많이 쌓을 수 있는 색종이들의 순서는 (20, 20), (15, 12), (12, 14), (11, 12), (8, 7), (1, 2)이다.
입력으로 색종이들이 주어졌을 때, 위의 조건 1과 조건 2를 만족하면서 쌓을 수 있는 최대 색종이 장수를 구하는 프로그램을 작성하시오.
*/

#if 0
//첫번째
#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
int N;

int ar[110][2];
int D[110];
int max;
int max_ind;

void input(void)
{
	int i,j,tmp[2],temp;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &ar[i][0], &ar[i][1]);
		if (ar[i][0] > ar[i][1])
		{
			temp = ar[i][0]; ar[i][0] = ar[i][1]; ar[i][1] = temp;
		}
	}
	for (i = 1; i < N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			if (ar[i][0]>ar[j][0] || (ar[i][0] == ar[j][0] && ar[i][1] > ar[j][1]))
			{
				tmp[0] = ar[i][0], tmp[1] = ar[i][1];
				ar[i][0] = ar[j][0], ar[i][1] = ar[j][1];
				ar[j][0] = tmp[0], ar[j][1] = tmp[1];
			}
		}
	}
	
}

int LIS(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (ar[i][1] >= ar[j][1])
			{
				D[i] = MAX(D[i], D[j] + 1);
			}
		}
		max = MAX(max, D[i]);
	}
	return max;
}


int main(void)
{
	input();
	printf("%d", LIS());
	return 0;
}
#endif // 01

//두번째 방법(이분탐색)
#if 0
#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y));
#define SWAP(x,y) {int (t)=(x);(x)=(y);(y)=(t);}
int N;
int ar[110][2];
int D[110][2];

void input(void)
{
	int i,j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &ar[i][0], &ar[i][1]);
		if (ar[i][0] > ar[i][1]) SWAP(ar[i][0], ar[i][1]);
	}
	for (i = 1; i < N; i++)
	{
		for (j = i+1; j <= N; j++)
		{
			if (ar[i][0] > ar[j][0] ||
				(ar[i][0] == ar[j][0] && ar[i][1] >= ar[j][1]))
			{
				SWAP(ar[i][0], ar[j][0]);
				SWAP(ar[i][1], ar[j][1]);
			}
		}
	}
}

int search(int s, int e,int *p)
{
	int mid,sol=0;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (D[mid][0] <= p[0] && D[mid][1] <= p[1]) s = mid + 1;
		else
		{
			sol = mid;
			e = mid - 1;
		}
	}
	return sol;
}

int LIS(void)
{
	int i, max = 0,cnt=0, low;
	for (i = 1; i <= N; i++)
	{
		if (ar[i][0] >= D[cnt][0] && ar[i][1] >= D[cnt][1])
		{
			D[++cnt][0] = ar[i][0], D[cnt][1] = ar[i][1];
		}
		else
		{
			low = search(0, cnt,ar[i]);
			D[low][0] = ar[i][0];
			D[low][1] = ar[i][1];
		}
	}
	return cnt;
}

int main(void)
{
	input();
	printf("%d", LIS());
	return 0;
}
#endif // 1

/*
// 가장 높은탑 쌓기
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래에서 위로 쌓으면서 만들어 간다. 아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프로그램을 작성하시오.
 
(조건1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
(조건2) 밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
(조건3) 벽돌들의 높이는 같을 수도 있다.
(조건4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
(조건5) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int N;
typedef struct
{
	int id, area, height, weight;
}BRICK;

BRICK brick[110];
int mem[110];
int D[110][2];

int cmp(BRICK *p, BRICK *q)
{
	if (p->area == q->area) return p->weight - q->weight;
	return p->area - q->area;
}

int input(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		brick[i].id = i;
		scanf("%d %d %d", &brick[i].area, &brick[i].height, &brick[i].weight);
	}
	qsort(brick, N + 1, sizeof(BRICK), cmp);
}

void Print_all(int n)
{
	if(n==0) return;
	Print_all(mem[n]);
	printf("%d\n", brick[n].id);
}

void LIS(void)
{
	int i, j, max = 0,max_ind,max_height=0;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (brick[i].weight >= brick[j].weight)
			{
				if (D[i][0] < D[j][0] + brick[i].height)
				{
					D[i][0] = D[j][0] + brick[i].height;
					D[i][1] = D[j][1] + 1;
					mem[i] = j;
				}
			}
		}
		if (max_height < D[i][0])
		{
			max = D[i][1];
			max_height = D[i][0];
			max_ind = i;
		}
	}
	printf("%d\n", max);
	Print_all(max_ind);
}



int main(void)
{
	input();
	LIS();
	return 0;
}
#endif

//전봇대
/*두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.
전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y)((x)>(y)?(x):(y))
typedef struct
{
	int i, j;
}LINE;
LINE line[110];
int D[110];
int N;

int cmp(LINE *p, LINE *q)
{
	return p->i - q->i;
}

void input(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &line[i].i, &line[i].j);
	qsort(line, N + 1, sizeof(LINE), cmp);
}

int LIS(void)
{
	int i, j,max=0;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (line[i].j>line[j].j)
			{
				D[i] = MAX(D[i], D[j] + 1);
			}
		}
		max = MAX(D[i],max);
	}
	return max;
}


int main(void)
{
	input();
	printf("%d", N-LIS());
	return 0;
}

#endif

//전봇대(이분탐색 이용)
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int id,i, j;
}LINE;
LINE line[100010];
LINE tmp[100010];
LINE temp[500000];
int N;
int D[100010];
int E[500000];
int path[100000];
int tmp2[500010];
int max;

int input(void)
{
	int i, cnt = 1;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &tmp[i].i, &tmp[i].j);
		tmp[i].id = i;
		temp[tmp[i].i]=tmp[i];
	}
	for (i = 1; i <= 500000; i++)
	{
		if (temp[i].i) line[cnt++] = temp[i];
		if (cnt > N) break;
	}
}

int search(int s, int e, LINE  p)
{
	int mid,sol=0;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (D[mid] < p.j) s = mid + 1;
		else
		{
			sol = mid;
			e = mid - 1;
		}
	}
	return sol;
}


int LIS(void)
{
	int i, j,cnt=0,low,max_ind=0;
	for (i = 1; i <= N; i++)
	{
		if (D[cnt] < line[i].j)
		{
			D[++cnt] = line[i].j;
			E[line[i].j] = i;
			path[i] = E[D[cnt-1]];
			max = i;
		}
		else
		{
			low = search(1, cnt, line[i]);
			E[line[i].j] = i;
			D[low] = line[i].j;
			path[i] = E[D[low-1]];
		}
	}
	
	return cnt;
}

void Print_all(int idx)
{
	if (!idx) return;
	tmp2[idx]++;
	Print_all(path[idx]);
	//printf("%d\n", line[idx].i);
}


void Print_not(void)
{
	int i; 
	for (i = 1; i <= N; i++)
	{
		if (!tmp2[i]) printf("%d\n", line[i].i);
	}
}

int main(void)
{
	input();
	printf("%d\n", N-LIS());
	Print_all(max);
	Print_not();
	return 0;
}
#endif // 1

//연구소
/*인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다.다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
일부 칸은 바이러스가 존재하며, 이 바이러스는 인접한 빈 칸으로 모두 퍼져나갈 수 있다.새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.*/
/*첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다*/

#if 0
#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define INF 0x7ff00000
int row,col;
int mat[10][10];
int chk[10][10];
int flag=3;
int max;
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };
int virus;
typedef struct
{
	int i, j;
}Q_t;
Q_t Q[100000];

int input(void)
{
	int i, j, rem = 0, cnt = 0;
	scanf("%d %d", &row,&col);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			scanf("%d", &mat[i][j]);
			if (!mat[i][j])
			{
				rem++;
			}
			else if (mat[i][j] == 1) chk[i][j] = 1;
			if (mat[i][j] == 2)
			{
				Q[virus].i = i, Q[virus++].j = j;
				chk[i][j] = 2;
			}
		}
	}
	return rem;
}


int Fill(int rem)
{
	Q_t tmp;
	int k, ni, nj,cnt=0;
	int rp = 0, wp = virus;
	while (rp < wp)
	{
		tmp = Q[rp++];
		if (cnt>=rem) return INF;
		for (k = 0; k < 4; k++)
		{
			ni = tmp.i + dirow[k];
			nj = tmp.j + dicol[k];
			if (ni<1 || ni>row || nj<1 || nj>col) continue;
			if (mat[ni][nj]>=1) continue;
			if (chk[ni][nj] == flag) continue;
			Q[wp].i = ni; Q[wp++].j = nj;
			chk[ni][nj] = flag; cnt++;
		}
	}
	return cnt;
}



void DFS(int n,int r,int rem)
{
	int i,j,k;
	if (n >= 3)
	{
		rem = rem - Fill(rem-max);
		flag++;
		max=MAX(max, rem);
		return;
	}

		for (i = r; i <= row*col; i++)
		{
			int a = (i - 1) / col + 1, b = (i - 1) % col + 1;
			if (!mat[a][b])
			{
				mat[a][b] = 1;
				DFS(n + 1, r + 1, rem - 1);
				mat[a][b] = 0;
			}
		}

}

int main(void)
{
	int rem;
	rem=input();
	DFS(0,1,rem);
	printf("%d", max);
	return 0;
}
#endif // 01


//욕심쟁이 판다
/*n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 그런데 단 조건이 있다. 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다. 만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)
이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 어떤 곳으로 이동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를 도와주는 것이다. n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.*/

#if 0
#include <stdio.h>
#define NOT_SOLVED -1
int N;
int map[502][502];
int D[502][502];

void input(void)
{
	int r, c;
	scanf("%d", &N);
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			scanf("%d", &map[r][c]);
			D[r][c] = NOT_SOLVED;
		}
	}
}

int Find_LIS(int r, int c)
{
	static dr[] = { 0, 0, 1, -1 }, dc[] = { 1, -1, 0, 0 };
	int i;
	if (D[r][c] != NOT_SOLVED) return D[r][c];
	D[r][c] = 1;
	for (i = 0; i < 4; i++)
	{
		if (map[r + dr[i]][c + dc[i]] < map[r][c])
		{
			int len = Find_LIS(r + dr[i], c + dc[i]) + 1;
			if (D[r][c] < len) D[r][c] = len;
		}
	}
	return D[r][c];
}

int main(void)
{
	int r, c, ret, max = 0;
	input();
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			if (D[r][c] == NOT_SOLVED)
			{
				ret = Find_LIS(r, c);
				if (ret > max) max = ret;
			}
		}
	}
	printf("%d", max);
	return 0;
}
#endif // 0


//뿌요뿌요

#if 0
#include <stdio.h>
typedef struct
{
	int i, j, col;
}Q_t;
Q_t Q[100];
int T;
char c;
int mat[14][8];
int cnt;
int cnt_all;
int chk[14][8];
int chk_clear[14][8];
int flag = 1;
int update_flag;
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };
int x_pos[7];


void Initialize(void)
{
	int i, j;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			chk_clear[i][j] = 0;
			chk[i][j] = 0;
		}
	}
	flag = 1;
}

void init(void)
{
	int i, j;
	update_flag = 0;
}

void SWAP(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void input(void)
{
	int i, j;
	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			scanf(" %c", &c);
			if (c == 'R')
			{
				mat[i][j] = 1;

			}
			else if (c == 'G')
			{
				mat[i][j] = 2;

			}
			else if (c == 'B')
			{
				mat[i][j] = 3;

			}
			else if (c == 'Y')
			{
				mat[i][j] = 4;

			}
			else if (c == 'P')
			{
				mat[i][j] = 5;
			}
			else
			{
				mat[i][j] = 0;
				chk_clear[i][j] = 1;
			}
		}
	}
}

void BFS(int i, int j)
{
	int rp = 0, wp = 0;
	int ni, nj, ti, tj, tcol;
	int k, r;
	Q_t tmp;
	Q[wp].i = i, Q[wp].j = j, Q[wp++].col = mat[i][j];
	chk[i][j] = flag;
	while (rp < wp)
	{
		tmp = Q[rp++];
		for (k = 0; k < 5; k++)
		{
			ni = tmp.i + dirow[k], nj = tmp.j + dicol[k];
			if (ni < 1 || ni>12 || nj < 1 || nj>6) continue;
			if (tmp.col != mat[ni][nj]) continue;
			if (chk[ni][nj] == flag) continue;
			Q[wp].i = ni, Q[wp].j = nj, Q[wp++].col = mat[ni][nj];
			chk[ni][nj] = flag; cnt++;
		}
	}
	if (cnt >= 3)
	{
		update_flag = 1;
		for (i = 0; i < wp; i++)
		{
			mat[Q[i].i][Q[i].j] = 0;
			chk_clear[Q[i].i][Q[i].j] = 1;

		}
	}
	rp = wp = 0;
	cnt = 0;
}

int update(void)
{
	int i, j, k, tmp;
	for (i = 12; i >= 1; i--)
	{
		for (j = 1; j <= 6; j++)
		{
			if (!mat[i][j])
			{
				tmp = i;
				while (!mat[tmp][j])
				{
					if (tmp == 0) break;
					tmp--;
				}
				if (tmp > 0)
				{
					for (k = tmp; k >= 1; k--)
					{
						if (mat[k][j] == mat[k + i - tmp][j]) continue;
						SWAP(&mat[k][j], &mat[k + i - tmp][j]);
						SWAP(&chk_clear[k][j], &chk_clear[k + i - tmp][j]);
					}
				}
			}
		}
	}
}

int main(void)
{
	int i, j, cnt = 0;
	scanf("%d", &T);
	while (T--)
	{
		Initialize();
		cnt = 0;
		input();
		do
		{
			init();
			for (i = 1; i <= 12; i++)
			{
				for (j = 1; j <= 6; j++)
				{
					if (chk[i][j] == flag) continue;
					if (chk_clear[i][j]) continue;
					BFS(i, j);
					flag++;
				}
			}
			if (update_flag)
			{
				update(); cnt++;
			}
		} while (update_flag);
		printf("%d\n", cnt);
	}

}

#endif // 01


//선거

#if 0
#include <stdio.h>
int T;
int mat[7][7];
int chk[7][7];
int chk2[7][7];
int cnt;
char c;
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };
int flag = 1;
int rect[8][2];
int chk[7][7];
int chk2[7][7];
int rec;
int cnt2;

typedef struct
{
	int i, j, cnt, d, id;
}Q_t;
Q_t Q[100];

void input(void)
{
	int i, j;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			scanf(" %c", &c);
			if (c == 'H') mat[i][j] = -1;
			else mat[i][j] = 1;
		}
	}
}

int Fill(int i, int j)
{
	int k, ni, nj, cnt = 1;
	chk2[i][j] = 1;
	for (k = 0; k < 4; k++)
	{
		ni = i + dirow[k]; nj = j + dicol[k];
		if (ni<1 || ni>5 || nj<1 || nj>5) continue;
		if (!chk[ni][nj]) continue;
		if (chk2[ni][nj]) continue;
		cnt += Fill(ni, nj);
	}
	return cnt;
}

void clear(void)
{
	int i, j;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			chk[i][j] = 0;
			chk2[i][j] = 0;
		}
	}
}

int cnn(void)
{
	int i, k, sol;
	int ti, tj, ni, nj;
	for (i = 1; i <= 7; i++) chk[rect[i][0]][rect[i][1]] = 1;
	ti = rect[1][0], tj = rect[1][1];
	sol = Fill(ti, tj);
	clear();
	//sol = cnt;
	cnt = 0;
	if (sol == 7) return 1;
	return 0;
}



void DFS(int n, int i, int sol)
{
	int ni, nj, k, r;
	if (n >= 7)
	{
		if (sol > 0 && cnn()) cnt2++;
		return;
	}
	for (k = i + 1; k <= 25; k++)
	{
		ni = (k - 1) / 5 + 1, nj = (k - 1) % 5 + 1;
		rect[n + 1][0] = ni, rect[n + 1][1] = nj;
		DFS(n + 1, k, sol + mat[ni][nj]);
	}
}

int main(void)
{
	scanf("%d", &T);
	int i, j;
	while (T--)
	{
		cnt = 0;
		cnt2 = 0;
		input();
		DFS(0, 0, 0);

		printf("%d\n", cnt2);
	}
	return 0;
}

#endif // 01

//DSLR
/*네 개의 명령어 D, S, L, R 을 이용하는 간단한 계산기가 있다. 이 계산기에는 레지스터가 하나 있는데, 이 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다. 각 명령어는 이 레지스터에 저장된 n을 다음과 같이 변환한다. n의 네 자릿수를 d1, d2, d3, d4라고 하자(즉 n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4라고 하자)
D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
위에서 언급한 것처럼, L 과 R 명령어는 십진 자릿수를 가정하고 연산을 수행한다. 예를 들어서 n = 1234 라면 여기에 L 을 적용하면 2341 이 되고 R 을 적용하면 4123 이 된다.
여러분이 작성할 프로그램은 주어진 서로 다른 두 정수 A와 B(A ≠ B)에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램이다. 예를 들어서 A = 1234, B = 3412 라면 다음과 같이 두 개의 명령어를 적용하면 A를 B로 변환할 수 있다.
1234 →L 2341 →L 3412
1234 →R 4123 →R 3412
따라서 여러분의 프로그램은 이 경우에 LL 이나 RR 을 출력해야 한다.
n의 자릿수로 0 이 포함된 경우에 주의해야 한다. 예를 들어서 1000 에 L 을 적용하면 0001 이 되므로 결과는 1 이 된다. 그러나 R 을 적용하면 0100 이 되므로 결과는 100 이 된다.*/
#if 0
#include <stdio.h>
#define D(x) (((x)*2)%10000)
#define S(x) (((x)==0)?(9999):(x-1))

typedef struct
{
	int x;
	int d;
	int before;
	char op;
}Q_t;
Q_t Q[10000];
int T;
int chk[10001];
int ar[11];
int num1, num2;
int rp, wp;
int flag = 1;

void input(void)
{
	wp = rp = 0;
	flag++;
	scanf("%d %d", &num1, &num2);
}

void split(int n)
{
	int cnt = 0;
	while (n)
	{
		ar[cnt++] = n % 10;
		n /= 10;
	}
	ar[10] = cnt;
}
int recover(int *p)
{
	int i, sol = 0;
	for (i = 3; i >= 0; i--)
	{
		sol *= 10;
		sol += ar[i];
	}
	for (i = 0; i < 4; i++) ar[i] = 0;
	return sol;
}

void rotate(int *p, int n)
{
	int cnt, tmp, i;
	cnt = p[10];
	switch (n)
	{
	case 0:
		tmp = p[3];
		for (i = 2; i >= 0; i--)
		{
			ar[i + 1] = ar[i];
		}
		ar[0] = tmp;
		break;
	case 1:
		tmp = p[0];
		for (i = 0; i <3; i++)
		{
			ar[i] = ar[i + 1];
		}
		ar[i] = tmp;
		break;
	}
}

int L(int x)
{
	split(x);
	rotate(ar, 0);
	return recover(ar);
}
int R(int x)
{
	split(x);
	rotate(ar, 1);
	return recover(ar);
}


int BFS(void)
{
	Q_t tmp;
	int n[4], k;
	Q[wp].x = num1, Q[wp].d = 0, Q[wp++].op = 0; chk[num1] = flag;
	while (rp < wp)
	{
		tmp = Q[rp];
		if (tmp.x == num2) return rp;
		n[0] = D(tmp.x);
		n[1] = S(tmp.x);
		n[2] = L(tmp.x);
		n[3] = R(tmp.x);
		for (k = 0; k < 4; k++)
		{
			if (chk[n[k]] == flag) continue;
			Q[wp].before = rp;
			Q[wp].x = n[k];
			Q[wp].d = tmp.d + 1;
			chk[n[k]] = flag;
			switch (k)
			{
			case 0: Q[wp].op = 'D'; break;
			case 1: Q[wp].op = 'S'; break;
			case 2: Q[wp].op = 'L'; break;
			case 3: Q[wp].op = 'R'; break;
			}
			wp++;
		}
		rp++;
	}
}

void Print_all(int idx)
{
	if (!idx) return;
	Print_all(Q[idx].before);
	printf("%c", Q[idx].op);
}

int main(void)
{
	int sol;
	scanf("%d", &T);
	while (T--)
	{
		input();
		sol = BFS();
		Print_all(sol);
		printf("\n");
	}
	return 0;
}

#endif // 01

//판다
#if 0
#include <stdio.h>
#define NOT_SOLVED -1
int N;
int map[502][502];
int D[502][502];

void input(void)
{
	int r, c;
	scanf("%d", &N);
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			scanf("%d", &map[r][c]);
			D[r][c] = NOT_SOLVED;
		}
	}
}

int Find_LIS(int r, int c)
{
	static dr[] = { 0, 0, 1, -1 }, dc[] = { 1, -1, 0, 0 };
	int i;
	if (D[r][c] != NOT_SOLVED) return D[r][c];
	D[r][c] = 1;
	for (i = 0; i < 4; i++)
	{
		if (map[r + dr[i]][c + dc[i]] < map[r][c])
		{
			int len = Find_LIS(r + dr[i], c + dc[i]) + 1;
			if (D[r][c] < len) D[r][c] = len;
		}
	}
	return D[r][c];
}

int main(void)
{
	int r, c, ret, max = 0;
	input();
	for (r = 1; r <= N; r++)
	{
		for (c = 1; c <= N; c++)
		{
			if (D[r][c] == NOT_SOLVED)
			{
				ret = Find_LIS(r, c);
				if (ret > max) max = ret;
			}
		}
	}
	printf("%d", max);
	return 0;
}
#endif // 0

#if 0
#include <stdio.h>
#define INF 0x7f000000
#define MIN(x,y) ((x)>(y)?(y):(x))
int T;
int mat[15][22];
int tmp[15][22];
int row, col, K;
int min = INF;


void input(void)
{
	int i, j;
	scanf("%d %d %d", &row, &col, &K);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			scanf("%d", &mat[i][j]);
			tmp[i][j] = mat[i][j];
		}
	}
}

int check(void)
{
	int i, j, cnt, test = 0;
	for (j = 1; j <= col; j++)
	{
		cnt = 1;
		for (i = 2; i <= row; i++)
		{
			if (mat[i][j] == mat[i - 1][j])
			{
				cnt++;
				if (cnt >= K)
				{
					test++;
					break;
				}
			}
			else cnt = 1;
		}
		cnt = 1;
	}
	if (test < col) return 0;
	return 1;
}


void DFS(int n, int cnt)
{
	int i, j;
	if (cnt > min) return;
	if (n > row) return;
	if (check())
	{
		min = MIN(min, cnt);
		return;
	}
	for (j = 1; j <= col; j++) mat[n + 1][j] = 1;
	DFS(n + 1, cnt + 1);
	for (j = 1; j <= col; j++) mat[n + 1][j] = 0;
	DFS(n + 1, cnt + 1);
	for (j = 1; j <= col; j++) mat[n + 1][j] = tmp[n + 1][j];
	DFS(n + 1, cnt);
}

int main(void)
{
	int i = 1;
	scanf("%d", &T);
	while (T--)
	{
		//clear();
		min = INF;
		input();
		DFS(0, 0);
		printf("#%d %d\n", i++, min);
	}
}

#endif // 01

//가스관
/*러시아 가스를 크로아티아로 운반하기 위해 자그레브와 모스코바는 파이프라인을 디자인하고 있다. 두 사람은 실제 디자인을 하기 전에 파이프 매니아 게임을 이용해서 설계를 해보려고 한다.
이 게임에서 유럽은 R행 C열로 나누어져 있다. 각 칸은 비어있거나, 아래 그림과 같은 일곱가지 기본 블럭으로 이루어져 있다.
가스는 모스크바에서 자그레브로 흐른다. 가스는 빌딩 블럭을 통해 양방향으로 흐를 수 있다. '+'는 특별한 블럭으로, 두 방향 (수직, 수평)으로 흐를 수 있다. 아래 예제를 참고한다.
파이프 라인의 설계를 마친 후 두 사람은 잠시 저녁을 먹으러 갔다. 그 사이 해커가 침임해 블럭 하나를 지웠다. 지운 블럭은 빈 칸이 되어있다.
해커가 어떤 칸을 지웟고, 그 칸에는 원래 어떤 블럭이 있었는지 구하는 프로그램을 작성하시오. */
#if 0
#include <stdio.h>
char mat[30][30];
int T;
int row, col;
int dir[4];
void input(void)
{
	int i;
	scanf("%d %d", &row, &col);
 	for (i = 1; i <= row; i++) scanf("%s", mat[i]+1);
}

int up(int i, int j)
{
	char c;
	if (i == 1) return 0;
	c = mat[i - 1][j];
	if (c == '|' || c == '+' || c == '1' || c == '4') return 1;
	return 0;
}
int down(int i, int j)
{
	char c;
	if (i == row) return 0;
	c = mat[i + 1][j];
	if (c == '|' || c == '+' || c == '2' || c == '3') return 1;
	return 0;
}
int left(int i, int j)
{
	char c;
	if (i == 1) return 0;
	c = mat[i][j-1];
	if (c == '-' || c == '+' || c == '1' || c == '2') return 1;
	return 0;
}
int right(int i, int j)
{
	char c;
	if (i == 1) return 0;
	c = mat[i][j+1];
	if (c == '-' || c == '+' || c == '3' || c == '4') return 1;
	return 0;
}

void solve(void)
{
	int i, j,k,r;
	char c;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (mat[i][j] != '.') continue;
			if (up(i,j)) dir[0] = 1;
			if (down(i, j)) dir[1] = 1;
			if (left(i, j)) dir[2] = 1;
			if (right(i, j)) dir[3] = 1;
			
			if (dir[0] && dir[1] && dir[2] && dir[3]) c = '+';
			else if (!dir[0] && !dir[1] && dir[2] && dir[3]) c = '-';
			else if (dir[0] && dir[1] && !dir[2] && !dir[3]) c = '|';
			else if (!dir[0] && dir[1] && !dir[2] && dir[3]) c = '1';
			else if (dir[0] && !dir[1] && !dir[2] && dir[3]) c = '2';
			else if (dir[0] && !dir[1] && dir[2] && !dir[3]) c = '3';
			else if (!dir[0] && dir[1] && dir[2] && !dir[3]) c = '4';
			else continue;
			printf("%d %d %c\n", i, j, c);
			return;
		}
	}
}
void clear(void)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		dir[i] = 0;
	}
}

int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		clear();
		input();
		solve();
	}
}

#endif // 01

//어민
/*한 작은 나라에서는 대부분의 시민들이 어부이며, 그 나라의 모든 마을은 직선 해변을 따라 건설된 직선 도로에 위치해 있다.
마을의 어부들은 엄청난 양의 물고기를 잡았으나 예전처럼 물고기를 좋아하지 않아서 이웃 나라의 가난하고 배고픈 아이들을 입양하기로 결정했다.
하나의 긴 직선 도로가 해변을 따라 모든 마을을 연결한다. 따라서 각 도시(첫 번째와 마지막 도시는 제외)는 두 이웃 마을에 직접 연결된다. 1년에 한 명의 어린이가 1톤의 물고기를 먹는다. 어떤 마을에서 잡힌 물고기의 양은 그 마을에서 먹거나 다른 마을로 옮길 수 있다.
도로를 이용해서 옮겨야 하는데 이용에 따른 세금이 부과된다. 1km당 1톤의 물고기를 세금으로 내야 한다.
각 마을마다 동등한 수의 가난한 아이들이 입양되기를 원한다. 각 마을에 수용될 수 있는 아이들의 최대 수를 결정하는 프로그램을 작성하시오. 모든 물고기가 잡히고 저렴하게 운반된 물고기를 먹을 수 있다는 조건이다.*/
#if 0
#include <stdio.h>
int T;
int N;
long long ar[100002][2];
long long tmp[100002][2];
long long max;

void input(void)
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%lld %lld", &ar[i][0], &ar[i][1]);
		tmp[i][0] = ar[i][0], tmp[i][1] = ar[i][1];
		if (max < ar[i][1]) max = ar[i][1];
	}
}

int clear(void)
{
	int i;
	for (i = 0; i < N; i++) ar[i][1] = tmp[i][1];
}
long long transport(int n)
{
	int i=0,tax,shortage;
	while (i<N-1)
	{
		tax = ar[i + 1][0] - ar[i][0];
		if (ar[i][1] >= n)
		{
			if (ar[i][1] - n >= tax)
				ar[i + 1][1] += (ar[i][1] - n) - tax;
		}
		else
		{
			shortage = n - ar[i][1];
			ar[i][1] = n;
			ar[i + 1][1] -= (shortage + tax);
		}
		i++;
	}
	return ar[N - 1][1];

}


int solve(int s,int e)
{
	int ans,mid;
	while (s<=e)
	{
		mid = (s + e) / 2;
		if (transport(mid) < mid) e = mid - 1;
		else
		{
			ans = mid;
			s = mid + 1;
		}
		clear();
	}
	return ans;
}


int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		max = 0;
		input();
		printf("%d\n", solve(1,max));
	}
	return 0;
}
#endif // 01

//열쇠
/*상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 한다. 상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 있다. 빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요하다. 상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있다.
상근이가 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.
각 테스트 케이스의 첫째 줄에는 지도의 높이와 너비 h와 w (2 ≤ h, w ≤ 100)가 주어진다. 다음 h개 줄에는 빌딩을 나타내는 w개의 문자가 주어지며, 각 문자는 다음 중 하나이다.
'.'는 빈 공간을 나타낸다.
'*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
'$'는 상근이가 훔쳐야하는 문서이다.
알파벳 대문자는 문을 나타낸다.
알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.
마지막 줄에는 상근이가 이미 가지고 있는 열쇠가 공백없이 주어진다. 만약, 열쇠를 하나도 가지고 있지 않는 경우에는 "0"이 주어진다.
상근이는 빌딩 밖으로 나갈 수 있다. 각각의 문에 대해서, 그 문을 열 수 잇는 열쇠의 개수는 0개, 1개, 또는 그 이상이고, 각각의 열쇠에 대해서, 그 열쇠로 열 수 있는 문의 개수도 0개, 1개, 또는 그 이상이다. 열쇠는 여러 번 사용할 수 있다.*/
#if 01
int T;
int key_ind[30];
char key[30];
int row, col;
int mat[110][110];
int chk[110][110];
int sol;
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };

typedef struct
{
	int i, j;
}Q_t;
Q_t Q[100000];
int rp, wp;
int tmp_rp;
int flag;

void input(void)
{
	int i, j;
	char c;
	scanf("%d %d", &row, &col);
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			scanf(" %c", &c);
			mat[i][j] = (int)c;
		}
	}
	scanf("%s", key);
	for (i = 0; key[i]; i++) key_ind[key[i] - 'a'] = 1;
	for (i = 0; i <= row + 1; i++) mat[i][0] = mat[i][col + 1] = '.';
	for (j = 0; j <= col + 1; j++) mat[0][j] = mat[row + 1][j] = '.';

	Q[wp].i = 0, Q[wp].j = 0, chk[Q[wp].i][Q[wp++].j] = flag;
}

int BFS(void)
{
	Q_t tmp;
	int ni, nj, k,ans=0;
	rp = 0;
	while (rp < wp)
	{
		tmp = Q[rp++];
		if ('A' <= mat[tmp.i][tmp.j] && mat[tmp.i][tmp.j] <= 'Z')
		{
			if (!key_ind[mat[tmp.i][tmp.j] - 'A']) continue;
		}

		for (k = 0; k < 4; k++)
		{
			ni = tmp.i + dirow[k];
			nj = tmp.j + dicol[k];
			if (ni<0 || ni>row + 1 || nj<0 || nj>col + 1) continue;
			if (chk[ni][nj]) continue;
			if (mat[ni][nj] == '*') continue;
			if (mat[ni][nj] == '$')
			{
				sol++; mat[ni][nj] = '.';
			}
			if ('a' <= mat[ni][nj] && mat[ni][nj] <= 'z')
			{
				key_ind[mat[ni][nj] - 'a'] = 1;
				mat[ni][nj] = '.';
			}
			Q[wp].i = ni, Q[wp++].j = nj, chk[ni][nj] = 1;
			ans = 1;
		}
	}
	return ans;
}

void clear(void)
{
	int i,j;
	for (i = 0; i < 30; i++) key_ind[i] = 0;
	sol = 0, wp = 0;
	for (i = 0; i <= row + 1; i++)
	{
		for (j = 0; j <= col + 1; j++) chk[i][j] = 0;
	}
}
int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		input();
		while (BFS());
		printf("%d\n", sol);
		clear();
	}
}
#endif // 01


