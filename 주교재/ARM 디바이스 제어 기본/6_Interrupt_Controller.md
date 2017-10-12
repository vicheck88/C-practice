# Interrupt Controller
### 인터럽트 방식
- 폴링 방식: 지속적으로 조건을 확인하는 방법
	- 기존 일에 집중하지 못하고 계속 확인함으로서 낭비가 생김
- 인터럽트: 설정 조건이 충족되면 현재 코드에서 처리루틴으로 분기되도록 하는 방법
- 입력이 들어올 때 현재 프로그램을 멈추고 서비스 루틴으로 분기
- 서비스 루틴에서는 이에 대한 처리를 한 후 원 코드로 복귀

![interrupt](http://www.pyroelectro.com/tutorials/pic_interrupts_vs_polling/img/int.png)

![polling](http://www.pyroelectro.com/tutorials/pic_interrupts_vs_polling/img/polling.png)

출처: http://www.pyroelectro.com/tutorials/pic_interrupts_vs_polling/theory.html

### 인터럽트 컨트롤러
- Interrupt Controller는 여러개의 인터럽트를 관리하는 역할 수행
	- ARM CPU의 인터럽트는 2개: IRQ, FIQ
	- 하지만 인터럽트를 발생하는 주변장치의 수는 많은 편으로 이를 관리하는 장치 필요
	- SoC 제조사마다 달랐지만, 현재는 ARM에서 직접 컨트롤러 제공
- 기능
	- 인터럽트 소스별로 인터럽트 가능/불가능 설정
	- 인터럽트 요청 확인: Pending 레지스터
	- 인터럽트 간의 우선순위 파악
	- IRQ, FIQ 발생 여부 결정
	- 최종적으로 발생한 인터럽트에 대한 정보
- 인터럽트 발생 시
	- CPU는 인터럽트 벡터로 자동 분기
	- 인터럽트 핸들러 함수로 분기
	- 핸들러는 인터럽트를 확인하고 ISR(Interrupt Service Routine) 호출
	- 결국 CPU에 의해 자동으로 인터럽트별 ISR 함수 호출

### S3C2440의 인터럽트 컨트롤러
- SRCPND: 32개의 인터럽트 발생 시 각 비트가 1로 set
- MASK(INTMASK): IRQ 발생여부 결정
- Priority: 인터럽트 우선순위 결정
	- 32개의 소스들은 각각의 그룹으로 나뉘어 있음
	- 먼저 그룹 안에서 경쟁한 후, 선발된 소스끼리 경쟁하여 최종 순위 선정
- INTPND: 우선순위 배정 후 최종 선정된 소스 비트 set
- FIQ: Priority의 영향을 받지 않으며 MASK, MODE에서만 선택됨
	- FIQ로 전달되는 이벤트는 하나밖에 없음: 우선순위 배정의 이유가 없음
- 최종적으로 발생한 IRQ번호는 INTOFFSET 레지스터에 저장됨
	- INTPND 레지스터를 일일히 찾아볼 필요 없음

![Interrupt Controller in S3C2440](http://cfs7.tistory.com/original/27/tistory/2008/08/17/14/08/48a7b25854622)

출처: http://armprocessor.tistory.com/entry/ARM-Interrupt-controller

![Interrupt Controller in S3C2440](http://img.blog.csdn.net/20160624100352338)

출처: http://blog.csdn.net/u012582664/article/details/51753570

