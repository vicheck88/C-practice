# 배열 기반 선형 자료구조
## 순차 리스트
### 자료처리
- 기계에서 자료를 어떻게 관리, 처리할까 고민하는 것
- 주요 동작
	- 자료생성: 관리 자료를 모델링하며, 주로 구조체를 활용
	- 자료보관: 비휘발성 메모리에 기록: 자료는 비휘발성이어야 함
	- 자료활용: 원하는 자료의 탐색, 변경, 삭제 등의 동작을 수행

### 자료구조
- 자료구조: 자료를 효율적으로 관리, 활용하기 위한 시스템
- 관리, 활용, 가공할 데이터를 보관하기 위한 시스템 의미
- 자료구조 형태
	- 선형 구조: 자료들이 열을 지어서 저장되느니 구조(list, stack, queue 등)
	- 비선형 구조: 자료들이 산발적으로 존재하는 구조
	- 파일 구조: 파일 시스템의 형식으로 저장되어 존재하는 방법

### 배열기반 sequence list
- 순차리스트: 배열 요소번호가 곧 정렬된 자료의 순서
- 기본 자료를 구조체 등으로 만들고, 이들 전체는 배열에 저장
	- 배열에 있어 관리에 유리
	- 데이터가 모여있으므로 쓰기/읽기가 편리
	- 최대 자료 개수가 미리 지정되어있는 경우의 시스템에 유리

```cpp
typedef struct _score // score 타입 생성
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST	20

SCORE exam[MAX_ST]; // 자료를 저장할 Buffer 생성

SCORE test[10] = {{10, 50, "kim"}, {2, 80, "lew"}, {8, 50, "lew"}, {4, 45, "lee"}, {1, 90, "song"}, {3, 45, "kim"}, {5, 50, "song"}, {9, 100, "lee"}, {7, 75, "moon"}, {6, 90, "park"}}; 

void Make_Test_Data(int n) // 데이터를 저장할 함수 설계
{
	int i;

	for(i=0; i<n; i++)
	{
		exam[i] = test[i];
	}
}
```

## 연결 리스트
### Singly Linked List
- 순차리스트의 단점
	- 순서대로 자료가 정렬되어야 함: 자료의 이동이 빈번
- Linked List: 배열 요소(구조체)의 위치는 그대로 두고 이들 간의 정렬 순서만을 정함
	- 자료들 간에 Link를 만들어 앞, 뒤 관계를 연결하는 방식
	- 자료를 Node, 연결주소를 Link라고 부름
	- 첫 자료가 다음에 위치할 자료의 주소를 구조체 멤버로 가지고 있음
	- 다음 자료가 메모리에 연속할 필요가 없어 좀 더 효율적
	- 자기참조구조체를 통해 linked list 구현
	- singly linked: 다음으로 이어지는 자료의 정보(next)만을 포함
	- doubly linked: 이전 자료의 정보(prev)도 포함
		- head와 tail이 연결될 경우, 자료는 원형(circular)

![Singly Linked list.PNG](.\image\Singly Linked list.PNG)


### 자료의 추가와 삭제
- 추가: 새 자료가 들어갈 위치를 찾은 뒤, 앞뒤 링크를 변경하여 추가

![Singly Linked_insert.PNG](.\image\Singly Linked_insert.PNG)


- 제거: 삭제될 자료를 찾은 뒤 앞의 링크를 변경

![Singly Linked_delete.PNG](.\image\Singly Linked_delete.PNG)

### 구현
- list의 처음(head)를 먼저 구현
	- Head 구조체의 내용은 의미가 없으며, 오직 다음 구조체의 주소를 저장하는 용도로 사용함
	- Head 구조체는 배열과 별도로 선언
	- 그 후, 주소를 통해 배열들을 서로 연결, list 생성
- while, 혹은 for 문을 이용하여 노드들을 비교: 함수를 통해 Head 구조체를 바로 이전의 구조체로 바꿀 때 좀 더 간편하게 삽입이 가능

