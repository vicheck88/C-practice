# C Runtime Startup
### C 프로그램의 메모리 영역
- 그림과 실제 메모리 위치는 다름: C에서 주소를 재배치하는 과정에서 일어난 일
- 실행 파일의 크기: 메모리 구조중 text(code + RO data) + initialized data
- BSS 영역의 초기화는 0이므로 실행파일에 포함시키지 않고 나중에 알아서 배정하면 됨
- initialized data을 실행파일에 포함하여 효율성을 높임(실행파일에 없을 경우 더 많은 코드가 필요하게 됨)
- initialized data, bss: 읽고 쓰기가 전부 가능해야 하므로 RAM에 저장

![memory for c](http://cs-fundamentals.com/assets/images/code-data-segments.png)

출처: http://cs-fundamentals.com/c-programming/memory-layout-of-c-program-code-data-segments.php

### C 프로그램의 수행 절차
1. 실행 시 OS에 의해 메모리로 로딩
2. 메모리, 스택 설정
3. main() 함수 호출
4. 프로그램 실행(stack, heap 사용)
- 1번은 OS, 4번은 프로그램의 역할
- 2,3번 작업 역시 프로그램이 스스로 수행해야: C Runtime Startup 코드

### C Runtime Startup
- CRT startup: C로 작성된 프로그램이 구동될 수 있는 환경을 구축해 주는 코드
	- main()함수가 있을때 링커는 startup을 코드에 추가, 프로그램이 실행될 수 있도록 조치
	- startup 코드가 있어야 C 구동 가능

### Hosted vs Free standing 환경
- C 표준에서 정의하는 사용자 프로그램이 구동되는 두 가지의 환경
	- Hosted: C 표준에서 지정한 규칙에 의거 사용자 프로그램이 구동
	- Free Standing: 프로그래머가 임의의 방식으로 구동
	- 임베디드의 경우, semi hosting 환경
- Hosted
	- main 함수부터 설계
	- `int main(void), int main(int argc, char * argv[])`
	- C 표준 라이브러리 전부 지원
	- printf()의 인쇄: 시스템에 따른 라이브러리 포팅 필요
- Free standing
	- 시작함수는 상관없음(보통 main이 아님)
	- 표준 라이브러리 지원여부 상관없음. 필요할 떄 유사한 함수 직접 제작
- OS가 있는 경우 Hosted 환경 사용
- 임베디드는 필요시 일부는 컴파일러에 의존, 일부는 직접 설계

### XIP와 RAM 로딩 실행
- 임베디드에서의 C runtime startup
	- 컴파일러에게 맡김
	- 직접 설계
- 임베디드에서 응용 프로그램 구동은 크게 다음 두가지로 구분됨
- XIP: eXecute In pLace
	- 비휘발성 코드메모리(ROM, nor flash)에 프로그램 기록
	- 실행 시 바로 그 자리(Reset vector)에서 프로그램 실행
		- ROM, NOR flash의 경우 cpu가 직접 접근, fetch할 수 있음
	- 대부분 기존 임베디드 시스템에 적용되던 방식
- RAM loading
	- NAND flash의 경우 cpu에 직접 연결이 되지 않음
	- 때문에 실행 전 RAM으로 파일을 옮겨 실행
	- 실행 시 RAM에 있는 상태로 실행
- 최근은 대부분 RAM loading 방식을 사용
	- 최근 실행 파일이 커지는 반면 ROM, NOR flash의 용량은 적은 편
	- 때문에 실행 파일은 NAND Flash에 저장
	- RAM에 들어가기에도 파일이 큰 편: 파일을 압축하여 RAM에 이동한 뒤 압축 해제

![XIP vs NOT XIP](https://static.designandreuse.com/news_img17/20170424_2.jpg)

출처: https://www.design-reuse.com/articles/41861/execute-in-place-xip-nor-flash-spi-protocol.html

### 메모리 레이아웃: XIP vs RAM Loading
- RO code의 시작을 RO Base, RO Data의 끝은 RO Limit이라 부름
- 전역변수부분의 시작을 RW Base, 끝을 RW Limit이라 부름
- 비슷하게 bss영역은 ZI이라고 부름
- XIP 구조
	- 실행 프로그램은 ROM에 저장되어 있음
	- 전역변수영역을 RAM에 저장해야 함(읽고 쓰기가 자유로워야)
	- 그 외의 나머지 작업들은 RAM에 순서대로 할당
	- RO Limit과 RW Base의 주소가 다름

- RAM Loading
	- 실행 프로그램을 RAM으로 복사
	- 전역변수영역은 복사할 필요가 없으므로 바로 BSS를 비롯한 나머지 부분 할당
	- RO Limit과 RW Base의 주소가 같음
	- 따라서 컴파일러에게 RO base 주소만 알려주면 됨

![XIP memory](http://www.keil.com/support/man/docs/armlink/armlink_pge1462449638742.png)

XIP
출처: http://www.keil.com/support/man/docs/armlink/armlink_pge1362065902090.htm

![RAM loading memory](http://www.keil.com/support/man/docs/armlink/armlink_pge1462449626328.png)
RAM Loading
출처: http://www.keil.com/support/man/docs/armlink/armlink_pge1362065904825.htm

### C Runtime Startup이 하는 일
- XIP일 경우, 컴파일러에게 RO/RW base를 전부 알려주어야 함
	- 초기화 정보를 램으로 복사
- RAM Loading일 경우, 컴파일러에게 RO base를 알려주어야 함
- 컴파일러로부터 RO limit, ZI base/limit의 정보를 받아야 함(사이의 영역을 0으로 초기화)
- 다음으로, 스택을 준비하는 과정 필요
- 마지막으로 C언어 프로그램으로 분기

### XIP vs RAM Loaing
- RAM Loading이 필요한 경우
	- 테스트 & 디버깅: 읽고 쓰는 작업이 편해야함(XIP는 쓰기 작업이 힘듦)
	- 고속 프로그램 실행: RAM은 빠름
	- ROM에 있는 압축된 실행파일 실행: 압축을 RAM에 풀게 됨
	- Non-Bootable 메모리(HDD,NAND,SD 등)에 있는 실행파일 실행
	- 여러 응용 프로그램의 선택적 실행
- XIP와 vs RAM Loading
	- XIP: 빠른 부팅시간, 느린 실행 시간
		- 프로그램을 적재하고 실행할 필요 없음
	- RAM Loading: 빠른 실행 시간, 느린 부팅 시간
		- 프로그램을 적재하고 실행해야 
- Link Script File: 원하는 타입(XIP, RAM Loading)에 맞춰 컴파일에게 정보를 알려주는 파일
- Make file: GCC는 Make file을 생성, 컴파일러로 실행파일을 생성

### SP 레지스터와 스택 설정
- R13(SP): stack-base 저장
- 스택은 높은주소 -> 낮은 주소 순
- Stack limit는 프로그래머가 관리

### C 함수 분기
- CRT0 코드가 구동되고 스택이 설정되면 main으로 분기

```assembly
	.extern Main
	bl Main @서브루틴으로 메인 호출
	b . @무한루프로 프로그램 종료
```

### Freestanding 방식의 문제점
- 표준 라이브러리를 사용하기 위한 준비가 되어있지 않음
- 설정이 제대로 되어있지 않을 경우 제대로 된 결과를 내지 못함

### Hosted 방식의 CRT-Startup
- Hosted 환경에서 프로그래머는 main부터 설계: C로만 작성
- Hosted 환경의 CRT-startup은 기존의 작업 이외에도 힙 생성, 라이브러리 함수 초기화의 작업을 수행
- 라이브러리 작업, 동적 할당 등의 작업 수행에 차질 생김

### Heap 설치와 Locale 지정
- heap, locale 설정을 직접 수행해야
- Locale 설정
	- 국가별로 다른 기호(화폐, 천단위 기호 등)을 지정하는 설정
	- setlocale 함수를 실행하여 국가 지정: GCC는 한 종류만 지원
- Heap 설정
	- 원하는 Heap의 영역을 지정하고 메모리 할당 함수를 설계
	- `_sbrk`: `malloc` 등의 함수가 메모리 할당을 위해 call back으로 호출

### 컴파일러의 최적화와 volatile
- 컴파일러는 자신의 판단을 통해 코드를 최적화하는 경우가 있음
- 이 경우 코더가 의도한 결과를 내지 않을 수 있음
- volatile을 통해 컴파일러가 최적화를 하지 않도록 할 수 있음
- volatile의 사용 예
	- 하드웨어 레지스터 제어
	- 고정된 메모리에 정보를 저장하고 주고받을 때(IPC)

```cpp
	volatile int i;

	#define GPBCON (*(volatile unsigned int *)0x56000010)
	#define GPBDAT (*(volatile unsigned int *)0x56000014)

	GPBCON = (GPBCON & ~0xFF<<14) | (0x55<<14);
	GPBDAT = (GPBDAT & ~0xF<<7) | (0xA<<7);

	for(;;)
	{
		GPBDAT ^= 0xf<<7;
		for(i=0; i<0x100000; i++);
		//volatile 선언이 되어있지 않을 경우 최적화되어 진행 X
	}
```

### NAND Booting
- NAND Flash는 기본적으로 부팅용으로 사용할 수 없음
- NAND Booting을 위해서는 하드웨어, 소프트웨어적으로 특별한 기능이 필요
- S3C2440 프로세서는 하드웨어적으로 NAND 부팅 지원
- 부팅 과정
	1. NAND Boot모드로 선택되고 리셋될 경우 ARM Core의 리셋을 잠시 중지
	2. NAND Controller가 NAND의 초기 4KB를 내부 램으로 이동, 적재
	3. 내부 램을 하드웨어적으로 ARM Core의 리셋벡터가 되도록 함
	4. 이후 ARM Core 리셋하여 램의 코드를 실행하도록 함
- 4KB의 역할
	- 부트로더라 불리는 프로그램을 넣음
	- 부트로더는 주변장치, 램, 클락 등을 초기화
	- 이후 응용프로그램을 램에 올리는 초기작업을 수행, 프로그램이 램에 적재되도록 함
	- 마지막으로 프로그램 실행

