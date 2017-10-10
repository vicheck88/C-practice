# GPIO 입력 제어
### GPIO pin의 논리 레벨 인식
- GPIO 핀에서는 출력 뿐 아니라 입력 역시 선택 가능
- 1도, 0도 아닐 경우 Hi-Z 상태로 불안정: 출력 값을 판단 불가
- Pull-up, Pull-down 저항을 통해 안정적인 값을 출력할 수 있도록 함

### 스위치 입력 회로
- 입력 핀 수를 줄이기 위해 key matrix를 만들어 연결
- Pull up 저항에 의해 스위치를 누르면 0, 누르지 않으면 1이 출력되도록 설계

### GPFCON, GPCCON
- S3C2440의 조이스틱은 GPFCON, GPCCON과 연결되어 있음: GPFCON을 입력, GPCCON을 출력으로
- 이중 up버튼은 GPF4,GPC8과 연결되어있음

```cpp
	#include "2440addr.h"
	#include "device_driver.h"
	#include "macro.h"

	void Main(void)
	{
		Led_Init();
		rGPCCON = Macro_Write_Block(rGPCCON, 3, 1, 16);
		//KEY_OUT0(GPC8) -> OUTPUT
		rGPCDAT = Macro_Clear_Bit(rGPCCON, 8);
		//0 값 출력

		rGPFCON= Macro_Clear_Area(rGPFCON, 0x3, 8);
		//KEY_IN0(GPF4) -> INPUT: 조이스틱의 값을 입력값으로

		for(;;)
		{
			// UP(GPF4)가 눌리면 LED1 ON 떼면 OFF
			// GPF4번 비트가 0인지 1인지 check
			Led_Display(Macro_Check_Bit_Clear(rGPFDAT, 4));
			//if(rGPFDAT & (1<<4)) Led_Display(0);
			//else Led_Display(1);
		}
	}
```

### Up key 토글
- Up key를 누를 때마다 led가 토글되도록 만들고 싶을 때
	- 단순하게 상태만 변화시키는 방법으로는 만들 수 없음
	- CPU의 속도가 매우 빠르기 때문에, 조금만 스위치를 눌러도 장비는 이를 여러 번 인식
	- 이 때문에 원하는 데로 동작하지 않음
- 해결 방안 1: wait key released
	- 키가 한 번 눌릴 때 while 등의 구문으로 더 이상의 작업을 하지 못하도록 조치
	- 문제점
		- 한 번 눌리면 while을 통해 계속 대기: 다른 작업을 동시에 하지 못함
- 해결 방안 2: inter-lock 방식
	- lock 변수를 통해 키가 눌렸을 때 lock을 1로, 아닐 때 0으로 만듦
	- 한 번 이상 작업을 못하도록 조치
	- wait key released 방식과 달리 다른 작업을 동시에 수행 가능
- 두 가지의 방법으로도 문제가 해결되지 않을 수 있음: chattering현상
	- 하드웨어, 소프트웨어적인 방법을 통해 문제를 해결

```cpp
	#include "2440addr.h"
	#include "device_driver.h"
	#include "macro.h"

	void Main(void)
	{
		int bit=0;
		int lock=0;
		Led_Init();

		// KEY_OUT0(GPC8) -> OUT, 0 값 출력
		// KEY_IN0(GPF4) -> IN
		rGPCCON = Macro_Write_Block(rGPCCON, 3, 1, 16);
		rGPCDAT = Macro_Clear_Bit(rGPCCON, 8);

		rGPFCON= Macro_Clear_Area(rGPFCON, 0x3, 8);
		for(;;)
		{
			//UP(GPF4)가 눌리면 LED1 Toggling

			//Wait-key-Released 방식
	//		if(Macro_Check_Bit_Clear(rGPFDAT,4))
	//		{
	//			Led_Display(bit^=1);
	//			while(Macro_Check_Bit_Clear(rGPFDAT,4));
	//			//눌려있는 동안 지속: 다른 작동을 금지하여 led 안정화
	//		}

			//Inter lock 방식
			if(!lock && Macro_Check_Bit_Clear(rGPFDAT,4))
			{
				lock=1;
				//한번 작동 후 lock을 1로 변화: 해당 조건문에 들어가지 못함
				Led_Display(bit^=1);
			}
			else if(lock && Macro_Check_Bit_Set(rGPFDAT,4)) lock=0;
			//키가 다 눌린 후 lock을 원래대로 되돌림
			Uart_Printf("%d\n",i++);
			i%=10;
			//inter-lock 방식을 사용할 경우, 다른 작업에 영향을 미치지 않음
			//wait-key-released방식을 사용할 경우, 키의 눌림여부에 따라 방해를 받음
		}
	}
```

### Switch key
- 스위치 8 ~ 11 역시 같은 방법으로 작동 가능
- 스위치를 누를 때 해당 led가 on 되는 결과를 얻고 싶을 때

