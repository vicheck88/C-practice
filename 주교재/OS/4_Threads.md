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

