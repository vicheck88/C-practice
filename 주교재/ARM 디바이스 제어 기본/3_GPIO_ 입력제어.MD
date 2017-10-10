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
		}
	}
```
