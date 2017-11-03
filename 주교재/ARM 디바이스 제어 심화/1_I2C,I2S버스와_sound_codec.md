# I2C, I2S 버스와 Sound CODEC
### I2C: Inter - IC BUS
- IC 소자간 저속 통신을 위한 직렬 버스
- 하나의 프로세서에 여러 IC를 2선만으로 연결: 간단하고 저렴
- 오디오, 비디오 관련 소자들과 프로세서간 통신에 많이 이용
- SCL(SCLK): 클락, SDA: 양방향 데이터(반이중 방식: half duplex)
- 1:N 통신(master - slave)이 목적이지만 multi master방식도 지원(master: 클락을 공급하는 장치)

![I2C버스](http://howtomechatronics.com/wp-content/uploads/2015/10/I2C-Communication-How-It-Works.png)

출처: http://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/

### 프로토콜
- 기본적으로 8비트 단위 MSB first로 통신

![protocol](http://i2c.info/wp-content/images/i2c.info/7-bit-address-writing.gif)

출처: http://i2c.info/i2c-bus-specification

### 확장 주소 방식

- 통신 단위를 2B로 확장하기도 함
	- master,slave 간 약속이 필수
	- 첫 부분은 노드 주소, 다음은 접속하는 레지스터 (write)
	- Read작업일 경우, 두번째 주소 뒤에 처음 7bit 주소를 추가적으로 전송

![protocol - extended](https://github.com/vicheck88/C-practice/blob/master/image/i2c%20protocol%20extended.PNG?raw=true)

출처: https://www.nxp.com/docs/en/user-guide/UM10204.pdf