```cpp
int Insert_Node(SCORE * head, SCORE * d) //노드 삽입 함수 생성
{
	{
	int i;
	for (i = 0; i < MAX_ST; i++)
	// 자료가 입력되지 않았을 경우, 또는 투입되는 값이 가장 클 경우
	{
		if (head->next == NULL || head->next->id > d->id)
		{
			d->next = head->next; // 이전 노드들과 새 노드를 연결하는 과정
			head->next = d;
			return 1;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
		// head의 주소를 다음 노드의 주소로 변경: 링크를 다루기 좀 더 용이해짐
	}
	return -1;
}
```
```cpp
int Delete_Node(SCORE * head, int id) 
//노드 삭제 함수: 노드들이 오름차순으로 정렬되어있다 가정
{
	int i;
	for (i = 0; i < MAX_ST; i++)
	{
		if (head->next == NULL) return -1;
		if (head->next->id == id)
		{
			head->next->id = 0;
			head->next = head->next->next;
			return 1;
		}
		if (head->next->id > id) return -1; 
        //id보다 큰 곳으로 간 경우, 해당 id가 없음을 의미: -1 리턴
		head = head->next;
	}
}
```

### 다중 연결 리스트
- 사번으로 정렬된 링크에서 다른 정렬(이름)을 수행할 경우, 기존 방식으로는 다시 한번 멤버들을 복사, 정렬해야함
- 미리 정렬을 위한 링크를 만들 때 좀 더 편리
- 자료의 탐색, 활용이 더 많아 유리하지만, 삽입, 삭제시 모든 링크를 수정해야 하므로 속도가 느려짐
	- 두가지 항목으로 정렬되어 있는 경우, 루프를 두 번 돌려야 함


![multiply linked.PNG](.\image\multiply linked.PNG)

### 이중 연결 리스트(doubly linked list)
- 기존 singly linked list의 경우, 다음 노드의 주소만을 가지고 있으며, 이전 노드릐 주소를 가지고 있지 않음: 후진 탐색이 안됨
- doubly linked list는 기존 next 이외에 prev 항목을 가지고 있어 전진과 후진 양방향의 링크를 가지도록 설계되어있음

![doubly linked.png](.\image\doubly linked.png)


```cpp
int Insert_Node(SCORE * head, SCORE * d) //노드삽입 함수
{
	int i;

	for(i=0; i<MAX_ST; i++)
	{
		if((head->next == (SCORE *)0x0) || (d->id < head->next->id))
		{
			d->next = head->next; //서로의 주소를 참소: 순서에 유의해야
			d->prev = head;
			if(head->next) head->next->prev = d;
			head->next = d;
			return 1;
		}

		if(d->id == head->next->id) return -2;

		head = head->next;
	}

	return -1;
}
```
```cpp
int Delete_Node(SCORE * head, int id) //노드삭제 함수
{
	SCORE *p = 	Search_Id_Node(head, id);

	if(p == (SCORE *)0x0) return -1;

	p->id = 0; //편의상 id가 0일때 삭제된 걸로 간주
	p->prev->next = p->next; //p의 이전 주소를 이후 주소에 연결
	if(p->next) p->next->prev = p->prev; 
    //p가 마지막이 아닐 경우, p의 이후 주소를 이전 주소에 연결: 양방향
	return 1;
}
```

### 내림차순 인쇄
- singly linked list와 달리 이전 노드의 주소를 저장: 역 차순으로 인쇄 가능
	- 방법 1: 마지막 노드 뒤에 tail 노드를 추가하여 활용
	- 기존 링크의 마지막 노드까지 검색한 뒤 prev 주소를 찾으며 인쇄

```cpp
int Print_All_Node_Reverse(SCORE * head) //내림차순 인쇄
{
	int cnt = 0;
	while (head->next != NULL) //마지막 노드까지 읽어들임
	{
		head = head->next;
		cnt++;
	}
	while (head->prev != NULL) //마지막부터 역차순으로 인쇄
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		head = head->prev;
	}
	return cnt;
}
```

## 스택과 큐
### 스택
- 스택은 LIFO(후입선출) 구조로 동작하는 자료구조
- 입구와 출구가 하나
- PUSH, POP 동작으로 이루어짐
- 스택 포인터(SP)를 통해 스택의 현재 데이터를 지시
	- 빈 상태에서, SP는 배열의 유효 범위 이후 주소를 가짐(`&a[MAX]`)
	- 가득 찬 상태에서 SP는 배열의 0번 요소의 주소를 가짐
- PUSH 동작시 자료를 저장한 뒤 SP는 한칸 상승
	- PUSH 동작은 항상 SP의 상태를 지켜봐야하며, SP가 0일경우 에러메세지 출력
- POP 동작은 반대로 자료를 내보낸 뒤 SP가 한칸 하강
	- POP 동작은 스택이 비었는지 여부를 체크(SP=`&a[MAX]`일 경우 에러메세지 출력)

