# ARM 어셈블리 명령어
### GPIO 핀
- GPIO(General Purpose Input & Output): 프로세서에서 원하는 논리 레벨을 출력하거나 입력 상태를 읽을 수 있는 핀
- High(1,3.3V) 또는 Low(0,0V) 등 출력
- 입력: 외부 핀 상태가 High인지 Low인지를 인식

### GPIO 핀들의 그룹 Port
- ARM은 한번 읽고 쓸 때 32비트를 한번에 처리
- 한 번의 GPIO 제어를 위하여도 32비트를 읽고 써야함
- 여러 핀들을 묶어 관리를 편하게 함
- 그룹을 Port라고 하며 임베디드 프로세서는 많은 포트로 구성되어 있음
- 같은 포트에 있는 핀들은 개별 접근 불가: 동시에 데이터를 읽거나 써야 함

### Multifunctional GPIO Pin
- S3C2440A는 289개의 핀으로 구성되며 이중 130개를 GPIO 핀으로 사용
- GPIO 핀들은 다른 주변장치의 핀들과 함께 공유하도록 설계됨
- 따라서 GPIO를 사용하기 위해서는 원하는 GPIO 용도로 핀을 사용하도록 선택해야 함(Mux를 이용하여 사용하고자 하는 용도를 선택)
	- GPIO 사용을 위한 선택
        - GPIO 입력, 출력, 다른 주변장치 중 하나 선택 (GPBCON)
        - GPIO 출력으로 사용할 경우 출력값 결정(0 or 1) (GPBDAT)
        - 칩셋에서 led 1 ~ 4는 GIPO 7 ~ 10 비트에 해당
        - 각 레지스터에서 원하는 부분의 값을 설정

