# ARM의 Mode과 Exception
### Mode와 Exception
- ARM은 하나의 프로세서에 7개의 프로그램이 구동될 수 있음
- 동시에 실행되지는 못하며 각각 용도가 정해져 있음
	- APP,고장처리,인터럽트 처리 등의 프로그램들이 7개가 존재(ver 4T)
- Exception: 구동 중인 프로그램을 멈추게 하고 새 프로그램을 실행하는 모든 이벤트
	- Reset, 고장, 인터럽트 발생, 오류 발생 등 7개의 exception이 존재(ver 4T)
- Mode: 7개가 존재하며 Exception에 따라 프로세서의 상태가 변경(ver 4T)
- Exception이 발생한다면
	- 프로세서의 모드와 프로그램(Exception Handler)가 바뀜
	- 모드가 변경되면 사용되는 레지스터 set, CPSR 레지스터의 내용이 바뀜

### Exception Vectors
- Exception Vector: Exception이 발생하면 구동되는 프로그램의 위치
- 벡터영역은 4B뿐이므로 프로그램당 명령어 1개만 있을 수 있음
	- exception vector 사이의 공간은 4B밖에 없음
	- 때문에 일반적으로 예외사항을 처리하는 프로그램은 다른 곳에 만든 뒤 공간에 주소를 남겨놓음
	- 예: `B RESET_HANDLER`
	- Why?: 각 예외사항을 해결하는 코드가 상황마다 다름
		- 미리 예상하고 충분한 공간을 남겨놓지 못함
		- 때문에 프로그램을 다른 부분에 두고 주소만 남겨둠
	- FIQ 예외는 분기의 필요가 없음: 가장 마지막이므로, 바로 뒤에 프로그램을 남길 수 있음
- FIQ Vector는 제일 아래에 놓이므로 분기 없이 코드를 바로 설계할 수 있음

