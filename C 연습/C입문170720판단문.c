#include <stdio.h>

//예제 7
#if 0
int compare(int num)
{

	if (num % 2 == 0) return 2;
	else if (num % 3 == 0) return 3;
	else if (num % 5 == 0) return 5;
	return 0;

}
void main()
{
	printf("3 => %d\n", compare(3));
	printf("62 => %d\n", compare(62));
	printf("25 => %d\n", compare(25));
	printf("157 => %d\n", compare(157));
}
#endif // 0

//예제 10
#if 0
void main()
{
	int a = 3;
	printf("%d\n", !1);
	printf("%d\n", !0);
	printf("%d\n", !(a == 3));
	printf("%d\n", !a == 3);
	printf("%d\n", !(a + 3));
}
#endif // 0

//예제 11
#if 0
int multiple_of_3(int num)
{
	//return 1 - ((num % 3 + 1) / 2);
	return num % 3 == 0;
}

void main(void)
{
	printf("3 => %d\n", multiple_of_3(3));
	printf("8 => %d\n", multiple_of_3(8));
	printf("27 => %d\n", multiple_of_3(27));
	printf("513 => %d\n", multiple_of_3(513));
}
#endif // 0

//예제 14
#if 0
void main()
{
	int a, b, c;
	if (a = 3, b = 4, c = 0) printf("True\n");
	else printf("False\n");
	printf("%d, %d, %d",a,b,c);
}  
#endif // 0

//예제 15
#if 0
int add(int a, int b)
{
	return a + b;
}
void main(void)
{
	int a;

	printf("%d\n", add(3, 4, 5));
	printf("%d\n", add(3, (4, 5)));

	a = 3, 4;
	printf("%d\n", add(a, 10));
	a = (50, 100);
	printf("%d\n", add(a, 200));
}
#endif // 0

//예제 15-2
#if 0
void main()
{
	int a, b, c;
	a = (b = 3, c = b + 4, c + 1);
	printf("%d, %d, %d\n", a, b, c);

	a = b = 3, c = b + 4, c + 1;
	printf("%d, %d, %d\n", a, b, c);
}
#endif // 0

//예제 16
#if 0
int three_five_div(int num)
{
	int a, b, c;
	a = num % 3 != 0;
	b = num % 5 != 0;
	c = !(a * b);
	return c;
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", three_five_div(n));
}
#endif // 0

//예제 17
#if 0
int between(int num)
{
	return (4 <= num && num <= 10);
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("%d", between(n));
}
#endif // 0

//예제 18
#if 0
int cap(char c)
{
	return (c >='A' && c<='Z') || (c>='a' && c<='z');
}
void main()
{
	char c;
	scanf(" %c", &c);
	printf("%d", cap(c));
}
#endif // 0

//예제 19
#if 0
void main()
{
	int a = 4, b = 0;
	if (a == 5 && b = 3) b++; //연산자 우선순위에 의해 ((a==5) && b)=3. 좌변은 0이므로 l-value 오류 발생
	printf("%d\n", b);
}
#endif // 0

//예제 20
#if 0
void main()
{
	int a = 4, b = 0;
	if ((a == 5) && (b = 3)) b++; // a==5 구문이 0이므로 b=3 연산 수행 안함. 따라서 b=0
	printf("%d\n", b);
}
#endif // 0


//예제 21
#if 0
void main()
{
	int a = 4, b = 0;
	if ((a < 5) || (b = 3)) b++; // a<5 구문이 참이므로 예제 20처럼 b=3 연산 수행 안함. 따라서 b++가 적용되어 b=1
	printf("%d\n", b);
}
#endif // 0

#if 0
void main()
{
	int a = 10, b = 20;
	(a == 20) ? (b < 0) ? (a = 1) : (a = 0) : (b = 30);
	printf("a=%d, b=%d\n", a, b);
}
#endif // 0

//예제 26
#if 0
int lower(char c)
{
	return ('f' <= c && c <= 'z');
}

//예제 27
char lower_upper(char d)
{
	if ('A'<=c && c<='Z') return d + 32;
	else if ('a'<=c && c<='z') return d - 32;
	else return;
}

char lew(char e)
{
	if (e == 'L' || e == 'E' || e == 'W') return '*';
	else return e;
}

int round(double n)
{
	if (n > 0) return n + 0.5;
	else return n - 0.5;
}

void main()
{
	char c;
	double n;
	scanf(" %c%lf", &c, &n);
	printf("%d\n", lower(c));
	printf("%c\n", lower_upper(c));
	printf("%c\n", lew(c));
	printf("%d\n", round(n));
}
#endif // 0

//예제 32
#if 0
void main()
{
	int n, lucky1 = 7, lucky2 = 3, lucky3 = 77;
	scanf("%d", &n);
	switch (n)
	{
	case 7: printf("컴퓨터\n"); break;
	case 3: printf("여행티켓\n"); break;
	case 77: printf("로또당첨\n"); break;
	default: printf("꽝\n");
	}
}
#endif // 0

//예제 33
#if 0
void main()
{
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 300: printf("바닷가재\n");
	case 200: printf("꽁치\n");
	case 100: printf("고등어\n"); break;
	default: printf("안팔아!\n");
	}
}
#endif // 0

