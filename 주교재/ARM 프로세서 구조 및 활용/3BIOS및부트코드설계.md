# BIOS 및 부트코드 설계
### 실습 시스템
- SoC: 삼성 S3C2440A
- 코어: ARM920T

### 시스템 초기 설정 요소
- 사용 가능하도록 최소한의 설정 작업 필요
- WDT(Watchdog Timer)
	- 시스템 고장 방지를 위한 시스템 감시 타이머
	- 전원 인가시 Enable 상태로, 주기적으로 시스템을 리셋
	- 따라서 주기적으로 카운터를 되돌려야 하며, 그렇지 않을 경우 문제점으로 인식하고 재부팅
	- 사용준비가 되기 전까지 Disable 상태로 변환해야 함
- PLL
	- PLL은 CPU의 클락을 높이는 역할 수행
	- 설정하지 않을 경우 낮은 주파수로 CPU 동작
	- 활성화를 통해 CPU의 주파수를 높여야(FLCK)
	- CPU 이외에도 여러 버스에 사용하기 위해 분주작업 또한 필요(HCLK,PLCK)
	- FCLK,HCLK,PCLK의 비율은 1:3:6 또는 1:4:8로 설정
- Interrupt
	- 프로그램을 실행하는 도중 예기치 못한 상황이 발생하였을 때 발생한 상황을 먼저 처리한 뒤 원래 작업으로 복귀하는 것
	- 초기화 작업중에는 아직 인터럽트 서비스 루틴이 생성되어있지 않음
	- 인터럽트 컨트롤러에서 모든 인터럽트를 불가 상태로 만듦

### ARM CPU의 기본구성
- ARM 프로세서는 R0 ~ R15 레지스터와 CPSR 레지스터를 가지고 있음
- RISC 계열 CPU들은 레지스터를 많이 두는 편
- R0 ~ R14: 범용 레지스터로, 자유롭게 사용 가능
	- R13,14 레지스터의 경우, 스택포인터, 함수 리턴값 저장용으로 사용되기도
	- 따라서, R0 ~ R12의 경우만이 지정한 범용 레지스터
- R15: 특수목적용 (프로그램 카운터)
- CPSR: Current Program Status Register
	- 현재 CPU의 상태 저장

