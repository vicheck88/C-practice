# C++
### 출력
- C와 달리 `include <iostream>` 사용
- `cout`이 `printf`의 역할을 수행(`std` 명령이 붙어야)

```cpp
    #include <iostream>
    //객체지향 라이브러리를 이용해 입력/출력을 제공
    using namespace std; 
    //std에 정의된 모든 것에 대해 이름공간을 생략한다
    int main(void)
    {
        std::cout << "Hello world\n";
        std::cout << "Hello" << " world"<<std::endl;
        std::cout << 100 << 3.14 << " world";
		// 정수, 실수가 전부 가능
        // using namespace std를 통해 std:: 명령 생략 가능

        int val1,val2;

        cout << "val1?";
        cin >> val1; // scanf의 역할 수행
        cout << "val2?";
        cin >> val2;

        int result = val1 + val2;
        cout << "result: " << result << endl;

		double dnum;
        std::cout << "dnum?";
        cin >> dnum;
        cout << "dnum: " << dnum << endl;
        
        char name[20];
        cout << "name?";
        cin >> name; // scanf처럼 공백을 포함하지 않음
        cin.getline(name, 20); // 공백을 포함하는 명령(gets같음)
        cout << "성명: " << name << endl;
        return 0;
    }
```

### 데이터 타입
- 기본적인 데이터 타입은 C와 동일
- 8바이트 정수는 `_int64`타입을 이용
	- C++에만 존재하며, long long 타입과 같음(C와는 다름)
- 형변환 역시 C와 동일

```cpp
    #include <iostream>
    using namespace std; 

    int main(void)
    {
        char ch = 'A';
        int iNum = 100;
        long int lNum = 2100000000000000;
        float fNum = 1.2;
        double dNum = 3.4;
        long long long_Num;
        cout << sizeof(ch) << ", " << sizeof(iNum) << ", "
            << sizeof(fNum) << ", " << sizeof(dNum) <<  ", " << sizeof(lNum) 
            << ", " << sizeof(long_Num) << endl;
        return 0;
    }
```

### bool 타입
- C++에만 존재하는 타입
- 참(true), 거짓(false)를 나타내는 타입
- bool타입의 크기는 1바이트로, char와 크기가 같음

```cpp
    #include <iostream>
    using namespace std; 

    bool IsPositive(int n)
    {
        return n > 0;
    }


    int main(void)
    {
        bool b1 = true;
        cout << "bool: " << b1 << endl;
        b1 = false;
        cout << "bool: " << b1 << endl;

        cout << sizeof(1) << endl; //4
        cout << sizeof(0) << endl; //4
        cout << sizeof(true) << endl; //1
        cout << sizeof(false) << endl; //1
        
        int val;
        int result;
        cin >> val;
        result = IsPositive(val);
        if (result) cout << "Positive" << endl;
        else cout << "Negative" << endl;
        return 0;
    }
```

### bitset
- `bitset`은 이진수를 담는 구조를 의미
- `bitset<8>`은 8개의 이진수를 담는 배열을 생성하고 이를 통해 주어진 수를 이진법으로 변환

```cpp
    #include <iostream>
    #include <bitset> //bitset을 포함해야
    using namespace std; 

    int main(void)
    {
        unsigned char a, b;
        a = 10, b = 7;

        unsigned char c1, c2, c3, c4;
        c1 = a&b;
        c2 = a | b;
        c3 = a^b;
        c4 = ~a;

        cout << "a: " << bitset<8>(a) << "(" << (unsigned int)a << ")"<<endl;
        cout << "b: " << bitset<8>(b) << "(" << (unsigned int)b << ")" << endl;
        cout << "c1: " << bitset<8>(c1) << "(" << (unsigned int)c1 << ")" << endl;
        cout << "c2: " << bitset<8>(c2) << "(" << (unsigned int)c2 << ")" << endl;
        cout << "c3: " << bitset<8>(c3) << "(" << (unsigned int)c3 << ")" << endl;
        cout << "c4: " << bitset<8>(c4) << "(" << (unsigned int)c4 << ")" << endl;
        //bitset<8>(a): a를 8자리의 이진법 수로 변환
        return 0;
    }
```

### Namespace
- 일종의 가방 역할을 수행
	- namespace는 관련된 여러 코드를 나누어 담을 수 있음 (폴더 역할 수행)
	- 소스파일과 코드를 구조적으로 관리할 수 있음
- namespace를 구현부와 선언부로 분리 가능
	- 선언부는 헤더 파일에 저장
	- 구현부는 다른 파일을 통해 구현

