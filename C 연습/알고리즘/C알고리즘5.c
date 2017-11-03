//�ټ����
//KOI ��������� N���� ���̵��� �ִ�.������ ��ǳ�� ���� ���̴�.�������� 1������ N������ ��ȣ�� �����ִ� ��ȣǥ�� ���̵��� ������ �ٿ��־���.�������� ���̵��� ȿ�������� ��ȣ�ϱ� ���� ���������� ��ȣ������� �Ϸķ� ���� �ɾ���� �Ͽ���.�̵� ���߿� ���� ���̵��� ��ȣ������ �ٲ����.�׷��� �������� �ٽ� ��ȣ ������� ���� ����� ���ؼ� ���̵��� ��ġ�� �ű���� �Ѵ�.�׸��� ���̵��� ȥ������������ �ʵ��� �ϱ� ���� ��ġ�� �ű�� ���̵��� ���� �ּҷ� �Ϸ��� �Ѵ�.���� ���, 7���� ���̵��� ������ ���� ������� ���� �� �ִٰ� ����.
//3 7 5 2 6 1 4
//���̵��� ������� ���� ����� ����, ���� 4�� ���̸� 7�� ������ �ڷ� �Űܺ���. �׷��� ������ ���� ������ �ȴ�.
//3 7 4 5 2 6 1
//����, 7�� ���̸� �� �ڷ� �ű��.
//3 4 5 2 6 1 7
//���� 1�� ���̸� �� ������ �ű��.
//1 3 4 5 2 6 7
//���������� 2�� ���̸� 1�� ������ �ڷ� �ű�� ��ȣ ������� ��ġ�ȴ�.
//1 2 3 4 5 6 7
//���� ������� ��� 4���� ���̸� �Ű� ��ȣ ������� ���� �����. ���� ������ 3���� ���̸��� �Űܼ��� ������� ��ġ�� ���� ����. ����, 4���� �ű�� ���� ���� ���� ���� ���̸� �ű�� ���̴�. N���� ���̵��� ������ ������ ���� �� ���� ��, ��ȣ ������� ��ġ�ϱ� ���� �Ű����� ������ �ּ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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

/*������ �÷�����
ũ�Ⱑ ��� �ٸ� ���簢�� ����� �����̰� ���� �� �ִ�. �����̸� �ϳ��� �÷� ����, �ǵ��� ���� ����� �����̵��� �������� �Ѵ�.
���� �� ���� �����̸� �÷� ���� ���� ���ݱ��� �׾� ���� �����̵� �� �� ���� ������ ���� �÷����ƾ� �ϸ� �Ʒ��� �� ������ ��� �����ؾ� �Ѵ�.
���� 1 : ���� �÷� ���� �����̴� �� ���� �����̺��� ũ�� �ʾƾ� �Ѵ�. ��, �� ���� ������ ������ ������ �ʾƾ� �Ѵ�.
���� 2 : ���� �÷� ���� �����̿� �� ���� �������� ������ ���� �����ؾ� �Ѵ�. (�����̸� 90������ ���� �� �ִ�.)
���� ���, �Ʒ��� �׸� �߿��� ���� �� ������ ��� �����ϴ� ���� (��)���̴�.
�����̴� �� ���� ���̷� ǥ���ȴ�. (3, 5)�� �� ���� ���̰� ���� 3�� 5�� �����̸� ��Ÿ����.
���� ���, ������ ���� 7���� �����̰� �־����ٰ� ����: (1, 2), (8, 7), (20, 10), (20, 20), (15, 12), (12, 14), (11, 12)
���� ������ �����ϸ鼭 ���� ���� ���� �� �ִ� �����̵��� ������ (20, 20), (15, 12), (12, 14), (11, 12), (8, 7), (1, 2)�̴�.
�Է����� �����̵��� �־����� ��, ���� ���� 1�� ���� 2�� �����ϸ鼭 ���� �� �ִ� �ִ� ������ ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#if 0
//ù��°
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

//�ι�° ���(�̺�Ž��)
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
// ���� ����ž �ױ�
�ظ��� ���簢���� ������ü �������� ����Ͽ� ž�� �װ��� �Ѵ�. ž�� ������ �� ���� �Ʒ����� ���� �����鼭 ����� ����. �Ʒ��� ������ �����ϸ鼭 ���� ���� ž�� ���� �� �ִ� ���α׷��� �ۼ��Ͻÿ�.
 
(����1) ������ ȸ����ų �� ����. ��, ������ �ظ����� ����� �� ����.
(����2) �ظ��� ���̰� ���� ������ ������, ���� ���԰� ���� ������ ����.
(����3) �������� ���̴� ���� ���� �ִ�.
(����4) ž�� ���� �� �ظ��� ���� ���� ���� �ظ��� ���� ������ ���� �� ����.
(����5) ���԰� ���ſ� ������ ���԰� ������ ���� ���� ���� �� ����.*/
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

