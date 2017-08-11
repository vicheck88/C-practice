#include <stdio.h>

#if 0
#define ABS(x) (((x)>0)? (x):-(x))  

void main(void)
{
	printf("%d\n", ABS(-5));
}
#endif // 0
#if 0

#include <stdio.h>

#define SWAP(p, q) 	{int  t = *(p); \
*(p) = *(q); \
*(q) = t;}
// 지역변수 t의 사용을 제한하여야 함
// C90에서는 변수 선언을 처음에 해야 하며, 따라서 에러가 생길 수 있음

void main(void)
{
	int x = 10; int y = 20;

	printf("%d %d\n", x, y);
	SWAP(&x, &y)
		printf("%d %d\n", x, y);
}
#endif // 0

#if 0
#include <stdio.h>

#define PRT(x) printf("NO_"#x " = %d\n", NO_##x)
// #x를 통해 "NO_" "x" " = %d\n"로 변화: 결국 "NO_x = %d\n" 와 같은 뜻
// ##x를 통해 NO_x로 변화

int NO_1 = 128;
int NO_2 = 256;
int NO_A = 512;

void main(void)
{
	PRT(1);
	PRT(2);
	PRT(A);
}
#endif // 0

#if 0
#include <stdio.h>

#define ARR_SIZE(x)  (sizeof(x)/sizeof((x)[0]))

int a[4] = { 1, 2, 3, 4 };

void main(void)
{
	int i;

	for (i = 0; i < ARR_SIZE(a); i++)
	{
		printf("%d\n", a[i]);
	}
}
#endif // 0
#if 0

typedef unsigned int UI;
typedef UI * UIP;

UI a[4] = { 1, 2, 3, 4 };

void main(void)
{
	int i;

	UIP b[4] = { a, a + 1, a + 2, a + 3 };

	for (i = 0; i < 3; i++)
	{
		printf("%d\n", b[i]);
	}
}
#endif // 0

#if 0
#include <stdio.h>

void main(void)
{
	int a = 1;

#if !a
	printf("사운드 장치를 사용하지 않음\n");

#elif a == 1
	printf("STEREO 모드 장치 사용\n");

#else
	printf("CODE 15 : Unknown Device!\n");

#endif

	printf("사운드 모드 = %d\n", a);
}
#endif // 0

#if 0
#include <stdio.h>

#define PRT

void main(void)
{
#ifdef PRT
	printf("defined PRT\n");
#endif

#ifdef ABC
	printf("defined ABC\n");
#else
	printf("not defined ABC\n");
#endif
}
#endif

#if 0
#include <stdio.h>

#define PRT

void main(void)
{
#ifndef PRT
	printf("not defined PRT\n");
#endif

#ifndef ABC
	printf("not defined ABC\n");
#else
	printf("defined ABC\n");
#endif
}
#endif


#if 0
#include <stdio.h>

#define DEBUG
#define LITTLE

void main(void)
{
	int a = 20;

#ifdef DEBUG
	printf("[DBG Message] a = %d\n", a);
#endif

#ifndef LITTLE
	a = mode_change(a);
#else
	a = a;
#endif
}
#endif

#if 0
#include <stdio.h>

#define DEBUG

void main(void)
{
#ifdef DEBUG
#undef DEBUG
#endif

#ifdef DEBUG
	printf("[DBG Message] a = %d\n", a);
#endif
}
#endif


#if 0
#include <stdio.h>

#define TEST	0

void main(void)
{
#ifdef TEST
#undef TEST
#define TEST	1
#endif

	printf("TEST = %d\n", TEST);
}
#endif

#if 0
#include <stdio.h>

#define SOUND_DEVICE_TYPE	2

void main(void)
{
#if !SOUND_DEVICE_TYPE
	printf("사운드 장치를 사용하지 않음\n");

#elif SOUND_DEVICE_TYPE == 1
	printf("STEREO 모드 장치 사용\n");

#else
	printf("CODE 15 : Unknown Device!\n");

#endif
	printf("사운드 모드 = %d\n", SOUND_DEVICE_TYPE);
}
#endif

#if 0
#include <stdio.h>

