# 정렬
- 원소들을 번호, 사전 순 등 일정한 순서로 재배열하는 것
- 쉬운 정렬 방법들은 O(n<sup>2</sup>)의 계산복잡도를 가지고 있으며, 일반적으로 비교정렬(두 수를 비교하여 결과를 얻는 정렬)의 경우 계산복잡도의 하한선은 O(nlogn)

## 종류
### 단순정렬
- 가장 기본적인 정렬 방법
- 주어진 한 수를 뒤에 있는 모든 수들과 비교, 순서를 변경하는 정렬법
```cpp
void main(void)
{
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++) 
	{
		for (j = i + 1; j < n; j++) //i 뒤의 숫자들을 비교
		{
			if (a[i]>a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp; // 정렬: i위치의 숫자가 더 클경우 뒤의 숫자들과 교환
			}
		}
	}
}
```

### 버블정렬(Bubble sort)
- 자신과 바로 뒤의 원소를 비교하여 지속적으로 순서를 변경하는 정렬법
- 비효율적인 방법으로 정렬 때 많은 시간이 걸리는 편
- 만약 원소들의 정렬이 어느정도 이루어져 있다면, 가장 효율적인 방법 중 하나

```cpp
int Sort_Bubble(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y))
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j]>a[j+1]) //자신의 바로 뒤의 원소와 비교
			{
				tmp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = tmp;
			}
		}
	}
}
```

![bubble1.gif](http://www.xybernetics.com/techtalk/SortingAlgorithmsExplained/images/bubble1.gif)
출처: http://www.xybernetics.com/techtalk/SortingAlgorithmsExplained/SortingAlgorithmsExplained.html

### 선택정렬(select sort)
- 원소들을 탐색하여 가장 작은 수를 찾은 뒤, 이 수를 원래 있어야할 곳에 넣는 방법
- 계산복잡도는 버블정렬과 같으나, 메모리의 이동이 잦지 않아, 버블정렬보다 속도가 빠름

```cpp
int Sort_Select(SCORE * d, int order, int (*comp)(SCORE * x, SCORE * y))
{
	SCORE tmp;
	int i, j;
	int max_ind=0; //가장 작은 인덱스를 저장할 변수

	for (i = n - 1; i > 0; i--)
	{
		for (j = 0, max_ind = 0; j <= i; j++)
		{
			if (d[j]<d[max_ind]) max_ind = j; //가장 큰 인덱스를 저장
		}
		if (j != max_ind) //저장한 인덱스의 숫자를 원래 있어야할 곳으로 이동
		{
			tmp = d[i];
			d[i] = d[max_ind];
			d[max_ind] = tmp;
		}
	}
	return cnt;
}
```
![SelectionEg02.gif](http://www.xybernetics.com/techtalk/SortingAlgorithmsExplained/images/SelectionEg02.gif)
출처: http://www.xybernetics.com/techtalk/SortingAlgorithmsExplained/SortingAlgorithmsExplained.html

### 삽입정렬(insertion sort)

![InsertionEg02.gif](http://www.xybernetics.com/techtalk/SortingAlgorithmsExplained/images/InsertionEg02.gif)
출처: http://www.xybernetics.com/techtalk/SortingAlgorithmsExplained/SortingAlgorithmsExplained.html