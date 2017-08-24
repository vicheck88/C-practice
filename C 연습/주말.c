/***********************************************************/
// [1-3] �迭 ��� ���� ����Ʈ
/***********************************************************/

#if 0

/***********************************************************/
// [1-3.1] ������ �𵨸�
/***********************************************************/

#if 1

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
}SCORE;

SCORE Head;

#define MAX_ST		20

SCORE exam[MAX_ST];

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�


int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = { { 10, 50, "kim" }, { 2, 80, "lew" }, { 8, 50, "lew" }, { 4, 45, "lee" }, { 1, 90, "song" }, \
{3, 45, "kim"}, { 5, 50, "song" }, { 9, 100, "lee" }, { 7, 75, "moon" }, { 6, 90, "park" }, \
{15, 90, "ki"}, { 11, 20, "kong" }, { 14, 40, "shin" }, { 12, 50, "son" }, { 17, 48, "lee" }, \
{20, 100, "min"}, { 19, 80, "you" }, { 13, 45, "song" }, { 16, 54, "no" }, { 18, 100, "yang" } };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i<n; i++)
	{
		exam[i] = test[i];
	}
}

#endif

/***********************************************************/
// [1-3.2] ������ ����, �μ�, ��� �Լ� ����
/***********************************************************/

#if 1

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->next = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head.next = 0x%.8X\n", Head.next);

	for (i = 0; i<MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next);
	}

	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next);
	return 1;
}

int Count_Data(void)
{
	int i;

	for (i = 0; i<MAX_ST; i++)
	{
		if (exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE * p)
{
	int i;

	for (i = 0; i<MAX_ST; i++)
	{
		if (exam[i].id == 0)
		{
			exam[i] = (*p);
			return i;
		}

		if (exam[i].id == p->id)
		{
			return -2;
		}
	}

	return -1;
}

#endif

/***********************************************************/
// [1-3.3] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ�
/***********************************************************/

#if 1

int Insert_Node(SCORE * head, SCORE * d)
{
	int i;
	for (i = 0; i < MAX_ST; i++)
		// �ڷᰡ �Էµ��� �ʾ��� ���, �Ǵ� ���ԵǴ� ���� ���� Ŭ ���
	{
		if (head->next == NULL || head->next->id > d->id)
		{
			d->next = head->next; // ���� ����� �� ��带 �����ϴ� ����
			head->next = d;
			return 1;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
		// head�� �ּҸ� ���� ����� �ּҷ� ����: ��ũ�� �ٷ�� �� �� ��������
	}
	if (i == MAX_ST) return -1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-3.4] link�� ���� �� ����� ������ �μ��ϵ��� �Լ�
/***********************************************************/
/***********************************************************/
// [1-3.5] link�� ���� �־��� ����� �´� ��� �� ã�� �ּҸ� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Print_All_Node(SCORE * head)
{
	int i;
	int cnt = 0;
	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) return cnt;
		printf("address: 0x%p  id: %d  name: %s  jumsu: %d  next: 0x%p\n", head->next,
			head->next->id, head->next->name, head->next->jumsu, head->next->next);
		cnt++;
		head = head->next;
	}
}
#endif

#if 1
SCORE * Search_Id_Node(SCORE * head, int id)
{
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) return NULL;
		if (head->next->id == id) return head->next;
		if (head->next->id>id) return NULL;
		head = head->next;
	}
}
#endif // 0




#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	for (i = 0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

#if 1
	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}
#endif // 0

}

#endif

/***********************************************************/
// [1-3.6] list�� ����� �ڷ��� �Ѽ��� ����ϴ� �Լ�
/***********************************************************/

#if 1

int Count_Node(SCORE * head)
{
	int cnt = 0;
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) return cnt;
		head = head->next;
	}
}

#endif

/***********************************************************/
// [1-3.7] link�� ���� �־��� ����� �´� �ڷḦ �μ��ϴ� �Լ�
/***********************************************************/

#if 1

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);
	if (p == NULL) return -1;
	printf("ID=%d  NAME=%s  SCORE=%d	", p->id, p->name, p->jumsu);
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Node Result = %d\n", Print_Node(&Head, 8));
	printf("Print Node Result = %d\n", Print_Node(&Head, 7));
}

#endif

/***********************************************************/
// [1-3.8] link�� ���� �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ�
/***********************************************************/

#if 1

int Delete_Node(SCORE * head, int id)
{
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) return -1;
		if (head->next->id == id)
		{
			head->next->id = 0;
			head->next = head->next->next;
			return 1;
		}
		if (head->next->id > id) return -1;
		head = head->next;
	}
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-3.9] �־��� ���ۿ� �ڷḦ ��� ������ �ִ� �Լ� 
/***********************************************************/

#if 0

int Copy_All_Node(SCORE * head, SCORE * buf)
{





}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i<8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Node Count = %d\n", r = Count_Node(&Head));

	p = calloc(r, sizeof(SCORE));
	printf("Copy All Node Result = %d\n", Copy_All_Node(&Head, p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

/***********************************************************/
// [1-3.10] node���� ��û�� �ڷ��� ���� ����ϰų� ���ۿ� ������ �ִ� �Լ�
/***********************************************************/

#if 0

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (!strcmp(head->name, name)) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		if (head->jumsu == jumsu) n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{




}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{




}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i<20; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

	printf("Name Node Count = %d\n", r = Count_Name_Node(&Head, "lew"));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Name Node Result = %d\n", Copy_Name_Node(&Head, "lew", p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

#endif