//������
/*�� ������ A�� B ���̿� �ϳ� �Ѿ� �������� �߰��ϴ� ���� �������� ���� �����ϴ� ��찡 �߻��Ͽ���. �ռ��� ������ �־� �̵� �� �� ���� �������� ���� �������� �������� �ʵ��� ������� �Ѵ�.
���� ���, <�׸� 1>�� ���� �������� ����Ǿ� �ִ� ��� A�� 1�� ��ġ�� B�� 8�� ��ġ�� �մ� ������, A�� 3�� ��ġ�� B�� 9�� ��ġ�� �մ� ������, A�� 4�� ��ġ�� B�� 1�� ��ġ�� �մ� �������� ���ָ� �����ִ� ��� �������� ���� �������� �ʰ� �ȴ�.
�������� �����뿡 ����Ǵ� ��ġ�� ������ ���������� ���ʴ�� ��ȣ�� �Ű�����. �������� ������ �����ٵ��� �� �����뿡 ����Ǵ� ��ġ�� ��ȣ�� �־��� ��, �����ִ� ��� �������� ���� �������� �ʰ� �ϱ� ���� ���־� �ϴ� �������� �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.*/
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

//������(�̺�Ž�� �̿�)
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

//������
/*��ü�� ġ������ ���̷����� �����ϴ� �����ҿ��� ���̷����� ����Ǿ���.������ ���̷����� ���� ������ �ʾҰ�, ���̷����� Ȯ���� ���� ���ؼ� �����ҿ� ���� ������� �Ѵ�.
�����Ҵ� ũ�Ⱑ N��M�� ���簢������ ��Ÿ�� �� ������, ���簢���� 1��1 ũ���� ���簢������ �������� �ִ�.�����Ҵ� �� ĭ, ������ �̷���� ������, ���� ĭ �ϳ��� ���� �����Ѵ�.
�Ϻ� ĭ�� ���̷����� �����ϸ�, �� ���̷����� ������ �� ĭ���� ��� �������� �� �ִ�.���� ���� �� �ִ� ���� ������ 3���̸�, �� 3���� ������ �Ѵ�.*/
/*ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (3 �� N, M �� 8)
��° �ٺ��� N���� �ٿ� ������ ����� �־�����. 0�� �� ĭ, 1�� ��, 2�� ���̷����� �ִ� ��ġ�̴�. 2�� ������ 2���� ũ�ų� ����, 10���� �۰ų� ���� �ڿ����̴�.
�� ĭ�� ������ 3�� �̻��̴�*/

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


//������� �Ǵ�
/*n*n�� ũ���� �볪�� ���� �ִ�. ������� �Ǵٴ� � �������� �볪���� �Ա� �����Ѵ�. �׸��� �� ���� �볪���� �� �Ծ� ġ��� ��, ��, ��, �� �� �� ������ �̵��� �Ѵ�. �׸��� �� �װ����� �볪���� �Դ´�. �׷��� �� ������ �ִ�. �� �Ǵٴ� �ſ� ����� ���Ƽ� �볪���� �԰� �ڸ��� �ű�� �� �ű� ������ �� �� �������� �볪���� ���� �־�� �Ѵ�. ���࿡ �׷� ������ ������ �� �Ǵٴ� �Ҹ��� ������ �ܽ� ������ �ϴٰ� �װ� �ȴ�(-_-)
�� �Ǵ��� ������� �̷� �Ǵٸ� �볪�� ���� Ǯ�� ���ƾ� �ϴµ�, � ������ ó���� Ǯ�� ���ƾ� �ϰ�, � ������ �̵��� ���Ѿ� �� �� ������ ���������� �Ǵٰ� �ִ��� ���� �� �� �ִ��� ��ο� ���� �ִ�. �츮�� �ӹ��� �� �����縦 �����ִ� ���̴�. n*n ũ���� �볪�� ���� �־��� ���� ��, �� �Ǵٰ� �ִ��� ���� ����� � ��θ� ���Ͽ� �������� �ϴ��� ���Ͽ���.*/

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