![exception vector](https://saurabhsengarblog.files.wordpress.com/2015/12/exception_vector.jpg)

출처: https://saurabhsengarblog.wordpress.com/2015/12/05/arm-architecture-basics/

![vector table explanation](https://hackpad-attachments.s3.amazonaws.com/hackpad.com_9kNqmqPbjtH_p.181189_1425059780130_arm_exception.jpg)

출처: https://kerker-notes.hackpad.com/ep/pad/static/9kNqmqPbjtH

### 7 Processor Modes
- user,system mode: 유저 프로그램이 실행되는 상황
	- user는 힘이 없고, system은 힘이 있음
	- 같은 레지스터를 사용
	- 이들을 제외한 나머지 모드는 exception을 관리하기 위한 모드
- Supervisor mode: OS에서 많은 자원을 관리하면서 접근할 수 있음(OS를 위한 모드)
- Privileged mode
	- 다른 모드로 자유롭게 전환 가능
	- Protected system recources의 액세스 가능

![7 processor mode](http://infocenter.arm.com/help/topic/com.arm.doc.dai0235c/AN235_migrating_from_mips_to_arm_files/image003.png)

출처: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dai0235c/index.html

### 모드에 따른 CPSR 변화
- 모드가 변경될 때 CPSR의 마지막 1바이트(0 ~ 7비트)가 변화(Control field)
- 일반 명령의 피연산자로 사용될 수 없으며 특수 명령 사용
- 모드를 변경할 때 변하는 것들
	- M[4:0]: 모드 id값 반영, 강제 변경 가능(user모드 제외)
	- T: Thumb mode로, 명령어 모드가 Thumb이면 1, Reset시 0
	- I: IRQ Mask: 1이면 IRQ 금지, Reset시 1
	- F: FRQ Mask: 1이면 IRQ 금지, Reset시 1
- User모드에서는 Control field 변경 불가

![mode-CPSR](http://www.jkelec.co.kr/img/lecture/arm_arch/img/57.png)

### 모드별 레지스터 구성

![ARM Register](https://image.slidesharecdn.com/arm1-140401220608-phpapp02/95/the-arm-architecture-arm-arm-architecture-11-638.jpg?cb=1396390153)

출처: https://www.slideshare.net/sreea4/arm-1

- R1 ~ R7,PC,CPSR: 모든 모드가 공유
- R8 ~ R12: FIQ모드를 제외한 다른 모드들은 다 같이 공유
- R13,R14,SPSR: 모드 개별적으로 따로따로 주어져 있음

### LR,SPSR
- Exception은 함수 호출과 달리 프로그램에서 발생 시점을 인지 못함
- LR,CPSR을 공용으로 사용하게 되면 원래 위치로 복귀시 LR,CPSR이 훼손
- LR: 각 모드들은 그 모드들이 종료된 후 돌아갈 곳을 지정하기 위해 각 모드별로 따로 존재
- SPSR: 모드로 넘어오기 이전 모드의 CPSR을 백업
	- Exception은 원모드로 복귀시 CPSR의 보존이 필요
	- Exception 발생시 CPSR을 전환하는 모드의 SPSR에 백업
	- Exception 종료 후 모드 복귀시 SPSR을 CPSR로 복원

### Exception 호출과 복귀 루틴
- Exception에서 복귀할 때 PC, CPSR이 동시에 복원되어야: 두가지
1. Destination Register(Rd)가 PC일 경우 산술 연산 명령 + S suffix 사용
	- S Suffix 사용시 CPSR 역시 복귀됨
	- `MOVS PC,R14`, `SUBS PC,R14,#4`
	- Exception 복귀 명령이 되어 동시에 PC <- LR, CPSR <- SPSR이 됨
2. LDMFD에서 reg-list에 PC가 있을 때 ^ 옵션 사용
	- reg-list에 PC가 있을 경우 ^: 현재 모드의 스택에 usr모드의 레지스터들을 push,pop
	- 모드가 usr/sys가 아닐 경우는 exception으로부터의 탈출 명령이 됨
	- `LDMFD SP!,{R0-R12,PC}^`

### 서브루틴과 PC값의 변화
```assembly
	MOV R0,PC
	MOV R1,R0
	B LOOP
```
- 처음 명령의 주소가 0x1000일 경우, PC값은 1008을 가리킴: Fetch-Decode-Execution단계에 의함
- BL에 의해 PC가 LR에 대입될 때는 자동으로 LR:=PC-4로 대입
- 따라서, BL func로 호출된 이후 리턴될 때에는 MOV PC,LR을 그대로 사용 가능

### 절대 위치 분기
- B,BL은 32비트 명령에 포함되므로, 32mb만큼 앞뒤의 내용으로 이동 가능
- 직접 분기 주소를 PC에 넣어 분기를 수동적으로 해결 가능

```assembly
	@범위 제한 없는 분기
	mov lr,pc @현재 위치의 다음다음 명령의 주소를 lr에 넣어 돌아올 수 있도록 조치
	ldr pc,=Delay @레이블의 주소를 pc에 넣어 분기로 바로 이동

	@레지스터 값을 주소로 하는 분기
	mov lr,pc @다음다음 명령의 주소 저장
	mov pc,r0 @r0주소로 pc 이동
	@에러 없는 BL r0
```

### Exception 처리과정

![exception](http://pds10.egloos.com/pds/200906/04/90/c0098890_4a27ab4a96429.jpg)

출처: http://recipes.egloos.com/4986862

### Reset Exception Handling
- 활성화
	- 처음 전원을 키거나 리셋 기능이 활성화 되었을 때
	- watchdog timer를 리셋하지 못했을 때
	- 들어오던 전원의 전압이 작아질 때(Brown out)

	|Register|상태|
	|---|---|
	|모드|supervisor mode|
	|LR,SPSR|모름(리셋 상태)|
	|CPSR[4:0]|10011b|
	|CPSR[5]|0(ARM state)|
	|CPSR[7:6]|IRQ=1,FIQ=1(Disable)|
	|PC|0x00000000|

- Handler 완료 후 동작
	- 일반적인 프로그램 본문의 시작
	- C언어의 시작부분인 main함수를 호출(분기)

### Undefined Exception
- 원인: 정의되어 있지 않은 명령어로 판단될 때
	- 외부 coprocessor 명령일 경우 coprocessor의 ACK를 기다림
	- ACK가 없을 때 undefined exception을 발생
- Handler 활용
	- 디버깅: Breakpoint 지점에 undefined 명령 삽입
- 서비스 시점, 복귀 위치
	- Decoding 시점에서 문제 인식 후 execution 과정에서 서비스 시작
	- LR_und := PC-4: 다음 명령 (고장난 위치를 복구할수 있다면)

|Register|상태|
|---|---|
|모드|Undefined mode|
|LR|undefined 명령어 다음 명령주소|
|SPSR|CPSR|
|CPSR[4:0]|11011b|
|CPSR[5]|0(ARM state)|
|CPSR[7:6]|IRQ=1,FIQ=안바뀜|
|PC|0x00000004|

- `SUBS PC,LR,#4`를 통해 exception 발생한 곳으로 이동할 수 있음

### Software Interrupt Exception
- 원인: SWI 명령 수행 시
	- `SWI 0x41`: 명령 뒤 24bit 한계의 SWI 번호 추가
- 활용
	- System Call: OS의 시스템 함수를 호출하여 사용
- 서비스 시점, 복귀 위치
	- Decoding 시점에서 문제 인식 후 execution 과정에서 서비스 시작
	- LR_svc := PC-4: 다음 명령 (고장난 위치를 복구할수 있다면)

|Register|상태|
|---|---|
|모드|Supervisor mode|
|LR|SWI 명령어 다음 명령주소|
|SPSR|CPSR|
|CPSR[4:0]|10011b|
|CPSR[5]|0(ARM state)|
|CPSR[7:6]|IRQ=1,FIQ=안바뀜|
|PC|0x00000008|

- `MOVS PC,LR`를 통해 exception 발생한 곳 다음으로 이동할 수 있음

### Preftch Abort Exception
- 발생원인: fetch한 code 메모리가 invalid한 경우
	- 없는 메모리를 탐색하도록 한 경우
	- 4B alignment가 지켜지지 않은 주소가 PC에 들어갈 경우
- invalid한 메모리가 fetch과정에 있더라도 실제로 실행되지 않는다면(branch 등으로 인해) exception이 발생하지 않음
- 서비스 시점, 복귀 위치
	- Decoding 시점에서 문제 인식 후 execution 과정에서 서비스 시작
	- LR_pabort := PC-4: 다음 명령 (고장난 위치를 복구할수 있다면)
- Architecture V5부터는 BKPT명령에서도 발생
- 활용: SW breakpoint로 사용하고자 하는 경우

|Register|상태|
|---|---|
|모드|Abort mode|
|LR|exception 다음 명령주소|
|SPSR|CPSR|
|CPSR[4:0]|10111b|
|CPSR[5]|0(ARM state)|
|CPSR[7:6]|IRQ=1,FIQ=안바뀜|
|PC|0x0000000C|

- `MOVS PC,LR`: 문제 처리 후 다음 명령을 수행(BKPT 명령이 사용된다면)

### Data Abort Exception
- 발생원인: invalid한 데이터 메모리를 Load, Store하는 경우
	- 없는 데이터를 처리할 때
	- alignment규정을 지키지 못할 때
- 서비스 시점, 복귀 위치
	- execution 과정에서 문제 인식 후 다음 phase때 서비스 시작
	- LR_dabort := PC-4: 다음 다음 명령

|Register|상태|
|---|---|
|모드|Abort mode|
|LR|exception 다음 다음 명령주소|
|SPSR|CPSR|
|CPSR[4:0]|10111b|
|CPSR[5]|0(ARM state)|
|CPSR[7:6]|IRQ=1,FIQ=안바뀜|
|PC|0x00000010|

- `SUBS PC,LR,#8` 명령을 통해 발생명령으로 복귀 가능

### IRQ Exception
- 발생 원인: 프로세서 외부에서 IRQ 신호가 인가되었을 때
	- 코어 밖에는 여러 이벤트들을 관리하는 컨트롤러가 존재
	- IRQ상황인 경우, 컨트롤러는 상황을 CPU에 전달, IRQ 신호가 인가
	- CPSR[6] (IRQ 비트)가 disabled인 경우 인식하지 않음
	- I비트는 privileged mode에서만 변경 가능
- 서비스 시점, 복귀 위치
	- execution 과정에서 문제 인식 후 다음 phase(명령의 실행이 끝난 다음)때 서비스 시작
	- LR_irq := PC-4: 다음다음 명령

|Register|상태|
|---|---|
|모드|IRQ mode|
|LR|exception 다음 다음 명령주소|
|SPSR|CPSR|
|CPSR[4:0]|10010b|
|CPSR[5]|0(ARM state)|
|CPSR[7:6]|IRQ=1,FIQ=안바뀜|
|PC|0x00000018|

- `SUBS PC,LR,#4` 명령을 통해 발생명령 다음으로 복귀 가능

### FIQ exception
- 발생 원인: 프로세서 외부에서 IRQ 신호가 인가되었을 때
	- 인식 방법은 IRQ와 같음
	- FIQ는 좀 더 빨리 처리해야할 일들을 말함
	- CPSR[7] (FIQ 비트)가 disabled인 경우 인식하지 않음
	- F비트는 privileged mode에서만 변경 가능
- Exception Handler
	- vector 주소가 가장 마지막에 위치: 바로 프로그램을 마련, 더 빠르게 처리
	- 자체적으로 레지스터 보유(R8-R12): 더 빠르게 처리 가능
- 서비스 시점, 복귀 위치
	- execution 과정에서 문제 인식 후 다음 phase(명령의 실행이 끝난 다음)때 서비스 시작
	- LR_irq := PC-4: 다음다음 명령

|Register|상태|
|---|---|
|모드|FIQ mode|
|LR|exception 다음 다음 명령주소|
|SPSR|CPSR|
|CPSR[4:0]|10001b|
|CPSR[5]|0(ARM state)|
|CPSR[7:6]|IRQ=1,FIQ=1|
|PC|0x0000001C|

- `SUBS PC,LR,#4` 명령을 통해 발생명령 다음으로 복귀 가능