### 스택 구현
- 스택 설계를 위한 버퍼와 상수
	- MAX_STACK: 최대 데이터 수
	- STACK_EMPTY: 비었을 때의 SP값
	- STACK_FULL: 꽉 찼을 때의 SP값
	- Stac: 스택으로 사용할 버퍼
	- Sptr: SP를 대신할 int 변수

![스택](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)
```cpp
int Push_Stack(int data) //Push 함수
{
	if (Sptr == STACK_FULL) return -1; //스택이 다 찾는지 검토
	Stack[--Sptr] = data; SP(Sptr)을 감소시킨 뒤, 그 자리에 데이터 삽입
	return 1;
}
```
```cpp
int Pop_Stack(int *p) //Pop 함수
{
	if (Sptr == STACK_EMPTY) return -1; //스택이 다 비었는지 검토
	*p = Stack[Sptr++]; //SP 위치에 있는 데이터의 주소를 전달한 뒤 SP 증가
	return 1;
}
```

### Queue
- 큐는 FIFO(선입선출)구조로 동작하는 자료구조
- 입구와 출구가 따로 있으며 입력은 입구, 출력은 출구에서 수행
	- Wrptr: 자료를 쓸 공간, Rdptr: 자료를 읽을 공간을 지시
	- Wrptr=Rdptr: 읽을 값이 없음을 의미
	- 자료읽기(Dequeue) 요청이 올 경우: 읽을 자료가 있을 경우(`Wdptr!=Rdptr`) 자료를 읽은 뒤 `Rdptr++.`
	- 자료쓰기(Queue) 요청이 올 경우: Wrptr 자리에 자료 기입 후 `Wrptr++`
	- Wrptr이 Queue를 초과할 경우, 쓰기 작업은 불가능

![큐](https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/1280px-Data_Queue.svg.png)

### Linear Queue
- `Wrptr==Rdptr`이지만 큐 자체는 다 차지 않는 상황이 올 수 있음: 만약 Wrptr이 큐 밖에 있을 경우, 쓰기 불가 상태
- 실제로 Wrptr이 Queue 밖에 있어도 Rdptr이 0번을 가리키지 않는다면, 해당 큐는 공간이 있는 상황
- 이 문제를 해결하기 위한 방법으로 Linear Queue, Circular Queue의 두가지 방법이 존재
- Linear Queue: 자료의 재배치를 통해 문제를 해결
	- `Rdptr!=0`일 경우 Rdptr에서 Wrptr까지의 자료들을 0번 방으로 밀어넣음: Wrptr의 값이 수정되어 쓰기가 가능해짐
	- 버퍼가 작을 경우, 버퍼 내 자료 이동이 잦아짐

```cpp
int In_Queue(int data) //큐에 데이터 입력
{
	int i;
	if (Wrptr == MAX_Q) // 쓰기 불능일 경우
	{
		if (Rdptr==Q_EMPTY) return -1;
		for (i = Rdptr; i < Wrptr; i++) // 버퍼 정리
		{
			Queue[i - Rdptr] = Queue[i];
		}
		Wrptr -= Rdptr; //버퍼 정리
		Rdptr = Q_EMPTY;
	}
	Queue[Wrptr++] = data; //자료 삽입
	return 1;
}

int Out_Queue(int *p) //큐 안의 데이터 출력
{
	if (Rdptr == Wrptr) return -1; //입력 불능일 경우
	*p = Queue[Rdptr++]; //자료 출력
	return 1;
}
```

### Circular Queue
- Linear Queue는 버퍼의 잦은 이동이 있을 수 있음
- Circular Queue는 Linear Queue의 시작과 끝을 이어붙인 개념으로, 무한히 반복되는 원 모양의 큐
	- Wrptr,Rdptr의 기본 동작은 Linear 형태와 동일
	- 버퍼 끝에 도달한 포인터들은 다시 앞으로 돌아옴: 포인터들 간의 선후 관계를 판단하기 힘들어짐
	- 해결책: 버퍼 1개를 비워두어 Wrptr이 해당 요소에서 멈추도록 함
	- 자료가 다 찼을 때, Rdptr은 Wrptr보다 1만큼 앞서 있음
	- 버퍼를 낭비하게 되나, 1개이므로 무시 가능
- Dequeue: Rdptr 위치의 자료를 읽은 뒤 항상 1 증가하며, 읽기 불가 상태는 Linear 상황과 동일
- Queue: Wrptr은 계속 1 증가하며, 버퍼를 벗어날 때 0부터 다시 시작
- 쓰기 동작 이전에 바로 앞에 Rdptr이 있는지를 항상 확인해야함