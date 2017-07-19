#include <stdio.h>

// �̸�, ���� ��� �Լ�
#if 0
void my_name() // parameter x, return x
{
	printf("��â��\n");
}
int my_age() // parameter x, return int
{
	return 30;
}
void print_age(int a) // parameter int, return x
{
	printf("%d\n", a);
}
int get_age(int a, int b) // parameter int*2, return int
{
	return a - b + 1;
}
void main()
{
	my_name();
	print_age(my_age());
	printf("%d\n", get_age(2017, 1988));
}

#endif // 0

//���� �Լ� - prototype
#if 0
void weight(int); // ����(prototype) ����. ���� ��� ������ �޶� ������ ��
// parameter �κп��� Ÿ�Ը� ���� ������ ���
void main(void)
{
	weight(50);
}
void weight(int w) // main �Լ� �ڿ� weight �Լ��� ����
{
	printf("Weight = %d Kg\n", w);
}
#endif // 0

//��������1 (��ũ�� �Լ� �����)
#if 0
void Upper_Disp(char c)
{
	printf("%c", c - 32);
}

int lower_to_upper()
{
	char a;
	scanf(" %c", &a);
	return (a - ('a' - 'A'));
}
void main(void)
{
	char ch;

	Upper_Disp('a');
	ch = lower_to_upper();
	printf("%c", ch);
}
#endif // 0

//��������2 (�Ǽ� �Է¹޾� ��Ģ����)
#if 0
double cal(double a, double b)
{
	double result;
	if (b == 0) result = 0;
	else result = a / b;
	printf("%f, %f, %f, %f", a + b, a - b, a*b, result);
}
void main(void)
{
	double a, b;
	scanf("%lf%lf", &a, &b);
	cal(a, b);
}
#endif // 0


//��������3 (��� �Է¹޾� ���� �μ�)
#if 0
int apple(int all,int want)
{
	return want * 100 / all;
}
void main()
{
	int all,want;
	scanf("%d%d",&all,&want);
	printf("%d\n", apple(all,want));
}
#endif // 0

//��������4 (���� ���� �޾� �հ�, ���)
#if 0
int sum(int a, int b, int c)
{
	return a + b + c;
}
double avg(int a, int b, int c)
{
	return (a + b + c) / 3.0;
}
void main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("sum= %d\n", sum(a, b, c));
	printf("avg= %lf\n", avg(a, b, c));
}
#endif // 0

// my.h ������� �����
#if 0
#include "my.h"

void main(void)
{
	weight(30);
}
#endif // 0

//�Լ� �������� 9 (1)~(4)

#if 0
float circle_area(float r)
{
	float pi = 3.14f;
	return r*r*pi;
}

unsigned int japan_to_korea(unsigned int yen)
{
	int rate = 11;
	return (rate * yen / 10) * 10;
}

int close_int(float a)
{
	if (a < 0) return 0;
	float b = a + 0.5;
	return a + 0.5;

}

unsigned int div(int idcode)
{
	int a = (idcode / 100) % 100;
	return ((a % 4) + 1);
}

void main(void)
{
	float r, a;
	unsigned int yen, idcode;
	scanf("%f%u%f%d", &r, &yen, &a, &idcode);
	printf("%10s%10s%10s%10s\n","����","��ȭ","���콺","�ֹι�ȣ");
	printf("%10.2f%10u%10d%10d\n", circle_area(r), japan_to_korea(yen), close_int(a), div(idcode));
}
#endif // 0