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
#include <string.h>
#define INF 0x7f000000
#define MIN(x,y) ((x)>(y)?(y):(x))
int T;
int mat[15][22];
int tmp[15][22];
int row, col, K;
int min = INF;


void input(void)
{
	memset(mat, 0, sizeof(mat));
	memset(tmp, 0, sizeof(tmp));
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
	int i, j, cnt;
	for (j = 1; j <= col; j++)
	{
		cnt = 1;
		for (i = 2; i <= row; i++)
		{
			if (mat[i][j] == mat[i - 1][j])
			{
				cnt++;
				if (cnt >= K) goto back;
			}
			else cnt = 1;
		}
		if(cnt<K) return 0;
	back:;
	}
	return 1;
}



void DFS(int n, int cnt)
{
	int i, j;
	if (cnt >= min) return;
	if (cnt > row) return;
	if (n >= row)
	{
		if (check())
		{
			min = MIN(min, cnt);
		}
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
#if 0
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

//Shortest Path Faster 
/*정점의 개수가 N개이고 간선의 개수가 M개인, 가중치가 있는 무방향 그래프에서 출발 정점의 번호과 도착 정점의 번호가 주어진다.
출발 정점에서 도착 정점에 이르는 최단경로의 길이를 출력하는 프로그램을 작성하시오.
주어지는 그래프는 하나의 연결 그래프임이 보장된다.
[제약 사항]
1. 1≤N≤100,000, N-1≤M≤300,000
2. 각 간선의 가중치는 1,000,000 이하인 양의 정수
[입력]
1. 입력의 가장 첫 줄에는 총 테스트 케이스의 개수 T가 주어진다.
2. 그 다음 줄에 정점의 개수 N과 간선의 개수 M이 공백으로 구분되어 주어진다.
3. 다음 M개 줄에는 간선의 시작점과 끝점, 가중치가 순서대로 공백을 사이에 두고 주어진다.
[출력]
각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최단 경로의 길이를 출력한다.
*/
#if 0
#include <stdio.h>
#define SWAP(x,y) {EDGE (t)=(x);(x)=(y);(y)=(t);}
#define INF 0x7f000000
#define que 1000000
int T;
int N, M;
int chk[100010];
int edge_chk[300010];
int start, end;
typedef struct
{
	int v, d;
}Q_t;
Q_t Q[que];
typedef struct
{
	int s, e, w;
}EDGE;
EDGE edge[300010];

void qsort(int s,int e)
{
	if (s >= e) return;
	int left = s, target = s, pivot = e;
	for (left = s; left < e; left++)
	{
		if ((edge[left].s < edge[pivot].s) || (edge[left].s==edge[pivot].s &&
			edge[left].s<edge[pivot].e))
		{
			SWAP(edge[left], edge[target]); target++;
		}
	}
	SWAP(edge[target], edge[pivot]);
	qsort(s, target - 1); qsort(target + 1, e);
}

void input(void)
{
	int i;
	scanf("%d %d %d %d", &N, &M, &start, &end);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &edge[i].s, &edge[i].e, &edge[i].w);
		if (edge[i].s>edge[i].e)
		{
			int t = edge[i].s; edge[i].s = edge[i].e; edge[i].e = t;
		}
	}
	for (i = 1; i <= N; i++) chk[i] = INF;
	qsort(0,M-1);
}




void clear(void)
{
	int i;
	for (i = 0; i <= N; i++)
	{
		chk[i] = INF;
		edge_chk[i] = 0;
	}
	for (i = N + 1; i < M; i++) edge_chk[i] = 0;
}

