#if 0
//약수의 수가 짝수인 수

//두 정수 A, B를 입력 받아서 A이상 B이하의 정수들 중 약수의 수가 짝수인 수의 개수를 출력하는 프로그램을 작성하시오.
//예를 들어, A가 4이고 B가 10인 경우, 약수의 개수가 짝수인 수는 5, 6, 7, 8, 10으로 총 5개가 존재한다.
//계산이 빠른 방법을 고민하라.

//약수의 개수가 홀수인 수: 완전제곱수를 의미
//따라서 전체 수에서 완전제곱수를 제거하여 답 구함

#include <stdio.h>

int N;
int sol;

double sqrt(const double d) //제곱근 구하기
{
	double tmp = 2;
	double x = 1;
	while (tmp - x > 0.005 || tmp - x < -0.005)
	{
		tmp = x;
		x = d / (2 * x) + x / 2;
	}
	return x;
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", b - a + 1 - (int)sqrt(b) + (int)sqrt(a - 1)); //범위 내 수에서 완전제곱수를 제거
	return 0;
}
#endif // 0

#if 0
//시간외 근무 수당
//A대학에서는 시간외 근무를 수기로 작성하고 있다.행정실의 K씨는 시간외 근무 수당을 전산으로 처리하고자 한다.이 대학의 시간외 근무 수당 규정은 아래와 같다.
//
//1. 시간외 근무는 최초 1시간은 제외하며, 최대 4시간까지 인정한다.
//2. 시간외 근무에 따른 금액은 30분에 5, 000원으로 한다.
//3. 5일간의 시간외 근무 합계가 15시간 이상이면 받는 금액의 5 % 를 감하여 지급한다.
//4. 5일간의 시간외 근무 합계가 5시간 이하이면 받는 금액의 5 % 를 더하여 지급한다.
//
//시간외 근무 수당을 계산하는 프로그램을 작성하시오.

//문제 설명 순서대로 코드를 작성, 해결

int main(void)
{
	int i;
	double sum = 0;
	double money = 0;
	double s[5], e[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%lf %lf", &s[i], &e[i]);

		if (e[i] - s[i] > 1)
		{

			if (e[i] - s[i] - 1 >= 4)
			{
				sum += 4;
				money += 40000;
			}
			else
			{
				sum += e[i] - s[i] - 1;
				money += (e[i] - s[i] - 1) * 10000;
			}
		}
	}

	if (sum >= 15) money *= 0.95;
	else if (sum <= 5) money *= 1.05;

	printf("%d\n", (int)money);
}
#endif // 0

#if 0
//케이크 자르기
//둥근 케이크에 일정 간격으로 1~100의 번호가 부여됨
// 케이크를 두 조각으로 자를 때 교차하는 부분이 있는지를 검토

//자르는 방향 중 한 방향을 고정, 최소 최대값을 구함
//다른 방향의 좌표가 기존 좌표와 비교하여 어느 위치에 있는지를 검토
int main(void)
{
	int x[2], y[2];
	int tmp;
	scanf("%d %d", &x[0], &x[1]);
	scanf("%d %d", &y[0], &y[1]);
	if (x[0] > x[1])
	{
		tmp = x[0];
		x[0] = x[1];
		x[1] = tmp;
	}
	if (y[0] > y[1])
	{
		tmp = y[0];
		y[0] = y[1];
		y[1] = tmp;
	}

	if (y[0] < x[0])
	{
		if (y[1] > x[1] || y[1]<x[0]) printf("not cross");
		else printf("cross");
	}
	else if (y[0] > x[1]) printf("not cross");
	else if (x[0] < y[0] && y[0] < x[1])
	{
		if (y[1] < x[1]) printf("not cross");
		else printf("cross");
	}
	else printf("cross");
}

#endif // 0

#if 0
//합과 평균, 표준편차
//평균, 표준편차를 구하면 됨
int main(void)
{
	int n;
	int i;
	int *p;
	int sum = 0;
	double mean;
	double var = 0;
	double std = 0;
	scanf("%d", &n);
	p = calloc(n, sizeof(int)); // 동적할당을 통해 원하는 사이즈를 할당
	for (i = 0; i < n; i++)
	{
		scanf("%d", p + i);
		sum += p[i];
	}
	mean = 1.0*sum / n;
	for (i = 0; i < n; i++)
	{
		var += (p[i] - mean)*(p[i] - mean) / n;
	}
	std = sqrt(var);
	printf("%d\n", sum);
	if ((int)((mean + 0.05) * 10) % 10 != 0) printf("%.1f\n", mean);
	else printf("%.0f\n", mean);
	if ((int)((std + 0.05) * 10) % 10 != 0) printf("%.1f\n", std);
	else printf("%.0f\n", std);
	free(p);
	return 0;
}
#endif // 0

#if 0
//최대공약수와최소공배수
//두 자연수의 최대공약수, 최소공배수 구하기
int gcd(int x, int y)
{
	int m = 1;
	while (m) //유클리드 호제법 사용
	{
		m = x%y;
		x = y; y = m;
	}
	return x;
}
int main(void)
{
	int m, n;
	scanf("%d%d", &n, &m);
	printf("%d\n%d\n", gcd(n, m), n*m / gcd(n, m));
	return 0;
}
#endif // 0