//�ѿ�ѿ�

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


//����

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
/*�� ���� ��ɾ� D, S, L, R �� �̿��ϴ� ������ ���Ⱑ �ִ�. �� ���⿡�� �������Ͱ� �ϳ� �ִµ�, �� �������Ϳ��� 0 �̻� 10,000 �̸��� �������� ������ �� �ִ�. �� ��ɾ�� �� �������Ϳ� ����� n�� ������ ���� ��ȯ�Ѵ�. n�� �� �ڸ����� d1, d2, d3, d4��� ����(�� n = ((d1 �� 10 + d2) �� 10 + d3) �� 10 + d4��� ����)
D: D �� n�� �� ��� �ٲ۴�. ��� ���� 9999 ���� ū ��쿡�� 10000 ���� ���� �������� ���Ѵ�. �� ��� ��(2n mod 10000)�� �������Ϳ� �����Ѵ�.
S: S �� n���� 1 �� �� ��� n-1�� �������Ϳ� �����Ѵ�. n�� 0 �̶�� 9999 �� ��� �������Ϳ� ����ȴ�.
L: L �� n�� �� �ڸ����� �������� ȸ������ �� ����� �������Ϳ� �����Ѵ�. �� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d2, d3, d4, d1�� �ȴ�.
R: R �� n�� �� �ڸ����� ���������� ȸ������ �� ����� �������Ϳ� �����Ѵ�. �� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d4, d1, d2, d3�� �ȴ�.
������ ����� ��ó��, L �� R ��ɾ�� ���� �ڸ����� �����ϰ� ������ �����Ѵ�. ���� �� n = 1234 ��� ���⿡ L �� �����ϸ� 2341 �� �ǰ� R �� �����ϸ� 4123 �� �ȴ�.
�������� �ۼ��� ���α׷��� �־��� ���� �ٸ� �� ���� A�� B(A �� B)�� ���Ͽ� A�� B�� �ٲٴ� �ּ����� ��ɾ �����ϴ� ���α׷��̴�. ���� �� A = 1234, B = 3412 ��� ������ ���� �� ���� ��ɾ �����ϸ� A�� B�� ��ȯ�� �� �ִ�.
1234 ��L 2341 ��L 3412
1234 ��R 4123 ��R 3412
���� �������� ���α׷��� �� ��쿡 LL �̳� RR �� ����ؾ� �Ѵ�.
n�� �ڸ����� 0 �� ���Ե� ��쿡 �����ؾ� �Ѵ�. ���� �� 1000 �� L �� �����ϸ� 0001 �� �ǹǷ� ����� 1 �� �ȴ�. �׷��� R �� �����ϸ� 0100 �� �ǹǷ� ����� 100 �� �ȴ�.*/
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

//�Ǵ�
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

//������
/*���þ� ������ ũ�ξ�Ƽ�Ʒ� ����ϱ� ���� �ڱ׷���� ���ڹٴ� ������������ �������ϰ� �ִ�. �� ����� ���� �������� �ϱ� ���� ������ �ŴϾ� ������ �̿��ؼ� ���踦 �غ����� �Ѵ�.
�� ���ӿ��� ������ R�� C���� �������� �ִ�. �� ĭ�� ����ְų�, �Ʒ� �׸��� ���� �ϰ����� �⺻ ������ �̷���� �ִ�.
������ ��ũ�ٿ��� �ڱ׷���� �帥��. ������ ���� ���� ���� ��������� �带 �� �ִ�. '+'�� Ư���� ������, �� ���� (����, ����)���� �带 �� �ִ�. �Ʒ� ������ �����Ѵ�.
������ ������ ���踦 ��ģ �� �� ����� ��� ������ ������ ����. �� ���� ��Ŀ�� ħ���� �� �ϳ��� ������. ���� ���� �� ĭ�� �Ǿ��ִ�.
��Ŀ�� � ĭ�� ���m��, �� ĭ���� ���� � ���� �־����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. */
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

