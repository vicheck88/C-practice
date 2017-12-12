# CPU Scheduling
## Basic concept
### CPU Scheduler
- ready 상태인 프로세스 중 하나를 고르는 방법
- 스케쥴링이 일어나는 경우
	- running에서 waiting으로 상태가 바뀔 경우
	- running에서 ready로 상태가 바뀔 경우
	- waiting에서 ready로 상태가 바뀔 경우
	- 종료(Termination)
- 첫번째, 네번째 경우는 nonpreemtive scheduling이라고 부름(자발적으로 자원을 내놓는 경우)
- 나머지는 preemtive scheduling이라고 부름(자원이 필요하지만 비자발적으로 자원을 내놓은 경우)

### Scheduling Criteria
- CPU utilization: CPU를 가능한 한 바쁘게
- Throughput: 단위 시간당 완료하는 프로세스의 양
- Turnaround time: 특정 프로세스가 시작해서 종료될 때 까지 걸린 시간
- Waiting time: ready queue에서 대기한 시간의 총계
- Response time: 요청한 작업이 실제로 작업을 시작할 때까지 걸린 시간

### First-Come, First-Served (FCFS) Scheduling
- 먼저 온 프로세스를 먼저 처리하는 알고리즘
- 순서에 따라 성능의 편차가 굉장히 심함: 좋은 알고리즘이 아님

![FCFS1](http://www.geeksforgeeks.org/wp-content/uploads/FCFS.png)

출처: http://www.geeksforgeeks.org/program-fcfs-scheduling-set-1/

### Shortest-Job-First (SJF) Scheduling
- 실행에 가장 시간이 적게 걸리는 프로세스를 우선적으로 실행
- 먼저 온 프로세스를 실행하되, 뒤에 오는 프로세스들과 실행 시간을 비교, 더 짧은 프로세스를 우선적으로 실행
- nonpreemtive, preemtive 방식이 있음
- optimal: 최소한의 average waiting time 제공

![SJF](https://i.stack.imgur.com/3VAWz.png)

출처: https://cs.stackexchange.com/questions/35723/can-shortest-job-first-scheduling-be-subject-to-convoy-effect

### Priority Scheduling
- 프로세스마다 우선순위를 부여, 가장 우선순위가 높은 프로세스를 먼저 실행
- nonpreemtive, preemtive 방식이 있음
- SJF는 실행시간의 크기를 통해 우선순위를 부여하는 방식에 해당
- 우선순위가 낮은 프로세스의 경우 실행이 제대로 되지 않을 수 있음
- 해결: 시간이 지나도 프로세스가 실행되지 않을 경우 프로세스의 우선순위를 점점 높여줌

### Round Robin
- 모든 프로세스가 일정 시간만큼 나눠서 자원 할당
- waiting time이 일정
- SJF에 비해 response time이 짧음
- 하지만 turnaround time이 SJF 방식보다 긺

![Response time](http://www.geeksforgeeks.org/wp-content/uploads/Round-Robin.jpg)

출처: http://www.geeksforgeeks.org/program-round-robin-scheduling-set-1/

### Multilevel Queue
- Ready queue를 여러 큐로 분해한 후 큐들 간의 우선순위를 부여
- 우선순위가 높은 큐를 먼저 수행
- 큐 안의 프로세스들은 Round Robin 방식을 이용하여 스케쥴링

![Multilevel queue](https://www.cs.rutgers.edu/~pxk/416/notes/images/07-mqueue.png)

출처: https://www.cs.rutgers.edu/~pxk/416/notes/07-scheduling.html

### Multilevel Feedback Queue
- 큐 안 프로세스의 우선순위를 변화시킴
- 큐 안을 Round Robin으로 수행 후 끝나지 않은 프로세스들은 우선순위가 낮은 큐에 배정

![Multilevel Feedback queue](https://worldfullofquestions.files.wordpress.com/2014/07/multilevel-feedback-queue-scheduling.png)

출처: https://worldfullofquestions.wordpress.com/tag/multilevel-feedback-queue-scheduling/

![Multilevel Feedback queue2](https://image.slidesharecdn.com/csc4320chapter5-2-101203002830-phpapp01/95/scheduling-algorithms-28-728.jpg?cb=1291336136)

출처: https://www.slideshare.net/Chankey007/scheduling-algorithms-6013407