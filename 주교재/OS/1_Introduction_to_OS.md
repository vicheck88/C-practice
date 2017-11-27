# Introduction to OS

## OS
- 일반적인 정의
    - 응용 프로그램들의 실행을 위한 환경을 제공하는 시스템 소프트웨어
    - 하드웨어와 소프트웨어 사이에 존재
- 기술적 정의
	- Abstraction provider
		- API(Application Programming Interface)를 제공
		- 응용프로그램들이 공통적으로 사용할 수 있는 기능 제공
	- Resource manager
		- 리소스 관리
	- Illusion creator
		- 리소스가 무한하고 독립적인 것처럼 보이게 함
- OS가 가지 역할이 많기 때문에, 각각의 사용층에서 OS를 다양한 관점에서 바라볼 수 있음
- 매우 복잡한 형태를 가지고 있음: OS를 제작, 보유하기 힘듦
	- 대부분의 OS를 미국내 회사들이 보유 (MS, 구글, 애플 등)

## OS를 공부하는 이유
- 기술적
    - 컴퓨터 시스템의 가장 중요한 기술에 해당
        - 복잡한 하드웨어 시스템 관리
        - 복잡한 프로그램을 개발, 실행시킴
    - 컴퓨터 시스템이 돌아가는 원리를 이해할 수 있음
- 사업적
	- 비즈니스 마켓을 이끔
	- 생태계 형성에 굉장히 중요(구글: 안드로이드, 애플: IOS)
		- 여러 애플리케이션, 사용자들이 OS에 종속됨

## OS Concepts
### Evolution of OS
- 시기를 셋으로 나눌 수 있음
1. 50년대 초반 - 60년대 후반 (사람, 모니터)
	1. Human Operator
		- 컴퓨터가 굉장히 비쌌던 시기
		- 사람이 직접 컴퓨터를 조작: 사람이 OS의 역할 수행
		- 세팅에 굉장히 많은 시간이 걸림
	2. Resident Monitor(상주 모니터)
		- OS의 시초
		- 여러 개의 프로그램을 순차적으로 실행시킬 수 있도록 관리(batch process)
	3. Multiprogrammed Batch Monitor
		- 여러 프로그램의 작업 순서를 설정
	4. Spooling
		- 계산과 입/출력을 동시에 수행
2. 60년대 후반 - 90년대 후반 (최신 OS 컨셉): UNIX, 마이크로프로세서의 등장
	1. 멀티태스킹
		- 여러 프로그램이 같은 시간에 실행되도록 함(시간을 쪼개 순차적으로 수행)
		- 유저와의 상호작용: 마우스, 키보드 등을 이용
		- 네트워크의 사용
		- 서로 다른 유저들이 같은 컴퓨터를 같은 시간에 사용 가능
	2. 인터넷
		- 알파넷에서 유래
		- 네트워크를 통해 세계를 하나로 묶게 됨
3. 90년대 후반 - 현재 (모바일, 클라우드 등)
	1. 모바일
		- PDA vs Celluler phone
		- 첫 PDA는 1984년 개발
		- 특징: 터치 스크린, 무선 연결, 배터리 이용
		- PDA OS: Windows CE, Palm OS 등
		- 현재 대세는 모바일 폰: IOS, 안드로이드
	2. 클라우드
	3. 멀티코어
		- 더 많은 코어를 넣는 방식
		- 클락수를 높이는 방식이 한계에 봉착하면서 이를 해결하기 위해 나타남

### Fundamental Concepts
- OS는 라이브러리로 볼 수 있음
	- 재사용 가능한 프로그램들의 모임
	- 운영체제에는 수많은 entry point가 존재: main함수가 따로 존재하지 않음

![Android OS](http://www.webgeometrics.com/wp-content/uploads/2014/02/android_architecture.jpg)

출처: http://www.webgeometrics.com/android-os-architecture-explained-for-non-techies/

- 하지만 OS는 라이브러리 이상의 역할을 수행
	1. Abstraction
	2. Protection
	3. Illusion
	4. Coordination and Optimization

1. Abstraction
	- 하드웨어들을 따로 관리하는 것은 굉장히 힘듦
	- OS는 복잡한 장치들을 쉽게 사용할 수 있도록 지원, 복잡도를 낮춤
	- 시스템 콜(system call)은 OS와 애플리케이션 사이의 소통 공간을 제공
		- 시스템 콜을 이용하여 OS의 기능을 사용

![System call](https://notes.shichao.io/spec/figure_3.2.png)

출처: https://notes.shichao.io/spec/ch3/

2. Protection
	- OS는 여러 종류의 애플리케이션들로부터 시스템을 보호하는 역할 수행
3. Illusion
	- 하드웨어에 제한을 둠
	- 애플리케이션 자신이 모든 메모리, 프로세서 자원을 사용한다고 생각하게 만듦
4. Coordination and Optimization
	- 여러 애플리케이션들이 효율적으로 동작하도록 제어
	- Concurrency
	- Efficiency