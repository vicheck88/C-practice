# Threads
## Thread Concepts
### Process vs Threads
- 프로세스: 실행의 단위
	- 리소스에 대한 권한이 있음
		- 주소 공간, 일부 리소스들에 대한 제어권한 보유
- 스레드: 실행의 단위
	- 프로세스의 리소스를 다른 스레드들과 같이 공유
	- 실행하기 위한 최소한의 리소스만 가지고 있음
		- Processor register, stack space
	- 경량화된 프로세스로 볼 수 있음
	- 스레드 ID, 프로그램 카운터, 레지스터 집합, 스택을 보유
- 스레드: Concurrent function call

![process vs thread](http://www.pling.org.uk/cs/opsimg/threadmodel.png)

출처: https://sites.google.com/site/sureshdevang/thread-vs-process

### 멀티 스레드의 이점
- 응답성: 프로그램의 일부가 막혀도 프로그램이 계속 구동되도록 함
	- 일부 스레드가 동작하지 않을 때 다른 스레드를 사용: 성능이 더 좋아짐
- 자원 공유: 스레드들은 프로세스의 리소스, 메모리에 전부 접근 가능
	- 프로세스 간 공유(IPC 등)보다 더 간단하게 자원을 공유할 수 있음
- 경제성: 생성에 드는 자원이 적음
- 멀티프로세서 활용
- 동시적 프로그래밍 모델
	- 대부분의 언어는 동시성(concurrency)를 지원하지 않음
	- 스레드를 통해 이를 보완 가능

## Multithreading Models
### Kernel Threads
- 커널에서 직접적으로 관리하는 스레드
- 커널은 thread creation, scheduling, 커널 공간 안에서의 관리를 수행
- 커널에서는 TID, stack, TCB를 생성(프로세스와 비슷)하여 관리
- 예: 윈도우스, 유닉스, 리눅스

### User Thread
- 유저공간에서 스레드를 생성, 관리(커널의 도움 없음)
	- 라이브러리에서 직접 제작, 흉내
- 커널 스레드에 비해 성능이 좋음
	- 커널은 유저 스레드들을 단순히 하나의 단일 프로세스로 인식
	- 커널 스레드의 생성,관리를 위해서는 반드시 커널 모드로 진입을 반복해야 함
	- 유저 스레드의 관리에는 그런 수고가 필요 없음
- 유저 스레드들이 커널의 단일 스레드와 연결될 경우, 유저 스레드 중 하나에 block 명령이 있을 때 나머지 유저 스레드들 역시 block당함
	- 커널이 나머지 유저 스레드들을 인식하지 못하기 때문
- 예: POSIX Pthreads, Mach C-threads

![User, kernel thread](https://worldfullofquestions.files.wordpress.com/2014/06/hybird-implementation.png)

출처: https://worldfullofquestions.wordpress.com/2014/06/05/hybrid-implementation-of-thread/

## Threading Issues
- Issue: fork
    - `fork()` 명령을 실행할 때 두 개의 가능성이 있음
        - 모든 스레드를 복제하여 프로세스 생성
        - 단일 스레드만을 가지고 있는 프로세스로 복제
- Thread Pool
	- 한 번에 여러 개의 스레드를 미리 만들어 풀에 넣어 놓음
	- 요청이 올 때 대기중인 스레드를 활용하여 작업 수행 후 풀에 복귀
	- 요청이 올 때마다 새로 생성하는 방법보다 속도가 더 빠름
	- 동시에 여러 요청이 올 경우 한계가 있을 수 있음
- Stack Overflow
	- 프로세스가 스택 범위를 넘을 경우 segmentation fault 에러 발생
	- UNIX 커널은 문제를 감지하고 허용된 스택의 범위를 한계 내로 늘려 문제를 해결
	- 유저 스레드의 경우, 커널은 유저 스택에 대해 알 수 없음
	- 유저 스레드의 스택의 범위를 넘어설 경우, OS는 에러를 내보냄