```cpp
    #include <iostream>
    #include <Windows.h>
    //윈도우 개발에 필요한 매크로 등을 포함
    using namespace std;
    namespace BestCom //namespace 정의
    {
        void ShowDate()
        {
            SYSTEMTIME systime;
            GetLocalTime(&systime);

            cout << "ShowDate() : ";
            cout << systime.wYear << "년" << systime.wMonth << "월"
                << systime.wDay << "일" << endl;
        }

        void Method1()
        {
            cout << "BestCom Method1 called. " <<endl;
            ShowDate();
        }
        void SimpleFunc()
        {
            cout << "BestCom SimpleFunc called. " << endl;
        }
    }

    namespace ProgCom
    {
        void Method2()
        {
            cout << "ProgCom Method1 called. " << endl;
        }
        void SimpleFunc()
        {
            cout << "ProgCom SimpleFunc called. " << endl;
        }
    }

    using namespace BestCom;
    using namespace ProgCom; //해당 namespace 이름을 생략하게 해줌
    int main(void)
    {
        Method1();
        Method2();
        ProgCom::SimpleFunc();
        //SimpleFunc는 두가지 namespace에 전부 존재: 이경우 반드시 소속을 적어야함
        return 0;
    }
```

```cpp
    //헤더파일
    namespace BestCom //원형들만 저장
    {
        void ShowDate();
        void Method1();
        void SimpleFunc();
    }
    namespace ProgCom
    {
        void Method2();
        void SimpleFunc();
    }

    //구현부
    #include <iostream>
    #include <windows.h>
    #include "Namesp.h"
    using namespace std;

    namespace BestCom
    {
        void ShowDate()
        {
            SYSTEMTIME systime;
            GetLocalTime(&systime);

            cout << "ShowDate() : ";
            cout << systime.wYear << "년" << systime.wMonth << "월"
                << systime.wDay << "일" << endl;
        }

        void Method1()
        {
            cout << "BestCom Method1 called. " << endl;
            ShowDate();
        }
        void SimpleFunc()
        {
            cout << "BestCom SimpleFunc called. " << endl;
        }
    }

    namespace ProgCom
    {
        void Method2()
        {
            cout << "ProgCom Method1 called. " << endl;
        }
        void SimpleFunc()
        {
            cout << "ProgCom SimpleFunc called. " << endl;
        }
    }

    //main 부분
    #include <iostream>
    #include "Namesp.h"
    using namespace std;
    using namespace BestCom;
    using namespace ProgCom;
    int main(void)
    {
        Method1();
        Method2();
        ProgCom::SimpleFunc();
        BestCom::SimpleFunc();
        return 0;
    }
```

### 레퍼런스 변수
- call by value: 값을 함수에 전달하여 함수 업무 수행
	- swap 함수 등을 실행할 때에는 call by value방식으로는 수행 불가
	- call by reference 방식이 필요
- C방식처럼 포인터를 이용하여 swap함수의 제대로 된 구현이 가능
- 이외에도 레퍼런스 변수(참조자) 개념을 이용하여 구현 가능
	- 레퍼런스는 변수의 별명: 변수의 원래 이름 외에 또 다른 이름을 붙여주는 것
	- &를 통해 레퍼런스 변수를 정의
		- `int & ref = target;` ref: 별명, target: 원래 변수 이름
		- 반드시 선언과 동시에 초기화되어야
		- 변수에 대해서면 레퍼런스 변수 선언이 가능
	- 참조자를 리턴하는 함수를 구성하는 것 또한 가능

```cpp
    #include <iostream>
    using namespace std;

    int main(void)
    {
        int salary = 3500000;
        int &r_salary = salary; //참조변수
        cout << "salary : " << salary << endl;
        cout << "r_salary : " << r_salary << endl;
        //r_salary는 salary의 별명이므로, 둘은 같은 값을 나타냄
        r_salary += 200000;
        cout << "salary : " << salary << endl;
        cout << "r_salary : " << r_salary << endl;
        //두 변수의 값은 같이 증가(결국 같은 값을 공유하므로)
        cout << &salary << " , " << &r_salary << endl;
        //두 변수는 같은 주소를 가짐
        return 0;
    }
```
```cpp
    #include <iostream>
    using namespace std; 
    void swap1(int *x, int *y);
    void swap2(int &x, int &y);
    int main(void)
    {
        int x = 100, y = 200;
        cout << "before : " << x << ", " << y << endl;
        swap1(&x, &y); //call by pointer
        cout << "after : " << x << ", " << y << endl;

        int x2 = 500, y2 = 900;
        cout << "before : " << x2 << ", " << y2 << endl;
        swap2(x2, y2); //call by reference
        cout << "after : " << x2 << ", " << y2 << endl;
        return 0;
    }
    void swap1(int *x, int *y)
    {
        int tmp;
        tmp = *x; *x = *y; *y = tmp;
    }

    void swap2(int &x, int &y) //참조자를 인수로 활용
    {
        int tmp;
        tmp = x; x = y; y = tmp; 
        //참조자의 값이 바뀜 --> 원래 변수와 같은 주소를 공유하므로 call by reference의 결과 얻음
    }
```

