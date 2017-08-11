#include <stdio.h>
#pragma warning(disable:4996) // 전처리기로, scanf와 관련된 경고문이 뜨지 않도록 조치함

//scanf - 숫자
#if 0
void main(void)
{

	int i; double j;
	printf("Input:");
	scanf("%d %lf", &i, &j);
	// 주소를 전달하여 변수의 값을 메모리 주소 안에 입력 (&)
	// 여러개의 값을 동시에 입력받으며, Enter 또는 Space로 각 입력값들을 구분
	// 단, 최종 입력에는 Enter키가 필요
	// 2개보다 더 많은 숫자를 입력할 경우, 처음 두개만을 받아들임
	printf("Your choice: %d and %f\n", i, j);
	// float 입력엔 %f사용. double은 %lf 입력
}
#endif // 1

//scanf - 문자
#if 0
void main(void)
{
	char a, b, c;
	printf("input: ");
	scanf("%c%c", &a, &b); // b 값에는 공백값이 입력됨
	scanf("%c %c", &a, &b); // 올바른 형식. %c와 %c 사이에 공백이 필요
	fflush(stdin) // fflush에 의해 Enter키가 청소, 문자를 제대로 받을 수 있음
	scanf("%c", &c);
	printf("Your choice is: %c%c", a, b);
}
#endif // 1

//scanf-문자열
#if 0
void main(void)
{
	char a[100],b[100]; // 100개의 문자 배열을 선언
	printf("Input(100글자 미만 문자열):");
	scanf("%s", a);
	//scanf("%s", &a);
	//scanf("%s", &a[0]); // 세 가지 모두 맞는 문법. 배열의 이름은 그 주소를 저장
	// scanf명령은 단어 사이가 떨어져 있을 경우 앞의 부분만 인식. 
	// scanf는 자동으로 공백 문자를 무시하고 입력(%c 제외)
	// 전부를 입력하기 위해선 gets()함수가 필요함
	gets(b); // b에 문자열 입력
	// 이 경우, Enter로 scanf를 구분하면 b의 값은 enter값이 되어버림
	// 해결을 위해선 "%s "식으로 한 칸 띄우거나 enter로 구분하지 말아야
	printf("Your choice is: %s", a);
}
#endif // 0

//getchar,putchar,getch,putch
#if 0
void main(void)
{
	int a;
	printf("getchar => Input : ");
	a = getchar();
	printf("Your choice is : ");
	putchar(a);
	putchar('\n'); // putchar는 강제 개행 필요. 문자형식으로 표기해야함
	printf("getch => Input : ");
	a = getch();
	printf("\n"); // printf는 항상 문자열로 표기해야함
	printf("Your choice is : ");
	putch(a);
	putch('\n');
}
#endif // 1


// 4. 기본 연산자

// 대입
#if 0
void main(void)
{
	int a = 0x12345678;
	unsigned char b;
	b = a; // a를 b에 대입: a값 중 가장 앞에 있는 메모리 주소가 b에 대입됨
	printf("a=%#.8x,b=%#.8x\n", a, b); // a=0x12345678, b=0x00000078
	a = b; // b를 a에 대입
	printf("a=%#.8x,b=%#.8x\n", a, b); // a=b=0x00000078
}
#endif // 0

//연산자 우선순위
#if 0
void main(void)
{
	int a = 10;
	int b = 20;
	int c;
	c = +a - -b;
	printf("c = %d\n", c);

	c = sizeof(a) + -b; // sizeof(a): a의 바이트크기를 알려줌
	printf("c = %d\n", c);
}
#endif // 0

// /,% 이용한 응용
#if 0
void main(void)
{
	int a = 2345; int a4, a3, a2, a1;
	a4 = a / 1000;
	a3 = (a % 1000) / 100;
	a2 = (a % 100) / 10;
	a1 = a % 10;
	printf("1000자리=%d, 100자리=%d, 10자리=%d, 1자리=%d\n", a4, a3, a2, a1);
}
#endif // 0

//복합 대입 연산자
#if 0
void main(void)
{
	int a = 20, b = 4;
	a += 3; // a = a+3
	printf("%d\n", a);
	a -= b; // a = a-b
	printf("%d\n", a);
	a *= b + 2; // a=a * (b+2)
	printf("%d\n", a);
	a /= a - b + 1; // a = a / ( a-b+1)
	printf("%d\n", a);
	a %= b -= 3; // a= a % (b-3)
	printf("%d\n", a);
}
#endif // 0

//증가/감소 연산자 ++,--
#if 0
void main(void)
{
	int a = 10, b = 10;
	b = ++a + b; // b = 11+10 = 21
	printf("a=%d, b=%d\n", a, b); // a=11, b=21
	// a값을 먼저 증가시킨 뒤 전체 계산 수행
	b = a++ + b; // b = 11+21 = 32
	printf("a=%d, b=%d\n", a, b); // a=12, b = 32
	// 전체 계산을 먼저 수행하고 그 뒤에 a값을 증가시킴
}
#endif // 1

// 연습문제1
#if 0
void main()
{
	int a = 1, b = 2, c = 3;
	//a = -3 * -4 % +6 / 5; printf("%d %d %d", a, b, c); // 0 2 3
	//a += b - c *= 2; printf("%d %d %d", a, b, c);
	// 오류 b-c가 좌변값이 아님
	// b-c가 우선적으로 계산되고, 이때 b-c는 상수값이 되어버림
	// 상수값에 곱하기 연산이 불가하므로 b-c는 좌변값의 자격을 가지지 않음
	//a += b -= c *= 2; printf("%d %d %d\n", a, b, c); //-3 -4 6
}
#endif // 0

//연습문제2
#if 0
void main(void)
{
	int p[4], a;
	printf("16진수 입력 : ");
	scanf("%x", &a);
	p[3] = a / 0x1000;
	p[2] = a / (0x100) % 0x10;
	p[1] = a / 0x10 % 0x10;
	p[0] = a % 0x10;
	printf("0x1000자리=%X, 0x100자리=%X, 0x10자리=%X, 0x1자리=%X\n", p[3], p[2], p[1], p[0]);
}
#endif // 0

//연습문제3
#if 0
void main(void)
{
	char brand[100], ans;
	int price; float wide;
	printf("브랜드 : ");
	scanf("%s", brand);
	printf("노트기능유무(y/n) : ");
	scanf(" %c", &ans);
	printf("화면크기(인치) : ");
	scanf("%f", &wide);
	printf("가격 : ");
	scanf("%d", &price);
	printf("%s, 노트기능 %c, %.1f인치, %d원\n", brand, ans, wide, price);

}
#endif