int BFS(int n)
{
	int k;
	int wp = 0, rp = 0;
	Q_t tmp;
	Q[wp].v = n, Q[wp++].d = 0; chk[n] = 0;
	while (rp < wp)
	{
		tmp = Q[rp++];
		for (k = 0; k <M; k++)
		{
			if (edge[k].e < tmp.v) continue;
			else if (edge[k].s>tmp.v) break;
			if (edge[k].e == tmp.v && edge[k].w+tmp.d<chk[edge[k].s] && !edge_chk[k])
			{
				Q[wp].v = edge[k].s;
				Q[wp].d = edge[k].w + tmp.d;
				chk[edge[k].s] = Q[wp++].d;
				edge_chk[k] = 1;
			}
			else if (edge[k].s == tmp.v && edge[k].w + tmp.d < chk[edge[k].e] && !edge_chk[k])
			{
				Q[wp].v = edge[k].e;
				Q[wp].d = edge[k].w + tmp.d;
				chk[edge[k].e] = Q[wp++].d;
				edge_chk[k] = 1;
			}
		}
	}
	return chk[end];
}

int main(void)
{
	int i=1;
	scanf("%d", &T);
	while (T--)
	{
		input();
		clear();
		printf("#%d %d\n", i++, BFS(start));
	}
}
#endif // 01

//페그 솔리테어
/*프랑스 왕 루이 14세때 궁정에서 인기있는 게임인 페그 솔리테어는 다음과 같은 규칙을 가지고 있다. 구멍이 뚫려있는 이차원 게임 판에서 하는 게임으로 각 구멍에는 핀을 하나 꽂을 수 있다.
핀은 인접한 핀을 뛰어 넘어서 그 핀의 다음 칸으로 이동할 수 있다. 인접한 핀이란 현재 핀의 상하좌우에 있는 핀을 의미한다. 인접한 핀의 다음 칸은 비어있어야 하며 그 인접한 핀은 제거한다.
현재 게임 판에 꽂혀있는 핀의 상태가 주어지면, 핀을 적절히 움직여서 게임 판에 남아있는 핀의 개수를 최소로 하려고 한다. 또, 그렇게 남기기 위해 필요한 최소 이동횟수를 구하는 프로그램을 작성하시오.*/
#if 0
#include <stdio.h>
int T;
int mat[7][11];
int cnt;
int max;
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };
void input(void)
{
	int i, j;
	char c;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			scanf(" %c", &c);
			mat[i][j] = (int)c;
			if (mat[i][j] == 'o') cnt++;
		}
	}
}

void DFS(int n)
{
	int i, j,k,ni,nj,nni,nnj;
	if (max < n) max = n;
	if (n >= cnt) return;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (mat[i][j] != 'o') continue;
			for (k = 0; k < 4; k++)
			{
				ni = i + dirow[k], nj = j + dicol[k];
				nni = ni + dirow[k], nnj = nj + dicol[k];

				if (nni < 1 || nni>5 || nnj < 1 || nnj>9) continue;
				if (mat[ni][nj] != 'o') continue;
				if (mat[ni][nj] == 'o' && mat[nni][nnj] != '.') continue;

				mat[i][j] = mat[ni][nj] = '.';
				mat[nni][nnj] = 'o';
				DFS(n + 1);

				mat[i][j] = mat[ni][nj] = 'o';
				mat[nni][nnj] = '.';
			}
		}
	}
}


int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = max = 0;
		input();
		DFS(0);
		printf("%d %d\n", cnt - max, max);
	}
}
#endif // 01

//부분집합의 합
//N개의 정수로 이루어진 집합이 있을 때, 이 집합의 공집합이 아닌 부분집합 중에서 그 집합의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
#if 0
#include <stdio.h>
int cnt;
int N;
int S;
int ar[30];

void input(void)
{
	int i;
	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; i++) scanf("%d", &ar[i]);
}

void DFS(int n,int sum)
{
	if (n >= N)
	{
		if (sum == S) cnt++;
		return;
	}
	DFS(n + 1, sum + ar[n+1]);
	DFS(n + 1, sum);

}

int main(void)
{
	input();
	DFS(0,0);
	if (!S) cnt--;
	printf("%d", cnt);
}

#endif // 01

