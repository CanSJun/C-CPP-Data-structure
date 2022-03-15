#include <iostream>

using namespace std;

/*
ㅇ정렬
-주어진 데이터를 정해진 기준에 따라 순서를 재 배열하는 작업이다.

-ascending order : 오름차순 작은순에서 높은순으로
-descending order : 내림차순 큰 값에서 작은 순으로

ㅇ다양한 종류의 정렬 알고리즘
-bubble sort
-selection sort
-insertion sort

이 3가지는 단순하지만 비효율적이다

-shell sort
-merge sort
-quick sort
-heap sort
-radix sort

이 5가지는 복잡하지만 효율적이다.

ㅇ평가 척도 
- 비교횟수 & 이동 횟수이 얼만큼 되는지 확인 해야함

ㅇ안정성
-안정된 정렬(stable sort) : 같은 값을 갖는 원소의 순서가 정렬 후에도 유지 되는 것.
-안정되지 않은 정렬(unstable sort) : 같은 값을 갖는 원소의 순서가 정렬 후에 보장되지 않는 것


여기선 3가지를 한번 다루어 본다.

ㅇbubble sort
-정렬되지 않은 부분에서 인접한 두 원소의 크기를 비교하여 교환하는 작업을 반복한다.

ex) 4 2 3 5 1  첫번쨰 부터 해본다
4 2 3 5 <->1
4 2 3<->1 5
4 2<-> 1 3 5
4<-> 1 2 3 5
1 4<-> 2 3 5
1 2 4<-> 3 5
1 2 3 4 5

 (n-1) + (n-2) 쭉가서 2+1 까지 즉 1 부터 n-1까지 모든 자연수의 합이 되니깐 
1/2n(n-1)로 전개할 수 있고
시간복잡도로 나타내면 O(n^2)이다

ㅇselection sort
-정렬되지 않은 원소들 중에서 최소값 원소를 찾아 맨 왼쪽 원소와 교환하는 형태

ex) 4 2 3 5 1
여기서 가장 작은값 위치를 찾는다
그러면 1이 가장 작으니 그 다음 
제일 왼쪽 즉 4와 교환한다.
그러면 1 2 3 5 4 가 된다.그러면 1은 정렬이 된 부분이다.
그러면 2 3 5 4를 한번 더 한다.
여기서는 2가 가장 작은데 2가 가장 왼쪽에 있기 때문에 자기자신과 맞 바꾸거나 가만히 둔다
3 5 4만 바꾼다 쭉 해서

1 2 3 4 5를 만든다.

(n-1) 쭉 해서 bubble sort와 같으니
시간복잡도로 나타내면 O(n^2)이다

ㅇinsert sort
-정렬되지 않은 부분의 첫번쨰 원소를 정렬된 부분의 알맞은 위치에 삽입하는 과정을 반복한다

ex)4 2 3 5 1

4를 본다. 이때 하나만 보기떄문에 이미 정렬됐다고 본다.
그러면 2 3 5 1이 정렬되지 않은 부분이다.
여기서 가장 앞에있는 2라는 정렬된 부분으로 이동해야하는데
어느부분이 좋은지 판단한다.
2가 4보다 작기 떄문에 4보다 앞으로 이동한다.
2 4 3 5 1이 된다.
그러면 정렬된게 2 4 부분이고 안된게 3 5 1이다
여기서 가장 왼쪽이 3 이니 정렬된 2 4 부분에 넣어 주기 위해 어느 위치가 적당한지 판단한다
그러면 2 3 4 5 1 이 된다.
그러면 5 1이 정렬안된거니 여기서 쭉 해줘서

1 2 3 4 5로 정렬 해준다.

최선의 경우 : n - 1 입력데이터가 이미 원하는 형태로 정렬이 되어있는 경우. 
최악의 경우 : 1/2n(n-1) 입력데이터가 역순으로 정렬이 되어있을 경우

그래서 O(n^2)이다.

*/

void swap2(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void bubble_srot(int data[], int n) {
	for (int i = 0; i < n - 1; i++) {
		//data[n - 1]부터 시작해서 data[i]까지 이동하면서 인접한 두 원소를 비교& 교환한다
			for (int j = n - 1; j > i; j--) {
				if (data[j] < data[j - 1]) swap2(data[j], data[j - 1]);
			}
	}
}

void selection_sort(int data[], int n) {
	
	for (int i = 0; i < n - 1; i++) {
		int idx = i;
		// data[i], data[i+1] , ... data[n-1]에 대해 최소값을 갖는
		// 인덱스를 알아낸후 data[i]와 data[인덱스]를 교환한다.
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[idx]) idx = j;
		}
		swap2(data[i], data[idx]);

	}

}

void insertion_sort(int data[], int n) {

	for (int i = 1; i < n; i++) {
		//data[i]를 임시 변수(key)에 복사한 후
		//data[i-1]부터 data[0]까지 차례대로 검사
		//ket를 삽입하기에 적절한 위치를 찾을 때 까지
		//각각의 원소 값을 오른쪽으로 원소로 복사하도
		// 적절한 위치에 키값을 삽입(복사)한다.
		int key = data[i];
		int j = i - 1;

		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}

}