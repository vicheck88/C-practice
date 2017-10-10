# UART 통신
### UART: Universal Asynchronous Receiver & Transmitter
- UART: 범용 비동기 송수신 장치
- 직렬 vs 병렬
	- 병렬: 많은 수의 데이터 버스를 이용하여 자료를 한 번에 보냄
		- 빠르지만 비쌈
	- 직렬: 작은 수의 데이터 버스를 이용하여 순차적으로 자료를 보냄
		- 느리지만 쌈(특히 원거리)

### 통신 프로토콜
- 장치 간 통신에는 데이터 형식에 대한 규약(protocol)이 필요
- UART의 통신: 직렬 (Frame Format)
	1. 평소 high를 유지하다 low로 떨어지는 start bit 발생
	2. start bit 이후 약속한 수의 data, parity bit 발생
		- 패리티비트를 이용하여 오류를 검출
		- stop bit와 데이터 사이에 위치
		- 최근에는 패리티비트를 별로 사용하지 않음
	3. 전송 완료 시 신호가 high로 올라 stop bit 발생
	4. 다음 데이터는 stop bit이후 start bit가 발생할 때 전송
- UART는 데이터 통신속도(bps - bit per sec)에 따라 비트가 전송됨
	- 2400bps: 초당 2400비트, 1비트 주기: 1/2400초

![msb first](https://learningmsp430.files.wordpress.com/2014/01/w_example.png)

출처: https://learningmsp430.wordpress.com/2014/01/08/serial-communication/