# 비선형 자료구조
## 이진 트리
### 트리(Tree)
- 트리는 나뭇가지처럼 자료를 여러갈래로 뻗어나가도록 만드는 구조
- 가지 수에 따라 여러 트리구조가 가능하나, 일반적으로 이진 트리를 이용
- head node가 평균값을 가지고 있다면 자료의 탐색시간 절감 가능
- 실제 자료구조에 많이 사용되지만, 설계나 분석이 어려운 편
- 트리는 기본적으로 좌, 우 가지를 가지며, 자료 크기에 따라 좌 또는 우로 저장됨
	- 일반적으로 좌 측에 작은 자료, 우 측에 큰 자료를 저장
	- 자료를 찾을 때 n개의 자료에 대한 검색 시간은 log<sub>2</sub>n으로 줄어듬(트리의 균형이 맞을 경우): 트리의 깊이(depth)에 비례하는 탐색 시간
- 노드간 링크를 이용, 대상 노드 또는 위치를 찾아 삽입, 삭제, 검색 등의 동작 수행
- 어떤 노드를 기준으로, 노드와 연결되고 노드보다 위에 있을 경우 부모, 밑에 있을 경우 자식이라고 부름
- 자리배치 순서에 따라 중위(inorder), 전위(preorder), 후위(postorder) 탐색으로 나뉨
    - 전위(preorder)
        1. 노드를 방문한다.
        2. 왼쪽 서브 트리를 전위 순회한다.
        3. 오른쪽 서브 트리를 전위 순회한다.
    - 중위(inorder)
        1. 왼쪽 서브 트리를 중위 순회한다.
        2. 노드를 방문한다.
        3. 오른쪽 서브 트리를 중위 순회한다.
    - 후위(postorder)
        1. 왼쪽 서브 트리를 후위 순회한다.
        2. 오른쪽 서브 트리를 후위 순회한다.
        3. 노드를 방문한다.
![트리 순회](https://upload.wikimedia.org/wikipedia/commons/thumb/6/67/Sorted_binary_tree.svg/250px-Sorted_binary_tree.svg.png)


    전위: F, B, A, D, C, E, G, I, H (root, left, right)
    중위: A, B, C, D, E, F, G, H, I (left, root, right)
    후위: A, C, E, D, B, H, I, G, F (left, right, root)

- 해당 방법들은 재귀함수로 표현

```cpp
void Print_All_Node2(struct node *p) //중위(inorder 방법)
{
	if(p->left) Print_All_Node1(p->left);
    printf("Name = %s\n",p->name); //printf명령이 중간에 위치
    if(p->right) Print_All_Node1(p->right);
}
```
```cpp
void Print_All_Node2(struct node *p) //전위(preorder 방법)
{
	printf("Name = %s\n",p->name); //printf명령이 위에 위치
	if(p->left) Print_All_Node1(p->left);
    if(p->right) Print_All_Node1(p->right);
}
```
```cpp
void Print_All_Node2(struct node *p) //후위(postorder 방법)
{
	if(p->left) Print_All_Node1(p->left);
    if(p->right) Print_All_Node1(p->right);
    printf("Name = %s\n",p->name); //printf명령이 아래에 위치
}
```

### 자료구조 구현
- 구조체를 이용하여 이진트리 구조를 구현
- Root: 트리의 최상단 노드
- 좌측(left): 현 자료보다 작은 자료 배치
- 우측(right): 현 자료보다 큰 자료 배치
- 부모(parent): 현 자료의 상위노드 기록

```cpp
typedef struct _score
{
	int id;
    struct _score *left;
    struct _score *right;
    struct _score *parent;
} SCORE;

SCORE * Root;
```

### 노드의 추가 (inorder)
- calloc을 통해 자료를 할당, 추가 자료를 복사
- 노드를 id와 비교해가며 좌 또는 우측 링크를 따라 제일 끝으로 이동
	- 작으면 좌측, 크면 우측으로
- 처음 값은 Root에 저장
- 현대 노드보다 작고 노드의 left가 0인 경우, 왼쪽에 노드 연결
	- 현재 노드 left에 추가 노드 기입, 추가 노드 parent에 현재 노드 기입
- 현대 노드보다 크고 노드의 right가 0인 경우, 오른쪽에 노드 연결
	- 현재 노드 right에 추가 노드 기입, 추가 노드 parent에 현재 노드 기입

## 해시 테이블
### 해시 테이블과 자료 검색
- 해시 테이블은 자료를 몇 덩어리로 분할, 관리하는 개념
- 자료가 들어갈 공간을 규칙에 의해 배정하는 방법
- 예) 자료를 10개의 버퍼에 사번에 따라 저장할 경우
	- 사번을 %10로 연산하여 나머지 값에 해당하는 배열 요소에 저장
	- 이 경우, %10 연산을 통해 자료가 저장된 배열 요소를 쉽게 찾을 수 있음
