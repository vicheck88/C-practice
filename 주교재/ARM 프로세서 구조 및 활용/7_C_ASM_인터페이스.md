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
		ldr		r0, =GPBDAT
		ldr		r1, [r0]
		bic		r1, r1, #(0xF<<7)
		str		r1, [r0]
		mov		pc, lr //함수 다음 값으로 이동

	.global	Asm_Led_Off
	Asm_Led_Off:
		ldr		r0, =GPBDAT
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
- 스택은 push 동작을 기준으로 4가지 타입으로 분류: FA,FD,EA,ED
- ARM에서는 FD 스택을 사용

![stack](https://azeria-labs.com/wp-content/uploads/2017/04/stacks.gif)

출처: https://azeria-labs.com/functions-and-the-stack-part-7/

### LR의 스택 대피
- 레지스터 하나를 스택에 대피시키는 명령
- LR은 스택포인터의 바로 위에 저장한 뒤 스택포인터를 LR위치로 이동
	- `str lr,[sp,#-4]`
- 후에 돌아갈 때 꺼내서 옮김
	- `ldr lr,[sp],#4`

```assembly
	.global	Asm_Print_Good
	Asm_Print_Good:

	str		lr, [sp, #-4]! @현재 스택의 마지막 부분에 LR 저장

	ldr		r0, =GPBCON
	ldr		r1, [r0]
	bic		r1, r1, #(0xFF << 14)
	orr		r1, r1, #(0x55 << 14)
	str		r1, [r0]

	 bl		c_func

	ldr		r0, =GPBDAT
	ldr		r1, [r0]
	orr		r1, r1, #(0xF<<7)
	str		r1, [r0]

	ldr		lr, [sp], #4 @LR 복원
	mov		pc, lr
```

### ATPCS: ARM-Thumb Prodedure Call Standard
- ATPCS: 함수호출규약으로, C에서 함수를 호출하거나 호출받을 때에 대한 규칙
- a1 ~ a4: argument들을 레지스터에 전달
	- r0,r1 레지스터들은 리턴값으로도 사용됨
- v1 ~ v8: 변수(지역변수)들을 레지스터에 전달
- scratch register


![ATPCS](https://github.com/vicheck88/C-practice/blob/master/image/ATPCS.PNG?raw=true)

출처: http://infocenter.arm.com/help/topic/com.arm.doc.espc0002/ATPCS.pdf ,  page 10

### ATPCS에 의한 argument 전달

|변수형|저장|
|---|---|
|`char,short,int,long,float,주소`|r0 ~ r3 register<br/>부족하면 스택 사용(4B align 준수)<br/>4B 미만 데이터는 4B로 확장|
|`long long,double,long double`|[r1:r0] 또는 [r3:r2]<br/>8B 데이터는 r0,r2 align(두 가지 중 하나를 온전히 다 사용) 및 스택의 8B align 주소 준수<br/>4B의 공백 발생 가능: 이를 고려한 argument 배열 필수<br/>실수의 경우, FPU가 있으면 FPU 레지스터로 전달|
|구조체, 공용체 등 대용량 데이터|용량이 부족하면 스택에 연속적으로 저장<br/>분할 저장될 수 있음|
|스택 규정|4B단위 align 유지(함수간에도)<br/>함수 호출 때 SP는 스택에 저장되는 첫 argument 주소(FD 스택 사용)|

```cpp
	void main(void)
	{
		f(1,2,3,4,5,6,7,8);
	}
	void f(int a,int b,int c,int d,int e,int f,int g,int h)
	// r0 ~ r3에 a,b,c,d값이 저장
	// 나머지는 스택에 저장되며 e값이 있는 주소에 스택 포인터 위치
```

### ATPCS에 의한 결과 Return

|변수형|저장|
|---|---|
|`char,short,int,long,float,주소`|r0 register<br/>4B 미만 데이터는 4B로 확장(integral promotion)|
|`long long,double,long double`|[r1:r0]<br/>실수의 경우, FPU가 있으면 FPU 레지스터로 전달|
|4B 이하 구조체, 공용체|r0 register<br/>4B 이하 데이터는 4B로 확장(쓰레기값으로 padding)|
|4B 초과 구조체, 공용체|- 4B 초과 리턴이 필요할 때 caller는 복사받은 주소값을 r0에 전달<br/>- 이로 인해 r0에 저장될 argument는 r1으로 이동하며, argument가 8B크기일 경우 r2로 이동(alignment)<br/>- 호출 받을 때 callee의 r0에 메모리 주소가 저장, 그 후 리턴값을 저장된 주소에 저장하여 리턴|

### Scratch Register
- ARM은 context 보존 책임을 caller,callee가 같이 지고 있음
- scratch register: callee가 마음대로 변경하여도 상관없는 레지스터(r0 ~ r3, r12)
- 따라서 중요한 정보가 scratch register에 있을 때 caller는 자료를 백업해야함
- LR을 제외한 나머지 모든 레지스터는 callee의 책임(lr은 caller의 책임)
- 책임을 분리한 이유
	- Callee가 모든 책임을 가지고 있는 경우
		- Callee가 레지스터를 여러 개 사용할 경우, 레지스터의 모든 내용들을 백업하고 복구해야: 속도가 느려짐
		- 즉, 효율적인 레지스터의 저장을 위해 책임을 나눠둠

### 다중 메모리 이동: `LDM: LDR multiple,STM: STR multiple`
- `LDM,STM`: 여러 개의 메모리와 레지스터들 간 이동
- 일일이 메모리와 레지스터들 값을 교환할 필요가 없음

|형식|`(op)(cond)<mode> Rn,<reg list>`, `(op):LDM,STM`|
|---|---|
||- cond: 조건부 실행 조건<br/>- mode: 주소 계산 방식 지정(8개 모드)<br/>- Rn: 메모리 주소 가지고 있는 레지스터<br/>- reg.list: 레지스터들 목록|

```assembly
	LDMDB	r1,{r1-r4,r12,LR} @r1 ~ r4레지스터, r12,LR 레지스터(-: 범위 지정)
	@주소에 있는 값들 여러개를 읽어들임
	STMNEIA	r0,{r0,r1,r2,SP} @조건부 명령 실행 가능
```

![LDM,STM](https://image.slidesharecdn.com/arminstructionset-160408155037/95/arm-instruction-set-23-638.jpg?cb=1460213268)

출처: https://www.slideshare.net/MathivananNatarajan/arm-instruction-set-60665439

![LDM,STM example](https://image.slidesharecdn.com/arminstructionset-160408155037/95/arm-instruction-set-24-638.jpg?cb=1460213268)

출처: https://www.slideshare.net/MathivananNatarajan/arm-instruction-set-60665439

### `LDM STM` 동작들
- `STM, LDM`의 특성
	- Base Register의 값은 변화 없음
	- `(op)(cond)<mode> Rn!,<reg list>`식으로 느낌표를 붙여주어야 변화
	- Register 리스트의 순서는 상관 없으며, 낮은 주소에 낮은 번호 레지스터 배정
		- 명령어 형식에서, 레지스터 리스트부분에서 순서를 알아낼 수는 없음
		- 레지스터가 있는지 없는지의 유무만을 알 수 있음

![operation](http://www.riscos.com/support/developers/asm/instrset-17.png)

출처:http://www.riscos.com/support/developers/asm/instrset.html

### FD 스택에 PUSH,POP
- FA,FD,EA,ED: PUSH 기준 스택 종류를 지정하는 동작 모드
- PUSH,POP 상관없이 스택 종류만 지정
- 이를 이용하여 서브루틴 호출, 복귀를 동시에 진행 가능

```assembly
	stmfd sp!,{regs,...,LR}
	ldrfd sp!,{regs,...,PC}
```

![LDM,STM in stack](https://image.slidesharecdn.com/arminstructionset-160408155037/95/arm-instruction-set-25-638.jpg?cb=1460213268)
https://www.slideshare.net/MathivananNatarajan/arm-instruction-set-60665439

### 예제
```assembly
	.global  Asm_Add_Sqr
	Asm_Add_Sqr:
	@ int Asm_Add_Sqr(int a, int b)@
	@ {
	@	return (Sqr(a)+Sqr(b))@
	@ }
	@ C의 함수인 Sqr()을 이용

	stmfd sp!,{r4,r5,lr} @r4,r5,lr 저장(scratch register가 아닌 곳)

	mov r5,r1 @r1을 r5로 이동
	bl Sqr
	mov r4,r0 @결과자료 대피이동
	mov r0,r5 @두번째 자료 삽입

	bl Sqr
	add r0,r0,r4
	ldmfd sp!,{r4,r5,pc} @대피자료 복귀
```

### LDR 명령의 데이터 타입 지정
- 레지스터보다 작은 데이터의 LDR/STR을 위해 크기 옵션이 제공됨

|기본 형식|`LDR(STR) {cond}{size} Rn,operand`|
|---|---|
|데이터 타입 지정|- B(unsigned byte),SB(signed byte),H(unsigned short),SH(signed short), 없으면 기본 4B<br/>- STR의 경우 4B 레지스터가 잘라 1B,2B 메모리에 저장: 부호가 의미가 없음<br/>- 따라서 SH,SB 옵션은 없음|

```assembly
	LDR		r0,[r1] @[r1]주소에서 int 로드
	LDRB	r0,[r1] @[r1]주소에서 unsigned byte 로드
	LDRSB	r0,[r1] @[r1]주소에서 signed byte 로드
	LDRH	r0,[r1] @[r1]주소에서 unsigned short 로드
	LDRSH	r0,[r1] @[r1]주소에서 signed short 로드

	LDRSHHS	r0,[r1] @if HS, r0 :=(signed short)[r1]
	LDRBEQ	r0,[r1] @if EQ, r0 :=(unsigned char)[r1]
```

### H,SH,SB 옵션의 제약사항
- LDR,LDRB
	- 사용법이 동일
	- LDRB에서 8비트가 넘는 데이터는 사용 불가
- LDRSB,LDRSH,LDRH
	- 상수 대입, shift 불가
- STR계열
	- STR,STRB,STRH만 사용 가능
- LDM,STM
	- 4B 단위 이동만 가능
- 크기 옵션으로 메모리를 레지스터로 로딩하는 경우 남은 공간 처리
	- unsigned 옵션은 0으로 확장
	- signed 옵션은 부호 확장

### 함수 리턴 타입에 따른 정리
- int리턴이 아니라면 결과 값이 저장된 R0를 정수 승격 시커야
- 리턴값을 저장한 후 다음과 같은 코드 필요
	- unsigned char: 상위 24비트를 전부 0으로
		- `AND R0,R0,#0x000000FF`
	- unsigned short: 상위 16비트를 전부 0으로
		- `AND R0,R0,#0x0000FFFF`: 불가능(\#으로 표현 불가)
		- `MOV R0,R0,LSL #16`,`MOV R0,R0,LSR #16`코드 작성
	- signed char, short: 상위 비트를 원래 값의 부호 값으로 확장
		- `MOV R0,R0, LSL #24`.`MOV R0,R0, ASR #24`: signed char
		- `MOV R0,R0, LSL #16`,`MOV R0,R0, ASR #16`: signed short
- int가 아닌 값을 리턴할 경우, 최적화에서 불리: 여분의 코드가 필요
- 따라서 (un)signed int값으로 리턴하는 것이 가장 효율적

### C의 전역변수, 배열, 포인터 공유
- 함수처럼 `.extern`을 선언: ASM에서는 변수들의 주소로 사용 가능

```assembly
	.extern uc @unsigned char uc
	.extern	sc @signed char sc
	.extern	us @unsigned short us
	.extern	ss @signed short ss

	.global 	Asm_Var_Unsigned_Char
Asm_Var_Unsigned_Char:

	ldr 	r1, =uc
	ldrb	r0, [r1] @변수들의 주소를 이용
	add	 r0, r0, #1
	strb	r0, [r1]
	ldrb	r0, [r1]
	mov 	pc, lr

	.extern	a @int a
	.extern	p @int *p
	.extern  x @int x[4]

	.global	Asm_Var_Access
Asm_Var_Access:
	
	@int a, a+1 표현
	ldr		r0, =a
	ldr		r1, [r0]
	add		r1, r1, #1
	str		r1, [r0]
	@int *p, (*P)+1 표현
	ldr		r0, =p
	ldr		r0, [r0]
	ldr		r1, [r0]
	add		r1, r1, #1
	str		r1, [r0]
	
	@int x[4], 각 배열 요소의 값을 1씩 증가
	mov		r2, #4
	ldr		r0, =x
1:
	ldr		r1, [r0]
	add		r1, r1, #1
	str		r1, [r0], #4
	subs	r2, r2, #1
	bgt		1b

	mov		pc, lr
```
