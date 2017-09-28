# C-ASM 인터페이스
### Visual Studio의 calling convention
- `__cdecl vs __stdcall`
	- 스택을 정리하는 방법이 다름

```cpp
	int __cdecl add(int a,int b)
	//(add(3,4,5))에서 정상적인 결과 도출
	{
		printf("%X : %X : %d\n",&a,&b,(&a)[2]);
		return a+b;
	}

	int __stdcall add(int a,int b)
	//(add(3,4,5))에서 정상적인 결과를 도출하지만 끝나고 런타임 에러 발생
	//스택포인터의 상황에 문제가 생긴 상황
	{
		printf("%X : %X : %d\n",&a,&b,(&a)[2]);
		return a+b;
	}

	void main(void)
	{
		printf("%d\n",add(3,4,5));
	}
```

### `__cdecl vs __stdcall`
- 스택을 정리하는 방법에 차이가 있음
- `__cdecl`
	- add에서는 리턴값만 리턴하고 스택포인터는 add 함수에 남아 있음
	- main함수에서 스택포인터를 정리하는 역할 수행
	- 위 예제에서, main함수는 인자가 3개임을 알고 있으므로 스택포인터를 인자 3개만큼 이동시킴: 제대로 작동
	- 즉, 호출한 쪽(caller, main)에서 스택포인터를 정리

![__cdecl](http://2we26u4fam7n16rz3a44uhbe1bq2.wpengine.netdna-cdn.com/wp-content/uploads/120912_1254_CallingConv1.png)

출처: http://resources.infosecinstitute.com/calling-conventions/#gref

- `__stdcall`
	- add에서는 마지막에 결과값을 리턴하면서 동시에 스택포인터에 값을 더함
	- 이 때, add함수에 저장된 인수는 2개이므로 스택포인터를 인자 2개만큼 이동시키며 main으로 복귀: main에는 인수가 3개이므로, 제대로 작동하지 못함
	- 즉, 호출당한 쪽(callee, add)에서 스택포인터 정리

![__stdcall](http://2we26u4fam7n16rz3a44uhbe1bq2.wpengine.netdna-cdn.com/wp-content/uploads/120912_1254_CallingConv2.png)

출처: http://resources.infosecinstitute.com/calling-conventions/#gref

- `__cdecl`의 특징
	- 인자의 수가 많아도 에러 없이 프로그램 수행 가능
	- 가변인자를 사용할 수 있음
	- 같은 함수라도 여러번 함수 호출이 있을 때마다 스택 정리 코드 역시 호출되어야 함

- `__stdcall`의 특징
	- 스택 정리 코드는 함수 한 번 당 한 번만 호출되면 됨: 코드 절약
	- 인자의 수가 다를 때 프로그램 수행 불가(런타임 에러)
	- 가변인자 사용 불가
- 두 가지 방법 중 어느 방법이 기본값인지는 컴파일러에 의존: 컴파일러에서 기본값 변경 가능

![__cdecl vs __stdcall](http://cfile10.uf.tistory.com/image/263C353F51DCF1E81AAD56)

출처: http://blog.mosaicstory.net/93

### 서브루틴 호출과 복귀 명령
- 서브루틴 호출 때: LR에 복귀주소를 저장하고 PC에 분기 주소를 지정
- 서브루틴 종료 때: PC에 복귀주소(LR 값)을 입력
- 함수호출이 다단계로 Nesting될 경우(중첩 호출), LR 역시 스택에 저장해야 함

### ASM 함수 호출
- C에서는 어셈블리 함수를 외부 함수처럼 사용: `extern` 이용
- 어셈블리에서는 `.global` 선언으로 외부 참조가 가능하도록 허용

```assembly
	@어셈블리
	.global	Asm_Led_On
	Asm_Led_On:

		ldr 	r0, =GPBDAT
		ldr		r1, [r0]
		bic		r1, r1, #(0xF<<7)
		str		r1, [r0]
		mov		pc, lr //함수 다음 값으로 이동

	.global	Asm_Led_Off
	Asm_Led_Off:

		ldr 	r0, =GPBDAT
		ldr		r1, [r0]
		orr		r1, r1, #(0xF<<7)
		str		r1, [r0]
		mov		pc, lr
```
```cpp
	//C언어
	extern void Asm_Led_On(void); //어셈블리 명령어를 외부 함수로 사용
	extern void Asm_Led_Off(void);

	int Main(void)
	{
		int i;
		Sys_Init("\nAPCS, C-ASM Interface Test #1\n");
		// ASM 함수 호출 기본
		for(i=0; i<5; i++)
		{
			Asm_Led_On(); //어셈블리의 서브루틴을 함수로 활용
			Delay(1000);
			Asm_Led_Off();
			Delay(1000);
		}
		Uart_Printf("\nReturned!\n");
		return 0;
	}
```

### C -> ASM -> C 호출
- 여러번 호출하는 경우에는 Link Register값에 유의해야함

```cpp
	extern void Asm_Print_Err(void);

	void c_func(void)
	{
		Uart_Printf("C-Function!\n");
	} //3. 어셈으로 복귀

	int Main(void)
	{
		Sys_Init("\nAPCS, C-ASM Interface Test #2\n");

		// C -> ASM -> C 함수 호출
		Asm_Print_Err(); // 1.어셈블리 호출(LR 변경)
		Uart_Printf("\nReturned!\n");

		return 0;
	}
```
```assembly
	.extern c_func

	.global	Asm_Print_Err
	Asm_Print_Err:

		ldr		r0, =GPBCON
		ldr		r1, [r0]
		bic		r1, r1, #(0xFF << 14)
		orr		r1, r1, #(0x55 << 14)
		str		r1, [r0]

		 bl		c_func @2. C 함수 호출(c_func)(LR 재변경)

		ldr		r0, =GPBDAT @4. 복귀값
		ldr		r1, [r0]
		orr		r1, r1, #(0xF<<7)
		str		r1, [r0]
		mov		pc, lr @5. lr값이 달라져 bl 이후 구문으로 이동
```

- 함수가 중첩되어 링크 레지스터의 내용이 망가짐
	- 스택에 임시 보관하여 필요할 때 꺼내야 함

### Context Switching
- Context: 환경 또는 상황정보
	- Caller와 Callee는 동작 환경이 서로 다름
	- 함수 전환 시 해당 함수의 환경이 유지되어야
	- Callee와 Caller는 환경을 복원해야 하는 어느정도의 책임을 각자 가지고 있음
- 함수의 context
	- Caller가 사용하던 레지스터
	- Callee 호출 직전의 스택 위치
	- CPSR의 복원은 필요 없음
- LR과 PC
	- Caller의 복귀 위치로 PC값이 변경되어야 환경이 유지
	- Callee가 다른 함수를 호출할 경우, 환경 복구가 불가: 리턴 불가
	- 다른 함수를 호출하기 전 LR 값을 스택에 저장해놓아야

### 스택의 분류