- 장점: 매우 빠른 탐색 속도
- 단점: 충돌(Collision)
	- Hash값이 동일한 서로 다른 자료가 존재할 경우, 공간에 제한이 있을 경우 저장이 불가능

### 충돌 해결
- 크게 두가지 방법 존재
1. 개방 주소 방법: 공간이 차 있을 때 순차적으로 빈 공간을 탐색하여 저장
	- 규칙에 따라 저장할 수 있는 다음 공간을 step만큼 건너뛰며 검색, 가능한 공간에 저장
	- 간단한 방식이지만, 해시 값이 같은 자료가 많을 경우 비효율적
	- 자료가 많아질 경우, 결국은 순차검색과 비슷하게 됨: 탐색 시간 증가
2. 체이닝 방법(chaining): 공간이 차 있을 때, 그 공간을 head로 하는 list를 생성
	- linked list를 생성하여 같은 해시값을 가진 자료들을 서로 연결
	- 자료가 늘어날수록, list의 수가 늘어남
	- 특정 해시 값의 자료가 많아질 수록 자료를 찾는 시간이 늘어나게 됨

### 개방 주소 (Open Address) 방법
- 자료가 들어갈 방에 다른 자료가 있을 경우, 다음 방으로 옮겨가며 빈 방을 찾음

```cpp
int Insert_Data(SCORE * d) //자료 삽입
{
	int hash = Get_Hash_Key(d->id); //해시키 계산
	int pos = hash; 
	for (;;)
	{
		if (Hash_table[pos].id == -1 || Hash_table[pos].id==-2)
		{
			Hash_table[pos] = *d;
			return pos;
		}
		pos = (pos+STEP) % MAX_ST; //pos를 step씩 증가시키며 빈 공간 탐색
		if (pos == hash) return -1;
	}
}
```
```cpp
SCORE * Search_Data(int id) //자료 검색
{
	int hash = Get_Hash_Key(id);
	int pos = hash;

	for (;;)
	{
		if (Hash_table[pos].id == id) return &Hash_table[pos];
		if (Hash_table[pos].id == -1 ) return NULL;
		pos = (pos + STEP) % MAX_ST;
        if (pos == hash) return NULL;
	}
}
```
```cpp
int Delete_Data(int id)
{
	SCORE *p;
	p = Search_Data(id);
	if (p == NULL) return -1;
	p->id = -2;
	return 1;
}
```

### 해시 함수와 개방 주소 STEP
- 해시 키를 발생하는 함수의 나머지 연산 수는 소수가 유리
- 빈 방을 찾을 때의 Step은 1보다 큰 수가 유리
	- 방들이 연속해서 배정될 확률을 줄여줌
	- Step은 테이블 요소수와 서로소인 수를 선택하는 것이 좋음

### 체이닝
- 자료가 들어갈 방 번호를 해시 함수로 결정
- 해시 테이블은 각 링크의 헤더로 동작하며, 따라서 실제 값은 없음
- 해시 테이블의 next가 0일 때: 자료가 없는 상황
- 자료의 추가, 삭제 때마다 링크를 수정해주어야 함

```cpp
int Insert_Data(SCORE * d)
{
	SCORE *head;
	SCORE *p;
	int hash = Get_Hash_Key(d->id);
	p = calloc(1, sizeof(SCORE));
	if (p == NULL) return -1;
	*p = *d;
	head = &Hash_table[hash];
	for (;;)
	{
		
		if (head->next == NULL || head->next->id>p->id)
		{
			p->next = head->next;
			head->next=p;
			return 1;
		}
		if (head->next->id == p->id) return -1;
		head = head->next;
	}

}
```
```cpp
int Delete_Data(int id)
{
	SCORE * head;
	SCORE * tmp;
	int hash = Get_Hash_Key(id);
	head = &Hash_table[hash];
	for (;;)
	{
		if (head->next == NULL) return 0;
		if (head->next->id > id) return 0;
		if (head->next->id == id)
		{
			tmp = head->next;
			head->next = tmp->next;
			free(tmp);
			return 1;
		}
		head = head->next;
	}
}
```
```cpp
SCORE * Search_Data(int id)
{
	SCORE *head;
	int hash = Get_Hash_Key(id);
	head = &Hash_table[hash];
	for (;;)
	{
		if (head->next == NULL) return NULL;
		if (head->next->id == id) return head->next;
		if (head->next->id > id) return NULL;
		head = head->next;
	}
}
```