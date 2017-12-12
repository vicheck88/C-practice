# Deadlock
### Deadlock Problem
- 여러개의 프로세스들이 맞물려서 동작하지 않는 상황
- 여러개의 세마포어를 사용할 때, 각 프로세스들이 다른 프로세스에게 필요한 자원을 가져가 더 이상 진행이 안되는 경우

### Bridge Crossing Example

![Bridge Crossing Exmaple](https://image.slidesharecdn.com/process-synchronization-and-deadlocks-119961623287018-3/95/process-synchronization-and-deadlocks-16-728.jpg?cb=1199587433)

출처: https://www.slideshare.net/tech2click/process-synchronization-and-deadlocks

### Deadlock Characterization
- 데드락은 다음 네 조건이 동시에 일어날 때 발생
	- Mutual exclusion: 하나의 프로세스만이 하나의 리소스를 사용할 수 있음
	- Hold and wait: 최소 하나의 리소스를 가진 프로세스가 다른 리소스를 얻기 위해 대기중
	- No preemption: 해당 리소스가 nonpreemptive이어야
		- 중간에 다른 요청이 와도 현재 진행 중인 프로세스를 완전히 끝내야 리소스 반환
	- Circular wait: 프로세스들이 리소스를 통해 서로 물고 물려있음
		- 프로세스0은 1이 가진 리소스를 기다리고, 1은 2가 가진 리소스를 기다리고... n은 0이 가진 리소스를 기다리는 경우

![Deadlock](http://www.geeksforgeeks.org/wp-content/uploads/gq/2015/06/deadlock.png)

출처: http://www.geeksforgeeks.org/operating-system-process-management-deadlock-introduction/

### Methods to Handle Deadlock
- 데드락이 발생하는 환경을 만들지 않음
- 데드락의 필요조건 네가지 중 한가지를 없애버림
- 데드락의 발생 상태를 생각하면서 리소스 분배
- 데드락 발생하면 이를 고침
- 데드락을 무시하고 내버려둠(프로그래머에게 맡김): 지금 운영체제들이 사용하는 방법

### Deadlock Prevention
- 데드락의 조건 네가지중 하나를 깸
- Mutual Exclusion: 공유 불가능한 리소스(프린터 등)에만 적용
	- 일반적으로 없애기 힘든 성질
- Hold and Wait: 가능할 때만 리소스를 요청
- No Preemption: 불가능
- Circular wait: 모든 리소스들에 방향성을 걸어 그 방향으로만 자원을 요구