//점심 식사시간 (sw expert)
#if 0
#include <stdio.h>
#include <string.h>
#define ABS(x) ((x)>0?(x):-(x))
#define MIN(x,y) ((x)>(y)?(y):(x))
int T;
int N;
int mat[12][12];
int stair[2][3];
int stair_pos[2][2];
int rp[2];
int wp[2];
int per_que[2][10];
int tmp[2][10];
int person[11][2];
int st[2];
int num;
int cnt;
int cnt2;
int min = 0x7f000000;
int time;

int input(void)
{
	int i, j;
	memset(mat, 0, sizeof(mat));
	memset(person, 0, sizeof(person));
	memset(tmp, 0, sizeof(tmp));
	cnt = 0;
	rp[0] = rp[1] = 0;
	wp[0] = wp[1] = 0;
	min = 0x7f000000;
	num = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == 1)
			{
				num++;
				person[cnt2][0] = i, person[cnt2++][1] = j;
			}
			else if (mat[i][j] > 1)
			{
				stair_pos[cnt][0] = i, stair_pos[cnt][1] = j;
				st[cnt++] = mat[i][j];
			}
		}
	}
	cnt = 0;
	cnt2 = 0;
}

void sort()
{
	int i, j;
	memcpy(per_que, tmp, sizeof(tmp));
	for (i = 0; i < wp[0] - 1; i++)
	{
		for (j = i + 1; j < wp[0]; j++)
		{
			if (per_que[0][i] > per_que[0][j])
			{
				int tmp = per_que[0][i];
				per_que[0][i] = per_que[0][j];
				per_que[0][j] = tmp;
			}
		}
	}
	for (i = 0; i < wp[0] - 1; i++)
	{
		for (j = i + 1; j < wp[1]; j++)
		{
			if (per_que[1][i] > per_que[1][j])
			{
				int tmp = per_que[1][i];
				per_que[1][i] = per_que[1][j];
				per_que[1][j] = tmp;
			}
		}
	}
}


int solve(void)
{
	int i, j;
	int time, ans=0;
	rp[0] = rp[1] = 0;
	sort();
	for (time = 1; ans < num; time++)
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (stair[i][j]>0)
				{
					if (--stair[i][j] == 0)
					{
						ans++;
						if (ans == num) return time;
					}
				}
				if (stair[i][j] == 0)
				{
					if (rp[i]<wp[i] && time > per_que[i][rp[i]])
					{
						stair[i][j] = st[i];
						rp[i]++;
					}
				}
			}
		}
	}
}


void DFS(int n)
{
	int abs1, abs2;
	if (n >= num)
	{
		cnt=solve();
		if (cnt < min) min = cnt;
		return;
	}
	
	abs1 = ABS(person[n][0] - stair_pos[0][0]) + ABS(person[n][1] - stair_pos[0][1]);
	abs2 = ABS(person[n][0] - stair_pos[1][0]) + ABS(person[n][1] - stair_pos[1][1]);
	
	tmp[0][wp[0]++] = abs1;
	DFS(n + 1);
	tmp[0][wp[0]--] = 0;

	tmp[1][wp[1]++] = abs2;
	DFS(n + 1);
	tmp[1][wp[1]--] = 0;
}

int main(void)
{
	int i=1;
	scanf("%d", &T);
	while (T--)
	{
		input();
		DFS(0);
		printf("#%d %d\n",i++, min);
	}
	return 0;
}
#endif // 01