```cpp
    #include <iostream>
    using namespace std; 

    int & refFuncOne(int &ref)
    {
        ref++;
        return ref;
    }

    int refFuncTwo(int &ref)
    {
        ref++;
        return ref;
    }

    int main()
    {
        int num1 = 1;
        int &num2 = refFuncOne(num1);
        num1++;
        num2++;
        cout << "num1: " << num1 << endl;
        cout << "num2: " << num2 << endl;

        num1 = 1;
        int num3 = refFuncTwo(num1); 
        //num3은 2를 가지게 됨
        num1 += 2;
        num3 += 3;

        cout << "num1: " << num1 << endl;
        cout << "num3: " << num3 << endl;

        int &num4 = num2; 
        //참조자에 대한 참조: 같은 값을 참조하게 됨
        num4++;
        cout << "num2: " << num2 << endl;
        cout << "num4: " << num4 << endl;
        return 0;
    }
```

### 구조체 함수
- 구조체에 관련된 함수에서는 일반적으로 구조체를 인수로 받아 구조체를 리턴
- Call by value를 이용한 방법으로, 메모리 낭비, 속도 등의 단점 존재
- 레퍼런스 변수를 이용하여 간단하게 함수 작성 가능

```cpp
    #include <iostream>
    using namespace std;

     //사각형 정보를 저장할 구조체
    struct Rectangle
    {
        int x, y; 
        int width, height;
    }; 

    Rectangle RectValue(Rectangle tmp) //일반적인 방법
    {
        tmp.x += 100;
        tmp.y += 100;
        tmp.width += 30;
        tmp.height += 30;
        return tmp;
    }

    void RectRef(Rectangle &tmp) //참조자를 이용한 방법
    {
        tmp.x -= 100;
        tmp.y -= 100;
        tmp.width -= 30;
        tmp.height -= 30;
    }

    int main()
    {
        Rectangle rc={10,10,10,10};
        rc= RectValue(rc);

        cout << "rc = ( " << rc.x << ", " << rc.y << ", ";
        cout << rc.width << ", " << rc.height << ")\n";

        RectRef(rc);

        cout << "rc = ( " << rc.x << ", " << rc.y << ", ";
        cout << rc.width << ", " << rc.height << ")\n";

        return 0;
    }
```

### 매소드 오버로딩
- 오버로딩(중복정의): 동일한 이름의 함수를 중복해서 정의
	- 매개변수의 개수 혹은 타입이 일치하지 않을 때 정의 가능
	- 객체지향 언어는 함수를 저장할 때 매개변수를 같이 저장하기 때문에 가능한 현상
	- 함수의 반환형은 오버로딩 조건에 포함되지 않음: 반환형만 다를 경우 오버로딩 불가

```cpp
    #include <iostream>
    using namespace std; 

    void swap(int &x, int &y)
    {
        int tmp = x; x = y; y = tmp;
    }
    void swap(char &x, char &y)
    {
        char tmp = x; x = y; y = tmp;
    }
    void swap(double &x, double &y)
    {
        double tmp = x; x = y; y = tmp;
    }

    int main()
    {
        int num1 = 100, num2 = 200;
        char c1 = 'A', c2 = 'B';
        double d1 = 10, d2 = 3.5;

        swap(num1,num2);
        swap(c1,c2);
        swap(d1,d2);

        cout << num1 << ", " << num2 << endl;
        cout << c1 << ", " << c2 << endl;
        cout << d1 << ", " << d2 << endl;
        return 0;
    }
```

### 디폴트 매개변수
- 함수의 매개변수의 기본값을 설정
- 함수를 호출할 때 인수값이 없을 경우, 디폴트값을 적용하여 함수 역할 수행
- 디폴트 매개변수는 선언부에 있어야 함: 컴파일러가 디폴트를 알고 있어야 함
- 변수 중 일부에만 디폴트를 선언할 경우, 뒤에서부터 초기값이 채워져야함
	- 앞에만 초기값이 있고 뒤에는 없을 경우, 에러 발생

