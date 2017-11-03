//����
/*������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.*/

#include <stdio.h>
int stack[10010];
int sp=-1;
char arg[6];
int N;
int num;
void push(int n)
{
	stack[++sp] = n;
}
int pop(void)
{
	if (sp == -1) return -1;
	return stack[sp--];
}
int size(void)
{
	return sp + 1;
}
int empty(void)
{
	if (size()) return 0;
	return 1;
}
int top(void)
{
	if (sp == -1) return -1;
	return stack[sp];
}

int strcmp(char *p, char *q)
{
	for (;;)
	{
		if (*p != *q) return *p - *q;
		if (!*p && !*q) return 0;
		p++; q++;
	}
}
int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", arg);
		if (!strcmp(arg, "push"))
		{
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(arg, "pop")) printf("%d\n",pop());
		else if (!strcmp(arg, "top")) printf("%d\n", top());
		else if (!strcmp(arg, "empty")) printf("%d\n", empty());
		else if (!strcmp(arg, "size")) printf("%d\n", size());
	}
}