//���
/*�� ���� ���󿡼��� ��κ��� �ùε��� ����̸�, �� ������ ��� ������ ���� �غ��� ���� �Ǽ��� ���� ���ο� ��ġ�� �ִ�.
������ ��ε��� ��û�� ���� ����⸦ ������� ����ó�� ����⸦ �������� �ʾƼ� �̿� ������ �����ϰ� ����� ���̵��� �Ծ��ϱ�� �����ߴ�.
�ϳ��� �� ���� ���ΰ� �غ��� ���� ��� ������ �����Ѵ�. ���� �� ����(ù ��°�� ������ ���ô� ����)�� �� �̿� ������ ���� ����ȴ�. 1�⿡ �� ���� ��̰� 1���� ����⸦ �Դ´�. � �������� ���� ������� ���� �� �������� �԰ų� �ٸ� ������ �ű� �� �ִ�.
���θ� �̿��ؼ� �Űܾ� �ϴµ� �̿뿡 ���� ������ �ΰ��ȴ�. 1km�� 1���� ����⸦ �������� ���� �Ѵ�.
�� �������� ������ ���� ������ ���̵��� �Ծ�Ǳ⸦ ���Ѵ�. �� ������ ����� �� �ִ� ���̵��� �ִ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��� ����Ⱑ ������ �����ϰ� ��ݵ� ����⸦ ���� �� �ִٴ� �����̴�.*/
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

//����
/*����̴� 1�� ������ ħ���� �ſ� �߿��� ������ ���Ŀ����� �Ѵ�. ����̰� ������ �ִ� ��鵵���� ������ ��ġ�� ��� ��Ÿ�� �ִ�. ������ ���� ��� ����ֱ� ������, ���� ������ ���谡 �ʿ��ϴ�. ����̴� �Ϻ� ���踦 �̹� ������ �ְ�, �Ϻ� ����� ������ �ٴڿ� ������ �ִ�.
����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� ���� 100���� ���� �ʴ´�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ���̿� �ʺ� h�� w (2 �� h, w �� 100)�� �־�����. ���� h�� �ٿ��� ������ ��Ÿ���� w���� ���ڰ� �־�����, �� ���ڴ� ���� �� �ϳ��̴�.
'.'�� �� ������ ��Ÿ����.
'*'�� ���� ��Ÿ����, ����̴� ���� ����� �� ����.
'$'�� ����̰� ���ľ��ϴ� �����̴�.
���ĺ� �빮�ڴ� ���� ��Ÿ����.
���ĺ� �ҹ��ڴ� ���踦 ��Ÿ����, �� ������ �빮���� ��� ���� �� �� �ִ�.
������ �ٿ��� ����̰� �̹� ������ �ִ� ���谡 ������� �־�����. ����, ���踦 �ϳ��� ������ ���� �ʴ� ��쿡�� "0"�� �־�����.
����̴� ���� ������ ���� �� �ִ�. ������ ���� ���ؼ�, �� ���� �� �� �մ� ������ ������ 0��, 1��, �Ǵ� �� �̻��̰�, ������ ���迡 ���ؼ�, �� ����� �� �� �ִ� ���� ������ 0��, 1��, �Ǵ� �� �̻��̴�. ����� ���� �� ����� �� �ִ�.*/
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
/*������ ������ N���̰� ������ ������ M����, ����ġ�� �ִ� ������ �׷������� ��� ������ ��ȣ�� ���� ������ ��ȣ�� �־�����.
��� �������� ���� ������ �̸��� �ִܰ���� ���̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�־����� �׷����� �ϳ��� ���� �׷������� ����ȴ�.
[���� ����]
1. 1��N��100,000, N-1��M��300,000
2. �� ������ ����ġ�� 1,000,000 ������ ���� ����
[�Է�]
1. �Է��� ���� ù �ٿ��� �� �׽�Ʈ ���̽��� ���� T�� �־�����.
2. �� ���� �ٿ� ������ ���� N�� ������ ���� M�� �������� ���еǾ� �־�����.
3. ���� M�� �ٿ��� ������ �������� ����, ����ġ�� ������� ������ ���̿� �ΰ� �־�����.
[���]
�� �׽�Ʈ ���̽����� ��#x��(x�� �׽�Ʈ���̽� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�)�� ����ϰ�, �ִ� ����� ���̸� ����Ѵ�.
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

//��� �ָ��׾�
/*������ �� ���� 14���� �������� �α��ִ� ������ ��� �ָ��׾�� ������ ���� ��Ģ�� ������ �ִ�. ������ �շ��ִ� ������ ���� �ǿ��� �ϴ� �������� �� ���ۿ��� ���� �ϳ� ���� �� �ִ�.
���� ������ ���� �پ� �Ѿ �� ���� ���� ĭ���� �̵��� �� �ִ�. ������ ���̶� ���� ���� �����¿쿡 �ִ� ���� �ǹ��Ѵ�. ������ ���� ���� ĭ�� ����־�� �ϸ� �� ������ ���� �����Ѵ�.
���� ���� �ǿ� �����ִ� ���� ���°� �־�����, ���� ������ �������� ���� �ǿ� �����ִ� ���� ������ �ּҷ� �Ϸ��� �Ѵ�. ��, �׷��� ����� ���� �ʿ��� �ּ� �̵�Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.*/
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