![핀 공유](http://1.bp.blogspot.com/-aUNR9ro4pS8/UzO0wJs0F1I/AAAAAAAAAPo/QjjyFYsa5h0/s1600/dt_pinmux.png)

출처: http://blog.naver.com/PostView.nhn?blogId=ham9627&logNo=220565656620&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

```assembly
    @GPBCON 설정(GPIO 출력을 설정)
    ldr 	r0,=GPBCON
    ldr 	r1,=0x154000
    str 	r1,[r0]

    @GPBDAT 설정(0을 입력: LED 켜기)
    ldr 	r0,=GPBDAT
    ldr 	r1,=0x0
    str 	r1,[r0]
```

### 비트 연산의 필요성
- GPIO는 포트로 이어져 있음
- 위의 방법대로 LED를 킬 경우, LED 이외의 모든 값이 0이 됨
- 같은 포트의 다른 핀들이 다른 작업을 하고 있을 경우 문제가 생길 수 있음
- 따라서, 비트 연산을 통해 제어하고자 하는 부분만 제어할 수 있어야 함

### ARM의 데이터 처리
- ARM의 CPU들은 shift 연산을 매우 빠르게 처리할 수 있음
	- 한 번의 연산으로 여러 비트의 shift 연산이 가능: Barrel shifter
- ARM의 데이터 연산

![calculation](https://image.slidesharecdn.com/arminstructionset-160408155037/95/arm-instruction-set-11-638.jpg?cb=1460213268)

출처: https://www.slideshare.net/MathivananNatarajan/arm-instruction-set-60665439

![barrel shifter](https://image.slidesharecdn.com/arminstructionset-090617055544-phpapp01/95/arm-fundamentals-10-728.jpg?cb=1245218187)

출처: https://www.slideshare.net/guest56d1b781/arm-fundamentals

### OP2
- ALU 그림에서 오른 쪽에 있는 것을 OP2라고 부름
- OP2에 놓을 수 있는 것
    1. 레지스터: `mov pc,r12`
    2. 상수(`#value`): `mov r0,#10`
    3. 레지스터 + shift(value)
        - `mov pc,r12,lsl #2`: r12 내용을 2만큼 왼쪽으로 시프트하여 pc로 이동(logical)
        - `mov r0,r1,ror #3`: r1 내용을 3만큼 오른쪽으로 로테이트하여 r0으로 이동
        - 로테이트: 시프트와 달리 끝자리가 맨 왼쪽(or 오른쪽)으로 이동
        - 계산 후 r12,r1의 값은 그대로
    4. 레지스터 + shift(register)
        - `mov pc,r12,asr r1`: r12내용을 r1만큼 시프트하여 pc로 이동(arithmetic)
        - `mov r0,r1,lsr r3`: r1내용을 r3만큼 왼쪽으로 시프트하여 r0으로 이동(logical)



###  상수 표현
- 상수는 # 또는 =를 반드시 사용해야
- \#상수: 32비트 명령내에 상수 값을 함께 저장함을 의미
	- `mov R0,#10`: ARM은 명령을 32비트로 처리
	- \#value는 데이터를 명령어에 같이 넣어 처리한다는 의미
	- \#상수는 데이터 명령에 들어갈 때 12비트로 처리: (ROR) 4 + \#value 8비트
	- rotation은 총 rotation의 절반값을 넣음: 따라서 2의 배수로 rotation되어야만 가능
		- 이유: 좀 더 넓은 범위의 숫자를 커버할 수 있도록
		- 2의 배수로 되지 않을 경우, 최대 15번의 rotation밖에 불가능
	- 더 많은 값을 넣을 수 없어 범위 제한 발생: 8비트 범위 내에서 표현 가능해야
	- 예시
		- `mov r0,#0x7f00`: 가능
			- 유효숫자는 7f로 8비트 표현
			- 7f를 왼쪽으로 8번 shift
			- rotate 개념으로는 오른쪽으로 24번 rotate해야 하며, 따라서 ROR 부분은 12
			- 따라서 코드표현으로는 `0xc7f`
		- `mov r0,#0x30c0`: 가능
			- 유효숫자(1이 있는)는 8비트로 표현 가능
			- 오른쪽으로 26번 rotate하면 되며, 따라서 ROR 부분은 13
			- 코드표현으로는 `0xdc3`

![# value](https://github.com/vicheck88/C-practice/blob/master/image/arm%20instruction%20set%20encoding.PNG?raw=true)

출처: ARM architecture manual A3-1, instruction set encoding

- = 상수: 범위 제한 없는 32비트 값으로 표현 가능
	- LDR 명령에서만 사용 가능
	- 실제 상수값은 메모리에 존재하며 레지스터 참조로 변환됨
	- 명령어 안에 포함할 수 없으며 따라서 다른 곳에 보관
	- 가짜(pseudo) 명령으로 볼 수 있으며, 어셈블러에 의해 다른 명령으로 변환

![=value](https://image.slidesharecdn.com/arm1-140401220608-phpapp02/95/the-arm-architecture-arm-arm-architecture-27-638.jpg?cb=1396390153)

출처: https://www.slideshare.net/sreea4/arm-1

### \#value와 MVN 명령어
- = 상수를 사용할 때 컴파일러는 ldr, mov로 자동 전환
	- \#value로 표현이 가능할 경우, 컴파일러가 mov 명령으로 변경
		- `ldr r1,=0x1000`는 `mov r1,#0x1000`으로 자동변경
	- 하지만 반대(\# -> = value)는 성립하지 않음
		- 메모리 사용을 줄일 수 있는 상황(ldr -> mov)에서는 컴파일러가 변경 가능
		- 메모리 사용이 늘어나야 할 경우 (mov -> ldr) 컴파일러가 변경할 수 없음

- MVN: MOV와 유사하나 op2를 비트 반전하여 저장
	- `mvn Rd,operand2 == Rd := ~operand2`: Mov not 명령
	- 어느 값의 1의 보수를 취할 때 쓰임
	- `mov r0,#0xffff03ff` -> `mvn r0,#0xfc00`으로 저장하는 것이 가능
- 앞의 논의와 더불어 어셈블러는 =상수를 ldr,mov,mvn 3가지 명령으로 자동 전환

```assembly
mov r0,#0xffff03ff -> mvn r0,#0xfc00
ldr r0,=-100 -> mvn r0,#0x63
```

### LSL, LSR shift
- OP2에 사용되는 shift에는 5가지가 있음: `ASR, LSL, LSR, ROR, RRX`
- shift는 OP2의 barrel shifter에서 이루어지며 추가적인 사이클이 발생하지 않음
- 따라서 다른 명령의 op2에 사용되어 매우 효율적으로 사용할 수 있음
- LSR, LSL은 unsigned 데이터의 곱하기, 나누기 용도로 사용됨
- 최후에 밀려난 비트가 상태레지스터의 C(Carry) flag에 저장됨

### C의 shift 연산과 ASR
- C에서 signed data의 shift는 컴파일러에 의존하고 표준적인 합의는 없음
- 기본적으로 signed data의 경우 산술적으로 shifting이 이루어짐(ASR)
- 최후에 밀려난 비트는 상태레지스터 C flag에 저장되며, MSB의 값은 그대로 유지
	- 이를 통해 부호를 유지
- ASL은 LSL과 같은 기능을 제공하므로 따로 취급하지 않음

### ROR, RRX shift
- ROR은 우측 rotate만 있으나 비트수를 조절, ROL 기능 수행 가능
- 이경우에도 마지막으로 밀려난 비트는 C flag에 저장
- RRX는 C flag 값을 포함하여 rotation 수행
- RRX는 한번에 1비트만 지정 가능

![shift](https://image.slidesharecdn.com/arminstructionset-160408155037/95/arm-instruction-set-7-638.jpg?cb=1460213268)

출처: https://www.slideshare.net/MathivananNatarajan/arm-instruction-set-60665439

### 비트 처리 명령어
- 비트 처리 명령어는 OR, AND, XOR 연산과 Bit clear 연산이 존재
- XOR: 0은 같은 값을 출력하며, 1은 반전시켜 출력
- AND: mask 연산 수행(출력하고 싶은 부분은 1, 아닌 부분은 0으로)
- BIC는 AND와 반대로 수행(출력하고 싶은 부분은 0으로, 아닌 부분은 1로)
- mov와 마찬가지로 \#상수는 제한 범위를 가지고 있음
- 하지만, ldr, mov, mvn때와 마찬가지로 컴파일러가 자동으로 바꿔줄 수 있음
```assembly
    orr r0,r0,#0xffffff00 @오류
    and r0,r0,#0xffffff00 @ -> bic r0,r0,#0xff: 가능
```

|명령 기본 형식|`(op) Rd,Rs,OP2 -> Rd := Rs (op) OP2`|
|---|:---|
|ORR|원하는 비트만 1로<br/>`ORR r0,r0,#0x1f`,`ORR r0,r1,r2,lsl #2`|
|EOR|원하는 비트만 반전(두 수의 비트가 얼마나 다른 지 볼 때 사용)<br/>`EOR r0,r0,#0x1f`,`ERR r0,r1,r2,lsl #2`|
|AND|원하는 비트만 0으로(0인 부분을 0으로)<br/>`AND r0,r0,#0x1f`,`AND r0,r1,r2,lsl #2`|
|BIC|원하는 비트만 0으로(1인 부분을 0으로: AND보다 편리)<br/>`BIC r0,r0,#0x1f`,`BIC r0,r1,r2,lsl #2`|

### 비트 연산에 의한 메모리 변경
- 메모리 변경의 패턴
1. 원하는 번지의 값을 레지스터에 읽어옴(Read)
2. 레지스터의 이름을 비트 연산으로 수정(Modify)
3. 수정된 값을 다시 원래 주소로 보냄(Write)

```assembly
    @ GPBCON
    @Read
    ldr 	r0,=GPBCON
    ldr 	r1,[r0]
    @Modify
    bic 	r1,r1,#0x3fc000
    orr 	r1,r1,#0x154000
    @Write
    str 	r1,[r0]
```

### 어셈블러 기본 Pseudo 연산자
- Pseudo 연산자는 ARM이 아닌 어셈블리에서 제공하는 연산자
- 어셈블러에 의해 사전에 계산되며 이를 이용할 경우 가독성이 좋아짐

|종류|연산|
|---|---|
|곱셈계열|*,/,%,:MOD:|
|비트연산|&#124;, &, ^, !, :AND:, :OR:, :EOR:, :NOT:|
|비트 shift|<<, >>, :ROL:, :ROR:, :SHL:, :SHR:|
|덧셈계열|+,-|
|관계연산|==, <>, !=, <, >, >=, <=|
|논리연산|&&, &#124;&#124;|

```assembly
    @ GPBCON
    @Read
    ldr		r0,=GPBCON
    ldr 	r1,[r0]
    @Modify
    bic 	r1,r1,#(0xff<<14) @shift연산: 훨씬 편해짐
    orr 	r1,r1,#(0x55<<14) @shift연산: 훨씬 편해짐
    @Write
    str 	r1,[r0]
```

### 분기 명령어
- 프로그램의 위치를 변경하는 명령으로 B와 BL이 있음
- B: 분기, BL: 서브루틴 호출 명령
- B,BL은 분기 대상 주소로 register를 사용할 수 없음: `B R0`같은 명령 불가

|분기|설명|
|---|---|
|B|`B label`-> branch|
||분기 가능 위치: 현재 위치에서 위아래로 32MB<br/>label은 상대위치로 변환되어 명령어가 만들어 짐<br/>nb,nf를 이용하여 Local Label 분기도 가능|
|사용 예|`B add`: Global Label(외부 파일은 .extern 필요)<br/>`B 3f`: Local Label<br/>`B .`: 무한루프|

![control flow](https://image.slidesharecdn.com/armisa-170326092339/95/arm-architecture-instruction-set-44-638.jpg?cb=1490520227)

출처: https://www.slideshare.net/dwightsabio/arm-architecture-instruction-set

### Label
- 분기 위치를 결정하는 Label에는 Global과 Local이 있음
- Global: 다른 파일에서도 접근할 수 있는 label(extern 생각)
- label은 함수, 변수 이름처럼 사용 가능
	- `.global directive`: 다른 파일에서의 참조를 허용(C언어의 extern 개념)
	- `.extern directive`: 다른 파일의 레이블 참조
	- B(Branch)는 원위치로 돌아오지 않음: 리턴되지 않음
	- 동일한 이름이 반복되지 않음
	- label의 위치는 상관 없음

```assembly
	.global label1 @ global label 선언
	label1:

	.extern label1 @ 다른 파일의 global label 사용
	label1:
```

- Local Label: 국소적인 부분에서만 사용할 경우(예: for문) 굳이 이름을 붙일 필요가 없음
- 이경우 local label을 사용
	- 숫자를 통해 이름을 만듦
	- 중복 숫자가 가능
	- 어느 label로 분기하는 지 결정하기 위해 현재 코드를 위치로 어느 방향에 있는지를 명시해야: b(backward), f(forward)를 통해 앞뒤를 결정하며, 가장 가까운 label로 이동
	- local label에 `.global, .extern`명령을 만드는 것은 불가능
	- 어셈블러에 따라 규칙이 다를 수 있음

```assembly
	1: mov r1,#200
	1: mov r0,#100
	b 1b @후방에서 가장 가까운 1로 분기

    b 2f @전방에서 가장 가까운 2로 분기
	2: sub r0,r0,r1
	2: str r0,[r1]
```

### 상태 레지스터와 flag
- CPSR: Current Program Status Register

![CPSR](https://image.slidesharecdn.com/arm-cortex-m3byjoebungoarm-150928184843-lva1-app6892/95/arm-cortexm3-byjoebungoarm-21-638.jpg?cb=1443466212)

출처: https://www.slideshare.net/ahireprashant/arm-cortexm3-byjoebungoarm

- N: 연산결과가 음수
- Z: 연산결과가 0
- C: Carry 발생여부, V: Overflow 발생여부
    - Overflow와 Carry
        - Carry는 최상위 비트와 그 전 비트에서의 값 넘김 여부가 같을 경우
        - Overflow는 최상위 비트와 그 전 비트에서의 값 넘김 여부가 다를 경우
        - Unsigned 상황에서는 Carry만 살펴보면 됨(V flag는 상관 없음)
        - 기본적으로 어셈블러는 모든 수를 signed로 살펴봄
- Q: saturation 관리
	- Overflow 등으로 이상한 결과가 나올 경우(최대치, 최소치에 있을 경우) 값의 결과가 더 넘어가지 않도록 해주는 역할 수행
	- 최대치에 있을 경우를 saturation 상황이라고 부름

### 비교 연산 명령어
- 분기를 위해 값들을 비교하는 비교 연산 명령어 사용
- 상태 플래그 값들을 변경
	- `CMP,CMN`: N,Z,C,V flag (`add,sub`) 사용
	- `TST,TEQ`: N,Z flag (`and, eor`) 사용
	- OP2 계산(`R1 lsl #2` 등) 시 C flag 업데이트 가능
- 연산의 결과는 저장되지 않으며 flag 상태에만 영향을 줌

![comparison](https://image.slidesharecdn.com/armisa-170326092339/95/arm-architecture-instruction-set-36-638.jpg?cb=1490520227)

출처: https://www.slideshare.net/dwightsabio/arm-architecture-instruction-set

```assembly
	cmp r0,#5 @r0-5의 상태를 flag에 저장(r0==5일 경우 Z=1)
    cmn r0,#5 @r0+5의 상태를 flag에 저장(r0==-5일 경우 Z=1)

    tst r0,#1<<7 @r0 & 1<<7의 상태를 flag에 저장
    teq r0,#1<<7 @r0 ^ 1<<7의 상태를 flag에 저장
```

### 상태 플래그와 조건
- N,Z,C,V 상태를 통해 연산의 현재 결과를 정리할 수 있음

![condition flag](https://github.com/vicheck88/C-practice/blob/master/image/condition%20flag.PNG?raw=true)

출처: ARM architecture reference manual A3-6 Table 3-1, condition codes

- 명령 뒤에 코드를 붙여 조건을 걸 수 있음

```assembly
	CMP r0,r1
	MOVEQ r1,#2 @상태코드가 EQ일 경우 명령 수행
```

### 분기 명령과 파이프라인
- ARM7: 3단, ARM9: 5단, ARM10:6단의 파이프라인을 가지고 있으나 기본은 3단
- 파이프라인이 사용될 경우 분기 명령 수행시 손실 발생
	- 명령어는 기본적으로 Fetch,Decode,Execute의 phase로 동작
	- 파이프라인을 통해 한 사이클의 3개 명령을 한 phase씩 수행
	- 분기 발생시 미리 fetch해둔 명령들은 버려짐: 속도에 손해 발생

```assembly
    BEQ 3f @이 상황에서 밑에 fetch한 명령어들은 전부 사라지게 됨
    MOV R0,R1
    LDR R0,[R2]
```

### 조건부 명령 실행
- 조건이 참이면 실행, 거짓이면 넘기는 명령
- 파이프라인의 분기를 줄이기 위해 사용
	- 잦은 분기 없이도 조건에 따른 명령 실행 가능: 파이프라인의 효율 증가

```assembly
	@r0>r1 -> r2=-2, r0<r1 -> r2=0, r0==r1 -> r2=1 구할 때
        cmp r0,r1
        bgt large
        blt small
        mov r2,#1
        b finish
	small:
    	mov r2,#0
    large:
    	mov r2,#-2
    finish:
	@기존 방법 이용: 잦은 분기 발생
```
```assembly
    cmp r0,r1
    movgt r2,#-2
    movlt r2,#0
    moveq r2,#1
    @조건부 실행 이용: 분기 상황이 많이 발생하지 않음
    @조건은 flag 상태로 판단
    @위 방법에 비해 좀 더 빠르게 같은 문장 실행 가능: 파이프라인에 이미 들어있음
```

### 산술 명령어
- OP2는 항상 뒤에 와야 함: `sub r1,#1,r0`: 불가능

|계산|형식|
|---|---|
|ADD|`ADD rd,rs,op2` `rd := rs + op2`|
|ADC|`ADC rd,rs,op2` `rd := rs + op2 + carry`|
|SUB|`SUB rd,rs,op2` `rd := rs - op2`|
|SBC|`SBC rd,rs,op2` `rd := rs - op2 - !carry`|
|RSB|`RSB rd,rs,op2` `rd := op2 - rs`|
|RSC|`RSC rd,rs,op2` `rd := op2 - rs - !carry`|

### ADDS,SUBS: 64비트 계산에서
- 64비트 덧셈, 뺄셈: `[r5:r4]=[r3:r2]+-[r1:r0]`
- 다음 코드의 문제
    ```assembly
        ADD r4,r2,r0
        ADC r5,r3,r1 @앞의 수에서 발생한 값을 포함

        SUB r4,r2,r0
        SBC r5,r3,r1 @앞의 계산에서 발생한 값을 포함
    ```
    - `ADD`함수는 캐리가 발생하여도 carry flag에 캐리값을 반영하지 않음
    - `SUB`함수 역시 같음
    - 상태 flag는 flag에 상태를 반영하라는 명령이 있을 때만 값을 입력
    - flag 반영 명령은 기존 명령의 뒤에 S를 붙임으로써 내릴 수 있음(S-suffix)
    - 따라서 `ADD` 대신 `ADDS`, `SUB` 대신 `SUBS`를 사용해야 함
- 비교 명령 외의 명령에서 CPSR 갱신을 하려면 S-suffix를 반드시 사용해야 함

### ADDS, SUBS: 일정 횟수 반복 프로그램
- 특정 기능을 10회 반복하는 경우 두 가지 방법을 생각할 수 있음
    ```assembly
        @for(i=0;i<10;i++)
        mov r0,#0
     1:[do something]
        add r0,r0,#1
        cmp r0,#10
        blt 1b
    ```
    ```assembly
        @for(i=10;i>0;i--)
        mov r0,#0
     1:[do something]
        sub r0,r0,#1
        cmp r0,#0
        bgt 1b
	```
- 두번째 방법에서 SUB 대신 SUBS를 사용할 경우
	- S-suffix로 인해 자동으로 flag 갱신
	- 따라서 CMP 명령을 사용할 필요가 없어짐: 효율 증가

### BL(Branch and Link): 서브루틴 호출
- BL은 서브루틴 또는 함수 호출
- `BL label`로 호출: label은 서브루틴의 상대주소값
- 복귀할 주소(다음 명령 주소)값을 R14에 저장

```assembly
	BL add @BLEQ add
	BL r0  @불가능: BL은 분기 주소로 레지스터를 사용 못함
```

### ARM의 특수용도 레지스터
- R13 ~ R15는 특수목적 레지스터

|레지스터|용도|
|---|---|
|SP/R13<br/>stack pointer|스택의 주소 저장(일반 레지스터로 사용해도 무방)|
|LR/R14<br/>Link register|함수 호출 시 리턴 주소를 저장(일반 레지스터로 사용해도 무방)|
|PC/R15<br/>Program Counter|프로그램 수행 시 읽어오는 명령의 주소 저장|
|CPSR<br/>Current Program Status Register|연산결과, IRQ, FIQ금지, 동작모드 등을 나타냄|

### 서브루틴 호출, 복귀
- 서브루틴 호출, 복귀 과정은 다음과 같음

|상황|설명|
|---|---|
|서브루틴 호출|`BL add`: `add subroutine` 호출 후 복귀|
||복귀할 주소를 LR에 저장<br/>서브루틴의 주소를 PC에 대입|
|서브루틴 복귀|`MOV PC,LR` 또는 `MOV R15,R14`|
||return 명령 없이 PC 갱신으로 복귀<br/>PC에 돌아올 주소값(LR에 저장되 값)을 PC에 대입|

- C언어 함수와의 차이
	- C언어에는 지역변수와 전역변수의 차이가 존재
	- 어셈블리에서는 레지스터를 사용: 레지스터는 전역이므로 바뀐 값이 서브루틴 밖에서도 작용함
	- 서브루틴을 작성할 때는 변수에 대해 좀 더 고민해야

### 어셈블러의 Symbal(상수) 생성
- `.equiv DELAY,1`: Symbol을 만들고 1로 함(상수). 값 변경 불가능
- `.equ DELAY,1`: 값 변경 가능
- `.set DELAY,2`: 파일 중간에 Symbol의 값을 바꿈(equ로 정의된 경우)

### 데이터 생성 Directive
- 메모리에 원하는 크기의 상수 데이터를 삽입하는 directive
- `.word 0x100`: 메모리에 0x100이 4B 크기로 생성되어 들어감
- `tbl1: .char 'A'`: char 'A'가 저장된 메모리 주소가 심볼 tbl1이 됨
- `.byte, .hword, .word(4B), .short, .char, .string, .double`가 있으며, 메모리의 주소에 해당 값에 해당하는 정보를 삽입

```assembly
		.word 0x100
		.word 10,20,30,40 @연속된 주소에 .word타입 정보 삽입
	tbl1:.char 'A' @'A'의 주소를 심볼로 관리
	tbl2:.string 'Hello' @연속된 6바이트의 주소에 삽입
```

### LDR, STR Post,Pre-Indexing
- post indexing: C의 *p++,*p--와 유사한 기능
- pre indexing: post indexing의 반대 기능
- `ldr r0,[r1],#4`: r1주소의 값을 r0에 넣고 r1의 값을 4 증가(post indexing)
- `ldr r0,[r1],r3,lsl #2`: r1주소의 값을 r0에 넣고 r1의 값을 r3를 shift한 값만큼 더함
- `ldr r0,[r1,#4]`: r1주소를 4 증가시킨 뒤 그곳에 r0를 넣음(pre indexing)
	- r1의 값은 그대로
	- !suffix를 이용하면 r1의 값을 변화시킬 수 있음
	- `ldr r0,[r1,#4]!`
	
![pre,post indexing](https://image.slidesharecdn.com/aaetc3v00instructionsets-150604164355-lva1-app6892/95/arm-aae-intrustion-sets-14-638.jpg?cb=1433436270)

출처: https://www.slideshare.net/AnhDungNGUYEN3/arm-aae-intrustion-set