#define SOUND_DEVICE_TYPE	0

void main(void)
{
#if SOUND_DEVICE_TYPE == 1
	printf("사운드 장치를 사용하지 않음\n");
#else
	printf("CODE 15 : Unknown Device!\n");
#endif

#if defined SOUND_DEVICE_TYPE
	printf("define SOUND_DEVICE_TYPE\n");
#else
	printf("not define SOUND_DEVICE_TYPE\n");
#endif

#if !defined SOUND_DEVICE_TYPE
	printf("define SOUND_DEVICE_TYPE\n");
#else
	printf("not define SOUND_DEVICE_TYPE\n");
#endif
}
#endif

#if 0
#include <stdio.h>

#define SOUND_DEVICE_TYPE	3

void main(void)
{
#if !SOUND_DEVICE_TYPE
	printf("사운드 장치를 사용하지 않음\n");

#else
#error CODE 15: Unknown Device!

#endif
	printf("사운드 모드 = %d\n", SOUND_DEVICE_TYPE);
}
#endif

#if 0
#include <stdio.h>

#pragma warning (disable : 4101 4700)
#pragma warning (once : 4552)
#pragma warning (error : 4700)

void main(void)
{
	unsigned int a, b; //(C4101 : b 미사용)

	a + 1;		//(C4552 : "+" has no effect)
	a >> 4;		//(C4552 : ">>" has no effect)
	a = a;		//(C4700 : use not initialized a)
}
#endif

#if 0
#include <stdio.h>
#define RANDOM(min,max) (rand()%((max)-(min)+1))+(min)
void main(void)
{
	int i;
	int min, max;
	srand((unsigned int)time(0));
	scanf("%d%d", &min, &max);
	printf("Random %d to %d\n", min, max);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", RANDOM(min, max));
	}
}
#endif // 1


#if 0
#include <stdio.h>
#define PI 3.14
#define Area(r) (r)*(r)*PI //워크샵 1번
#define Set_Bit(a,n) (a)|=1<<(n) //워크샵 2번
#define Write_Block(data,bits,value,bit) (data)=(data) & ~((bits)<<(bit)) | ((value)<<(bit)) //워크샵 3번
 
typedef struct //워크샵 4번
{
	int a;
	char b;
} ST;

void main(void)
{
	int a = 3;
	ST x = { 1, 'A' };
	printf("%d %c\n", x.a, x.b);
	printf("원의 넓이 = %f\n", Area(a));
	printf("%d\n", Set_Bit(a,3));
	printf("%d\n",Write_Block(a, 7, 2, 0));
}
#endif // 0

#if 0
#include <stdio.h>
#define DEBUG 0
void main(void)
{
#ifdef DEBUG
	#undef DEBUG
	#define DEBUG 1
#endif

#if DEBUG
	printf("SAMSUNG");
#else
	printf("SCSA");
#endif
}
#endif // 1

//워크샵 1번
#if 0
void main(void)
{
	int n1,n2, m;
	int sum;
	int i;
	int ar[6] = { 0 };
	int cnt = 0;
	printf(">>>> N진법연산 <<<<\n");
	printf("2 ~ 16 진법 입력: \n");
	scanf("%d",&m);
	printf("Operand1 : \n");
	scanf("%d",&n1);
	printf("Operand2 : \n");
	scanf("%d", &n2);
	sum=n1+n2;
	while (sum)
	{
		ar[cnt] = sum%m;
		sum /= m;
		cnt++;
	}
	printf("10진법 => %d   ", n1+n2);
	printf("%d진법 => ", m);
	for (i = cnt-1; i >= 0; i--)
	{
		if (ar[i] >= 10) printf("%c", ar[i] + 55);
		else printf("%d\n", ar[i]);
	}
}
#endif // 0

//워크샵 2번

#if 0

int wordcpy(char *p)
{
	int cnt = 0;
	while (*p)
	{
		cnt++;
		p++;
	}
	return cnt;
}


