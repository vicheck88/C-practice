//스택
/*정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/

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