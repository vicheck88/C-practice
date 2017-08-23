#if 0
#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct
{
	int id;
	char name[21];
	char place[11];
	int price;
	int num;
} PARTS;

#define MAX_ST 20
PARTS prod[MAX_ST];

int Parts_Create_Data(PARTS * p);
int Parts_Insert_Data(PARTS * p);
int Parts_Print_Data(int id);
int Parts_Delete_Data(int id);
int Parts_Sort_All_Data(void);
int Parts_Print_All_Data(void);
int Parts_Insert_n_Sort_Data(PARTS * p);
void Parts_Insert_No_sort(void);
void Parts_Insert_sort(void);
void Parts_Print_by_ID(void);
void Parts_Sort(void);
void Parts_Print_All(void);


PARTS test[10] = { { 10, "kim", "seo", 1, 2 }, { 2, "lew", "bu", 2, 3 }, { 3, "lew", "gwa", 3, 4 }, { 4, "lee", "dae", 4, 5 }, { 5, "song", "go", 5, 6 }, \
{6, "kim", "paj", 6, 7}, { 7, "song", "an", 7, 8 }, { 8, "lee", "ban", 8, 9 }, { 9, "moon", "san", 9, 10 }, { 10, "park", "son", 10, 11 } };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		prod[i] = test[i];
	}
}

int Parts_Create_Data(PARTS * p)
{
	printf("ID: ");
	scanf("%d", &(p->id));
	printf("��ǰ�� : ");
	scanf("%s", p->name);
	printf("������ : ");
	scanf("%s", p->place);
	printf("�ܰ� : ");
	scanf("%d", &(p->price));
	printf("��������: ");
	scanf("%d", &(p->num));
	return 1;
}

int Parts_Insert_Data(PARTS * p)
{
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (prod[i].id == p->id) return -2;
		if (prod[i].id == 0)
		{
			prod[i] = *p;
			return 1;
		}
	}
	return -1;
}

int Parts_Print_Data(int id)
{
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (prod[i].id == id)
		{
			printf("ID:%3d  ��ǰ��: %s  ������: %s, �ܰ�:%6d, ��������:%3d\n",
				prod[i].id, prod[i].name, prod[i].place, prod[i].price, prod[i].num);
			return 1;
		}
		if (prod[i].id == 0) return-1;
	}
	return -1;
}

int Count_data(PARTS *p)
{
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (p[i].id == 0) break;
	}
	return i;
}

int Parts_Delete_Data(int id)
{
	int i, j;
	int cnt = Count_data(prod);
	if (cnt == 0) return -1;
	for (i = 0; i < cnt; i++)
	{
		if (prod[i].id == id)
		{
			for (j = i; j < cnt - 1; j++)
			{
				prod[j] = prod[j + 1];
			}
		}
		prod[cnt - 1].id = 0;
		return 1;
	}
	return -1;
}

int Parts_Sort_All_Data(void)
{
	int i, j, k;
	PARTS tmp;
	int cnt = Count_data(prod);
	if (prod[0].id == 0) return;
	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (prod[j].id > prod[i].id)
			{
				tmp = prod[i];
				for (k = i - 1; k >= j; k--)
				{
					prod[k + 1] = prod[k];
				}
				prod[j] = tmp;
			}
		}
	}
	return cnt;
}

int Parts_Print_All_Data(void)
{
	int i;
	int cnt = Count_data(prod);
	for (i = 0; i < cnt; i++)
	{
		printf("ID:%3d  ��ǰ��: %s  ������: %s, �ܰ�:%6d, ��������:%3d\n",
			prod[i].id, prod[i].name, prod[i].place, prod[i].price, prod[i].num);
	}
	return cnt;
}

int Parts_Insert_n_Sort_Data(PARTS * p)
{
	int i, j;
	int cnt = Count_data(prod);
	if (cnt == MAX_ST) return -1;
	for (i = 0; i < cnt; i++)
	{
		if (prod[i].id == p->id) return -2;
		if (p->id < prod[i].id)
		{
			for (j = cnt; j > i; j--) prod[j] = prod[j - 1];
			prod[i] = *p;
			return i;
		}
	}
	prod[cnt] = *p;
	return cnt;
}

int menu_disp()
{
	int sel;
	system("cls");
	printf("====����====\n");
	printf("1. �ڷ��߰�(������)\n");
	printf("2. �ڷ��߰�(����)\n");
	printf("3. ��ǰ���\n");
	printf("4. ��������\n");
	printf("5. ��ü���\n");
	printf("0. ������\n");
	printf("���ϴ� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &sel);
	return sel;
}

void Parts_Insert_No_sort(void)
{
	PARTS tmp;
	Parts_Create_Data(&tmp);
	if (Parts_Insert_Data(&tmp) > 0) printf("����\n");
	else printf("����\n");
}
void Parts_Insert_sort(void)
{
	PARTS tmp;
	Parts_Create_Data(&tmp);
	if (Parts_Insert_n_Sort_Data(&tmp) > 0) printf("����\n");
	else printf("����\n");
}

void Parts_Print_by_ID(void)
{
	int id;
	int i;
	int cnt = Count_data(prod);
	printf("ID: ");
	scanf("%d", &id);
	for (i = 0; i < cnt; i++)
	{
		if (prod[i].id == id)
		{
			Parts_Print_Data(id);
			printf("����\n");
			return;
		}
	}
	printf("����\n");
}

void Parts_Sort(void)
{
	Parts_Sort_All_Data();
	printf("���ĵ� ����: %d\n", Count_data(prod));
	printf("���� �Ϸ�\n");
}
void Parts_Print_All(void)
{
	Parts_Print_All_Data();
}

int main(void)
{
	int sel;
	for (;;)
	{
		sel = menu_disp();
		if (sel == 0) break;
		switch (sel)
		{
		case 1: Parts_Insert_No_sort(); break;
		case 2: Parts_Insert_sort(); break;
		case 3: Parts_Print_by_ID(); break;
		case 4: Parts_Sort(); break;
		case 5: Parts_Print_All(); break;
		}
		printf("���: �ƹ�Ű, ����: x\n");
		if (getch() == 'x') break;
	}
	return 0;
}
#endif // 0