![ARM Register](http://infocenter.arm.com/help/topic/com.arm.doc.kui0049a/armregs.png)

출처: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.kui0049a/gs_ma_arm.htm

### 레지스터
- 하드웨어를 제어하기 위해서는 수많은 레지스터를 사용해야 함
	- 레지스터: 하드웨어가 자기만 사용하기 위해 특별 용도로 예약한 메모리
	- CPU 안 레지스터는 주소 없이 이름만 존재함
- Port mapped IO
	- CPU와 하드웨어가 별도의 정보를 주고 받기 위해 CPU와 하드웨어 사이에 직접 포트를 연결
- Memory mapped IO
    - 하드웨어 제어를 위한 주변장치들은 CPU 메모리 버스에 연결됨
    - 각각의 주변장치들도 자신만의 레지스터가 있지만(TCON 등), CPU 입장에서는 범용 메모리에 불과
    - 때문에, 모든 주변장치의 레지스터에는 주소가 배정되어있음
	- 메모리 액세스를 통해 하드웨어의 레지스터를 제어하고, 이를 통해 결국 하드웨어를 제어

![memory mapped io](https://i.stack.imgur.com/rBbh1.png)
출처: https://superuser.com/questions/703695/difference-between-port-mapped-and-memory-mapped-access

### Load, Store 개념
- 레지스터를 제어하기 위해서는 어셈블리를 다루어야 함
- MOV 명령
	- ARM에서 연산은 레지스터 사이에서만 일어남
	- MOV는 레지스터간 데이터 복사에 사용되는 명령(`MOV R0,R1`: R1 내용을 R0에 복사)
- 주변장치 제어
	- 연산이 레지스터 사이에서만 일어나므로, 외부 메모리의 자료를 레지스터로 가지고 올 수 있어야 함
	- MOV 명령은 레지스터 사이에서만 가능한 명령이므로, 사용 불가
	- 이 경우, Load, Store 명령 사용
- Load, Store
	- 레지스터와 외부 메모리 사이에 데이터를 이동할 때 사용
	- 메모리 -> 레지스터: LDR(Load to Register)
	- 레지스터 -> 메모리: STR(Store to Memory)

### 상수 값 Load

|LDR 명령 형식|`ldr Rn, =value`|
|:---:|:---|
||주어진 값을 Rn으로 복사<br/>Rn: R0 ~ R15로 대소문자 구분 없음<br/>`=value`: 상수값 지정, 최대 4바이트|
|상수값 지정 방식|10진수: 41, -1, 16진수: 0x12 등|
|활용 예|`LDR r0,=100`<br/>`ldr r1,=-200`<br/>`LDR R13,=0x1e3c`<br/>`ldr R15,=-0x1ff`|
||R15에 로드: 다음 명령 주소 혹은 분기명령 의미|
|Address label|label은 모두 주소 값이 됨(해당 label 위치의 주소)<br/>label은 첫 칸부터 기입|
||`HERE: MOV r0, #10`<br/>`STR r0,[r1]`<br/>`LDR pc, =HERE`|
||pc(R15)에 HERE명령의 주소(`MOV r0,#10`)를 기입: <br/>해당 명령을 다시 수행하며 결국 무한루프|

### 레지터스 간접참조, LDR STR
- 특정 주소에 있는 메모리를 LDR/STR할 때는 간접 참조 사용

|레지스터 간접참조|`ldr Rd,[Rs]`|
|:---:|:---|
||`Rd := [Rs]`<br/>Rs 레지스터 값을 메모리 주소로 그 내용을 Rd로 로드<br/>Rs,Rd: r0 ~ r15 |
||`str Rs,[Rd`|
||`[Rd] := Rs`<br/>Rd 레지스터 값을 메모리 주소로 그 내용에 Rs 저장<br/>Rs,Rd: r0 ~ r15|
|활용 예|`LDR r0,[r1]`: R0 값 = R1 주소 안의 값<br/>`STR r0,[r1]` : R0 값 = R1 주소 |

- C문법으로 다음과 같이 이해가능

```cpp
LDR Rd,[Rs]: Rd = *Rs;
STR Rs,[Rd]: *Rd = Rs;
```

### WDT 레지스터
- WDT를 Disable하려면 WTCON 레지스터의 비트 필드 설정을 바꾸어야
- WDT는 Periperal로, 따라서 WTCON 레지스터는 메모리로 인식, CPU에서 접근

![WTCON](http://www.ntrexgo.com/wp-content/uploads/2013/05/18feajkarm001.jpg)

출처: http://www.ntrexgo.com/archives/13612

### WDT 제어
- 0x53000000번지에 0을 대입
```assembly
ldr r0,=0x53000000
ldr r1,=0x0
str r1,[r0]
```
<<<<<<< HEAD

### ARM920T Coprocessor
- 코프로세서는 CPU에 없는 기능을 수행하는 보조 프로세서
- 캐시, MMU, GPU 등 다양하게 존재

### Coprocessor 액세스
- 코프로세서는 주변장치와 달리 별도의 포트로 CPU에 연결(Port Mapped IO)
- 코프로세서는 CPU와 독립적인 별도 CPU로 볼 수 있음
- ARM CPU는 CP0 ~ CP15를 통해 코프로레서에 접근, 제어
- 이들의 역할은 지정되어있으며, ARM920T는 CP15만 가지고 있음
	- CP15를 이용하여 MMU, 캐시, Write Buffer를 제어

### CP15: System Control Coprocessor
- CP15에는 C0 ~ C15가 있으며 이들은 다시 여러 개의 레지스터로 구성됨
- 기존 LDR, STR, MOV 명령으로는 코프로세서에 접근 불가: 별도의 명령이 존재
- MCR, MRC를 이용하여 접근
	- MCR: 코프로세서 -> 레지스터
	- MRC: 레지스터 -> 코프로세서
- 암기할 수는 없으며, Teghnical Reference를 통해 확인하여 사용

=======
>>>>>>> af698c473ca68c51463242d1935220a74c30d5d1
