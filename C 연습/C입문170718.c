#include <stdio.h>
#pragma warning(disable:4996) // ��ó�����, scanf�� ���õ� ����� ���� �ʵ��� ��ġ��

//scanf - ����
#if 0
void main(void)
{

	int i; double j;
	printf("Input:");
	scanf("%d %lf", &i, &j);
	// �ּҸ� �����Ͽ� ������ ���� �޸� �ּ� �ȿ� �Է� (&)
	// �������� ���� ���ÿ� �Է¹�����, Enter �Ǵ� Space�� �� �Է°����� ����
	// ��, ���� �Է¿��� EnterŰ�� �ʿ�
	// 2������ �� ���� ���ڸ� �Է��� ���, ó�� �ΰ����� �޾Ƶ���
	printf("Your choice: %d and %f\n", i, j);
	// float �Է¿� %f���. double�� %lf �Է�
}
#endif // 1

//scanf - ����
#if 0
void main(void)
{
	char a, b, c;
	printf("input: ");
	scanf("%c%c", &a, &b); // b ������ ���鰪�� �Էµ�
	scanf("%c %c", &a, &b); // �ùٸ� ����. %c�� %c ���̿� ������ �ʿ�
	fflush(stdin) // fflush�� ���� EnterŰ�� û��, ���ڸ� ����� ���� �� ����
	scanf("%c", &c);
	printf("Your choice is: %c%c", a, b);
}
#endif // 1

//scanf-���ڿ�
#if 0
void main(void)
{
	char a[100],b[100]; // 100���� ���� �迭�� ����
	printf("Input(100���� �̸� ���ڿ�):");
	scanf("%s", a);
	//scanf("%s", &a);
	//scanf("%s", &a[0]); // �� ���� ��� �´� ����. �迭�� �̸��� �� �ּҸ� ����
	// scanf����� �ܾ� ���̰� ������ ���� ��� ���� �κи� �ν�. 
	// scanf�� �ڵ����� ���� ���ڸ� �����ϰ� �Է�(%c ����)
	// ���θ� �Է��ϱ� ���ؼ� gets()�Լ��� �ʿ���
	gets(b); // b�� ���ڿ� �Է�
	// �� ���, Enter�� scanf�� �����ϸ� b�� ���� enter���� �Ǿ����
	// �ذ��� ���ؼ� "%s "������ �� ĭ ���ų� enter�� �������� ���ƾ�
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
	putchar('\n'); // putchar�� ���� ���� �ʿ�. ������������ ǥ���ؾ���
	printf("getch => Input : ");
	a = getch();
	printf("\n"); // printf�� �׻� ���ڿ��� ǥ���ؾ���
	printf("Your choice is : ");
	putch(a);
	putch('\n');
}
#endif // 1


// 4. �⺻ ������

// ����
#if 0
void main(void)
{
	int a = 0x12345678;
	unsigned char b;
	b = a; // a�� b�� ����: a�� �� ���� �տ� �ִ� �޸� �ּҰ� b�� ���Ե�
	printf("a=%#.8x,b=%#.8x\n", a, b); // a=0x12345678, b=0x00000078
	a = b; // b�� a�� ����
	printf("a=%#.8x,b=%#.8x\n", a, b); // a=b=0x00000078
}
#endif // 0

//������ �켱����
#if 0
void main(void)
{
	int a = 10;
	int b = 20;
	int c;
	c = +a - -b;
	printf("c = %d\n", c);

	c = sizeof(a) + -b; // sizeof(a): a�� ����Ʈũ�⸦ �˷���
	printf("c = %d\n", c);
}
#endif // 0

// /,% �̿��� ����
#if 0
void main(void)
{
	int a = 2345; int a4, a3, a2, a1;
	a4 = a / 1000;
	a3 = (a % 1000) / 100;
	a2 = (a % 100) / 10;
	a1 = a % 10;
	printf("1000�ڸ�=%d, 100�ڸ�=%d, 10�ڸ�=%d, 1�ڸ�=%d\n", a4, a3, a2, a1);
}
#endif // 0

//���� ���� ������
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

//����/���� ������ ++,--
#if 0
void main(void)
{
	int a = 10, b = 10;
	b = ++a + b; // b = 11+10 = 21
	printf("a=%d, b=%d\n", a, b); // a=11, b=21
	// a���� ���� ������Ų �� ��ü ��� ����
	b = a++ + b; // b = 11+21 = 32
	printf("a=%d, b=%d\n", a, b); // a=12, b = 32
	// ��ü ����� ���� �����ϰ� �� �ڿ� a���� ������Ŵ
}
#endif // 1

// ��������1
#if 0
void main()
{
	int a = 1, b = 2, c = 3;
	//a = -3 * -4 % +6 / 5; printf("%d %d %d", a, b, c); // 0 2 3
	//a += b - c *= 2; printf("%d %d %d", a, b, c);
	// ���� b-c�� �º����� �ƴ�
	// b-c�� �켱������ ���ǰ�, �̶� b-c�� ������� �Ǿ����
	// ������� ���ϱ� ������ �Ұ��ϹǷ� b-c�� �º����� �ڰ��� ������ ����
	//a += b -= c *= 2; printf("%d %d %d\n", a, b, c); //-3 -4 6
}
#endif // 0

//��������2
#if 0
void main(void)
{
	int p[4], a;
	printf("16���� �Է� : ");
	scanf("%x", &a);
	p[3] = a / 0x1000;
	p[2] = a / (0x100) % 0x10;
	p[1] = a / 0x10 % 0x10;
	p[0] = a % 0x10;
	printf("0x1000�ڸ�=%X, 0x100�ڸ�=%X, 0x10�ڸ�=%X, 0x1�ڸ�=%X\n", p[3], p[2], p[1], p[0]);
}
#endif // 0

//��������3
#if 0
void main(void)
{
	char brand[100], ans;
	int price; float wide;
	printf("�귣�� : ");
	scanf("%s", brand);
	printf("��Ʈ�������(y/n) : ");
	scanf(" %c", &ans);
	printf("ȭ��ũ��(��ġ) : ");
	scanf("%f", &wide);
	printf("���� : ");
	scanf("%d", &price);
	printf("%s, ��Ʈ��� %c, %.1f��ġ, %d��\n", brand, ans, wide, price);

}
#endif