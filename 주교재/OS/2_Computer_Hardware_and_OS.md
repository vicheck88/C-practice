# Computer Hardware and OS
## Computer Organization
### CPU 제어
- 기계어를 통해 CPU를 제어: CPU는 명령만을 인식하고 수행
	- `load, store, add, sub` 등의 명령을 전달
- 프로그래밍의 뜻
	- 명령들의 수열을 구축하는 것
	- 결과물을 프로그램이라고 부름

### Von Neumann Architectur
- 폰 노이만 기계: 레지스터, 램 등을 가지고 있는 CPU
- 메모리로부터 명령어를 가져와 레지스터에서 실행

### 프로그래밍
- 어셈블리를 이용한 프로그래밍: 기계어와 1:1로 대응됨
- 어셈블리를 이용한 프로그래밍은 어려운 편: C,Java 등의 고급언어를 사용

### I/O Device Controller
- 각 I/O 디바이스들은 컨트롤러를 가지고 있음
- CPU는 컨트롤러를 통해 장치들과 통신

![I/O Device Controller](http://slideplayer.com/2406777/8/images/12/Device+controller+A+device+controller+has+registers+that+control+operation..jpg)

출처: http://slideplayer.com/slide/2406777/

## Interrupts and OS
### Interrupt
- 인터럽트: 외부에서 발생하는 이벤트를 받아들이는 하드웨어적인 처리법
	- 인터럽트 핀을 장치에 연결하여 이벤트를 받아들임
	- 이벤트 발생 시 PC의 값 이벤트에 해당하는 주소로 변경, 핸들러 프로그램 실행
- 인터럽트의 종류
	- 하드웨어 인터럽트: 하드웨어 신호로 발생, 비동기적
	- 소프트웨어 인터럽트: 명령의 수행하는 중 에러가 발생할 경우, 동기적

### Interrupt Hardware
- PIC(programmable interrupt controller)
	- 인터럽트를 관리하는 컨트롤러
	- CPU은 한 개의 인터럽트 신호만을 받을 수 있기 때문에 필요한 장치
	- 인터럽트 신호를 주는 여러개의 장치와 연결, CPU에 전달될 인터럽트를 관리
- Handling
	- 인터럽트 발생시
		- 현재 프로그램 중단, 현재 프로그램 주소 저장
		- IRQ 번호와 Interrupt vector table을 통해 약속된 주소로 이동
		- 핸들러 프로그램 실행
	- 인터럽트 과정 수행중
		- 처리 중에는 인터럽트 부분을 막아놓음: 루틴이 꼬이는 것을 방지
		- 처리 중에 온 신호는 PIC가 저장, 인터럽트가 끝난 뒤 CPU로 전달
	- 인터럽트 수행 후
		- 원래 프로그램으로 이동

### Dual Mode Execution
- OS는 시스템을 안전하게 보호하기 위해 두가지 방식의 모드를 가지고 있음
	- 유저 모드: 응용 프로그램 실행
		- 실행 가능 명령, 접근 가능한 레지스터에 제한이 없음
	- 커널 모드: 커널 코드를 실행
		- 모든 명령, 레지스터에 접근, 제어 가능
- 프로세서는 여러가지 모드들을 지원
	- 인텔은 4가지의 모드를, ARM은 8가지의 모드들을 지원

![intel protection ring](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2f/Priv_rings.svg/300px-Priv_rings.svg.png)

출처: https://en.wikipedia.org/wiki/Protection_ring

![ARM processor mode](http://infocenter.arm.com/help/topic/com.arm.doc.dai0235c/AN235_migrating_from_mips_to_arm_files/image003.png)

출처: infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dai0235c/index.html

### Memory Space
- 메모리는 유저, 커널 공간의 두가지로 나뉨
- 특정 명령(SWI in ARM)을 통해 유저 모드에서 커널 모드로 변환, 명령을 수행
- System call: 모드를 바꾸는 명령으로, 같은 프로세스, 모드 내에서 작동하는 function call과는 다름

![Memory Space](https://m.eet.com/media/1174619/emb111612_argawal01.png)

출처: https://www.embedded.com/design/operating-systems/4401769/Device-drivers-in-user-space