#include<iostream>

using namespace std;

/*
ㅇHeap
-완전이진트리의 형태를 따르면서 힙 속성을 만족하는 자료구조.

ㅇ힙속성
최대 힙 속성(max heap property) : 부모 노드의 키 값은 항상 자식 노드의 키 값보다 크거나 같아야함
최소 힙 속성(min heap property) : 부모 노드의 키 값은 항상 자식 노드의 키 값보다 작거나 같아야한다

최대 힙이라고하고 최소힙 이라고 한다

heap에서는 자식노드에서 왼쪽노드 오른쪽노드값이 크거나 작거나 그런건 없다.

ㅇ힙의 특징
-루트 노드는 항상 최댓값 또는 최솟값을 가진다.
-부모-자식 사이의 크기 관계만 있고, 왼쪽 자식, 오른쪽 자식 사이의 크기 관계는 없다
-완전이진트리 이기 때문에 트리의 높이는 h = [log 2 n]
-응용분야 : 힙 정렬, 우선순위 큐, 다익스트라 알고리즘(그래프에서 두 지점사이의 최단거리 찾는 알고리즘) 등

ㅇ시간복잡도
-최댓값 또는 최솟값 참조 : O(1)
-원소 삽입 : O(log N)
-원소 삭제 : O(log N)


								힙			vs			이진탐색트리
트리의형태					완전이진트리				 이진트리
원소 중복여부				 중복가능				중복 불가능
원소 정렬여부				정렬되지 않음			  정렬됨(중위탐색)
빠른원소탐색			미지원(순차탐색, O(n))    지원(이진탐색, O(log n))
원소의 삽입 또는 삭제			O(log n)				O(log n) / O(n) -쳐져있을경우
최댓값/최솟값 참조				O(1)					O(log n) / O(n) -쳐져있을 경우

ㅇ힙의 구현
-힙은 완전 이진트리이므로 각 노드에 인덱스를 붙이고, 배열을 이용하여 쉽게 표현할 수 있다.
-구현의 편의상 루트 노드의 인덱스를 1부터 시작(배열의 0번 인덱스는 무시)

-인덱스가 m인 노드에 대해서
* 루트 노드 인덱스 : 1
* 부모 노드 인덱스 : m / 2
* 왼쪽 자식 인덱스 : m *2
* 오른쪽 자식 인덱스 : m*2 +!


ㅇ힙에 원소 삽입
1. 힙의 맨 마지막에 새로운 원소값을 갖는 노드를 추가한다.
2. 새로 삽입한 노드와 부모노드를 서로 비교하여 힙 속성을 만족하지 않으면 현재 노드와 부모 노드를 교환한다.
그리고 부모 노드에서 이 작업을 반복한다 (heapify_up)

ex) -10 삽입

		10  -- 새 노드 추가

	-5 삽입

		10
	5
	-15 삽입
	
		10
	5		15- 부모 보다 큼 swap 실행

		15
	5		10


	-8 삽입
			15
		7		14
	 5	 3	  9	   10
   8--부모보다큼

			15
		7		14
	 8	 3	  9	   10  - 또크니
   5
			15
		8		14
	 7	 3	  9	   10
   5


*/
#include<vector>
class MaxHeap
{
private :
	vector<int> vec;

public:
	MaxHeap() : vec(1) { }

	void push(int value) {
		vec.push_back(value);
		heapify_up(vec.size() - 1);
	}
	void pop();
	int top() const { return vec[1]; }
	int size() { return vec.size() - 1; }
	bool empty() { return vec.size() == 1; }

private:
	int parent(int i) { return i / 2; }
	int left(int i) { return 2 * i; }
	int right(int i) { return 2 * i + 1; }
	void heapify_up(int i) {
		if (i > 1 && vec[i] > vec[parent(i)]) { // i가 루트노드면 굳이 할 필요없으니깐 .
			swap(vec[i], vec[parent(i)]);
			heapify_up(parent(i));
		}
	}


};