//예제 34
#if 0
//if else로
char grade_if(int score)
{
	if (0 > score || score > 100) return 'X';
	else if (score > 90) return 'A';
	else if (score > 80) return 'B';
	else if (score > 70) return 'C';
	else if (score > 60) return 'D';
	else return 'F';
}
//switch case로
char grade_switch(int score)
{
	if (0 > score || score > 100) return 'X';
	score = (score - 1) / 10;
	switch (score)
	{
	case 9: return 'A'; break;
	case 8: return 'B'; break;
	case 7: return 'C'; break;
	case 6: return 'D'; break;
	default: return 'F';
	}
}

void main()
{
	int score;
	scanf("%d", &score);
	printf("Grade : %c\n", grade_switch(score));
}
#endif // 0

//번외 문제
#if 0
int main()
{
	int h1, m1, s1;
	int h2, m2, s2;
	int sec1, sec2, dif;
	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);

	if (h2 <= h1) h2 += 24;
	else if (h1 == h2 && m2 <= m1) h2 += 24;
	else if (h1 == h2 && m2 == m1 && s2 <= s1) h2 += 24;


	sec1 = h1 * 3600 + m1 * 60 + s1;
	sec2 = h2 * 3600 + m2 * 60 + s2;

	dif = sec2 - sec1;
	printf("%02d:%02d:%02d\n", dif / 3600, (dif % 3600) / 60, dif % 60);
}
#endif // 0

// 워크샵
// 문제 1
#if 0
int Max_Calc(int a, int b);

int main(void)
{
	//함수작성
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", Max_Calc(a, b));

	return 0;
}

int Max_Calc(int a, int b)
{
	//함수작성
	if (a > b) return a;
	else return b;
}
#endif // 0

// 문제 2
#if 0
void Num_Comp(int a, int b);

int main(void)
{
	//함수작성
	int a, b;
	scanf("%d%d", &a, &b);
	Num_Comp(a, b);
	return 0;
}

void Num_Comp(int a, int b)
{
	//함수작성
	if (a > b) printf("%d > %d", a, b);
	else if (a < b) printf("%d < %d", a, b);
	else printf("%d == %d", a, b);
}
#endif // 0

//문제 3
#if 0
int Num_Count(int num);

int main(void)
{
	//함수작성
	int num;
	scanf("%d", &num);
	printf("%d", Num_Count(num));
	return 0;
}

int Num_Count(int num)
{
	//함수작성
	if (num <= 0) return 0;
	else if (num / 10 == 0) return 1;
	else if (num / 100 == 0) return 2;
	else if (num / 1000 == 0) return 3;
	else return 3;


}
#endif // 0

//문제 4
#if 0
int Abs_Calc(int num);

int main(void)
{
	//함수작성
	int num;
	scanf("%d", &num);
	printf("%d", Abs_Calc(num));
	return 0;
}

int Abs_Calc(int num)
{
	//함수작성
	if (num >= 0) return num;
	else return -num;
}
#endif // 0

//문제 5
#if 0
char Multiple_Calc(int num);

int main(void)
{
	//함수작성
	int num;
	scanf("%d", &num);
	printf("%c", Multiple_Calc(num));
	return 0;
}

char Multiple_Calc(int num)
{
	//함수작성
	int a, b;
	a = num % 3;
	b = num % 5;
	if (a + b == 0) return 'O';
	else return 'X';
}
#endif // 0

//문제 6
#if 0
int Num_Calc(int x, int y, char op);

int main(void)
{
	//함수작성
	int x, y;
	char op;
	scanf("%d%d %c", &x, &y, &op);
	printf("%d\n", Num_Calc(x, y, op));
	return 0;
}

int Num_Calc(int x, int y, char op)
{
	//함수작성
	if (op == '+') return x + y;
	else if (op == '-') return x - y;
	else if (op == '/') return x / y;
	else if (op == '%') return x%y;
	else if (op == '*') return x*y;
}
#endif // 0

//문제 7
#if 0
char Weight_Check(int weight);

int main(void)
{
	//함수작성
	int weight;
	scanf("%d", &weight);
	if (Weight_Check(weight) == 'X') printf("error\n");
	else printf("%c\n", Weight_Check(weight));
	return 0;
}

char Weight_Check(int weight)
{
	//함수작성
	if (weight < 0 || weight>200) return 'X';
	switch (weight / 10)
	{
	case 6: return 'M'; break;
	case 5: return 'L'; break;
	case 4:
	case 3:
	case 2:
	case 1:
	case 0: return 'F'; break;
	default: return 'H';
	}
}
#endif // 0

//문제 8
#if 0
int main()
{
	/*int a = 0, b = 3, c;
	c = !(a == b); printf("%d", c);
	c = a = b; printf("%d", c);
	c = !a++; printf("%d", c);
	c = (b % 2 == 0); printf("%d", c);
	return 0;*/

	/*int a, b, c;
	a=(b=0,c=b++,c+1); printf("%d", a);
	a = b = 0, c = b++, c + 1; printf("%d", a);*/

	/*int a;
	scanf("%d", &a);
	printf("%s\n", (a % 2 == 0) ? ("짝수") : ("홀수"));*/
}
#endif // 0