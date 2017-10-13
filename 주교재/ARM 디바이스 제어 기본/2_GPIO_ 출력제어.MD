# GPIO 출력 제어
### GPIO 핀
- GPIO(General Purpose Input & Output): 프로세서에서 원하는 논리 레벨을 출력하거나 입력 상태를 읽을 수 있는 핀
- High(1,3.3V) 또는 Low(0,0V) 등 출력
- 입력: 외부 핀 상태가 High인지 Low인지를 인식

### GPIO 핀들의 그룹 Port
- ARM은 한번 읽고 쓸 때 32비트를 한번에 처리
- 한 번의 GPIO 제어를 위하여도 32비트를 읽고 써야함
- 여러 핀들을 묶어 관리를 편하게 함
- 그룹을 Port라고 하며 임베디드 프로세서는 많은 포트로 구성되어 있음
- 같은 포트에 있는 핀들은 개별 접근 불가: 동시에 데이터를 읽거나 써야 함

### Multifunctional GPIO Pin
- S3C2440A는 289개의 핀으로 구성되며 이중 130개를 GPIO 핀으로 사용
- GPIO 핀들은 다른 주변장치의 핀들과 함께 공유하도록 설계됨
- 따라서 GPIO를 사용하기 위해서는 원하는 GPIO 용도로 핀을 사용하도록 선택해야 함(Mux를 이용하여 사용하고자 하는 용도를 선택)
	- GPIO 사용을 위한 선택
        - GPIO 입력, 출력, 다른 주변장치 중 하나 선택 (GPBCON: MUX 설정)
        - GPIO 출력으로 사용할 경우 출력값 결정(0 or 1) (GPBDAT)
        - 칩셋에서 led 1 ~ 4는 GIPO 7 ~ 10 비트에 해당
        - 각 레지스터에서 원하는 부분의 값을 설정
- 원하는 부분의 비트만을 조작할 수 있도록 비트 연산을 수행
- 프로세서 레지스터의 값(`#define`)은 주로 제조사에서 제공
- S3C2440칩은 `2440addr.h` 파일에 해당 주소가 저장되어 있음
- 일일히 주소를 정의하지 않고 이 파일을 이용하여 활용 가능
- 매크로를 이용하면 같은 동작을 좀 더 쉽게 수행 가능

![핀 공유](http://1.bp.blogspot.com/-aUNR9ro4pS8/UzO0wJs0F1I/AAAAAAAAAPo/QjjyFYsa5h0/s1600/dt_pinmux.png)

출처: http://blog.naver.com/PostView.nhn?blogId=ham9627&logNo=220565656620&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

```cpp
	#define GPBCON (*(volatile unsigned *)0x56000010)
	#define GPBDAT (*(volatile unsigned *)0x56000014)

	void Main(void)
	{
		GPBCON = (GPBCON & ~(0xff<<14)) | (0x55<<14);
		GPBDAT = (GPBDAT & ~(0xf<<7)) | (0x6<<7); 
		//GPIO 설정
		for(;;);
	}
	
	//제조사에서 제공하는 파일 이용
	#include "2440addr.h"
	//rGPBCON,rGPBDAT 항목으로 메모리 주소 저장되어있음
	void Main(void)
	{
		rGPBCON = (rGPBCON & ~(0xff<<14)) | 0x55<<14;
		rGPBDAT = (rGPBDAT & ~(0xf<<7)) | 0x6<<7;

		for(;;);
	}

	//매크로 이용
	#include "2440addr.h"
	#include "macro.h"

	void Main(void)
	{
		volatile int i; //컴파일러의 최적화 방지

		// LED를 출력 포트로 설정하고 초기에 LED1, LED3 ON
		Macro_Write_Block(rGPBCON, 0xff, 0x55, 14);
		Macro_Write_Block(rGPBDAT, 0xf, 0xa, 7);

		for(;;)
		{
			// GPB10~7을 반전시킨다
			Macro_Invert_Area(rGPBDAT, 0xf, 7);
			for(i=0; i<0x1000000; i++);
		}
	}
```

### LED 디바이스 드라이버 설계
- LEB를 활용하기 위한 디바이스 드라이버 함수를 Led.c 파일에 설계

```cpp
	#include "2440addr.h"
	#include "macro.h"
	#include "device_driver.h"

	void Led_Init(void)
	{
		// LED(GPB10~7)을 출력으로 설정하고 초기에 모두 OFF한다
		Macro_Write_Block(rGPBCON, 0xff, 0x55, 14);
		Macro_Set_Area(rGPBDAT, 0xf, 7);
	}

	void Led_Display(int disp)
	{
		// disp 값에 따라 LED를 제어한다
		int value=Macro_Extract_Area(~disp, 0xf, 0);
		Macro_Write_Block(rGPBDAT, 0xf, value, 7);
	}
	
	void Main(void) //검증 코드
	{
		int cnt = 0;
		volatile int i;

		Led_Init(); //초기화

		for(;;)
		{
			Led_Display(cnt++); //불이 원하는대로 들어오는지 검토
			for(i=0; i<0x2000000; i++);
		}
	}
```