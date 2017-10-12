# Timer & PWM Output

### Timer & Counter
- 외부에서 인가되는 clock을 세는 장치
- 타이머 vs 카운터
	- 타이머: 주기적으로 펄스를 입력하고 이를 세 경과 시간을 측정
	- 카운터: 외부에서 들어온 펄스의 수를 세는 목적
	- 회로적으로는 동일하며, 개념적인 차이만 존재
	- 타이머: 일정 주기를 갖는 내부 클락, 카운터는 외부 펄스를 사용
- S3C2440에 내장된 타이머/카운터
	- 16비트 down counter: clock당 값이 하나씩 감소

### 기준 펄스의 형성
- 최고 16비트(65536) 펄스 계수 가능
- Prescaler: 타이머 기준 펄스(PCLK)를 분주
	- 8비트로 PCLK를 0 ~ 256까지 분주
- Prescaler 뒤 분주기(Divider)가 있어 다시 2,4,8,16분주 선택
- MUX를 통해 원하는 분주 주기 설정
	- 채널 별로 하나씩 존재: 채널별로 각각의 clock 소스 선택
	- MUX에서 TCLKx선택: 외부 펄스를 타이머 입력으로 사용

![timer](http://img.blog.csdn.net/20140821233615437?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvWHNjS2VybmVs/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

출처: http://blog.csdn.net/XscKernel/article/details/38736177

### 타이머의 기본 구조
- TCNTB0: 버퍼로, 타이머 동작을 위한 초기값 저장
- Timer0: 16비트 down counter로 0이 될 때 TCNTB0에서 값을 가지고 와 다시 동작
- TCNTO0: 타이머의 값이 감소될 때마다 값을 저장하는 레지스터

### One shot 모드와 Auto Repeat 모드
- One shot: 타이머가 0으로 expired되었을 때 동작이 멈추는 방식
- Auto Reload: 0이 될 때 다시 TCNTB값으로 자동으로 재시작하는 방식
- TCNTB의 값은 Manual Update와 Auto Update에 의해 갱신
	- Manual Update: 수동으로 TCNTB의 값을 타이머 내부로 로드
	- Auto Update: 타이머가 0으로 될 때 자동으로 TCNTB값 로드

![Timer](https://mblogthumb-phinf.pstatic.net/20120229_84/ham9627_1330496112479gJsLz_JPEG/PWM_%B1%E2%BA%BB%B5%BF%C0%DB%BF%B9%C1%A6.jpg?type=w2)

출처: https://m.blog.naver.com/PostView.nhn?blogId=ham9627&logNo=40150920051&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F

### 스탑워치 만들기
```cpp
	void Timer0_Stop_Watch_Run(void)
	{
		// Timer0 Prescaler와 MUX를 20usec tick (50KHz)가 되도록 설정한다
		Macro_Write_Block(rTCFG0,0xff,124,0);
		Macro_Write_Block(rTCFG1,0xf,2,0);
		// TCNTB0에 최대값을 저장한다
		rTCNTB0=TIMER0_MAX;
		// Timer0 Manual Update On & Timer Off & Auto-Reload Off & inverter off
		Macro_Write_Block(rTCON,0xf,2,0);
		// Timer0 Manual Update Off & Timer ON
		Macro_Write_Block(rTCON,0x3,1,0);
	}
	unsigned int Timer0_Stop_Watch_Stop(void)
	{
		// Timer0 Off
		Macro_Clear_Bit(rTCON,0);
		// 경과 펄스수에 20usec를 곱한 값을 리턴
		return (0xffff-rTCNTO0)*20;
	}
	//PCLK값이 정확히 50MHz가 아니기 때문에 출력값에는 오차가 존재
```

### Timeout 측정
- TCNTO0이 0일때를 timeout으로 측정하는 것은 바람직하지 않음
	- 초기값이 0일 경우 처음부터 timeout이 됨
- 타임아웃이 발생할 때 SRCPND 레지스터에 flag로 표시가 됨
- 이 레지스터를 이용하여, 타임아웃을 판단, 딜레이 함수 구현이 가능
	- SRCPND레지스터는 클리어할때 1을 대입해야 함
	- 0을 대입하면 클리어가 되지 않음
		- SRCPND레지스터는 하드웨어 레지스터
		- 0으로 클리어할 경우, 만약 그 즈음 다른 상황이 발생할 때 그 상황 역시 초기화
		- 이를 예방하기 위해 1로 클리어
	- flag를 확인한 수 반드시 클리어시켜야 함

```cpp
	//Delay
	void Timer0_Delay(int time)
	{
		// 20usec tick (50KHz)로 Prescaler와 MUX 설정
		Macro_Write_Block(rTCFG0,0xff,(int)(PCLK/50000./4+0.5),0);
		Macro_Write_Block(rTCFG1,0xf,1,0);
		// TCNTB0에 주어진 time(msec 단위)를 지연하기 위한 시간 설정
		rTCNTB0 = time*TIMER0_PULSE_FOR_1MS;
		//16비트로, 최대값을 넘을 경우 제대로 작동 불가
		// SRCPND 레지스터 해당 비트 PENDING Clear
		rSRCPND = 1<<10;
		// Manual Update ON & TImer OFF
		Macro_Write_Block(rTCON,0xf,2,0);
		// Manual Update OFF & TImer ON
		Macro_Write_Block(rTCON,0x3,1,0);
		// Timer0 종료 대기
		while(Macro_Check_Bit_Clear(rSRCPND,10));
		// SRCPND 레지스터 해당 비트 PENDING Clear
		rSRCPND = 1<<10;Macro_Clear_Bit(rTCON,0);
	}
	
	//시간제약 없음
	void Timer0_Delay(int time)
	{
		int i;
		unsigned int temp = time * 50;

		Macro_Write_Block(rTCFG0, 0xff, PCLK/(50000 * 8)-1, 0);
		Macro_Write_Block(rTCFG1, 0xf, 2, 0);
		//for문을 통해 시간을 여러번 돌림
		//여러번 돌림으로써 rTCNTB0의 문제 해결
		for(i=0; i<(temp/0x10000); i++)
		{   
			rTCNTB0 = 0xFFFF;
			rSRCPND = BIT_TIMER0;
			Macro_Write_Block(rTCON,0x3, 2, 0);
			Macro_Write_Block(rTCON,0x3, 1, 0);

			while(Macro_Check_Bit_Clear(rSRCPND, TIMER0));
			rSRCPND = 1<<10;;
		}

		if(temp % 0x10000)
		{
			rTCNTB0 = (temp % 0x10000) - 1;
			rSRCPND = BIT_TIMER0;
			Macro_Write_Block(rTCON,0x3, 2, 0);
			Macro_Write_Block(rTCON,0x3, 1, 0);

			while(Macro_Check_Bit_Clear(rSRCPND, TIMER0));
			rSRCPND = 1<<10;;
		}
	}
```

### 타이머 Repeat 함수
- Auto reload 기능을 이용할 경우, 자동으로 타이머가 갱신됨

```cpp
	void Timer0_Repeat(int time)
	{
		// 20usec tick (50KHz)로 Prescaler와 MUX 설정
		Macro_Write_Block(rTCFG0,0xff,(int)(PCLK/50000./4+0.5)-1,0);
		Macro_Write_Block(rTCFG1,0xf,1,0);
		// TCNTB0에 주어진 time(msec 단위) 지연 시간 설정
		rTCNTB0 = time*TIMER0_PULSE_FOR_1MS;
		// SRCPND 레지스터 해당 비트 PENDING Clear
		rSRCPND = 1<<10;
		// Manual Update ON & TImer OFF
		Macro_Write_Block(rTCON,0xf,2,0);
		// Manual Update OFF & TImer ON, Auto Reload ON
		Macro_Write_Block(rTCON,0xf,9,0);
	}

	int Timer0_Check_Timeout(void)
	{
		// Timer가 Expired 되었으면 Pending Clear하고 1 리턴
		if(Macro_Check_Bit_Set(rSRCPND,10))
		{
			rSRCPND = 1<<10; return 1;
		}
		// Timer가 Expired 되지 않았으면 0 리턴
		return 0;
	}
	void Timer0_Stop(void)
	{
		// Timer0 Stop
		Macro_Clear_Bit(rTCON,0);
	}
```