//카드게임
/*지훈이는 최근에 혼자 하는 카드게임을 즐겨하고 있다. 게임에 사용하는 각 카드에는 양의 정수 하나가 적혀있고 같은 숫자가 적힌 카드는 여러 장 있을 수 있다. 게임방법은 우선 짝수개의 카드를 무작위로 섞은 뒤 같은 개수의 두 더미로 나누어 하나는 왼쪽에 다른 하나는 오른쪽에 둔다. 그리고 빈 통을 하나 준비한다.
이제 각 더미의 제일 위에 있는 카드끼리 서로 비교하며 게임을 한다.
게임 규칙은 다음과 같다.
지금부터 왼쪽 더미의 제일 위 카드를 왼쪽 카드로, 오른쪽 더미의 제일 위 카드를 오른쪽 카드로 부르겠다.
(1) 언제든지 왼쪽 카드만 통에 버릴 수도 있고 왼쪽 카드와 오른쪽 카드를 둘 다 통에 버릴 수도 있다. 이때 얻는 점수는 없다.
(2) 오른쪽 카드에 적힌 수가 왼쪽 카드에 적힌 수보다 작은 경우에는 오른쪽 카드만 통에 버릴 수도 있다. 오른쪽 카드만 버리는 경우에는 오른쪽 카드에 적힌 수만큼 점수를 얻는다.
(3) (1)과 (2)의 규칙에 따라 게임을 진행하다가 어느 쪽 더미든 남은 카드가 없다면 게임이 끝나며 그때까지 얻은 점수의 합이 최종 점수가 된다.
다음 예는 세 장 씩 두 더미의 카드를 가지고 게임을 시작하는 경우이다.*/
#if 0
#include <stdio.h>
#include <string.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
int T;
int N;
int left[30], right[30];
int D[30][30];
int max;
int max_left;

void input(void)
{
	int i;
	scanf("%d", &N);
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	max = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &left[i]);
		max_left = MAX(left[i], max_left);
	}
	for (i = 0; i < N; i++) scanf("%d", &right[i]);
}

void DFS(int le, int ri, int total)
{
	if (D[le][ri] >= total) return;
	D[le][ri] = total;

	if (le>=N || ri>=N)
	{
		max = MAX(max, total);
		return;
	}

	if (left[le] > right[ri]) DFS(le, ri + 1, total + right[ri]);
	else
	{
		DFS(le + 1, ri + 1, total);
		DFS(le + 1, ri, total);
	}
}



int main(void)
{
	int i, j;
	scanf("%d", &T);
	while (T--)
	{
		memset(D, 0xff, sizeof(D));
		input();
		DFS(0, 0, 0);
		printf("%d\n", max);
	}
}

#endif // 01

