# Processes
## Process Concepts
### Process
- 정의: 현재 실행중인 프로그램
- 구성요소
	- PID(Process ID): 프로세스의 식별 기준, unsigned int
	- Address space: 메모리 상의 독자적인 주소공간
		- 32bit기계에서 4GB의 공간이 할당: 커널, 유저 공간으로 나뉨
		- 코드, 데이터, 스택, 힙 등으로 구성
	- State: running, waiting, ready
	- Current activity: CPU의 레지스터 값

### Process Control Block(PCB)
- 운영체제가 프로세스를 관리하는 방식

![PCB](http://slideplayer.com/4897843/16/images/7/Process+Control+Block+%28PCB%29.jpg)

출처: http://slideplayer.com/slide/4897843/

### Process state
- 프로세스의 현재 상태를 나타냄

![Process State](https://www2.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/images/Chapter3/3_02_ProcessState.jpg)

출처: https://www2.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/3_Processes.html

## Process Scheduling
### CPU Scheduling
- 멀티태스킹을 위해 OS는 다음에 실행할 프로세스를 선택하여 자원을 나눠줌
- 메모리에 올라가있는 여러 프로세스들을 번갈아가며 실행: Scheduling and Dispatching

### Context Switching
- Dispatcher가 사용 중인 프로세스를 변경할 때, 현재 실행중인 상황을 저장해두어야 함
- 이를 Context switching이라 부름
- 프로세스 context(state)
	- 시스템 context: 입출력 상태 등의 시스템 상태들
	- 메모리 context: 코드, 데이터, 스택, 힙 등의 공간
	- 프로세서 context: 프로세서 레지스터
- 프로세서 context를 제외한 나머지는 안전하게 저장되어있음: 마지막 부분만 저장하는 것으로 충분
- 변환하는 데에 시간, 자원 등이 소모됨
	- 시간을 줄이는 뾰족한 방법은 없음
- 프로세스에 한 번 주는 시간이 짧아질수록 프로그램은 매끄럽게 잘 되지만, 변환에 드는 시간, 자원 들은 더 늘어남

![Context switching](https://3.bp.blogspot.com/-awzANabX1O4/VMUx-d_bNII/AAAAAAAAABo/bDSWpdaTmCk/s1600/image026.jpg)

출처: https://mooneegee.blogspot.kr/2015/01/oscontex-switching.html

### Scheduling Queue
- Job Queue: 시스템 상의 모든 프로세스의 큐
- Ready Queue
	- 현재 실행을 기다리고 있는 프로세스들이 모인 큐
	- 연결 리스트로 구현됨
	- 큐의 헤더는 첫번째와 마지막 PCB의 포인터를 가지고 있음
- Device Queue
	- I/O 장치와 관련된 프로세스들의 집합

![Ready Queue](https://www2.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/images/Chapter3/3_05_Queues.jpg)

출처: https://www2.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/3_Processes.html

## Process Creation and Termination
### Process Creation
- 프로세스 생성법
	- 처음에 만들어냄
	- 원래 것을 클론(`fork()`)
- `fork()`명령은 원래 프로세스를 복제: PID를 제외한 모든 것이 다름
	- `exec()` 명령을 통해 프로세스에 다른 명령을 내림: 다른 프로세스로 변화
	- 굳이 바로 바꾸지 않고 `exec()` 명령을 사용하는 이유: 복제하는 데에 드는 비용이 0이어서 성능의 저하가 없음

![fork](https://i.stack.imgur.com/x7JPT.png)

출처: https://stackoverflow.com/questions/26793402/visually-what-happens-to-fork-in-a-for-loop

## Cooperating Processes
### Cooperating Processes
- 독립 프로세스(independent process)들은 다른 프로세스의 실행에 독립적임
- 협력 프로세스(cooperating process)들은 다른 프로세스의 실행과 연관됨
- 장점: 정보 공유, 계산속도 증가, 편리성, 모듈성

### Producer-Consumer Problem
- 생산자 프로세스는 소비자 프로세스가 사용하는 정보를 생성
- 주로 버퍼를 통해 정보를 주고받음: unbounded/bounded buffer

![comsumer-producer](https://pages.mtu.edu/~shene/NSF-3/e-Book/SEMA/DIAGRAM-producer.jpg)

출처: https://pages.mtu.edu/~shene/NSF-3/e-Book/SEMA/TM-example-buffer.html

### Interprocess Communication(IPC)
- 공유메모리나 메세지 이동(message passing)을 통해 데이터를 주고 받는 방법

### Direct Communication
