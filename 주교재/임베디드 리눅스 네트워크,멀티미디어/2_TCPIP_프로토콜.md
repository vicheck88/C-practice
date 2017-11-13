# TCP/IP 프로토콜
## 이더넷 프로토콜
### 이더넷 프레임

![Ethernet Frame](http://imgur.com/qWZ0H.png)

출처: http://www.firewall.cx/forum/2-basic-concepts/38119-bpdu-frame-formatting.html

- 이더넷 프레임: 처음 데이터가 전송될 때의 모습
- 프리앰블: 10101010 반복되는 필드
	- 수신 측에 프레임의 시작을 알림, 동기신호를 제공
- SFD(Start Frame Delimeter): 프레임의 시작을 알림(10101011)
- 목적지 MAC 주소(Destination)
	- 2계층의 주소 제공. 앞 3B는 제조사, 뒤는 제조사의 고유 일련번호
	- 6B의 모든 비트가 1일 경우 브로트캐스트, 첫비트가 1이면 멀티캐스트	
- 출발지 MAC 주소(Source Address)
	- 출발지 이더넷 포트의 MAC 주소
- 길이/타입(2B): MAC Control Type의 뒤 2B
	- 데이터필드의 길이 또는 MAC 클라이언트 프로토콜을 나타냄
- 데이터(payload): 46B ~ 1500B
	- 데이터가 46B 이하일 경우 패딩 바이트를 채워 46B로 만듦
- FCS(Frame Check Sequence): 에러검출

### IP(Internet Protocol)
- IP Address
	- 네트워크 계층에서 사용되는 주소를 정의
	- 인터넷에서 호스트를 구별하기 위한 논리적인 주소(MAC: 물리적 주소)
	- 패킷을 전달할 경로를 지정함
- IP Address 구성(네트워크 ID+호스트 ID)
	- 네트워크 ID: 네트워크를 구분하는데 사용
	- 호스트 ID: 네트워크 내에서 호스트를 구분하는데 사용

![IP Address](http://www.software-engineer-training.com/wp-content/uploads/2007/09/ipaddressclasses.jpg)

출처: http://software-engineer-training.com/internetworking-and-the-internet-protocol/

### IP Datagram
- 이더넷 프레임에서 처음, 마지막 부분을 제거
- http://wooguy-tcpip.blogspot.kr/2013/10/blog-post_7.html 참조

![IP Datagram](https://docstore.mik.ua/orelly/networking_2ndEd/tcp/figs/tcp3_0105.gif)

출처: https://docstore.mik.ua/orelly/networking_2ndEd/tcp/ch01_05.htm