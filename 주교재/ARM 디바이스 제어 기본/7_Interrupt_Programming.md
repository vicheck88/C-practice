# Interrupt Programming
### Key Matrix 회로
- S3C2440 칩의 스위치들은 기존 GPF말고도 EINT(External Interrupt)와 연결되어있음
- 기존 핀들의 기능을 EINT로 설정함으로써 IRQ 인터럽트로 사용 가능
- 이경우 EINT의 트리거 레벨을 설정해야
	- 어떤 상태일때(Falling/Rising edge 등) 인터럽트를 발생할지 결정

```cpp
	//초기화(push key)
	void Key_Push_ISR_Init(void)
	{
		// Key_Push => GPF0 (EINT0)
		Macro_Write_Block(rGPFCON,0x3,2,0);
		// KEY_OUT0 => GPC8 (Output)
		Macro_Write_Block(rGPCCON,0x3,0x1,16);
		// KEY_OUT0 => Out 0
		Macro_Clear_Bit(rGPCDAT,8);
		// EINT0 Trigger ==> Falling Edge
		Macro_Write_Block(rEXTINT0,0xf,2,0);
	}
	//신호가 들어올 경우 인터럽트를 받아들이도록 하는 함수
	void Key_Push_ISR_Enable(int en)
	{
		if(en)
		{
			// 기존 인터럽트 PEnding Clear
			// 클리어 순서는 SRCPND -> INTPND: 
			// 마스크가 enable되어있을 경우 INTPND값은 SRCPND에 의존
			// SRCPND가 1일 경우 INTPND값이 클리어되지 않을 수 있음
			rSRCPND=BIT_EINT0; //BIT_EINT0: 매크로로 0x1에 해당
			rINTPND=BIT_EINT0;
			// EINT0 Enable
			Macro_Clear_Bit(rINTMSK,0);
		}
		else
		{
			// EINT0 Disable
			Macro_Set_Bit(rINTMSK,EINT0);
		}
	}
```
```cpp
	void Key_ISR_Init(void)
	{
		// KEY_IN[3:0] => GPF4,5,6,7 (EINT4~7)
		Macro_Write_Block(rGPFCON,0xff,0xAA,8);
		// KEY_OUT[1:0] => GPC9,8 (Output)
		Macro_Write_Block(rGPCCON,0xf,0x5,16);
		// KEY_OUT[1:0] => All Clear
		Macro_Write_Block(rGPCDAT,0x3,0,8);
		// EINT[7:4] Trigger ==> Falling Edge
		Macro_Write_Block(rEXTINT0,0xffff,0x2222,16);

	}

	void Key_ISR_Enable(int en)
	{
		if(en)
		{
				// 기존 인터럽트 PEnding Clear
				// EINTPEND, SRCPND, INTPND
				// 스위치들은 하나의 인터럽트로 연결
				// 때문에 인터럽트와 연결된 여러 키를 관리하는 보조 기능 필요
				// 여기에서는 EINTPND, EINTMASK가 그 역할을 담당하며 따라서 해당 레지스터를 관리해야
				rEINTPEND = 0xf<<4;
				rSRCPND = BIT_EINT4_7;
				rINTPND = BIT_EINT4_7;
				// EINT4~7 개별 인터럽트 Enable
				Macro_Clear_Area(rEINTMASK, 0xf, 4);
				// EINT4_7 IRQ Enable
				Macro_Clear_Bit(rINTMSK,EINT4_7);
		}

		else
		{
				// EINT4~7 개별 인터럽트 Disable
				Macro_Set_Area(rEINTMASK, 0xf, 4);
				// EINT4_7 IRQ Disable
				Macro_Set_Bit(rINTMSK,EINT4_7);
		}
	}
	
	void EINT4_7_ISR(void) //인터럽트 핸들러 함수
	{
		Macro_Write_Block(rGPFCON, 0xff, 0x0, 8);
		//모드변경: 어떤 키를 눌렀는지 알기 위해 입력모드로 변경
		Uart_Printf("Key = %d\n", Key_Get_Pressed());
		//이전에 만든 Key_Get_Pressed 함수를 이용
		Key_ISR_Init();

		rEINTPEND = 0xf << 4;
		rSRCPND = 1<<4;
		rINTPND = 1<<4;
	}

```

### 인터럽트 루틴의 개선
- 서비스함수의 서비스 시간은 최소한으로 줄어야 함
	- 시간이 길어질 경우, 원래 루틴의 중지 시간이 늘어나게 됨
	- 인터럽트 상황 서비스는 짧은 시간 내에 끝내는 것이 바람직
- 반드시 필요한 일만 서비스 함수에서 처리하고 중요하지 않은 일은 main에서 확인할 경우, 본 작업을 오래 중지하지 않아도 되므로 좀 더 바람직
	- 서비스 함수에서는 flag를 생성하고 나머지는 메인함수에서 처리하도록 함

```cpp
	volatile int Key_push = 0;

	void EINT0_ISR(void) //ISR 함수: 플래그만 세우고 돌아감
	{
		Key_push = 1;

		rSRCPND = 1<<0;
		rINTPND = 1<<0;
	}

	void Main(void)
	{
		Uart_Init(115200);
		Led_Init();

		Uart_Printf("Key Matrix IRQ Event Test\n");

		Key_Push_ISR_Init();
		Key_ISR_Init();
		Key_Push_ISR_Enable(1);
		Key_ISR_Enable(1);

		for(;;)
		{
			if(Key_push) //메인에서 나머지 작업 수행
			{
				Uart_Printf("Push Key!\n");
				Key_push = 0;
			}
			Led_Display(0x0);
			Timer0_Delay(100);
			Led_Display(0xf);
			Timer0_Delay(100);
		}
	}
```

