#include <stdio.h>

//抗力 9
#if 0

char * Vending_Machine(int num)
{
	static char drink[4][10] = { "妮扼", "荤捞促", "券鸥", "阜吧府" };

	return drink[num];
}

void main(void)
{
	int n;
	char *p;
	scanf("%d", &n);
	p = Vending_Machine(n);
	printf("%s\n", p);
}
#endif#

//况农讥 1
#if 0
void main(void)
{
	char a = 65;
	char *p = &a;
	printf("%d\n", *p);
	*p = 97; printf("%d\n", *p);
	*p += 10; printf("%d\n", *p);
	(*p)++; printf("%d\n", *p);
}
#endif // 0

//况农讥 2锅
#if 0
void main(void)
{
	short a = 100;
	float b = 3.5f;
	short *p = &a;
	float *q = &b;
	printf("%d %f\n", *p, *q);
	printf("%x %x\n", p, q);
	printf("%d %d\n", sizeof(*p), sizeof(*q));
	printf("%x %x\n", p + 1, q + 1);
	printf("%d %d\n", *(p + 1), *(q + 1));
}
#endif // 0

//况农讥 4锅
#if 0
void Input(float *p)
{
	*p = 3.5f;
}
void main(void)
{
	float f;
	Input(&f);
	printf("f=%f\n", f);
}
#endif // 0

//况农讥 5锅
#if 0
void main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p = a;
	printf("%d, %d, %d\n", a[2], *(p + 2), p[2]);
	printf("%#.8x, %#.8x, %#.8x\n", &a[2], p + 2, &p[2]);
}
#endif // 0

//况农讥 8锅
#if 0
void main(void)
{
	int a[4] = { 1, 2, 3, 4 };
	int *p = a;
	printf("%d %d\n", p[0], p[2]);
}
#endif // 0

//况农讥 9锅

#if 0
int Max_Find(int *p, int num)
{
	int i, max = 0x80000000;
	for (i = 0; i < num; i++)
	{
		if (max < p[i]) max = p[i];
	}
	return max;
}

void main(void)
{
	int a[10] = { 40, 30, 20, 90, 60, 80, 35, 100, 70, 50 };
	printf("%d\n", Max_Find(a, sizeof(a) / sizeof(a[0])));

}
#endif // 0

//况农讥 10锅
#if 0
char * Name_Return(void)
{
	int i = 0;
	static char name[100] = "Hong GilDong";

	return name;
}
void main(void)
{
	char *p;
	p = Name_Return();
	printf("%s\n", p + 5);
}
#endif // 0


//况农讥 10锅-2
#if 0
char * Name_Return(void)
{
	int i=0;
	static char name[100] = "Hong GilDong";
	while (name[i] != ' ')
	{
		i++;
	}
	return name+i+1;
}
void main(void)
{
	char *p;
	p = Name_Return();
	printf("%s\n", p);
}
#endif // 0

//况农讥 11锅
#if 0
void Name_Edit(char *p)
{
	int i;
	p[0] -= 'a'-'A';
	while (*p != ' ')
	{
		p++;
	}
	*(p + 1) -= 'a' - 'A';
}
void main(void)
{
	char name[100] = "hong gildong";
	Name_Edit(name);
	printf("%s\n", name);
}
#endif // 0

//况农讥 12锅
#if 0
void main(void)
{
	char *p = "HiSCSA";
	char a[3][10] = { "Hi", "SCSA", "SAMSUNG" };
	printf("%s\n", p + 2);
	printf("%c\n", *(p + 3));
	printf("%s\n", a[1]);
	printf("%s\n", a[2] + 3);
}
#endif // 0

//况农讥 13锅
#if 0
void main(void)
{
	int i;
	char a[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	for (i = 0; i < 7; i++)
	{
		printf("%s\n", a[i]);
	}
}
#endif // 0

//况农讥 14锅

#if 0
char * Week_Calc(int num)
{
	static char a[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return a[num];
}

void main(void)
{
	int n;
	char *p;
	scanf("%d", &n);
	p = Week_Calc(n);
	printf("%s\n", p);
}
#endif // 0

//况农讥 15锅
#if 0
int strlen(char *p)
{
	int cnt = 0;
	while (p[0] != 0)
	{
		p++;
		cnt++;
	}
	return cnt;
}
void main(void)
{
	char a[100] = "honggildong";
	printf("%d\n", strlen(a));
}
#endif // 0