#if 0
//최대공약수와 최소공배수(여러개)
//여러개의 최대공약수,최소공배수를 구하기
int gcd(int x, int y)
{
	int m = 1;
	while (m)
	{
		m = x%y;
		x = y; y = m;
	}
	return x;
}

int lcd(int x, int y) return x*y / gcd(x, y);

int main(void)
{
	int n;
	int m[10];
	int i;
	int gc = 1;
	int lc = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m[i]); //최대공약수, 최소공배수를 누적하면서 구하기
		if (i == 0)
		{
			gc = lc = m[0];
		}
		else
		{
			gc = gcd(m[i], gc);
			lc = lcd(m[i], lc);
		}
	}
	printf("%d %d\n", gc, lc);
}
#endif // 0

#if 0
//찢어진 책
//도서관 사서인 현준이는 만화책의 한 장이 찢어졌다는 것을 알고, 찢어진 페이지를 알아보려고 한다.그 만화책은 N
//페이지(N은 짝수)였고, 1, 2쪽이 같은 종이에 있고 그 뒤부터 N쪽까지 쭉 쪽수가 매겨져 있다.현준이는 책의 쪽번호
//의 합을 구하는 기계를 가지고 있었기 때문에, 쪽번호의 합 Sum을 구할 수 있었으나, 그걸 이용해서 찢어진 페이지
//의 번호를 구하기에는 역부족이었다.
//
//현준이를 도와 찢어진 페이지를 구하는 프로그램을 작성하여라.

//책의 페이지가 짝수라는 점, 1,2쪽이 같은 종이에 있다는 점을 이용
//여러가지의 예외 케이스를 고려하는 데에 유의할 것

int main(void)
{
	int n;
	int sum;
	int dif;
	int real_sum;
	scanf("%d %d", &n, &sum);
	if ((n < 2 || n>500) || (sum < 1 || sum>125000) || n & 1) printf("Error");
	real_sum = (1 + n)*n / 2;
	dif = real_sum - sum;
	if (!(dif & 1) || !(dif / 2 & 1) || dif<0 || n<dif / 2 + 1) printf("Error");
	else printf("%d %d", dif / 2, dif / 2 + 1);
}
#endif // 0

#if 0
//금메달은 누구?
//각 종목은 토너먼트 방식으로 진행되며 1등 4점, 2등 3점, 3등 2점, 나머지는 1점을 준다.최종 평가는 각 종목의
//점수를 모두 합하여 점수가 가장 높은 사람이 1등, 그 다음 사람이 2등...이렇게 순위가 정해지고, 1등은 금메달, 2등
//은 은메달, 3등은 동메달을 준다.이때 같은 점수는 같은 등수로 하고 같은 메달을 준다.즉, 합이 5, 8, 16, 8, 5, 6
//이라면, 16점이 1등(금메달)1명, 8점이 2등 (은메달)2명, 6점 3등(동메달)1명이 된다.
//
//참가 인원과 각 종목의 점수가 주어지면 금메달, 은메달, 동메달을 받는 사람이 누구인지를 구하는 프로그램을 작성하시오.

//이중 정렬을 이용, 원하는 결과를 도출
int main(void)
{
	int i;
	int j;
	int k = 0;
	int n;
	int tmp;
	int cnt = 0;

	int p[10][6] = { 0 };
	int id[10];
	int medal[3][10] = { 0 };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 5; j++) 
		{
			scanf("%d", &p[i][j]);
			if (j != 0) p[i][5] += p[i][j];
		}
		id[i] = p[i][0];
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (p[i][5] < p[j][5]) //점수를 정렬
			{
				tmp = p[i][5];
				p[i][5] = p[j][5];
				p[j][5] = tmp;

				tmp = id[i];
				id[i] = id[j];
				id[j] = tmp;
			}
			else if (p[i][5] == p[j][5] && id[i]>id[j]) //점수가 같을 때 id를 정렬
			{
				tmp = id[i];
				id[i] = id[j];
				id[j] = tmp;
			}
		}

		if (i>0 && p[i][5] != p[i - 1][5])
		{
			cnt++;
			k = 0;
		}
		if (cnt > 2) break;
		medal[cnt][k] = id[i];
		k++;
	}

	for (i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0: printf("GOLD :"); break;
		case 1: printf("SILVER :"); break;
		case 2: printf("BRONZE :"); break;
		}
		for (j = 0; j < 10; j++)
		{
			if (medal[i][j] != 0) printf(" %d", medal[i][j]);
			else break;
		}
		printf("\n");
	}
	return 0;
}
#endif // 0

#if 0
//배수의 합
//양의 정수 N(1이상, 10, 000미만)을 입력 받아, N부터 N의 배수의 합을 구해서 합이 10, 000을 넘지 않도록 하는 가장 큰 N의 배수 K를 인쇄하라.
//예를 들어, N이 7이라면, 7 + 14 + 21 + ... + K < 10, 000 인 K 중 가장 큰 값을 인쇄한다.
//N이 범위를 벗어나는 경우는 없다고 가정하고, 이에 대한 예외 처리는 하지 않는다.

int main(void)
{
	int i;
	int r = 1;
	int sum = 0;
	int n;
	scanf("%d", &n);
	for (i = n; sum < 10000; i += n) //n의 배수만을 더함
	{
		sum += i;
	}
	printf("%d", i - 2 * n);
	return 0;
}
#endif // 0