//불켜기
/*농부 존은 최근에 N*N개의 방이 있는 거대한 헛간을 새로 지었다. 각 방은 (1, 1)부터 (N,N)까지 번호가 매겨져있다(2≤N≤100). 어둠을 무서워하는 암소 베시는 최대한 많은 방에 불을 밝히고 싶어한다.
베시는 유일하게 불이 켜져있는 방인 (1,1)방에서 출발한다. 어떤 방에는 다른 방의 불을 끄고 켤 수 있는 스위치가 달려있다. 예를 들어, (1, 1)방에 있는 스위치로 (1, 2)방의 불을 끄고 켤 수 있다. 베시는 불이 켜져있는 방으로만 들어갈 수 있고, 각 방에서는 상하좌우에 인접한 방으로 움직일 수 있다.
 베시가 불을 켤 수 있는 방의 최대 갯수를 구하시오.*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int T;
int N, M;
typedef struct
{
	int x, y, a, b;
}POS;
POS pos[20010];
typedef struct
{
	int x, y;
}Q_t;
Q_t Q[10010];
int wp, rp;
int light[110][110];
int ind[110][110];
int dirow[4] = { -1, 1, 0, 0 };
int dicol[4] = { 0, 0, -1, 1 };
int cnt;
int chk[110][110];
int update;


int cmp(const void *p, const void *q);
void input(void)
{
	int i;
	cnt = 1;
	memset(pos, 0, sizeof(pos));
	memset(ind, -1, sizeof(ind));
	memset(light , 0, sizeof(light));
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &pos[i].x, &pos[i].y, &pos[i].a, &pos[i].b);
	}
	qsort(pos, M, sizeof(POS), cmp);
	for (i = 0; i < M; i++)
	{
		if ((pos[i].x != pos[i + 1].x) || (pos[i].y != pos[i + 1].y))
			ind[pos[i + 1].x][pos[i + 1].y] = i + 1;
	}
	ind[1][1] = 0;
}

int cmp(const void *pp, const void *qq)
{
	POS * p;
	POS * q;
	p = (POS *)pp, q = (POS *)qq;
	if (p->x == q->x) return p->y - q->y;
	return p->x - q->x;
}

void light_on(int i, int j)
{
	int k, tmp = cnt;
	if (ind[i][j]<0) return;
	for (k = ind[i][j]; pos[k].x == i && pos[k].y == j; k++)
	{
		if (!light[pos[k].a][pos[k].b])
		{
			light[pos[k].a][pos[k].b] = 1;
			cnt++;
			update = 1;
		}
	}
	return;
}

void BFS(void)
{
	int ni, nj, k;
	Q_t tmp;
	Q[wp].x = 1, Q[wp++].y = 1, light[1][1] = 1;
	while (rp < wp)
	{
		tmp = Q[rp++];
		light_on(tmp.x, tmp.y);
		for (k = 0; k < 4; k++)
		{
			ni = tmp.x + dirow[k];
			nj = tmp.y + dicol[k];
			if (ni<1 || ni>N || nj<1 || nj>N) continue;
			if (chk[ni][nj]) continue;
			if (!light[ni][nj]) continue;
			Q[wp].x = ni, Q[wp++].y = nj, chk[ni][nj] = 1;
		}
	}
}


int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		input();
		do
		{
			memset(chk, 0, sizeof(chk));
			update = 0;
			rp = wp = 0;
			BFS();
		} while (update);
		printf("%d\n", cnt);
	}
	return 0;
}
#endif // 01

//차량 정비소
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int T;
int N, M, K, A, B;
int time;
int recept_time[22];
int repair_time[22];
int customer[1010];
int total;
int sol;
typedef struct
{
	int num,recept,t;
}DESK;
DESK recept[22];
DESK repair[22];
typedef struct
{
	int num, recept;
}WAIT;
WAIT wait[10000];
int wp_cus, wp_wait;
int rp_cus, rp_wait;

int cmp(const void * pp,const void * qq)
{
	int *p;
	int *q;
	p = (int *)pp, q = (int *)qq;
	return *p - *q;
}

void input(void)
{
	int i, j;
	memset(recept, 0, sizeof(recept));
	memset(repair, 0, sizeof(repair));
	memset(customer, 0, sizeof(customer));
	memset(wait, 0, sizeof(wait));
	wp_cus = 1, wp_wait = 1;
	rp_cus = 1, rp_wait = 1;
	total = sol = 0;
	scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
	for (i = 1; i <= N; i++) scanf("%d", &recept_time[i]);
	for (i = 1; i <= M; i++) scanf("%d", &repair_time[i]);
	for (i = 1; i <= K; i++) 
		scanf("%d", &customer[i]);
	qsort(customer, K + 1, sizeof(int), cmp);
}

void solve(void)
{
	int i, j;
	for (time = customer[1]; total < K; time++)
	{
		for (i = 1; i <= N; i++)
		{
			if (recept[i].t > 0)
			{
				if (--recept[i].t == 0)
				{
					wait[wp_wait].num = recept[i].num;
					wait[wp_wait++].recept = i;
				}
			}
			if (recept[i].t == 0)
			{
				if (rp_cus < K+1 && customer[rp_cus] <= time)
				{
					recept[i].num = rp_cus++;
					recept[i].t = recept_time[i];
				}
			}
		}
		for (i = 1; i <= M; i++)
		{
			if (repair[i].t>0)
			{
				if (--repair[i].t == 0)
				{
					total++;
					if (i == B && repair[i].recept == A) sol+=repair[i].num;
				}
			}
			if (repair[i].t == 0)
			{
				if (rp_wait < wp_wait)
				{
					repair[i].num = wait[rp_wait].num;
					repair[i].t = repair_time[i];
					repair[i].recept = wait[rp_wait++].recept;
				}
			}
		}
	}
}



int main(void)
{
	int i=1;
	scanf("%d", &T);
	while (T--)
	{
		input();
		solve();
		if (!sol) printf("#%d -1\n",i++);
		else printf("#%d %d\n",i++, sol);
	}
	return 0;
}
#endif // 01

