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
- Data bit 수, parity 유무, stop bit 수 등에 따라 frame format이 달라짐
- UART는 데이터 통신속도(bps - bit per sec)에 따라 비트가 전송됨
	- 2400bps: 초당 2400비트, 1비트 주기: 1/2400초
- 인식하는 통신 속도가 다를 경우, 데이터를 주고 받을 때에 문제가 생김므로, 사전에 약속된 통신 속도로 데이터를 주고 받아야 함

![msb first](https://learningmsp430.files.wordpress.com/2014/01/w_example.png)

출처: https://learningmsp430.wordpress.com/2014/01/08/serial-communication/

### 동기 vs 비동기
- 동기(synchronous) 통신
	- 데이터와 clock를 같이 제공, 수신측에서 clock에 따라 데이터를 인식
	- 데이터를 취득해야하는 시기를 송신측에서 통보: 통신속도에 대한 합의가 필요 없음
	- 데이터를 인식하는 시점을 같이 제공: 고속, 원거리 송신에 적당
	- 비용이 많이 듬
- 비동기(asynchronous) 통신
	- 데이터만 전송하고 clock은 전송하지 않음
	- 송수신측은 각각의 clock에 따라 데이터를 주고 받음
	- 통신속도에 대한 정확한 합의가 필요
	- 데이터 폭이 좁아지거나 넓어질 때 문제 발생 가능
	- 저속, 근거리 송수신에 적합하며 데이터만 전송: 저렴

### 송수신 방식과 parity
- UART는 다음 3개 신호를 통해 데이터 송수신이 가능
	- TxD: 데이터 송신, RxD: 데이터 수신, GND: 신호 레벨 맞추는 기본 전압
- UART는 전이중 통신(Full Duplex)이 가능
	- 데이터를 주고 받는 신호가 서로 다름: 동시에 주고 보내는 동작이 가능해짐
- parity bit를 통해 수신 데이터의 오류 판단
	- parity: 옵션으로 선택시 데이터 뒤에 추가됨
	- even parity: 자료와 패리티의 1의 개수가 짝수가 되도록
	- odd parity: 1의 개수가 홀수가 되도록
	- 단점
		- 에러난 부분의 위치를 알 수 없음
		- 에러가 여러개 난 경우, 데이터의 오류 여부 판단 불가

![UART](https://sites.google.com/site/avrtutorials2/06-serial-link-full.gif)

출처: https://sites.google.com/site/avrtutorials2/serialport

### Flow Control
- 송신측에서 데이터를 너무 빨리 보내 수신측이 처리를 못하는 경우가 발생 가능
- RTS,CTS 등의 흐름제어 신호를 통해 문제 해결
	- RTS: Request To Send
		- 데이터 수신이 가능한 상태일 때 Active 신호 발생
		- 상대편의 CTS에 연결: 요청을 수신하여 자료 전송
	- CTS: Clear To Send
		- Active 상태일 때만 데이터 전송이 가능
- AFC(Automatic FC): 하드웨어가 플로우 컨트롤을 자동으로 행함

![Flow Control](http://mgrfq63796.i.lithium.com/t5/image/serverpage/image-id/4046i6C69F30F4790C3CD?v=mpbl-1)

출처: http://community.silabs.com/t5/Bluetooth-Wi-Fi-Knowledge-Base/REFERENCE-Using-or-bypassing-flow-control-with-UART/ta-p/147683

### RS232C 통신
- UART 장치를 이용하여 통신을 하는 대표적인 방식
- PC와 모뎀을 결선할 때 사용
- 근거리 정도 거리까지 송수신이 가능한 통신 방식
- 전압 감쇄 등의 문제로 인해 직접 통신하는 것은 무리
- 신호가 멀리 갈 수 있도록 변조하는 과정 필요
	- 변조: 원래 신호를 전기적으로 변환하는 방식
	- AM(Amplitude Modulation): 진폭변조, FM(Frequency Modulation): 주파수 변조
	- 전압의 진폭을 넓힐 경우, 전압 감쇄에도 안전하게 데이터 전송 가능
	- RS232C Modulation이라고 부름
	- 수신 측은 이를 복조하여 원래 정보로 변환

![RS232C modulation](https://arcelect.com/RS232_signals.gif)

출처: https://arcelect.com/rs232.htm