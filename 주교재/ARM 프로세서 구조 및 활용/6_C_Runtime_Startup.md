# C Runtime Startup
### C 프로그램의 메모리 영역
- 그림과 실제 메모리 위치는 다름: C에서 주소를 재배치하는 과정에서 일어난 일
- 실행 파일의 크기: 메모리 구조중 text(code + RO data) + initialized data
- BSS 영역의 초기화는 0이므로 실행파일에 포함시키지 않고 나중에 알아서 배정하면 됨
- initialized data을 실행파일에 포함하여 효율성을 높임(실행파일에 없을 경우, 프로그램 코드는 데이터와 데이터를 보관할 주소, 2가지의 정보를 더 필요로 하게 됨)
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