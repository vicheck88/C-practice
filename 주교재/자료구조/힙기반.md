# 힙 기반 선형 자료구조
## 연결 리스트
### 힙 기반 linked list
- 배열 기반 리스트는 자료가 한 곳에 모인다는 점에서 장점이 있지만, 자료의 수를 동적으로 조절하는 것은 불가능
- 이를 개선하기 위해 Heap 메모리를 이용
	- 노드를 배열이 아닌 힙에 생성: 거의 무제한으로 생성이 가능
	- 항상 최대 자료수 만큼의 버퍼를 확보할 필요 없이, 때마다 동적으로 버퍼를 확보
	- 자료가 비선형적으로 저장되는 문제 발생
- 임베디드 시스템의 경우, 제한적으로 사용
	- 자료가 비선형적으로 존재할 경우, 메모리 저장이 불편하고 크기 예측이 어려우며 힙 할당으로 인한 낭비 등의 문제가 생김
	- 때문에 배열기반을 주로 사용하거나, 힙을 초기에 최대 요소수 만큼 할당 받아 사용

```cpp
int Insert_Node(SCORE * head, SCORE * d) //노드 삽입
{
	for (;;) //최대값이 정해지지 않았으므로 무한루프 이용
	{
		if (head->next == NULL || head->next->id > d->id) //삽입할 자리를 찾은 경우
		{
			SCORE *p = calloc(1, sizeof(SCORE));
			// calloc을 통해 0으로 초기화된 힙공간을 할당받음(배열기반과의 차이점)
			*p = *d; // 입력값을 힙 메모리에 저장
			if (p == NULL) return -1;

			p->next = head->next;
			head->next = p;
			return 1;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
	}
}
```
```cpp
int Delete_Node(SCORE * head, int id) //노드 삭제
{
	SCORE *p; //임시로 주소를 저장할 변수 설정
	for (;;)
	{
		if (head->next == NULL) return -1;
		if (head->next->id == id)
		{
			p = head->next; //삭제할 노드 주소를 임시로 저장
			head->next = head->next->next; //삭제 노드 전후의 링크 조절
			free(p); //삭제할 노드 삭제 (힙 메모리 해제)
			return 1;
		}
		head = head->next;
	}
}
```

### 이중링크 자료
```cpp
int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE *p;
	for (;;)
	{
		if (head->next == NULL || head->next->id > d->id)
		{
			p = calloc(1, sizeof(SCORE));
			if (p == NULL) return -1;
			*p = *d;
			p->prev = head; //prev, next 링크를 서로 연결하는 과정
			p->next = head->next;
			if (head->next) head->next->prev = p; //마지막 부분에 링크하는 경우
			head->next = p;
			return 1;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
	}
}
```
```cpp
int Delete_Node(SCORE * head, int id)
{
	SCORE *tmp;
	tmp = Search_Id_Node(head, id); //삭제하고자 하는 노드를 찾음
	if (tmp == NULL) return -1;
	
	tmp->prev->next = tmp->next; // 삭제노드 주변의 링크들을 서로 연결
	if (tmp->next) tmp->next->prev = tmp->prev; //삭제노드가 마지막이 아닐경우
	free(tmp); //노드 삭제
	return 1;
}
```

## 스택과 큐
### 힙 기반 스택
- 배열 기반 스택의 경우, 스택의 크기가 고정됨
- 자료가 가변적으로 늘어나는 경우, 힙을 구현하여 문제를 해결
- PUSH동작에는 힙에 자료를 계속 생성하며, POP 동작시에 자료를 free시켜 제거
- 힙 기반 스택은 기본 구조는 링크드 리스트이면서, 운영은 스택처럼 하는 것
- SP의 기본값은 NULL이며, 항상 제일 나중에 추가된 자료를 지시
- POP 동작시 최근 자료부터 삭제하며 모든 자료가 삭제될 때 SP는 다시 NULL로 회귀
- SP는 연결 리스트에서의 tail 역할을 수행한다고 생각할 수 있음

```cpp
int Push_Stack(STACK *data) //PUSH 작업
{
	STACK *p = calloc(1, sizeof(STACK));
	if (p == NULL) return -1;
	*p = *data;
	p->prev = Sptr; //새 자료의 이전주소 입력
	Sptr= p ; //스택 포인터 변화
	return 1;
}
```
```cpp
int Pop_Stack(STACK *p) //POP 작업
{
	STACK *tmp=Sptr; //스택 포인터 주소 백업
	if (tmp == NULL) return -1;
	*p = *Sptr;
	Sptr = Sptr->prev; //스택 포인터 변화
	free(tmp); //POP한 자료 삭제
	return 1;
}
```
```cpp
int Count_Full_Data_Stack(void)
{
	int cnt = 0;
	STACK *tmp = Sptr;
	while (tmp)
	{
		cnt++;
		tmp = tmp->prev;
	}
	return cnt;
}
```
```cpp
int Print_Stack(void)
{
	STACK *tmp = Sptr;
	while (tmp)
	{
		printf("%d\n", (*tmp).num);
		tmp = tmp->prev;
	}
	return Count_Full_Data_Stack();
}
```

### 힙 기반 Linear Queue
- 배열기반 Linear, Circular Queue는 버퍼 크기를 늘리기 힘듬
- 힙 기반에서는 스택과 마찬가지고 버퍼의 제약없이 Queue 설계 가능
- 이 경우, linear방식으로만 설계
- 스택과 마찬가지고 linked list로 설계하며 큐처럼 운영
- Rdptr은 가장 오래전에 생성된 자료를 가리킴 (기존의 Head)
- Wrptr은 가장 최근에 추가된 자료를 가리킴 (기존의 Tail)

```cpp
int In_Queue(QUEUE * data) //enqueue 작업
{
	QUEUE *q = calloc(1, sizeof(QUEUE));
	if (q == NULL) return -1;
	*q = *data;

	(Wrptr == NULL) ? (Rdptr = q) : (Wrptr->next = q);
	//입력값이 없을경우 Rdptr도 이동. 있을 경우 q를 다음 값으로 지정
	Wrptr = q;
	Wrptr->next = NULL; //최근값이므로 next부분을 0로 만듦
	return 1;	
}
```
```cpp
int Out_Queue(QUEUE * p) //dequeue 작업
{
	QUEUE *tmp = Rdptr;
	if (Rdptr == NULL) return -1; //읽을 값이 없을 경우
	*p = *Rdptr;
	Rdptr = Rdptr->next;
	if (Rdptr == NULL) Wrptr = NULL; 
	// 더 이상 읽을 값이 없을 경우 Wrptr 역시 같은 방향으로 이동
	free(tmp); //읽은 값 삭제
	return 1;
}
```
```cpp
int Print_Queue(void)
{
	int cnt=0;
	QUEUE *tmp = Rdptr;
	for (;;cnt++)
	{
		if (tmp == NULL) return cnt;
		printf("num:%d   adrress: 0x%p   next: 0x%p\n", tmp->num, tmp, tmp->next);
		tmp = tmp->next;
	}
}
```
```cpp
int Count_Full_Data_Queue(void)
{
	int cnt = 0;
	QUEUE *tmp = Rdptr;
	for (;;cnt++)
	{
		if (tmp == NULL) return cnt;
		tmp = tmp->next;
	}
}
```