```cpp
    #include <iostream>
    using namespace std; 

    int Adder(int x = 0, int y = 1) //디폴트인자
    {
        return x + y;
    }

    int main()
    {
        cout << Adder() << endl; //1 출력
        cout << Adder(5) << endl; //5 출력
        cout << Adder(3, 10) << endl; // 13 출력
        return 0;
    }
///////////////////////////////////////////////////////////////////////////
    int Adder(int x = 0, int y = 1); //디폴트인자 선언
    int main()
    {
        cout << Adder() << endl;
        cout << Adder(5) << endl;
        cout << Adder(3, 10) << endl;
        return 0;
    }

    int Adder(int x, int y)
    {
        return x + y;
    }
////////////////////////////////////////////////////////////////////////////
    int Func()
    {
        return 100;
    }
    int Func(int x = 0)
    {
        return x + 100;
    }

    int main()
    {
        cout << Func(500) << endl; //문제 없음
        cout << Func() << endl;
        //에러 발생: 위 두가지의 함수 형식과 전부 일치하게 됨
        return 0;
    }

    int BoxVolume(int x = 1, int y = 1, int z)
    // 에러 발생: x 대신 z의 초기값을 설정해야
    {
        return x*y*z;
    }

    int main()
    {
        cout << BoxVolume(3, 4, 5) << endl;
        cout << BoxVolume(3, 4) << endl;
        cout << BoxVolume(3) << endl;
    }
```

### 동적 메모리 할당
- C++에서는 C의 malloc,calloc 이외에도 new 명령을 통해 메모리를 할당 가능

```cpp
    #include <iostream>
    #include <cstring> 
    //c에서 사용하는 함수를 사용할 때에는 기존 include 파일에서 h를 없앤뒤 앞에 c를 붙임
    using namespace std; 

    int main()
    {
        char *str = new char[50];
        int *num = new int;
        int *nArray = new int[5];
        //new: 메모리를 할당하라는 뜻
        int i;
        strcpy(str, "multi campus~~");
        *num = 50;
        for (i = 0; i < 5; i++)
        {
            *(nArray + i) = i + 100;
        }
        cout << "str: "<< str << endl;
        cout << "*num: " << *num << endl;
        for (i = 0; i < 5; i++) cout << *(nArray+i) << ", ";
        cout << endl;
        //할당된 메모리 반납
        delete[] str; //배열 메모리를 회수
        delete num;
        delete[] nArray;
        //해제한 메모리는 다시 해제 불가: delete명령을 또 사용할 경우 다운됨
        //해제한 메모리와 관련된 변수들을 널포인터로 변환, 사용 못하게 함
        //널포인터로 변환하지 않아도 할당된 메모리가 없으므로 에러 발생
        str = NULL;
        num = NULL;
        nArray = NULL;
        return 0;
    }
//////////////////////////////////////////////////////////////////////////
	//구조체의 동적할당
    typedef struct _Point
    {
        int x, y;
    }Point;

    void Pnt1(Point &p1) //구조체 참조자 이용
    {
        p1.x = 100;
        p1.y = 100;
    }
    void Pnt2(Point *p2) //구조체 포인터 이용
    {
        p2->x = 200;
        p2->y = 200;
    }

    int main()
    {	
        Point *ptr1 = new Point;
        ptr1->x = 10;
        ptr1->y = 10;
        //cout<<"ptr1: " << ptr1->x << ", " << ptr1->y << endl;

        Point *ptr2 = new Point;
        ptr2->x = 20;
        ptr2->y = 20;
        //cout << "ptr2: " << ptr2->x << ", " << ptr2->y << endl;

        Pnt1(*ptr1);
        cout<<"ptr1: " << ptr1->x << ", " << ptr1->y << endl;
        Pnt2(ptr2);
        cout << "ptr2: " << ptr2->x << ", " << ptr2->y << endl;
        return 0;
    }    #include <cstring> 
    using namespace std; 

    typedef struct _Point
    {
        int x, y;
    }Point;

    void Pnt1(Point &p1)
    {
        p1.x = 100;
        p1.y = 100;
    }
    void Pnt2(Point *p2)
    {
        p2->x = 200;
        p2->y = 200;
    }

    Point & PntAdder(Point &p1, Point &p2)
    {
        Point *ptr3 = new Point;
        ptr3->x = p1.x + p2.x;
        ptr3->y = p1.y + p2.y;
        return *ptr3;
    }
    
    int main()
    {	
        Point *ptr1 = new Point;
        ptr1->x = 10;
        ptr1->y = 10;
        //cout<<"ptr1: " << ptr1->x << ", " << ptr1->y << endl;

        Point *ptr2 = new Point;
        ptr2->x = 20;
        ptr2->y = 20;
        //cout << "ptr2: " << ptr2->x << ", " << ptr2->y << endl;

        Pnt1(*ptr1);
        cout<<"ptr1: " << ptr1->x << ", " << ptr1->y << endl;
        Pnt2(ptr2);
        cout << "ptr2: " << ptr2->x << ", " << ptr2->y << endl;
        point & pre = PntAdder(*ptr1,*ptr2)
        cout << "pre: " << pre.x << ", " << pre.y << endl;

        delete ptr1; //주소 해제
        delete ptr2; //주소 해제
        delete &pre; //참조변수 pre의 해제
        return 0;
    }
```

