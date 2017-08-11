#include <stdio.h>
// 예제 16번
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

//예제 17번
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

// 예제 18번
#if 0
unsigned int str_length(const char * d)
{
	unsigned int cnt = 0;
	while (*d++)
	{
		cnt += sizeof(*d);
	}
	return cnt;
}

void main(void)
{
	char a[] = "Willtek";

	printf("%d\n", sizeof(a));
	printf("%d\n", str_length(a));
}
#endif // 0

//예제 19번
#if 1
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

//예제 20번
#if 0
int str_comp(const char *a, const char *b)
{
	while (*a)
	{
		if (*a > *b) return 1;
		else if (*a < *b) return 0;
		a++;b++;
	}
	return 0;
}
void main(void)
{
	printf("%d\n", str_comp("ABC", "BC"));
	printf("%d\n", str_comp("ABC", "AC"));
	printf("%d\n", str_comp("ABC", "AB"));
	printf("%d\n", str_comp("abc", "ABC"));
	printf("%d\n", str_comp("ab", " "));
	printf("%d\n", str_comp("ABC", "ABC"));
}
#endif // 0