//�κ������� ��
//N���� ������ �̷���� ������ ���� ��, �� ������ �������� �ƴ� �κ����� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

//���� �Ļ�ð� (sw expert)
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

//ī�����
/*�����̴� �ֱٿ� ȥ�� �ϴ� ī������� ����ϰ� �ִ�. ���ӿ� ����ϴ� �� ī�忡�� ���� ���� �ϳ��� �����ְ� ���� ���ڰ� ���� ī��� ���� �� ���� �� �ִ�. ���ӹ���� �켱 ¦������ ī�带 �������� ���� �� ���� ������ �� ���̷� ������ �ϳ��� ���ʿ� �ٸ� �ϳ��� �����ʿ� �д�. �׸��� �� ���� �ϳ� �غ��Ѵ�.
���� �� ������ ���� ���� �ִ� ī�峢�� ���� ���ϸ� ������ �Ѵ�.
���� ��Ģ�� ������ ����.
���ݺ��� ���� ������ ���� �� ī�带 ���� ī���, ������ ������ ���� �� ī�带 ������ ī��� �θ��ڴ�.
(1) �������� ���� ī�常 �뿡 ���� ���� �ְ� ���� ī��� ������ ī�带 �� �� �뿡 ���� ���� �ִ�. �̶� ��� ������ ����.
(2) ������ ī�忡 ���� ���� ���� ī�忡 ���� ������ ���� ��쿡�� ������ ī�常 �뿡 ���� ���� �ִ�. ������ ī�常 ������ ��쿡�� ������ ī�忡 ���� ����ŭ ������ ��´�.
(3) (1)�� (2)�� ��Ģ�� ���� ������ �����ϴٰ� ��� �� ���̵� ���� ī�尡 ���ٸ� ������ ������ �׶����� ���� ������ ���� ���� ������ �ȴ�.
���� ���� �� �� �� �� ������ ī�带 ������ ������ �����ϴ� ����̴�.*/
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

//���ѱ�
/*��� ���� �ֱٿ� N*N���� ���� �ִ� �Ŵ��� �갣�� ���� ������. �� ���� (1, 1)���� (N,N)���� ��ȣ�� �Ű����ִ�(2��N��100). ����� �������ϴ� �ϼ� ���ô� �ִ��� ���� �濡 ���� ������ �;��Ѵ�.
���ô� �����ϰ� ���� �����ִ� ���� (1,1)�濡�� ����Ѵ�. � �濡�� �ٸ� ���� ���� ���� �� �� �ִ� ����ġ�� �޷��ִ�. ���� ���, (1, 1)�濡 �ִ� ����ġ�� (1, 2)���� ���� ���� �� �� �ִ�. ���ô� ���� �����ִ� �����θ� �� �� �ְ�, �� �濡���� �����¿쿡 ������ ������ ������ �� �ִ�.
 ���ð� ���� �� �� �ִ� ���� �ִ� ������ ���Ͻÿ�.*/
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

//���� �����
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