### 문자열
- C++은 기존의 C에서 사용하던 문자열 방식과 더불어 새로운 방식을 가지고 있음
	- C 스타일
		- `strlen,strcpy,strcmp` 등의 함수를 사용하여 문자열을 처리
	- C++ 스타일
		- string 클래스를 이용하여 문자열 관리
		- 문자열 간 더하기 연산이 가능(연산자 오버로딩)
		- string 클래스의 여러 메소드들을 통해 쉽게 문자열을 관리할 수 있음

```cpp
    #include <iostream>
    #include <cstring> //C 방식의 문자열 처리 라이브러리 
    #include <string> //C++ 방식의 문자열 처리 라이브러리 
    //#include <vld.h>
    using namespace std;


    int main()
    {
        char s1[20] = "king";
        char s2[20] = "dom";
        char s3[50];
        cout << "s1: " << s1 << ", s2: " << s2 << endl;
        cout << "s1 len: " << strlen(s1) << ", s2 length: " << strlen(s2) << endl;
        strcpy(s3, s1), strcat(s3, s2);
        cout << "s3: " << s3 << endl;
        if (strcmp(s1, s2)) cout << "Equal." << endl;
        else cout << "Not Equal." << endl;

        //string은 자료형이 아닌 클래스의 일종
        //크기제한 없으며, string 을 include하여 사용
        //C와 달리 문자열 간의 더하기를 지원
        string str1 = "I like ";
        string str2 = "String Class";
        string str3 = str1 + str2; //연산자 오버로딩
        cout << str1 << ", " << str2 << ", " << str3 << endl;

        str1 += "C.";
        cout << str1 << endl;
        //일반 타입처럼 두 문자열이 같은지의 여부를 확인할 수 있음

        str1 = "king"; str2 = "king";
        if (str1 == str2) cout << "Equal." << endl;
        else cout << "Not Equal." << endl;

        int len = str1.length(); //메소드를 제공
        cout << "len: " << len << endl;

        return 0;
    }
//////////////////////////////////////////////////////////////////////////////
	int main()
    {	
        char cs[20],cs2[20]; // C 스타일
        string cpp; // C++ 스타일

        cout << "input cs? " << endl;
        cin.getline(cs,20);
        cout << "cs : " << cs << endl;
        /*
        객체는 내부에 상태정보를 저장하는 플래그를 가짐
        이 상태정보에 따라 입력을 결정하는데, 입력값이 임계를 넘을 경우 플래그가 정상적으로 작동 안함
        이 경우, 플래그를 정상적으로 바꾸어주어야 cs2를 제대로 입력받을 수 있음
        */
        if (cin.fail())
        {
            cin.clear(); //cin개체의 내부상태를 초기화, cin의 상태를 정상적으로 돌림
            cin.ignore(100, '\n'); //입력상태의 버퍼를 초기화
        }
        cout << "input cs2? " << endl;
        cin.getline(cs2, 20);
        cout << "cs2 : " << cs2 << endl << endl;

        //C++
        cout << "input cpp? " << endl;
        getline(cin,cpp);
        //string 개체는 cin의 메소드를 사용할 수 없으며, getline이라는 전용 함수를 가지고 있음
        cout << "cpp : " << cpp << endl;

        return 0;
    }
/////////////////////////////////////////////////////////////////////////////
    int main()
    {
        char name[20], comAddr[50];
        int salary;
        cout << "성명 ? ";
        cin.getline(name, 20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << "월급 ? ";
        cin >> salary;
        if (cin.fail())
        {
            cout << "월급은 숫자로" << endl;
            salary = 0;
            cin.clear();
            cin.ignore(100, '\n');
        }
        else cin.ignore(1);
        //1바이트를 제거:여기서는 버퍼에 있는 엔터키를 제거
        cout << "회사주소 ? ";
        cin.getline(comAddr, 100);
        if (cin.good() == false)
        //cin.good()==F --> cin.fail()=T
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << name << ", " << salary << ", " << comAddr << endl;
        return 0;
    }
```
