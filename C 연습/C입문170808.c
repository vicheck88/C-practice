#include <stdio.h>
#include <stdlib.h>
// 抗力 16锅
#if 0
void main(void)
{
	int cnt = 0;
	char *p = "Enbedded";
	while (*p++)
	{
		cnt += (*p == 'd');
	}
	printf("%d\n", cnt);
}
#endif // 0

//抗力 17锅
#if 0
void str_copy(char *d, const char *s)
{
	while (*s) *d++ = *s++;
	*d = NULL;
}

void main(void)
{
	char a[5];
	char b[5] = "ABCD";
	str_copy(a, b);
	printf("%s\n%s\n", a, b);
}
#endif // 0

// 抗力 18锅
#if 0
unsigned int str_length(const char * d)
{
	unsigned int cnt = 0;
	while (*d++) cnt += sizeof(*d);
	return cnt;
}

void main(void)
{
	char a[] = "Willtek";

	printf("%d\n", sizeof(a));
	printf("%d\n", str_length(a));
}
#endif // 0

//抗力 19锅
#if 0
void str_add(char * d, const char * s)
{
	while (*d) d++;
	while (*d++=*s++) ;
}
void main(void)
{
	char a[15] = "Willtek";
	char b[15] = "Corp.";

	str_add(a, b);
	printf("%s\n", a);
}
#endif // 0

//抗力 20锅
#if 0
int str_comp(const char *a, const char *b)
{
	while (*a ||*b)
	{
		if (*a == *b)
		{
			a++; b++; continue;
		}
		return (*a > *b) ? 1 : -1;
	}
	return 0;
}
void main(void)
{
	printf("%d\n", str_comp("ABC", "BC"));
	printf("%d\n", str_comp("ABC", "AC"));
	printf("%d\n", str_comp("ABC", "AB"));
	printf("%d\n", str_comp("A", "AB"));
	printf("%d\n", str_comp("abc", "ABC"));
	printf("%d\n", str_comp("ab", " "));
	printf("%d\n", str_comp("ABC", "ABC"));
}
#endif // 0

#if 0
void main(void)
{
	int a = 10;
	int *p = &a;
	int **q = &p;
	printf("q: %x, q+1: %x, *q: %x, *q+1: %x, **q: %d\n", q, q + 1, *q, *q + 1, **q);
	printf("p: %x, p+1: %x, *p: %d\n", p, p + 1, *p);
}
#endif // 0

#if 0
int avg(int * x, int num)
{
	int i, sum = 0;
	for (i = 0; i < num; i++)
	{
		sum += x[i];
	}
	return sum / num;
}

void share(int *p, int *human, int *monkey, int avg, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (p[i] >= avg) *human++ = p[i];
		else *monkey++ = p[i];
	}

}

void main(void)
{
	int i;
	int n;
	int average;
	int cnt1 = 0, cnt2 = 0;
	int *monkey;
	int *human;
	scanf("%d", &n);
	int *p = malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		printf("%d ", p[i]);
	}
	printf("\n");
	average = avg(p, n);

	for (i = 0; i < n; i++)
	{
		(p[i] >= average) ? cnt1++ : cnt2++;
	}
	monkey = calloc(cnt2, sizeof(int));
	human = calloc(cnt1, sizeof(int));
	share(p, human, monkey, average, n);

	printf("average: %d\n", average);
	printf("human: ");
	for (i = 0; i < cnt1; i++)
	{
		printf("%d ", human[i]);
	}
	printf("\nmonkey: ");
	for (i = 0; i < cnt2; i++)
	{
		printf("%d ", monkey[i]);
	}
	printf("\n");

	free(p);
	free(human);
	free(monkey);
}

#endif // 0

//况农讥 1锅
#if 0
int Char_Find(char *p,char c)
{
	int cnt=0;
	while(*p++)
	{
		if(*(p-1)==c) cnt++;
	}
	return cnt;
}

int main(void)
{
	char a[110];
	char c;
	scanf("%s", a);
	scanf(" %c", &c);
	printf("%d\n", Char_Find(a, c));
	return 0;
}
#endif // 0

//况农讥 2锅
#if 0
void Upper_Disp(char *p)
{
	while (*p++)
	{
		if (*(p - 1) >= 'a') *(p - 1) -=32;
		printf("%c", *(p - 1));
	}
}
void main(void)
{
   	char a[110];
   	scanf("%s", a);
   	Upper_Disp(a);
}
#endif // 0

//况农讥 3锅
#if 0
void Reverse_Disp(char *p)
{
	int i;
	int cnt = 0;
	while (*p++) cnt++;
	for (i = -2; i >-cnt-2;i--)
	{
		printf("%c", p[i]);
	}
}

int main(void)
{
	char a[110];
	scanf("%s", a);
	Reverse_Disp(a);
	return 0;
}
#endif // 1

//况农讥 4锅
#if 0

void Upper_Change(char *dest, char *src)
{
	while(*src++)
	{
		(*(src-1)>='a') ? (*dest=*(src-1)-32):(*dest=*(src-1));
		dest++;
	}
	*dest = 0;
}
int main(void)
{
	char s_str[110];	// src 
	char d_str[110]; // dest 
	scanf("%s", s_str);
	Upper_Change(d_str, s_str);
	printf("%s", d_str);
	return 0;
}

#endif // 0

//况农讥 7锅
#if 0
void Input(int *p)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &p[i]);
	}
}
void Display(int *p)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", p[i]);
	}
}
int main(void)
{
	int a[5];
	Input(a);
	Display(a);
	return 0;
}
#endif // 0

//况农讥 8锅
#if 0
char * Week_Calc(int num)
{
	static char *week[7] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return week[num];
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%s\n", Week_Calc(n));
	return 0;
}
#endif // 0


//况农讥 9锅
#if 0
void str_copy(char *d, const char *s)
{
	while (*d++ = *s++);
}
void Swap(char *ap, char *bp)
{
	char tmp[110];
	str_copy(tmp, bp);
	str_copy(bp, ap);
	str_copy(ap, tmp);
}

int main(void)
{
	char a[110], b[110];
	scanf("%s %s", a, b);
	Swap(a, b);
	printf("%s %s\n", a, b);
	return 0;
}
#endif // 0

void main()
{
	int a[2] = { 1, 2 };
	printf("%d", 1[a]);
}