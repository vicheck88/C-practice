#include <stdio.h>

// 이름, 나이 출력 함수
#if 0
void my_name() // parameter x, return x
{
	printf("한창혁\n");
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

//무게 함수 - prototype
#if 0
void weight(int); // 원형(prototype) 설정. 없을 경우 순서가 달라 오류가 남
// parameter 부분에는 타입만 적는 것으로 충분
void main(void)
{
	weight(50);
}
void weight(int w) // main 함수 뒤에 weight 함수를 정의
{
	printf("Weight = %d Kg\n", w);
}
#endif // 0

//연습문제1 (워크샵 함수 만들기)
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

//연습문제2 (실수 입력받아 사칙연산)
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


//연습문제3 (사과 입력받아 비율 인쇄)
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

//연습문제4 (정수 세개 받아 합계, 평균)
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

// my.h 헤더파일 만들기
#if 0
#include "my.h"

void main(void)
{
	weight(30);
}
#endif // 0

//함수 연습문제 9 (1)~(4)

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
	printf("%10s%10s%10s%10s\n","넓이","원화","가우스","주민번호");
	printf("%10.2f%10u%10d%10d\n", circle_area(r), japan_to_korea(yen), close_int(a), div(idcode));
}
#endif // 0