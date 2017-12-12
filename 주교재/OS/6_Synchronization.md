# Synchronization
## The Critical Section Problem
### Race Condition
- Race Condition: 여러 프로세스가 공유하고 있는 데이터를 동시에 사용, 수정하는 경우
	- 마지막 결과물은 어떤 프로세스가 해당 데이터를 사용하는지에 의존하게 됨
- 이 문제를 해결하기 위해 동기화가 필요

### The Critical-Section Problem
- 여러 프로세스가 공유하는 자원에 접근하는 영역
- 문제: 한 프로세스가 영역에 접근할 때, 다른 프로세스들은 접근하지 말아야 함

### Requirements for Critical-Secion Problem
1. Mutual Exclusion: 한 번에 한 개의 프로세스만이 Critical Section에 들어갈 수 있어야
2. Progress: critical section 밖 부분을 실행 중인 프로세스가 다른 프로세스들을 방해하지 말아야
3. Bounded Waiting: Critical section에 접근하기 위해 대기하는 시간이 너무 많아지는 것을 방지해야

### Algorithms
- https://m.blog.naver.com/PostView.nhn?blogId=odin515&logNo=150024735273&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F 참조


## Synchronization with Hardware Support
### Synchronization Hardware: Test and Set
- 기계들이 가지고 있는 특별한 명령어들
	- 변수의 내용을 테스트하고 수정하는 명령
	- 두 변수의 내용을 바꾸는 명령어
	- 다른 명령어들이 중간에 개입하지 않음
- 이들을 이용하여 좀 더 쉽게 동기화를 이끌어낼 수 있음

### Synchronization by interrupt disabling
- 인터럽트(타이머 인터럽트)를 잠시 중지하고 작업을 수행
- 스케쥴링을 잠시 중지함으로써 동시에 작동하는 코드들이 꼬이지 않고 순서대로 작동할 수 있도록 함
- 멀티 프로세서환경에서는 적절하지 않을 수 있음
	- 인터럽트가 모든 프로세서에게 적용됨: 한 프로세서의 인터럽트를 막아도 다른 프로세서에서 작동할 수 있음
	- 모든 인터럽트를 막는다고 하여도, 인터럽트 중지를 요청하는 동안 다른 프로세서에서 작업을 이미 수행하였을 수 있음

### Synchronization with OS Support
- 이전 솔루션들은 좀 더 복잡한 상황에 일반화하기 힘듦
- 세마포어를 통해 동기화문제를 해결
	- 세마포어는 atomic(운영체제에서 보장): 세마포어 구문 실행 도중 다른 코드 실행 불가
- 세마포어에는 Busy Waiting 방법과 Blocking 방법이 있음
	- Busy waiting: 프로세스가 계속 움직이면서 세마포어 상태를 확인
		- 지속적으로 변수를 확인하므로 계속 실행중인 상태
		- CPU 클락의 낭비에 대한 우려 존재
	- Blocking: 프로세스의 상태를 한번만 확인한 수 waiting 상태로 변화
		- 후에 signal 명령을 통해 프로세스를 깨울 수 있음
		- 계속적으로 실행하지 않고 다른 프로세스를 실행할 수 있음

### Two Types of Semaphore
- Counting Semaphore
	- 여러 프로세스가 Critical section에 진입해야 할 때 사용
	- 리소스가 여러개 있을 때 리소스 개수만큼 세마포어 개수를 지정 가능
- Binary Semaphore
	- 일반적인 세마포어의 형태로, 한 프로세스만 영역에 접근 가능

### Mutex
- Mutual Exclusion의 줄임말로, binary semaphore와 비슷
- Mutex는 자신이 lock할 경우 unlock은 반드시 자신이 해야함

## Classical Synchronization Problems
### Classical Problems
- 세마포어, 뮤텍스는 원시적인 방법: 이들을 이용하여 복잡한 동기화 문제를 해결해야 함
- 문제
	- Readers-Writers Problem
	- Dining-Philosophers Problem

### Readers-Writers Problem
- 여러명의 Reader, Writer에 관한 버퍼를 생성
- Writer들은 한번에 하나만 버퍼에 접근 가능
- First readers-writers problem
	- 독자들은 서로를 기다리지 않음
	- 작가가 쓸 권한을 얻을때까지 기다리지 않음
- Second readers-writers problem
	- 작가가 준비가 되면 바로 버퍼에 입력
	- 작가가 접근이 되있을 경우 새로 유입된 독자들을 읽지 못함