```cpp
	#include "2440addr.h"
	#include "device_driver.h"
	#include "macro.h"

	void Main(void)
	{
		int led;
		Led_Init();

		// KEY_OUT1 -> OUT, 0 값 출력 (GPC9)
		rGPCCON = Macro_Write_Block(rGPCCON,0x3,0x1,18);//GPCCON9[19:18]
		rGPCDAT = Macro_Clear_Bit(rGPCDAT,9);//GPCDAT[9]

		// KEY_IN0~3 -> IN (GPF[15:8])
		rGPFCON = Macro_Clear_Area(rGPFCON,0xff,8);

		for(;;)
		{
			// KEY_IN0~3을 확인하고 눌린 키가 있으면 해당하는 LED ON, 안 눌렸으면 OFF
			//GPF[7:4]
			//Macro_Write_Block(rGPBDAT, 0xf, ((rGPFDAT>>4) & 0xf), 7);
			Led_Display((~(rGPFDAT>>4))&0xf);
			//스위치와 연관된 4개의 비트를 마스킹하여 led 레지스터에 기입

			//잘못된 예
		//	if(Macro_Check_Bit_Clear(rGPFDAT,4)) Led_Display(1);
		//	if(Macro_Check_Bit_Clear(rGPFDAT,5)) Led_Display(2);
		//	if(Macro_Check_Bit_Clear(rGPFDAT,6)) Led_Display(4);
		//	if(Macro_Check_Bit_Clear(rGPFDAT,7)) Led_Display(8);
		//	Led_Display(0);
			//제대로 작동하는 듯 보이지만 사실은 제대로 작동하지 않음
			//Led_Display는 지정한 부분 이외의 모든 led를 끄는 작업
			//사실 동시에 켜진 것이 아니라 꺼지고 켜지는게 계속 반복됨

			//위의 예를 고친 답
			led=0;
			if(Macro_Check_Bit_Clear(rGPFDAT,4)) led |= (1<<0);
			if(Macro_Check_Bit_Clear(rGPFDAT,5)) led |= (1<<1);
			if(Macro_Check_Bit_Clear(rGPFDAT,6)) led |= (1<<2);
			if(Macro_Check_Bit_Clear(rGPFDAT,7)) led |= (1<<3);
			Led_Display(led);
			//led값을 or 연산으로 업데이트하여 반영: 제대로 움직임
		}
	}
```

### 방향키와 switch (key matrix)
- 방향키 역시 같은 방법으로 조작 가능
- 방향키와 스위치키의 입력값은 동일(key_in0 ~ key_in3)하며 out값만 다름
- 방향키와 스위치를 구분하는 방법이 필요함
- key_out값을 변화시킴으로써 구분 가능(한쪽 out부분을 floating 상태로)
- floating 상태로 변환하는 기능은 없으며 대신 한쪽 부분을 in 상태로 변환

```cpp
	//키 인식 디바이스 드라이버
	#include "2440addr.h"
	#include "macro.h"

	void Key_Poll_Init(void) //초기화 과정
	{
		//Key_In 0~3(GPF[7:4]), Key_Push(GPF0) : input
		Macro_Write_Block(rGPFCON,0xff,0,8);
		Macro_Write_Block(rGPFCON,0x3,0,0);
		//Key_out0,1(GPC8,9): input
		Macro_Write_Block(rGPCCON,0xff,0,16);
	}

	#define DELAY_VALUE (0x100000)
	#define CHATTERING_CNT (1000)
	int lut[]={1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,0}; //룩업 테이블
	int Key_Get_Pressed(void) //키가 눌렸을 때 눌린 번호 출력
	{
		volatile int i;
		int key;
		//Key_out0 -> 0, Key_out1 ->입력(조이스틱)
		Macro_Write_Block(rGPCCON,0xf,1,16);
		//Key_out0에 0 입력
		Macro_Clear_Bit(rGPCDAT,8);
		for(i=0;i<DELAY_VALUE;i++); //딜레이 발생
		if(Macro_Check_Bit_Clear(rGPFDAT,0)) return 9; //push키 리턴
		key = Macro_Extract_Area(rGPFDAT,0xf,4);
		if(key != 0xf) //키가 눌렷을 때
		{
			//채터링 작업
			for(i=0;i<CHATTERING_CNT;i++)
			{
				if(key!=Macro_Extract_Area(rGPFDAT,0xf,4)) return 0;
			}
			return lut[key];
		}

		//Key_out0 -> 입력, Key_out1 ->0(스위치)
		Macro_Write_Block(rGPCCON,0xf,0x4,16);
		//Key_out1에 0 입력
		Macro_Clear_Bit(rGPCDAT,9);
		for(i=0;i<DELAY_VALUE;i++); //딜레이 발생
		key = Macro_Extract_Area(rGPFDAT,0xf,4);
		if(key != 0xf) //키가 눌렷을 때
		{
			//채터링 작업
			for(i=0;i<CHATTERING_CNT;i++)
			{
				if(key!=Macro_Extract_Area(rGPFDAT,0xf,4)) return 0;
			}
			return lut[key]+4;
		}
		return 0;
	}
	void Key_Wait_Key_Released(void) //눌리는 동안 무한 대기
	{
		while(Key_Get_Pressed());
	}
	int Key_Wait_Key_Pressed(void) //눌리지 않는 동안 무한 대기
	{
		int key;
		while(!(key=Key_Get_Pressed()));
		return key;
	}
```