### UART 인터럽트
- UART 인터럽트에는 송신, 수신, 에러 3개의 인터럽트가 존재
	- 송신: TX버퍼가 비거나 FIFO사용 시 trigger level에 도달
		- 인터럽트 때 새로운 데이터를 보냄
	- 수신: RX버퍼가 비거나 FIFO사용 시 trigger level에 도달
		- 인터럽트 때 새로운 데이터 수신
	- 에러: Frame, Parity, Overrun 에러 발생 시 발생
- S3C2440의 경우 각 UART 인터럽트들은 핀 하나에 배정
- 따라서, 좀 더 자세한 구분을 위해 보조 pending,mask 레지스터가 필요(SUBSRCPND,SUBMASK)

![Interrupt Controller in S3C2440](http://cfs7.tistory.com/original/27/tistory/2008/08/17/14/08/48a7b25854622)

출처: http://armprocessor.tistory.com/entry/ARM-Interrupt-controller

![Interrupt Controller in S3C2440](http://img.blog.csdn.net/20160624100352338)

출처: http://blog.csdn.net/u012582664/article/details/51753570

```cpp
	//원하는 인터럽트를 받아들일 수 있도록 준비하는 함수
	void Uart_ISR_Enable(int rx, int tx, int err)
	{
		// 요청한 각 인터럽트의 SUB Source 인터럽트 허용
		// 하나라도 인터럽트를 허용하는 경우 부모 인터럽트 허용
		if(rx || tx || err)
		{
			// 인터럽트 허용전에 이전의 pending clear 필요
			// SUBSRCPND, SRCPND, INTPND Clear
			rSUBSRCPND = 0x7;
			rSRCPND = 1<<28;
			rINTPND = 1<<28;
			// Interrupt Enable
			if(rx) Macro_Clear_Bit(rINTSUBMSK,0);
			else Macro_Set_Bit(rINTSUBMSK,0);
			if(tx) Macro_Clear_Bit(rINTSUBMSK,1);
			else Macro_Set_Bit(rINTSUBMSK,1);
			if(err) Macro_Clear_Bit(rINTSUBMSK,2);
			else Macro_Set_Bit(rINTSUBMSK,2);

			Macro_Clear_Bit(rINTMSK,28);
		}
		// 아무 인터럽트도 요청하지 않으면 부모 인터럽트 불허
		else
		{
			Macro_Write_Block(rINTSUBMSK,0x7,0x7,0);
			Macro_Set_Bit(rINTMSK,28);
		}
	}
	void UART0_ISR(void) //ISR 함수(수신 인터럽트)
	{
		Uart_Printf("DATA=%c\n", rURXH0);
		// Pending Clear
		// 클리어는 데이터를 출력한 이후 수행: 출력 전에 클리어할 경우 다시 버퍼자료가 들어와 set
		rSUBSRCPND = 0x7;
		rSRCPND = 1<<28;
		rINTPND = 1<<28;
	}
	//ISR 함수 개선(수신 인터럽트): 중요한 것만 처리하고 플래그 처리한 채로 메인으로
	void UART0_ISR(void)
	{
		Rx_data = rURXH0; //데이터 수신
		Rx_data_in = 1;
		//플래그 변수(수신변수를 플래그로 같이 쓸 경우, 수신에 0이 들어갈 경우 플래그가 제대로 적용하지 않음)

		rSUBSRCPND = 1<<0;
		rSRCPND = 1<<28;
		rINTPND = 1<<28;
	}
```

### Time 인터럽트
- 기존 Delay 함수의 문제점
	- 함수 시행 동안 다른 작업 처리가 불가: while문을 사용하기 때문
	- 인터럽트를 이용하여  timeout되었을 때만 led를 켜고 끌 수 있음

```cpp
	void Timer0_Delay_ISR_Enable(int en, int time)
	{
		if(en)
		{
			// 주어진 시간으로 one-shot 동작하도록 타이머 설정
			Macro_Write_Block(rTCFG0, 0xff, PCLK/(50000 * 8)-1, 0);
			Macro_Write_Block(rTCFG1, 0xf, 2, 0);
			Timer0_Set_Time(time);
			// Pending Clear
			rSRCPND = 1<<10;
			rINTPND = 1<<10;
			// Timer0 인터럽트 Enable
			Macro_Clear_Bit(rINTMSK,10);
			// Timer0 Start (Manual Update Off)
			Macro_Write_Block(rTCON,0xf,2,0);
			Macro_Write_Block(rTCON,0x3,1,0);
		}
		else
		{
			// TImer0 Stop
			Macro_Clear_Bit(rTCON,0);
			// Timer0 인터럽트 Disable
			Macro_Set_Bit(rINTMSK,10);
		}
	}
	
	void TIMER0_ISR(void) //exception handler
	{
		rSRCPND = 1<<10;
		rINTPND = 1<<10;

		Timer0_time_out = 1; //flag 설정
	}
```