void main(void)
{
	char sent[255];
	char word[15];
	char *p;
	int i;
	printf("Input Sentence : \n");
	gets(sent);
	printf("Input word : \n");
	gets(word);
	int cnt = wordcpy(word);
	p = sent;
	int cnt2 = 0;
	
	while (*p)
	{
		for (i = 0; i < cnt; i++)
		{
			if (p[i] != word[i]) break;
		}
		if (i == cnt) cnt2++;
		p++;
	}
	printf("There are(is) %d word in the sentence.\n", cnt2);
}
#endif // 0

//워크샵 3번
#if 0
#define MAX 5
struct st_score
{
	int no;
	char name[30];
	int age;
	int kor;
	int eng;
	int tot;
};

void All_Print(struct st_score *p);
void One_Print(struct st_score *p);
void Data_Input(struct st_score *p);
void Data_Update(struct st_score *p);
void Name_Sort(struct st_score *p);
void Tot_Sort(struct st_score *p);

int Menu_Disp(void)
{
	int sel = 0;
	printf("==== 신상 기록부 ====\n");
	printf(" 1) 전체출력 \n");
	printf(" 2) 개인출력 \n");
	printf(" 3) 개인정보입력 \n");
	printf(" 4) 개인정보수정 \n");
	printf(" 5) 이름순정렬 \n");
	printf(" 6) 성적순정렬 \n");
	printf("====================\n");
	printf("> >메뉴 선택? ");
	scanf("%d", &sel); return sel;
}

void main(void)
{
	int sel;
	struct st_score score[MAX] = { { 1, "kim", 25, 80, 90, 0 }, { 2, "lew", 35, 70, 60, 0 }, { 3, "hong", 29, 80, 55, 0 }, \
	{4, "lee", 44, 89, 79, 0}, { 5, "park", 37, 50, 100, 0 } };
	for (;;)
	{
		//system("cls");
		sel = Menu_Disp();
		switch (sel)
		{
		case 1: All_Print(score); break;
		case 2: One_Print(score); break;
		case 3: Data_Input(score); break;
		case 4: Data_Update(score); break;
		case 5: Name_Sort(score); break;
		case 6: Tot_Sort(score); break;
		default: printf("다시입력해주세요\n"); break;
		}
	}
}

void All_Print(struct st_score *p)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("%d %s %d %d %d\n", p[i].no, p[i].name, p[i].age, p[i].kor, p[i].eng);
	}
}
void One_Print(struct st_score *p)
{
	int n;
	printf("번호를 입력하세요 : ");
	scanf("%d", &n);
	printf("%d %s %d %d %d\n", p[n].no, p[n].name, p[n].age, p[n].kor, p[n].eng);
}
void Data_Input(struct st_score *p)
{
	int i;
	printf("번호 이름 나이 국어 영어 순서대로 입력해주세요\n");
	for (i = 0; i < MAX; i++)
	{
		scanf("%d%s%d%d%d", &p[i].no, p[i].name, p[i].age, p[i].kor, p[i].eng);
	}
}

void Data_Update(struct st_score *p)
{
	int i;
	printf("번호를 입력하세요 : ");
	scanf("%d", &i);
	scanf("%d%s%d%d%d", &p[i].no, p[i].name, p[i].age, p[i].kor, p[i].eng);
}

void Name_Sort(struct st_score *p)
{
	int i, j;
	struct st_score tmp;
	for (i = 0; i < MAX - 1; i++)
	{
		char *q = p[i].name;
		for (j = i + 1; j < MAX; j++)
		{
			while (*q)
			{
				if (*p[i].name > *p[j].name)
				{
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
				else if (*p[i].name > *p[j].name) break;
				q++;
			}
		}
	}
	for (i = 0; i < MAX; i++)
	{
		printf("%d %s %d %d %d\n", p[i].no, p[i].name, p[i].age, p[i].kor, p[i].eng);
	}
}

void Tot_Sort(struct st_score *p)
{
	int i, j;
	struct st_score tmp;
	for (i = 0; i < MAX - 1; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (p[i].kor + p[i].eng > p[j].kor + p[j].eng)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (i = 0; i < MAX; i++)
	{
		printf("%d %s %d %d %d\n", p[i].no, p[i].name, p[i].age, p[i].kor, p[i].eng);
	}
}
#endif // 0
